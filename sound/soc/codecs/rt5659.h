/*
 * rt5659.h  --  RT5659/RT5658 ALSA SoC audio driver
 *
 * Copyright 2015 Realtek Microelectronics
 * Author: Bard Liao <bardliao@realtek.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __RT5659_H__
#define __RT5659_H__

#include <sound/rt5659.h>

#define DEVICE_ID 0x6311

/* Info */
#define RT5659_RESET				0x0000
#define RT5659_VENDOR_ID			0x00fd
#define RT5659_VENDOR_ID_1			0x00fe
#define RT5659_DEVICE_ID			0x00ff
/*  I/O - Output */
#define RT5659_SPO_VOL				0x0001
#define RT5659_HP_VOL				0x0002
#define RT5659_LOUT				0x0003
#define RT5659_MONO_OUT				0x0004
#define RT5659_HPL_GAIN				0x0005
#define RT5659_HPR_GAIN				0x0006
#define RT5659_MONO_GAIN			0x0007
#define RT5659_SPDIF_CTRL_1			0x0008
#define RT5659_SPDIF_CTRL_2			0x0009
/* I/O - Input */
#define RT5659_CAL_BST_CTRL			0x000a
#define RT5659_IN1_IN2				0x000c
#define RT5659_IN3_IN4				0x000d
#define RT5659_INL1_INR1_VOL			0x000f
/* I/O - Speaker */
#define RT5659_EJD_CTRL_1			0x0010
#define RT5659_EJD_CTRL_2			0x0011
#define RT5659_EJD_CTRL_3			0x0012
#define RT5659_SILENCE_CTRL			0x0015
#define RT5659_PSV_CTRL				0x0016
/* I/O - Sidetone */
#define RT5659_SIDETONE_CTRL			0x0018
/* I/O - ADC/DAC/DMIC */
#define RT5659_DAC1_DIG_VOL			0x0019
#define RT5659_DAC2_DIG_VOL			0x001a
#define RT5659_DAC_CTRL				0x001b
#define RT5659_STO1_ADC_DIG_VOL			0x001c
#define RT5659_MONO_ADC_DIG_VOL			0x001d
#define RT5659_STO2_ADC_DIG_VOL			0x001e
#define RT5659_STO1_BOOST			0x001f
#define RT5659_MONO_BOOST			0x0020
#define RT5659_STO2_BOOST			0x0021
#define RT5659_HP_IMP_GAIN_1			0x0022
#define RT5659_HP_IMP_GAIN_2			0x0023
/* Mixer - D-D */
#define RT5659_STO1_ADC_MIXER			0x0026
#define RT5659_MONO_ADC_MIXER			0x0027
#define RT5659_AD_DA_MIXER			0x0029
#define RT5659_STO_DAC_MIXER			0x002a
#define RT5659_MONO_DAC_MIXER			0x002b
#define RT5659_DIG_MIXER			0x002c
#define RT5659_A_DAC_MUX			0x002d
#define RT5659_DIG_INF23_DATA			0x002f
/* Mixer - PDM */
#define RT5659_PDM_OUT_CTRL			0x0031
#define RT5659_PDM_DATA_CTRL_1			0x0032
#define RT5659_PDM_DATA_CTRL_2			0x0033
#define RT5659_PDM_DATA_CTRL_3			0x0034
#define RT5659_PDM_DATA_CTRL_4			0x0035
#define RT5659_SPDIF_CTRL			0x0036

/* Mixer - ADC */
#define RT5659_REC1_GAIN			0x003a
#define RT5659_REC1_L1_MIXER			0x003b
#define RT5659_REC1_L2_MIXER			0x003c
#define RT5659_REC1_R1_MIXER			0x003d
#define RT5659_REC1_R2_MIXER			0x003e
#define RT5659_CAL_REC				0x0040
#define RT5659_REC2_L1_MIXER			0x009b
#define RT5659_REC2_L2_MIXER			0x009c
#define RT5659_REC2_R1_MIXER			0x009d
#define RT5659_REC2_R2_MIXER			0x009e
#define RT5659_RC_CLK_CTRL			0x009f
/* Mixer - DAC */
#define RT5659_SPK_L_MIXER			0x0046
#define RT5659_SPK_R_MIXER			0x0047
#define RT5659_SPO_AMP_GAIN			0x0048
#define RT5659_ALC_BACK_GAIN			0x0049
#define RT5659_MONOMIX_GAIN			0x004a
#define RT5659_MONOMIX_IN_GAIN			0x004b
#define RT5659_OUT_L_GAIN			0x004d
#define RT5659_OUT_L_MIXER			0x004e
#define RT5659_OUT_R_GAIN			0x004f
#define RT5659_OUT_R_MIXER			0x0050
#define RT5659_LOUT_MIXER			0x0052

#define RT5659_HAPTIC_GEN_CTRL_1		0x0053
#define RT5659_HAPTIC_GEN_CTRL_2		0x0054
#define RT5659_HAPTIC_GEN_CTRL_3		0x0055
#define RT5659_HAPTIC_GEN_CTRL_4		0x0056
#define RT5659_HAPTIC_GEN_CTRL_5		0x0057
#define RT5659_HAPTIC_GEN_CTRL_6		0x0058
#define RT5659_HAPTIC_GEN_CTRL_7		0x0059
#define RT5659_HAPTIC_GEN_CTRL_8		0x005a
#define RT5659_HAPTIC_GEN_CTRL_9		0x005b
#define RT5659_HAPTIC_GEN_CTRL_10		0x005c
#define RT5659_HAPTIC_GEN_CTRL_11		0x005d
#define RT5659_HAPTIC_LPF_CTRL_1		0x005e
#define RT5659_HAPTIC_LPF_CTRL_2		0x005f
#define RT5659_HAPTIC_LPF_CTRL_3		0x0060
/* Power */
#define RT5659_PWR_DIG_1			0x0061
#define RT5659_PWR_DIG_2			0x0062
#define RT5659_PWR_ANLG_1			0x0063
#define RT5659_PWR_ANLG_2			0x0064
#define RT5659_PWR_ANLG_3			0x0065
#define RT5659_PWR_MIXER			0x0066
#define RT5659_PWR_VOL				0x0067
/* Private Register Control */
#define RT5659_PRIV_INDEX			0x006a
#define RT5659_CLK_DET				0x006b
#define RT5659_PRIV_DATA			0x006c
/* System Clock Pre Divider Gating Control */
#define RT5659_PRE_DIV_1			0x006e
#define RT5659_PRE_DIV_2			0x006f
/* Format - ADC/DAC */
#define RT5659_I2S1_SDP				0x0070
#define RT5659_I2S2_SDP				0x0071
#define RT5659_I2S3_SDP				0x0072
#define RT5659_ADDA_CLK_1			0x0073
#define RT5659_ADDA_CLK_2			0x0074
#define RT5659_DMIC_CTRL_1			0x0075
#define RT5659_DMIC_CTRL_2			0x0076
/* Format - TDM Control */
#define RT5659_TDM_CTRL_1			0x0077
#define RT5659_TDM_CTRL_2			0x0078
#define RT5659_TDM_CTRL_3			0x0079
#define RT5659_TDM_CTRL_4			0x007a
#define RT5659_TDM_CTRL_5			0x007b

/* Function - Analog */
#define RT5659_GLB_CLK				0x0080
#define RT5659_PLL_CTRL_1			0x0081
#define RT5659_PLL_CTRL_2			0x0082
#define RT5659_ASRC_1				0x0083
#define RT5659_ASRC_2				0x0084
#define RT5659_ASRC_3				0x0085
#define RT5659_ASRC_4				0x0086
#define RT5659_ASRC_5				0x0087
#define RT5659_ASRC_6				0x0088
#define RT5659_ASRC_7				0x0089
#define RT5659_ASRC_8				0x008a
#define RT5659_ASRC_9				0x008b
#define RT5659_ASRC_10				0x008c
#define RT5659_DEPOP_1				0x008e
#define RT5659_DEPOP_2				0x008f
#define RT5659_DEPOP_3				0x0090
#define RT5659_HP_CHARGE_PUMP_1			0x0091
#define RT5659_HP_CHARGE_PUMP_2			0x0092
#define RT5659_MICBIAS_1			0x0093
#define RT5659_MICBIAS_2			0x0094
#define RT5659_ASRC_11				0x0097
#define RT5659_ASRC_12				0x0098
#define RT5659_ASRC_13				0x0099
#define RT5659_REC_M1_M2_GAIN_CTRL		0x009a
#define RT5659_CLASSD_CTRL_1			0x00a0
#define RT5659_CLASSD_CTRL_2			0x00a1

/* Function - Digital */
#define RT5659_ADC_EQ_CTRL_1			0x00ae
#define RT5659_ADC_EQ_CTRL_2			0x00af
#define RT5659_DAC_EQ_CTRL_1			0x00b0
#define RT5659_DAC_EQ_CTRL_2			0x00b1
#define RT5659_DAC_EQ_CTRL_3			0x00b2

#define RT5659_IRQ_CTRL_1			0x00b6
#define RT5659_IRQ_CTRL_2			0x00b7
#define RT5659_IRQ_CTRL_3			0x00b8
#define RT5659_IRQ_CTRL_4			0x00ba
#define RT5659_IRQ_CTRL_5			0x00bb
#define RT5659_IRQ_CTRL_6			0x00bc
#define RT5659_INT_ST_1				0x00be
#define RT5659_INT_ST_2				0x00bf
#define RT5659_GPIO_CTRL_1			0x00c0
#define RT5659_GPIO_CTRL_2			0x00c1
#define RT5659_GPIO_CTRL_3			0x00c2
#define RT5659_GPIO_CTRL_4			0x00c3
#define RT5659_GPIO_CTRL_5			0x00c4
#define RT5659_GPIO_STA				0x00c5
#define RT5659_SINE_GEN_CTRL_1			0x00cb
#define RT5659_SINE_GEN_CTRL_2			0x00cc
#define RT5659_SINE_GEN_CTRL_3			0x00cd
#define RT5659_HP_AMP_DET_CTRL_1		0x00d6
#define RT5659_HP_AMP_DET_CTRL_2		0x00d7
#define RT5659_SV_ZCD_1				0x00d9
#define RT5659_SV_ZCD_2				0x00da
#define RT5659_IL_CMD_1				0x00db
#define RT5659_IL_CMD_2				0x00dc
#define RT5659_IL_CMD_3				0x00dd
#define RT5659_IL_CMD_4				0x00de
#define RT5659_4BTN_IL_CMD_1			0x00df
#define RT5659_4BTN_IL_CMD_2			0x00e0
#define RT5659_4BTN_IL_CMD_3			0x00e1
#define RT5659_PSV_IL_CMD_1			0x00e4
#define RT5659_PSV_IL_CMD_2			0x00e5

#define RT5659_ADC_STO1_HP_CTRL_1		0x00ea
#define RT5659_ADC_STO1_HP_CTRL_2		0x00eb
#define RT5659_ADC_MONO_HP_CTRL_1		0x00ec
#define RT5659_ADC_MONO_HP_CTRL_2		0x00ed
#define RT5659_AJD1_CTRL			0x00f0
#define RT5659_AJD2_AJD3_CTRL			0x00f1
#define RT5659_JD1_THD				0x00f2
#define RT5659_JD2_THD				0x00f3
#define RT5659_JD3_THD				0x00f4
#define RT5659_JD_CTRL_1			0x00f6
#define RT5659_JD_CTRL_2			0x00f7
#define RT5659_JD_CTRL_3			0x00f8
#define RT5659_JD_CTRL_4			0x00f9
/* General Control */
#define RT5659_DIG_MISC				0x00fa
#define RT5659_DUMMY_2				0x00fb
#define RT5659_DUMMY_3				0x00fc

