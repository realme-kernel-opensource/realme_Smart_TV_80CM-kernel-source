/*
 * Low-level SLB routines
 *
 * Copyright (C) 2004 David Gibson <dwg@au.ibm.com>, IBM
 *
 * Based on earlier C version:
 * Dave Engebretsen and Mike Corrigan {engebret|mikejc}@us.ibm.com
 *    Copyright (c) 2001 Dave Engebretsen
 * Copyright (C) 2002 Anton Blanchard <anton@au.ibm.com>, IBM
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version
 *  2 of the License, or (at your option) any later version.
 */

#include <asm/processor.h>
#include <asm/ppc_asm.h>
#include <asm/asm-offsets.h>
#include <asm/cputable.h>
#include <asm/page.h>
#include <asm/mmu.h>
#include <asm/pgtable.h>
#include <asm/firmware.h>
#include <asm/feature-fixups.h>

/*
 * This macro generates asm code to compute the VSID scramble
 * function.  Used in slb_allocate() and do_stab_bolted.  The function
 * computed is: (protovsid*VSID_MULTIPLIER) % VSID_MODULUS
 *
 *	rt = register containing the proto-VSID and into which the
 *		VSID will be stored
 *	rx = scratch register (clobbered)
 *	rf = flags
 *
 *	- rt and rx must be different registers
 *	- The answer will end up in the low VSID_BITS bits of rt.  The higher
 *	  bits may contain other garbage, so you may need to mask the
 *	  result.
 */
#define ASM_VSID_SCRAMBLE(rt, rx, rf, size)				\
	lis	rx,VSID_MULTIPLIER_##size@h;				\
	ori	rx,rx,VSID_MULTIPLIER_##size@l;				\
	mulld	rt,rt,rx;		/* rt = rt * MULTIPLIER */	\
/*									\
 * powermac get slb fault before feature fixup, so make 65 bit part     \
 * the default part of feature fixup					\
 */									\
