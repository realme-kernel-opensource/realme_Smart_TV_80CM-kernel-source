/*
 * STMicroelectronics hts221 sensor driver
 *
 * Copyright 2016 STMicroelectronics Inc.
 *
 * Lorenzo Bianconi <lorenzo.bianconi@st.com>
 *
 * Licensed under the GPL-2.
 */

#ifndef HTS221_H
#define HTS221_H

#define HTS221_DEV_NAME		"hts221"

#include <linux/iio/iio.h>

#define HTS221_DATA_SIZE	2

enum hts221_sensor_type {
	HTS221_SENSOR_H,
	HTS221_SENSOR_T,
	HTS221_SENSOR_MAX,
};

struct hts221_sensor {
	u8 cur_avg_idx;
	int slope, b_gen;
};

struct hts221_hw {
	const char *name;
	struct device *dev;
	struct regmap *regmap;

	struct iio_trigger *trig;
	int irq;

	struct hts221_sensor sensors[HTS221_SENSOR_MAX];

	bool enabled;
	u8 odr;
};

extern const struct dev_pm_ops hts221_pm_ops;

int hts221_probe(struct device *dev, int irq, const char *name,
		 struct regmap *regmap);
int hts221_set_enable(struct hts221_hw *hw, bool enable);
int hts221_allocate_buffers(struct hts221_hw *hw);
int hts221_allocate_trigger(struct hts221_hw *hw);

#endif /* HTS221_H */
