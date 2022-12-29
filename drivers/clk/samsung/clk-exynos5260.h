/*
 * Copyright (c) 2014 Samsung Electronics Co., Ltd.
 * Author: Rahul Sharma <rahul.sharma@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Common Clock Framework support for Exynos5260 SoC.
 */

#ifndef __CLK_EXYNOS5260_H
#define __CLK_EXYNOS5260_H

/*
*Registers for CMU_AUD
*/
#define MUX_SEL_AUD				0x0200
#define MUX_ENABLE_AUD				0x0300
#define MUX_STAT_AUD				0x0400
#define MUX_IGNORE_AUD				0x0500
#define DIV_AUD0				0x0600
#define DIV_AUD1				0x0604
#define DIV_STAT_AUD0				0x0700
#define DIV_STAT_AUD1				0x0704
#define EN_ACLK_AUD				0x0800
#define EN_PCLK_AUD				0x0900
#define EN_SCLK_AUD				0x0a00
#define EN_IP_AUD				0x0b00

/*
*Registers for CMU_DISP
*/
#define MUX_SEL_DISP0				0x0200
#define MUX_SEL_DISP1				0x0204
#define MUX_SEL_DISP2				0x0208
#define MUX_SEL_DISP3				0x020C
#define MUX_SEL_DISP4				0x0210
#define MUX_ENABLE_DISP0			0x0300
#define MUX_ENABLE_DISP1			0x0304
#define MUX_ENABLE_DISP2			0x0308
#define MUX_ENABLE_DISP3			0x030c
#define MUX_ENABLE_DISP4			0x0310
#define MUX_STAT_DISP0				0x0400
#define MUX_STAT_DISP1				0x0404
#define MUX_STAT_DISP2				0x0408
#define MUX_STAT_DISP3				0x040c
#define MUX_STAT_DISP4				0x0410
#define MUX_IGNORE_DISP0			0x0500
#define MUX_IGNORE_DISP1			0x0504
#define MUX_IGNORE_DISP2			0x0508
#define MUX_IGNORE_DISP3			0x050c
#define MUX_IGNORE_DISP4			0x0510
#define DIV_DISP				0x0600
#define DIV_STAT_DISP				0x0700
#define EN_ACLK_DISP				0x0800
#define EN_PCLK_DISP				0x0900
#define EN_SCLK_DISP0				0x0a00
#define EN_SCLK_DISP1				0x0a04
#define EN_IP_DISP				0x0b00
#define EN_IP_DISP_BUS				0x0b04


/*
*Registers for CMU_EGL
*/
#define EGL_PLL_LOCK				0x0000
#define EGL_DPLL_LOCK				0x0004
#define EGL_PLL_CON0				0x0100
#define EGL_PLL_CON1				0x0104
#define EGL_PLL_FREQ_DET			0x010c
#define EGL_DPLL_CON0				0x0110
#define EGL_DPLL_CON1				0x0114
#define EGL_DPLL_FREQ_DET			0x011c
#define MUX_SEL_EGL				0x0200
#define MUX_ENABLE_EGL				0x0300
#define MUX_STAT_EGL				0x0400
#define DIV_EGL					0x0600
#define DIV_EGL_PLL_FDET			0x0604
#define DIV_STAT_EGL				0x0700
#define DIV_STAT_EGL_PLL_FDET			0x0704
#define EN_ACLK_EGL				0x0800
#define EN_PCLK_EGL				0x0900
#define EN_SCLK_EGL				0x0a00
#define EN_IP_EGL				0x0b00
#define CLKOUT_CMU_EGL				0x0c00
#define CLKOUT_CMU_EGL_DIV_STAT			0x0c04
#define ARMCLK_STOPCTRL				0x1000
#define EAGLE_EMA_CTRL				0x1008
#define EAGLE_EMA_STATUS			0x100c
#define PWR_CTRL				0x1020
#define PWR_CTRL2				0x1024
#define CLKSTOP_CTRL				0x1028
#define INTR_SPREAD_EN				0x1080
#define INTR_SPREAD_USE_STANDBYWFI		0x1084
#define INTR_SPREAD_BLOCKING_DURATION		0x1088
#define CMU_EGL_SPARE0				0x2000
#define CMU_EGL_SPARE1				0x2004
#define CMU_EGL_SPARE2				0x2008
#define CMU_EGL_SPARE3				0x200c
#define CMU_EGL_SPARE4				0x2010