#define RT5659_DAC_ADC_DIG_VOL			0x0100
#define RT5659_BIAS_CUR_CTRL_1			0x010a
#define RT5659_BIAS_CUR_CTRL_2			0x010b
#define RT5659_BIAS_CUR_CTRL_3			0x010c
#define RT5659_BIAS_CUR_CTRL_4			0x010d
#define RT5659_BIAS_CUR_CTRL_5			0x010e
#define RT5659_BIAS_CUR_CTRL_6			0x010f
#define RT5659_BIAS_CUR_CTRL_7			0x0110
#define RT5659_BIAS_CUR_CTRL_8			0x0111
#define RT5659_BIAS_CUR_CTRL_9			0x0112
#define RT5659_BIAS_CUR_CTRL_10			0x0113
#define RT5659_MEMORY_TEST			0x0116
#define RT5659_VREF_REC_OP_FB_CAP_CTRL		0x0117
#define RT5659_CLASSD_0				0x011a
#define RT5659_CLASSD_1				0x011b
#define RT5659_CLASSD_2				0x011c
#define RT5659_CLASSD_3				0x011d
#define RT5659_CLASSD_4				0x011e
#define RT5659_CLASSD_5				0x011f
#define RT5659_CLASSD_6				0x0120
#define RT5659_CLASSD_7				0x0121
#define RT5659_CLASSD_8				0x0122
#define RT5659_CLASSD_9				0x0123
#define RT5659_CLASSD_10			0x0124
#define RT5659_CHARGE_PUMP_1			0x0125
#define RT5659_CHARGE_PUMP_2			0x0126
#define RT5659_DIG_IN_CTRL_1			0x0132
#define RT5659_DIG_IN_CTRL_2			0x0133
#define RT5659_PAD_DRIVING_CTRL			0x0137
#define RT5659_SOFT_RAMP_DEPOP			0x0138
#define RT5659_PLL				0x0139
#define RT5659_CHOP_DAC				0x013a
#define RT5659_CHOP_ADC				0x013b
#define RT5659_CALIB_ADC_CTRL			0x013c
#define RT5659_SOFT_RAMP_DEPOP_DAC_CLK_CTRL	0x013e
#define RT5659_VOL_TEST				0x013f
#define RT5659_TEST_MODE_CTRL_1			0x0145
#define RT5659_TEST_MODE_CTRL_2			0x0146
#define RT5659_TEST_MODE_CTRL_3			0x0147
#define RT5659_TEST_MODE_CTRL_4			0x0148
#define RT5659_BASSBACK_CTRL			0x0150
#define RT5659_MP3_PLUS_CTRL_1			0x0151
#define RT5659_MP3_PLUS_CTRL_2			0x0152
#define RT5659_MP3_HPF_A1			0x0153
#define RT5659_MP3_HPF_A2			0x0154
#define RT5659_MP3_HPF_H0			0x0155
#define RT5659_MP3_LPF_H0			0x0156
#define RT5659_3D_SPK_CTRL			0x0157
#define RT5659_3D_SPK_COEF_1			0x0158
#define RT5659_3D_SPK_COEF_2			0x0159
#define RT5659_3D_SPK_COEF_3			0x015a
#define RT5659_3D_SPK_COEF_4			0x015b
#define RT5659_3D_SPK_COEF_5			0x015c
#define RT5659_3D_SPK_COEF_6			0x015d
#define RT5659_3D_SPK_COEF_7			0x015e
#define RT5659_STO_NG2_CTRL_1			0x0160
#define RT5659_STO_NG2_CTRL_2			0x0161
#define RT5659_STO_NG2_CTRL_3			0x0162
#define RT5659_STO_NG2_CTRL_4			0x0163
#define RT5659_STO_NG2_CTRL_5			0x0164
#define RT5659_STO_NG2_CTRL_6			0x0165
#define RT5659_STO_NG2_CTRL_7			0x0166
#define RT5659_STO_NG2_CTRL_8			0x0167
#define RT5659_MONO_NG2_CTRL_1			0x0170
#define RT5659_MONO_NG2_CTRL_2			0x0171
#define RT5659_MONO_NG2_CTRL_3			0x0172
#define RT5659_MONO_NG2_CTRL_4			0x0173
#define RT5659_MONO_NG2_CTRL_5			0x0174
#define RT5659_MONO_NG2_CTRL_6			0x0175
#define RT5659_MID_HP_AMP_DET			0x0190
#define RT5659_LOW_HP_AMP_DET			0x0191
#define RT5659_LDO_CTRL				0x0192
#define RT5659_HP_DECROSS_CTRL_1		0x01b0
#define RT5659_HP_DECROSS_CTRL_2		0x01b1
#define RT5659_HP_DECROSS_CTRL_3		0x01b2
#define RT5659_HP_DECROSS_CTRL_4		0x01b3
#define RT5659_HP_IMP_SENS_CTRL_1		0x01c0
#define RT5659_HP_IMP_SENS_CTRL_2		0x01c1
#define RT5659_HP_IMP_SENS_CTRL_3		0x01c2
#define RT5659_HP_IMP_SENS_CTRL_4		0x01c3
#define RT5659_HP_IMP_SENS_MAP_1		0x01c7
#define RT5659_HP_IMP_SENS_MAP_2		0x01c8
#define RT5659_HP_IMP_SENS_MAP_3		0x01c9
#define RT5659_HP_IMP_SENS_MAP_4		0x01ca
#define RT5659_HP_IMP_SENS_MAP_5		0x01cb
#define RT5659_HP_IMP_SENS_MAP_6		0x01cc
#define RT5659_HP_IMP_SENS_MAP_7		0x01cd
#define RT5659_HP_IMP_SENS_MAP_8		0x01ce
#define RT5659_HP_LOGIC_CTRL_1			0x01da
#define RT5659_HP_LOGIC_CTRL_2			0x01db
#define RT5659_HP_CALIB_CTRL_1			0x01de
#define RT5659_HP_CALIB_CTRL_2			0x01df
#define RT5659_HP_CALIB_CTRL_3			0x01e0
#define RT5659_HP_CALIB_CTRL_4			0x01e1
#define RT5659_HP_CALIB_CTRL_5			0x01e2
#define RT5659_HP_CALIB_CTRL_6			0x01e3
#define RT5659_HP_CALIB_CTRL_7			0x01e4
#define RT5659_HP_CALIB_CTRL_9			0x01e6
#define RT5659_HP_CALIB_CTRL_10			0x01e7
#define RT5659_HP_CALIB_CTRL_11			0x01e8
#define RT5659_HP_CALIB_STA_1			0x01ea
#define RT5659_HP_CALIB_STA_2			0x01eb
#define RT5659_HP_CALIB_STA_3			0x01ec
#define RT5659_HP_CALIB_STA_4			0x01ed
#define RT5659_HP_CALIB_STA_5			0x01ee
#define RT5659_HP_CALIB_STA_6			0x01ef
#define RT5659_HP_CALIB_STA_7			0x01f0
#define RT5659_HP_CALIB_STA_8			0x01f1
#define RT5659_HP_CALIB_STA_9			0x01f2
#define RT5659_MONO_AMP_CALIB_CTRL_1		0x01f6
#define RT5659_MONO_AMP_CALIB_CTRL_2		0x01f7
#define RT5659_MONO_AMP_CALIB_CTRL_3		0x01f8
#define RT5659_MONO_AMP_CALIB_CTRL_4		0x01f9
#define RT5659_MONO_AMP_CALIB_CTRL_5		0x01fa
#define RT5659_MONO_AMP_CALIB_STA_1		0x01fb
#define RT5659_MONO_AMP_CALIB_STA_2		0x01fc
#define RT5659_MONO_AMP_CALIB_STA_3		0x01fd
#define RT5659_MONO_AMP_CALIB_STA_4		0x01fe
#define RT5659_SPK_PWR_LMT_CTRL_1		0x0200
#define RT5659_SPK_PWR_LMT_CTRL_2		0x0201
#define RT5659_SPK_PWR_LMT_CTRL_3		0x0202
#define RT5659_SPK_PWR_LMT_STA_1		0x0203
#define RT5659_SPK_PWR_LMT_STA_2		0x0204
#define RT5659_SPK_PWR_LMT_STA_3		0x0205
#define RT5659_SPK_PWR_LMT_STA_4		0x0206
#define RT5659_SPK_PWR_LMT_STA_5		0x0207
#define RT5659_SPK_PWR_LMT_STA_6		0x0208
#define RT5659_FLEX_SPK_BST_CTRL_1		0x0256
#define RT5659_FLEX_SPK_BST_CTRL_2		0x0257
#define RT5659_FLEX_SPK_BST_CTRL_3		0x0258
#define RT5659_FLEX_SPK_BST_CTRL_4		0x0259
#define RT5659_SPK_EX_LMT_CTRL_1		0x025a
#define RT5659_SPK_EX_LMT_CTRL_2		0x025b
#define RT5659_SPK_EX_LMT_CTRL_3		0x025c
#define RT5659_SPK_EX_LMT_CTRL_4		0x025d
#define RT5659_SPK_EX_LMT_CTRL_5		0x025e
#define RT5659_SPK_EX_LMT_CTRL_6		0x025f
#define RT5659_SPK_EX_LMT_CTRL_7		0x0260
#define RT5659_ADJ_HPF_CTRL_1			0x0261
#define RT5659_ADJ_HPF_CTRL_2			0x0262
#define RT5659_SPK_DC_CAILB_CTRL_1		0x0265
#define RT5659_SPK_DC_CAILB_CTRL_2		0x0266
#define RT5659_SPK_DC_CAILB_CTRL_3		0x0267
#define RT5659_SPK_DC_CAILB_CTRL_4		0x0268
#define RT5659_SPK_DC_CAILB_CTRL_5		0x0269
#define RT5659_SPK_DC_CAILB_STA_1		0x026a
#define RT5659_SPK_DC_CAILB_STA_2		0x026b
#define RT5659_SPK_DC_CAILB_STA_3		0x026c
#define RT5659_SPK_DC_CAILB_STA_4		0x026d
#define RT5659_SPK_DC_CAILB_STA_5		0x026e
#define RT5659_SPK_DC_CAILB_STA_6		0x026f
#define RT5659_SPK_DC_CAILB_STA_7		0x0270
#define RT5659_SPK_DC_CAILB_STA_8		0x0271
#define RT5659_SPK_DC_CAILB_STA_9		0x0272
#define RT5659_SPK_DC_CAILB_STA_10		0x0273
#define RT5659_SPK_VDD_STA_1			0x0280
#define RT5659_SPK_VDD_STA_2			0x0281
#define RT5659_SPK_DC_DET_CTRL_1		0x0282
#define RT5659_SPK_DC_DET_CTRL_2		0x0283
#define RT5659_SPK_DC_DET_CTRL_3		0x0284
#define RT5659_PURE_DC_DET_CTRL_1		0x0290
#define RT5659_PURE_DC_DET_CTRL_2		0x0291
#define RT5659_DUMMY_4				0x02fa
#define RT5659_DUMMY_5				0x02fb
#define RT5659_DUMMY_6				0x02fc
#define RT5659_DRC1_CTRL_1			0x0300
#define RT5659_DRC1_CTRL_2			0x0301
#define RT5659_DRC1_CTRL_3			0x0302
#define RT5659_DRC1_CTRL_4			0x0303
#define RT5659_DRC1_CTRL_5			0x0304
#define RT5659_DRC1_CTRL_6			0x0305
#define RT5659_DRC1_HARD_LMT_CTRL_1		0x0306
#define RT5659_DRC1_HARD_LMT_CTRL_2		0x0307
#define RT5659_DRC2_CTRL_1			0x0308
#define RT5659_DRC2_CTRL_2			0x0309
#define RT5659_DRC2_CTRL_3			0x030a
#define RT5659_DRC2_CTRL_4			0x030b
#define RT5659_DRC2_CTRL_5			0x030c
#define RT5659_DRC2_CTRL_6			0x030d
#define RT5659_DRC2_HARD_LMT_CTRL_1		0x030e
#define RT5659_DRC2_HARD_LMT_CTRL_2		0x030f
#define RT5659_DRC1_PRIV_1			0x0310
#define RT5659_DRC1_PRIV_2			0x0311
#define RT5659_DRC1_PRIV_3			0x0312
#define RT5659_DRC1_PRIV_4			0x0313
#define RT5659_DRC1_PRIV_5			0x0314
#define RT5659_DRC1_PRIV_6			0x0315
#define RT5659_DRC1_PRIV_7			0x0316
#define RT5659_DRC2_PRIV_1			0x0317
#define RT5659_DRC2_PRIV_2			0x0318
#define RT5659_DRC2_PRIV_3			0x0319
#define RT5659_DRC2_PRIV_4			0x031a
#define RT5659_DRC2_PRIV_5			0x031b
#define RT5659_DRC2_PRIV_6			0x031c
#define RT5659_DRC2_PRIV_7			0x031d
#define RT5659_MULTI_DRC_CTRL			0x0320
#define RT5659_CROSS_OVER_1			0x0321
#define RT5659_CROSS_OVER_2			0x0322
#define RT5659_CROSS_OVER_3			0x0323
#define RT5659_CROSS_OVER_4			0x0324
#define RT5659_CROSS_OVER_5			0x0325
#define RT5659_CROSS_OVER_6			0x0326
#define RT5659_CROSS_OVER_7			0x0327
#define RT5659_CROSS_OVER_8			0x0328
#define RT5659_CROSS_OVER_9			0x0329
#define RT5659_CROSS_OVER_10			0x032a
#define RT5659_ALC_PGA_CTRL_1			0x0330
#define RT5659_ALC_PGA_CTRL_2			0x0331
#define RT5659_ALC_PGA_CTRL_3			0x0332
#define RT5659_ALC_PGA_CTRL_4			0x0333
#define RT5659_ALC_PGA_CTRL_5			0x0334
#define RT5659_ALC_PGA_CTRL_6			0x0335
#define RT5659_ALC_PGA_CTRL_7			0x0336
#define RT5659_ALC_PGA_CTRL_8			0x0337
#define RT5659_ALC_PGA_STA_1			0x0338
#define RT5659_ALC_PGA_STA_2			0x0339
#define RT5659_ALC_PGA_STA_3			0x033a
#define RT5659_DAC_L_EQ_PRE_VOL			0x0340
#define RT5659_DAC_R_EQ_PRE_VOL			0x0341
#define RT5659_DAC_L_EQ_POST_VOL		0x0342
#define RT5659_DAC_R_EQ_POST_VOL		0x0343
#define RT5659_DAC_L_EQ_LPF1_A1			0x0344
#define RT5659_DAC_L_EQ_LPF1_H0			0x0345
#define RT5659_DAC_R_EQ_LPF1_A1			0x0346
#define RT5659_DAC_R_EQ_LPF1_H0			0x0347
#define RT5659_DAC_L_EQ_BPF2_A1			0x0348
#define RT5659_DAC_L_EQ_BPF2_A2			0x0349
#define RT5659_DAC_L_EQ_BPF2_H0			0x034a
#define RT5659_DAC_R_EQ_BPF2_A1			0x034b
#define RT5659_DAC_R_EQ_BPF2_A2			0x034c
#define RT5659_DAC_R_EQ_BPF2_H0			0x034d
#define RT5659_DAC_L_EQ_BPF3_A1			0x034e
#define RT5659_DAC_L_EQ_BPF3_A2			0x034f
#define RT5659_DAC_L_EQ_BPF3_H0			0x0350
#define RT5659_DAC_R_EQ_BPF3_A1			0x0351
#define RT5659_DAC_R_EQ_BPF3_A2			0x0352
#define RT5659_DAC_R_EQ_BPF3_H0			0x0353
#define RT5659_DAC_L_EQ_BPF4_A1			0x0354
#define RT5659_DAC_L_EQ_BPF4_A2			0x0355
#define RT5659_DAC_L_EQ_BPF4_H0			0x0356
#define RT5659_DAC_R_EQ_BPF4_A1			0x0357
#define RT5659_DAC_R_EQ_BPF4_A2			0x0358
#define RT5659_DAC_R_EQ_BPF4_H0			0x0359
#define RT5659_DAC_L_EQ_HPF1_A1			0x035a
#define RT5659_DAC_L_EQ_HPF1_H0			0x035b
#define RT5659_DAC_R_EQ_HPF1_A1			0x035c
#define RT5659_DAC_R_EQ_HPF1_H0			0x035d
#define RT5659_DAC_L_EQ_HPF2_A1			0x035e
#define RT5659_DAC_L_EQ_HPF2_A2			0x035f
#define RT5659_DAC_L_EQ_HPF2_H0			0x0360
#define RT5659_DAC_R_EQ_HPF2_A1			0x0361
#define RT5659_DAC_R_EQ_HPF2_A2			0x0362
#define RT5659_DAC_R_EQ_HPF2_H0			0x0363
#define RT5659_DAC_L_BI_EQ_BPF1_H0_1		0x0364
#define RT5659_DAC_L_BI_EQ_BPF1_H0_2		0x0365
#define RT5659_DAC_L_BI_EQ_BPF1_B1_1		0x0366
#define RT5659_DAC_L_BI_EQ_BPF1_B1_2		0x0367
#define RT5659_DAC_L_BI_EQ_BPF1_B2_1		0x0368
#define RT5659_DAC_L_BI_EQ_BPF1_B2_2		0x0369
#define RT5659_DAC_L_BI_EQ_BPF1_A1_1		0x036a
#define RT5659_DAC_L_BI_EQ_BPF1_A1_2		0x036b
#define RT5659_DAC_L_BI_EQ_BPF1_A2_1		0x036c
#define RT5659_DAC_L_BI_EQ_BPF1_A2_2		0x036d
#define RT5659_DAC_R_BI_EQ_BPF1_H0_1		0x036e
#define RT5659_DAC_R_BI_EQ_BPF1_H0_2		0x036f
#define RT5659_DAC_R_BI_EQ_BPF1_B1_1		0x0370
#define RT5659_DAC_R_BI_EQ_BPF1_B1_2		0x0371
#define RT5659_DAC_R_BI_EQ_BPF1_B2_1		0x0372
#define RT5659_DAC_R_BI_EQ_BPF1_B2_2		0x0373
#define RT5659_DAC_R_BI_EQ_BPF1_A1_1		0x0374
#define RT5659_DAC_R_BI_EQ_BPF1_A1_2		0x0375
#define RT5659_DAC_R_BI_EQ_BPF1_A2_1		0x0376
#define RT5659_DAC_R_BI_EQ_BPF1_A2_2		0x0377
#define RT5659_ADC_L_EQ_LPF1_A1			0x03d0
#define RT5659_ADC_R_EQ_LPF1_A1			0x03d1
#define RT5659_ADC_L_EQ_LPF1_H0			0x03d2
#define RT5659_ADC_R_EQ_LPF1_H0			0x03d3
#define RT5659_ADC_L_EQ_BPF1_A1			0x03d4
#define RT5659_ADC_R_EQ_BPF1_A1			0x03d5
#define RT5659_ADC_L_EQ_BPF1_A2			0x03d6
#define RT5659_ADC_R_EQ_BPF1_A2			0x03d7
#define RT5659_ADC_L_EQ_BPF1_H0			0x03d8
#define RT5659_ADC_R_EQ_BPF1_H0			0x03d9
#define RT5659_ADC_L_EQ_BPF2_A1			0x03da
#define RT5659_ADC_R_EQ_BPF2_A1			0x03db
#define RT5659_ADC_L_EQ_BPF2_A2			0x03dc
#define RT5659_ADC_R_EQ_BPF2_A2			0x03dd
#define RT5659_ADC_L_EQ_BPF2_H0			0x03de
#define RT5659_ADC_R_EQ_BPF2_H0			0x03df
#define RT5659_ADC_L_EQ_BPF3_A1			0x03e0
#define RT5659_ADC_R_EQ_BPF3_A1			0x03e1
#define RT5659_ADC_L_EQ_BPF3_A2			0x03e2
#define RT5659_ADC_R_EQ_BPF3_A2			0x03e3
#define RT5659_ADC_L_EQ_BPF3_H0			0x03e4
#define RT5659_ADC_R_EQ_BPF3_H0			0x03e5
#define RT5659_ADC_L_EQ_BPF4_A1			0x03e6
#define RT5659_ADC_R_EQ_BPF4_A1			0x03e7
#define RT5659_ADC_L_EQ_BPF4_A2			0x03e8
#define RT5659_ADC_R_EQ_BPF4_A2			0x03e9
#define RT5659_ADC_L_EQ_BPF4_H0			0x03ea
#define RT5659_ADC_R_EQ_BPF4_H0			0x03eb
#define RT5659_ADC_L_EQ_HPF1_A1			0x03ec
#define RT5659_ADC_R_EQ_HPF1_A1			0x03ed
#define RT5659_ADC_L_EQ_HPF1_H0			0x03ee
#define RT5659_ADC_R_EQ_HPF1_H0			0x03ef
#define RT5659_ADC_L_EQ_PRE_VOL			0x03f0
#define RT5659_ADC_R_EQ_PRE_VOL			0x03f1
#define RT5659_ADC_L_EQ_POST_VOL		0x03f2
#define RT5659_ADC_R_EQ_POST_VOL		0x03f3



