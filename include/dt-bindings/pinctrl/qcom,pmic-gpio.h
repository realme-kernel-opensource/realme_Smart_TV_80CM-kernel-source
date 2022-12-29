/* SPDX-License-Identifier: GPL-2.0 */
/*
 * This header provides constants for the Qualcomm PMIC GPIO binding.
 */

#ifndef _DT_BINDINGS_PINCTRL_QCOM_PMIC_GPIO_H
#define _DT_BINDINGS_PINCTRL_QCOM_PMIC_GPIO_H

#define PMIC_GPIO_PULL_UP_30		0
#define PMIC_GPIO_PULL_UP_1P5		1
#define PMIC_GPIO_PULL_UP_31P5		2
#define PMIC_GPIO_PULL_UP_1P5_30	3

#define PMIC_GPIO_STRENGTH_NO		0
#define PMIC_GPIO_STRENGTH_HIGH		1
#define PMIC_GPIO_STRENGTH_MED		2
#define PMIC_GPIO_STRENGTH_LOW		3

/*
 * Note: PM8018 GPIO3 and GPIO4 are supporting
 * only S3 and L2 options (1.8V)
 */
#define PM8018_GPIO_L6			0
#define PM8018_GPIO_L5			1
#define PM8018_GPIO_S3			2
#define PM8018_GPIO_L14			3
#define PM8018_GPIO_L2			4
#define PM8018_GPIO_L4			5
#define PM8018_GPIO_VDD			6

/*
 * Note: PM8038 GPIO7 and GPIO8 are supporting
 * only L11 and L4 options (1.8V)
 */
#define PM8038_GPIO_VPH			0
#define PM8038_GPIO_BB			1
#define PM8038_GPIO_L11			2
#define PM8038_GPIO_L15			3
#define PM8038_GPIO_L4			4
#define PM8038_GPIO_L3			5
#define PM8038_GPIO_L17			6

#define PM8058_GPIO_VPH			0
#define PM8058_GPIO_BB			1
#define PM8058_GPIO_S3			2
#define PM8058_GPIO_L3			3
#define PM8058_GPIO_L7			4
#define PM8058_GPIO_L6			5
#define PM8058_GPIO_L5			6
#define PM8058_GPIO_L2			7

/*
 * Note: PM8916 GPIO1 and GPIO2 are supporting
 * only L2(1.15V) and L5(1.8V) options
 */
#define PM8916_GPIO_VPH			0
#define PM8916_GPIO_L2			2
#define PM8916_GPIO_L5			3

#define PM8917_GPIO_VPH			0
#define PM8917_GPIO_S4			2
#define PM8917_GPIO_L15			3
#define PM8917_GPIO_L4			4
#define PM8917_GPIO_L3			5
#define PM8917_GPIO_L17			6

#define PM8921_GPIO_VPH			0
#define PM8921_GPIO_BB			1
#define PM8921_GPIO_S4			2
#define PM8921_GPIO_L15			3
#define PM8921_GPIO_L4			4
#define PM8921_GPIO_L3			5
#define PM8921_GPIO_L17			6

/*
 * Note: PM8941 gpios from 15 to 18 are supporting
 * only S3 and L6 options (1.8V)
 */
#define PM8941_GPIO_VPH			0
#define PM8941_GPIO_L1			1
#define PM8941_GPIO_S3			2
#define PM8941_GPIO_L6			3

/*
 * Note: PMA8084 gpios from 15 to 18 are supporting
 * only S4 and L6 options (1.8V)
 */
#define PMA8084_GPIO_VPH		0
#define PMA8084_GPIO_L1			1
#define PMA8084_GPIO_S4			2
#define PMA8084_GPIO_L6			3

#define PM8994_GPIO_VPH			0
#define PM8994_GPIO_S4			2
#define PM8994_GPIO_L12			3

/* To be used with "function" */
#define PMIC_GPIO_FUNC_NORMAL		"normal"
#define PMIC_GPIO_FUNC_PAIRED		"paired"
#define PMIC_GPIO_FUNC_FUNC1		"func1"
#define PMIC_GPIO_FUNC_FUNC2		"func2"
#define PMIC_GPIO_FUNC_FUNC3		"func3"
#define PMIC_GPIO_FUNC_FUNC4		"func4"
#define PMIC_GPIO_FUNC_DTEST1		"dtest1"
#define PMIC_GPIO_FUNC_DTEST2		"dtest2"
#define PMIC_GPIO_FUNC_DTEST3		"dtest3"
#define PMIC_GPIO_FUNC_DTEST4		"dtest4"

#define PM8038_GPIO1_2_LPG_DRV		PMIC_GPIO_FUNC_FUNC1
#define PM8038_GPIO3_5V_BOOST_EN	PMIC_GPIO_FUNC_FUNC1
#define PM8038_GPIO4_SSBI_ALT_CLK	PMIC_GPIO_FUNC_FUNC1
#define PM8038_GPIO5_6_EXT_REG_EN	PMIC_GPIO_FUNC_FUNC1
#define PM8038_GPIO10_11_EXT_REG_EN	PMIC_GPIO_FUNC_FUNC1
#define PM8038_GPIO6_7_CLK		PMIC_GPIO_FUNC_FUNC1
#define PM8038_GPIO9_BAT_ALRM_OUT	PMIC_GPIO_FUNC_FUNC1
#define PM8038_GPIO6_12_KYPD_DRV	PMIC_GPIO_FUNC_FUNC2

