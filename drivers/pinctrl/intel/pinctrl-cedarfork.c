// SPDX-License-Identifier: GPL-2.0
/*
 * Intel Cedar Fork PCH pinctrl/GPIO driver
 *
 * Copyright (C) 2017, Intel Corporation
 * Author: Mika Westerberg <mika.westerberg@linux.intel.com>
 */

#include <linux/acpi.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/pm.h>
#include <linux/pinctrl/pinctrl.h>

#include "pinctrl-intel.h"

#define CDF_PAD_OWN	0x020
#define CDF_PADCFGLOCK	0x0c0
#define CDF_HOSTSW_OWN	0x120
#define CDF_GPI_IS	0x200
#define CDF_GPI_IE	0x230

#define CDF_GPP(r, s, e)				\
	{						\
		.reg_num = (r),				\
		.base = (s),				\
		.size = ((e) - (s) + 1),		\
	}

#define CDF_COMMUNITY(b, s, e, g)			\
	{						\
		.barno = (b),				\
		.padown_offset = CDF_PAD_OWN,		\
		.padcfglock_offset = CDF_PADCFGLOCK,	\
		.hostown_offset = CDF_HOSTSW_OWN,	\
		.is_offset = CDF_GPI_IS,		\
		.ie_offset = CDF_GPI_IE,		\
		.pin_base = (s),			\
		.npins = ((e) - (s) + 1),		\
		.gpps = (g),				\
		.ngpps = ARRAY_SIZE(g),			\
	}