/* global definition */
#define RT5659_L_MUTE				(0x1 << 15)
#define RT5659_L_MUTE_SFT			15
#define RT5659_VOL_L_MUTE			(0x1 << 14)
#define RT5659_VOL_L_SFT			14
#define RT5659_R_MUTE				(0x1 << 7)
#define RT5659_R_MUTE_SFT			7
#define RT5659_VOL_R_MUTE			(0x1 << 6)
#define RT5659_VOL_R_SFT			6
#define RT5659_L_VOL_MASK			(0x3f << 8)
#define RT5659_L_VOL_SFT			8
#define RT5659_R_VOL_MASK			(0x3f)
#define RT5659_R_VOL_SFT			0

/*Headphone Amp L/R Analog Gain and Digital NG2 Gain Control (0x0005 0x0006)*/
#define RT5659_G_HP				(0x1f << 8)
#define RT5659_G_HP_SFT				8
#define RT5659_G_STO_DA_DMIX			(0x1f)
#define RT5659_G_STO_DA_SFT			0

/* IN1/IN2 Control (0x000c) */
#define RT5659_IN1_DF_MASK			(0x1 << 15)
#define RT5659_IN1_DF				15
#define RT5659_BST1_MASK			(0x7f << 8)
#define RT5659_BST1_SFT				8
#define RT5659_BST2_MASK			(0x7f)
#define RT5659_BST2_SFT				0

/* IN3/IN4 Control (0x000d) */
#define RT5659_IN3_DF_MASK			(0x1 << 15)
#define RT5659_IN3_DF				15
#define RT5659_BST3_MASK			(0x7f << 8)
#define RT5659_BST3_SFT				8
#define RT5659_IN4_DF_MASK			(0x1 << 7)
#define RT5659_IN4_DF				7
#define RT5659_BST4_MASK			(0x7f)
#define RT5659_BST4_SFT				0

/* INL and INR Volume Control (0x000f) */
#define RT5659_INL_VOL_MASK			(0x1f << 8)
#define RT5659_INL_VOL_SFT			8
#define RT5659_INR_VOL_MASK			(0x1f)
#define RT5659_INR_VOL_SFT			0

/* Embeeded Jack and Type Detection Control 1 (0x0010) */
#define RT5659_EMB_JD_EN			(0x1 << 15)
#define RT5659_EMB_JD_EN_SFT			15
#define RT5659_JD_MODE				(0x1 << 13)
#define RT5659_JD_MODE_SFT			13
#define RT5659_EXT_JD_EN			(0x1 << 11)
#define RT5659_EXT_JD_EN_SFT			11
#define RT5659_EXT_JD_DIG			(0x1 << 9)

/* Embeeded Jack and Type Detection Control 2 (0x0011) */
#define RT5659_EXT_JD_SRC			(0x7 << 4)
#define RT5659_EXT_JD_SRC_SFT			4
#define RT5659_EXT_JD_SRC_GPIO_JD1		(0x0 << 4)
#define RT5659_EXT_JD_SRC_GPIO_JD2		(0x1 << 4)
#define RT5659_EXT_JD_SRC_JD1_1			(0x2 << 4)
#define RT5659_EXT_JD_SRC_JD1_2			(0x3 << 4)
#define RT5659_EXT_JD_SRC_JD2			(0x4 << 4)
#define RT5659_EXT_JD_SRC_JD3			(0x5 << 4)
#define RT5659_EXT_JD_SRC_MANUAL		(0x6 << 4)

/* Slience Detection Control (0x0015) */
#define RT5659_SIL_DET_MASK			(0x1 << 15)
#define RT5659_SIL_DET_DIS			(0x0 << 15)
#define RT5659_SIL_DET_EN			(0x1 << 15)

/* Sidetone Control (0x0018) */
#define RT5659_ST_SEL_MASK			(0x7 << 9)
#define RT5659_ST_SEL_SFT			9
#define RT5659_ST_EN				(0x1 << 6)
#define RT5659_ST_EN_SFT			6

/* DAC1 Digital Volume (0x0019) */
#define RT5659_DAC_L1_VOL_MASK			(0xff << 8)
#define RT5659_DAC_L1_VOL_SFT			8
#define RT5659_DAC_R1_VOL_MASK			(0xff)
#define RT5659_DAC_R1_VOL_SFT			0

/* DAC2 Digital Volume (0x001a) */
#define RT5659_DAC_L2_VOL_MASK			(0xff << 8)
#define RT5659_DAC_L2_VOL_SFT			8
#define RT5659_DAC_R2_VOL_MASK			(0xff)
#define RT5659_DAC_R2_VOL_SFT			0

/* DAC2 Control (0x001b) */
#define RT5659_M_DAC2_L_VOL			(0x1 << 13)
#define RT5659_M_DAC2_L_VOL_SFT			13
#define RT5659_M_DAC2_R_VOL			(0x1 << 12)
#define RT5659_M_DAC2_R_VOL_SFT			12
#define RT5659_DAC_L2_SEL_MASK			(0x7 << 4)
#define RT5659_DAC_L2_SEL_SFT			4
#define RT5659_DAC_R2_SEL_MASK			(0x7 << 0)
#define RT5659_DAC_R2_SEL_SFT			0

/* ADC Digital Volume Control (0x001c) */
#define RT5659_ADC_L_VOL_MASK			(0x7f << 8)
#define RT5659_ADC_L_VOL_SFT			8
#define RT5659_ADC_R_VOL_MASK			(0x7f)
#define RT5659_ADC_R_VOL_SFT			0

/* Mono ADC Digital Volume Control (0x001d) */
#define RT5659_MONO_ADC_L_VOL_MASK		(0x7f << 8)
#define RT5659_MONO_ADC_L_VOL_SFT		8
#define RT5659_MONO_ADC_R_VOL_MASK		(0x7f)
#define RT5659_MONO_ADC_R_VOL_SFT		0

/* Stereo1 ADC Boost Gain Control (0x001f) */
#define RT5659_STO1_ADC_L_BST_MASK		(0x3 << 14)
#define RT5659_STO1_ADC_L_BST_SFT		14
#define RT5659_STO1_ADC_R_BST_MASK		(0x3 << 12)
#define RT5659_STO1_ADC_R_BST_SFT		12

/* Mono ADC Boost Gain Control (0x0020) */
#define RT5659_MONO_ADC_L_BST_MASK		(0x3 << 14)
#define RT5659_MONO_ADC_L_BST_SFT		14
#define RT5659_MONO_ADC_R_BST_MASK		(0x3 << 12)
#define RT5659_MONO_ADC_R_BST_SFT		12

/* Stereo1 ADC Boost Gain Control (0x001f) */
#define RT5659_STO2_ADC_L_BST_MASK		(0x3 << 14)
#define RT5659_STO2_ADC_L_BST_SFT		14
#define RT5659_STO2_ADC_R_BST_MASK		(0x3 << 12)
#define RT5659_STO2_ADC_R_BST_SFT		12

/* Stereo ADC Mixer Control (0x0026) */
#define RT5659_M_STO1_ADC_L1			(0x1 << 15)
#define RT5659_M_STO1_ADC_L1_SFT		15
#define RT5659_M_STO1_ADC_L2			(0x1 << 14)
#define RT5659_M_STO1_ADC_L2_SFT		14
#define RT5659_STO1_ADC1_SRC_MASK		(0x1 << 13)
#define RT5659_STO1_ADC1_SRC_SFT		13
#define RT5659_STO1_ADC1_SRC_ADC		(0x1 << 13)
#define RT5659_STO1_ADC1_SRC_DACMIX		(0x0 << 13)
#define RT5659_STO1_ADC_SRC_MASK		(0x1 << 12)
#define RT5659_STO1_ADC_SRC_SFT			12
#define RT5659_STO1_ADC_SRC_ADC1		(0x1 << 12)
#define RT5659_STO1_ADC_SRC_ADC2		(0x0 << 12)
#define RT5659_STO1_ADC2_SRC_MASK		(0x1 << 11)
#define RT5659_STO1_ADC2_SRC_SFT		11
#define RT5659_STO1_DMIC_SRC_MASK		(0x1 << 8)
#define RT5659_STO1_DMIC_SRC_SFT		8
#define RT5659_STO1_DMIC_SRC_DMIC2		(0x1 << 8)
#define RT5659_STO1_DMIC_SRC_DMIC1		(0x0 << 8)
#define RT5659_M_STO1_ADC_R1			(0x1 << 6)
#define RT5659_M_STO1_ADC_R1_SFT		6
#define RT5659_M_STO1_ADC_R2			(0x1 << 5)
#define RT5659_M_STO1_ADC_R2_SFT		5

