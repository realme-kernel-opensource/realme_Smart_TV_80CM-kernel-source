/*
 * Debugging macro include header for Conexant Digicolor USART
 *
 * Copyright (C) 2014 Paradox Innovation Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
*/

#define UA0_STATUS	0x0742
#define UA0_EMI_REC	0x0744

#define UA0_STATUS_TX_READY	0x40

#ifdef CONFIG_DEBUG_UART_PHYS
		.macro	addruart, rp, rv, tmp
		ldr	\rp, =CONFIG_DEBUG_UART_PHYS
		ldr	\rv, =CONFIG_DEBUG_UART_VIRT
		.endm
#endif

		.macro	senduart,rd,rx
		strb	\rd, [\rx, #UA0_EMI_REC]
		.endm

		.macro	waituart,rd,rx
		.endm

	.macro	busyuart,rd,rx
1001:		ldrb	\rd, [\rx, #UA0_STATUS]
		tst	\rd, #UA0_STATUS_TX_READY
		beq	1001b
		.endm