/* Cedar Fork PCH */
static const struct pinctrl_pin_desc cdf_pins[] = {
	/* WEST2 */
	PINCTRL_PIN(0, "GBE_SDP_TIMESYNC0_S2N"),
	PINCTRL_PIN(1, "GBE_SDP_TIMESYNC1_S2N"),
	PINCTRL_PIN(2, "GBE_SDP_TIMESYNC2_S2N"),
	PINCTRL_PIN(3, "GBE_SDP_TIMESYNC3_S2N"),
	PINCTRL_PIN(4, "GBE0_I2C_CLK"),
	PINCTRL_PIN(5, "GBE0_I2C_DATA"),
	PINCTRL_PIN(6, "GBE1_I2C_CLK"),
	PINCTRL_PIN(7, "GBE1_I2C_DATA"),
	PINCTRL_PIN(8, "GBE2_I2C_CLK"),
	PINCTRL_PIN(9, "GBE2_I2C_DATA"),
	PINCTRL_PIN(10, "GBE3_I2C_CLK"),
	PINCTRL_PIN(11, "GBE3_I2C_DATA"),
	PINCTRL_PIN(12, "GBE0_LED0"),
	PINCTRL_PIN(13, "GBE0_LED1"),
	PINCTRL_PIN(14, "GBE0_LED2"),
	PINCTRL_PIN(15, "GBE1_LED0"),
	PINCTRL_PIN(16, "GBE1_LED1"),
	PINCTRL_PIN(17, "GBE1_LED2"),
	PINCTRL_PIN(18, "GBE2_LED0"),
	PINCTRL_PIN(19, "GBE2_LED1"),
	PINCTRL_PIN(20, "GBE2_LED2"),
	PINCTRL_PIN(21, "GBE3_LED0"),
	PINCTRL_PIN(22, "GBE3_LED1"),
	PINCTRL_PIN(23, "GBE3_LED2"),
	/* WEST3 */
	PINCTRL_PIN(24, "NCSI_RXD0"),
	PINCTRL_PIN(25, "NCSI_CLK_IN"),
	PINCTRL_PIN(26, "NCSI_RXD1"),
	PINCTRL_PIN(27, "NCSI_CRS_DV"),
	PINCTRL_PIN(28, "NCSI_ARB_IN"),
	PINCTRL_PIN(29, "NCSI_TX_EN"),
	PINCTRL_PIN(30, "NCSI_TXD0"),
	PINCTRL_PIN(31, "NCSI_TXD1"),
	PINCTRL_PIN(32, "NCSI_ARB_OUT"),
	PINCTRL_PIN(33, "GBE_SMB_CLK"),
	PINCTRL_PIN(34, "GBE_SMB_DATA"),
	PINCTRL_PIN(35, "GBE_SMB_ALRT_N"),
	PINCTRL_PIN(36, "THERMTRIP_N"),
	PINCTRL_PIN(37, "PCHHOT_N"),
	PINCTRL_PIN(38, "ERROR0_N"),
	PINCTRL_PIN(39, "ERROR1_N"),
	PINCTRL_PIN(40, "ERROR2_N"),
	PINCTRL_PIN(41, "MSMI_N"),
	PINCTRL_PIN(42, "CATERR_N"),
	PINCTRL_PIN(43, "MEMTRIP_N"),
	PINCTRL_PIN(44, "UART0_RXD"),
	PINCTRL_PIN(45, "UART0_TXD"),
	PINCTRL_PIN(46, "UART1_RXD"),
	PINCTRL_PIN(47, "UART1_TXD"),
	/* WEST01 */
	PINCTRL_PIN(48, "GBE_GPIO13"),
	PINCTRL_PIN(49, "AUX_PWR"),
	PINCTRL_PIN(50, "CPU_GP_2"),
	PINCTRL_PIN(51, "CPU_GP_3"),
	PINCTRL_PIN(52, "FAN_PWM_0"),
	PINCTRL_PIN(53, "FAN_PWM_1"),
	PINCTRL_PIN(54, "FAN_PWM_2"),
	PINCTRL_PIN(55, "FAN_PWM_3"),
	PINCTRL_PIN(56, "FAN_TACH_0"),
	PINCTRL_PIN(57, "FAN_TACH_1"),
	PINCTRL_PIN(58, "FAN_TACH_2"),
	PINCTRL_PIN(59, "FAN_TACH_3"),
	PINCTRL_PIN(60, "ME_SMB0_CLK"),
	PINCTRL_PIN(61, "ME_SMB0_DATA"),
	PINCTRL_PIN(62, "ME_SMB0_ALRT_N"),
	PINCTRL_PIN(63, "ME_SMB1_CLK"),
	PINCTRL_PIN(64, "ME_SMB1_DATA"),
	PINCTRL_PIN(65, "ME_SMB1_ALRT_N"),
	PINCTRL_PIN(66, "ME_SMB2_CLK"),
	PINCTRL_PIN(67, "ME_SMB2_DATA"),
	PINCTRL_PIN(68, "ME_SMB2_ALRT_N"),
	PINCTRL_PIN(69, "GBE_MNG_I2C_CLK"),
	PINCTRL_PIN(70, "GBE_MNG_I2C_DATA"),
	/* WEST5 */
	PINCTRL_PIN(71, "IE_UART_RXD"),
	PINCTRL_PIN(72, "IE_UART_TXD"),
	PINCTRL_PIN(73, "VPP_SMB_CLK"),
	PINCTRL_PIN(74, "VPP_SMB_DATA"),
	PINCTRL_PIN(75, "VPP_SMB_ALRT_N"),
	PINCTRL_PIN(76, "PCIE_CLKREQ0_N"),
	PINCTRL_PIN(77, "PCIE_CLKREQ1_N"),
	PINCTRL_PIN(78, "PCIE_CLKREQ2_N"),
	PINCTRL_PIN(79, "PCIE_CLKREQ3_N"),
	PINCTRL_PIN(80, "PCIE_CLKREQ4_N"),
	PINCTRL_PIN(81, "PCIE_CLKREQ5_N"),
	PINCTRL_PIN(82, "PCIE_CLKREQ6_N"),
	PINCTRL_PIN(83, "PCIE_CLKREQ7_N"),
	PINCTRL_PIN(84, "PCIE_CLKREQ8_N"),
	PINCTRL_PIN(85, "PCIE_CLKREQ9_N"),
	PINCTRL_PIN(86, "FLEX_CLK_SE0"),
	PINCTRL_PIN(87, "FLEX_CLK_SE1"),
	PINCTRL_PIN(88, "FLEX_CLK1_50"),
	PINCTRL_PIN(89, "FLEX_CLK2_50"),
	PINCTRL_PIN(90, "FLEX_CLK_125"),
	/* WESTC */
	PINCTRL_PIN(91, "TCK_PCH"),
	PINCTRL_PIN(92, "JTAGX_PCH"),
	PINCTRL_PIN(93, "TRST_N_PCH"),
	PINCTRL_PIN(94, "TMS_PCH"),
	PINCTRL_PIN(95, "TDI_PCH"),
	PINCTRL_PIN(96, "TDO_PCH"),
	/* WESTC_DFX */
	PINCTRL_PIN(97, "CX_PRDY_N"),
	PINCTRL_PIN(98, "CX_PREQ_N"),
	PINCTRL_PIN(99, "CPU_FBREAK_OUT_N"),
	PINCTRL_PIN(100, "TRIGGER0_N"),
	PINCTRL_PIN(101, "TRIGGER1_N"),
	/* WESTA */
	PINCTRL_PIN(102, "DBG_PTI_CLK0"),
	PINCTRL_PIN(103, "DBG_PTI_CLK3"),
	PINCTRL_PIN(104, "DBG_PTI_DATA0"),
	PINCTRL_PIN(105, "DBG_PTI_DATA1"),
	PINCTRL_PIN(106, "DBG_PTI_DATA2"),
	PINCTRL_PIN(107, "DBG_PTI_DATA3"),
	PINCTRL_PIN(108, "DBG_PTI_DATA4"),
	PINCTRL_PIN(109, "DBG_PTI_DATA5"),
	PINCTRL_PIN(110, "DBG_PTI_DATA6"),
	PINCTRL_PIN(111, "DBG_PTI_DATA7"),
	/* WESTB */
	PINCTRL_PIN(112, "DBG_PTI_DATA8"),
	PINCTRL_PIN(113, "DBG_PTI_DATA9"),
	PINCTRL_PIN(114, "DBG_PTI_DATA10"),
	PINCTRL_PIN(115, "DBG_PTI_DATA11"),
	PINCTRL_PIN(116, "DBG_PTI_DATA12"),
	PINCTRL_PIN(117, "DBG_PTI_DATA13"),
	PINCTRL_PIN(118, "DBG_PTI_DATA14"),
	PINCTRL_PIN(119, "DBG_PTI_DATA15"),
	PINCTRL_PIN(120, "DBG_SPARE0"),
	PINCTRL_PIN(121, "DBG_SPARE1"),
	PINCTRL_PIN(122, "DBG_SPARE2"),
	PINCTRL_PIN(123, "DBG_SPARE3"),
	/* WESTD */
	PINCTRL_PIN(124, "CPU_PWR_GOOD"),
	PINCTRL_PIN(125, "PLTRST_CPU_N"),
	PINCTRL_PIN(126, "NAC_RESET_NAC_N"),
	PINCTRL_PIN(127, "PCH_SBLINK_RX"),
	PINCTRL_PIN(128, "PCH_SBLINK_TX"),
	PINCTRL_PIN(129, "PMSYNC_CLK"),
	PINCTRL_PIN(130, "CPU_ERR0_N"),
	PINCTRL_PIN(131, "CPU_ERR1_N"),
	PINCTRL_PIN(132, "CPU_ERR2_N"),
	PINCTRL_PIN(133, "CPU_THERMTRIP_N"),
	PINCTRL_PIN(134, "CPU_MSMI_N"),
	PINCTRL_PIN(135, "CPU_CATERR_N"),
	PINCTRL_PIN(136, "CPU_MEMTRIP_N"),
	PINCTRL_PIN(137, "NAC_GR_N"),
	PINCTRL_PIN(138, "NAC_XTAL_VALID"),
	PINCTRL_PIN(139, "NAC_WAKE_N"),
	PINCTRL_PIN(140, "NAC_SBLINK_CLK_S2N"),
	PINCTRL_PIN(141, "NAC_SBLINK_N2S"),
	PINCTRL_PIN(142, "NAC_SBLINK_S2N"),
	PINCTRL_PIN(143, "NAC_SBLINK_CLK_N2S"),
	/* WESTD_PECI */
	PINCTRL_PIN(144, "ME_PECI"),
	/* WESTF */
	PINCTRL_PIN(145, "NAC_RMII_CLK"),
	PINCTRL_PIN(146, "NAC_RGMII_CLK"),
	PINCTRL_PIN(147, "NAC_SPARE0"),
	PINCTRL_PIN(148, "NAC_SPARE1"),
	PINCTRL_PIN(149, "NAC_SPARE2"),
	PINCTRL_PIN(150, "NAC_INIT_SX_WAKE_N"),
	PINCTRL_PIN(151, "NAC_GBE_GPIO0_S2N"),
	PINCTRL_PIN(152, "NAC_GBE_GPIO1_S2N"),
	PINCTRL_PIN(153, "NAC_GBE_GPIO2_S2N"),
	PINCTRL_PIN(154, "NAC_GBE_GPIO3_S2N"),
	PINCTRL_PIN(155, "NAC_NCSI_RXD0"),
	PINCTRL_PIN(156, "NAC_NCSI_CLK_IN"),
	PINCTRL_PIN(157, "NAC_NCSI_RXD1"),
	PINCTRL_PIN(158, "NAC_NCSI_CRS_DV"),
	PINCTRL_PIN(159, "NAC_NCSI_ARB_IN"),
	PINCTRL_PIN(160, "NAC_NCSI_TX_EN"),
	PINCTRL_PIN(161, "NAC_NCSI_TXD0"),
	PINCTRL_PIN(162, "NAC_NCSI_TXD1"),
	PINCTRL_PIN(163, "NAC_NCSI_ARB_OUT"),
	PINCTRL_PIN(164, "NAC_NCSI_OE_N"),
	PINCTRL_PIN(165, "NAC_GBE_SMB_CLK"),
	PINCTRL_PIN(166, "NAC_GBE_SMB_DATA"),
	PINCTRL_PIN(167, "NAC_GBE_SMB_ALRT_N"),
	/* EAST2 */
	PINCTRL_PIN(168, "USB_OC0_N"),
	PINCTRL_PIN(169, "GBE_GPIO0"),
	PINCTRL_PIN(170, "GBE_GPIO1"),
	PINCTRL_PIN(171, "GBE_GPIO2"),
	PINCTRL_PIN(172, "GBE_GPIO3"),
	PINCTRL_PIN(173, "GBE_GPIO4"),
	PINCTRL_PIN(174, "GBE_GPIO5"),
	PINCTRL_PIN(175, "GBE_GPIO6"),
	PINCTRL_PIN(176, "GBE_GPIO7"),
	PINCTRL_PIN(177, "GBE_GPIO8"),
	PINCTRL_PIN(178, "GBE_GPIO9"),
	PINCTRL_PIN(179, "GBE_GPIO10"),
	PINCTRL_PIN(180, "GBE_GPIO11"),
	PINCTRL_PIN(181, "GBE_GPIO12"),
	PINCTRL_PIN(182, "PECI_SMB_DATA"),
	PINCTRL_PIN(183, "SATA0_LED_N"),
	PINCTRL_PIN(184, "SATA1_LED_N"),
	PINCTRL_PIN(185, "SATA_PDETECT0"),
	PINCTRL_PIN(186, "SATA_PDETECT1"),
	PINCTRL_PIN(187, "SATA0_SDOUT"),
	PINCTRL_PIN(188, "SATA1_SDOUT"),
	PINCTRL_PIN(189, "SATA2_LED_N"),
	PINCTRL_PIN(190, "SATA_PDETECT2"),
	PINCTRL_PIN(191, "SATA2_SDOUT"),
	/* EAST3 */
	PINCTRL_PIN(192, "ESPI_IO0"),
	PINCTRL_PIN(193, "ESPI_IO1"),
	PINCTRL_PIN(194, "ESPI_IO2"),
	PINCTRL_PIN(195, "ESPI_IO3"),
	PINCTRL_PIN(196, "ESPI_CLK"),
	PINCTRL_PIN(197, "ESPI_RST_N"),
	PINCTRL_PIN(198, "ESPI_CS0_N"),
	PINCTRL_PIN(199, "ESPI_ALRT0_N"),
	PINCTRL_PIN(200, "ESPI_CS1_N"),
	PINCTRL_PIN(201, "ESPI_ALRT1_N"),
	PINCTRL_PIN(202, "ESPI_CLK_LOOPBK"),
	/* EAST0 */
	PINCTRL_PIN(203, "SPI_CS0_N"),
	PINCTRL_PIN(204, "SPI_CS1_N"),
	PINCTRL_PIN(205, "SPI_MOSI_IO0"),
	PINCTRL_PIN(206, "SPI_MISO_IO1"),
	PINCTRL_PIN(207, "SPI_IO2"),
	PINCTRL_PIN(208, "SPI_IO3"),
	PINCTRL_PIN(209, "SPI_CLK"),
	PINCTRL_PIN(210, "SPI_CLK_LOOPBK"),
	PINCTRL_PIN(211, "SUSPWRDNACK"),
	PINCTRL_PIN(212, "PMU_SUSCLK"),
	PINCTRL_PIN(213, "ADR_COMPLETE"),
	PINCTRL_PIN(214, "ADR_TRIGGER_N"),
	PINCTRL_PIN(215, "PMU_SLP_S45_N"),
	PINCTRL_PIN(216, "PMU_SLP_S3_N"),
	PINCTRL_PIN(217, "PMU_WAKE_N"),
	PINCTRL_PIN(218, "PMU_PWRBTN_N"),
	PINCTRL_PIN(219, "PMU_RESETBUTTON_N"),
	PINCTRL_PIN(220, "PMU_PLTRST_N"),
	PINCTRL_PIN(221, "SUS_STAT_N"),
	PINCTRL_PIN(222, "PMU_I2C_CLK"),
	PINCTRL_PIN(223, "PMU_I2C_DATA"),
	PINCTRL_PIN(224, "PECI_SMB_CLK"),
	PINCTRL_PIN(225, "PECI_SMB_ALRT_N"),
	/* EMMC */
	PINCTRL_PIN(226, "EMMC_CMD"),
	PINCTRL_PIN(227, "EMMC_STROBE"),
	PINCTRL_PIN(228, "EMMC_CLK"),
	PINCTRL_PIN(229, "EMMC_D0"),
	PINCTRL_PIN(230, "EMMC_D1"),
	PINCTRL_PIN(231, "EMMC_D2"),
	PINCTRL_PIN(232, "EMMC_D3"),
	PINCTRL_PIN(233, "EMMC_D4"),
	PINCTRL_PIN(234, "EMMC_D5"),
	PINCTRL_PIN(235, "EMMC_D6"),
	PINCTRL_PIN(236, "EMMC_D7"),
};