/* Mono1 ADC Mixer control (0x0027) */
#define RT5659_M_MONO_ADC_L1			(0x1 << 15)
#define RT5659_M_MONO_ADC_L1_SFT		15
#define RT5659_M_MONO_ADC_L2			(0x1 << 14)
#define RT5659_M_MONO_ADC_L2_SFT		14
#define RT5659_MONO_ADC_L2_SRC_MASK		(0x1 << 12)
#define RT5659_MONO_ADC_L2_SRC_SFT		12
#define RT5659_MONO_ADC_L1_SRC_MASK		(0x1 << 11)
#define RT5659_MONO_ADC_L1_SRC_SFT		11
#define RT5659_MONO_ADC_L_SRC_MASK		(0x3 << 9)
#define RT5659_MONO_ADC_L_SRC_SFT		9
#define RT5659_MONO_DMIC_L_SRC_MASK		(0x1 << 8)
#define RT5659_MONO_DMIC_L_SRC_SFT		8
#define RT5659_M_MONO_ADC_R1			(0x1 << 7)
#define RT5659_M_MONO_ADC_R1_SFT		7
#define RT5659_M_MONO_ADC_R2			(0x1 << 6)
#define RT5659_M_MONO_ADC_R2_SFT		6
#define RT5659_STO2_ADC_SRC_MASK		(0x1 << 5)
#define RT5659_STO2_ADC_SRC_SFT			5
#define RT5659_MONO_ADC_R2_SRC_MASK		(0x1 << 4)
#define RT5659_MONO_ADC_R2_SRC_SFT		4
#define RT5659_MONO_ADC_R1_SRC_MASK		(0x1 << 3)
#define RT5659_MONO_ADC_R1_SRC_SFT		3
#define RT5659_MONO_ADC_R_SRC_MASK		(0x3 << 1)
#define RT5659_MONO_ADC_R_SRC_SFT		1
#define RT5659_MONO_DMIC_R_SRC_MASK		0x1
#define RT5659_MONO_DMIC_R_SRC_SFT		0

/* ADC Mixer to DAC Mixer Control (0x0029) */
#define RT5659_M_ADCMIX_L			(0x1 << 15)
#define RT5659_M_ADCMIX_L_SFT			15
#define RT5659_M_DAC1_L				(0x1 << 14)
#define RT5659_M_DAC1_L_SFT			14
#define RT5659_DAC1_R_SEL_MASK			(0x3 << 10)
#define RT5659_DAC1_R_SEL_SFT			10
#define RT5659_DAC1_R_SEL_IF1			(0x0 << 10)
#define RT5659_DAC1_R_SEL_IF2			(0x1 << 10)
#define RT5659_DAC1_R_SEL_IF3			(0x2 << 10)
#define RT5659_DAC1_L_SEL_MASK			(0x3 << 8)
#define RT5659_DAC1_L_SEL_SFT			8
#define RT5659_DAC1_L_SEL_IF1			(0x0 << 8)
#define RT5659_DAC1_L_SEL_IF2			(0x1 << 8)
#define RT5659_DAC1_L_SEL_IF3			(0x2 << 8)
#define RT5659_M_ADCMIX_R			(0x1 << 7)
#define RT5659_M_ADCMIX_R_SFT			7
#define RT5659_M_DAC1_R				(0x1 << 6)
#define RT5659_M_DAC1_R_SFT			6

/* Stereo DAC Mixer Control (0x002a) */
#define RT5659_M_DAC_L1_STO_L			(0x1 << 15)
#define RT5659_M_DAC_L1_STO_L_SFT		15
#define RT5659_G_DAC_L1_STO_L_MASK		(0x1 << 14)
#define RT5659_G_DAC_L1_STO_L_SFT		14
#define RT5659_M_DAC_R1_STO_L			(0x1 << 13)
#define RT5659_M_DAC_R1_STO_L_SFT		13
#define RT5659_G_DAC_R1_STO_L_MASK		(0x1 << 12)
#define RT5659_G_DAC_R1_STO_L_SFT		12
#define RT5659_M_DAC_L2_STO_L			(0x1 << 11)
#define RT5659_M_DAC_L2_STO_L_SFT		11
#define RT5659_G_DAC_L2_STO_L_MASK		(0x1 << 10)
#define RT5659_G_DAC_L2_STO_L_SFT		10
#define RT5659_M_DAC_R2_STO_L			(0x1 << 9)
#define RT5659_M_DAC_R2_STO_L_SFT		9
#define RT5659_G_DAC_R2_STO_L_MASK		(0x1 << 8)
#define RT5659_G_DAC_R2_STO_L_SFT		8
#define RT5659_M_DAC_L1_STO_R			(0x1 << 7)
#define RT5659_M_DAC_L1_STO_R_SFT		7
#define RT5659_G_DAC_L1_STO_R_MASK		(0x1 << 6)
#define RT5659_G_DAC_L1_STO_R_SFT		6
#define RT5659_M_DAC_R1_STO_R			(0x1 << 5)
#define RT5659_M_DAC_R1_STO_R_SFT		5
#define RT5659_G_DAC_R1_STO_R_MASK		(0x1 << 4)
#define RT5659_G_DAC_R1_STO_R_SFT		4
#define RT5659_M_DAC_L2_STO_R			(0x1 << 3)
#define RT5659_M_DAC_L2_STO_R_SFT		3
#define RT5659_G_DAC_L2_STO_R_MASK		(0x1 << 2)
#define RT5659_G_DAC_L2_STO_R_SFT		2
#define RT5659_M_DAC_R2_STO_R			(0x1 << 1)
#define RT5659_M_DAC_R2_STO_R_SFT		1
#define RT5659_G_DAC_R2_STO_R_MASK		(0x1)
#define RT5659_G_DAC_R2_STO_R_SFT		0

/* Mono DAC Mixer Control (0x002b) */
#define RT5659_M_DAC_L1_MONO_L			(0x1 << 15)
#define RT5659_M_DAC_L1_MONO_L_SFT		15
#define RT5659_G_DAC_L1_MONO_L_MASK		(0x1 << 14)
#define RT5659_G_DAC_L1_MONO_L_SFT		14
#define RT5659_M_DAC_R1_MONO_L			(0x1 << 13)
#define RT5659_M_DAC_R1_MONO_L_SFT		13
#define RT5659_G_DAC_R1_MONO_L_MASK		(0x1 << 12)
#define RT5659_G_DAC_R1_MONO_L_SFT		12
#define RT5659_M_DAC_L2_MONO_L			(0x1 << 11)
#define RT5659_M_DAC_L2_MONO_L_SFT		11
#define RT5659_G_DAC_L2_MONO_L_MASK		(0x1 << 10)
#define RT5659_G_DAC_L2_MONO_L_SFT		10
#define RT5659_M_DAC_R2_MONO_L			(0x1 << 9)
#define RT5659_M_DAC_R2_MONO_L_SFT		9
#define RT5659_G_DAC_R2_MONO_L_MASK		(0x1 << 8)
#define RT5659_G_DAC_R2_MONO_L_SFT		8
#define RT5659_M_DAC_L1_MONO_R			(0x1 << 7)
#define RT5659_M_DAC_L1_MONO_R_SFT		7
#define RT5659_G_DAC_L1_MONO_R_MASK		(0x1 << 6)
#define RT5659_G_DAC_L1_MONO_R_SFT		6
#define RT5659_M_DAC_R1_MONO_R			(0x1 << 5)
#define RT5659_M_DAC_R1_MONO_R_SFT		5
#define RT5659_G_DAC_R1_MONO_R_MASK		(0x1 << 4)
#define RT5659_G_DAC_R1_MONO_R_SFT		4
#define RT5659_M_DAC_L2_MONO_R			(0x1 << 3)
#define RT5659_M_DAC_L2_MONO_R_SFT		3
#define RT5659_G_DAC_L2_MONO_R_MASK		(0x1 << 2)
#define RT5659_G_DAC_L2_MONO_R_SFT		2
#define RT5659_M_DAC_R2_MONO_R			(0x1 << 1)
#define RT5659_M_DAC_R2_MONO_R_SFT		1
#define RT5659_G_DAC_R2_MONO_R_MASK		(0x1)
#define RT5659_G_DAC_R2_MONO_R_SFT		0

/* Digital Mixer Control (0x002c) */
#define RT5659_M_DAC_MIX_L			(0x1 << 7)
#define RT5659_M_DAC_MIX_L_SFT			7
#define RT5659_DAC_MIX_L_MASK			(0x1 << 6)
#define RT5659_DAC_MIX_L_SFT			6
#define RT5659_M_DAC_MIX_R			(0x1 << 5)
#define RT5659_M_DAC_MIX_R_SFT			5
#define RT5659_DAC_MIX_R_MASK			(0x1 << 4)
#define RT5659_DAC_MIX_R_SFT			4

/* Analog DAC Input Source Control (0x002d) */
#define RT5659_A_DACL1_SEL			(0x1 << 3)
#define RT5659_A_DACL1_SFT			3
#define RT5659_A_DACR1_SEL			(0x1 << 2)
#define RT5659_A_DACR1_SFT			2
#define RT5659_A_DACL2_SEL			(0x1 << 1)
#define RT5659_A_DACL2_SFT			1
#define RT5659_A_DACR2_SEL			(0x1 << 0)
#define RT5659_A_DACR2_SFT			0

/* Digital Interface Data Control (0x002f) */
#define RT5659_IF2_ADC3_IN_MASK			(0x3 << 14)
#define RT5659_IF2_ADC3_IN_SFT			14
#define RT5659_IF2_ADC_IN_MASK			(0x3 << 12)
#define RT5659_IF2_ADC_IN_SFT			12
#define RT5659_IF2_DAC_SEL_MASK			(0x3 << 10)
#define RT5659_IF2_DAC_SEL_SFT			10
#define RT5659_IF2_ADC_SEL_MASK			(0x3 << 8)
#define RT5659_IF2_ADC_SEL_SFT			8
#define RT5659_IF3_DAC_SEL_MASK			(0x3 << 6)
#define RT5659_IF3_DAC_SEL_SFT			6
#define RT5659_IF3_ADC_SEL_MASK			(0x3 << 4)
#define RT5659_IF3_ADC_SEL_SFT			4
#define RT5659_IF3_ADC_IN_MASK			(0x3 << 0)
#define RT5659_IF3_ADC_IN_SFT			0

/* PDM Output Control (0x0031) */
#define RT5659_PDM1_L_MASK			(0x1 << 15)
#define RT5659_PDM1_L_SFT			15
#define RT5659_M_PDM1_L				(0x1 << 14)
#define RT5659_M_PDM1_L_SFT			14
#define RT5659_PDM1_R_MASK			(0x1 << 13)
#define RT5659_PDM1_R_SFT			13
#define RT5659_M_PDM1_R				(0x1 << 12)
#define RT5659_M_PDM1_R_SFT			12
#define RT5659_PDM2_BUSY			(0x1 << 7)
#define RT5659_PDM1_BUSY			(0x1 << 6)
#define RT5659_PDM_PATTERN			(0x1 << 5)
#define RT5659_PDM_GAIN				(0x1 << 4)
#define RT5659_PDM_DIV_MASK			(0x3)

/*S/PDIF Output Control (0x0036) */
#define RT5659_SPDIF_SEL_MASK			(0x3 << 0)
#define RT5659_SPDIF_SEL_SFT			0

/* REC Left Mixer Control 2 (0x003c) */
#define RT5659_M_BST1_RM1_L			(0x1 << 5)
#define RT5659_M_BST1_RM1_L_SFT			5
#define RT5659_M_BST2_RM1_L			(0x1 << 4)
#define RT5659_M_BST2_RM1_L_SFT			4
#define RT5659_M_BST3_RM1_L			(0x1 << 3)
#define RT5659_M_BST3_RM1_L_SFT			3
#define RT5659_M_BST4_RM1_L			(0x1 << 2)
#define RT5659_M_BST4_RM1_L_SFT			2
#define RT5659_M_INL_RM1_L			(0x1 << 1)
#define RT5659_M_INL_RM1_L_SFT			1
#define RT5659_M_SPKVOLL_RM1_L			(0x1)
#define RT5659_M_SPKVOLL_RM1_L_SFT		0

/* REC Right Mixer Control 2 (0x003e) */
#define RT5659_M_BST1_RM1_R			(0x1 << 5)
#define RT5659_M_BST1_RM1_R_SFT			5
#define RT5659_M_BST2_RM1_R			(0x1 << 4)
#define RT5659_M_BST2_RM1_R_SFT			4
#define RT5659_M_BST3_RM1_R			(0x1 << 3)
#define RT5659_M_BST3_RM1_R_SFT			3
#define RT5659_M_BST4_RM1_R			(0x1 << 2)
#define RT5659_M_BST4_RM1_R_SFT			2
#define RT5659_M_INR_RM1_R			(0x1 << 1)
#define RT5659_M_INR_RM1_R_SFT			1
#define RT5659_M_HPOVOLR_RM1_R			(0x1)
#define RT5659_M_HPOVOLR_RM1_R_SFT		0

