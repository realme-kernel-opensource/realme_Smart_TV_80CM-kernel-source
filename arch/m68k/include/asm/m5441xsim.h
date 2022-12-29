/* SPDX-License-Identifier: GPL-2.0 */
/*
 *	m5441xsim.h -- Coldfire 5441x register definitions
 *
 *	(C) Copyright 2012, Steven King <sfking@fdwdc.com>
*/

#ifndef m5441xsim_h
#define m5441xsim_h

#define CPU_NAME		"COLDFIRE(m5441x)"
#define CPU_INSTR_PER_JIFFY	2
#define MCF_BUSCLK		(MCF_CLK / 2)
#define MACHINE			MACH_M5441X
#define FPUTYPE			0
#define IOMEMBASE		0xe0000000
#define IOMEMSIZE		0x20000000

#include <asm/m54xxacr.h>

/*
 *  Reset Controller Module.
 */

#define	MCF_RCR			0xec090000
#define	MCF_RSR			0xec090001

#define	MCF_RCR_SWRESET		0x80		/* Software reset bit */
#define	MCF_RCR_FRCSTOUT	0x40		/* Force external reset */

/*
 *  Interrupt Controller Modules.
 */
/* the 5441x have 3 interrupt controllers, each control 64 interrupts */
#define MCFINT_VECBASE		64
#define MCFINT0_VECBASE		MCFINT_VECBASE
#define MCFINT1_VECBASE		(MCFINT0_VECBASE + 64)
#define MCFINT2_VECBASE		(MCFINT1_VECBASE + 64)

/* interrupt controller 0 */
#define MCFINTC0_SIMR		0xfc04801c
#define MCFINTC0_CIMR		0xfc04801d
#define	MCFINTC0_ICR0		0xfc048040
/* interrupt controller 1 */
#define MCFINTC1_SIMR		0xfc04c01c
#define MCFINTC1_CIMR		0xfc04c01d
#define	MCFINTC1_ICR0		0xfc04c040
/* interrupt controller 2 */
#define MCFINTC2_SIMR		0xfc05001c
#define MCFINTC2_CIMR		0xfc05001d
#define	MCFINTC2_ICR0		0xfc050040

/* on interrupt controller 0 */
#define MCFINT0_EPORT0		1
#define MCFINT0_UART0		26
#define MCFINT0_UART1		27
#define MCFINT0_UART2		28
#define MCFINT0_UART3		29
#define MCFINT0_I2C0		30
#define MCFINT0_DSPI0		31

#define MCFINT0_TIMER0		32
#define MCFINT0_TIMER1		33
#define MCFINT0_TIMER2		34
#define MCFINT0_TIMER3		35

#define MCFINT0_FECRX0		36
#define MCFINT0_FECTX0		40
#define MCFINT0_FECENTC0	42

#define MCFINT0_FECRX1		49
#define MCFINT0_FECTX1		53
#define MCFINT0_FECENTC1	55

/* on interrupt controller 1 */
#define MCFINT1_UART4		48
#define MCFINT1_UART5		49
#define MCFINT1_UART6		50
#define MCFINT1_UART7		51
#define MCFINT1_UART8		52
#define MCFINT1_UART9		53
#define MCFINT1_DSPI1		54
#define MCFINT1_DSPI2		55
#define MCFINT1_DSPI3		56
#define MCFINT1_I2C1		57
#define MCFINT1_I2C2		58
#define MCFINT1_I2C3		59
#define MCFINT1_I2C4		60
#define MCFINT1_I2C5		61

/* on interrupt controller 2 */
#define MCFINT2_PIT0		13
#define MCFINT2_PIT1		14
#define MCFINT2_PIT2		15
#define MCFINT2_PIT3		16
#define MCFINT2_RTC		26

/*
 *  PIT timer module.
 */
#define	MCFPIT_BASE0		0xFC080000	/* Base address of TIMER0 */
#define	MCFPIT_BASE1		0xFC084000	/* Base address of TIMER1 */
#define	MCFPIT_BASE2		0xFC088000	/* Base address of TIMER2 */
#define	MCFPIT_BASE3		0xFC08C000	/* Base address of TIMER3 */


#define MCF_IRQ_PIT1		(MCFINT2_VECBASE + MCFINT2_PIT1)

/*
 * Power Management
 */
#define MCFPM_WCR		0xfc040013
#define MCFPM_PPMSR0		0xfc04002c
#define MCFPM_PPMCR0		0xfc04002d
#define MCFPM_PPMSR1		0xfc04002e
#define MCFPM_PPMCR1		0xfc04002f
#define MCFPM_PPMHR0		0xfc040030
#define MCFPM_PPMLR0		0xfc040034
#define MCFPM_PPMHR1		0xfc040038
#define MCFPM_PPMLR1		0xfc04003c
#define MCFPM_LPCR		0xec090007
/*
 *  UART module.
 */
