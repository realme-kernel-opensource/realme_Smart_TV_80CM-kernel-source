/* SPDX-License-Identifier: GPL-2.0 */
/*
 * realmode.lds.S
 *
 * Linker script for the real-mode code
 */

#include <asm/page_types.h>

#undef i386

OUTPUT_FORMAT("elf32-i386", "elf32-i386", "elf32-i386")
OUTPUT_ARCH(i386)

SECTIONS
{
	real_mode_seg = 0;

	. = 0;
	.header : {
		pa_real_mode_base = .;
		*(.header)
	}

	. = ALIGN(4);
	.rodata : {
		*(.rodata)
		*(.rodata.*)
		. = ALIGN(16);
		video_cards = .;
		*(.videocards)
		video_cards_end = .;
	}

	. = ALIGN(PAGE_SIZE);
	pa_text_start = .;
	.text : {
		*(.text)
		*(.text.*)
	}

	.text32 : {
		*(.text32)
		*(.text32.*)
	}

	.text64 : {
		*(.text64)
		*(.text64.*)
	}
	pa_ro_end = .;

	. = ALIGN(PAGE_SIZE);
	.data : {
		*(.data)
		*(.data.*)
	}

	. = ALIGN(128);
	.bss : {
		*(.bss*)
	}

	/* End signature for integrity checking */
	. = ALIGN(4);
	.signature : {
		*(.signature)
	}

	/DISCARD/ : {
		*(.note*)
		*(.debug*)
		*(.eh_frame*)
	}

#include "pasyms.h"
}
