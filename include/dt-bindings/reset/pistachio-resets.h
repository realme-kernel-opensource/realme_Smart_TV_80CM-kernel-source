/* SPDX-License-Identifier: GPL-2.0 */
/*
 * This header provides constants for the reset controller
 * present in the Pistachio SoC
 */

#ifndef _PISTACHIO_RESETS_H
#define _PISTACHIO_RESETS_H

#define PISTACHIO_RESET_I2C0		0
#define PISTACHIO_RESET_I2C1		1
#define PISTACHIO_RESET_I2C2		2
#define PISTACHIO_RESET_I2C3		3
#define PISTACHIO_RESET_I2S_IN		4
#define PISTACHIO_RESET_PRL_OUT		5
#define PISTACHIO_RESET_SPDIF_OUT	6
#define PISTACHIO_RESET_SPI		7
#define PISTACHIO_RESET_PWM_PDM		8
#define PISTACHIO_RESET_UART0		9
#define PISTACHIO_RESET_UART1		10
#define PISTACHIO_RESET_QSPI		11
#define PISTACHIO_RESET_MDC		12
#define PISTACHIO_RESET_SDHOST		13
#define PISTACHIO_RESET_ETHERNET	14
#define PISTACHIO_RESET_IR		15
#define PISTACHIO_RESET_HASH		16
#define PISTACHIO_RESET_TIMER		17
#define PISTACHIO_RESET_I2S_OUT		18
#define PISTACHIO_RESET_SPDIF_IN	19
#define PISTACHIO_RESET_EVT		20
#define PISTACHIO_RESET_USB_H		21
#define PISTACHIO_RESET_USB_PR		22
#define PISTACHIO_RESET_USB_PHY_PR	23
#define PISTACHIO_RESET_USB_PHY_PON	24
#define PISTACHIO_RESET_MAX		24

#endif