/* SPK Left Mixer Control (0x0046) */
#define RT5659_M_BST3_SM_L			(0x1 << 4)
#define RT5659_M_BST3_SM_L_SFT			4
#define RT5659_M_IN_R_SM_L			(0x1 << 3)
#define RT5659_M_IN_R_SM_L_SFT			3
#define RT5659_M_IN_L_SM_L			(0x1 << 2)
#define RT5659_M_IN_L_SM_L_SFT			2
#define RT5659_M_BST1_SM_L			(0x1 << 1)
#define RT5659_M_BST1_SM_L_SFT			1
#define RT5659_M_DAC_L2_SM_L			(0x1)
#define RT5659_M_DAC_L2_SM_L_SFT		0

/* SPK Right Mixer Control (0x0047) */
#define RT5659_M_BST3_SM_R			(0x1 << 4)
#define RT5659_M_BST3_SM_R_SFT			4
#define RT5659_M_IN_R_SM_R			(0x1 << 3)
#define RT5659_M_IN_R_SM_R_SFT			3
#define RT5659_M_IN_L_SM_R			(0x1 << 2)
#define RT5659_M_IN_L_SM_R_SFT			2
#define RT5659_M_BST4_SM_R			(0x1 << 1)
#define RT5659_M_BST4_SM_R_SFT			1
#define RT5659_M_DAC_R2_SM_R			(0x1)
#define RT5659_M_DAC_R2_SM_R_SFT		0

/* SPO Amp Input and Gain Control (0x0048) */
#define RT5659_M_DAC_L2_SPKOMIX			(0x1 << 13)
#define RT5659_M_DAC_L2_SPKOMIX_SFT		13
#define RT5659_M_SPKVOLL_SPKOMIX		(0x1 << 12)
#define RT5659_M_SPKVOLL_SPKOMIX_SFT		12
#define RT5659_M_DAC_R2_SPKOMIX			(0x1 << 9)
#define RT5659_M_DAC_R2_SPKOMIX_SFT		9
#define RT5659_M_SPKVOLR_SPKOMIX		(0x1 << 8)
#define RT5659_M_SPKVOLR_SPKOMIX_SFT		8

/* MONOMIX Input and Gain Control (0x004b) */
#define RT5659_M_MONOVOL_MA			(0x1 << 9)
#define RT5659_M_MONOVOL_MA_SFT			9
#define RT5659_M_DAC_L2_MA			(0x1 << 8)
#define RT5659_M_DAC_L2_MA_SFT			8
#define RT5659_M_BST3_MM			(0x1 << 4)
#define RT5659_M_BST3_MM_SFT			4
#define RT5659_M_BST2_MM			(0x1 << 3)
#define RT5659_M_BST2_MM_SFT			3
#define RT5659_M_BST1_MM			(0x1 << 2)
#define RT5659_M_BST1_MM_SFT			2
#define RT5659_M_DAC_R2_MM			(0x1 << 1)
#define RT5659_M_DAC_R2_MM_SFT			1
#define RT5659_M_DAC_L2_MM			(0x1)
#define RT5659_M_DAC_L2_MM_SFT			0

/* Output Left Mixer Control 1 (0x004d) */
#define RT5659_G_BST3_OM_L_MASK			(0x7 << 12)
#define RT5659_G_BST3_OM_L_SFT			12
#define RT5659_G_BST2_OM_L_MASK			(0x7 << 9)
#define RT5659_G_BST2_OM_L_SFT			9
#define RT5659_G_BST1_OM_L_MASK			(0x7 << 6)
#define RT5659_G_BST1_OM_L_SFT			6
#define RT5659_G_IN_L_OM_L_MASK			(0x7 << 3)
#define RT5659_G_IN_L_OM_L_SFT			3
#define RT5659_G_DAC_L2_OM_L_MASK		(0x7 << 0)
#define RT5659_G_DAC_L2_OM_L_SFT		0

/* Output Left Mixer Input Control (0x004e) */
#define RT5659_M_BST3_OM_L			(0x1 << 4)
#define RT5659_M_BST3_OM_L_SFT			4
#define RT5659_M_BST2_OM_L			(0x1 << 3)
#define RT5659_M_BST2_OM_L_SFT			3
#define RT5659_M_BST1_OM_L			(0x1 << 2)
#define RT5659_M_BST1_OM_L_SFT			2
#define RT5659_M_IN_L_OM_L			(0x1 << 1)
#define RT5659_M_IN_L_OM_L_SFT			1
#define RT5659_M_DAC_L2_OM_L			(0x1)
#define RT5659_M_DAC_L2_OM_L_SFT		0

/* Output Right Mixer Input Control (0x0050) */
#define RT5659_M_BST4_OM_R			(0x1 << 4)
#define RT5659_M_BST4_OM_R_SFT			4
#define RT5659_M_BST3_OM_R			(0x1 << 3)
#define RT5659_M_BST3_OM_R_SFT			3
#define RT5659_M_BST2_OM_R			(0x1 << 2)
#define RT5659_M_BST2_OM_R_SFT			2
#define RT5659_M_IN_R_OM_R			(0x1 << 1)
#define RT5659_M_IN_R_OM_R_SFT			1
#define RT5659_M_DAC_R2_OM_R			(0x1)
#define RT5659_M_DAC_R2_OM_R_SFT		0

/* LOUT Mixer Control (0x0052) */
#define RT5659_M_DAC_L2_LM			(0x1 << 15)
#define RT5659_M_DAC_L2_LM_SFT			15
#define RT5659_M_DAC_R2_LM			(0x1 << 14)
#define RT5659_M_DAC_R2_LM_SFT			14
#define RT5659_M_OV_L_LM			(0x1 << 13)
#define RT5659_M_OV_L_LM_SFT			13
#define RT5659_M_OV_R_LM			(0x1 << 12)
#define RT5659_M_OV_R_LM_SFT			12

/* Power Management for Digital 1 (0x0061) */
#define RT5659_PWR_I2S1				(0x1 << 15)
#define RT5659_PWR_I2S1_BIT			15
#define RT5659_PWR_I2S2				(0x1 << 14)
#define RT5659_PWR_I2S2_BIT			14
#define RT5659_PWR_I2S3				(0x1 << 13)
#define RT5659_PWR_I2S3_BIT			13
#define RT5659_PWR_SPDIF			(0x1 << 12)
#define RT5659_PWR_SPDIF_BIT			12
#define RT5659_PWR_DAC_L1			(0x1 << 11)
#define RT5659_PWR_DAC_L1_BIT			11
#define RT5659_PWR_DAC_R1			(0x1 << 10)
#define RT5659_PWR_DAC_R1_BIT			10
#define RT5659_PWR_DAC_L2			(0x1 << 9)
#define RT5659_PWR_DAC_L2_BIT			9
#define RT5659_PWR_DAC_R2			(0x1 << 8)
#define RT5659_PWR_DAC_R2_BIT			8
#define RT5659_PWR_LDO				(0x1 << 7)
#define RT5659_PWR_LDO_BIT			7
#define RT5659_PWR_ADC_L1			(0x1 << 4)
#define RT5659_PWR_ADC_L1_BIT			4
#define RT5659_PWR_ADC_R1			(0x1 << 3)
#define RT5659_PWR_ADC_R1_BIT			3
#define RT5659_PWR_ADC_L2			(0x1 << 2)
#define RT5659_PWR_ADC_L2_BIT			2
#define RT5659_PWR_ADC_R2			(0x1 << 1)
#define RT5659_PWR_ADC_R2_BIT			1
#define RT5659_PWR_CLS_D			(0x1)
#define RT5659_PWR_CLS_D_BIT			0

/* Power Management for Digital 2 (0x0062) */
#define RT5659_PWR_ADC_S1F			(0x1 << 15)
#define RT5659_PWR_ADC_S1F_BIT			15
#define RT5659_PWR_ADC_S2F			(0x1 << 14)
#define RT5659_PWR_ADC_S2F_BIT			14
#define RT5659_PWR_ADC_MF_L			(0x1 << 13)
#define RT5659_PWR_ADC_MF_L_BIT			13
#define RT5659_PWR_ADC_MF_R			(0x1 << 12)
#define RT5659_PWR_ADC_MF_R_BIT			12
#define RT5659_PWR_DAC_S1F			(0x1 << 10)
#define RT5659_PWR_DAC_S1F_BIT			10
#define RT5659_PWR_DAC_MF_L			(0x1 << 9)
#define RT5659_PWR_DAC_MF_L_BIT			9
#define RT5659_PWR_DAC_MF_R			(0x1 << 8)
#define RT5659_PWR_DAC_MF_R_BIT			8
#define RT5659_PWR_PDM1				(0x1 << 7)
#define RT5659_PWR_PDM1_BIT			7

/* Power Management for Analog 1 (0x0063) */
#define RT5659_PWR_VREF1			(0x1 << 15)
#define RT5659_PWR_VREF1_BIT			15
#define RT5659_PWR_FV1				(0x1 << 14)
#define RT5659_PWR_FV1_BIT			14
#define RT5659_PWR_VREF2			(0x1 << 13)
#define RT5659_PWR_VREF2_BIT			13
#define RT5659_PWR_FV2				(0x1 << 12)
#define RT5659_PWR_FV2_BIT			12
#define RT5659_PWR_VREF3			(0x1 << 11)
#define RT5659_PWR_VREF3_BIT			11
#define RT5659_PWR_FV3				(0x1 << 10)
#define RT5659_PWR_FV3_BIT			10
#define RT5659_PWR_MB				(0x1 << 9)
#define RT5659_PWR_MB_BIT			9
#define RT5659_PWR_LM				(0x1 << 8)
#define RT5659_PWR_LM_BIT			8
#define RT5659_PWR_BG				(0x1 << 7)
#define RT5659_PWR_BG_BIT			7
#define RT5659_PWR_MA				(0x1 << 6)
#define RT5659_PWR_MA_BIT			6
#define RT5659_PWR_HA_L				(0x1 << 5)
#define RT5659_PWR_HA_L_BIT			5
#define RT5659_PWR_HA_R				(0x1 << 4)
#define RT5659_PWR_HA_R_BIT			4

/* Power Management for Analog 2 (0x0064) */
#define RT5659_PWR_BST1				(0x1 << 15)
#define RT5659_PWR_BST1_BIT			15
#define RT5659_PWR_BST2				(0x1 << 14)
#define RT5659_PWR_BST2_BIT			14
#define RT5659_PWR_BST3				(0x1 << 13)
#define RT5659_PWR_BST3_BIT			13
#define RT5659_PWR_BST4				(0x1 << 12)
#define RT5659_PWR_BST4_BIT			12
#define RT5659_PWR_MB1				(0x1 << 11)
#define RT5659_PWR_MB1_BIT			11
#define RT5659_PWR_MB2				(0x1 << 10)
#define RT5659_PWR_MB2_BIT			10
#define RT5659_PWR_MB3				(0x1 << 9)
#define RT5659_PWR_MB3_BIT			9
#define RT5659_PWR_BST1_P			(0x1 << 6)
#define RT5659_PWR_BST1_P_BIT			6
#define RT5659_PWR_BST2_P			(0x1 << 5)
#define RT5659_PWR_BST2_P_BIT			5
#define RT5659_PWR_BST3_P			(0x1 << 4)
#define RT5659_PWR_BST3_P_BIT			4
#define RT5659_PWR_BST4_P			(0x1 << 3)
#define RT5659_PWR_BST4_P_BIT			3
#define RT5659_PWR_JD1				(0x1 << 2)
#define RT5659_PWR_JD1_BIT			2
#define RT5659_PWR_JD2				(0x1 << 1)
#define RT5659_PWR_JD2_BIT			1
#define RT5659_PWR_JD3				(0x1)
#define RT5659_PWR_JD3_BIT			0

/* Power Management for Analog 3 (0x0065) */
#define RT5659_PWR_BST_L			(0x1 << 8)
#define RT5659_PWR_BST_L_BIT			8
#define RT5659_PWR_BST_R			(0x1 << 7)
#define RT5659_PWR_BST_R_BIT			7
#define RT5659_PWR_PLL				(0x1 << 6)
#define RT5659_PWR_PLL_BIT			6
#define RT5659_PWR_LDO5				(0x1 << 5)
#define RT5659_PWR_LDO5_BIT			5
#define RT5659_PWR_LDO4				(0x1 << 4)
#define RT5659_PWR_LDO4_BIT			4
#define RT5659_PWR_LDO3				(0x1 << 3)
#define RT5659_PWR_LDO3_BIT			3
#define RT5659_PWR_LDO2				(0x1 << 2)
#define RT5659_PWR_LDO2_BIT			2
#define RT5659_PWR_SVD				(0x1 << 1)
#define RT5659_PWR_SVD_BIT			1

/* Power Management for Mixer (0x0066) */
#define RT5659_PWR_OM_L				(0x1 << 15)
#define RT5659_PWR_OM_L_BIT			15
#define RT5659_PWR_OM_R				(0x1 << 14)
#define RT5659_PWR_OM_R_BIT			14
#define RT5659_PWR_SM_L				(0x1 << 13)
#define RT5659_PWR_SM_L_BIT			13
#define RT5659_PWR_SM_R				(0x1 << 12)
#define RT5659_PWR_SM_R_BIT			12
#define RT5659_PWR_RM1_L			(0x1 << 11)
#define RT5659_PWR_RM1_L_BIT			11
#define RT5659_PWR_RM1_R			(0x1 << 10)
#define RT5659_PWR_RM1_R_BIT			10
#define RT5659_PWR_MM				(0x1 << 8)
#define RT5659_PWR_MM_BIT			8
#define RT5659_PWR_RM2_L			(0x1 << 3)
#define RT5659_PWR_RM2_L_BIT			3
#define RT5659_PWR_RM2_R			(0x1 << 2)
#define RT5659_PWR_RM2_R_BIT			2