/*
*Registers for CMU_FSYS
*/

#define MUX_SEL_FSYS0				0x0200
#define MUX_SEL_FSYS1				0x0204
#define MUX_ENABLE_FSYS0			0x0300
#define MUX_ENABLE_FSYS1			0x0304
#define MUX_STAT_FSYS0				0x0400
#define MUX_STAT_FSYS1				0x0404
#define MUX_IGNORE_FSYS0			0x0500
#define MUX_IGNORE_FSYS1			0x0504
#define EN_ACLK_FSYS				0x0800
#define EN_ACLK_FSYS_SECURE_RTIC		0x0804
#define EN_ACLK_FSYS_SECURE_SMMU_RTIC		0x0808
#define EN_PCLK_FSYS				0x0900
#define EN_SCLK_FSYS				0x0a00
#define EN_IP_FSYS				0x0b00
#define EN_IP_FSYS_SECURE_RTIC			0x0b04
#define EN_IP_FSYS_SECURE_SMMU_RTIC		0x0b08

/*
*Registers for CMU_G2D
*/

#define MUX_SEL_G2D				0x0200
#define MUX_ENABLE_G2D				0x0300
#define MUX_STAT_G2D				0x0400
#define DIV_G2D					0x0600
#define DIV_STAT_G2D				0x0700
#define EN_ACLK_G2D				0x0800
#define EN_ACLK_G2D_SECURE_SSS			0x0804
#define EN_ACLK_G2D_SECURE_SLIM_SSS		0x0808
#define EN_ACLK_G2D_SECURE_SMMU_SLIM_SSS	0x080c
#define EN_ACLK_G2D_SECURE_SMMU_SSS		0x0810
#define EN_ACLK_G2D_SECURE_SMMU_MDMA		0x0814
#define EN_ACLK_G2D_SECURE_SMMU_G2D		0x0818
#define EN_PCLK_G2D				0x0900
#define EN_PCLK_G2D_SECURE_SMMU_SLIM_SSS	0x0904
#define EN_PCLK_G2D_SECURE_SMMU_SSS		0x0908
#define EN_PCLK_G2D_SECURE_SMMU_MDMA		0x090c
#define EN_PCLK_G2D_SECURE_SMMU_G2D		0x0910
#define EN_IP_G2D				0x0b00
#define EN_IP_G2D_SECURE_SSS			0x0b04
#define EN_IP_G2D_SECURE_SLIM_SSS		0x0b08
#define EN_IP_G2D_SECURE_SMMU_SLIM_SSS		0x0b0c
#define EN_IP_G2D_SECURE_SMMU_SSS		0x0b10
#define EN_IP_G2D_SECURE_SMMU_MDMA		0x0b14
#define EN_IP_G2D_SECURE_SMMU_G2D		0x0b18

/*
*Registers for CMU_G3D
*/

#define G3D_PLL_LOCK				0x0000
#define G3D_PLL_CON0				0x0100
#define G3D_PLL_CON1				0x0104
#define G3D_PLL_FDET				0x010c
#define MUX_SEL_G3D				0x0200
#define MUX_EN_G3D				0x0300
#define MUX_STAT_G3D				0x0400
#define MUX_IGNORE_G3D				0x0500
#define DIV_G3D					0x0600
#define DIV_G3D_PLL_FDET			0x0604
#define DIV_STAT_G3D				0x0700
#define DIV_STAT_G3D_PLL_FDET			0x0704
#define EN_ACLK_G3D				0x0800
#define EN_PCLK_G3D				0x0900
#define EN_SCLK_G3D				0x0a00
#define EN_IP_G3D				0x0b00
#define CLKOUT_CMU_G3D				0x0c00
#define CLKOUT_CMU_G3D_DIV_STAT			0x0c04
#define G3DCLK_STOPCTRL				0x1000
#define G3D_EMA_CTRL				0x1008
#define G3D_EMA_STATUS				0x100c

