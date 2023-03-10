/*
 * KVM_GET/SET_* tests
 *
 * Copyright (C) 2018, Red Hat, Inc.
 *
 * This work is licensed under the terms of the GNU GPL, version 2.
 *
 * Tests for vCPU state save/restore, including nested guest state.
 */
#define _GNU_SOURCE /* for program_invocation_short_name */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>

#include "test_util.h"

#include "kvm_util.h"
#include "x86.h"
#include "vmx.h"

#define VCPU_ID		5

static bool have_nested_state;

void l2_guest_code(void)
{
	GUEST_SYNC(5);

        /* Exit to L1 */
	vmcall();

	/* L1 has now set up a shadow VMCS for us.  */
	GUEST_ASSERT(vmreadz(GUEST_RIP) == 0xc0ffee);
	GUEST_SYNC(9);
	GUEST_ASSERT(vmreadz(GUEST_RIP) == 0xc0ffee);
	GUEST_ASSERT(!vmwrite(GUEST_RIP, 0xc0fffee));
	GUEST_SYNC(10);
	GUEST_ASSERT(vmreadz(GUEST_RIP) == 0xc0fffee);
	GUEST_ASSERT(!vmwrite(GUEST_RIP, 0xc0ffffee));
	GUEST_SYNC(11);

	/* Done, exit to L1 and never come back.  */
	vmcall();
}

void l1_guest_code(struct vmx_pages *vmx_pages)
{
#define L2_GUEST_STACK_SIZE 64
        unsigned long l2_guest_stack[L2_GUEST_STACK_SIZE];

	GUEST_ASSERT(vmx_pages->vmcs_gpa);
	GUEST_ASSERT(prepare_for_vmx_operation(vmx_pages));
	GUEST_ASSERT(vmptrstz() == vmx_pages->vmcs_gpa);

	GUEST_SYNC(3);
	GUEST_ASSERT(vmptrstz() == vmx_pages->vmcs_gpa);

	prepare_vmcs(vmx_pages, l2_guest_code,
		     &l2_guest_stack[L2_GUEST_STACK_SIZE]);

	GUEST_SYNC(4);
	GUEST_ASSERT(vmptrstz() == vmx_pages->vmcs_gpa);
	GUEST_ASSERT(!vmlaunch());
	GUEST_ASSERT(vmptrstz() == vmx_pages->vmcs_gpa);
	GUEST_ASSERT(vmreadz(VM_EXIT_REASON) == EXIT_REASON_VMCALL);

	/* Check that the launched state is preserved.  */
	GUEST_ASSERT(vmlaunch());

	GUEST_ASSERT(!vmresume());
	GUEST_ASSERT(vmreadz(VM_EXIT_REASON) == EXIT_REASON_VMCALL);

	GUEST_SYNC(6);
	GUEST_ASSERT(vmreadz(VM_EXIT_REASON) == EXIT_REASON_VMCALL);

	GUEST_ASSERT(!vmresume());
	GUEST_ASSERT(vmreadz(VM_EXIT_REASON) == EXIT_REASON_VMCALL);

	vmwrite(GUEST_RIP, vmreadz(GUEST_RIP) + 3);

	vmwrite(SECONDARY_VM_EXEC_CONTROL, SECONDARY_EXEC_SHADOW_VMCS);
	vmwrite(VMCS_LINK_POINTER, vmx_pages->shadow_vmcs_gpa);

	GUEST_ASSERT(!vmptrld(vmx_pages->shadow_vmcs_gpa));
	GUEST_ASSERT(vmlaunch());
	GUEST_SYNC(7);
	GUEST_ASSERT(vmlaunch());
	GUEST_ASSERT(vmresume());

	vmwrite(GUEST_RIP, 0xc0ffee);
	GUEST_SYNC(8);
	GUEST_ASSERT(vmreadz(GUEST_RIP) == 0xc0ffee);

	GUEST_ASSERT(!vmptrld(vmx_pages->vmcs_gpa));
	GUEST_ASSERT(!vmresume());
	GUEST_ASSERT(vmreadz(VM_EXIT_REASON) == EXIT_REASON_VMCALL);

	GUEST_ASSERT(!vmptrld(vmx_pages->shadow_vmcs_gpa));
	GUEST_ASSERT(vmreadz(GUEST_RIP) == 0xc0ffffee);
	GUEST_ASSERT(vmlaunch());
	GUEST_ASSERT(vmresume());
	GUEST_SYNC(12);
	GUEST_ASSERT(vmreadz(GUEST_RIP) == 0xc0ffffee);
	GUEST_ASSERT(vmlaunch());
	GUEST_ASSERT(vmresume());
}

