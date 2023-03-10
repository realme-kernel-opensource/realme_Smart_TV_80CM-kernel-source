/* SPDX-License-Identifier: GPL-2.0 */

#ifndef __MACH_SPI_H_
#define __MACH_SPI_H_

/*
 * struct spi_imx_master - device.platform_data for SPI controller devices.
 * @chipselect: Array of chipselects for this master or NULL.  Numbers >= 0
 *              mean GPIO pins, -ENOENT means internal CSPI chipselect
 *              matching the position in the array.  E.g., if chipselect[1] =
 *              -ENOENT then a SPI slave using chip select 1 will use the
 *              native SS1 line of the CSPI.  Omitting the array will use
 *              all native chip selects.

 *              Normally you want to use gpio based chip selects as the CSPI
 *              module tries to be intelligent about when to assert the
 *              chipselect:  The CSPI module deasserts the chipselect once it
 *              runs out of input data.  The other problem is that it is not
 *              possible to mix between high active and low active chipselects
 *              on one single bus using the internal chipselects.
 *              Unfortunately, on some SoCs, Freescale decided to put some
 *              chipselects on dedicated pins which are not usable as gpios,
 *              so we have to support the internal chipselects.
 *
 * @num_chipselect: If @chipselect is specified, ARRAY_SIZE(chipselect),
 *                  otherwise the number of native chip selects.
 */
struct spi_imx_master {
	int	*chipselect;
	int	num_chipselect;
};

#endif /* __MACH_SPI_H_*/
