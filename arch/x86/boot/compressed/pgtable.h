#ifndef BOOT_COMPRESSED_PAGETABLE_H
#define BOOT_COMPRESSED_PAGETABLE_H

#define TRAMPOLINE_32BIT_SIZE		(2 * PAGE_SIZE)

#define TRAMPOLINE_32BIT_PGTABLE_OFFSET	0

#define TRAMPOLINE_32BIT_CODE_OFFSET	PAGE_SIZE
#define TRAMPOLINE_32BIT_CODE_SIZE	0x70

#define TRAMPOLINE_32BIT_STACK_END	TRAMPOLINE_32BIT_SIZE

#ifndef __ASSEMBLER__

extern unsigned long *trampoline_32bit;

extern void trampoline_32bit_src(void *return_ptr);

#endif /* __ASSEMBLER__ */
#endif /* BOOT_COMPRESSED_PAGETABLE_H */