#define MCFUART_BASE0		0xfc060000	/* Base address of UART0 */
#define MCFUART_BASE1		0xfc064000	/* Base address of UART1 */
#define MCFUART_BASE2		0xfc068000	/* Base address of UART2 */
#define MCFUART_BASE3		0xfc06c000	/* Base address of UART3 */
#define MCFUART_BASE4		0xec060000	/* Base address of UART4 */
#define MCFUART_BASE5		0xec064000	/* Base address of UART5 */
#define MCFUART_BASE6		0xec068000	/* Base address of UART6 */
#define MCFUART_BASE7		0xec06c000	/* Base address of UART7 */
#define MCFUART_BASE8		0xec070000	/* Base address of UART8 */
#define MCFUART_BASE9		0xec074000	/* Base address of UART9 */

#define MCF_IRQ_UART0		(MCFINT0_VECBASE + MCFINT0_UART0)
#define MCF_IRQ_UART1		(MCFINT0_VECBASE + MCFINT0_UART1)
#define MCF_IRQ_UART2		(MCFINT0_VECBASE + MCFINT0_UART2)
#define MCF_IRQ_UART3		(MCFINT0_VECBASE + MCFINT0_UART3)
#define MCF_IRQ_UART4		(MCFINT1_VECBASE + MCFINT1_UART4)
#define MCF_IRQ_UART5		(MCFINT1_VECBASE + MCFINT1_UART5)
#define MCF_IRQ_UART6		(MCFINT1_VECBASE + MCFINT1_UART6)
#define MCF_IRQ_UART7		(MCFINT1_VECBASE + MCFINT1_UART7)
#define MCF_IRQ_UART8		(MCFINT1_VECBASE + MCFINT1_UART8)
#define MCF_IRQ_UART9		(MCFINT1_VECBASE + MCFINT1_UART9)
/*
 *  FEC modules.
 */
#define MCFFEC_BASE0		0xfc0d4000
#define MCFFEC_SIZE0		0x800
#define MCF_IRQ_FECRX0		(MCFINT0_VECBASE + MCFINT0_FECRX0)
#define MCF_IRQ_FECTX0		(MCFINT0_VECBASE + MCFINT0_FECTX0)
#define MCF_IRQ_FECENTC0	(MCFINT0_VECBASE + MCFINT0_FECENTC0)

#define MCFFEC_BASE1		0xfc0d8000
#define MCFFEC_SIZE1		0x800
#define MCF_IRQ_FECRX1		(MCFINT0_VECBASE + MCFINT0_FECRX1)
#define MCF_IRQ_FECTX1		(MCFINT0_VECBASE + MCFINT0_FECTX1)
#define MCF_IRQ_FECENTC1	(MCFINT0_VECBASE + MCFINT0_FECENTC1)
/*
 *  I2C modules.
 */
#define MCFI2C_BASE0		0xfc058000
#define MCFI2C_SIZE0		0x20
#define MCFI2C_BASE1		0xfc038000
#define MCFI2C_SIZE1		0x20
#define MCFI2C_BASE2		0xec010000
#define MCFI2C_SIZE2		0x20
#define MCFI2C_BASE3		0xec014000
#define MCFI2C_SIZE3		0x20
#define MCFI2C_BASE4		0xec018000
#define MCFI2C_SIZE4		0x20
#define MCFI2C_BASE5		0xec01c000
#define MCFI2C_SIZE5		0x20

#define MCF_IRQ_I2C0		(MCFINT0_VECBASE + MCFINT0_I2C0)
#define MCF_IRQ_I2C1		(MCFINT1_VECBASE + MCFINT1_I2C1)
#define MCF_IRQ_I2C2		(MCFINT1_VECBASE + MCFINT1_I2C2)
#define MCF_IRQ_I2C3		(MCFINT1_VECBASE + MCFINT1_I2C3)
#define MCF_IRQ_I2C4		(MCFINT1_VECBASE + MCFINT1_I2C4)
#define MCF_IRQ_I2C5		(MCFINT1_VECBASE + MCFINT1_I2C5)
/*
 *  EPORT Module.
 */
#define MCFEPORT_EPPAR		0xfc090000
#define MCFEPORT_EPIER		0xfc090003
#define MCFEPORT_EPFR		0xfc090006
/*
 *  RTC Module.
 */
#define MCFRTC_BASE		0xfc0a8000
#define MCFRTC_SIZE		(0xfc0a8840 - 0xfc0a8000)
#define MCF_IRQ_RTC		(MCFINT2_VECBASE + MCFINT2_RTC)

/*
 *  GPIO Module.
 */