/* Power Management for Volume (0x0067) */
#define RT5659_PWR_SV_L				(0x1 << 15)
#define RT5659_PWR_SV_L_BIT			15
#define RT5659_PWR_SV_R				(0x1 << 14)
#define RT5659_PWR_SV_R_BIT			14
#define RT5659_PWR_OV_L				(0x1 << 13)
#define RT5659_PWR_OV_L_BIT			13
#define RT5659_PWR_OV_R				(0x1 << 12)
#define RT5659_PWR_OV_R_BIT			12
#define RT5659_PWR_IN_L				(0x1 << 9)
#define RT5659_PWR_IN_L_BIT			9
#define RT5659_PWR_IN_R				(0x1 << 8)
#define RT5659_PWR_IN_R_BIT			8
#define RT5659_PWR_MV				(0x1 << 7)
#define RT5659_PWR_MV_BIT			7
#define RT5659_PWR_MIC_DET			(0x1 << 5)
#define RT5659_PWR_MIC_DET_BIT			5

/* I2S1/2/3 Audio Serial Data Port Control (0x0070 0x0071 0x0072) */
#define RT5659_I2S_MS_MASK			(0x1 << 15)
#define RT5659_I2S_MS_SFT			15
#define RT5659_I2S_MS_M				(0x0 << 15)
#define RT5659_I2S_MS_S				(0x1 << 15)
#define RT5659_I2S_O_CP_MASK			(0x3 << 12)
#define RT5659_I2S_O_CP_SFT			12
#define RT5659_I2S_O_CP_OFF			(0x0 << 12)
#define RT5659_I2S_O_CP_U_LAW			(0x1 << 12)
#define RT5659_I2S_O_CP_A_LAW			(0x2 << 12)
#define RT5659_I2S_I_CP_MASK			(0x3 << 10)
#define RT5659_I2S_I_CP_SFT			10
#define RT5659_I2S_I_CP_OFF			(0x0 << 10)
#define RT5659_I2S_I_CP_U_LAW			(0x1 << 10)
#define RT5659_I2S_I_CP_A_LAW			(0x2 << 10)
#define RT5659_I2S_BP_MASK			(0x1 << 8)
#define RT5659_I2S_BP_SFT			8
#define RT5659_I2S_BP_NOR			(0x0 << 8)
#define RT5659_I2S_BP_INV			(0x1 << 8)
#define RT5659_I2S_DL_MASK			(0x3 << 4)
#define RT5659_I2S_DL_SFT			4
#define RT5659_I2S_DL_16			(0x0 << 4)
#define RT5659_I2S_DL_20			(0x1 << 4)
#define RT5659_I2S_DL_24			(0x2 << 4)
#define RT5659_I2S_DL_8				(0x3 << 4)
#define RT5659_I2S_DF_MASK			(0x7)
#define RT5659_I2S_DF_SFT			0
#define RT5659_I2S_DF_I2S			(0x0)
#define RT5659_I2S_DF_LEFT			(0x1)
#define RT5659_I2S_DF_PCM_A			(0x2)
#define RT5659_I2S_DF_PCM_B			(0x3)
#define RT5659_I2S_DF_PCM_A_N			(0x6)
#define RT5659_I2S_DF_PCM_B_N			(0x7)

/* ADC/DAC Clock Control 1 (0x0073) */
#define RT5659_I2S_PD1_MASK			(0x7 << 12)
#define RT5659_I2S_PD1_SFT			12
#define RT5659_I2S_PD1_1			(0x0 << 12)
#define RT5659_I2S_PD1_2			(0x1 << 12)
#define RT5659_I2S_PD1_3			(0x2 << 12)
#define RT5659_I2S_PD1_4			(0x3 << 12)
#define RT5659_I2S_PD1_6			(0x4 << 12)
#define RT5659_I2S_PD1_8			(0x5 << 12)
#define RT5659_I2S_PD1_12			(0x6 << 12)
#define RT5659_I2S_PD1_16			(0x7 << 12)
#define RT5659_I2S_BCLK_MS2_MASK		(0x1 << 11)
#define RT5659_I2S_BCLK_MS2_SFT			11
#define RT5659_I2S_BCLK_MS2_32			(0x0 << 11)
#define RT5659_I2S_BCLK_MS2_64			(0x1 << 11)
#define RT5659_I2S_PD2_MASK			(0x7 << 8)
#define RT5659_I2S_PD2_SFT			8
#define RT5659_I2S_PD2_1			(0x0 << 8)
#define RT5659_I2S_PD2_2			(0x1 << 8)
#define RT5659_I2S_PD2_3			(0x2 << 8)
#define RT5659_I2S_PD2_4			(0x3 << 8)
#define RT5659_I2S_PD2_6			(0x4 << 8)
#define RT5659_I2S_PD2_8			(0x5 << 8)
#define RT5659_I2S_PD2_12			(0x6 << 8)
#define RT5659_I2S_PD2_16			(0x7 << 8)
#define RT5659_I2S_BCLK_MS3_MASK		(0x1 << 7)
#define RT5659_I2S_BCLK_MS3_SFT			7
#define RT5659_I2S_BCLK_MS3_32			(0x0 << 7)
#define RT5659_I2S_BCLK_MS3_64			(0x1 << 7)
#define RT5659_I2S_PD3_MASK			(0x7 << 4)
#define RT5659_I2S_PD3_SFT			4
#define RT5659_I2S_PD3_1			(0x0 << 4)
#define RT5659_I2S_PD3_2			(0x1 << 4)
#define RT5659_I2S_PD3_3			(0x2 << 4)
#define RT5659_I2S_PD3_4			(0x3 << 4)
#define RT5659_I2S_PD3_6			(0x4 << 4)
#define RT5659_I2S_PD3_8			(0x5 << 4)
#define RT5659_I2S_PD3_12			(0x6 << 4)
#define RT5659_I2S_PD3_16			(0x7 << 4)
#define RT5659_DAC_OSR_MASK			(0x3 << 2)
#define RT5659_DAC_OSR_SFT			2
#define RT5659_DAC_OSR_128			(0x0 << 2)
#define RT5659_DAC_OSR_64			(0x1 << 2)
#define RT5659_DAC_OSR_32			(0x2 << 2)
#define RT5659_DAC_OSR_16			(0x3 << 2)
#define RT5659_ADC_OSR_MASK			(0x3)
#define RT5659_ADC_OSR_SFT			0
#define RT5659_ADC_OSR_128			(0x0)
#define RT5659_ADC_OSR_64			(0x1)
#define RT5659_ADC_OSR_32			(0x2)
#define RT5659_ADC_OSR_16			(0x3)

/* Digital Microphone Control (0x0075) */
#define RT5659_DMIC_1_EN_MASK			(0x1 << 15)
#define RT5659_DMIC_1_EN_SFT			15
#define RT5659_DMIC_1_DIS			(0x0 << 15)
#define RT5659_DMIC_1_EN			(0x1 << 15)
#define RT5659_DMIC_2_EN_MASK			(0x1 << 14)
#define RT5659_DMIC_2_EN_SFT			14
#define RT5659_DMIC_2_DIS			(0x0 << 14)
#define RT5659_DMIC_2_EN			(0x1 << 14)
#define RT5659_DMIC_1L_LH_MASK			(0x1 << 13)
#define RT5659_DMIC_1L_LH_SFT			13
#define RT5659_DMIC_1L_LH_RISING		(0x0 << 13)
#define RT5659_DMIC_1L_LH_FALLING		(0x1 << 13)
#define RT5659_DMIC_1R_LH_MASK			(0x1 << 12)
#define RT5659_DMIC_1R_LH_SFT			12
#define RT5659_DMIC_1R_LH_RISING		(0x0 << 12)
#define RT5659_DMIC_1R_LH_FALLING		(0x1 << 12)
#define RT5659_DMIC_2_DP_MASK			(0x3 << 10)
#define RT5659_DMIC_2_DP_SFT			10
#define RT5659_DMIC_2_DP_GPIO6			(0x0 << 10)
#define RT5659_DMIC_2_DP_GPIO10			(0x1 << 10)
#define RT5659_DMIC_2_DP_GPIO12			(0x2 << 10)
#define RT5659_DMIC_2_DP_IN2P			(0x3 << 10)
#define RT5659_DMIC_CLK_MASK			(0x7 << 5)
#define RT5659_DMIC_CLK_SFT			5
#define RT5659_DMIC_1_DP_MASK			(0x3 << 0)
#define RT5659_DMIC_1_DP_SFT			0
#define RT5659_DMIC_1_DP_GPIO5			(0x0 << 0)
#define RT5659_DMIC_1_DP_GPIO9			(0x1 << 0)
#define RT5659_DMIC_1_DP_GPIO11			(0x2 << 0)
#define RT5659_DMIC_1_DP_IN2N			(0x3 << 0)

/* TDM control 1 (0x0078)*/
#define RT5659_DS_ADC_SLOT01_SFT		14
#define RT5659_DS_ADC_SLOT23_SFT		12
#define RT5659_DS_ADC_SLOT45_SFT		10
#define RT5659_DS_ADC_SLOT67_SFT		8
#define RT5659_ADCDAT_SRC_MASK			0x1f
#define RT5659_ADCDAT_SRC_SFT			0

/* Global Clock Control (0x0080) */
#define RT5659_SCLK_SRC_MASK			(0x3 << 14)
#define RT5659_SCLK_SRC_SFT			14
#define RT5659_SCLK_SRC_MCLK			(0x0 << 14)
#define RT5659_SCLK_SRC_PLL1			(0x1 << 14)
#define RT5659_SCLK_SRC_RCCLK			(0x2 << 14)
#define RT5659_PLL1_SRC_MASK			(0x7 << 11)
#define RT5659_PLL1_SRC_SFT			11
#define RT5659_PLL1_SRC_MCLK			(0x0 << 11)
#define RT5659_PLL1_SRC_BCLK1			(0x1 << 11)
#define RT5659_PLL1_SRC_BCLK2			(0x2 << 11)
#define RT5659_PLL1_SRC_BCLK3			(0x3 << 11)
#define RT5659_PLL1_PD_MASK			(0x1 << 3)
#define RT5659_PLL1_PD_SFT			3
#define RT5659_PLL1_PD_1			(0x0 << 3)
#define RT5659_PLL1_PD_2			(0x1 << 3)

#define RT5659_PLL_INP_MAX			40000000
#define RT5659_PLL_INP_MIN			256000
/* PLL M/N/K Code Control 1 (0x0081) */
#define RT5659_PLL_N_MAX			0x001ff
#define RT5659_PLL_N_MASK			(RT5659_PLL_N_MAX << 7)
#define RT5659_PLL_N_SFT			7
#define RT5659_PLL_K_MAX			0x001f
#define RT5659_PLL_K_MASK			(RT5659_PLL_K_MAX)
#define RT5659_PLL_K_SFT			0

/* PLL M/N/K Code Control 2 (0x0082) */
#define RT5659_PLL_M_MAX			0x00f
#define RT5659_PLL_M_MASK			(RT5659_PLL_M_MAX << 12)
#define RT5659_PLL_M_SFT			12
#define RT5659_PLL_M_BP				(0x1 << 11)
#define RT5659_PLL_M_BP_SFT			11

/* PLL tracking mode 1 (0x0083) */
#define RT5659_I2S3_ASRC_MASK			(0x1 << 13)
#define RT5659_I2S3_ASRC_SFT			13
#define RT5659_I2S2_ASRC_MASK			(0x1 << 12)
#define RT5659_I2S2_ASRC_SFT			12
#define RT5659_I2S1_ASRC_MASK			(0x1 << 11)
#define RT5659_I2S1_ASRC_SFT			11
#define RT5659_DAC_STO_ASRC_MASK		(0x1 << 10)
#define RT5659_DAC_STO_ASRC_SFT			10
#define RT5659_DAC_MONO_L_ASRC_MASK		(0x1 << 9)
#define RT5659_DAC_MONO_L_ASRC_SFT		9
#define RT5659_DAC_MONO_R_ASRC_MASK		(0x1 << 8)
#define RT5659_DAC_MONO_R_ASRC_SFT		8
#define RT5659_DMIC_STO1_ASRC_MASK		(0x1 << 7)
#define RT5659_DMIC_STO1_ASRC_SFT		7
#define RT5659_DMIC_MONO_L_ASRC_MASK		(0x1 << 5)
#define RT5659_DMIC_MONO_L_ASRC_SFT		5
#define RT5659_DMIC_MONO_R_ASRC_MASK		(0x1 << 4)
#define RT5659_DMIC_MONO_R_ASRC_SFT		4
#define RT5659_ADC_STO1_ASRC_MASK		(0x1 << 3)
#define RT5659_ADC_STO1_ASRC_SFT		3
#define RT5659_ADC_MONO_L_ASRC_MASK		(0x1 << 1)
#define RT5659_ADC_MONO_L_ASRC_SFT		1
#define RT5659_ADC_MONO_R_ASRC_MASK		(0x1)
#define RT5659_ADC_MONO_R_ASRC_SFT		0