BEGIN_MMU_FTR_SECTION							\
	srdi	rx,rt,VSID_BITS_65_##size;				\
	clrldi	rt,rt,(64-VSID_BITS_65_##size);				\
	add	rt,rt,rx;						\
	addi	rx,rt,1;						\
	srdi	rx,rx,VSID_BITS_65_##size;				\
	add	rt,rt,rx;						\
	rldimi	rf,rt,SLB_VSID_SHIFT_##size,(64 - (SLB_VSID_SHIFT_##size + VSID_BITS_65_##size)); \
MMU_FTR_SECTION_ELSE							\
	srdi	rx,rt,VSID_BITS_##size;					\
	clrldi	rt,rt,(64-VSID_BITS_##size);				\
	add	rt,rt,rx;		/* add high and low bits */	\
	addi	rx,rt,1;						\
	srdi	rx,rx,VSID_BITS_##size;	/* extract 2^VSID_BITS bit */	\
	add	rt,rt,rx;						\
	rldimi	rf,rt,SLB_VSID_SHIFT_##size,(64 - (SLB_VSID_SHIFT_##size + VSID_BITS_##size)); \
ALT_MMU_FTR_SECTION_END_IFCLR(MMU_FTR_68_BIT_VA)


/* void slb_allocate(unsigned long ea);
 *
 * Create an SLB entry for the given EA (user or kernel).
 * 	r3 = faulting address, r13 = PACA
 *	r9, r10, r11 are clobbered by this function
 *	r3 is preserved.
 * No other registers are examined or changed.
 */
_GLOBAL(slb_allocate)
	/*
	 * Check if the address falls within the range of the first context, or
	 * if we may need to handle multi context. For the first context we
	 * allocate the slb entry via the fast path below. For large address we
	 * branch out to C-code and see if additional contexts have been
	 * allocated.
	 * The test here is:
	 *   (ea & ~REGION_MASK) >= (1ull << MAX_EA_BITS_PER_CONTEXT)
	 */
	rldicr. r9,r3,4,(63 - MAX_EA_BITS_PER_CONTEXT - 4)
	bne-	8f

	srdi	r9,r3,60		/* get region */
	srdi	r10,r3,SID_SHIFT	/* get esid */
	cmpldi	cr7,r9,0xc		/* cmp PAGE_OFFSET for later use */

	/* r3 = address, r10 = esid, cr7 = <> PAGE_OFFSET */
	blt	cr7,0f			/* user or kernel? */

	/* Check if hitting the linear mapping or some other kernel space
	*/
	bne	cr7,1f

	/* Linear mapping encoding bits, the "li" instruction below will
	 * be patched by the kernel at boot
	 */
.globl slb_miss_kernel_load_linear
slb_miss_kernel_load_linear:
	li	r11,0
	/*
	 * context = (ea >> 60) - (0xc - 1)
	 * r9 = region id.
	 */
	subi	r9,r9,KERNEL_REGION_CONTEXT_OFFSET

BEGIN_FTR_SECTION
	b	.Lslb_finish_load
END_MMU_FTR_SECTION_IFCLR(MMU_FTR_1T_SEGMENT)
	b	.Lslb_finish_load_1T

1:
#ifdef CONFIG_SPARSEMEM_VMEMMAP
	cmpldi	cr0,r9,0xf
	bne	1f
/* Check virtual memmap region. To be patched at kernel boot */
.globl slb_miss_kernel_load_vmemmap
slb_miss_kernel_load_vmemmap:
	li	r11,0
	b	6f
1:
#endif /* CONFIG_SPARSEMEM_VMEMMAP */

	/*
	 * r10 contains the ESID, which is the original faulting EA shifted
	 * right by 28 bits. We need to compare that with (H_VMALLOC_END >> 28)
	 * which is 0xd00038000. That can't be used as an immediate, even if we
	 * ignored the 0xd, so we have to load it into a register, and we only
	 * have one register free. So we must load all of (H_VMALLOC_END >> 28)
	 * into a register and compare ESID against that.
	 */
	lis	r11,(H_VMALLOC_END >> 32)@h	// r11 = 0xffffffffd0000000
	ori	r11,r11,(H_VMALLOC_END >> 32)@l	// r11 = 0xffffffffd0003800
	// Rotate left 4, then mask with 0xffffffff0
	rldic	r11,r11,4,28			// r11 = 0xd00038000
	cmpld	r10,r11				// if r10 >= r11
	bge	5f				//   goto io_mapping

	/*
	 * vmalloc mapping gets the encoding from the PACA as the mapping
	 * can be demoted from 64K -> 4K dynamically on some machines.
	 */
	lhz	r11,PACAVMALLOCSLLP(r13)
	b	6f
5:
	/* IO mapping */
.globl slb_miss_kernel_load_io
slb_miss_kernel_load_io:
	li	r11,0
6:
	/*
	 * context = (ea >> 60) - (0xc - 1)
	 * r9 = region id.
	 */
	subi	r9,r9,KERNEL_REGION_CONTEXT_OFFSET

BEGIN_FTR_SECTION
	b	.Lslb_finish_load
END_MMU_FTR_SECTION_IFCLR(MMU_FTR_1T_SEGMENT)
	b	.Lslb_finish_load_1T

0:	/*
	 * For userspace addresses, make sure this is region 0.
	 */
	cmpdi	r9, 0
	bne-	8f
        /*
         * user space make sure we are within the allowed limit
	 */
	ld	r11,PACA_SLB_ADDR_LIMIT(r13)
	cmpld	r3,r11
	bge-	8f

	/* when using slices, we extract the psize off the slice bitmaps
	 * and then we need to get the sllp encoding off the mmu_psize_defs
	 * array.
	 *
	 * XXX This is a bit inefficient especially for the normal case,
	 * so we should try to implement a fast path for the standard page
	 * size using the old sllp value so we avoid the array. We cannot
	 * really do dynamic patching unfortunately as processes might flip
	 * between 4k and 64k standard page size
	 */
#ifdef CONFIG_PPC_MM_SLICES
	/* r10 have esid */
	cmpldi	r10,16
	/* below SLICE_LOW_TOP */
	blt	5f
	/*
	 * Handle hpsizes,
	 * r9 is get_paca()->context.high_slices_psize[index], r11 is mask_index
	 */
	srdi    r11,r10,(SLICE_HIGH_SHIFT - SLICE_LOW_SHIFT + 1) /* index */
	addi	r9,r11,PACAHIGHSLICEPSIZE
	lbzx	r9,r13,r9		/* r9 is hpsizes[r11] */
	/* r11 = (r10 >> (SLICE_HIGH_SHIFT - SLICE_LOW_SHIFT)) & 0x1 */
	rldicl	r11,r10,(64 - (SLICE_HIGH_SHIFT - SLICE_LOW_SHIFT)),63
	b	6f

5:
	/*
	 * Handle lpsizes
	 * r9 is get_paca()->context.low_slices_psize[index], r11 is mask_index
	 */
	srdi    r11,r10,1 /* index */
	addi	r9,r11,PACALOWSLICESPSIZE
	lbzx	r9,r13,r9		/* r9 is lpsizes[r11] */
	rldicl	r11,r10,0,63		/* r11 = r10 & 0x1 */
6:
	sldi	r11,r11,2  /* index * 4 */
	/* Extract the psize and multiply to get an array offset */
	srd	r9,r9,r11
	andi.	r9,r9,0xf
	mulli	r9,r9,MMUPSIZEDEFSIZE

	/* Now get to the array and obtain the sllp
	 */
	ld	r11,PACATOC(r13)
	ld	r11,mmu_psize_defs@got(r11)
	add	r11,r11,r9
	ld	r11,MMUPSIZESLLP(r11)
	ori	r11,r11,SLB_VSID_USER
#else
	/* paca context sllp already contains the SLB_VSID_USER bits */
	lhz	r11,PACACONTEXTSLLP(r13)
#endif /* CONFIG_PPC_MM_SLICES */

	ld	r9,PACACONTEXTID(r13)
BEGIN_FTR_SECTION
	cmpldi	r10,0x1000
	bge	.Lslb_finish_load_1T
END_MMU_FTR_SECTION_IFSET(MMU_FTR_1T_SEGMENT)
	b	.Lslb_finish_load

8:	/* invalid EA - return an error indication */
	crset	4*cr0+eq		/* indicate failure */
	blr

/*
 * Finish loading of an SLB entry and return
 *
 * r3 = EA, r9 = context, r10 = ESID, r11 = flags, clobbers r9, cr7 = <> PAGE_OFFSET
 */
.Lslb_finish_load:
	rldimi  r10,r9,ESID_BITS,0
	ASM_VSID_SCRAMBLE(r10,r9,r11,256M)
	/* r3 = EA, r11 = VSID data */
	/*
	 * Find a slot, round robin. Previously we tried to find a
	 * free slot first but that took too long. Unfortunately we
 	 * dont have any LRU information to help us choose a slot.
 	 */

	mr	r9,r3

	/* slb_finish_load_1T continues here. r9=EA with non-ESID bits clear */
7:	ld	r10,PACASTABRR(r13)
	addi	r10,r10,1
	/* This gets soft patched on boot. */
.globl slb_compare_rr_to_size
slb_compare_rr_to_size:
	cmpldi	r10,0

	blt+	4f
	li	r10,SLB_NUM_BOLTED

4:
	std	r10,PACASTABRR(r13)

3:
	rldimi	r9,r10,0,36		/* r9  = EA[0:35] | entry */
	oris	r10,r9,SLB_ESID_V@h	/* r10 = r9 | SLB_ESID_V */

	/* r9 = ESID data, r11 = VSID data */

	/*
	 * No need for an isync before or after this slbmte. The exception
	 * we enter with and the rfid we exit with are context synchronizing.
	 */
	slbmte	r11,r10

	/* we're done for kernel addresses */
	crclr	4*cr0+eq		/* set result to "success" */
	bgelr	cr7

	/* Update the slb cache */
	lhz	r9,PACASLBCACHEPTR(r13)	/* offset = paca->slb_cache_ptr */
	cmpldi	r9,SLB_CACHE_ENTRIES
	bge	1f

	/* still room in the slb cache */
	sldi	r11,r9,2		/* r11 = offset * sizeof(u32) */
	srdi    r10,r10,28		/* get the 36 bits of the ESID */
	add	r11,r11,r13		/* r11 = (u32 *)paca + offset */
	stw	r10,PACASLBCACHE(r11)	/* paca->slb_cache[offset] = esid */
	addi	r9,r9,1			/* offset++ */
	b	2f
1:					/* offset >= SLB_CACHE_ENTRIES */
	li	r9,SLB_CACHE_ENTRIES+1
2:
	sth	r9,PACASLBCACHEPTR(r13)	/* paca->slb_cache_ptr = offset */
	crclr	4*cr0+eq		/* set result to "success" */
	blr

/*
 * Finish loading of a 1T SLB entry (for the kernel linear mapping) and return.
 *
 * r3 = EA, r9 = context, r10 = ESID(256MB), r11 = flags, clobbers r9
 */
.Lslb_finish_load_1T:
	srdi	r10,r10,(SID_SHIFT_1T - SID_SHIFT)	/* get 1T ESID */
	rldimi  r10,r9,ESID_BITS_1T,0
	ASM_VSID_SCRAMBLE(r10,r9,r11,1T)

	li	r10,MMU_SEGSIZE_1T
	rldimi	r11,r10,SLB_VSID_SSIZE_SHIFT,0	/* insert segment size */

	/* r3 = EA, r11 = VSID data */
	clrrdi	r9,r3,SID_SHIFT_1T	/* clear out non-ESID bits */
	b	7b


_ASM_NOKPROBE_SYMBOL(slb_allocate)
_ASM_NOKPROBE_SYMBOL(slb_miss_kernel_load_linear)
_ASM_NOKPROBE_SYMBOL(slb_miss_kernel_load_io)
_ASM_NOKPROBE_SYMBOL(slb_compare_rr_to_size)
#ifdef CONFIG_SPARSEMEM_VMEMMAP
_ASM_NOKPROBE_SYMBOL(slb_miss_kernel_load_vmemmap)
#endif
