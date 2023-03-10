/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _ADDI_TCW_H
#define _ADDI_TCW_H

/*
 * Following are the generic definitions for the ADDI-DATA timer/counter/
 * watchdog (TCW) registers and bits. Some of the registers are not used
 * depending on the use of the TCW.
 */

#define ADDI_TCW_VAL_REG		0x00

#define ADDI_TCW_SYNC_REG		0x00
#define ADDI_TCW_SYNC_CTR_TRIG		BIT(8)
#define ADDI_TCW_SYNC_CTR_DIS		BIT(7)
#define ADDI_TCW_SYNC_CTR_ENA		BIT(6)
#define ADDI_TCW_SYNC_TIMER_TRIG	BIT(5)
#define ADDI_TCW_SYNC_TIMER_DIS		BIT(4)
#define ADDI_TCW_SYNC_TIMER_ENA		BIT(3)
#define ADDI_TCW_SYNC_WDOG_TRIG		BIT(2)
#define ADDI_TCW_SYNC_WDOG_DIS		BIT(1)
#define ADDI_TCW_SYNC_WDOG_ENA		BIT(0)

#define ADDI_TCW_RELOAD_REG		0x04

#define ADDI_TCW_TIMEBASE_REG		0x08

#define ADDI_TCW_CTRL_REG		0x0c
#define ADDI_TCW_CTRL_EXT_CLK_STATUS	BIT(21)
#define ADDI_TCW_CTRL_CASCADE		BIT(20)
#define ADDI_TCW_CTRL_CNTR_ENA		BIT(19)
#define ADDI_TCW_CTRL_CNT_UP		BIT(18)
#define ADDI_TCW_CTRL_EXT_CLK(x)	(((x) & 3) << 16)
#define ADDI_TCW_CTRL_EXT_CLK_MASK	ADDI_TCW_CTRL_EXT_CLK(3)
#define ADDI_TCW_CTRL_MODE(x)		(((x) & 7) << 13)
#define ADDI_TCW_CTRL_MODE_MASK		ADDI_TCW_CTRL_MODE(7)
#define ADDI_TCW_CTRL_OUT(x)		(((x) & 3) << 11)
#define ADDI_TCW_CTRL_OUT_MASK		ADDI_TCW_CTRL_OUT(3)
#define ADDI_TCW_CTRL_GATE		BIT(10)
#define ADDI_TCW_CTRL_TRIG		BIT(9)
#define ADDI_TCW_CTRL_EXT_GATE(x)	(((x) & 3) << 7)
#define ADDI_TCW_CTRL_EXT_GATE_MASK	ADDI_TCW_CTRL_EXT_GATE(3)
#define ADDI_TCW_CTRL_EXT_TRIG(x)	(((x) & 3) << 5)
#define ADDI_TCW_CTRL_EXT_TRIG_MASK	ADDI_TCW_CTRL_EXT_TRIG(3)
#define ADDI_TCW_CTRL_TIMER_ENA		BIT(4)
#define ADDI_TCW_CTRL_RESET_ENA		BIT(3)
#define ADDI_TCW_CTRL_WARN_ENA		BIT(2)
#define ADDI_TCW_CTRL_IRQ_ENA		BIT(1)
#define ADDI_TCW_CTRL_ENA		BIT(0)

#define ADDI_TCW_STATUS_REG		0x10
#define ADDI_TCW_STATUS_SOFT_CLR	BIT(3)
#define ADDI_TCW_STATUS_HARDWARE_TRIG	BIT(2)
#define ADDI_TCW_STATUS_SOFT_TRIG	BIT(1)
#define ADDI_TCW_STATUS_OVERFLOW	BIT(0)

#define ADDI_TCW_IRQ_REG		0x14
#define ADDI_TCW_IRQ			BIT(0)

#define ADDI_TCW_WARN_TIMEVAL_REG	0x18

#define ADDI_TCW_WARN_TIMEBASE_REG	0x1c

#endif