#define MCFGPIO_PODR_A		0xec094000
#define MCFGPIO_PODR_B		0xec094001
#define MCFGPIO_PODR_C		0xec094002
#define MCFGPIO_PODR_D		0xec094003
#define MCFGPIO_PODR_E		0xec094004
#define MCFGPIO_PODR_F		0xec094005
#define MCFGPIO_PODR_G		0xec094006
#define MCFGPIO_PODR_H		0xec094007
#define MCFGPIO_PODR_I		0xec094008
#define MCFGPIO_PODR_J		0xec094009
#define MCFGPIO_PODR_K		0xec09400a

#define MCFGPIO_PDDR_A		0xec09400c
#define MCFGPIO_PDDR_B		0xec09400d
#define MCFGPIO_PDDR_C		0xec09400e
#define MCFGPIO_PDDR_D		0xec09400f
#define MCFGPIO_PDDR_E		0xec094010
#define MCFGPIO_PDDR_F		0xec094011
#define MCFGPIO_PDDR_G		0xec094012
#define MCFGPIO_PDDR_H		0xec094013
#define MCFGPIO_PDDR_I		0xec094014
#define MCFGPIO_PDDR_J		0xec094015
#define MCFGPIO_PDDR_K		0xec094016

#define MCFGPIO_PPDSDR_A	0xec094018
#define MCFGPIO_PPDSDR_B	0xec094019
#define MCFGPIO_PPDSDR_C	0xec09401a
#define MCFGPIO_PPDSDR_D	0xec09401b
#define MCFGPIO_PPDSDR_E	0xec09401c
#define MCFGPIO_PPDSDR_F	0xec09401d
#define MCFGPIO_PPDSDR_G	0xec09401e
#define MCFGPIO_PPDSDR_H	0xec09401f
#define MCFGPIO_PPDSDR_I	0xec094020
#define MCFGPIO_PPDSDR_J	0xec094021
#define MCFGPIO_PPDSDR_K	0xec094022

#define MCFGPIO_PCLRR_A		0xec094024
#define MCFGPIO_PCLRR_B		0xec094025
#define MCFGPIO_PCLRR_C		0xec094026
#define MCFGPIO_PCLRR_D		0xec094027
#define MCFGPIO_PCLRR_E		0xec094028
#define MCFGPIO_PCLRR_F		0xec094029
#define MCFGPIO_PCLRR_G		0xec09402a
#define MCFGPIO_PCLRR_H		0xec09402b
#define MCFGPIO_PCLRR_I		0xec09402c
#define MCFGPIO_PCLRR_J		0xec09402d
#define MCFGPIO_PCLRR_K		0xec09402e

#define MCFGPIO_PAR_FBCTL	0xec094048
#define MCFGPIO_PAR_BE		0xec094049
#define MCFGPIO_PAR_CS		0xec09404a
#define MCFGPIO_PAR_CANI2C	0xec09404b
#define MCFGPIO_PAR_IRQ0H	0xec09404c
#define MCFGPIO_PAR_IRQ0L	0xec09404d
#define MCFGPIO_PAR_DSPIOWH	0xec09404e
#define MCFGPIO_PAR_DSPIOWL	0xec09404f
#define MCFGPIO_PAR_TIMER	0xec094050
#define MCFGPIO_PAR_UART2	0xec094051
#define MCFGPIO_PAR_UART1	0xec094052
#define MCFGPIO_PAR_UART0	0xec094053
#define MCFGPIO_PAR_SDHCH	0xec094054
#define MCFGPIO_PAR_SDHCL	0xec094055
#define MCFGPIO_PAR_SIMP0H	0xec094056
#define MCFGPIO_PAR_SIMP0L	0xec094057
#define MCFGPIO_PAR_SSI0H	0xec094058
#define MCFGPIO_PAR_SSI0L	0xec094059
#define MCFGPIO_PAR_DEBUGH1	0xec09405a
#define MCFGPIO_PAR_DEBUGH0	0xec09405b
#define MCFGPIO_PAR_DEBUGl	0xec09405c
#define MCFGPIO_PAR_FEC		0xec09405e

/* generalization for generic gpio support */
#define MCFGPIO_PODR		MCFGPIO_PODR_A
#define MCFGPIO_PDDR		MCFGPIO_PDDR_A
#define MCFGPIO_PPDR		MCFGPIO_PPDSDR_A
#define MCFGPIO_SETR		MCFGPIO_PPDSDR_A
#define MCFGPIO_CLRR		MCFGPIO_PCLRR_A

#define MCFGPIO_IRQ_MIN		17
#define MCFGPIO_IRQ_MAX		24
#define MCFGPIO_IRQ_VECBASE	(MCFINT_VECBASE - MCFGPIO_IRQ_MIN)
#define MCFGPIO_PIN_MAX		87

/*
 *  DSPI module.
 */
#define MCFDSPI_BASE0		0xfc05c000
#define MCF_IRQ_DSPI0		(MCFINT0_VECBASE + MCFINT0_DSPI0)

#endif /* m5441xsim_h */