/*
*Registers for CMU_GSCL
*/

#define MUX_SEL_GSCL				0x0200
#define MUX_EN_GSCL				0x0300
#define MUX_STAT_GSCL				0x0400
#define MUX_IGNORE_GSCL				0x0500
#define DIV_GSCL				0x0600
#define DIV_STAT_GSCL				0x0700
#define EN_ACLK_GSCL				0x0800
#define EN_ACLK_GSCL_FIMC			0x0804
#define EN_ACLK_GSCL_SECURE_SMMU_GSCL0		0x0808
#define EN_ACLK_GSCL_SECURE_SMMU_GSCL1		0x080c
#define EN_ACLK_GSCL_SECURE_SMMU_MSCL0		0x0810
#define EN_ACLK_GSCL_SECURE_SMMU_MSCL1		0x0814
#define EN_PCLK_GSCL				0x0900
#define EN_PCLK_GSCL_FIMC			0x0904
#define EN_PCLK_GSCL_SECURE_SMMU_GSCL0		0x0908
#define EN_PCLK_GSCL_SECURE_SMMU_GSCL1		0x090c
#define EN_PCLK_GSCL_SECURE_SMMU_MSCL0		0x0910
#define EN_PCLK_GSCL_SECURE_SMMU_MSCL1		0x0914
#define EN_SCLK_GSCL				0x0a00
#define EN_SCLK_GSCL_FIMC			0x0a04
#define EN_IP_GSCL				0x0b00
#define EN_IP_GSCL_FIMC				0x0b04
#define EN_IP_GSCL_SECURE_SMMU_GSCL0		0x0b08
#define EN_IP_GSCL_SECURE_SMMU_GSCL1		0x0b0c
#define EN_IP_GSCL_SECURE_SMMU_MSCL0		0x0b10
#define EN_IP_GSCL_SECURE_SMMU_MSCL1		0x0b14

/*
*Registers for CMU_ISP
*/
#define MUX_SEL_ISP0				0x0200
#define MUX_SEL_ISP1				0x0204
#define MUX_ENABLE_ISP0				0x0300
#define MUX_ENABLE_ISP1				0x0304
#define MUX_STAT_ISP0				0x0400
#define MUX_STAT_ISP1				0x0404
#define MUX_IGNORE_ISP0				0x0500
#define MUX_IGNORE_ISP1				0x0504
#define DIV_ISP					0x0600
#define DIV_STAT_ISP				0x0700
#define EN_ACLK_ISP0				0x0800
#define EN_ACLK_ISP1				0x0804
#define EN_PCLK_ISP0				0x0900
#define EN_PCLK_ISP1				0x0904
#define EN_SCLK_ISP				0x0a00
#define EN_IP_ISP0				0x0b00
#define EN_IP_ISP1				0x0b04

