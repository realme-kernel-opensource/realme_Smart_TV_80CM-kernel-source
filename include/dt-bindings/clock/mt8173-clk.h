/*
 * Copyright (c) 2014 MediaTek Inc.
 * Author: James Liao <jamesjj.liao@mediatek.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _DT_BINDINGS_CLK_MT8173_H
#define _DT_BINDINGS_CLK_MT8173_H

/* TOPCKGEN */

#define CLK_TOP_CLKPH_MCK_O		1
#define CLK_TOP_USB_SYSPLL_125M		3
#define CLK_TOP_HDMITX_DIG_CTS		4
#define CLK_TOP_ARMCA7PLL_754M		5
#define CLK_TOP_ARMCA7PLL_502M		6
#define CLK_TOP_MAIN_H546M		7
#define CLK_TOP_MAIN_H364M		8
#define CLK_TOP_MAIN_H218P4M		9
#define CLK_TOP_MAIN_H156M		10
#define CLK_TOP_TVDPLL_445P5M		11
#define CLK_TOP_TVDPLL_594M		12
#define CLK_TOP_UNIV_624M		13
#define CLK_TOP_UNIV_416M		14
#define CLK_TOP_UNIV_249P6M		15
#define CLK_TOP_UNIV_178P3M		16
#define CLK_TOP_UNIV_48M		17
#define CLK_TOP_CLKRTC_EXT		18
#define CLK_TOP_CLKRTC_INT		19
#define CLK_TOP_FPC			20
#define CLK_TOP_HDMITXPLL_D2		21
#define CLK_TOP_HDMITXPLL_D3		22
#define CLK_TOP_ARMCA7PLL_D2		23
#define CLK_TOP_ARMCA7PLL_D3		24
#define CLK_TOP_APLL1			25
#define CLK_TOP_APLL2			26
#define CLK_TOP_DMPLL			27
#define CLK_TOP_DMPLL_D2		28
#define CLK_TOP_DMPLL_D4		29
#define CLK_TOP_DMPLL_D8		30
#define CLK_TOP_DMPLL_D16		31
#define CLK_TOP_LVDSPLL_D2		32
#define CLK_TOP_LVDSPLL_D4		33
#define CLK_TOP_LVDSPLL_D8		34
#define CLK_TOP_MMPLL			35
#define CLK_TOP_MMPLL_D2		36
#define CLK_TOP_MSDCPLL			37
#define CLK_TOP_MSDCPLL_D2		38
#define CLK_TOP_MSDCPLL_D4		39
#define CLK_TOP_MSDCPLL2		40
#define CLK_TOP_MSDCPLL2_D2		41
#define CLK_TOP_MSDCPLL2_D4		42
#define CLK_TOP_SYSPLL_D2		43
#define CLK_TOP_SYSPLL1_D2		44
#define CLK_TOP_SYSPLL1_D4		45
#define CLK_TOP_SYSPLL1_D8		46
#define CLK_TOP_SYSPLL1_D16		47
#define CLK_TOP_SYSPLL_D3		48
#define CLK_TOP_SYSPLL2_D2		49
#define CLK_TOP_SYSPLL2_D4		50
#define CLK_TOP_SYSPLL_D5		51
#define CLK_TOP_SYSPLL3_D2		52
#define CLK_TOP_SYSPLL3_D4		53
#define CLK_TOP_SYSPLL_D7		54
#define CLK_TOP_SYSPLL4_D2		55
#define CLK_TOP_SYSPLL4_D4		56
#define CLK_TOP_TVDPLL			57
#define CLK_TOP_TVDPLL_D2		58
#define CLK_TOP_TVDPLL_D4		59
#define CLK_TOP_TVDPLL_D8		60
#define CLK_TOP_TVDPLL_D16		61
#define CLK_TOP_UNIVPLL_D2		62
#define CLK_TOP_UNIVPLL1_D2		63
#define CLK_TOP_UNIVPLL1_D4		64
#define CLK_TOP_UNIVPLL1_D8		65
#define CLK_TOP_UNIVPLL_D3		66
#define CLK_TOP_UNIVPLL2_D2		67
#define CLK_TOP_UNIVPLL2_D4		68
#define CLK_TOP_UNIVPLL2_D8		69
#define CLK_TOP_UNIVPLL_D5		70
#define CLK_TOP_UNIVPLL3_D2		71
#define CLK_TOP_UNIVPLL3_D4		72
#define CLK_TOP_UNIVPLL3_D8		73
#define CLK_TOP_UNIVPLL_D7		74
#define CLK_TOP_UNIVPLL_D26		75
#define CLK_TOP_UNIVPLL_D52		76
#define CLK_TOP_VCODECPLL		77
#define CLK_TOP_VCODECPLL_370P5		78
#define CLK_TOP_VENCPLL			79
#define CLK_TOP_VENCPLL_D2		80
#define CLK_TOP_VENCPLL_D4		81
#define CLK_TOP_AXI_SEL			82
#define CLK_TOP_MEM_SEL			83
#define CLK_TOP_DDRPHYCFG_SEL		84
#define CLK_TOP_MM_SEL			85
#define CLK_TOP_PWM_SEL			86
#define CLK_TOP_VDEC_SEL		87
#define CLK_TOP_VENC_SEL		88
#define CLK_TOP_MFG_SEL			89
#define CLK_TOP_CAMTG_SEL		90
#define CLK_TOP_UART_SEL		91
#define CLK_TOP_SPI_SEL			92
#define CLK_TOP_USB20_SEL		93
#define CLK_TOP_USB30_SEL		94
#define CLK_TOP_MSDC50_0_H_SEL		95
#define CLK_TOP_MSDC50_0_SEL		96
#define CLK_TOP_MSDC30_1_SEL		97
#define CLK_TOP_MSDC30_2_SEL		98
#define CLK_TOP_MSDC30_3_SEL		99
#define CLK_TOP_AUDIO_SEL		100
#define CLK_TOP_AUD_INTBUS_SEL		101
#define CLK_TOP_PMICSPI_SEL		102
#define CLK_TOP_SCP_SEL			103
#define CLK_TOP_ATB_SEL			104
#define CLK_TOP_VENC_LT_SEL		105
#define CLK_TOP_DPI0_SEL		106
#define CLK_TOP_IRDA_SEL		107
#define CLK_TOP_CCI400_SEL		108
#define CLK_TOP_AUD_1_SEL		109
#define CLK_TOP_AUD_2_SEL		110
#define CLK_TOP_MEM_MFG_IN_SEL		111
#define CLK_TOP_AXI_MFG_IN_SEL		112
#define CLK_TOP_SCAM_SEL		113
#define CLK_TOP_SPINFI_IFR_SEL		114
#define CLK_TOP_HDMI_SEL		115
#define CLK_TOP_DPILVDS_SEL		116
#define CLK_TOP_MSDC50_2_H_SEL		117
#define CLK_TOP_HDCP_SEL		118
#define CLK_TOP_HDCP_24M_SEL		119
#define CLK_TOP_RTC_SEL			120
#define CLK_TOP_APLL1_DIV0		121
#define CLK_TOP_APLL1_DIV1		122
#define CLK_TOP_APLL1_DIV2		123
#define CLK_TOP_APLL1_DIV3		124
#define CLK_TOP_APLL1_DIV4		125
#define CLK_TOP_APLL1_DIV5		126
#define CLK_TOP_APLL2_DIV0		127
#define CLK_TOP_APLL2_DIV1		128
#define CLK_TOP_APLL2_DIV2		129
#define CLK_TOP_APLL2_DIV3		130
#define CLK_TOP_APLL2_DIV4		131
#define CLK_TOP_APLL2_DIV5		132
#define CLK_TOP_I2S0_M_SEL		133
#define CLK_TOP_I2S1_M_SEL		134
#define CLK_TOP_I2S2_M_SEL		135
#define CLK_TOP_I2S3_M_SEL		136
#define CLK_TOP_I2S3_B_SEL		137
#define CLK_TOP_DSI0_DIG		138
#define CLK_TOP_DSI1_DIG		139
#define CLK_TOP_LVDS_PXL		140
#define CLK_TOP_LVDS_CTS		141
#define CLK_TOP_NR_CLK			142

