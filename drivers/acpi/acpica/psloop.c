// SPDX-License-Identifier: BSD-3-Clause OR GPL-2.0
/******************************************************************************
 *
 * Module Name: psloop - Main AML parse loop
 *
 * Copyright (C) 2000 - 2018, Intel Corp.
 *
 *****************************************************************************/

/*
 * Parse the AML and build an operation tree as most interpreters, (such as
 * Perl) do. Parsing is done by hand rather than with a YACC generated parser
 * to tightly constrain stack and dynamic memory usage. Parsing is kept
 * flexible and the code fairly compact by parsing based on a list of AML
 * opcode templates in aml_op_info[].
 */

#include <acpi/acpi.h>
#include "accommon.h"
#include "acinterp.h"
#include "acparser.h"
#include "acdispat.h"
#include "amlcode.h"
#include "acconvert.h"
#include "acnamesp.h"

#define _COMPONENT          ACPI_PARSER
ACPI_MODULE_NAME("psloop")

/* Local prototypes */
static acpi_status
acpi_ps_get_arguments(struct acpi_walk_state *walk_state,
		      u8 * aml_op_start, union acpi_parse_object *op);

static void
acpi_ps_link_module_code(union acpi_parse_object *parent_op,
			 u8 *aml_start, u32 aml_length, acpi_owner_id owner_id);

/*******************************************************************************
 *
 * FUNCTION:    acpi_ps_get_arguments
 *
 * PARAMETERS:  walk_state          - Current state
 *              aml_op_start        - Op start in AML
 *              op                  - Current Op
 *
 * RETURN:      Status
 *
 * DESCRIPTION: Get arguments for passed Op.
 *
 ******************************************************************************/