/*
*Registers for CMU_KFC
*/
#define KFC_PLL_LOCK				0x0000
#define KFC_PLL_CON0				0x0100
#define KFC_PLL_CON1				0x0104
#define KFC_PLL_FDET				0x010c
#define MUX_SEL_KFC0				0x0200
#define MUX_SEL_KFC2				0x0208
#define MUX_ENABLE_KFC0				0x0300
#define MUX_ENABLE_KFC2				0x0308
#define MUX_STAT_KFC0				0x0400
#define MUX_STAT_KFC2				0x0408
#define DIV_KFC					0x0600
#define DIV_KFC_PLL_FDET			0x0604
#define DIV_STAT_KFC				0x0700
#define DIV_STAT_KFC_PLL_FDET			0x0704
#define EN_ACLK_KFC				0x0800
#define EN_PCLK_KFC				0x0900
#define EN_SCLK_KFC				0x0a00
#define EN_IP_KFC				0x0b00
#define CLKOUT_CMU_KFC				0x0c00
#define CLKOUT_CMU_KFC_DIV_STAT			0x0c04
#define ARMCLK_STOPCTRL_KFC			0x1000
#define ARM_EMA_CTRL				0x1008
#define ARM_EMA_STATUS				0x100c
#define PWR_CTRL_KFC				0x1020
#define PWR_CTRL2_KFC				0x1024
#define CLKSTOP_CTRL_KFC			0x1028
#define INTR_SPREAD_ENABLE_KFC			0x1080
#define INTR_SPREAD_USE_STANDBYWFI_KFC		0x1084
#define INTR_SPREAD_BLOCKING_DURATION_KFC	0x1088
#define CMU_KFC_SPARE0				0x2000
#define CMU_KFC_SPARE1				0x2004
#define CMU_KFC_SPARE2				0x2008
#define CMU_KFC_SPARE3				0x200c
#define CMU_KFC_SPARE4				0x2010

/*
*Registers for CMU_MFC
*/
#define MUX_SEL_MFC				0x0200
#define MUX_ENABLE_MFC				0x0300
#define MUX_STAT_MFC				0x0400
#define DIV_MFC					0x0600
#define DIV_STAT_MFC				0x0700
#define EN_ACLK_MFC				0x0800
#define EN_ACLK_SECURE_SMMU2_MFC		0x0804
#define EN_PCLK_MFC				0x0900
#define EN_PCLK_SECURE_SMMU2_MFC		0x0904
#define EN_IP_MFC				0x0b00
#define EN_IP_MFC_SECURE_SMMU2_MFC		0x0b04

/*
*Registers for CMU_MIF
*/
#define MEM_PLL_LOCK				0x0000
#define BUS_PLL_LOCK				0x0004
#define MEDIA_PLL_LOCK				0x0008
#define MEM_PLL_CON0				0x0100
#define MEM_PLL_CON1				0x0104
#define MEM_PLL_FDET				0x010c
#define BUS_PLL_CON0				0x0110
#define BUS_PLL_CON1				0x0114
#define BUS_PLL_FDET				0x011c
#define MEDIA_PLL_CON0				0x0120
#define MEDIA_PLL_CON1				0x0124
#define MEDIA_PLL_FDET				0x012c
#define MUX_SEL_MIF				0x0200
#define MUX_ENABLE_MIF				0x0300
#define MUX_STAT_MIF				0x0400
#define MUX_IGNORE_MIF				0x0500
#define DIV_MIF					0x0600
#define DIV_MIF_PLL_FDET			0x0604
#define DIV_STAT_MIF				0x0700
#define DIV_STAT_MIF_PLL_FDET			0x0704
#define EN_ACLK_MIF				0x0800
#define EN_ACLK_MIF_SECURE_DREX1_TZ		0x0804
#define EN_ACLK_MIF_SECURE_DREX0_TZ		0x0808
#define EN_ACLK_MIF_SECURE_INTMEM		0x080c
#define EN_PCLK_MIF				0x0900
#define EN_PCLK_MIF_SECURE_MONOCNT		0x0904
#define EN_PCLK_MIF_SECURE_RTC_APBIF		0x0908
#define EN_PCLK_MIF_SECURE_DREX1_TZ		0x090c
#define EN_PCLK_MIF_SECURE_DREX0_TZ		0x0910
#define EN_SCLK_MIF				0x0a00
#define EN_IP_MIF				0x0b00
#define EN_IP_MIF_SECURE_MONOCNT		0x0b04
#define EN_IP_MIF_SECURE_RTC_APBIF		0x0b08
#define EN_IP_MIF_SECURE_DREX1_TZ		0x0b0c
#define EN_IP_MIF_SECURE_DREX0_TZ		0x0b10
#define EN_IP_MIF_SECURE_INTEMEM		0x0b14
#define CLKOUT_CMU_MIF_DIV_STAT			0x0c04
#define DREX_FREQ_CTRL				0x1000
#define PAUSE					0x1004
#define DDRPHY_LOCK_CTRL			0x1008
#define CLKOUT_CMU_MIF				0xcb00

