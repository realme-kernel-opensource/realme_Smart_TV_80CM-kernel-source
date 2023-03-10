/* SPDX-License-Identifier: GPL-2.0-only */
/*
 *  Copyright 2014-2015 Cisco Systems, Inc. and/or its affiliates.
 *  All rights reserved.
 */

#ifndef M00233_VIDEO_MEASURE_MEMMAP_PACKAGE_H
#define M00233_VIDEO_MEASURE_MEMMAP_PACKAGE_H

/*******************************************************************
 * Register Block
 * M00233_VIDEO_MEASURE_MEMMAP_PACKAGE_VHD_REGMAP
 *******************************************************************/
struct m00233_video_measure_regmap {
	uint32_t irq_status;        /* Reg 0x0000 */
	/* The vertical counter starts on rising edge of vsync */
	uint32_t vsync_time;        /* Reg 0x0004 */
	uint32_t vback_porch;       /* Reg 0x0008 */
	uint32_t vactive_area;      /* Reg 0x000c */
	uint32_t vfront_porch;      /* Reg 0x0010 */
	/* The horizontal counter starts on rising edge of hsync. */
	uint32_t hsync_time;        /* Reg 0x0014 */
	uint32_t hback_porch;       /* Reg 0x0018 */
	uint32_t hactive_area;      /* Reg 0x001c */
	uint32_t hfront_porch;      /* Reg 0x0020 */
	uint32_t control;           /* Reg 0x0024, Default=0x0 */
	uint32_t irq_triggers;      /* Reg 0x0028, Default=0xff */
	/* Value is given in number of register bus clock periods between */
	/* falling and rising edge of hsync. Must be non-zero. */
	uint32_t hsync_timeout_val; /* Reg 0x002c, Default=0x1fff */
	uint32_t status;            /* Reg 0x0030 */
};

#define M00233_VIDEO_MEASURE_REG_IRQ_STATUS_OFST 0
#define M00233_VIDEO_MEASURE_REG_VSYNC_TIME_OFST 4
#define M00233_VIDEO_MEASURE_REG_VBACK_PORCH_OFST 8
#define M00233_VIDEO_MEASURE_REG_VACTIVE_AREA_OFST 12
#define M00233_VIDEO_MEASURE_REG_VFRONT_PORCH_OFST 16
#define M00233_VIDEO_MEASURE_REG_HSYNC_TIME_OFST 20
#define M00233_VIDEO_MEASURE_REG_HBACK_PORCH_OFST 24
#define M00233_VIDEO_MEASURE_REG_HACTIVE_AREA_OFST 28
#define M00233_VIDEO_MEASURE_REG_HFRONT_PORCH_OFST 32
#define M00233_VIDEO_MEASURE_REG_CONTROL_OFST 36
#define M00233_VIDEO_MEASURE_REG_IRQ_TRIGGERS_OFST 40
#define M00233_VIDEO_MEASURE_REG_HSYNC_TIMEOUT_VAL_OFST 44
#define M00233_VIDEO_MEASURE_REG_STATUS_OFST 48

/*******************************************************************
 * Bit Mask for register
 * M00233_VIDEO_MEASURE_MEMMAP_PACKAGE_VHD_BITMAP
 *******************************************************************/