static acpi_status
acpi_ps_get_arguments(struct acpi_walk_state *walk_state,
		      u8 * aml_op_start, union acpi_parse_object *op)
{
	acpi_status status = AE_OK;
	union acpi_parse_object *arg = NULL;
	const struct acpi_opcode_info *op_info;

	ACPI_FUNCTION_TRACE_PTR(ps_get_arguments, walk_state);

	ACPI_DEBUG_PRINT((ACPI_DB_PARSE,
			  "Get arguments for opcode [%s]\n",
			  op->common.aml_op_name));

	switch (op->common.aml_opcode) {
	case AML_BYTE_OP:	/* AML_BYTEDATA_ARG */
	case AML_WORD_OP:	/* AML_WORDDATA_ARG */
	case AML_DWORD_OP:	/* AML_DWORDATA_ARG */
	case AML_QWORD_OP:	/* AML_QWORDATA_ARG */
	case AML_STRING_OP:	/* AML_ASCIICHARLIST_ARG */

		/* Fill in constant or string argument directly */

		acpi_ps_get_next_simple_arg(&(walk_state->parser_state),
					    GET_CURRENT_ARG_TYPE(walk_state->
								 arg_types),
					    op);
		break;

	case AML_INT_NAMEPATH_OP:	/* AML_NAMESTRING_ARG */

		status = acpi_ps_get_next_namepath(walk_state,
						   &(walk_state->parser_state),
						   op,
						   ACPI_POSSIBLE_METHOD_CALL);
		if (ACPI_FAILURE(status)) {
			return_ACPI_STATUS(status);
		}

		walk_state->arg_types = 0;
		break;

	default:
		/*
		 * Op is not a constant or string, append each argument to the Op
		 */
		while (GET_CURRENT_ARG_TYPE(walk_state->arg_types) &&
		       !walk_state->arg_count) {
			walk_state->aml = walk_state->parser_state.aml;

			switch (op->common.aml_opcode) {
			case AML_METHOD_OP:
			case AML_BUFFER_OP:
			case AML_PACKAGE_OP:
			case AML_VARIABLE_PACKAGE_OP:
			case AML_WHILE_OP:

				break;

			default:

				ASL_CV_CAPTURE_COMMENTS(walk_state);
				break;
			}

			status =
			    acpi_ps_get_next_arg(walk_state,
						 &(walk_state->parser_state),
						 GET_CURRENT_ARG_TYPE
						 (walk_state->arg_types), &arg);
			if (ACPI_FAILURE(status)) {
				return_ACPI_STATUS(status);
			}

			if (arg) {
				acpi_ps_append_arg(op, arg);
			}

			INCREMENT_ARG_LIST(walk_state->arg_types);
		}

		ACPI_DEBUG_PRINT((ACPI_DB_PARSE,
				  "Final argument count: %8.8X pass %u\n",
				  walk_state->arg_count,
				  walk_state->pass_number));

		/*
		 * This case handles the legacy option that groups all module-level
		 * code blocks together and defers execution until all of the tables
		 * are loaded. Execute all of these blocks at this time.
		 * Execute any module-level code that was detected during the table
		 * load phase.
		 *
		 * Note: this option is deprecated and will be eliminated in the
		 * future. Use of this option can cause problems with AML code that
		 * depends upon in-order immediate execution of module-level code.
		 */
		if (acpi_gbl_group_module_level_code &&
		    (walk_state->pass_number <= ACPI_IMODE_LOAD_PASS2) &&
		    ((walk_state->parse_flags & ACPI_PARSE_DISASSEMBLE) == 0)) {
			/*
			 * We want to skip If/Else/While constructs during Pass1 because we
			 * want to actually conditionally execute the code during Pass2.
			 *
			 * Except for disassembly, where we always want to walk the
			 * If/Else/While packages
			 */
			switch (op->common.aml_opcode) {
			case AML_IF_OP:
			case AML_ELSE_OP:
			case AML_WHILE_OP:
				/*
				 * Currently supported module-level opcodes are:
				 * IF/ELSE/WHILE. These appear to be the most common,
				 * and easiest to support since they open an AML
				 * package.
				 */
				if (walk_state->pass_number ==
				    ACPI_IMODE_LOAD_PASS1) {
					acpi_ps_link_module_code(op->common.
								 parent,
								 aml_op_start,
								 (u32)
								 (walk_state->
								 parser_state.
								 pkg_end -
								 aml_op_start),
								 walk_state->
								 owner_id);
				}

				ACPI_DEBUG_PRINT((ACPI_DB_PARSE,
						  "Pass1: Skipping an If/Else/While body\n"));

				/* Skip body of if/else/while in pass 1 */

				walk_state->parser_state.aml =
				    walk_state->parser_state.pkg_end;
				walk_state->arg_count = 0;
				break;

			default:
				/*
				 * Check for an unsupported executable opcode at module
				 * level. We must be in PASS1, the parent must be a SCOPE,
				 * The opcode class must be EXECUTE, and the opcode must
				 * not be an argument to another opcode.
				 */
				if ((walk_state->pass_number ==
				     ACPI_IMODE_LOAD_PASS1)
				    && (op->common.parent->common.aml_opcode ==
					AML_SCOPE_OP)) {
					op_info =
					    acpi_ps_get_opcode_info(op->common.
								    aml_opcode);
					if ((op_info->class ==
					     AML_CLASS_EXECUTE) && (!arg)) {
						ACPI_WARNING((AE_INFO,
							      "Unsupported module-level executable opcode "
							      "0x%.2X at table offset 0x%.4X",
							      op->common.
							      aml_opcode,
							      (u32)
							      (ACPI_PTR_DIFF
							       (aml_op_start,
								walk_state->
								parser_state.
								aml_start) +
							       sizeof(struct
								      acpi_table_header))));
					}
				}
				break;
			}
		}

		/* Special processing for certain opcodes */

		switch (op->common.aml_opcode) {
		case AML_METHOD_OP:
			/*
			 * Skip parsing of control method because we don't have enough
			 * info in the first pass to parse it correctly.
			 *
			 * Save the length and address of the body
			 */
			op->named.data = walk_state->parser_state.aml;
			op->named.length = (u32)
			    (walk_state->parser_state.pkg_end -
			     walk_state->parser_state.aml);

			/* Skip body of method */

			walk_state->parser_state.aml =
			    walk_state->parser_state.pkg_end;
			walk_state->arg_count = 0;
			break;

		case AML_BUFFER_OP:
		case AML_PACKAGE_OP:
		case AML_VARIABLE_PACKAGE_OP:

			if ((op->common.parent) &&
			    (op->common.parent->common.aml_opcode ==
			     AML_NAME_OP)
			    && (walk_state->pass_number <=
				ACPI_IMODE_LOAD_PASS2)) {
				ACPI_DEBUG_PRINT((ACPI_DB_PARSE,
						  "Setup Package/Buffer: Pass %u, AML Ptr: %p\n",
						  walk_state->pass_number,
						  aml_op_start));

				/*
				 * Skip parsing of Buffers and Packages because we don't have
				 * enough info in the first pass to parse them correctly.
				 */
				op->named.data = aml_op_start;
				op->named.length = (u32)
				    (walk_state->parser_state.pkg_end -
				     aml_op_start);

				/* Skip body */

				walk_state->parser_state.aml =
				    walk_state->parser_state.pkg_end;
				walk_state->arg_count = 0;
			}
			break;

		case AML_WHILE_OP:

			if (walk_state->control_state) {
				walk_state->control_state->control.package_end =
				    walk_state->parser_state.pkg_end;
			}
			break;

		default:

			/* No action for all other opcodes */

			break;
		}

		break;
	}

	return_ACPI_STATUS(AE_OK);
}