void guest_code(struct vmx_pages *vmx_pages)
{
	GUEST_SYNC(1);
	GUEST_SYNC(2);

	if (vmx_pages)
		l1_guest_code(vmx_pages);

	GUEST_DONE();
}

int main(int argc, char *argv[])
{
	struct vmx_pages *vmx_pages = NULL;
	vm_vaddr_t vmx_pages_gva = 0;

	struct kvm_regs regs1, regs2;
	struct kvm_vm *vm;
	struct kvm_run *run;
	struct kvm_x86_state *state;
	int stage;

	struct kvm_cpuid_entry2 *entry = kvm_get_supported_cpuid_entry(1);

	/* Create VM */
	vm = vm_create_default(VCPU_ID, 0, guest_code);
	vcpu_set_cpuid(vm, VCPU_ID, kvm_get_supported_cpuid());
	run = vcpu_state(vm, VCPU_ID);

	vcpu_regs_get(vm, VCPU_ID, &regs1);

	if (kvm_check_cap(KVM_CAP_NESTED_STATE)) {
		vmx_pages = vcpu_alloc_vmx(vm, &vmx_pages_gva);
		vcpu_args_set(vm, VCPU_ID, 1, vmx_pages_gva);
	} else {
		printf("will skip nested state checks\n");
		vcpu_args_set(vm, VCPU_ID, 1, 0);
	}

	for (stage = 1;; stage++) {
		_vcpu_run(vm, VCPU_ID);
		TEST_ASSERT(run->exit_reason == KVM_EXIT_IO,
			    "Unexpected exit reason: %u (%s),\n",
			    run->exit_reason,
			    exit_reason_str(run->exit_reason));

		memset(&regs1, 0, sizeof(regs1));
		vcpu_regs_get(vm, VCPU_ID, &regs1);
		switch (run->io.port) {
		case GUEST_PORT_ABORT:
			TEST_ASSERT(false, "%s at %s:%d", (const char *) regs1.rdi,
				    __FILE__, regs1.rsi);
			/* NOT REACHED */
		case GUEST_PORT_SYNC:
			break;
		case GUEST_PORT_DONE:
			goto done;
		default:
			TEST_ASSERT(false, "Unknown port 0x%x.", run->io.port);
		}

		/* PORT_SYNC is handled here.  */
		TEST_ASSERT(!strcmp((const char *)regs1.rdi, "hello") &&
			    regs1.rsi == stage, "Unexpected register values vmexit #%lx, got %lx",
			    stage, (ulong) regs1.rsi);

		state = vcpu_save_state(vm, VCPU_ID);
		kvm_vm_release(vm);

		/* Restore state in a new VM.  */
		kvm_vm_restart(vm, O_RDWR);
		vm_vcpu_add(vm, VCPU_ID, 0, 0);
		vcpu_set_cpuid(vm, VCPU_ID, kvm_get_supported_cpuid());
		vcpu_load_state(vm, VCPU_ID, state);
		run = vcpu_state(vm, VCPU_ID);
		free(state);

		memset(&regs2, 0, sizeof(regs2));
		vcpu_regs_get(vm, VCPU_ID, &regs2);
		TEST_ASSERT(!memcmp(&regs1, &regs2, sizeof(regs2)),
			    "Unexpected register values after vcpu_load_state; rdi: %lx rsi: %lx",
			    (ulong) regs2.rdi, (ulong) regs2.rsi);
	}

done:
	kvm_vm_free(vm);
}