/*
*Registers for CMU_PERI
*/
#define MUX_SEL_PERI				0x0200
#define MUX_SEL_PERI1				0x0204
#define MUX_ENABLE_PERI				0x0300
#define MUX_ENABLE_PERI1			0x0304
#define MUX_STAT_PERI				0x0400
#define MUX_STAT_PERI1				0x0404
#define MUX_IGNORE_PERI				0x0500
#define MUX_IGNORE_PERI1			0x0504
#define DIV_PERI				0x0600
#define DIV_STAT_PERI				0x0700
#define EN_PCLK_PERI0				0x0800
#define EN_PCLK_PERI1				0x0804
#define EN_PCLK_PERI2				0x0808
#define EN_PCLK_PERI3				0x080c
#define EN_PCLK_PERI_SECURE_CHIPID		0x0810
#define EN_PCLK_PERI_SECURE_PROVKEY0		0x0814
#define EN_PCLK_PERI_SECURE_PROVKEY1		0x0818
#define EN_PCLK_PERI_SECURE_SECKEY		0x081c
#define EN_PCLK_PERI_SECURE_ANTIRBKCNT		0x0820
#define EN_PCLK_PERI_SECURE_TOP_RTC		0x0824
#define EN_PCLK_PERI_SECURE_TZPC		0x0828
#define EN_SCLK_PERI				0x0a00
#define EN_SCLK_PERI_SECURE_TOP_RTC		0x0a04
#define EN_IP_PERI0				0x0b00
#define EN_IP_PERI1				0x0b04
#define EN_IP_PERI2				0x0b08
#define EN_IP_PERI_SECURE_CHIPID		0x0b0c
#define EN_IP_PERI_SECURE_PROVKEY0		0x0b10
#define EN_IP_PERI_SECURE_PROVKEY1		0x0b14
#define EN_IP_PERI_SECURE_SECKEY		0x0b18
#define EN_IP_PERI_SECURE_ANTIRBKCNT		0x0b1c
#define EN_IP_PERI_SECURE_TOP_RTC		0x0b20
#define EN_IP_PERI_SECURE_TZPC			0x0b24