#define PM8058_GPIO7_8_MP3_CLK		PMIC_GPIO_FUNC_FUNC1
#define PM8058_GPIO7_8_BCLK_19P2MHZ	PMIC_GPIO_FUNC_FUNC2
#define PM8058_GPIO9_26_KYPD_DRV	PMIC_GPIO_FUNC_FUNC1
#define PM8058_GPIO21_23_UART_TX	PMIC_GPIO_FUNC_FUNC2
#define PM8058_GPIO24_26_LPG_DRV	PMIC_GPIO_FUNC_FUNC2
#define PM8058_GPIO33_BCLK_19P2MHZ	PMIC_GPIO_FUNC_FUNC1
#define PM8058_GPIO34_35_MP3_CLK	PMIC_GPIO_FUNC_FUNC1
#define PM8058_GPIO36_BCLK_19P2MHZ	PMIC_GPIO_FUNC_FUNC1
#define PM8058_GPIO37_UPL_OUT		PMIC_GPIO_FUNC_FUNC1
#define PM8058_GPIO37_UART_M_RX		PMIC_GPIO_FUNC_FUNC2
#define PM8058_GPIO38_XO_SLEEP_CLK	PMIC_GPIO_FUNC_FUNC1
#define PM8058_GPIO38_39_CLK_32KHZ	PMIC_GPIO_FUNC_FUNC2
#define PM8058_GPIO39_MP3_CLK		PMIC_GPIO_FUNC_FUNC1
#define PM8058_GPIO40_EXT_BB_EN		PMIC_GPIO_FUNC_FUNC1

#define PM8916_GPIO1_BAT_ALRM_OUT	PMIC_GPIO_FUNC_FUNC1
#define PM8916_GPIO1_KEYP_DRV		PMIC_GPIO_FUNC_FUNC2
#define PM8916_GPIO2_DIV_CLK		PMIC_GPIO_FUNC_FUNC1
#define PM8916_GPIO2_SLEEP_CLK		PMIC_GPIO_FUNC_FUNC2
#define PM8916_GPIO3_KEYP_DRV		PMIC_GPIO_FUNC_FUNC1
#define PM8916_GPIO4_KEYP_DRV		PMIC_GPIO_FUNC_FUNC2

#define PM8917_GPIO9_18_KEYP_DRV	PMIC_GPIO_FUNC_FUNC1
#define PM8917_GPIO20_BAT_ALRM_OUT	PMIC_GPIO_FUNC_FUNC1
#define PM8917_GPIO21_23_UART_TX	PMIC_GPIO_FUNC_FUNC2
#define PM8917_GPIO25_26_EXT_REG_EN	PMIC_GPIO_FUNC_FUNC1
#define PM8917_GPIO37_38_XO_SLEEP_CLK	PMIC_GPIO_FUNC_FUNC1
#define PM8917_GPIO37_38_MP3_CLK	PMIC_GPIO_FUNC_FUNC2

#define PM8941_GPIO9_14_KYPD_DRV	PMIC_GPIO_FUNC_FUNC1
#define PM8941_GPIO15_18_DIV_CLK	PMIC_GPIO_FUNC_FUNC1
#define PM8941_GPIO15_18_SLEEP_CLK	PMIC_GPIO_FUNC_FUNC2
#define PM8941_GPIO23_26_KYPD_DRV	PMIC_GPIO_FUNC_FUNC1
#define PM8941_GPIO23_26_LPG_DRV_HI	PMIC_GPIO_FUNC_FUNC2
#define PM8941_GPIO31_BAT_ALRM_OUT	PMIC_GPIO_FUNC_FUNC1
#define PM8941_GPIO33_36_LPG_DRV_3D	PMIC_GPIO_FUNC_FUNC1
#define PM8941_GPIO33_36_LPG_DRV_HI	PMIC_GPIO_FUNC_FUNC2

#define PMA8084_GPIO4_5_LPG_DRV		PMIC_GPIO_FUNC_FUNC1
#define PMA8084_GPIO7_10_LPG_DRV	PMIC_GPIO_FUNC_FUNC1
#define PMA8084_GPIO5_14_KEYP_DRV	PMIC_GPIO_FUNC_FUNC2
#define PMA8084_GPIO19_21_KEYP_DRV	PMIC_GPIO_FUNC_FUNC2
#define PMA8084_GPIO15_18_DIV_CLK	PMIC_GPIO_FUNC_FUNC1
#define PMA8084_GPIO15_18_SLEEP_CLK	PMIC_GPIO_FUNC_FUNC2
#define PMA8084_GPIO22_BAT_ALRM_OUT	PMIC_GPIO_FUNC_FUNC1

#endif
