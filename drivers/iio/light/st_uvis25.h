/*
 * STMicroelectronics uvis25 sensor driver
 *
 * Copyright 2017 STMicroelectronics Inc.
 *
 * Lorenzo Bianconi <lorenzo.bianconi83@gmail.com>
 *
 * Licensed under the GPL-2.
 */

#ifndef ST_UVIS25_H
#define ST_UVIS25_H

#define ST_UVIS25_DEV_NAME		"uvis25"

#include <linux/iio/iio.h>

/**
 * struct st_uvis25_hw - ST UVIS25 sensor instance
 * @regmap: Register map of the device.
 * @trig: The trigger in use by the driver.
 * @enabled: Status of the sensor (false->off, true->on).
 * @irq: Device interrupt line (I2C or SPI).
 */
struct st_uvis25_hw {
	struct regmap *regmap;

	struct iio_trigger *trig;
	bool enabled;
	int irq;
};

extern const struct dev_pm_ops st_uvis25_pm_ops;

int st_uvis25_probe(struct device *dev, int irq, struct regmap *regmap);

#endif /* ST_UVIS25_H */
