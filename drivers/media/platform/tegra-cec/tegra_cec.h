/*
 * Tegra CEC register definitions
 *
 * The original 3.10 CEC driver using a custom API:
 *
 * Copyright (c) 2012-2015, NVIDIA CORPORATION.  All rights reserved.
 *
 * Conversion to the CEC framework and to the mainline kernel:
 *
 * Copyright 2016-2017 Cisco Systems, Inc. and/or its affiliates. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TEGRA_CEC_H
#define TEGRA_CEC_H

/* CEC registers */
#define TEGRA_CEC_SW_CONTROL	0x000
#define TEGRA_CEC_HW_CONTROL	0x004
#define TEGRA_CEC_INPUT_FILTER	0x008
#define TEGRA_CEC_TX_REGISTER	0x010
#define TEGRA_CEC_RX_REGISTER	0x014
#define TEGRA_CEC_RX_TIMING_0	0x018
#define TEGRA_CEC_RX_TIMING_1	0x01c
#define TEGRA_CEC_RX_TIMING_2	0x020
#define TEGRA_CEC_TX_TIMING_0	0x024
#define TEGRA_CEC_TX_TIMING_1	0x028
#define TEGRA_CEC_TX_TIMING_2	0x02c
#define TEGRA_CEC_INT_STAT	0x030
#define TEGRA_CEC_INT_MASK	0x034
#define TEGRA_CEC_HW_DEBUG_RX	0x038
#define TEGRA_CEC_HW_DEBUG_TX	0x03c

#define TEGRA_CEC_HWCTRL_RX_LADDR_MASK				0x7fff
#define TEGRA_CEC_HWCTRL_RX_LADDR(x)	\
	((x) & TEGRA_CEC_HWCTRL_RX_LADDR_MASK)
#define TEGRA_CEC_HWCTRL_RX_SNOOP				(1 << 15)
#define TEGRA_CEC_HWCTRL_RX_NAK_MODE				(1 << 16)
#define TEGRA_CEC_HWCTRL_TX_NAK_MODE				(1 << 24)
#define TEGRA_CEC_HWCTRL_FAST_SIM_MODE				(1 << 30)
#define TEGRA_CEC_HWCTRL_TX_RX_MODE				(1 << 31)

#define TEGRA_CEC_INPUT_FILTER_MODE				(1 << 31)
#define TEGRA_CEC_INPUT_FILTER_FIFO_LENGTH_SHIFT		0

#define TEGRA_CEC_TX_REG_DATA_SHIFT				0
#define TEGRA_CEC_TX_REG_EOM					(1 << 8)
#define TEGRA_CEC_TX_REG_BCAST					(1 << 12)
#define TEGRA_CEC_TX_REG_START_BIT				(1 << 16)
#define TEGRA_CEC_TX_REG_RETRY					(1 << 17)

#define TEGRA_CEC_RX_REGISTER_SHIFT				0
#define TEGRA_CEC_RX_REGISTER_EOM				(1 << 8)
#define TEGRA_CEC_RX_REGISTER_ACK				(1 << 9)

#define TEGRA_CEC_RX_TIM0_START_BIT_MAX_LO_TIME_SHIFT		0
#define TEGRA_CEC_RX_TIM0_START_BIT_MIN_LO_TIME_SHIFT		8
#define TEGRA_CEC_RX_TIM0_START_BIT_MAX_DURATION_SHIFT		16
#define TEGRA_CEC_RX_TIM0_START_BIT_MIN_DURATION_SHIFT		24

#define TEGRA_CEC_RX_TIM1_DATA_BIT_MAX_LO_TIME_SHIFT		0
#define TEGRA_CEC_RX_TIM1_DATA_BIT_SAMPLE_TIME_SHIFT		8
#define TEGRA_CEC_RX_TIM1_DATA_BIT_MAX_DURATION_SHIFT		16
#define TEGRA_CEC_RX_TIM1_DATA_BIT_MIN_DURATION_SHIFT		24

#define TEGRA_CEC_RX_TIM2_END_OF_BLOCK_TIME_SHIFT		0

#define TEGRA_CEC_TX_TIM0_START_BIT_LO_TIME_SHIFT		0
#define TEGRA_CEC_TX_TIM0_START_BIT_DURATION_SHIFT		8
#define TEGRA_CEC_TX_TIM0_BUS_XITION_TIME_SHIFT			16
#define TEGRA_CEC_TX_TIM0_BUS_ERROR_LO_TIME_SHIFT		24