/* PLL tracking mode 2 (0x0084)*/
#define RT5659_DA_STO_T_MASK			(0x7 << 12)
#define RT5659_DA_STO_T_SFT			12
#define RT5659_DA_MONO_L_T_MASK			(0x7 << 8)
#define RT5659_DA_MONO_L_T_SFT			8
#define RT5659_DA_MONO_R_T_MASK			(0x7 << 4)
#define RT5659_DA_MONO_R_T_SFT			4
#define RT5659_AD_STO1_T_MASK			(0x7)
#define RT5659_AD_STO1_T_SFT			0

/* PLL tracking mode 3 (0x0085)*/
#define RT5659_AD_STO2_T_MASK			(0x7 << 8)
#define RT5659_AD_STO2_T_SFT			8
#define RT5659_AD_MONO_L_T_MASK			(0x7 << 4)
#define RT5659_AD_MONO_L_T_SFT			4
#define RT5659_AD_MONO_R_T_MASK			(0x7)
#define RT5659_AD_MONO_R_T_SFT			0

/* ASRC Control 4 (0x0086) */
#define RT5659_I2S1_RATE_MASK			(0xf << 12)
#define RT5659_I2S1_RATE_SFT			12
#define RT5659_I2S2_RATE_MASK			(0xf << 8)
#define RT5659_I2S2_RATE_SFT			8
#define RT5659_I2S3_RATE_MASK			(0xf << 4)
#define RT5659_I2S3_RATE_SFT			4

/* Depop Mode Control 1 (0x8e) */
#define RT5659_SMT_TRIG_MASK			(0x1 << 15)
#define RT5659_SMT_TRIG_SFT			15
#define RT5659_SMT_TRIG_DIS			(0x0 << 15)
#define RT5659_SMT_TRIG_EN			(0x1 << 15)
#define RT5659_HP_L_SMT_MASK			(0x1 << 9)
#define RT5659_HP_L_SMT_SFT			9
#define RT5659_HP_L_SMT_DIS			(0x0 << 9)
#define RT5659_HP_L_SMT_EN			(0x1 << 9)
#define RT5659_HP_R_SMT_MASK			(0x1 << 8)
#define RT5659_HP_R_SMT_SFT			8
#define RT5659_HP_R_SMT_DIS			(0x0 << 8)
#define RT5659_HP_R_SMT_EN			(0x1 << 8)
#define RT5659_HP_CD_PD_MASK			(0x1 << 7)
#define RT5659_HP_CD_PD_SFT			7
#define RT5659_HP_CD_PD_DIS			(0x0 << 7)
#define RT5659_HP_CD_PD_EN			(0x1 << 7)
#define RT5659_RSTN_MASK			(0x1 << 6)
#define RT5659_RSTN_SFT				6
#define RT5659_RSTN_DIS				(0x0 << 6)
#define RT5659_RSTN_EN				(0x1 << 6)
#define RT5659_RSTP_MASK			(0x1 << 5)
#define RT5659_RSTP_SFT				5
#define RT5659_RSTP_DIS				(0x0 << 5)
#define RT5659_RSTP_EN				(0x1 << 5)
#define RT5659_HP_CO_MASK			(0x1 << 4)
#define RT5659_HP_CO_SFT			4
#define RT5659_HP_CO_DIS			(0x0 << 4)
#define RT5659_HP_CO_EN				(0x1 << 4)
#define RT5659_HP_CP_MASK			(0x1 << 3)
#define RT5659_HP_CP_SFT			3
#define RT5659_HP_CP_PD				(0x0 << 3)
#define RT5659_HP_CP_PU				(0x1 << 3)
#define RT5659_HP_SG_MASK			(0x1 << 2)
#define RT5659_HP_SG_SFT			2
#define RT5659_HP_SG_DIS			(0x0 << 2)
#define RT5659_HP_SG_EN				(0x1 << 2)
#define RT5659_HP_DP_MASK			(0x1 << 1)
#define RT5659_HP_DP_SFT			1
#define RT5659_HP_DP_PD				(0x0 << 1)
#define RT5659_HP_DP_PU				(0x1 << 1)
#define RT5659_HP_CB_MASK			(0x1)
#define RT5659_HP_CB_SFT			0
#define RT5659_HP_CB_PD				(0x0)
#define RT5659_HP_CB_PU				(0x1)

/* Depop Mode Control 2 (0x8f) */
#define RT5659_DEPOP_MASK			(0x1 << 13)
#define RT5659_DEPOP_SFT			13
#define RT5659_DEPOP_AUTO			(0x0 << 13)
#define RT5659_DEPOP_MAN			(0x1 << 13)
#define RT5659_RAMP_MASK			(0x1 << 12)
#define RT5659_RAMP_SFT				12
#define RT5659_RAMP_DIS				(0x0 << 12)
#define RT5659_RAMP_EN				(0x1 << 12)
#define RT5659_BPS_MASK				(0x1 << 11)
#define RT5659_BPS_SFT				11
#define RT5659_BPS_DIS				(0x0 << 11)
#define RT5659_BPS_EN				(0x1 << 11)
#define RT5659_FAST_UPDN_MASK			(0x1 << 10)
#define RT5659_FAST_UPDN_SFT			10
#define RT5659_FAST_UPDN_DIS			(0x0 << 10)
#define RT5659_FAST_UPDN_EN			(0x1 << 10)
#define RT5659_MRES_MASK			(0x3 << 8)
#define RT5659_MRES_SFT				8
#define RT5659_MRES_15MO			(0x0 << 8)
#define RT5659_MRES_25MO			(0x1 << 8)
#define RT5659_MRES_35MO			(0x2 << 8)
#define RT5659_MRES_45MO			(0x3 << 8)
#define RT5659_VLO_MASK				(0x1 << 7)
#define RT5659_VLO_SFT				7
#define RT5659_VLO_3V				(0x0 << 7)
#define RT5659_VLO_32V				(0x1 << 7)
#define RT5659_DIG_DP_MASK			(0x1 << 6)
#define RT5659_DIG_DP_SFT			6
#define RT5659_DIG_DP_DIS			(0x0 << 6)
#define RT5659_DIG_DP_EN			(0x1 << 6)
#define RT5659_DP_TH_MASK			(0x3 << 4)
#define RT5659_DP_TH_SFT			4

/* Depop Mode Control 3 (0x90) */
#define RT5659_CP_SYS_MASK			(0x7 << 12)
#define RT5659_CP_SYS_SFT			12
#define RT5659_CP_FQ1_MASK			(0x7 << 8)
#define RT5659_CP_FQ1_SFT			8
#define RT5659_CP_FQ2_MASK			(0x7 << 4)
#define RT5659_CP_FQ2_SFT			4
#define RT5659_CP_FQ3_MASK			(0x7)
#define RT5659_CP_FQ3_SFT			0
#define RT5659_CP_FQ_1_5_KHZ			0
#define RT5659_CP_FQ_3_KHZ			1
#define RT5659_CP_FQ_6_KHZ			2
#define RT5659_CP_FQ_12_KHZ			3
#define RT5659_CP_FQ_24_KHZ			4
#define RT5659_CP_FQ_48_KHZ			5
#define RT5659_CP_FQ_96_KHZ			6
#define RT5659_CP_FQ_192_KHZ			7

/* HPOUT charge pump 1 (0x0091) */
#define RT5659_OSW_L_MASK			(0x1 << 11)
#define RT5659_OSW_L_SFT			11
#define RT5659_OSW_L_DIS			(0x0 << 11)
#define RT5659_OSW_L_EN				(0x1 << 11)
#define RT5659_OSW_R_MASK			(0x1 << 10)
#define RT5659_OSW_R_SFT			10
#define RT5659_OSW_R_DIS			(0x0 << 10)
#define RT5659_OSW_R_EN				(0x1 << 10)
#define RT5659_PM_HP_MASK			(0x3 << 8)
#define RT5659_PM_HP_SFT			8
#define RT5659_PM_HP_LV				(0x0 << 8)
#define RT5659_PM_HP_MV				(0x1 << 8)
#define RT5659_PM_HP_HV				(0x2 << 8)
#define RT5659_IB_HP_MASK			(0x3 << 6)
#define RT5659_IB_HP_SFT			6
#define RT5659_IB_HP_125IL			(0x0 << 6)
#define RT5659_IB_HP_25IL			(0x1 << 6)
#define RT5659_IB_HP_5IL			(0x2 << 6)
#define RT5659_IB_HP_1IL			(0x3 << 6)

/* PV detection and SPK gain control (0x92) */
#define RT5659_PVDD_DET_MASK			(0x1 << 15)
#define RT5659_PVDD_DET_SFT			15
#define RT5659_PVDD_DET_DIS			(0x0 << 15)
#define RT5659_PVDD_DET_EN			(0x1 << 15)
#define RT5659_SPK_AG_MASK			(0x1 << 14)
#define RT5659_SPK_AG_SFT			14
#define RT5659_SPK_AG_DIS			(0x0 << 14)
#define RT5659_SPK_AG_EN			(0x1 << 14)

/* Micbias Control (0x93) */
#define RT5659_MIC1_BS_MASK			(0x1 << 15)
#define RT5659_MIC1_BS_SFT			15
#define RT5659_MIC1_BS_9AV			(0x0 << 15)
#define RT5659_MIC1_BS_75AV			(0x1 << 15)
#define RT5659_MIC2_BS_MASK			(0x1 << 14)
#define RT5659_MIC2_BS_SFT			14
#define RT5659_MIC2_BS_9AV			(0x0 << 14)
#define RT5659_MIC2_BS_75AV			(0x1 << 14)
#define RT5659_MIC1_CLK_MASK			(0x1 << 13)
#define RT5659_MIC1_CLK_SFT			13
#define RT5659_MIC1_CLK_DIS			(0x0 << 13)
#define RT5659_MIC1_CLK_EN			(0x1 << 13)
#define RT5659_MIC2_CLK_MASK			(0x1 << 12)
#define RT5659_MIC2_CLK_SFT			12
#define RT5659_MIC2_CLK_DIS			(0x0 << 12)
#define RT5659_MIC2_CLK_EN			(0x1 << 12)
#define RT5659_MIC1_OVCD_MASK			(0x1 << 11)
#define RT5659_MIC1_OVCD_SFT			11
#define RT5659_MIC1_OVCD_DIS			(0x0 << 11)
#define RT5659_MIC1_OVCD_EN			(0x1 << 11)
#define RT5659_MIC1_OVTH_MASK			(0x3 << 9)
#define RT5659_MIC1_OVTH_SFT			9
#define RT5659_MIC1_OVTH_600UA			(0x0 << 9)
#define RT5659_MIC1_OVTH_1500UA			(0x1 << 9)
#define RT5659_MIC1_OVTH_2000UA			(0x2 << 9)
#define RT5659_MIC2_OVCD_MASK			(0x1 << 8)
#define RT5659_MIC2_OVCD_SFT			8
#define RT5659_MIC2_OVCD_DIS			(0x0 << 8)
#define RT5659_MIC2_OVCD_EN			(0x1 << 8)
#define RT5659_MIC2_OVTH_MASK			(0x3 << 6)
#define RT5659_MIC2_OVTH_SFT			6
#define RT5659_MIC2_OVTH_600UA			(0x0 << 6)
#define RT5659_MIC2_OVTH_1500UA			(0x1 << 6)
#define RT5659_MIC2_OVTH_2000UA			(0x2 << 6)
#define RT5659_PWR_MB_MASK			(0x1 << 5)
#define RT5659_PWR_MB_SFT			5
#define RT5659_PWR_MB_PD			(0x0 << 5)
#define RT5659_PWR_MB_PU			(0x1 << 5)
#define RT5659_PWR_CLK25M_MASK			(0x1 << 4)
#define RT5659_PWR_CLK25M_SFT			4
#define RT5659_PWR_CLK25M_PD			(0x0 << 4)
#define RT5659_PWR_CLK25M_PU			(0x1 << 4)

/* REC Mixer 2 Left Control 2 (0x009c) */
#define RT5659_M_BST1_RM2_L			(0x1 << 5)
#define RT5659_M_BST1_RM2_L_SFT			5
#define RT5659_M_BST2_RM2_L			(0x1 << 4)
#define RT5659_M_BST2_RM2_L_SFT			4
#define RT5659_M_BST3_RM2_L			(0x1 << 3)
#define RT5659_M_BST3_RM2_L_SFT			3
#define RT5659_M_BST4_RM2_L			(0x1 << 2)
#define RT5659_M_BST4_RM2_L_SFT			2
#define RT5659_M_OUTVOLL_RM2_L			(0x1 << 1)
#define RT5659_M_OUTVOLL_RM2_L_SFT		1
#define RT5659_M_SPKVOL_RM2_L			(0x1)
#define RT5659_M_SPKVOL_RM2_L_SFT		0

/* REC Mixer 2 Right Control 2 (0x009e) */
#define RT5659_M_BST1_RM2_R			(0x1 << 5)
#define RT5659_M_BST1_RM2_R_SFT			5
#define RT5659_M_BST2_RM2_R			(0x1 << 4)
#define RT5659_M_BST2_RM2_R_SFT			4
#define RT5659_M_BST3_RM2_R			(0x1 << 3)
#define RT5659_M_BST3_RM2_R_SFT			3
#define RT5659_M_BST4_RM2_R			(0x1 << 2)
#define RT5659_M_BST4_RM2_R_SFT			2
#define RT5659_M_OUTVOLR_RM2_R			(0x1 << 1)
#define RT5659_M_OUTVOLR_RM2_R_SFT		1
#define RT5659_M_MONOVOL_RM2_R			(0x1)
#define RT5659_M_MONOVOL_RM2_R_SFT		0

/* Class D Output Control (0x00a0) */
#define RT5659_POW_CLSD_DB_MASK			(0x1 << 9)
#define RT5659_POW_CLSD_DB_EN			(0x1 << 9)
#define RT5659_POW_CLSD_DB_DIS			(0x0 << 9)

