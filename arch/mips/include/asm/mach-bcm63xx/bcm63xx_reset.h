/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __BCM63XX_RESET_H
#define __BCM63XX_RESET_H

enum bcm63xx_core_reset {
	BCM63XX_RESET_SPI,
	BCM63XX_RESET_ENET,
	BCM63XX_RESET_USBH,
	BCM63XX_RESET_USBD,
	BCM63XX_RESET_SAR,
	BCM63XX_RESET_DSL,
	BCM63XX_RESET_EPHY,
	BCM63XX_RESET_ENETSW,
	BCM63XX_RESET_PCM,
	BCM63XX_RESET_MPI,
	BCM63XX_RESET_PCIE,
	BCM63XX_RESET_PCIE_EXT,
};

void bcm63xx_core_set_reset(enum bcm63xx_core_reset, int reset);

#endif
