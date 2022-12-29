#ifndef SHADOW_FIELD_RO
#define SHADOW_FIELD_RO(x)
#endif
#ifndef SHADOW_FIELD_RW
#define SHADOW_FIELD_RW(x)
#endif

/*
 * We do NOT shadow fields that are modified when L0
 * traps and emulates any vmx instruction (e.g. VMPTRLD,
 * VMXON...) executed by L1.
 * For example, VM_INSTRUCTION_ERROR is read
 * by L1 if a vmx instruction fails (part of the error path).
 * Note the code assumes this logic. If for some reason
 * we start shadowing these fields then we need to
 * force a shadow sync when L0 emulates vmx instructions
 * (e.g. force a sync if VM_INSTRUCTION_ERROR is modified
 * by nested_vmx_failValid)
 *
 * When adding or removing fields here, note that shadowed
 * fields must always be synced by prepare_vmcs02, not just
 * prepare_vmcs02_full.
 */

/*
 * Keeping the fields ordered by size is an attempt at improving
 * branch prediction in vmcs_read_any and vmcs_write_any.
 */

/* 16-bits */
SHADOW_FIELD_RW(GUEST_CS_SELECTOR)
SHADOW_FIELD_RW(GUEST_INTR_STATUS)
SHADOW_FIELD_RW(GUEST_PML_INDEX)
SHADOW_FIELD_RW(HOST_FS_SELECTOR)
SHADOW_FIELD_RW(HOST_GS_SELECTOR)

/* 32-bits */
SHADOW_FIELD_RO(VM_EXIT_REASON)
SHADOW_FIELD_RO(VM_EXIT_INTR_INFO)
SHADOW_FIELD_RO(VM_EXIT_INSTRUCTION_LEN)
SHADOW_FIELD_RO(IDT_VECTORING_INFO_FIELD)
SHADOW_FIELD_RO(IDT_VECTORING_ERROR_CODE)
SHADOW_FIELD_RO(VM_EXIT_INTR_ERROR_CODE)
SHADOW_FIELD_RW(CPU_BASED_VM_EXEC_CONTROL)
SHADOW_FIELD_RW(EXCEPTION_BITMAP)
SHADOW_FIELD_RW(VM_ENTRY_EXCEPTION_ERROR_CODE)
SHADOW_FIELD_RW(VM_ENTRY_INTR_INFO_FIELD)
SHADOW_FIELD_RW(VM_ENTRY_INSTRUCTION_LEN)
SHADOW_FIELD_RW(TPR_THRESHOLD)
SHADOW_FIELD_RW(GUEST_CS_LIMIT)
SHADOW_FIELD_RW(GUEST_CS_AR_BYTES)
SHADOW_FIELD_RW(GUEST_INTERRUPTIBILITY_INFO)
SHADOW_FIELD_RW(VMX_PREEMPTION_TIMER_VALUE)

/* Natural width */
SHADOW_FIELD_RO(EXIT_QUALIFICATION)
SHADOW_FIELD_RO(GUEST_LINEAR_ADDRESS)
SHADOW_FIELD_RW(GUEST_RIP)
SHADOW_FIELD_RW(GUEST_RSP)
SHADOW_FIELD_RW(GUEST_CR0)
SHADOW_FIELD_RW(GUEST_CR3)
SHADOW_FIELD_RW(GUEST_CR4)
SHADOW_FIELD_RW(GUEST_RFLAGS)
SHADOW_FIELD_RW(GUEST_CS_BASE)
SHADOW_FIELD_RW(GUEST_ES_BASE)
SHADOW_FIELD_RW(CR0_GUEST_HOST_MASK)
SHADOW_FIELD_RW(CR0_READ_SHADOW)
SHADOW_FIELD_RW(CR4_READ_SHADOW)
SHADOW_FIELD_RW(HOST_FS_BASE)
SHADOW_FIELD_RW(HOST_GS_BASE)

/* 64-bit */
SHADOW_FIELD_RO(GUEST_PHYSICAL_ADDRESS)
SHADOW_FIELD_RO(GUEST_PHYSICAL_ADDRESS_HIGH)

#undef SHADOW_FIELD_RO
#undef SHADOW_FIELD_RW