/*******************************************************************************
 *
 * FUNCTION:    acpi_ps_link_module_code
 *
 * PARAMETERS:  parent_op           - Parent parser op
 *              aml_start           - Pointer to the AML
 *              aml_length          - Length of executable AML
 *              owner_id            - owner_id of module level code
 *
 * RETURN:      None.
 *
 * DESCRIPTION: Wrap the module-level code with a method object and link the
 *              object to the global list. Note, the mutex field of the method
 *              object is used to link multiple module-level code objects.
 *
 * NOTE: In this legacy option, each block of detected executable AML
 * code that is outside of any control method is wrapped with a temporary
 * control method object and placed on a global list below.
 *
 * This function executes the module-level code for all tables only after
 * all of the tables have been loaded. It is a legacy option and is
 * not compatible with other ACPI implementations. See acpi_ns_load_table.
 *
 * This function will be removed when the legacy option is removed.
 *
 ******************************************************************************/

static void
acpi_ps_link_module_code(union acpi_parse_object *parent_op,
			 u8 *aml_start, u32 aml_length, acpi_owner_id owner_id)
{
	union acpi_operand_object *prev;
	union acpi_operand_object *next;
	union acpi_operand_object *method_obj;
	struct acpi_namespace_node *parent_node;

	ACPI_FUNCTION_TRACE(ps_link_module_code);

	/* Get the tail of the list */

	prev = next = acpi_gbl_module_code_list;
	while (next) {
		prev = next;
		next = next->method.mutex;
	}

	/*
	 * Insert the module level code into the list. Merge it if it is
	 * adjacent to the previous element.
	 */
	if (!prev ||
	    ((prev->method.aml_start + prev->method.aml_length) != aml_start)) {

		/* Create, initialize, and link a new temporary method object */

		method_obj = acpi_ut_create_internal_object(ACPI_TYPE_METHOD);
		if (!method_obj) {
			return_VOID;
		}

		ACPI_DEBUG_PRINT((ACPI_DB_PARSE,
				  "Create/Link new code block: %p\n",
				  method_obj));

		if (parent_op->common.node) {
			parent_node = parent_op->common.node;
		} else {
			parent_node = acpi_gbl_root_node;
		}

		method_obj->method.aml_start = aml_start;
		method_obj->method.aml_length = aml_length;
		method_obj->method.owner_id = owner_id;
		method_obj->method.info_flags |= ACPI_METHOD_MODULE_LEVEL;

		/*
		 * Save the parent node in next_object. This is cheating, but we
		 * don't want to expand the method object.
		 */
		method_obj->method.next_object =
		    ACPI_CAST_PTR(union acpi_operand_object, parent_node);

		if (!prev) {
			acpi_gbl_module_code_list = method_obj;
		} else {
			prev->method.mutex = method_obj;
		}
	} else {
		ACPI_DEBUG_PRINT((ACPI_DB_PARSE,
				  "Appending to existing code block: %p\n",
				  prev));

		prev->method.aml_length += aml_length;
	}

	return_VOID;
}

