/*
 * patch.c - livepatch patching functions
 *
 * Copyright (C) 2014 Seth Jennings <sjenning@redhat.com>
 * Copyright (C) 2014 SUSE
 * Copyright (C) 2015 Josh Poimboeuf <jpoimboe@redhat.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <linux/livepatch.h>
#include <linux/list.h>
#include <linux/ftrace.h>
#include <linux/rculist.h>
#include <linux/slab.h>
#include <linux/bug.h>
#include <linux/printk.h>
#include "core.h"
#include "patch.h"
#include "transition.h"

static LIST_HEAD(klp_ops);

struct klp_ops *klp_find_ops(unsigned long old_addr)
{
	struct klp_ops *ops;
	struct klp_func *func;

	list_for_each_entry(ops, &klp_ops, node) {
		func = list_first_entry(&ops->func_stack, struct klp_func,
					stack_node);
		if (func->old_addr == old_addr)
			return ops;
	}

	return NULL;
}

static void notrace klp_ftrace_handler(unsigned long ip,
				       unsigned long parent_ip,
				       struct ftrace_ops *fops,
				       struct pt_regs *regs)
{
	struct klp_ops *ops;
	struct klp_func *func;
	int patch_state;

	ops = container_of(fops, struct klp_ops, fops);

	/*
	 * A variant of synchronize_sched() is used to allow patching functions
	 * where RCU is not watching, see klp_synchronize_transition().
	 */
	preempt_disable_notrace();

	func = list_first_or_null_rcu(&ops->func_stack, struct klp_func,
				      stack_node);

	/*
	 * func should never be NULL because preemption should be disabled here
	 * and unregister_ftrace_function() does the equivalent of a
	 * synchronize_sched() before the func_stack removal.
	 */
	if (WARN_ON_ONCE(!func))
		goto unlock;

	/*
	 * In the enable path, enforce the order of the ops->func_stack and
	 * func->transition reads.  The corresponding write barrier is in
	 * __klp_enable_patch().
	 *
	 * (Note that this barrier technically isn't needed in the disable
	 * path.  In the rare case where klp_update_patch_state() runs before
	 * this handler, its TIF_PATCH_PENDING read and this func->transition
	 * read need to be ordered.  But klp_update_patch_state() already
	 * enforces that.)
	 */
	smp_rmb();

	if (unlikely(func->transition)) {

		/*
		 * Enforce the order of the func->transition and
		 * current->patch_state reads.  Otherwise we could read an
		 * out-of-date task state and pick the wrong function.  The
		 * corresponding write barrier is in klp_init_transition().
		 */
		smp_rmb();

		patch_state = current->patch_state;

		WARN_ON_ONCE(patch_state == KLP_UNDEFINED);

		if (patch_state == KLP_UNPATCHED) {
			/*
			 * Use the previously patched version of the function.
			 * If no previous patches exist, continue with the
			 * original function.
			 */
			func = list_entry_rcu(func->stack_node.next,
					      struct klp_func, stack_node);

			if (&func->stack_node == &ops->func_stack)
				goto unlock;
		}
	}

	klp_arch_set_pc(regs, (unsigned long)func->new_func);
unlock:
	preempt_enable_notrace();
}

/*
 * Convert a function address into the appropriate ftrace location.
 *
 * Usually this is just the address of the function, but on some architectures
 * it's more complicated so allow them to provide a custom behaviour.
 */
#ifndef klp_get_ftrace_location
static unsigned long klp_get_ftrace_location(unsigned long faddr)
{
	return faddr;
}
#endif

static void klp_unpatch_func(struct klp_func *func)
{
	struct klp_ops *ops;

	if (WARN_ON(!func->patched))
		return;
	if (WARN_ON(!func->old_addr))
		return;

	ops = klp_find_ops(func->old_addr);
	if (WARN_ON(!ops))
		return;

	if (list_is_singular(&ops->func_stack)) {
		unsigned long ftrace_loc;

		ftrace_loc = klp_get_ftrace_location(func->old_addr);
		if (WARN_ON(!ftrace_loc))
			return;

		WARN_ON(unregister_ftrace_function(&ops->fops));
		WARN_ON(ftrace_set_filter_ip(&ops->fops, ftrace_loc, 1, 0));

		list_del_rcu(&func->stack_node);
		list_del(&ops->node);
		kfree(ops);
	} else {
		list_del_rcu(&func->stack_node);
	}

	func->patched = false;
}

static int klp_patch_func(struct klp_func *func)
{
	struct klp_ops *ops;
	int ret;

	if (WARN_ON(!func->old_addr))
		return -EINVAL;

	if (WARN_ON(func->patched))
		return -EINVAL;

	ops = klp_find_ops(func->old_addr);
	if (!ops) {
		unsigned long ftrace_loc;

		ftrace_loc = klp_get_ftrace_location(func->old_addr);
		if (!ftrace_loc) {
			pr_err("failed to find location for function '%s'\n",
				func->old_name);
			return -EINVAL;
		}

		ops = kzalloc(sizeof(*ops), GFP_KERNEL);
		if (!ops)
			return -ENOMEM;

		ops->fops.func = klp_ftrace_handler;
		ops->fops.flags = FTRACE_OPS_FL_SAVE_REGS |
				  FTRACE_OPS_FL_DYNAMIC |
				  FTRACE_OPS_FL_IPMODIFY;

		list_add(&ops->node, &klp_ops);

		INIT_LIST_HEAD(&ops->func_stack);
		list_add_rcu(&func->stack_node, &ops->func_stack);

		ret = ftrace_set_filter_ip(&ops->fops, ftrace_loc, 0, 0);
		if (ret) {
			pr_err("failed to set ftrace filter for function '%s' (%d)\n",
			       func->old_name, ret);
			goto err;
		}

		ret = register_ftrace_function(&ops->fops);
		if (ret) {
			pr_err("failed to register ftrace handler for function '%s' (%d)\n",
			       func->old_name, ret);
			ftrace_set_filter_ip(&ops->fops, ftrace_loc, 1, 0);
			goto err;
		}


	} else {
		list_add_rcu(&func->stack_node, &ops->func_stack);
	}

	func->patched = true;

	return 0;

err:
	list_del_rcu(&func->stack_node);
	list_del(&ops->node);
	kfree(ops);
	return ret;
}

void klp_unpatch_object(struct klp_object *obj)
{
	struct klp_func *func;

	klp_for_each_func(obj, func)
		if (func->patched)
			klp_unpatch_func(func);

	obj->patched = false;
}

int klp_patch_object(struct klp_object *obj)
{
	struct klp_func *func;
	int ret;

	if (WARN_ON(obj->patched))
		return -EINVAL;

	klp_for_each_func(obj, func) {
		ret = klp_patch_func(func);
		if (ret) {
			klp_unpatch_object(obj);
			return ret;
		}
	}
	obj->patched = true;

	return 0;
}

void klp_unpatch_objects(struct klp_patch *patch)
{
	struct klp_object *obj;

	klp_for_each_object(patch, obj)
		if (obj->patched)
			klp_unpatch_object(obj);
}