/* irq_status [7:0] */
#define M00233_IRQ_STATUS_BITMAP_VSYNC_TIME_OFST      (0)
#define M00233_IRQ_STATUS_BITMAP_VSYNC_TIME_MSK       (0x1 << M00233_IRQ_STATUS_BITMAP_VSYNC_TIME_OFST)
#define M00233_IRQ_STATUS_BITMAP_VBACK_PORCH_OFST     (1)
#define M00233_IRQ_STATUS_BITMAP_VBACK_PORCH_MSK      (0x1 << M00233_IRQ_STATUS_BITMAP_VBACK_PORCH_OFST)
#define M00233_IRQ_STATUS_BITMAP_VACTIVE_AREA_OFST    (2)
#define M00233_IRQ_STATUS_BITMAP_VACTIVE_AREA_MSK     (0x1 << M00233_IRQ_STATUS_BITMAP_VACTIVE_AREA_OFST)
#define M00233_IRQ_STATUS_BITMAP_VFRONT_PORCH_OFST    (3)
#define M00233_IRQ_STATUS_BITMAP_VFRONT_PORCH_MSK     (0x1 << M00233_IRQ_STATUS_BITMAP_VFRONT_PORCH_OFST)
#define M00233_IRQ_STATUS_BITMAP_HSYNC_TIME_OFST      (4)
#define M00233_IRQ_STATUS_BITMAP_HSYNC_TIME_MSK       (0x1 << M00233_IRQ_STATUS_BITMAP_HSYNC_TIME_OFST)
#define M00233_IRQ_STATUS_BITMAP_HBACK_PORCH_OFST     (5)
#define M00233_IRQ_STATUS_BITMAP_HBACK_PORCH_MSK      (0x1 << M00233_IRQ_STATUS_BITMAP_HBACK_PORCH_OFST)
#define M00233_IRQ_STATUS_BITMAP_HACTIVE_AREA_OFST    (6)
#define M00233_IRQ_STATUS_BITMAP_HACTIVE_AREA_MSK     (0x1 << M00233_IRQ_STATUS_BITMAP_HACTIVE_AREA_OFST)
#define M00233_IRQ_STATUS_BITMAP_HFRONT_PORCH_OFST    (7)
#define M00233_IRQ_STATUS_BITMAP_HFRONT_PORCH_MSK     (0x1 << M00233_IRQ_STATUS_BITMAP_HFRONT_PORCH_OFST)
/* control [4:0] */
#define M00233_CONTROL_BITMAP_HSYNC_POLARITY_LOW_OFST (0)
#define M00233_CONTROL_BITMAP_HSYNC_POLARITY_LOW_MSK  (0x1 << M00233_CONTROL_BITMAP_HSYNC_POLARITY_LOW_OFST)
#define M00233_CONTROL_BITMAP_VSYNC_POLARITY_LOW_OFST (1)
#define M00233_CONTROL_BITMAP_VSYNC_POLARITY_LOW_MSK  (0x1 << M00233_CONTROL_BITMAP_VSYNC_POLARITY_LOW_OFST)
#define M00233_CONTROL_BITMAP_ENABLE_MEASURE_OFST     (2)
#define M00233_CONTROL_BITMAP_ENABLE_MEASURE_MSK      (0x1 << M00233_CONTROL_BITMAP_ENABLE_MEASURE_OFST)
#define M00233_CONTROL_BITMAP_ENABLE_INTERRUPT_OFST   (3)
#define M00233_CONTROL_BITMAP_ENABLE_INTERRUPT_MSK    (0x1 << M00233_CONTROL_BITMAP_ENABLE_INTERRUPT_OFST)
#define M00233_CONTROL_BITMAP_UPDATE_ON_HSYNC_OFST    (4)
#define M00233_CONTROL_BITMAP_UPDATE_ON_HSYNC_MSK     (0x1 << M00233_CONTROL_BITMAP_UPDATE_ON_HSYNC_OFST)
/* irq_triggers [7:0] */
#define M00233_IRQ_TRIGGERS_BITMAP_VSYNC_TIME_OFST    (0)
#define M00233_IRQ_TRIGGERS_BITMAP_VSYNC_TIME_MSK     (0x1 << M00233_IRQ_TRIGGERS_BITMAP_VSYNC_TIME_OFST)
#define M00233_IRQ_TRIGGERS_BITMAP_VBACK_PORCH_OFST   (1)
#define M00233_IRQ_TRIGGERS_BITMAP_VBACK_PORCH_MSK    (0x1 << M00233_IRQ_TRIGGERS_BITMAP_VBACK_PORCH_OFST)
#define M00233_IRQ_TRIGGERS_BITMAP_VACTIVE_AREA_OFST  (2)
#define M00233_IRQ_TRIGGERS_BITMAP_VACTIVE_AREA_MSK   (0x1 << M00233_IRQ_TRIGGERS_BITMAP_VACTIVE_AREA_OFST)
#define M00233_IRQ_TRIGGERS_BITMAP_VFRONT_PORCH_OFST  (3)
#define M00233_IRQ_TRIGGERS_BITMAP_VFRONT_PORCH_MSK   (0x1 << M00233_IRQ_TRIGGERS_BITMAP_VFRONT_PORCH_OFST)
#define M00233_IRQ_TRIGGERS_BITMAP_HSYNC_TIME_OFST    (4)
#define M00233_IRQ_TRIGGERS_BITMAP_HSYNC_TIME_MSK     (0x1 << M00233_IRQ_TRIGGERS_BITMAP_HSYNC_TIME_OFST)
#define M00233_IRQ_TRIGGERS_BITMAP_HBACK_PORCH_OFST   (5)
#define M00233_IRQ_TRIGGERS_BITMAP_HBACK_PORCH_MSK    (0x1 << M00233_IRQ_TRIGGERS_BITMAP_HBACK_PORCH_OFST)
#define M00233_IRQ_TRIGGERS_BITMAP_HACTIVE_AREA_OFST  (6)
#define M00233_IRQ_TRIGGERS_BITMAP_HACTIVE_AREA_MSK   (0x1 << M00233_IRQ_TRIGGERS_BITMAP_HACTIVE_AREA_OFST)
#define M00233_IRQ_TRIGGERS_BITMAP_HFRONT_PORCH_OFST  (7)
#define M00233_IRQ_TRIGGERS_BITMAP_HFRONT_PORCH_MSK   (0x1 << M00233_IRQ_TRIGGERS_BITMAP_HFRONT_PORCH_OFST)
/* status [1:0] */
#define M00233_STATUS_BITMAP_HSYNC_TIMEOUT_OFST       (0)
#define M00233_STATUS_BITMAP_HSYNC_TIMEOUT_MSK        (0x1 << M00233_STATUS_BITMAP_HSYNC_TIMEOUT_OFST)
#define M00233_STATUS_BITMAP_INIT_DONE_OFST           (1)
#define M00233_STATUS_BITMAP_INIT_DONE_MSK            (0x1 << M00233_STATUS_BITMAP_INIT_DONE_OFST)

#endif /*M00233_VIDEO_MEASURE_MEMMAP_PACKAGE_H*/
