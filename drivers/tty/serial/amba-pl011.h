/* SPDX-License-Identifier: GPL-2.0 */
#ifndef AMBA_PL011_H
#define AMBA_PL011_H

enum {
	REG_DR,
	REG_ST_DMAWM,
	REG_ST_TIMEOUT,
	REG_FR,
	REG_LCRH_RX,
	REG_LCRH_TX,
	REG_IBRD,
	REG_FBRD,
	REG_CR,
	REG_IFLS,
	REG_IMSC,
	REG_RIS,
	REG_MIS,
	REG_ICR,
	REG_DMACR,
	REG_ST_XFCR,
	REG_ST_XON1,
	REG_ST_XON2,
	REG_ST_XOFF1,
	REG_ST_XOFF2,
	REG_ST_ITCR,
	REG_ST_ITIP,
	REG_ST_ABCR,
	REG_ST_ABIMSC,

	/* The size of the array - must be last */
	REG_ARRAY_SIZE,
};

#endif
