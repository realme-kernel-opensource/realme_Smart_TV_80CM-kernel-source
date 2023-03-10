/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __ASM_MACH_MFP_PXA910_H
#define __ASM_MACH_MFP_PXA910_H

#include "mfp.h"

#define MFP_DRIVE_VERY_SLOW	(0x0 << 13)
#define MFP_DRIVE_SLOW		(0x2 << 13)
#define MFP_DRIVE_MEDIUM	(0x4 << 13)
#define MFP_DRIVE_FAST		(0x6 << 13)

/* UART2 */
#define GPIO47_UART2_RXD	MFP_CFG(GPIO47, AF6)
#define GPIO48_UART2_TXD	MFP_CFG(GPIO48, AF6)

/* UART3 */
#define GPIO31_UART3_RXD	MFP_CFG(GPIO31, AF4)
#define GPIO32_UART3_TXD	MFP_CFG(GPIO32, AF4)

/*IRDA*/
#define GPIO51_IRDA_SHDN	MFP_CFG(GPIO51, AF0)

/* SMC */
#define SM_nCS0_nCS0		MFP_CFG(SM_nCS0, AF0)
#define SM_ADV_SM_ADV		MFP_CFG(SM_ADV, AF0)
#define SM_SCLK_SM_SCLK		MFP_CFG(SM_SCLK, AF0)
#define SM_BE0_SM_BE0		MFP_CFG(SM_BE0, AF1)
#define SM_BE1_SM_BE1		MFP_CFG(SM_BE1, AF1)

/* I2C */
#define GPIO53_CI2C_SCL		MFP_CFG(GPIO53, AF2)
#define GPIO54_CI2C_SDA		MFP_CFG(GPIO54, AF2)

/* SSP1 (I2S) */
#define GPIO24_SSP1_SDATA_IN	MFP_CFG_DRV(GPIO24, AF1, MEDIUM)
#define GPIO21_SSP1_BITCLK	MFP_CFG_DRV(GPIO21, AF1, MEDIUM)
#define GPIO20_SSP1_SYSCLK	MFP_CFG_DRV(GPIO20, AF1, MEDIUM)
#define GPIO22_SSP1_SYNC	MFP_CFG_DRV(GPIO22, AF1, MEDIUM)
#define GPIO23_SSP1_DATA_OUT	MFP_CFG_DRV(GPIO23, AF1, MEDIUM)
#define GPIO124_MN_CLK_OUT	MFP_CFG_DRV(GPIO124, AF1, MEDIUM)
#define GPIO123_CLK_REQ		MFP_CFG_DRV(GPIO123, AF0, MEDIUM)

/* DFI */
#define DF_IO0_ND_IO0		MFP_CFG(DF_IO0, AF0)
#define DF_IO1_ND_IO1		MFP_CFG(DF_IO1, AF0)
#define DF_IO2_ND_IO2		MFP_CFG(DF_IO2, AF0)
#define DF_IO3_ND_IO3		MFP_CFG(DF_IO3, AF0)
#define DF_IO4_ND_IO4		MFP_CFG(DF_IO4, AF0)
#define DF_IO5_ND_IO5		MFP_CFG(DF_IO5, AF0)
#define DF_IO6_ND_IO6		MFP_CFG(DF_IO6, AF0)
#define DF_IO7_ND_IO7		MFP_CFG(DF_IO7, AF0)
#define DF_IO8_ND_IO8		MFP_CFG(DF_IO8, AF0)
#define DF_IO9_ND_IO9		MFP_CFG(DF_IO9, AF0)
#define DF_IO10_ND_IO10		MFP_CFG(DF_IO10, AF0)
#define DF_IO11_ND_IO11		MFP_CFG(DF_IO11, AF0)
#define DF_IO12_ND_IO12		MFP_CFG(DF_IO12, AF0)
#define DF_IO13_ND_IO13		MFP_CFG(DF_IO13, AF0)
#define DF_IO14_ND_IO14		MFP_CFG(DF_IO14, AF0)
#define DF_IO15_ND_IO15		MFP_CFG(DF_IO15, AF0)
#define DF_nCS0_SM_nCS2_nCS0	MFP_CFG(DF_nCS0_SM_nCS2, AF0)
#define DF_ALE_SM_WEn_ND_ALE	MFP_CFG(DF_ALE_SM_WEn, AF1)
#define DF_CLE_SM_OEn_ND_CLE	MFP_CFG(DF_CLE_SM_OEn, AF0)
#define DF_WEn_DF_WEn		MFP_CFG(DF_WEn, AF1)
#define DF_REn_DF_REn		MFP_CFG(DF_REn, AF1)
#define DF_RDY0_DF_RDY0		MFP_CFG(DF_RDY0, AF0)

