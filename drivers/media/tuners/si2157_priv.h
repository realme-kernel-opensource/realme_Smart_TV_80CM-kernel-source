/*
 * Silicon Labs Si2146/2147/2148/2157/2158 silicon tuner driver
 *
 * Copyright (C) 2014 Antti Palosaari <crope@iki.fi>
 *
 *    This program is free software; you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation; either version 2 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 */

#ifndef SI2157_PRIV_H
#define SI2157_PRIV_H

#include <linux/firmware.h>
#include <media/v4l2-mc.h>
#include "si2157.h"

/* state struct */
struct si2157_dev {
	struct mutex i2c_mutex;
	struct dvb_frontend *fe;
	bool active;
	bool inversion;
	u8 chiptype;
	u8 if_port;
	u32 if_frequency;
	struct delayed_work stat_work;

#if defined(CONFIG_MEDIA_CONTROLLER)
	struct media_device	*mdev;
	struct media_entity	ent;
	struct media_pad	pad[TUNER_NUM_PADS];
#endif

};

#define SI2157_CHIPTYPE_SI2157 0
#define SI2157_CHIPTYPE_SI2146 1
#define SI2157_CHIPTYPE_SI2141 2

/* firmware command struct */
#define SI2157_ARGLEN      30
struct si2157_cmd {
	u8 args[SI2157_ARGLEN];
	unsigned wlen;
	unsigned rlen;
};

#define SI2158_A20_FIRMWARE "dvb-tuner-si2158-a20-01.fw"
#define SI2141_A10_FIRMWARE "dvb-tuner-si2141-a10-01.fw"

#endif