/*
*Registers for CMU_TOP
*/
#define DISP_PLL_LOCK				0x0000
#define AUD_PLL_LOCK				0x0004
#define DISP_PLL_CON0				0x0100
#define DISP_PLL_CON1				0x0104
#define DISP_PLL_FDET				0x0108
#define AUD_PLL_CON0				0x0110
#define AUD_PLL_CON1				0x0114
#define AUD_PLL_CON2				0x0118
#define AUD_PLL_FDET				0x011c
#define MUX_SEL_TOP_PLL0			0x0200
#define MUX_SEL_TOP_MFC				0x0204
#define MUX_SEL_TOP_G2D				0x0208
#define MUX_SEL_TOP_GSCL			0x020c
#define MUX_SEL_TOP_ISP10			0x0214
#define MUX_SEL_TOP_ISP11			0x0218
#define MUX_SEL_TOP_DISP0			0x021c
#define MUX_SEL_TOP_DISP1			0x0220
#define MUX_SEL_TOP_BUS				0x0224
#define MUX_SEL_TOP_PERI0			0x0228
#define MUX_SEL_TOP_PERI1			0x022c
#define MUX_SEL_TOP_FSYS			0x0230
#define MUX_ENABLE_TOP_PLL0			0x0300
#define MUX_ENABLE_TOP_MFC			0x0304
#define MUX_ENABLE_TOP_G2D			0x0308
#define MUX_ENABLE_TOP_GSCL			0x030c
#define MUX_ENABLE_TOP_ISP10			0x0314
#define MUX_ENABLE_TOP_ISP11			0x0318
#define MUX_ENABLE_TOP_DISP0			0x031c
#define MUX_ENABLE_TOP_DISP1			0x0320
#define MUX_ENABLE_TOP_BUS			0x0324
#define MUX_ENABLE_TOP_PERI0			0x0328
#define MUX_ENABLE_TOP_PERI1			0x032c
#define MUX_ENABLE_TOP_FSYS			0x0330
#define MUX_STAT_TOP_PLL0			0x0400
#define MUX_STAT_TOP_MFC			0x0404
#define MUX_STAT_TOP_G2D			0x0408
#define MUX_STAT_TOP_GSCL			0x040c
#define MUX_STAT_TOP_ISP10			0x0414
#define MUX_STAT_TOP_ISP11			0x0418
#define MUX_STAT_TOP_DISP0			0x041c
#define MUX_STAT_TOP_DISP1			0x0420
#define MUX_STAT_TOP_BUS			0x0424
#define MUX_STAT_TOP_PERI0			0x0428
#define MUX_STAT_TOP_PERI1			0x042c
#define MUX_STAT_TOP_FSYS			0x0430
#define MUX_IGNORE_TOP_PLL0			0x0500
#define MUX_IGNORE_TOP_MFC			0x0504
#define MUX_IGNORE_TOP_G2D			0x0508
#define MUX_IGNORE_TOP_GSCL			0x050c
#define MUX_IGNORE_TOP_ISP10			0x0514
#define MUX_IGNORE_TOP_ISP11			0x0518
#define MUX_IGNORE_TOP_DISP0			0x051c
#define MUX_IGNORE_TOP_DISP1			0x0520
#define MUX_IGNORE_TOP_BUS			0x0524
#define MUX_IGNORE_TOP_PERI0			0x0528
#define MUX_IGNORE_TOP_PERI1			0x052c
#define MUX_IGNORE_TOP_FSYS			0x0530
#define DIV_TOP_G2D_MFC				0x0600
#define DIV_TOP_GSCL_ISP0			0x0604
#define DIV_TOP_ISP10				0x0608
#define DIV_TOP_ISP11				0x060c
#define DIV_TOP_DISP				0x0610
#define DIV_TOP_BUS				0x0614
#define DIV_TOP_PERI0				0x0618
#define DIV_TOP_PERI1				0x061c
#define DIV_TOP_PERI2				0x0620
#define DIV_TOP_FSYS0				0x0624
#define DIV_TOP_FSYS1				0x0628
#define DIV_TOP_HPM				0x062c
#define DIV_TOP_PLL_FDET			0x0630
#define DIV_STAT_TOP_G2D_MFC			0x0700
#define DIV_STAT_TOP_GSCL_ISP0			0x0704
#define DIV_STAT_TOP_ISP10			0x0708
#define DIV_STAT_TOP_ISP11			0x070c
#define DIV_STAT_TOP_DISP			0x0710
#define DIV_STAT_TOP_BUS			0x0714
#define DIV_STAT_TOP_PERI0			0x0718
#define DIV_STAT_TOP_PERI1			0x071c
#define DIV_STAT_TOP_PERI2			0x0720
#define DIV_STAT_TOP_FSYS0			0x0724
#define DIV_STAT_TOP_FSYS1			0x0728
#define DIV_STAT_TOP_HPM			0x072c
#define DIV_STAT_TOP_PLL_FDET			0x0730
#define EN_ACLK_TOP				0x0800
#define EN_SCLK_TOP				0x0a00
#define EN_IP_TOP				0x0b00
#define CLKOUT_CMU_TOP				0x0c00
#define CLKOUT_CMU_TOP_DIV_STAT			0x0c04

#endif /*__CLK_EXYNOS5260_H */