/* EQ Control 1 (0x00b0) */
#define RT5659_EQ_SRC_DAC			(0x0 << 15)
#define RT5659_EQ_SRC_ADC			(0x1 << 15)
#define RT5659_EQ_UPD				(0x1 << 14)
#define RT5659_EQ_UPD_BIT			14
#define RT5659_EQ_CD_MASK			(0x1 << 13)
#define RT5659_EQ_CD_SFT			13
#define RT5659_EQ_CD_DIS			(0x0 << 13)
#define RT5659_EQ_CD_EN				(0x1 << 13)
#define RT5659_EQ_DITH_MASK			(0x3 << 8)
#define RT5659_EQ_DITH_SFT			8
#define RT5659_EQ_DITH_NOR			(0x0 << 8)
#define RT5659_EQ_DITH_LSB			(0x1 << 8)
#define RT5659_EQ_DITH_LSB_1			(0x2 << 8)
#define RT5659_EQ_DITH_LSB_2			(0x3 << 8)

/* IRQ Control 1 (0x00b7) */
#define RT5659_JD1_1_EN_MASK			(0x1 << 15)
#define RT5659_JD1_1_EN_SFT			15
#define RT5659_JD1_1_DIS			(0x0 << 15)
#define RT5659_JD1_1_EN				(0x1 << 15)
#define RT5659_JD1_2_EN_MASK			(0x1 << 12)
#define RT5659_JD1_2_EN_SFT			12
#define RT5659_JD1_2_DIS			(0x0 << 12)
#define RT5659_JD1_2_EN				(0x1 << 12)
#define RT5659_IL_IRQ_MASK			(0x1 << 3)
#define RT5659_IL_IRQ_DIS			(0x0 << 3)
#define RT5659_IL_IRQ_EN			(0x1 << 3)

/* IRQ Control 5 (0x00ba) */
#define RT5659_IRQ_JD_EN			(0x1 << 3)
#define RT5659_IRQ_JD_EN_SFT			3

/* GPIO Control 1 (0x00c0) */
#define RT5659_GP1_PIN_MASK			(0x1 << 15)
#define RT5659_GP1_PIN_SFT			15
#define RT5659_GP1_PIN_GPIO1			(0x0 << 15)
#define RT5659_GP1_PIN_IRQ			(0x1 << 15)
#define RT5659_GP2_PIN_MASK			(0x1 << 14)
#define RT5659_GP2_PIN_SFT			14
#define RT5659_GP2_PIN_GPIO2			(0x0 << 14)
#define RT5659_GP2_PIN_DMIC1_SCL		(0x1 << 14)
#define RT5659_GP3_PIN_MASK			(0x1 << 13)
#define RT5659_GP3_PIN_SFT			13
#define RT5659_GP3_PIN_GPIO3			(0x0 << 13)
#define RT5659_GP3_PIN_PDM_SCL			(0x1 << 13)
#define RT5659_GP4_PIN_MASK			(0x1 << 12)
#define RT5659_GP4_PIN_SFT			12
#define RT5659_GP4_PIN_GPIO4			(0x0 << 12)
#define RT5659_GP4_PIN_PDM_SDA			(0x1 << 12)
#define RT5659_GP5_PIN_MASK			(0x1 << 11)
#define RT5659_GP5_PIN_SFT			11
#define RT5659_GP5_PIN_GPIO5			(0x0 << 11)
#define RT5659_GP5_PIN_DMIC1_SDA		(0x1 << 11)
#define RT5659_GP6_PIN_MASK			(0x1 << 10)
#define RT5659_GP6_PIN_SFT			10
#define RT5659_GP6_PIN_GPIO6			(0x0 << 10)
#define RT5659_GP6_PIN_DMIC2_SDA		(0x1 << 10)
#define RT5659_GP7_PIN_MASK			(0x1 << 9)
#define RT5659_GP7_PIN_SFT			9
#define RT5659_GP7_PIN_GPIO7			(0x0 << 9)
#define RT5659_GP7_PIN_PDM_SCL			(0x1 << 9)
#define RT5659_GP8_PIN_MASK			(0x1 << 8)
#define RT5659_GP8_PIN_SFT			8
#define RT5659_GP8_PIN_GPIO8			(0x0 << 8)
#define RT5659_GP8_PIN_PDM_SDA			(0x1 << 8)
#define RT5659_GP9_PIN_MASK			(0x1 << 7)
#define RT5659_GP9_PIN_SFT			7
#define RT5659_GP9_PIN_GPIO9			(0x0 << 7)
#define RT5659_GP9_PIN_DMIC1_SDA		(0x1 << 7)
#define RT5659_GP10_PIN_MASK			(0x1 << 6)
#define RT5659_GP10_PIN_SFT			6
#define RT5659_GP10_PIN_GPIO10			(0x0 << 6)
#define RT5659_GP10_PIN_DMIC2_SDA		(0x1 << 6)
#define RT5659_GP11_PIN_MASK			(0x1 << 5)
#define RT5659_GP11_PIN_SFT			5
#define RT5659_GP11_PIN_GPIO11			(0x0 << 5)
#define RT5659_GP11_PIN_DMIC1_SDA		(0x1 << 5)
#define RT5659_GP12_PIN_MASK			(0x1 << 4)
#define RT5659_GP12_PIN_SFT			4
#define RT5659_GP12_PIN_GPIO12			(0x0 << 4)
#define RT5659_GP12_PIN_DMIC2_SDA		(0x1 << 4)
#define RT5659_GP13_PIN_MASK			(0x3 << 2)
#define RT5659_GP13_PIN_SFT			2
#define RT5659_GP13_PIN_GPIO13			(0x0 << 2)
#define RT5659_GP13_PIN_SPDIF_SDA		(0x1 << 2)
#define RT5659_GP13_PIN_DMIC2_SCL		(0x2 << 2)
#define RT5659_GP13_PIN_PDM_SCL			(0x3 << 2)
#define RT5659_GP15_PIN_MASK			(0x3)
#define RT5659_GP15_PIN_SFT			0
#define RT5659_GP15_PIN_GPIO15			(0x0)
#define RT5659_GP15_PIN_DMIC3_SCL		(0x1)
#define RT5659_GP15_PIN_PDM_SDA			(0x2)

/* GPIO Control 2 (0x00c1)*/
#define RT5659_GP1_PF_IN			(0x0 << 2)
#define RT5659_GP1_PF_OUT			(0x1 << 2)
#define RT5659_GP1_PF_MASK			(0x1 << 2)
#define RT5659_GP1_PF_SFT			2

/* GPIO Control 3 (0x00c2) */
#define RT5659_I2S2_PIN_MASK			(0x1 << 15)
#define RT5659_I2S2_PIN_SFT			15
#define RT5659_I2S2_PIN_I2S			(0x0 << 15)
#define RT5659_I2S2_PIN_GPIO			(0x1 << 15)

/* Soft volume and zero cross control 1 (0x00d9) */
#define RT5659_SV_MASK				(0x1 << 15)
#define RT5659_SV_SFT				15
#define RT5659_SV_DIS				(0x0 << 15)
#define RT5659_SV_EN				(0x1 << 15)
#define RT5659_OUT_SV_MASK			(0x1 << 13)
#define RT5659_OUT_SV_SFT			13
#define RT5659_OUT_SV_DIS			(0x0 << 13)
#define RT5659_OUT_SV_EN			(0x1 << 13)
#define RT5659_HP_SV_MASK			(0x1 << 12)
#define RT5659_HP_SV_SFT			12
#define RT5659_HP_SV_DIS			(0x0 << 12)
#define RT5659_HP_SV_EN				(0x1 << 12)
#define RT5659_ZCD_DIG_MASK			(0x1 << 11)
#define RT5659_ZCD_DIG_SFT			11
#define RT5659_ZCD_DIG_DIS			(0x0 << 11)
#define RT5659_ZCD_DIG_EN			(0x1 << 11)
#define RT5659_ZCD_MASK				(0x1 << 10)
#define RT5659_ZCD_SFT				10
#define RT5659_ZCD_PD				(0x0 << 10)
#define RT5659_ZCD_PU				(0x1 << 10)
#define RT5659_SV_DLY_MASK			(0xf)
#define RT5659_SV_DLY_SFT			0

/* Soft volume and zero cross control 2 (0x00da) */
#define RT5659_ZCD_HP_MASK			(0x1 << 15)
#define RT5659_ZCD_HP_SFT			15
#define RT5659_ZCD_HP_DIS			(0x0 << 15)
#define RT5659_ZCD_HP_EN			(0x1 << 15)

/* 4 Button Inline Command Control 2 (0x00e0) */
#define RT5659_4BTN_IL_MASK			(0x1 << 15)
#define RT5659_4BTN_IL_EN			(0x1 << 15)
#define RT5659_4BTN_IL_DIS			(0x0 << 15)

/* Analog JD Control 1 (0x00f0) */
#define RT5659_JD1_MODE_MASK			(0x3 << 0)
#define RT5659_JD1_MODE_0			(0x0 << 0)
#define RT5659_JD1_MODE_1			(0x1 << 0)
#define RT5659_JD1_MODE_2			(0x2 << 0)

/* Jack Detect Control 3 (0x00f8) */
#define RT5659_JD_TRI_HPO_SEL_MASK		(0x7)
#define RT5659_JD_TRI_HPO_SEL_SFT		(0)
#define RT5659_JD_HPO_GPIO_JD1			(0x0)
#define RT5659_JD_HPO_JD1_1			(0x1)
#define RT5659_JD_HPO_JD1_2			(0x2)
#define RT5659_JD_HPO_JD2			(0x3)
#define RT5659_JD_HPO_GPIO_JD2			(0x4)
#define RT5659_JD_HPO_JD3			(0x5)
#define RT5659_JD_HPO_JD_D			(0x6)

/* Digital Misc Control (0x00fa) */
#define RT5659_AM_MASK				(0x1 << 7)
#define RT5659_AM_EN				(0x1 << 7)
#define RT5659_AM_DIS				(0x1 << 7)
#define RT5659_DIG_GATE_CTRL			0x1
#define RT5659_DIG_GATE_CTRL_SFT		(0)

/* Chopper and Clock control for ADC (0x011c)*/
#define RT5659_M_RF_DIG_MASK			(0x1 << 12)
#define RT5659_M_RF_DIG_SFT			12
#define RT5659_M_RI_DIG				(0x1 << 11)

/* Chopper and Clock control for DAC (0x013a)*/
#define RT5659_CKXEN_DAC1_MASK			(0x1 << 13)
#define RT5659_CKXEN_DAC1_SFT			13
#define RT5659_CKGEN_DAC1_MASK			(0x1 << 12)
#define RT5659_CKGEN_DAC1_SFT			12
#define RT5659_CKXEN_DAC2_MASK			(0x1 << 5)
#define RT5659_CKXEN_DAC2_SFT			5
#define RT5659_CKGEN_DAC2_MASK			(0x1 << 4)
#define RT5659_CKGEN_DAC2_SFT			4

/* Chopper and Clock control for ADC (0x013b)*/
#define RT5659_CKXEN_ADC1_MASK			(0x1 << 13)
#define RT5659_CKXEN_ADC1_SFT			13
#define RT5659_CKGEN_ADC1_MASK			(0x1 << 12)
#define RT5659_CKGEN_ADC1_SFT			12
#define RT5659_CKXEN_ADC2_MASK			(0x1 << 5)
#define RT5659_CKXEN_ADC2_SFT			5
#define RT5659_CKGEN_ADC2_MASK			(0x1 << 4)
#define RT5659_CKGEN_ADC2_SFT			4

/* Test Mode Control 1 (0x0145) */
#define RT5659_AD2DA_LB_MASK			(0x1 << 9)
#define RT5659_AD2DA_LB_SFT			9

/* Stereo Noise Gate Control 1 (0x0160) */
#define RT5659_NG2_EN_MASK			(0x1 << 15)
#define RT5659_NG2_EN				(0x1 << 15)
#define RT5659_NG2_DIS				(0x0 << 15)

/* System Clock Source */
enum {
	RT5659_SCLK_S_MCLK,
	RT5659_SCLK_S_PLL1,
	RT5659_SCLK_S_RCCLK,
};

/* PLL1 Source */
enum {
	RT5659_PLL1_S_MCLK,
	RT5659_PLL1_S_BCLK1,
	RT5659_PLL1_S_BCLK2,
	RT5659_PLL1_S_BCLK3,
	RT5659_PLL1_S_BCLK4,
};

enum {
	RT5659_AIF1,
	RT5659_AIF2,
	RT5659_AIF3,
	RT5659_AIF4,
	RT5659_AIFS,
};

struct rt5659_pll_code {
	bool m_bp;
	int m_code;
	int n_code;
	int k_code;
};

struct rt5659_priv {
	struct snd_soc_component *component;
	struct rt5659_platform_data pdata;
	struct regmap *regmap;
	struct gpio_desc *gpiod_ldo1_en;
	struct gpio_desc *gpiod_reset;
	struct snd_soc_jack *hs_jack;
	struct delayed_work jack_detect_work;
	struct clk *mclk;

	int sysclk;
	int sysclk_src;
	int lrck[RT5659_AIFS];
	int bclk[RT5659_AIFS];
	int master[RT5659_AIFS];
	int v_id;

	int pll_src;
	int pll_in;
	int pll_out;

	int jack_type;
	bool hda_hp_plugged;
	bool hda_mic_plugged;
};

int rt5659_set_jack_detect(struct snd_soc_component *component,
	struct snd_soc_jack *hs_jack);

#endif /* __RT5659_H__ */