/*keypad*/
#define GPIO00_KP_MKIN0		MFP_CFG(GPIO0, AF1)
#define GPIO01_KP_MKOUT0	MFP_CFG(GPIO1, AF1)
#define GPIO02_KP_MKIN1		MFP_CFG(GPIO2, AF1)
#define GPIO03_KP_MKOUT1	MFP_CFG(GPIO3, AF1)
#define GPIO04_KP_MKIN2		MFP_CFG(GPIO4, AF1)
#define GPIO05_KP_MKOUT2	MFP_CFG(GPIO5, AF1)
#define GPIO06_KP_MKIN3		MFP_CFG(GPIO6, AF1)
#define GPIO07_KP_MKOUT3	MFP_CFG(GPIO7, AF1)
#define GPIO08_KP_MKIN4		MFP_CFG(GPIO8, AF1)
#define GPIO09_KP_MKOUT4	MFP_CFG(GPIO9, AF1)
#define GPIO10_KP_MKIN5		MFP_CFG(GPIO10, AF1)
#define GPIO11_KP_MKOUT5	MFP_CFG(GPIO11, AF1)
#define GPIO12_KP_MKIN6		MFP_CFG(GPIO12, AF1)
#define GPIO13_KP_MKOUT6	MFP_CFG(GPIO13, AF1)
#define GPIO14_KP_MKIN7		MFP_CFG(GPIO14, AF1)
#define GPIO15_KP_MKOUT7	MFP_CFG(GPIO15, AF1)
#define GPIO16_KP_DKIN0		MFP_CFG(GPIO16, AF1)
#define GPIO17_KP_DKIN1		MFP_CFG(GPIO17, AF1)
#define GPIO18_KP_DKIN2		MFP_CFG(GPIO18, AF1)
#define GPIO19_KP_DKIN3		MFP_CFG(GPIO19, AF1)

/* LCD */
#define GPIO81_LCD_FCLK		MFP_CFG(GPIO81, AF1)
#define GPIO82_LCD_LCLK		MFP_CFG(GPIO82, AF1)
#define GPIO83_LCD_PCLK		MFP_CFG(GPIO83, AF1)
#define GPIO84_LCD_DENA		MFP_CFG(GPIO84, AF1)
#define GPIO85_LCD_DD0		MFP_CFG(GPIO85, AF1)
#define GPIO86_LCD_DD1		MFP_CFG(GPIO86, AF1)
#define GPIO87_LCD_DD2		MFP_CFG(GPIO87, AF1)
#define GPIO88_LCD_DD3		MFP_CFG(GPIO88, AF1)
#define GPIO89_LCD_DD4		MFP_CFG(GPIO89, AF1)
#define GPIO90_LCD_DD5		MFP_CFG(GPIO90, AF1)
#define GPIO91_LCD_DD6		MFP_CFG(GPIO91, AF1)
#define GPIO92_LCD_DD7		MFP_CFG(GPIO92, AF1)
#define GPIO93_LCD_DD8		MFP_CFG(GPIO93, AF1)
#define GPIO94_LCD_DD9		MFP_CFG(GPIO94, AF1)
#define GPIO95_LCD_DD10		MFP_CFG(GPIO95, AF1)
#define GPIO96_LCD_DD11		MFP_CFG(GPIO96, AF1)
#define GPIO97_LCD_DD12		MFP_CFG(GPIO97, AF1)
#define GPIO98_LCD_DD13		MFP_CFG(GPIO98, AF1)
#define GPIO100_LCD_DD14	MFP_CFG(GPIO100, AF1)
#define GPIO101_LCD_DD15	MFP_CFG(GPIO101, AF1)
#define GPIO102_LCD_DD16	MFP_CFG(GPIO102, AF1)
#define GPIO103_LCD_DD17	MFP_CFG(GPIO103, AF1)
#define GPIO104_LCD_DD18	MFP_CFG(GPIO104, AF1)
#define GPIO105_LCD_DD19	MFP_CFG(GPIO105, AF1)
#define GPIO106_LCD_DD20	MFP_CFG(GPIO106, AF1)
#define GPIO107_LCD_DD21	MFP_CFG(GPIO107, AF1)
#define GPIO108_LCD_DD22	MFP_CFG(GPIO108, AF1)
#define GPIO109_LCD_DD23	MFP_CFG(GPIO109, AF1)