/* APMIXED_SYS */

#define CLK_APMIXED_ARMCA15PLL		1
#define CLK_APMIXED_ARMCA7PLL		2
#define CLK_APMIXED_MAINPLL		3
#define CLK_APMIXED_UNIVPLL		4
#define CLK_APMIXED_MMPLL		5
#define CLK_APMIXED_MSDCPLL		6
#define CLK_APMIXED_VENCPLL		7
#define CLK_APMIXED_TVDPLL		8
#define CLK_APMIXED_MPLL		9
#define CLK_APMIXED_VCODECPLL		10
#define CLK_APMIXED_APLL1		11
#define CLK_APMIXED_APLL2		12
#define CLK_APMIXED_LVDSPLL		13
#define CLK_APMIXED_MSDCPLL2		14
#define CLK_APMIXED_REF2USB_TX		15
#define CLK_APMIXED_HDMI_REF		16
#define CLK_APMIXED_NR_CLK		17

/* INFRA_SYS */

#define CLK_INFRA_DBGCLK		1
#define CLK_INFRA_SMI			2
#define CLK_INFRA_AUDIO			3
#define CLK_INFRA_GCE			4
#define CLK_INFRA_L2C_SRAM		5
#define CLK_INFRA_M4U			6
#define CLK_INFRA_CPUM			7
#define CLK_INFRA_KP			8
#define CLK_INFRA_CEC			9
#define CLK_INFRA_PMICSPI		10
#define CLK_INFRA_PMICWRAP		11
#define CLK_INFRA_CLK_13M		12
#define CLK_INFRA_CA53SEL               13
#define CLK_INFRA_CA57SEL               14
#define CLK_INFRA_NR_CLK                15

