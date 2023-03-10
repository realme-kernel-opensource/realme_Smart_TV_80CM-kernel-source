/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __CPU_SHX3_H
#define __CPU_SHX3_H

enum {
	/* PA */
	GPIO_PA7, GPIO_PA6, GPIO_PA5, GPIO_PA4,
	GPIO_PA3, GPIO_PA2, GPIO_PA1, GPIO_PA0,

	/* PB */
	GPIO_PB7, GPIO_PB6, GPIO_PB5, GPIO_PB4,
	GPIO_PB3, GPIO_PB2, GPIO_PB1, GPIO_PB0,

	/* PC */
	GPIO_PC7, GPIO_PC6, GPIO_PC5, GPIO_PC4,
	GPIO_PC3, GPIO_PC2, GPIO_PC1, GPIO_PC0,

	/* PD */
	GPIO_PD7, GPIO_PD6, GPIO_PD5, GPIO_PD4,
	GPIO_PD3, GPIO_PD2, GPIO_PD1, GPIO_PD0,

	/* PE */
	GPIO_PE7, GPIO_PE6, GPIO_PE5, GPIO_PE4,
	GPIO_PE3, GPIO_PE2, GPIO_PE1, GPIO_PE0,

	/* PF */
	GPIO_PF7, GPIO_PF6, GPIO_PF5, GPIO_PF4,
	GPIO_PF3, GPIO_PF2, GPIO_PF1, GPIO_PF0,

	/* PG */
	GPIO_PG7, GPIO_PG6, GPIO_PG5, GPIO_PG4,
	GPIO_PG3, GPIO_PG2, GPIO_PG1, GPIO_PG0,

	/* PH */
	GPIO_PH5, GPIO_PH4,
	GPIO_PH3, GPIO_PH2, GPIO_PH1, GPIO_PH0,

	/* SCIF */
	GPIO_FN_SCK3, GPIO_FN_TXD3, GPIO_FN_RXD3,
	GPIO_FN_SCK2, GPIO_FN_TXD2, GPIO_FN_RXD2,
	GPIO_FN_SCK1, GPIO_FN_TXD1, GPIO_FN_RXD1,
	GPIO_FN_SCK0, GPIO_FN_TXD0, GPIO_FN_RXD0,

	/* LBSC */
	GPIO_FN_D31, GPIO_FN_D30, GPIO_FN_D29, GPIO_FN_D28,
	GPIO_FN_D27, GPIO_FN_D26, GPIO_FN_D25, GPIO_FN_D24,
	GPIO_FN_D23, GPIO_FN_D22, GPIO_FN_D21, GPIO_FN_D20,
	GPIO_FN_D19, GPIO_FN_D18, GPIO_FN_D17, GPIO_FN_D16,
	GPIO_FN_WE3, GPIO_FN_WE2, GPIO_FN_CS6, GPIO_FN_CS5,
	GPIO_FN_CS4, GPIO_FN_CLKOUTENB, GPIO_FN_BREQ,
	GPIO_FN_IOIS16, GPIO_FN_CE2B, GPIO_FN_CE2A, GPIO_FN_BACK,

	/* DMAC */
	GPIO_FN_DACK0, GPIO_FN_DREQ0, GPIO_FN_DRAK0,
	GPIO_FN_DACK1, GPIO_FN_DREQ1, GPIO_FN_DRAK1,
	GPIO_FN_DACK2, GPIO_FN_DREQ2, GPIO_FN_DRAK2,
	GPIO_FN_DACK3, GPIO_FN_DREQ3, GPIO_FN_DRAK3,

	/* INTC */
	GPIO_FN_IRQ3, GPIO_FN_IRQ2, GPIO_FN_IRQ1, GPIO_FN_IRQ0,
	GPIO_FN_IRL3, GPIO_FN_IRL2, GPIO_FN_IRL1, GPIO_FN_IRL0,
	GPIO_FN_IRQOUT, GPIO_FN_STATUS1, GPIO_FN_STATUS0,
};

#endif /* __CPU_SHX3_H */
