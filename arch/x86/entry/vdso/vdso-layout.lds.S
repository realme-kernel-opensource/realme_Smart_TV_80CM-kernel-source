/* SPDX-License-Identifier: GPL-2.0 */
#include <asm/vdso.h>

/*
 * Linker script for vDSO.  This is an ELF shared object prelinked to
 * its virtual address, and with only one read-only segment.
 * This script controls its layout.
 */

#if defined(BUILD_VDSO64)
# define SHDR_SIZE 64
#elif defined(BUILD_VDSO32) || defined(BUILD_VDSOX32)
# define SHDR_SIZE 40
#else
# error unknown VDSO target
#endif

#define NUM_FAKE_SHDRS 13

SECTIONS
{
	/*
	 * User/kernel shared data is before the vDSO.  This may be a little
	 * uglier than putting it after the vDSO, but it avoids issues with
	 * non-allocatable things that dangle past the end of the PT_LOAD
	 * segment.
	 */

	vvar_start = . - 3 * PAGE_SIZE;
	vvar_page = vvar_start;

	/* Place all vvars at the offsets in asm/vvar.h. */
#define EMIT_VVAR(name, offset) vvar_ ## name = vvar_page + offset;
#define __VVAR_KERNEL_LDS
#include <asm/vvar.h>
#undef __VVAR_KERNEL_LDS
#undef EMIT_VVAR

	pvclock_page = vvar_start + PAGE_SIZE;
	hvclock_page = vvar_start + 2 * PAGE_SIZE;

	. = SIZEOF_HEADERS;

	.hash		: { *(.hash) }			:text
	.gnu.hash	: { *(.gnu.hash) }
	.dynsym		: { *(.dynsym) }
	.dynstr		: { *(.dynstr) }
	.gnu.version	: { *(.gnu.version) }
	.gnu.version_d	: { *(.gnu.version_d) }
	.gnu.version_r	: { *(.gnu.version_r) }

	.dynamic	: { *(.dynamic) }		:text	:dynamic

	.rodata		: {
		*(.rodata*)
		*(.data*)
		*(.sdata*)
		*(.got.plt) *(.got)
		*(.gnu.linkonce.d.*)
		*(.bss*)
		*(.dynbss*)
		*(.gnu.linkonce.b.*)

		/*
		 * Ideally this would live in a C file, but that won't
		 * work cleanly for x32 until we start building the x32
		 * C code using an x32 toolchain.
		 */
		VDSO_FAKE_SECTION_TABLE_START = .;
		. = . + NUM_FAKE_SHDRS * SHDR_SIZE;
		VDSO_FAKE_SECTION_TABLE_END = .;
	}						:text

	.fake_shstrtab	: { *(.fake_shstrtab) }		:text


	.note		: { *(.note.*) }		:text	:note

	.eh_frame_hdr	: { *(.eh_frame_hdr) }		:text	:eh_frame_hdr
	.eh_frame	: { KEEP (*(.eh_frame)) }	:text


	/*
	 * Text is well-separated from actual data: there's plenty of
	 * stuff that isn't used at runtime in between.
	 */

	.text		: { *(.text*) }			:text	=0x90909090,

	/*
	 * At the end so that eu-elflint stays happy when vdso2c strips
	 * these.  A better implementation would avoid allocating space
	 * for these.
	 */
	.altinstructions	: { *(.altinstructions) }	:text
	.altinstr_replacement	: { *(.altinstr_replacement) }	:text

	/DISCARD/ : {
		*(.discard)
		*(.discard.*)
		*(__bug_table)
	}
}

/*
 * Very old versions of ld do not recognize this name token; use the constant.
 */
#define PT_GNU_EH_FRAME	0x6474e550

/*
 * We must supply the ELF program headers explicitly to get just one
 * PT_LOAD segment, and set the flags explicitly to make segments read-only.
 */
PHDRS
{
	text		PT_LOAD		FLAGS(5) FILEHDR PHDRS; /* PF_R|PF_X */
	dynamic		PT_DYNAMIC	FLAGS(4);		/* PF_R */
	note		PT_NOTE		FLAGS(4);		/* PF_R */
	eh_frame_hdr	PT_GNU_EH_FRAME;
}