/*******************************************************************************
 *
 * FUNCTION:    acpi_ps_parse_loop
 *
 * PARAMETERS:  walk_state          - Current state
 *
 * RETURN:      Status
 *
 * DESCRIPTION: Parse AML (pointed to by the current parser state) and return
 *              a tree of ops.
 *
 ******************************************************************************/

acpi_status acpi_ps_parse_loop(struct acpi_walk_state *walk_state)
{
	acpi_status status = AE_OK;
	union acpi_parse_object *op = NULL;	/* current op */
	struct acpi_parse_state *parser_state;
	u8 *aml_op_start = NULL;
	u8 opcode_length;

	ACPI_FUNCTION_TRACE_PTR(ps_parse_loop, walk_state);

	if (walk_state->descending_callback == NULL) {
		return_ACPI_STATUS(AE_BAD_PARAMETER);
	}

	parser_state = &walk_state->parser_state;
	walk_state->arg_types = 0;

#if (!defined (ACPI_NO_METHOD_EXECUTION) && !defined (ACPI_CONSTANT_EVAL_ONLY))

	if (walk_state->walk_type & ACPI_WALK_METHOD_RESTART) {

		/* We are restarting a preempted control method */

		if (acpi_ps_has_completed_scope(parser_state)) {
			/*
			 * We must check if a predicate to an IF or WHILE statement
			 * was just completed
			 */
			if ((parser_state->scope->parse_scope.op) &&
			    ((parser_state->scope->parse_scope.op->common.
			      aml_opcode == AML_IF_OP)
			     || (parser_state->scope->parse_scope.op->common.
				 aml_opcode == AML_WHILE_OP))
			    && (walk_state->control_state)
			    && (walk_state->control_state->common.state ==
				ACPI_CONTROL_PREDICATE_EXECUTING)) {
				/*
				 * A predicate was just completed, get the value of the
				 * predicate and branch based on that value
				 */
				walk_state->op = NULL;
				status =
				    acpi_ds_get_predicate_value(walk_state,
								ACPI_TO_POINTER
								(TRUE));
				if (ACPI_FAILURE(status)
				    && ((status & AE_CODE_MASK) !=
					AE_CODE_CONTROL)) {
					if (status == AE_AML_NO_RETURN_VALUE) {
						ACPI_EXCEPTION((AE_INFO, status,
								"Invoked method did not return a value"));
					}

					ACPI_EXCEPTION((AE_INFO, status,
							"GetPredicate Failed"));
					return_ACPI_STATUS(status);
				}

				status =
				    acpi_ps_next_parse_state(walk_state, op,
							     status);
			}

			acpi_ps_pop_scope(parser_state, &op,
					  &walk_state->arg_types,
					  &walk_state->arg_count);
			ACPI_DEBUG_PRINT((ACPI_DB_PARSE,
					  "Popped scope, Op=%p\n", op));
		} else if (walk_state->prev_op) {

			/* We were in the middle of an op */

			op = walk_state->prev_op;
			walk_state->arg_types = walk_state->prev_arg_types;
		}
	}
#endif

	/* Iterative parsing loop, while there is more AML to process: */

	while ((parser_state->aml < parser_state->aml_end) || (op)) {
		ASL_CV_CAPTURE_COMMENTS(walk_state);

		aml_op_start = parser_state->aml;
		if (!op) {
			status =
			    acpi_ps_create_op(walk_state, aml_op_start, &op);
			if (ACPI_FAILURE(status)) {
				/*
				 * ACPI_PARSE_MODULE_LEVEL means that we are loading a table by
				 * executing it as a control method. However, if we encounter
				 * an error while loading the table, we need to keep trying to
				 * load the table rather than aborting the table load. Set the
				 * status to AE_OK to proceed with the table load.
				 */
				if ((walk_state->
				     parse_flags & ACPI_PARSE_MODULE_LEVEL)
				    && status == AE_ALREADY_EXISTS) {
					status = AE_OK;
				}
				if (status == AE_CTRL_PARSE_CONTINUE) {
					continue;
				}

				if (status == AE_CTRL_PARSE_PENDING) {
					status = AE_OK;
				}

				if (status == AE_CTRL_TERMINATE) {
					return_ACPI_STATUS(status);
				}

				status =
				    acpi_ps_complete_op(walk_state, &op,
							status);
				if (ACPI_FAILURE(status)) {
					return_ACPI_STATUS(status);
				}
				if (acpi_ns_opens_scope
				    (acpi_ps_get_opcode_info
				     (walk_state->opcode)->object_type)) {
					/*
					 * If the scope/device op fails to parse, skip the body of
					 * the scope op because the parse failure indicates that
					 * the device may not exist.
					 */
					ACPI_ERROR((AE_INFO,
						    "Skip parsing opcode %s",
						    acpi_ps_get_opcode_name
						    (walk_state->opcode)));

					/*
					 * Determine the opcode length before skipping the opcode.
					 * An opcode can be 1 byte or 2 bytes in length.
					 */
					opcode_length = 1;
					if ((walk_state->opcode & 0xFF00) ==
					    AML_EXTENDED_OPCODE) {
						opcode_length = 2;
					}
					walk_state->parser_state.aml =
					    walk_state->aml + opcode_length;

					walk_state->parser_state.aml =
					    acpi_ps_get_next_package_end
					    (&walk_state->parser_state);
					walk_state->aml =
					    walk_state->parser_state.aml;
				}

				continue;
			}

			acpi_ex_start_trace_opcode(op, walk_state);
		}

		/*
		 * Start arg_count at zero because we don't know if there are
		 * any args yet
		 */
		walk_state->arg_count = 0;

		switch (op->common.aml_opcode) {
		case AML_BYTE_OP:
		case AML_WORD_OP:
		case AML_DWORD_OP:
		case AML_QWORD_OP:

			break;

		default:

			ASL_CV_CAPTURE_COMMENTS(walk_state);
			break;
		}

		/* Are there any arguments that must be processed? */

		if (walk_state->arg_types) {

			/* Get arguments */

			status =
			    acpi_ps_get_arguments(walk_state, aml_op_start, op);
			if (ACPI_FAILURE(status)) {
				status =
				    acpi_ps_complete_op(walk_state, &op,
							status);
				if (ACPI_FAILURE(status)) {
					return_ACPI_STATUS(status);
				}
				if ((walk_state->control_state) &&
				    ((walk_state->control_state->control.
				      opcode == AML_IF_OP)
				     || (walk_state->control_state->control.
					 opcode == AML_WHILE_OP))) {
					/*
					 * If the if/while op fails to parse, we will skip parsing
					 * the body of the op.
					 */
					parser_state->aml =
					    walk_state->control_state->control.
					    aml_predicate_start + 1;
					parser_state->aml =
					    acpi_ps_get_next_package_end
					    (parser_state);
					walk_state->aml = parser_state->aml;

					ACPI_ERROR((AE_INFO,
						    "Skipping While/If block"));
					if (*walk_state->aml == AML_ELSE_OP) {
						ACPI_ERROR((AE_INFO,
							    "Skipping Else block"));
						walk_state->parser_state.aml =
						    walk_state->aml + 1;
						walk_state->parser_state.aml =
						    acpi_ps_get_next_package_end
						    (parser_state);
						walk_state->aml =
						    parser_state->aml;
					}
					ACPI_FREE(acpi_ut_pop_generic_state
						  (&walk_state->control_state));
				}
				op = NULL;
				continue;
			}
		}

		/* Check for arguments that need to be processed */

		ACPI_DEBUG_PRINT((ACPI_DB_PARSE,
				  "Parseloop: argument count: %8.8X\n",
				  walk_state->arg_count));

		if (walk_state->arg_count) {
			/*
			 * There are arguments (complex ones), push Op and
			 * prepare for argument
			 */
			status = acpi_ps_push_scope(parser_state, op,
						    walk_state->arg_types,
						    walk_state->arg_count);
			if (ACPI_FAILURE(status)) {
				status =
				    acpi_ps_complete_op(walk_state, &op,
							status);
				if (ACPI_FAILURE(status)) {
					return_ACPI_STATUS(status);
				}

				continue;
			}

			op = NULL;
			continue;
		}

		/*
		 * All arguments have been processed -- Op is complete,
		 * prepare for next
		 */
		walk_state->op_info =
		    acpi_ps_get_opcode_info(op->common.aml_opcode);
		if (walk_state->op_info->flags & AML_NAMED) {
			if (op->common.aml_opcode == AML_REGION_OP ||
			    op->common.aml_opcode == AML_DATA_REGION_OP) {
				/*
				 * Skip parsing of control method or opregion body,
				 * because we don't have enough info in the first pass
				 * to parse them correctly.
				 *
				 * Completed parsing an op_region declaration, we now
				 * know the length.
				 */
				op->named.length =
				    (u32) (parser_state->aml - op->named.data);
			}
		}

		if (walk_state->op_info->flags & AML_CREATE) {
			/*
			 * Backup to beginning of create_XXXfield declaration (1 for
			 * Opcode)
			 *
			 * body_length is unknown until we parse the body
			 */
			op->named.length =
			    (u32) (parser_state->aml - op->named.data);
		}

		if (op->common.aml_opcode == AML_BANK_FIELD_OP) {
			/*
			 * Backup to beginning of bank_field declaration
			 *
			 * body_length is unknown until we parse the body
			 */
			op->named.length =
			    (u32) (parser_state->aml - op->named.data);
		}

		/* This op complete, notify the dispatcher */

		if (walk_state->ascending_callback != NULL) {
			walk_state->op = op;
			walk_state->opcode = op->common.aml_opcode;

			status = walk_state->ascending_callback(walk_state);
			status =
			    acpi_ps_next_parse_state(walk_state, op, status);
			if (status == AE_CTRL_PENDING) {
				status = AE_OK;
			} else
			    if ((walk_state->
				 parse_flags & ACPI_PARSE_MODULE_LEVEL)
				&& (ACPI_AML_EXCEPTION(status)
				    || status == AE_ALREADY_EXISTS
				    || status == AE_NOT_FOUND)) {
				/*
				 * ACPI_PARSE_MODULE_LEVEL flag means that we
				 * are currently loading a table by executing
				 * it as a control method. However, if we
				 * encounter an error while loading the table,
				 * we need to keep trying to load the table
				 * rather than aborting the table load (setting
				 * the status to AE_OK continues the table
				 * load). If we get a failure at this point, it
				 * means that the dispatcher got an error while
				 * trying to execute the Op.
				 */
				status = AE_OK;
			}
		}

		status = acpi_ps_complete_op(walk_state, &op, status);
		if (ACPI_FAILURE(status)) {
			return_ACPI_STATUS(status);
		}

	}			/* while parser_state->Aml */

	status = acpi_ps_complete_final_op(walk_state, op, status);
	return_ACPI_STATUS(status);
}
