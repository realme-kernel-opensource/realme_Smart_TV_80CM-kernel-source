/* SPDX-License-Identifier: GPL-2.0 */
	.section ".rodata","a"
	.balign	16
tr_idt: .fill 1, 6, 0

	.bss
	.balign	4
GLOBAL(trampoline_status)	.space	4
