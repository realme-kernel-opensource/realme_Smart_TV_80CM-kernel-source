/*
 * Hardware specific definitions for SL-Cx000 series of PDAs
 *
 * Copyright (c) 2005 Alexander Wykes
 * Copyright (c) 2005 Richard Purdie
 *
 * Based on Sharp's 2.4 kernel patches
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */
#ifndef __ASM_ARCH_SPITZ_H
#define __ASM_ARCH_SPITZ_H  1
#endif

#include "irqs.h" /* PXA_NR_BUILTIN_GPIO, PXA_GPIO_TO_IRQ */
#include <linux/fb.h>

/* Spitz/Akita GPIOs */

#define SPITZ_GPIO_KEY_INT         (0) /* Key Interrupt */
#define SPITZ_GPIO_RESET           (1)
#define SPITZ_GPIO_nSD_DETECT      (9)
#define SPITZ_GPIO_TP_INT          (11) /* Touch Panel interrupt */
#define SPITZ_GPIO_AK_INT          (13) /* Remote Control */
#define SPITZ_GPIO_ADS7846_CS      (14)
#define SPITZ_GPIO_SYNC            (16)
#define SPITZ_GPIO_MAX1111_CS      (20)
#define SPITZ_GPIO_FATAL_BAT       (21)
#define SPITZ_GPIO_HSYNC           (22)
#define SPITZ_GPIO_nSD_CLK         (32)
#define SPITZ_GPIO_USB_DEVICE      (35)
#define SPITZ_GPIO_USB_HOST        (37)
#define SPITZ_GPIO_USB_CONNECT     (41)
#define SPITZ_GPIO_LCDCON_CS       (53)
#define SPITZ_GPIO_nPCE            (54)
#define SPITZ_GPIO_nSD_WP          (81)
#define SPITZ_GPIO_ON_RESET        (89)
#define SPITZ_GPIO_BAT_COVER       (90)
#define SPITZ_GPIO_CF_CD           (94)
#define SPITZ_GPIO_ON_KEY          (95)
#define SPITZ_GPIO_SWA             (97)
#define SPITZ_GPIO_SWB             (96)
#define SPITZ_GPIO_CHRG_FULL       (101)
#define SPITZ_GPIO_CO              (101)
#define SPITZ_GPIO_CF_IRQ          (105)
#define SPITZ_GPIO_AC_IN           (115)
#define SPITZ_GPIO_HP_IN           (116)

/* Spitz Only GPIOs */

#define SPITZ_GPIO_CF2_IRQ         (106) /* CF slot1 Ready */
#define SPITZ_GPIO_CF2_CD          (93)


/* Spitz/Akita Keyboard Definitions */

#define SPITZ_KEY_STROBE_NUM         (11)
#define SPITZ_KEY_SENSE_NUM          (7)
#define SPITZ_GPIO_G0_STROBE_BIT     0x0f800000
#define SPITZ_GPIO_G1_STROBE_BIT     0x00100000
#define SPITZ_GPIO_G2_STROBE_BIT     0x01000000
#define SPITZ_GPIO_G3_STROBE_BIT     0x00041880
#define SPITZ_GPIO_G0_SENSE_BIT      0x00021000
#define SPITZ_GPIO_G1_SENSE_BIT      0x000000d4
#define SPITZ_GPIO_G2_SENSE_BIT      0x08000000
#define SPITZ_GPIO_G3_SENSE_BIT      0x00000000

#define SPITZ_GPIO_KEY_STROBE0       88
#define SPITZ_GPIO_KEY_STROBE1       23
#define SPITZ_GPIO_KEY_STROBE2       24
#define SPITZ_GPIO_KEY_STROBE3       25
#define SPITZ_GPIO_KEY_STROBE4       26
#define SPITZ_GPIO_KEY_STROBE5       27
#define SPITZ_GPIO_KEY_STROBE6       52
#define SPITZ_GPIO_KEY_STROBE7       103
#define SPITZ_GPIO_KEY_STROBE8       107
#define SPITZ_GPIO_KEY_STROBE9       108
#define SPITZ_GPIO_KEY_STROBE10      114

#define SPITZ_GPIO_KEY_SENSE0        12
#define SPITZ_GPIO_KEY_SENSE1        17
#define SPITZ_GPIO_KEY_SENSE2        91
#define SPITZ_GPIO_KEY_SENSE3        34
#define SPITZ_GPIO_KEY_SENSE4        36
#define SPITZ_GPIO_KEY_SENSE5        38
#define SPITZ_GPIO_KEY_SENSE6        39


