/* SPDX-License-Identifier: GPL-2.0 */
/* Copyright (c) 2018, NVIDIA CORPORATION. All rights reserved. */

#ifndef __ABI_MACH_T194_CLOCK_H
#define __ABI_MACH_T194_CLOCK_H

#define TEGRA194_CLK_ACTMON			1
#define TEGRA194_CLK_ADSP			2
#define TEGRA194_CLK_ADSPNEON			3
#define TEGRA194_CLK_AHUB			4
#define TEGRA194_CLK_APB2APE			5
#define TEGRA194_CLK_APE			6
#define TEGRA194_CLK_AUD_MCLK			7
#define TEGRA194_CLK_AXI_CBB			8
#define TEGRA194_CLK_CAN1			9
#define TEGRA194_CLK_CAN1_HOST			10
#define TEGRA194_CLK_CAN2			11
#define TEGRA194_CLK_CAN2_HOST			12
#define TEGRA194_CLK_CEC			13
#define TEGRA194_CLK_CLK_M			14
#define TEGRA194_CLK_DMIC1			15
#define TEGRA194_CLK_DMIC2			16
#define TEGRA194_CLK_DMIC3			17
#define TEGRA194_CLK_DMIC4			18
#define TEGRA194_CLK_DPAUX			19
#define TEGRA194_CLK_DPAUX1			20
#define TEGRA194_CLK_ACLK			21
#define TEGRA194_CLK_MSS_ENCRYPT		22
#define TEGRA194_CLK_EQOS_RX_INPUT		23
#define TEGRA194_CLK_IQC2			24
#define TEGRA194_CLK_AON_APB			25
#define TEGRA194_CLK_AON_NIC			26
#define TEGRA194_CLK_AON_CPU_NIC		27
#define TEGRA194_CLK_PLLA1			28
#define TEGRA194_CLK_DSPK1			29
#define TEGRA194_CLK_DSPK2			30
#define TEGRA194_CLK_EMC			31
#define TEGRA194_CLK_EQOS_AXI			32
#define TEGRA194_CLK_EQOS_PTP_REF		33
#define TEGRA194_CLK_EQOS_RX			34
#define TEGRA194_CLK_EQOS_TX			35
#define TEGRA194_CLK_EXTPERIPH1			36
#define TEGRA194_CLK_EXTPERIPH2			37
#define TEGRA194_CLK_EXTPERIPH3			38
#define TEGRA194_CLK_EXTPERIPH4			39
#define TEGRA194_CLK_FUSE			40
#define TEGRA194_CLK_GPCCLK			41
#define TEGRA194_CLK_GPU_PWR			42
#define TEGRA194_CLK_HDA			43
#define TEGRA194_CLK_HDA2CODEC_2X		44
#define TEGRA194_CLK_HDA2HDMICODEC		45
#define TEGRA194_CLK_HOST1X			46
#define TEGRA194_CLK_HSIC_TRK			47
#define TEGRA194_CLK_I2C1			48
#define TEGRA194_CLK_I2C2			49
#define TEGRA194_CLK_I2C3			50
#define TEGRA194_CLK_I2C4			51
#define TEGRA194_CLK_I2C6			52
#define TEGRA194_CLK_I2C7			53
#define TEGRA194_CLK_I2C8			54
#define TEGRA194_CLK_I2C9			55
#define TEGRA194_CLK_I2S1			56
#define TEGRA194_CLK_I2S1_SYNC_INPUT		57
#define TEGRA194_CLK_I2S2			58
#define TEGRA194_CLK_I2S2_SYNC_INPUT		59
#define TEGRA194_CLK_I2S3			60
#define TEGRA194_CLK_I2S3_SYNC_INPUT		61
#define TEGRA194_CLK_I2S4			62
#define TEGRA194_CLK_I2S4_SYNC_INPUT		63
#define TEGRA194_CLK_I2S5			64
#define TEGRA194_CLK_I2S5_SYNC_INPUT		65
#define TEGRA194_CLK_I2S6			66
#define TEGRA194_CLK_I2S6_SYNC_INPUT		67
#define TEGRA194_CLK_IQC1			68
#define TEGRA194_CLK_ISP			69
#define TEGRA194_CLK_KFUSE			70
#define TEGRA194_CLK_MAUD			71
#define TEGRA194_CLK_MIPI_CAL			72
#define TEGRA194_CLK_MPHY_CORE_PLL_FIXED	73
#define TEGRA194_CLK_MPHY_L0_RX_ANA		74
#define TEGRA194_CLK_MPHY_L0_RX_LS_BIT		75
#define TEGRA194_CLK_MPHY_L0_RX_SYMB		76
#define TEGRA194_CLK_MPHY_L0_TX_LS_3XBIT	77
#define TEGRA194_CLK_MPHY_L0_TX_SYMB		78
#define TEGRA194_CLK_MPHY_L1_RX_ANA		79
#define TEGRA194_CLK_MPHY_TX_1MHZ_REF		80
#define TEGRA194_CLK_NVCSI			81
#define TEGRA194_CLK_NVCSILP			82
#define TEGRA194_CLK_NVDEC			83
#define TEGRA194_CLK_NVDISPLAYHUB		84
#define TEGRA194_CLK_NVDISPLAY_DISP		85
#define TEGRA194_CLK_NVDISPLAY_P0		86
#define TEGRA194_CLK_NVDISPLAY_P1		87
#define TEGRA194_CLK_NVDISPLAY_P2		88
#define TEGRA194_CLK_NVENC			89
#define TEGRA194_CLK_NVJPG			90
#define TEGRA194_CLK_OSC			91
#define TEGRA194_CLK_AON_TOUCH			92
#define TEGRA194_CLK_PLLA			93
#define TEGRA194_CLK_PLLAON			94
#define TEGRA194_CLK_PLLD			95
#define TEGRA194_CLK_PLLD2			96
#define TEGRA194_CLK_PLLD3			97
#define TEGRA194_CLK_PLLDP			98
#define TEGRA194_CLK_PLLD4			99
#define TEGRA194_CLK_PLLE			100
#define TEGRA194_CLK_PLLP			101
#define TEGRA194_CLK_PLLP_OUT0			102
#define TEGRA194_CLK_UTMIPLL			103
#define TEGRA194_CLK_PLLA_OUT0			104
#define TEGRA194_CLK_PWM1			105
#define TEGRA194_CLK_PWM2			106
#define TEGRA194_CLK_PWM3			107
#define TEGRA194_CLK_PWM4			108
#define TEGRA194_CLK_PWM5			109
#define TEGRA194_CLK_PWM6			110
#define TEGRA194_CLK_PWM7			111
#define TEGRA194_CLK_PWM8			112
#define TEGRA194_CLK_RCE_CPU_NIC		113
#define TEGRA194_CLK_RCE_NIC			114
#define TEGRA194_CLK_SATA			115
#define TEGRA194_CLK_SATA_OOB			116
#define TEGRA194_CLK_AON_I2C_SLOW		117
#define TEGRA194_CLK_SCE_CPU_NIC		118
#define TEGRA194_CLK_SCE_NIC			119
#define TEGRA194_CLK_SDMMC1			120
#define TEGRA194_CLK_UPHY_PLL3			121
#define TEGRA194_CLK_SDMMC3			122
#define TEGRA194_CLK_SDMMC4			123
#define TEGRA194_CLK_SE				124
#define TEGRA194_CLK_SOR0_OUT			125
#define TEGRA194_CLK_SOR0_REF			126
#define TEGRA194_CLK_SOR0_PAD_CLKOUT		127
#define TEGRA194_CLK_SOR1_OUT			128
#define TEGRA194_CLK_SOR1_REF			129
#define TEGRA194_CLK_SOR1_PAD_CLKOUT		130
#define TEGRA194_CLK_SOR_SAFE			131
#define TEGRA194_CLK_IQC1_IN			132
#define TEGRA194_CLK_IQC2_IN			133
#define TEGRA194_CLK_DMIC5			134
#define TEGRA194_CLK_SPI1			135
#define TEGRA194_CLK_SPI2			136
#define TEGRA194_CLK_SPI3			137
#define TEGRA194_CLK_I2C_SLOW			138
#define TEGRA194_CLK_SYNC_DMIC1			139
#define TEGRA194_CLK_SYNC_DMIC2			140
#define TEGRA194_CLK_SYNC_DMIC3			141
#define TEGRA194_CLK_SYNC_DMIC4			142
#define TEGRA194_CLK_SYNC_DSPK1			143
#define TEGRA194_CLK_SYNC_DSPK2			144
#define TEGRA194_CLK_SYNC_I2S1			145
#define TEGRA194_CLK_SYNC_I2S2			146
#define TEGRA194_CLK_SYNC_I2S3			147
#define TEGRA194_CLK_SYNC_I2S4			148
#define TEGRA194_CLK_SYNC_I2S5			149
#define TEGRA194_CLK_SYNC_I2S6			150
#define TEGRA194_CLK_MPHY_FORCE_LS_MODE		151
#define TEGRA194_CLK_TACH			152
#define TEGRA194_CLK_TSEC			153
#define TEGRA194_CLK_TSECB			154
#define TEGRA194_CLK_UARTA			155
#define TEGRA194_CLK_UARTB			156
#define TEGRA194_CLK_UARTC			157
#define TEGRA194_CLK_UARTD			158
#define TEGRA194_CLK_UARTE			159
#define TEGRA194_CLK_UARTF			160
#define TEGRA194_CLK_UARTG			161
#define TEGRA194_CLK_UART_FST_MIPI_CAL		162
#define TEGRA194_CLK_UFSDEV_REF			163
#define TEGRA194_CLK_UFSHC			164
#define TEGRA194_CLK_USB2_TRK			165
#define TEGRA194_CLK_VI				166
#define TEGRA194_CLK_VIC			167
#define TEGRA194_CLK_PVA0_AXI			168
#define TEGRA194_CLK_PVA0_VPS0			169
#define TEGRA194_CLK_PVA0_VPS1			170
#define TEGRA194_CLK_PVA1_AXI			171
#define TEGRA194_CLK_PVA1_VPS0			172
#define TEGRA194_CLK_PVA1_VPS1			173
#define TEGRA194_CLK_DLA0_FALCON		174
#define TEGRA194_CLK_DLA0_CORE			175
#define TEGRA194_CLK_DLA1_FALCON		176
#define TEGRA194_CLK_DLA1_CORE			177
#define TEGRA194_CLK_SOR2_OUT			178
#define TEGRA194_CLK_SOR2_REF			179
#define TEGRA194_CLK_SOR2_PAD_CLKOUT		180
#define TEGRA194_CLK_SOR3_OUT			181
#define TEGRA194_CLK_SOR3_REF			182
#define TEGRA194_CLK_SOR3_PAD_CLKOUT		183
#define TEGRA194_CLK_NVDISPLAY_P3		184
#define TEGRA194_CLK_DPAUX2			185
#define TEGRA194_CLK_DPAUX3			186
#define TEGRA194_CLK_NVDEC1			187
#define TEGRA194_CLK_NVENC1			188
#define TEGRA194_CLK_SE_FREE			189
#define TEGRA194_CLK_UARTH			190
#define TEGRA194_CLK_FUSE_SERIAL		191
#define TEGRA194_CLK_QSPI0			192
#define TEGRA194_CLK_QSPI1			193
#define TEGRA194_CLK_QSPI0_PM			194
#define TEGRA194_CLK_QSPI1_PM			195
#define TEGRA194_CLK_VI_CONST			196
#define TEGRA194_CLK_NAFLL_BPMP			197
#define TEGRA194_CLK_NAFLL_SCE			198
#define TEGRA194_CLK_NAFLL_NVDEC		199
#define TEGRA194_CLK_NAFLL_NVJPG		200
#define TEGRA194_CLK_NAFLL_TSEC			201
#define TEGRA194_CLK_NAFLL_TSECB		202
#define TEGRA194_CLK_NAFLL_VI			203
#define TEGRA194_CLK_NAFLL_SE			204
#define TEGRA194_CLK_NAFLL_NVENC		205
#define TEGRA194_CLK_NAFLL_ISP			206
#define TEGRA194_CLK_NAFLL_VIC			207
#define TEGRA194_CLK_NAFLL_NVDISPLAYHUB		208
#define TEGRA194_CLK_NAFLL_AXICBB		209
#define TEGRA194_CLK_NAFLL_DLA			210
#define TEGRA194_CLK_NAFLL_PVA_CORE		211
#define TEGRA194_CLK_NAFLL_PVA_VPS		212
#define TEGRA194_CLK_NAFLL_CVNAS		213
#define TEGRA194_CLK_NAFLL_RCE			214
#define TEGRA194_CLK_NAFLL_NVENC1		215
#define TEGRA194_CLK_NAFLL_DLA_FALCON		216
#define TEGRA194_CLK_NAFLL_NVDEC1		217
#define TEGRA194_CLK_NAFLL_GPU			218
#define TEGRA194_CLK_SDMMC_LEGACY_TM		219
#define TEGRA194_CLK_PEX0_CORE_0		220
#define TEGRA194_CLK_PEX0_CORE_1		221
#define TEGRA194_CLK_PEX0_CORE_2		222
#define TEGRA194_CLK_PEX0_CORE_3		223
#define TEGRA194_CLK_PEX0_CORE_4		224
#define TEGRA194_CLK_PEX1_CORE_5		225
#define TEGRA194_CLK_PEX_REF1			226
#define TEGRA194_CLK_PEX_REF2			227
#define TEGRA194_CLK_CSI_A			229
#define TEGRA194_CLK_CSI_B			230
#define TEGRA194_CLK_CSI_C			231
#define TEGRA194_CLK_CSI_D			232
#define TEGRA194_CLK_CSI_E			233
#define TEGRA194_CLK_CSI_F			234
#define TEGRA194_CLK_CSI_G			235
#define TEGRA194_CLK_CSI_H			236
#define TEGRA194_CLK_PLLC4			237
#define TEGRA194_CLK_PLLC4_OUT			238
#define TEGRA194_CLK_PLLC4_OUT1			239
#define TEGRA194_CLK_PLLC4_OUT2			240
#define TEGRA194_CLK_PLLC4_MUXED		241
#define TEGRA194_CLK_PLLC4_VCO_DIV2		242
#define TEGRA194_CLK_CSI_A_PAD			244
#define TEGRA194_CLK_CSI_B_PAD			245
#define TEGRA194_CLK_CSI_C_PAD			246
#define TEGRA194_CLK_CSI_D_PAD			247
#define TEGRA194_CLK_CSI_E_PAD			248
#define TEGRA194_CLK_CSI_F_PAD			249
#define TEGRA194_CLK_CSI_G_PAD			250
#define TEGRA194_CLK_CSI_H_PAD			251
#define TEGRA194_CLK_PEX_SATA_USB_RX_BYP	254
#define TEGRA194_CLK_PEX_USB_PAD_PLL0_MGMT	255
#define TEGRA194_CLK_PEX_USB_PAD_PLL1_MGMT	256
#define TEGRA194_CLK_PEX_USB_PAD_PLL2_MGMT	257
#define TEGRA194_CLK_PEX_USB_PAD_PLL3_MGMT	258
#define TEGRA194_CLK_XUSB_CORE_DEV		265
#define TEGRA194_CLK_XUSB_CORE_MUX		266
#define TEGRA194_CLK_XUSB_CORE_HOST		267
#define TEGRA194_CLK_XUSB_CORE_SS		268
#define TEGRA194_CLK_XUSB_FALCON		269
#define TEGRA194_CLK_XUSB_FALCON_HOST		270
#define TEGRA194_CLK_XUSB_FALCON_SS		271
#define TEGRA194_CLK_XUSB_FS			272
#define TEGRA194_CLK_XUSB_FS_HOST		273
#define TEGRA194_CLK_XUSB_FS_DEV		274
#define TEGRA194_CLK_XUSB_SS			275
#define TEGRA194_CLK_XUSB_SS_DEV		276
#define TEGRA194_CLK_XUSB_SS_SUPERSPEED		277
#define TEGRA194_CLK_PLLDISPHUB			278
#define TEGRA194_CLK_PLLDISPHUB_DIV		279
#define TEGRA194_CLK_NAFLL_CLUSTER0		280
#define TEGRA194_CLK_NAFLL_CLUSTER1		281
#define TEGRA194_CLK_NAFLL_CLUSTER2		282
#define TEGRA194_CLK_NAFLL_CLUSTER3		283
#define TEGRA194_CLK_CAN1_CORE			284
#define TEGRA194_CLK_CAN2_CORE			285
#define TEGRA194_CLK_PLLA1_OUT1			286
#define TEGRA194_CLK_PLLREFE_VCOOUT		288
#define TEGRA194_CLK_CLK_32K			289
#define TEGRA194_CLK_SPDIFIN_SYNC_INPUT		290
#define TEGRA194_CLK_UTMIPLL_CLKOUT48		291
#define TEGRA194_CLK_UTMIPLL_CLKOUT480		292
#define TEGRA194_CLK_CVNAS			293
#define TEGRA194_CLK_PLLNVCSI			294
#define TEGRA194_CLK_PVA0_CPU_AXI		295
#define TEGRA194_CLK_PVA1_CPU_AXI		296
#define TEGRA194_CLK_PVA0_VPS			297
#define TEGRA194_CLK_PVA1_VPS			298
#define TEGRA194_CLK_DLA0_FALCON_MUX		299
#define TEGRA194_CLK_DLA1_FALCON_MUX		300
#define TEGRA194_CLK_DLA0_CORE_MUX		301
#define TEGRA194_CLK_DLA1_CORE_MUX		302
#define TEGRA194_CLK_UTMIPLL_HPS		304
#define TEGRA194_CLK_I2C5			305
#define TEGRA194_CLK_I2C10			306
#define TEGRA194_CLK_BPMP_CPU_NIC		307
#define TEGRA194_CLK_BPMP_APB			308
#define TEGRA194_CLK_TSC			309
#define TEGRA194_CLK_EMCSA			310
#define TEGRA194_CLK_EMCSB			311
#define TEGRA194_CLK_EMCSC			312
#define TEGRA194_CLK_EMCSD			313
#define TEGRA194_CLK_PLLC			314
#define TEGRA194_CLK_PLLC2			315
#define TEGRA194_CLK_PLLC3			316
#define TEGRA194_CLK_TSC_REF			317
#define TEGRA194_CLK_FUSE_BURN			318
#define TEGRA194_CLK_PEX0_CORE_0M		319
#define TEGRA194_CLK_PEX0_CORE_1M		320
#define TEGRA194_CLK_PEX0_CORE_2M		321
#define TEGRA194_CLK_PEX0_CORE_3M		322
#define TEGRA194_CLK_PEX0_CORE_4M		323
#define TEGRA194_CLK_PEX1_CORE_5M		324
#define TEGRA194_CLK_PLLE_HPS			326

#endif
