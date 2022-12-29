/*
 * Copyright (C) 2015-2017 Socionext Inc.
 *   Author: Masahiro Yamada <yamada.masahiro@socionext.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/mod_devicetable.h>
#include <linux/pinctrl/pinctrl.h>
#include <linux/platform_device.h>

#include "pinctrl-uniphier.h"

static const struct pinctrl_pin_desc uniphier_ld4_pins[] = {
	UNIPHIER_PINCTRL_PIN(0, "EA1", UNIPHIER_PIN_IECTRL_NONE,
			     8, UNIPHIER_PIN_DRV_1BIT,
			     8, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(1, "EA2", UNIPHIER_PIN_IECTRL_NONE,
			     9, UNIPHIER_PIN_DRV_1BIT,
			     9, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(2, "EA3", UNIPHIER_PIN_IECTRL_NONE,
			     10, UNIPHIER_PIN_DRV_1BIT,
			     10, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(3, "EA4", UNIPHIER_PIN_IECTRL_NONE,
			     11, UNIPHIER_PIN_DRV_1BIT,
			     11, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(4, "EA5", UNIPHIER_PIN_IECTRL_NONE,
			     12, UNIPHIER_PIN_DRV_1BIT,
			     12, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(5, "EA6", UNIPHIER_PIN_IECTRL_NONE,
			     13, UNIPHIER_PIN_DRV_1BIT,
			     13, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(6, "EA7", UNIPHIER_PIN_IECTRL_NONE,
			     14, UNIPHIER_PIN_DRV_1BIT,
			     14, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(7, "EA8", 0,
			     15, UNIPHIER_PIN_DRV_1BIT,
			     15, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(8, "EA9", 0,
			     16, UNIPHIER_PIN_DRV_1BIT,
			     16, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(9, "EA10", 0,
			     17, UNIPHIER_PIN_DRV_1BIT,
			     17, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(10, "EA11", 0,
			     18, UNIPHIER_PIN_DRV_1BIT,
			     18, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(11, "EA12", 0,
			     19, UNIPHIER_PIN_DRV_1BIT,
			     19, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(12, "EA13", 0,
			     20, UNIPHIER_PIN_DRV_1BIT,
			     20, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(13, "EA14", 0,
			     21, UNIPHIER_PIN_DRV_1BIT,
			     21, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(14, "EA15", 0,
			     22, UNIPHIER_PIN_DRV_1BIT,
			     22, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(15, "ECLK", UNIPHIER_PIN_IECTRL_NONE,
			     23, UNIPHIER_PIN_DRV_1BIT,
			     23, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(16, "XERWE0", UNIPHIER_PIN_IECTRL_NONE,
			     24, UNIPHIER_PIN_DRV_1BIT,
			     24, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(17, "XERWE1", UNIPHIER_PIN_IECTRL_NONE,
			     25, UNIPHIER_PIN_DRV_1BIT,
			     25, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(18, "ES0", UNIPHIER_PIN_IECTRL_NONE,
			     27, UNIPHIER_PIN_DRV_1BIT,
			     27, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(19, "ES1", UNIPHIER_PIN_IECTRL_NONE,
			     28, UNIPHIER_PIN_DRV_1BIT,
			     28, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(20, "ES2", UNIPHIER_PIN_IECTRL_NONE,
			     29, UNIPHIER_PIN_DRV_1BIT,
			     29, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(21, "XERST", UNIPHIER_PIN_IECTRL_NONE,
			     38, UNIPHIER_PIN_DRV_1BIT,
			     38, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(22, "MMCCLK", UNIPHIER_PIN_IECTRL_NONE,
			     0, UNIPHIER_PIN_DRV_2BIT,
			     146, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(23, "MMCCMD", UNIPHIER_PIN_IECTRL_NONE,
			     1, UNIPHIER_PIN_DRV_2BIT,
			     147, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(24, "MMCDAT0", UNIPHIER_PIN_IECTRL_NONE,
			     2, UNIPHIER_PIN_DRV_2BIT,
			     148, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(25, "MMCDAT1", UNIPHIER_PIN_IECTRL_NONE,
			     3, UNIPHIER_PIN_DRV_2BIT,
			     149, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(26, "MMCDAT2", UNIPHIER_PIN_IECTRL_NONE,
			     4, UNIPHIER_PIN_DRV_2BIT,
			     150, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(27, "MMCDAT3", UNIPHIER_PIN_IECTRL_NONE,
			     5, UNIPHIER_PIN_DRV_2BIT,
			     151, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(28, "MMCDAT4", UNIPHIER_PIN_IECTRL_NONE,
			     6, UNIPHIER_PIN_DRV_2BIT,
			     152, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(29, "MMCDAT5", UNIPHIER_PIN_IECTRL_NONE,
			     7, UNIPHIER_PIN_DRV_2BIT,
			     153, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(30, "MMCDAT6", UNIPHIER_PIN_IECTRL_NONE,
			     8, UNIPHIER_PIN_DRV_2BIT,
			     154, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(31, "MMCDAT7", UNIPHIER_PIN_IECTRL_NONE,
			     9, UNIPHIER_PIN_DRV_2BIT,
			     155, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(32, "RMII_RXD0", 6,
			     39, UNIPHIER_PIN_DRV_1BIT,
			     39, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(33, "RMII_RXD1", 6,
			     40, UNIPHIER_PIN_DRV_1BIT,
			     40, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(34, "RMII_CRS_DV", 6,
			     41, UNIPHIER_PIN_DRV_1BIT,
			     41, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(35, "RMII_RXER", 6,
			     42, UNIPHIER_PIN_DRV_1BIT,
			     42, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(36, "RMII_REFCLK", 6,
			     43, UNIPHIER_PIN_DRV_1BIT,
			     43, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(37, "RMII_TXD0", 6,
			     44, UNIPHIER_PIN_DRV_1BIT,
			     44, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(38, "RMII_TXD1", 6,
			     45, UNIPHIER_PIN_DRV_1BIT,
			     45, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(39, "RMII_TXEN", 6,
			     46, UNIPHIER_PIN_DRV_1BIT,
			     46, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(40, "MDC", 6,
			     47, UNIPHIER_PIN_DRV_1BIT,
			     47, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(41, "MDIO", 6,
			     48, UNIPHIER_PIN_DRV_1BIT,
			     48, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(42, "MDIO_INTL", 6,
			     49, UNIPHIER_PIN_DRV_1BIT,
			     49, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(43, "PHYRSTL", 6,
			     50, UNIPHIER_PIN_DRV_1BIT,
			     50, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(44, "SDCLK", UNIPHIER_PIN_IECTRL_NONE,
			     10, UNIPHIER_PIN_DRV_2BIT,
			     156, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(45, "SDCMD", UNIPHIER_PIN_IECTRL_NONE,
			     11, UNIPHIER_PIN_DRV_2BIT,
			     157, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(46, "SDDAT0", UNIPHIER_PIN_IECTRL_NONE,
			     12, UNIPHIER_PIN_DRV_2BIT,
			     158, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(47, "SDDAT1", UNIPHIER_PIN_IECTRL_NONE,
			     13, UNIPHIER_PIN_DRV_2BIT,
			     159, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(48, "SDDAT2", UNIPHIER_PIN_IECTRL_NONE,
			     14, UNIPHIER_PIN_DRV_2BIT,
			     160, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(49, "SDDAT3", UNIPHIER_PIN_IECTRL_NONE,
			     15, UNIPHIER_PIN_DRV_2BIT,
			     161, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(50, "SDCD", UNIPHIER_PIN_IECTRL_NONE,
			     51, UNIPHIER_PIN_DRV_1BIT,
			     51, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(51, "SDWP", UNIPHIER_PIN_IECTRL_NONE,
			     52, UNIPHIER_PIN_DRV_1BIT,
			     52, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(52, "SDVOLC", UNIPHIER_PIN_IECTRL_NONE,
			     53, UNIPHIER_PIN_DRV_1BIT,
			     53, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(53, "USB0VBUS", 0,
			     54, UNIPHIER_PIN_DRV_1BIT,
			     54, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(54, "USB0OD", 0,
			     55, UNIPHIER_PIN_DRV_1BIT,
			     55, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(55, "USB1VBUS", 0,
			     56, UNIPHIER_PIN_DRV_1BIT,
			     56, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(56, "USB1OD", 0,
			     57, UNIPHIER_PIN_DRV_1BIT,
			     57, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(57, "PCRESET", 0,
			     58, UNIPHIER_PIN_DRV_1BIT,
			     58, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(58, "PCREG", 0,
			     59, UNIPHIER_PIN_DRV_1BIT,
			     59, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(59, "PCCE2", 0,
			     60, UNIPHIER_PIN_DRV_1BIT,
			     60, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(60, "PCVS1", 0,
			     61, UNIPHIER_PIN_DRV_1BIT,
			     61, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(61, "PCCD2", 0,
			     62, UNIPHIER_PIN_DRV_1BIT,
			     62, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(62, "PCCD1", 0,
			     63, UNIPHIER_PIN_DRV_1BIT,
			     63, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(63, "PCREADY", 0,
			     64, UNIPHIER_PIN_DRV_1BIT,
			     64, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(64, "PCDOE", 0,
			     65, UNIPHIER_PIN_DRV_1BIT,
			     65, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(65, "PCCE1", 0,
			     66, UNIPHIER_PIN_DRV_1BIT,
			     66, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(66, "PCWE", 0,
			     67, UNIPHIER_PIN_DRV_1BIT,
			     67, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(67, "PCOE", 0,
			     68, UNIPHIER_PIN_DRV_1BIT,
			     68, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(68, "PCWAIT", 0,
			     69, UNIPHIER_PIN_DRV_1BIT,
			     69, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(69, "PCIOWR", 0,
			     70, UNIPHIER_PIN_DRV_1BIT,
			     70, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(70, "PCIORD", 0,
			     71, UNIPHIER_PIN_DRV_1BIT,
			     71, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(71, "HS0DIN0", 0,
			     72, UNIPHIER_PIN_DRV_1BIT,
			     72, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(72, "HS0DIN1", 0,
			     73, UNIPHIER_PIN_DRV_1BIT,
			     73, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(73, "HS0DIN2", 0,
			     74, UNIPHIER_PIN_DRV_1BIT,
			     74, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(74, "HS0DIN3", 0,
			     75, UNIPHIER_PIN_DRV_1BIT,
			     75, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(75, "HS0DIN4", 0,
			     76, UNIPHIER_PIN_DRV_1BIT,
			     76, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(76, "HS0DIN5", 0,
			     77, UNIPHIER_PIN_DRV_1BIT,
			     77, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(77, "HS0DIN6", 0,
			     78, UNIPHIER_PIN_DRV_1BIT,
			     78, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(78, "HS0DIN7", 0,
			     79, UNIPHIER_PIN_DRV_1BIT,
			     79, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(79, "HS0BCLKIN", 0,
			     80, UNIPHIER_PIN_DRV_1BIT,
			     80, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(80, "HS0VALIN", 0,
			     81, UNIPHIER_PIN_DRV_1BIT,
			     81, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(81, "HS0SYNCIN", 0,
			     82, UNIPHIER_PIN_DRV_1BIT,
			     82, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(82, "HSDOUT0", 0,
			     83, UNIPHIER_PIN_DRV_1BIT,
			     83, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(83, "HSDOUT1", 0,
			     84, UNIPHIER_PIN_DRV_1BIT,
			     84, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(84, "HSDOUT2", 0,
			     85, UNIPHIER_PIN_DRV_1BIT,
			     85, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(85, "HSDOUT3", 0,
			     86, UNIPHIER_PIN_DRV_1BIT,
			     86, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(86, "HSDOUT4", 0,
			     87, UNIPHIER_PIN_DRV_1BIT,
			     87, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(87, "HSDOUT5", 0,
			     88, UNIPHIER_PIN_DRV_1BIT,
			     88, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(88, "HSDOUT6", 0,
			     89, UNIPHIER_PIN_DRV_1BIT,
			     89, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(89, "HSDOUT7", 0,
			     90, UNIPHIER_PIN_DRV_1BIT,
			     90, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(90, "HSBCLKOUT", 0,
			     91, UNIPHIER_PIN_DRV_1BIT,
			     91, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(91, "HSVALOUT", 0,
			     92, UNIPHIER_PIN_DRV_1BIT,
			     92, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(92, "HSSYNCOUT", 0,
			     93, UNIPHIER_PIN_DRV_1BIT,
			     93, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(93, "AGCI", 3,
			     -1, UNIPHIER_PIN_DRV_FIXED4,
			     162, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(94, "AGCR", 4,
			     -1, UNIPHIER_PIN_DRV_FIXED4,
			     163, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(95, "AGCBS", 5,
			     -1, UNIPHIER_PIN_DRV_FIXED4,
			     164, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(96, "IECOUT", 0,
			     94, UNIPHIER_PIN_DRV_1BIT,
			     94, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(97, "ASMCK", 0,
			     95, UNIPHIER_PIN_DRV_1BIT,
			     95, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(98, "ABCKO", UNIPHIER_PIN_IECTRL_NONE,
			     96, UNIPHIER_PIN_DRV_1BIT,
			     96, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(99, "ALRCKO", UNIPHIER_PIN_IECTRL_NONE,
			     97, UNIPHIER_PIN_DRV_1BIT,
			     97, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(100, "ASDOUT0", UNIPHIER_PIN_IECTRL_NONE,
			     98, UNIPHIER_PIN_DRV_1BIT,
			     98, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(101, "ARCOUT", 0,
			     99, UNIPHIER_PIN_DRV_1BIT,
			     99, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(102, "SDA0", UNIPHIER_PIN_IECTRL_NONE,
			     -1, UNIPHIER_PIN_DRV_FIXED4,
			     -1, UNIPHIER_PIN_PULL_NONE),
	UNIPHIER_PINCTRL_PIN(103, "SCL0", UNIPHIER_PIN_IECTRL_NONE,
			     -1, UNIPHIER_PIN_DRV_FIXED4,
			     -1, UNIPHIER_PIN_PULL_NONE),
	UNIPHIER_PINCTRL_PIN(104, "SDA1", UNIPHIER_PIN_IECTRL_NONE,
			     -1, UNIPHIER_PIN_DRV_FIXED4,
			     -1, UNIPHIER_PIN_PULL_NONE),
	UNIPHIER_PINCTRL_PIN(105, "SCL1", UNIPHIER_PIN_IECTRL_NONE,
			     -1, UNIPHIER_PIN_DRV_FIXED4,
			     -1, UNIPHIER_PIN_PULL_NONE),
	UNIPHIER_PINCTRL_PIN(106, "DMDSDA0", UNIPHIER_PIN_IECTRL_NONE,
			     -1, UNIPHIER_PIN_DRV_FIXED4,
			     -1, UNIPHIER_PIN_PULL_NONE),
	UNIPHIER_PINCTRL_PIN(107, "DMDSCL0", UNIPHIER_PIN_IECTRL_NONE,
			     -1, UNIPHIER_PIN_DRV_FIXED4,
			     -1, UNIPHIER_PIN_PULL_NONE),
	UNIPHIER_PINCTRL_PIN(108, "DMDSDA1", UNIPHIER_PIN_IECTRL_NONE,
			     -1, UNIPHIER_PIN_DRV_FIXED4,
			     -1, UNIPHIER_PIN_PULL_NONE),
	UNIPHIER_PINCTRL_PIN(109, "DMDSCL1", UNIPHIER_PIN_IECTRL_NONE,
			     -1, UNIPHIER_PIN_DRV_FIXED4,
			     -1, UNIPHIER_PIN_PULL_NONE),
	UNIPHIER_PINCTRL_PIN(110, "SBO0", UNIPHIER_PIN_IECTRL_NONE,
			     100, UNIPHIER_PIN_DRV_1BIT,
			     100, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(111, "SBI0", UNIPHIER_PIN_IECTRL_NONE,
			     101, UNIPHIER_PIN_DRV_1BIT,
			     101, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(112, "HIN", 1,
			     -1, UNIPHIER_PIN_DRV_FIXED5,
			     -1, UNIPHIER_PIN_PULL_NONE),
	UNIPHIER_PINCTRL_PIN(113, "VIN", 2,
			     -1, UNIPHIER_PIN_DRV_FIXED5,
			     -1, UNIPHIER_PIN_PULL_NONE),
	UNIPHIER_PINCTRL_PIN(114, "TCON0", UNIPHIER_PIN_IECTRL_NONE,
			     102, UNIPHIER_PIN_DRV_1BIT,
			     102, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(115, "TCON1", UNIPHIER_PIN_IECTRL_NONE,
			     103, UNIPHIER_PIN_DRV_1BIT,
			     103, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(116, "TCON2", UNIPHIER_PIN_IECTRL_NONE,
			     104, UNIPHIER_PIN_DRV_1BIT,
			     104, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(117, "TCON3", UNIPHIER_PIN_IECTRL_NONE,
			     105, UNIPHIER_PIN_DRV_1BIT,
			     105, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(118, "TCON4", UNIPHIER_PIN_IECTRL_NONE,
			     106, UNIPHIER_PIN_DRV_1BIT,
			     106, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(119, "TCON5", UNIPHIER_PIN_IECTRL_NONE,
			     107, UNIPHIER_PIN_DRV_1BIT,
			     107, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(120, "TCON6", 0,
			     108, UNIPHIER_PIN_DRV_1BIT,
			     108, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(121, "TCON7", 0,
			     109, UNIPHIER_PIN_DRV_1BIT,
			     109, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(122, "PWMA", 0,
			     110, UNIPHIER_PIN_DRV_1BIT,
			     110, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(123, "XIRQ1", 0,
			     111, UNIPHIER_PIN_DRV_1BIT,
			     111, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(124, "XIRQ2", 0,
			     112, UNIPHIER_PIN_DRV_1BIT,
			     112, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(125, "XIRQ3", 0,
			     113, UNIPHIER_PIN_DRV_1BIT,
			     113, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(126, "XIRQ4", 0,
			     114, UNIPHIER_PIN_DRV_1BIT,
			     114, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(127, "XIRQ5", 0,
			     115, UNIPHIER_PIN_DRV_1BIT,
			     115, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(128, "XIRQ6", 0,
			     116, UNIPHIER_PIN_DRV_1BIT,
			     116, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(129, "XIRQ7", 0,
			     117, UNIPHIER_PIN_DRV_1BIT,
			     117, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(130, "XIRQ8", 0,
			     118, UNIPHIER_PIN_DRV_1BIT,
			     118, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(131, "XIRQ9", 0,
			     119, UNIPHIER_PIN_DRV_1BIT,
			     119, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(132, "XIRQ10", 0,
			     120, UNIPHIER_PIN_DRV_1BIT,
			     120, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(133, "XIRQ11", 0,
			     121, UNIPHIER_PIN_DRV_1BIT,
			     121, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(134, "XIRQ14", 0,
			     122, UNIPHIER_PIN_DRV_1BIT,
			     122, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(135, "PORT00", 0,
			     123, UNIPHIER_PIN_DRV_1BIT,
			     123, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(136, "PORT01", 0,
			     124, UNIPHIER_PIN_DRV_1BIT,
			     124, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(137, "PORT02", 0,
			     125, UNIPHIER_PIN_DRV_1BIT,
			     125, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(138, "PORT03", 0,
			     126, UNIPHIER_PIN_DRV_1BIT,
			     126, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(139, "PORT04", 0,
			     127, UNIPHIER_PIN_DRV_1BIT,
			     127, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(140, "PORT05", 0,
			     128, UNIPHIER_PIN_DRV_1BIT,
			     128, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(141, "PORT06", 0,
			     129, UNIPHIER_PIN_DRV_1BIT,
			     129, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(142, "PORT07", 0,
			     130, UNIPHIER_PIN_DRV_1BIT,
			     130, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(143, "PORT10", 0,
			     131, UNIPHIER_PIN_DRV_1BIT,
			     131, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(144, "PORT11", 0,
			     132, UNIPHIER_PIN_DRV_1BIT,
			     132, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(145, "PORT12", 0,
			     133, UNIPHIER_PIN_DRV_1BIT,
			     133, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(146, "PORT13", 0,
			     134, UNIPHIER_PIN_DRV_1BIT,
			     134, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(147, "PORT14", 0,
			     135, UNIPHIER_PIN_DRV_1BIT,
			     135, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(148, "PORT15", 0,
			     136, UNIPHIER_PIN_DRV_1BIT,
			     136, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(149, "PORT16", 0,
			     137, UNIPHIER_PIN_DRV_1BIT,
			     137, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(150, "PORT17", UNIPHIER_PIN_IECTRL_NONE,
			     138, UNIPHIER_PIN_DRV_1BIT,
			     138, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(151, "PORT20", 0,
			     139, UNIPHIER_PIN_DRV_1BIT,
			     139, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(152, "PORT21", 0,
			     140, UNIPHIER_PIN_DRV_1BIT,
			     140, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(153, "PORT22", 0,
			     141, UNIPHIER_PIN_DRV_1BIT,
			     141, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(154, "PORT23", 0,
			     142, UNIPHIER_PIN_DRV_1BIT,
			     142, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(155, "PORT24", UNIPHIER_PIN_IECTRL_NONE,
			     143, UNIPHIER_PIN_DRV_1BIT,
			     143, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(156, "PORT25", 0,
			     144, UNIPHIER_PIN_DRV_1BIT,
			     144, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(157, "PORT26", 0,
			     145, UNIPHIER_PIN_DRV_1BIT,
			     145, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(158, "XNFRE", UNIPHIER_PIN_IECTRL_NONE,
			     31, UNIPHIER_PIN_DRV_1BIT,
			     31, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(159, "XNFWE", UNIPHIER_PIN_IECTRL_NONE,
			     32, UNIPHIER_PIN_DRV_1BIT,
			     32, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(160, "NFALE", UNIPHIER_PIN_IECTRL_NONE,
			     33, UNIPHIER_PIN_DRV_1BIT,
			     33, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(161, "NFCLE", UNIPHIER_PIN_IECTRL_NONE,
			     34, UNIPHIER_PIN_DRV_1BIT,
			     34, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(162, "XNFWP", UNIPHIER_PIN_IECTRL_NONE,
			     35, UNIPHIER_PIN_DRV_1BIT,
			     35, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(163, "XNFCE0", UNIPHIER_PIN_IECTRL_NONE,
			     36, UNIPHIER_PIN_DRV_1BIT,
			     36, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(164, "NANDRYBY0", UNIPHIER_PIN_IECTRL_NONE,
			     37, UNIPHIER_PIN_DRV_1BIT,
			     37, UNIPHIER_PIN_PULL_UP),
	/* dedicated pins */
	UNIPHIER_PINCTRL_PIN(165, "ED0", -1,
			     0, UNIPHIER_PIN_DRV_1BIT,
			     0, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(166, "ED1", -1,
			     1, UNIPHIER_PIN_DRV_1BIT,
			     1, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(167, "ED2", -1,
			     2, UNIPHIER_PIN_DRV_1BIT,
			     2, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(168, "ED3", -1,
			     3, UNIPHIER_PIN_DRV_1BIT,
			     3, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(169, "ED4", -1,
			     4, UNIPHIER_PIN_DRV_1BIT,
			     4, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(170, "ED5", -1,
			     5, UNIPHIER_PIN_DRV_1BIT,
			     5, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(171, "ED6", -1,
			     6, UNIPHIER_PIN_DRV_1BIT,
			     6, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(172, "ED7", -1,
			     7, UNIPHIER_PIN_DRV_1BIT,
			     7, UNIPHIER_PIN_PULL_DOWN),
	UNIPHIER_PINCTRL_PIN(173, "ERXW", -1,
			     26, UNIPHIER_PIN_DRV_1BIT,
			     26, UNIPHIER_PIN_PULL_UP),
	UNIPHIER_PINCTRL_PIN(174, "XECS1", -1,
			     30, UNIPHIER_PIN_DRV_1BIT,
			     30, UNIPHIER_PIN_PULL_UP),
};

static const unsigned emmc_pins[] = {21, 22, 23, 24, 25, 26, 27};
static const int emmc_muxvals[] = {0, 1, 1, 1, 1, 1, 1};
static const unsigned emmc_dat8_pins[] = {28, 29, 30, 31};
static const int emmc_dat8_muxvals[] = {1, 1, 1, 1};
static const unsigned ether_mii_pins[] = {32, 33, 34, 35, 36, 37, 38, 39, 40,
					  41, 42, 43, 136, 137, 138, 139, 140,
					  141, 142};
static const int ether_mii_muxvals[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					4, 4, 4, 4, 4, 4, 4};
static const unsigned ether_rmii_pins[] = {32, 33, 34, 35, 36, 37, 38, 39, 40,
					   41, 42, 43};
static const int ether_rmii_muxvals[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static const unsigned i2c0_pins[] = {102, 103};
static const int i2c0_muxvals[] = {0, 0};
static const unsigned i2c1_pins[] = {104, 105};
static const int i2c1_muxvals[] = {0, 0};
static const unsigned i2c2_pins[] = {108, 109};
static const int i2c2_muxvals[] = {2, 2};
static const unsigned i2c3_pins[] = {108, 109};
static const int i2c3_muxvals[] = {3, 3};
static const unsigned nand_pins[] = {24, 25, 26, 27, 28, 29, 30, 31, 158, 159,
				     160, 161, 162, 163, 164};
static const int nand_muxvals[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static const unsigned nand_cs1_pins[] = {22, 23};
static const int nand_cs1_muxvals[] = {0, 0};
static const unsigned sd_pins[] = {44, 45, 46, 47, 48, 49, 50, 51, 52};
static const int sd_muxvals[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
static const unsigned spi0_pins[] = {135, 136, 137, 138};
static const int spi0_muxvals[] = {12, 12, 12, 12};
static const unsigned system_bus_pins[] = {16, 17, 18, 19, 20, 165, 166, 167,
					   168, 169, 170, 171, 172, 173};
static const int system_bus_muxvals[] = {0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1,
					 -1, -1, -1};
static const unsigned system_bus_cs0_pins[] = {155};
static const int system_bus_cs0_muxvals[] = {1};
static const unsigned system_bus_cs1_pins[] = {174};
static const int system_bus_cs1_muxvals[] = {-1};
static const unsigned system_bus_cs2_pins[] = {64};
static const int system_bus_cs2_muxvals[] = {1};
static const unsigned system_bus_cs3_pins[] = {156};
static const int system_bus_cs3_muxvals[] = {1};
static const unsigned uart0_pins[] = {85, 88};
static const int uart0_muxvals[] = {1, 1};
static const unsigned uart0_ctsrts_pins[] = {86, 87, 89};
static const int uart0_ctsrts_muxvals[] = {1, 1, 1};
static const unsigned uart1_pins[] = {155, 156};
static const int uart1_muxvals[] = {13, 13};
static const unsigned uart1b_pins[] = {69, 70};
static const int uart1b_muxvals[] = {23, 23};
static const unsigned uart2_pins[] = {128, 129};
static const int uart2_muxvals[] = {13, 13};
static const unsigned uart3_pins[] = {110, 111};
static const int uart3_muxvals[] = {1, 1};
static const unsigned usb0_pins[] = {53, 54};
static const int usb0_muxvals[] = {0, 0};
static const unsigned usb1_pins[] = {55, 56};
static const int usb1_muxvals[] = {0, 0};
static const unsigned usb2_pins[] = {155, 156};
static const int usb2_muxvals[] = {4, 4};
static const unsigned usb2b_pins[] = {67, 68};
static const int usb2b_muxvals[] = {23, 23};
static const unsigned int gpio_range_pins[] = {
	135, 136, 137, 138, 139, 140, 141, 142,	/* PORT0x */
	143, 144, 145, 146, 147, 148, 149, 150,	/* PORT1x */
	151, 152, 153, 154, 155, 156, 157, 0,	/* PORT2x */
	1, 2, 3, 4, 5, 120, 121, 122,		/* PORT3x */
	24, 25, 26, 27, 28, 29, 30, 31,		/* PORT4x */
	40, 41, 42, 43, 44, 45, 46, 47,		/* PORT5x */
	48, 49, 50, 51, 52, 53, 54, 55,		/* PORT6x */
	56, 85, 84, 59, 82, 61, 64, 65,		/* PORT7x */
	8, 9, 10, 11, 12, 13, 14, 15,		/* PORT8x */
	66, 67, 68, 69, 70, 71, 72, 73,		/* PORT9x */
	74, 75, 89, 86, 78, 79, 80, 81,		/* PORT10x */
	60, 83, 58, 57, 88, 87, 77, 76,		/* PORT11x */
	90, 91, 92, 93, 94, 95, 96, 97,		/* PORT12x */
	98, 99, 100, 6, 101, 114, 115, 116,	/* PORT13x */
	103, 108, 21, 22, 23, 117, 118, 119,	/* PORT14x */
	151, 123, 124, 125, 126, 127, 128, 129,	/* XIRQ0-7 */
	130, 131, 132, 133, 62, 7, 134, 63,   /* XIRQ8-12, PORT165, XIRQ14-15 */
};

static const struct uniphier_pinctrl_group uniphier_ld4_groups[] = {
	UNIPHIER_PINCTRL_GROUP(emmc),
	UNIPHIER_PINCTRL_GROUP(emmc_dat8),
	UNIPHIER_PINCTRL_GROUP(ether_mii),
	UNIPHIER_PINCTRL_GROUP(ether_rmii),
	UNIPHIER_PINCTRL_GROUP(i2c0),
	UNIPHIER_PINCTRL_GROUP(i2c1),
	UNIPHIER_PINCTRL_GROUP(i2c2),
	UNIPHIER_PINCTRL_GROUP(i2c3),
	UNIPHIER_PINCTRL_GROUP(nand),
	UNIPHIER_PINCTRL_GROUP(nand_cs1),
	UNIPHIER_PINCTRL_GROUP(sd),
	UNIPHIER_PINCTRL_GROUP(spi0),
	UNIPHIER_PINCTRL_GROUP(system_bus),
	UNIPHIER_PINCTRL_GROUP(system_bus_cs0),
	UNIPHIER_PINCTRL_GROUP(system_bus_cs1),
	UNIPHIER_PINCTRL_GROUP(system_bus_cs2),
	UNIPHIER_PINCTRL_GROUP(system_bus_cs3),
	UNIPHIER_PINCTRL_GROUP(uart0),
	UNIPHIER_PINCTRL_GROUP(uart0_ctsrts),
	UNIPHIER_PINCTRL_GROUP(uart1),
	UNIPHIER_PINCTRL_GROUP(uart1b),
	UNIPHIER_PINCTRL_GROUP(uart2),
	UNIPHIER_PINCTRL_GROUP(uart3),
	UNIPHIER_PINCTRL_GROUP(usb0),
	UNIPHIER_PINCTRL_GROUP(usb1),
	UNIPHIER_PINCTRL_GROUP(usb2),
	UNIPHIER_PINCTRL_GROUP(usb2b),
	UNIPHIER_PINCTRL_GROUP_GPIO(gpio_range),
};

static const char * const emmc_groups[] = {"emmc", "emmc_dat8"};
static const char * const ether_mii_groups[] = {"ether_mii"};
static const char * const ether_rmii_groups[] = {"ether_rmii"};
static const char * const i2c0_groups[] = {"i2c0"};
static const char * const i2c1_groups[] = {"i2c1"};
static const char * const i2c2_groups[] = {"i2c2"};
static const char * const i2c3_groups[] = {"i2c3"};
static const char * const nand_groups[] = {"nand", "nand_cs1"};
static const char * const sd_groups[] = {"sd"};
static const char * const spi0_groups[] = {"spi0"};
static const char * const system_bus_groups[] = {"system_bus",
						 "system_bus_cs0",
						 "system_bus_cs1",
						 "system_bus_cs2",
						 "system_bus_cs3"};
static const char * const uart0_groups[] = {"uart0", "uart0_ctsrts"};
static const char * const uart1_groups[] = {"uart1", "uart1b"};
static const char * const uart2_groups[] = {"uart2"};
static const char * const uart3_groups[] = {"uart3"};
static const char * const usb0_groups[] = {"usb0"};
static const char * const usb1_groups[] = {"usb1"};
static const char * const usb2_groups[] = {"usb2", "usb2b"};

static const struct uniphier_pinmux_function uniphier_ld4_functions[] = {
	UNIPHIER_PINMUX_FUNCTION(emmc),
	UNIPHIER_PINMUX_FUNCTION(ether_mii),
	UNIPHIER_PINMUX_FUNCTION(ether_rmii),
	UNIPHIER_PINMUX_FUNCTION(i2c0),
	UNIPHIER_PINMUX_FUNCTION(i2c1),
	UNIPHIER_PINMUX_FUNCTION(i2c2),
	UNIPHIER_PINMUX_FUNCTION(i2c3),
	UNIPHIER_PINMUX_FUNCTION(nand),
	UNIPHIER_PINMUX_FUNCTION(sd),
	UNIPHIER_PINMUX_FUNCTION(spi0),
	UNIPHIER_PINMUX_FUNCTION(system_bus),
	UNIPHIER_PINMUX_FUNCTION(uart0),
	UNIPHIER_PINMUX_FUNCTION(uart1),
	UNIPHIER_PINMUX_FUNCTION(uart2),
	UNIPHIER_PINMUX_FUNCTION(uart3),
	UNIPHIER_PINMUX_FUNCTION(usb0),
	UNIPHIER_PINMUX_FUNCTION(usb1),
	UNIPHIER_PINMUX_FUNCTION(usb2),
};

static int uniphier_ld4_get_gpio_muxval(unsigned int pin,
					unsigned int gpio_offset)
{
	switch (gpio_offset) {
	case 0 ... 22:		/* PORT00-PORT26 */
	case 121 ... 131:	/* XIRQ1-XIRQ11 */
	case 134:		/* XIRQ14 */
		return 0;
	case 120:		/* XIRQ0 */
	case 132:		/* XIRQ12 */
	case 135:		/* XIRQ15 */
		return 14;
	default:
		return 15;
	}
}

static struct uniphier_pinctrl_socdata uniphier_ld4_pindata = {
	.pins = uniphier_ld4_pins,
	.npins = ARRAY_SIZE(uniphier_ld4_pins),
	.groups = uniphier_ld4_groups,
	.groups_count = ARRAY_SIZE(uniphier_ld4_groups),
	.functions = uniphier_ld4_functions,
	.functions_count = ARRAY_SIZE(uniphier_ld4_functions),
	.get_gpio_muxval = uniphier_ld4_get_gpio_muxval,
	.caps = 0,
};

static int uniphier_ld4_pinctrl_probe(struct platform_device *pdev)
{
	return uniphier_pinctrl_probe(pdev, &uniphier_ld4_pindata);
}

static const struct of_device_id uniphier_ld4_pinctrl_match[] = {
	{ .compatible = "socionext,uniphier-ld4-pinctrl" },
	{ /* sentinel */ }
};

static struct platform_driver uniphier_ld4_pinctrl_driver = {
	.probe = uniphier_ld4_pinctrl_probe,
	.driver = {
		.name = "uniphier-ld4-pinctrl",
		.of_match_table = uniphier_ld4_pinctrl_match,
		.pm = &uniphier_pinctrl_pm_ops,
	},
};
builtin_platform_driver(uniphier_ld4_pinctrl_driver);