/* Spitz Scoop Device (No. 1) GPIOs */
/* Suspend States in comments */
#define SPITZ_SCP_LED_GREEN     SCOOP_GPCR_PA11  /* Keep */
#define SPITZ_SCP_JK_B          SCOOP_GPCR_PA12  /* Keep */
#define SPITZ_SCP_CHRG_ON       SCOOP_GPCR_PA13  /* Keep */
#define SPITZ_SCP_MUTE_L        SCOOP_GPCR_PA14  /* Low */
#define SPITZ_SCP_MUTE_R        SCOOP_GPCR_PA15  /* Low */
#define SPITZ_SCP_CF_POWER      SCOOP_GPCR_PA16  /* Keep */
#define SPITZ_SCP_LED_ORANGE    SCOOP_GPCR_PA17  /* Keep */
#define SPITZ_SCP_JK_A          SCOOP_GPCR_PA18  /* Low */
#define SPITZ_SCP_ADC_TEMP_ON   SCOOP_GPCR_PA19  /* Low */

#define SPITZ_SCP_IO_DIR      (SPITZ_SCP_JK_B | SPITZ_SCP_CHRG_ON | \
                               SPITZ_SCP_MUTE_L | SPITZ_SCP_MUTE_R | \
                               SPITZ_SCP_CF_POWER | SPITZ_SCP_JK_A | SPITZ_SCP_ADC_TEMP_ON)
#define SPITZ_SCP_IO_OUT      (SPITZ_SCP_CHRG_ON | SPITZ_SCP_MUTE_L | SPITZ_SCP_MUTE_R)
#define SPITZ_SCP_SUS_CLR     (SPITZ_SCP_MUTE_L | SPITZ_SCP_MUTE_R | SPITZ_SCP_JK_A | SPITZ_SCP_ADC_TEMP_ON)
#define SPITZ_SCP_SUS_SET     0

#define SPITZ_SCP_GPIO_BASE	(PXA_NR_BUILTIN_GPIO)
#define SPITZ_GPIO_LED_GREEN	(SPITZ_SCP_GPIO_BASE + 0)
#define SPITZ_GPIO_JK_B		(SPITZ_SCP_GPIO_BASE + 1)
#define SPITZ_GPIO_CHRG_ON	(SPITZ_SCP_GPIO_BASE + 2)
#define SPITZ_GPIO_MUTE_L	(SPITZ_SCP_GPIO_BASE + 3)
#define SPITZ_GPIO_MUTE_R	(SPITZ_SCP_GPIO_BASE + 4)
#define SPITZ_GPIO_CF_POWER	(SPITZ_SCP_GPIO_BASE + 5)
#define SPITZ_GPIO_LED_ORANGE	(SPITZ_SCP_GPIO_BASE + 6)
#define SPITZ_GPIO_JK_A		(SPITZ_SCP_GPIO_BASE + 7)
#define SPITZ_GPIO_ADC_TEMP_ON	(SPITZ_SCP_GPIO_BASE + 8)

/* Spitz Scoop Device (No. 2) GPIOs */
/* Suspend States in comments */
#define SPITZ_SCP2_IR_ON           SCOOP_GPCR_PA11  /* High */
#define SPITZ_SCP2_AKIN_PULLUP     SCOOP_GPCR_PA12  /* Keep */
#define SPITZ_SCP2_RESERVED_1      SCOOP_GPCR_PA13  /* High */
#define SPITZ_SCP2_RESERVED_2      SCOOP_GPCR_PA14  /* Low */
#define SPITZ_SCP2_RESERVED_3      SCOOP_GPCR_PA15  /* Low */
#define SPITZ_SCP2_RESERVED_4      SCOOP_GPCR_PA16  /* Low */
#define SPITZ_SCP2_BACKLIGHT_CONT  SCOOP_GPCR_PA17  /* Low */
#define SPITZ_SCP2_BACKLIGHT_ON    SCOOP_GPCR_PA18  /* Low */
#define SPITZ_SCP2_MIC_BIAS        SCOOP_GPCR_PA19  /* Low */

#define SPITZ_SCP2_IO_DIR (SPITZ_SCP2_AKIN_PULLUP | SPITZ_SCP2_RESERVED_1 | \
                           SPITZ_SCP2_RESERVED_2 | SPITZ_SCP2_RESERVED_3 | SPITZ_SCP2_RESERVED_4 | \
                           SPITZ_SCP2_BACKLIGHT_CONT | SPITZ_SCP2_BACKLIGHT_ON | SPITZ_SCP2_MIC_BIAS)

#define SPITZ_SCP2_IO_OUT   (SPITZ_SCP2_AKIN_PULLUP | SPITZ_SCP2_RESERVED_1)
#define SPITZ_SCP2_SUS_CLR  (SPITZ_SCP2_RESERVED_2 | SPITZ_SCP2_RESERVED_3 | SPITZ_SCP2_RESERVED_4 | \
                             SPITZ_SCP2_BACKLIGHT_CONT | SPITZ_SCP2_BACKLIGHT_ON | SPITZ_SCP2_MIC_BIAS)
#define SPITZ_SCP2_SUS_SET  (SPITZ_SCP2_IR_ON | SPITZ_SCP2_RESERVED_1)

