/* SPDX-License-Identifier: GPL-2.0 */
/*
 * mt8173_afe_common.h  --  Mediatek 8173 audio driver common definitions
 *
 * Copyright (c) 2015 MediaTek Inc.
 * Author: Koro Chen <koro.chen@mediatek.com>
 *             Sascha Hauer <s.hauer@pengutronix.de>
 *             Hidalgo Huang <hidalgo.huang@mediatek.com>
 *             Ir Lian <ir.lian@mediatek.com>
 */

#ifndef _MT8173_AFE_COMMON_H_
#define _MT8173_AFE_COMMON_H_

#include <linux/clk.h>
#include <linux/regmap.h>

enum {
	MT8173_AFE_MEMIF_DL1,
	MT8173_AFE_MEMIF_DL2,
	MT8173_AFE_MEMIF_VUL,
	MT8173_AFE_MEMIF_DAI,
	MT8173_AFE_MEMIF_AWB,
	MT8173_AFE_MEMIF_MOD_DAI,
	MT8173_AFE_MEMIF_HDMI,
	MT8173_AFE_MEMIF_NUM,
	MT8173_AFE_IO_MOD_PCM1 = MT8173_AFE_MEMIF_NUM,
	MT8173_AFE_IO_MOD_PCM2,
	MT8173_AFE_IO_PMIC,
	MT8173_AFE_IO_I2S,
	MT8173_AFE_IO_2ND_I2S,
	MT8173_AFE_IO_HW_GAIN1,
	MT8173_AFE_IO_HW_GAIN2,
	MT8173_AFE_IO_MRG_O,
	MT8173_AFE_IO_MRG_I,
	MT8173_AFE_IO_DAIBT,
	MT8173_AFE_IO_HDMI,
};

enum {
	MT8173_AFE_IRQ_DL1,
	MT8173_AFE_IRQ_DL2,
	MT8173_AFE_IRQ_VUL,
	MT8173_AFE_IRQ_DAI,
	MT8173_AFE_IRQ_AWB,
	MT8173_AFE_IRQ_MOD_DAI,
	MT8173_AFE_IRQ_HDMI,
	MT8173_AFE_IRQ_NUM,
};

enum {
	MT8173_CLK_INFRASYS_AUD,
	MT8173_CLK_TOP_PDN_AUD,
	MT8173_CLK_TOP_PDN_AUD_BUS,
	MT8173_CLK_I2S0_M,
	MT8173_CLK_I2S1_M,
	MT8173_CLK_I2S2_M,
	MT8173_CLK_I2S3_M,
	MT8173_CLK_I2S3_B,
	MT8173_CLK_BCK0,
	MT8173_CLK_BCK1,
	MT8173_CLK_NUM
};

#endif