#define GPIO104_LCD_SPIDOUT	MFP_CFG(GPIO104, AF3)
#define GPIO105_LCD_SPIDIN	MFP_CFG(GPIO105, AF3)
#define GPIO107_LCD_CS1 	MFP_CFG(GPIO107, AF3)
#define GPIO108_LCD_DCLK	MFP_CFG(GPIO108, AF3)

#define GPIO106_LCD_RESET	MFP_CFG(GPIO106, AF0)

/*smart panel*/
#define GPIO82_LCD_A0		MFP_CFG(GPIO82, AF0)
#define GPIO83_LCD_WR		MFP_CFG(GPIO83, AF0)
#define GPIO103_LCD_CS		MFP_CFG(GPIO103, AF0)

/*1wire*/
#define GPIO106_1WIRE		MFP_CFG(GPIO106, AF3)

/*CCIC*/
#define GPIO67_CCIC_IN7		MFP_CFG_DRV(GPIO67, AF1, MEDIUM)
#define GPIO68_CCIC_IN6		MFP_CFG_DRV(GPIO68, AF1, MEDIUM)
#define GPIO69_CCIC_IN5		MFP_CFG_DRV(GPIO69, AF1, MEDIUM)
#define GPIO70_CCIC_IN4		MFP_CFG_DRV(GPIO70, AF1, MEDIUM)
#define GPIO71_CCIC_IN3		MFP_CFG_DRV(GPIO71, AF1, MEDIUM)
#define GPIO72_CCIC_IN2		MFP_CFG_DRV(GPIO72, AF1, MEDIUM)
#define GPIO73_CCIC_IN1		MFP_CFG_DRV(GPIO73, AF1, MEDIUM)
#define GPIO74_CCIC_IN0		MFP_CFG_DRV(GPIO74, AF1, MEDIUM)
#define GPIO75_CAM_HSYNC	MFP_CFG_DRV(GPIO75, AF1, MEDIUM)
#define GPIO76_CAM_VSYNC	MFP_CFG_DRV(GPIO76, AF1, MEDIUM)
#define GPIO77_CAM_MCLK		MFP_CFG_DRV(GPIO77, AF1, MEDIUM)
#define GPIO78_CAM_PCLK		MFP_CFG_DRV(GPIO78, AF1, MEDIUM)

/* MMC1 */
#define MMC1_DAT7_MMC1_DAT7	MFP_CFG_DRV(MMC1_DAT7, AF0, MEDIUM)
#define MMC1_DAT6_MMC1_DAT6	MFP_CFG_DRV(MMC1_DAT6, AF0, MEDIUM)
#define MMC1_DAT5_MMC1_DAT5	MFP_CFG_DRV(MMC1_DAT5, AF0, MEDIUM)
#define MMC1_DAT4_MMC1_DAT4	MFP_CFG_DRV(MMC1_DAT4, AF0, MEDIUM)
#define MMC1_DAT3_MMC1_DAT3	MFP_CFG_DRV(MMC1_DAT3, AF0, MEDIUM)
#define MMC1_DAT2_MMC1_DAT2	MFP_CFG_DRV(MMC1_DAT2, AF0, MEDIUM)
#define MMC1_DAT1_MMC1_DAT1	MFP_CFG_DRV(MMC1_DAT1, AF0, MEDIUM)
#define MMC1_DAT0_MMC1_DAT0	MFP_CFG_DRV(MMC1_DAT0, AF0, MEDIUM)
#define MMC1_CMD_MMC1_CMD	MFP_CFG_DRV(MMC1_CMD, AF0, MEDIUM)
#define MMC1_CLK_MMC1_CLK	MFP_CFG_DRV(MMC1_CLK, AF0, MEDIUM)
#define MMC1_CD_MMC1_CD		MFP_CFG_DRV(MMC1_CD, AF0, MEDIUM)
#define MMC1_WP_MMC1_WP		MFP_CFG_DRV(MMC1_WP, AF0, MEDIUM)

/* PWM */
#define GPIO27_PWM3_AF2		MFP_CFG(GPIO27, AF2)
#define GPIO51_PWM2_OUT		MFP_CFG(GPIO51, AF2)
#define GPIO117_PWM1_OUT	MFP_CFG(GPIO117, AF2)
#define GPIO118_PWM2_OUT	MFP_CFG(GPIO118, AF2)
#define GPIO119_PWM3_OUT	MFP_CFG(GPIO119, AF2)
#define GPIO120_PWM4_OUT	MFP_CFG(GPIO120, AF2)

#endif /* __ASM_MACH MFP_PXA910_H */