static const struct intel_padgroup cdf_community0_gpps[] = {
	CDF_GPP(0, 0, 23),	/* WEST2 */
	CDF_GPP(1, 24, 47),	/* WEST3 */
	CDF_GPP(2, 48, 70),	/* WEST01 */
	CDF_GPP(3, 71, 90),	/* WEST5 */
	CDF_GPP(4, 91, 96),	/* WESTC */
	CDF_GPP(5, 97, 101),	/* WESTC_DFX */
	CDF_GPP(6, 102, 111),	/* WESTA */
	CDF_GPP(7, 112, 123),	/* WESTB */
	CDF_GPP(8, 124, 143),	/* WESTD */
	CDF_GPP(9, 144, 144),	/* WESTD_PECI */
	CDF_GPP(10, 145, 167),	/* WESTF */
};

static const struct intel_padgroup cdf_community1_gpps[] = {
	CDF_GPP(0, 168, 191),	/* EAST2 */
	CDF_GPP(1, 192, 202),	/* EAST3 */
	CDF_GPP(2, 203, 225),	/* EAST0 */
	CDF_GPP(3, 226, 236),	/* EMMC */
};

static const struct intel_community cdf_communities[] = {
	CDF_COMMUNITY(0, 0, 167, cdf_community0_gpps),		/* West */
	CDF_COMMUNITY(1, 168, 236, cdf_community1_gpps),	/* East */
};