/* PERI_SYS */

#define CLK_PERI_NFI			1
#define CLK_PERI_THERM			2
#define CLK_PERI_PWM1			3
#define CLK_PERI_PWM2			4
#define CLK_PERI_PWM3			5
#define CLK_PERI_PWM4			6
#define CLK_PERI_PWM5			7
#define CLK_PERI_PWM6			8
#define CLK_PERI_PWM7			9
#define CLK_PERI_PWM			10
#define CLK_PERI_USB0			11
#define CLK_PERI_USB1			12
#define CLK_PERI_AP_DMA			13
#define CLK_PERI_MSDC30_0		14
#define CLK_PERI_MSDC30_1		15
#define CLK_PERI_MSDC30_2		16
#define CLK_PERI_MSDC30_3		17
#define CLK_PERI_NLI_ARB		18
#define CLK_PERI_IRDA			19
#define CLK_PERI_UART0			20
#define CLK_PERI_UART1			21
#define CLK_PERI_UART2			22
#define CLK_PERI_UART3			23
#define CLK_PERI_I2C0			24
#define CLK_PERI_I2C1			25
#define CLK_PERI_I2C2			26
#define CLK_PERI_I2C3			27
#define CLK_PERI_I2C4			28
#define CLK_PERI_AUXADC			29
#define CLK_PERI_SPI0			30
#define CLK_PERI_I2C5			31
#define CLK_PERI_NFIECC			32
#define CLK_PERI_SPI			33
#define CLK_PERI_IRRX			34
#define CLK_PERI_I2C6			35
#define CLK_PERI_UART0_SEL		36
#define CLK_PERI_UART1_SEL		37
#define CLK_PERI_UART2_SEL		38
#define CLK_PERI_UART3_SEL		39
#define CLK_PERI_NR_CLK			40