#define SPITZ_SCP2_GPIO_BASE		(PXA_NR_BUILTIN_GPIO + 12)
#define SPITZ_GPIO_IR_ON		(SPITZ_SCP2_GPIO_BASE + 0)
#define SPITZ_GPIO_AKIN_PULLUP		(SPITZ_SCP2_GPIO_BASE + 1)
#define SPITZ_GPIO_RESERVED_1		(SPITZ_SCP2_GPIO_BASE + 2)
#define SPITZ_GPIO_RESERVED_2		(SPITZ_SCP2_GPIO_BASE + 3)
#define SPITZ_GPIO_RESERVED_3		(SPITZ_SCP2_GPIO_BASE + 4)
#define SPITZ_GPIO_RESERVED_4		(SPITZ_SCP2_GPIO_BASE + 5)
#define SPITZ_GPIO_BACKLIGHT_CONT	(SPITZ_SCP2_GPIO_BASE + 6)
#define SPITZ_GPIO_BACKLIGHT_ON		(SPITZ_SCP2_GPIO_BASE + 7)
#define SPITZ_GPIO_MIC_BIAS		(SPITZ_SCP2_GPIO_BASE + 8)

/* Akita IO Expander GPIOs */
#define AKITA_IOEXP_GPIO_BASE		(PXA_NR_BUILTIN_GPIO + 12)
#define AKITA_GPIO_RESERVED_0		(AKITA_IOEXP_GPIO_BASE + 0)
#define AKITA_GPIO_RESERVED_1		(AKITA_IOEXP_GPIO_BASE + 1)
#define AKITA_GPIO_MIC_BIAS		(AKITA_IOEXP_GPIO_BASE + 2)
#define AKITA_GPIO_BACKLIGHT_ON		(AKITA_IOEXP_GPIO_BASE + 3)
#define AKITA_GPIO_BACKLIGHT_CONT	(AKITA_IOEXP_GPIO_BASE + 4)
#define AKITA_GPIO_AKIN_PULLUP		(AKITA_IOEXP_GPIO_BASE + 5)
#define AKITA_GPIO_IR_ON		(AKITA_IOEXP_GPIO_BASE + 6)
#define AKITA_GPIO_RESERVED_7		(AKITA_IOEXP_GPIO_BASE + 7)

/* Spitz IRQ Definitions */

#define SPITZ_IRQ_GPIO_KEY_INT        PXA_GPIO_TO_IRQ(SPITZ_GPIO_KEY_INT)
#define SPITZ_IRQ_GPIO_AC_IN          PXA_GPIO_TO_IRQ(SPITZ_GPIO_AC_IN)
#define SPITZ_IRQ_GPIO_AK_INT         PXA_GPIO_TO_IRQ(SPITZ_GPIO_AK_INT)
#define SPITZ_IRQ_GPIO_HP_IN          PXA_GPIO_TO_IRQ(SPITZ_GPIO_HP_IN)
#define SPITZ_IRQ_GPIO_TP_INT         PXA_GPIO_TO_IRQ(SPITZ_GPIO_TP_INT)
#define SPITZ_IRQ_GPIO_SYNC           PXA_GPIO_TO_IRQ(SPITZ_GPIO_SYNC)
#define SPITZ_IRQ_GPIO_ON_KEY         PXA_GPIO_TO_IRQ(SPITZ_GPIO_ON_KEY)
#define SPITZ_IRQ_GPIO_SWA            PXA_GPIO_TO_IRQ(SPITZ_GPIO_SWA)
#define SPITZ_IRQ_GPIO_SWB            PXA_GPIO_TO_IRQ(SPITZ_GPIO_SWB)
#define SPITZ_IRQ_GPIO_BAT_COVER      PXA_GPIO_TO_IRQ(SPITZ_GPIO_BAT_COVER)
#define SPITZ_IRQ_GPIO_FATAL_BAT      PXA_GPIO_TO_IRQ(SPITZ_GPIO_FATAL_BAT)
#define SPITZ_IRQ_GPIO_CO             PXA_GPIO_TO_IRQ(SPITZ_GPIO_CO)
#define SPITZ_IRQ_GPIO_CF_IRQ         PXA_GPIO_TO_IRQ(SPITZ_GPIO_CF_IRQ)
#define SPITZ_IRQ_GPIO_CF_CD          PXA_GPIO_TO_IRQ(SPITZ_GPIO_CF_CD)
#define SPITZ_IRQ_GPIO_CF2_IRQ        PXA_GPIO_TO_IRQ(SPITZ_GPIO_CF2_IRQ)
#define SPITZ_IRQ_GPIO_nSD_INT        PXA_GPIO_TO_IRQ(SPITZ_GPIO_nSD_INT)
#define SPITZ_IRQ_GPIO_nSD_DETECT     PXA_GPIO_TO_IRQ(SPITZ_GPIO_nSD_DETECT)

/*
 * Shared data structures
 */
extern struct platform_device spitzssp_device;
extern struct sharpsl_charger_machinfo spitz_pm_machinfo;
