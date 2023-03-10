/*
 * Simple Reset Controller ops
 *
 * Based on Allwinner SoCs Reset Controller driver
 *
 * Copyright 2013 Maxime Ripard
 *
 * Maxime Ripard <maxime.ripard@free-electrons.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef __RESET_SIMPLE_H__
#define __RESET_SIMPLE_H__

#include <linux/io.h>
#include <linux/reset-controller.h>
#include <linux/spinlock.h>

/**
 * struct reset_simple_data - driver data for simple reset controllers
 * @lock: spinlock to protect registers during read-modify-write cycles
 * @membase: memory mapped I/O register range
 * @rcdev: reset controller device base structure
 * @active_low: if true, bits are cleared to assert the reset. Otherwise, bits
 *              are set to assert the reset. Note that this says nothing about
 *              the voltage level of the actual reset line.
 * @status_active_low: if true, bits read back as cleared while the reset is
 *                     asserted. Otherwise, bits read back as set while the
 *                     reset is asserted.
 */
struct reset_simple_data {
	spinlock_t			lock;
	void __iomem			*membase;
	struct reset_controller_dev	rcdev;
	bool				active_low;
	bool				status_active_low;
};

extern const struct reset_control_ops reset_simple_ops;

#endif /* __RESET_SIMPLE_H__ */