/* IMG_SYS */

#define CLK_IMG_LARB2_SMI		1
#define CLK_IMG_CAM_SMI			2
#define CLK_IMG_CAM_CAM			3
#define CLK_IMG_SEN_TG			4
#define CLK_IMG_SEN_CAM			5
#define CLK_IMG_CAM_SV			6
#define CLK_IMG_FD			7
#define CLK_IMG_NR_CLK			8

/* MM_SYS */

#define CLK_MM_SMI_COMMON		1
#define CLK_MM_SMI_LARB0		2
#define CLK_MM_CAM_MDP			3
#define CLK_MM_MDP_RDMA0		4
#define CLK_MM_MDP_RDMA1		5
#define CLK_MM_MDP_RSZ0			6
#define CLK_MM_MDP_RSZ1			7
#define CLK_MM_MDP_RSZ2			8
#define CLK_MM_MDP_TDSHP0		9
#define CLK_MM_MDP_TDSHP1		10
#define CLK_MM_MDP_WDMA			11
#define CLK_MM_MDP_WROT0		12
#define CLK_MM_MDP_WROT1		13
#define CLK_MM_FAKE_ENG			14
#define CLK_MM_MUTEX_32K		15
#define CLK_MM_DISP_OVL0		16
#define CLK_MM_DISP_OVL1		17
#define CLK_MM_DISP_RDMA0		18
#define CLK_MM_DISP_RDMA1		19
#define CLK_MM_DISP_RDMA2		20
#define CLK_MM_DISP_WDMA0		21
#define CLK_MM_DISP_WDMA1		22
#define CLK_MM_DISP_COLOR0		23
#define CLK_MM_DISP_COLOR1		24
#define CLK_MM_DISP_AAL			25
#define CLK_MM_DISP_GAMMA		26
#define CLK_MM_DISP_UFOE		27
#define CLK_MM_DISP_SPLIT0		28
#define CLK_MM_DISP_SPLIT1		29
#define CLK_MM_DISP_MERGE		30
#define CLK_MM_DISP_OD			31
#define CLK_MM_DISP_PWM0MM		32
#define CLK_MM_DISP_PWM026M		33
#define CLK_MM_DISP_PWM1MM		34
#define CLK_MM_DISP_PWM126M		35
#define CLK_MM_DSI0_ENGINE		36
#define CLK_MM_DSI0_DIGITAL		37
#define CLK_MM_DSI1_ENGINE		38
#define CLK_MM_DSI1_DIGITAL		39
#define CLK_MM_DPI_PIXEL		40
#define CLK_MM_DPI_ENGINE		41
#define CLK_MM_DPI1_PIXEL		42
#define CLK_MM_DPI1_ENGINE		43
#define CLK_MM_HDMI_PIXEL		44
#define CLK_MM_HDMI_PLLCK		45
#define CLK_MM_HDMI_AUDIO		46
#define CLK_MM_HDMI_SPDIF		47
#define CLK_MM_LVDS_PIXEL		48
#define CLK_MM_LVDS_CTS			49
#define CLK_MM_SMI_LARB4		50
#define CLK_MM_HDMI_HDCP		51
#define CLK_MM_HDMI_HDCP24M		52
#define CLK_MM_NR_CLK			53

/* VDEC_SYS */

#define CLK_VDEC_CKEN			1
#define CLK_VDEC_LARB_CKEN		2
#define CLK_VDEC_NR_CLK			3

/* VENC_SYS */

#define CLK_VENC_CKE0			1
#define CLK_VENC_CKE1			2
#define CLK_VENC_CKE2			3
#define CLK_VENC_CKE3			4
#define CLK_VENC_NR_CLK			5

/* VENCLT_SYS */

#define CLK_VENCLT_CKE0			1
#define CLK_VENCLT_CKE1			2
#define CLK_VENCLT_NR_CLK		3

#endif /* _DT_BINDINGS_CLK_MT8173_H */