#define TEGRA_CEC_TX_TIM1_LO_DATA_BIT_LO_TIME_SHIFT		0
#define TEGRA_CEC_TX_TIM1_HI_DATA_BIT_LO_TIME_SHIFT		8
#define TEGRA_CEC_TX_TIM1_DATA_BIT_DURATION_SHIFT		16
#define TEGRA_CEC_TX_TIM1_ACK_NAK_BIT_SAMPLE_TIME_SHIFT		24

#define TEGRA_CEC_TX_TIM2_BUS_IDLE_TIME_ADDITIONAL_FRAME_SHIFT	0
#define TEGRA_CEC_TX_TIM2_BUS_IDLE_TIME_NEW_FRAME_SHIFT		4
#define TEGRA_CEC_TX_TIM2_BUS_IDLE_TIME_RETRY_FRAME_SHIFT	8

#define TEGRA_CEC_INT_STAT_TX_REGISTER_EMPTY			(1 << 0)
#define TEGRA_CEC_INT_STAT_TX_REGISTER_UNDERRUN			(1 << 1)
#define TEGRA_CEC_INT_STAT_TX_FRAME_OR_BLOCK_NAKD		(1 << 2)
#define TEGRA_CEC_INT_STAT_TX_ARBITRATION_FAILED		(1 << 3)
#define TEGRA_CEC_INT_STAT_TX_BUS_ANOMALY_DETECTED		(1 << 4)
#define TEGRA_CEC_INT_STAT_TX_FRAME_TRANSMITTED			(1 << 5)
#define TEGRA_CEC_INT_STAT_RX_REGISTER_FULL			(1 << 8)
#define TEGRA_CEC_INT_STAT_RX_REGISTER_OVERRUN			(1 << 9)
#define TEGRA_CEC_INT_STAT_RX_START_BIT_DETECTED		(1 << 10)
#define TEGRA_CEC_INT_STAT_RX_BUS_ANOMALY_DETECTED		(1 << 11)
#define TEGRA_CEC_INT_STAT_RX_BUS_ERROR_DETECTED		(1 << 12)
#define TEGRA_CEC_INT_STAT_FILTERED_RX_DATA_PIN_TRANSITION_H2L	(1 << 13)
#define TEGRA_CEC_INT_STAT_FILTERED_RX_DATA_PIN_TRANSITION_L2H	(1 << 14)

#define TEGRA_CEC_INT_MASK_TX_REGISTER_EMPTY			(1 << 0)
#define TEGRA_CEC_INT_MASK_TX_REGISTER_UNDERRUN			(1 << 1)
#define TEGRA_CEC_INT_MASK_TX_FRAME_OR_BLOCK_NAKD		(1 << 2)
#define TEGRA_CEC_INT_MASK_TX_ARBITRATION_FAILED		(1 << 3)
#define TEGRA_CEC_INT_MASK_TX_BUS_ANOMALY_DETECTED		(1 << 4)
#define TEGRA_CEC_INT_MASK_TX_FRAME_TRANSMITTED			(1 << 5)
#define TEGRA_CEC_INT_MASK_RX_REGISTER_FULL			(1 << 8)
#define TEGRA_CEC_INT_MASK_RX_REGISTER_OVERRUN			(1 << 9)
#define TEGRA_CEC_INT_MASK_RX_START_BIT_DETECTED		(1 << 10)
#define TEGRA_CEC_INT_MASK_RX_BUS_ANOMALY_DETECTED		(1 << 11)
#define TEGRA_CEC_INT_MASK_RX_BUS_ERROR_DETECTED		(1 << 12)
#define TEGRA_CEC_INT_MASK_FILTERED_RX_DATA_PIN_TRANSITION_H2L	(1 << 13)
#define TEGRA_CEC_INT_MASK_FILTERED_RX_DATA_PIN_TRANSITION_L2H	(1 << 14)

#define TEGRA_CEC_HW_DEBUG_TX_DURATION_COUNT_SHIFT		0
#define TEGRA_CEC_HW_DEBUG_TX_TXBIT_COUNT_SHIFT			17
#define TEGRA_CEC_HW_DEBUG_TX_STATE_SHIFT			21
#define TEGRA_CEC_HW_DEBUG_TX_FORCELOOUT			(1 << 25)
#define TEGRA_CEC_HW_DEBUG_TX_TXDATABIT_SAMPLE_TIMER		(1 << 26)

#endif /* TEGRA_CEC_H */