static const struct intel_pinctrl_soc_data cdf_soc_data = {
	.pins = cdf_pins,
	.npins = ARRAY_SIZE(cdf_pins),
	.communities = cdf_communities,
	.ncommunities = ARRAY_SIZE(cdf_communities),
};

static int cdf_pinctrl_probe(struct platform_device *pdev)
{
	return intel_pinctrl_probe(pdev, &cdf_soc_data);
}

static const struct dev_pm_ops cdf_pinctrl_pm_ops = {
	SET_LATE_SYSTEM_SLEEP_PM_OPS(intel_pinctrl_suspend,
				     intel_pinctrl_resume)
};

static const struct acpi_device_id cdf_pinctrl_acpi_match[] = {
	{ "INTC3001" },
	{ }
};
MODULE_DEVICE_TABLE(acpi, cdf_pinctrl_acpi_match);

static struct platform_driver cdf_pinctrl_driver = {
	.probe = cdf_pinctrl_probe,
	.driver = {
		.name = "cedarfork-pinctrl",
		.acpi_match_table = cdf_pinctrl_acpi_match,
		.pm = &cdf_pinctrl_pm_ops,
	},
};

static int __init cdf_pinctrl_init(void)
{
	return platform_driver_register(&cdf_pinctrl_driver);
}
subsys_initcall(cdf_pinctrl_init);

static void __exit cdf_pinctrl_exit(void)
{
	platform_driver_unregister(&cdf_pinctrl_driver);
}
module_exit(cdf_pinctrl_exit);

MODULE_AUTHOR("Mika Westerberg <mika.westerberg@linux.intel.com>");
MODULE_DESCRIPTION("Intel Cedar Fork PCH pinctrl/GPIO driver");
MODULE_LICENSE("GPL v2");
