/*
 * Copyright (C) 2010 Juergen Beisert, Pengutronix
 *
 * This code is based on:
 * Author: Vitaly Wool <vital@embeddedalley.com>
 *
 * Copyright 2008-2009 Freescale Semiconductor, Inc. All Rights Reserved.
 * Copyright 2008 Embedded Alley Solutions, Inc All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#define DRIVER_NAME "mxsfb"

/**
 * @file
 * @brief LCDIF driver for i.MX23 and i.MX28
 *
 * The LCDIF support four modes of operation
 * - MPU interface (to drive smart displays) -> not supported yet
 * - VSYNC interface (like MPU interface plus Vsync) -> not supported yet
 * - Dotclock interface (to drive LC displays with RGB data and sync signals)
 * - DVI (to drive ITU-R BT656)  -> not supported yet
 *
 * This driver depends on a correct setup of the pins used for this purpose
 * (platform specific).
 *
 * For the developer: Don't forget to set the data bus width to the display
 * in the imx_fb_videomode structure. You will else end up with ugly colours.
 * If you fight against jitter you can vary the clock delay. This is a feature
 * of the i.MX28 and you can vary it between 2 ns ... 8 ns in 2 ns steps. Give
 * the required value in the imx_fb_videomode structure.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/of_device.h>
#include <linux/platform_device.h>
#include <linux/clk.h>
#include <linux/dma-mapping.h>
#include <linux/io.h>
#include <linux/fb.h>
#include <linux/regulator/consumer.h>
#include <video/of_display_timing.h>
#include <video/of_videomode.h>
#include <video/videomode.h>

#define REG_SET	4
#define REG_CLR	8

#define LCDC_CTRL			0x00
#define LCDC_CTRL1			0x10
#define LCDC_V4_CTRL2			0x20
#define LCDC_V3_TRANSFER_COUNT		0x20
#define LCDC_V4_TRANSFER_COUNT		0x30
#define LCDC_V4_CUR_BUF			0x40
#define LCDC_V4_NEXT_BUF		0x50
#define LCDC_V3_CUR_BUF			0x30
#define LCDC_V3_NEXT_BUF		0x40
#define LCDC_TIMING			0x60
#define LCDC_VDCTRL0			0x70
#define LCDC_VDCTRL1			0x80
#define LCDC_VDCTRL2			0x90
#define LCDC_VDCTRL3			0xa0
#define LCDC_VDCTRL4			0xb0
#define LCDC_DVICTRL0			0xc0
#define LCDC_DVICTRL1			0xd0
#define LCDC_DVICTRL2			0xe0
#define LCDC_DVICTRL3			0xf0
#define LCDC_DVICTRL4			0x100
#define LCDC_V4_DATA			0x180
#define LCDC_V3_DATA			0x1b0
#define LCDC_V4_DEBUG0			0x1d0
#define LCDC_V3_DEBUG0			0x1f0

#define CTRL_SFTRST			(1 << 31)
#define CTRL_CLKGATE			(1 << 30)
#define CTRL_BYPASS_COUNT		(1 << 19)
#define CTRL_VSYNC_MODE			(1 << 18)
#define CTRL_DOTCLK_MODE		(1 << 17)
#define CTRL_DATA_SELECT		(1 << 16)
#define CTRL_SET_BUS_WIDTH(x)		(((x) & 0x3) << 10)
#define CTRL_GET_BUS_WIDTH(x)		(((x) >> 10) & 0x3)
#define CTRL_SET_WORD_LENGTH(x)		(((x) & 0x3) << 8)
#define CTRL_GET_WORD_LENGTH(x)		(((x) >> 8) & 0x3)
#define CTRL_MASTER			(1 << 5)
#define CTRL_DF16			(1 << 3)
#define CTRL_DF18			(1 << 2)
#define CTRL_DF24			(1 << 1)
#define CTRL_RUN			(1 << 0)

#define CTRL1_FIFO_CLEAR		(1 << 21)
#define CTRL1_SET_BYTE_PACKAGING(x)	(((x) & 0xf) << 16)
#define CTRL1_GET_BYTE_PACKAGING(x)	(((x) >> 16) & 0xf)

#define TRANSFER_COUNT_SET_VCOUNT(x)	(((x) & 0xffff) << 16)
#define TRANSFER_COUNT_GET_VCOUNT(x)	(((x) >> 16) & 0xffff)
#define TRANSFER_COUNT_SET_HCOUNT(x)	((x) & 0xffff)
#define TRANSFER_COUNT_GET_HCOUNT(x)	((x) & 0xffff)


#define VDCTRL0_ENABLE_PRESENT		(1 << 28)
#define VDCTRL0_VSYNC_ACT_HIGH		(1 << 27)
#define VDCTRL0_HSYNC_ACT_HIGH		(1 << 26)
#define VDCTRL0_DOTCLK_ACT_FALLING	(1 << 25)
#define VDCTRL0_ENABLE_ACT_HIGH		(1 << 24)
#define VDCTRL0_VSYNC_PERIOD_UNIT	(1 << 21)
#define VDCTRL0_VSYNC_PULSE_WIDTH_UNIT	(1 << 20)
#define VDCTRL0_HALF_LINE		(1 << 19)
#define VDCTRL0_HALF_LINE_MODE		(1 << 18)
#define VDCTRL0_SET_VSYNC_PULSE_WIDTH(x) ((x) & 0x3ffff)
#define VDCTRL0_GET_VSYNC_PULSE_WIDTH(x) ((x) & 0x3ffff)

#define VDCTRL2_SET_HSYNC_PERIOD(x)	((x) & 0x3ffff)
#define VDCTRL2_GET_HSYNC_PERIOD(x)	((x) & 0x3ffff)

#define VDCTRL3_MUX_SYNC_SIGNALS	(1 << 29)
#define VDCTRL3_VSYNC_ONLY		(1 << 28)
#define SET_HOR_WAIT_CNT(x)		(((x) & 0xfff) << 16)
#define GET_HOR_WAIT_CNT(x)		(((x) >> 16) & 0xfff)
#define SET_VERT_WAIT_CNT(x)		((x) & 0xffff)
#define GET_VERT_WAIT_CNT(x)		((x) & 0xffff)

#define VDCTRL4_SET_DOTCLK_DLY(x)	(((x) & 0x7) << 29) /* v4 only */
#define VDCTRL4_GET_DOTCLK_DLY(x)	(((x) >> 29) & 0x7) /* v4 only */
#define VDCTRL4_SYNC_SIGNALS_ON		(1 << 18)
#define SET_DOTCLK_H_VALID_DATA_CNT(x)	((x) & 0x3ffff)

#define DEBUG0_HSYNC			(1 < 26)
#define DEBUG0_VSYNC			(1 < 25)

#define MIN_XRES			120
#define MIN_YRES			120

#define RED 0
#define GREEN 1
#define BLUE 2
#define TRANSP 3

#define STMLCDIF_8BIT  1 /** pixel data bus to the display is of 8 bit width */
#define STMLCDIF_16BIT 0 /** pixel data bus to the display is of 16 bit width */
#define STMLCDIF_18BIT 2 /** pixel data bus to the display is of 18 bit width */
#define STMLCDIF_24BIT 3 /** pixel data bus to the display is of 24 bit width */

#define MXSFB_SYNC_DATA_ENABLE_HIGH_ACT	(1 << 6)
#define MXSFB_SYNC_DOTCLK_FALLING_ACT	(1 << 7) /* negative edge sampling */

enum mxsfb_devtype {
	MXSFB_V3,
	MXSFB_V4,
};

/* CPU dependent register offsets */
struct mxsfb_devdata {
	unsigned transfer_count;
	unsigned cur_buf;
	unsigned next_buf;
	unsigned debug0;
	unsigned hs_wdth_mask;
	unsigned hs_wdth_shift;
	unsigned ipversion;
};

struct mxsfb_info {
	struct platform_device *pdev;
	struct clk *clk;
	struct clk *clk_axi;
	struct clk *clk_disp_axi;
	void __iomem *base;	/* registers */
	unsigned allocated_size;
	int enabled;
	unsigned ld_intf_width;
	unsigned dotclk_delay;
	const struct mxsfb_devdata *devdata;
	u32 sync;
	struct regulator *reg_lcd;
};

#define mxsfb_is_v3(host) (host->devdata->ipversion == 3)
#define mxsfb_is_v4(host) (host->devdata->ipversion == 4)

static const struct mxsfb_devdata mxsfb_devdata[] = {
	[MXSFB_V3] = {
		.transfer_count = LCDC_V3_TRANSFER_COUNT,
		.cur_buf = LCDC_V3_CUR_BUF,
		.next_buf = LCDC_V3_NEXT_BUF,
		.debug0 = LCDC_V3_DEBUG0,
		.hs_wdth_mask = 0xff,
		.hs_wdth_shift = 24,
		.ipversion = 3,
	},
	[MXSFB_V4] = {
		.transfer_count = LCDC_V4_TRANSFER_COUNT,
		.cur_buf = LCDC_V4_CUR_BUF,
		.next_buf = LCDC_V4_NEXT_BUF,
		.debug0 = LCDC_V4_DEBUG0,
		.hs_wdth_mask = 0x3fff,
		.hs_wdth_shift = 18,
		.ipversion = 4,
	},
};

/* mask and shift depends on architecture */
static inline u32 set_hsync_pulse_width(struct mxsfb_info *host, unsigned val)
{
	return (val & host->devdata->hs_wdth_mask) <<
		host->devdata->hs_wdth_shift;
}

static inline u32 get_hsync_pulse_width(struct mxsfb_info *host, unsigned val)
{
	return (val >> host->devdata->hs_wdth_shift) &
		host->devdata->hs_wdth_mask;
}

static const struct fb_bitfield def_rgb565[] = {
	[RED] = {
		.offset = 11,
		.length = 5,
	},
	[GREEN] = {
		.offset = 5,
		.length = 6,
	},
	[BLUE] = {
		.offset = 0,
		.length = 5,
	},
	[TRANSP] = {	/* no support for transparency */
		.length = 0,
	}
};

static const struct fb_bitfield def_rgb888[] = {
	[RED] = {
		.offset = 16,
		.length = 8,
	},
	[GREEN] = {
		.offset = 8,
		.length = 8,
	},
	[BLUE] = {
		.offset = 0,
		.length = 8,
	},
	[TRANSP] = {	/* no support for transparency */
		.length = 0,
	}
};

static inline unsigned chan_to_field(unsigned chan, struct fb_bitfield *bf)
{
	chan &= 0xffff;
	chan >>= 16 - bf->length;
	return chan << bf->offset;
}

static int mxsfb_check_var(struct fb_var_screeninfo *var,
		struct fb_info *fb_info)
{
	struct mxsfb_info *host = fb_info->par;
	const struct fb_bitfield *rgb = NULL;

	if (var->xres < MIN_XRES)
		var->xres = MIN_XRES;
	if (var->yres < MIN_YRES)
		var->yres = MIN_YRES;

	var->xres_virtual = var->xres;

	var->yres_virtual = var->yres;

	switch (var->bits_per_pixel) {
	case 16:
		/* always expect RGB 565 */
		rgb = def_rgb565;
		break;
	case 32:
		switch (host->ld_intf_width) {
		case STMLCDIF_8BIT:
			pr_debug("Unsupported LCD bus width mapping\n");
			break;
		case STMLCDIF_16BIT:
		case STMLCDIF_18BIT:
		case STMLCDIF_24BIT:
			/* real 24 bit */
			rgb = def_rgb888;
			break;
		}
		break;
	default:
		pr_err("Unsupported colour depth: %u\n", var->bits_per_pixel);
		return -EINVAL;
	}

	/*
	 * Copy the RGB parameters for this display
	 * from the machine specific parameters.
	 */
	var->red    = rgb[RED];
	var->green  = rgb[GREEN];
	var->blue   = rgb[BLUE];
	var->transp = rgb[TRANSP];

	return 0;
}

static inline void mxsfb_enable_axi_clk(struct mxsfb_info *host)
{
	if (host->clk_axi)
		clk_prepare_enable(host->clk_axi);
}

static inline void mxsfb_disable_axi_clk(struct mxsfb_info *host)
{
	if (host->clk_axi)
		clk_disable_unprepare(host->clk_axi);
}

static void mxsfb_enable_controller(struct fb_info *fb_info)
{
	struct mxsfb_info *host = fb_info->par;
	u32 reg;
	int ret;

	dev_dbg(&host->pdev->dev, "%s\n", __func__);

	if (host->reg_lcd) {
		ret = regulator_enable(host->reg_lcd);
		if (ret) {
			dev_err(&host->pdev->dev,
				"lcd regulator enable failed:	%d\n", ret);
			return;
		}
	}

	if (host->clk_disp_axi)
		clk_prepare_enable(host->clk_disp_axi);
	clk_prepare_enable(host->clk);
	clk_set_rate(host->clk, PICOS2KHZ(fb_info->var.pixclock) * 1000U);

	mxsfb_enable_axi_clk(host);

	/* if it was disabled, re-enable the mode again */
	writel(CTRL_DOTCLK_MODE, host->base + LCDC_CTRL + REG_SET);

	/* enable the SYNC signals first, then the DMA engine */
	reg = readl(host->base + LCDC_VDCTRL4);
	reg |= VDCTRL4_SYNC_SIGNALS_ON;
	writel(reg, host->base + LCDC_VDCTRL4);

	writel(CTRL_RUN, host->base + LCDC_CTRL + REG_SET);

	host->enabled = 1;
}

static void mxsfb_disable_controller(struct fb_info *fb_info)
{
	struct mxsfb_info *host = fb_info->par;
	unsigned loop;
	u32 reg;
	int ret;

	dev_dbg(&host->pdev->dev, "%s\n", __func__);

	/*
	 * Even if we disable the controller here, it will still continue
	 * until its FIFOs are running out of data
	 */
	writel(CTRL_DOTCLK_MODE, host->base + LCDC_CTRL + REG_CLR);

	loop = 1000;
	while (loop) {
		reg = readl(host->base + LCDC_CTRL);
		if (!(reg & CTRL_RUN))
			break;
		loop--;
	}

	reg = readl(host->base + LCDC_VDCTRL4);
	writel(reg & ~VDCTRL4_SYNC_SIGNALS_ON, host->base + LCDC_VDCTRL4);

	mxsfb_disable_axi_clk(host);

	clk_disable_unprepare(host->clk);
	if (host->clk_disp_axi)
		clk_disable_unprepare(host->clk_disp_axi);

	host->enabled = 0;

	if (host->reg_lcd) {
		ret = regulator_disable(host->reg_lcd);
		if (ret)
			dev_err(&host->pdev->dev,
				"lcd regulator disable failed: %d\n", ret);
	}
}

static int mxsfb_set_par(struct fb_info *fb_info)
{
	struct mxsfb_info *host = fb_info->par;
	u32 ctrl, vdctrl0, vdctrl4;
	int line_size, fb_size;
	int reenable = 0;

	line_size =  fb_info->var.xres * (fb_info->var.bits_per_pixel >> 3);
	fb_size = fb_info->var.yres_virtual * line_size;

	if (fb_size > fb_info->fix.smem_len)
		return -ENOMEM;

	fb_info->fix.line_length = line_size;

	/*
	 * It seems, you can't re-program the controller if it is still running.
	 * This may lead into shifted pictures (FIFO issue?).
	 * So, first stop the controller and drain its FIFOs
	 */
	if (host->enabled) {
		reenable = 1;
		mxsfb_disable_controller(fb_info);
	}

	mxsfb_enable_axi_clk(host);

	/* clear the FIFOs */
	writel(CTRL1_FIFO_CLEAR, host->base + LCDC_CTRL1 + REG_SET);

	ctrl = CTRL_BYPASS_COUNT | CTRL_MASTER |
		CTRL_SET_BUS_WIDTH(host->ld_intf_width);

	switch (fb_info->var.bits_per_pixel) {
	case 16:
		dev_dbg(&host->pdev->dev, "Setting up RGB565 mode\n");
		ctrl |= CTRL_SET_WORD_LENGTH(0);
		writel(CTRL1_SET_BYTE_PACKAGING(0xf), host->base + LCDC_CTRL1);
		break;
	case 32:
		dev_dbg(&host->pdev->dev, "Setting up RGB888/666 mode\n");
		ctrl |= CTRL_SET_WORD_LENGTH(3);
		switch (host->ld_intf_width) {
		case STMLCDIF_8BIT:
			mxsfb_disable_axi_clk(host);
			dev_err(&host->pdev->dev,
					"Unsupported LCD bus width mapping\n");
			return -EINVAL;
		case STMLCDIF_16BIT:
		case STMLCDIF_18BIT:
		case STMLCDIF_24BIT:
			/* real 24 bit */
			break;
		}
		/* do not use packed pixels = one pixel per word instead */
		writel(CTRL1_SET_BYTE_PACKAGING(0x7), host->base + LCDC_CTRL1);
		break;
	default:
		mxsfb_disable_axi_clk(host);
		dev_err(&host->pdev->dev, "Unhandled color depth of %u\n",
				fb_info->var.bits_per_pixel);
		return -EINVAL;
	}

	writel(ctrl, host->base + LCDC_CTRL);

	writel(TRANSFER_COUNT_SET_VCOUNT(fb_info->var.yres) |
			TRANSFER_COUNT_SET_HCOUNT(fb_info->var.xres),
			host->base + host->devdata->transfer_count);

	vdctrl0 = VDCTRL0_ENABLE_PRESENT |	/* always in DOTCLOCK mode */
		VDCTRL0_VSYNC_PERIOD_UNIT |
		VDCTRL0_VSYNC_PULSE_WIDTH_UNIT |
		VDCTRL0_SET_VSYNC_PULSE_WIDTH(fb_info->var.vsync_len);
	if (fb_info->var.sync & FB_SYNC_HOR_HIGH_ACT)
		vdctrl0 |= VDCTRL0_HSYNC_ACT_HIGH;
	if (fb_info->var.sync & FB_SYNC_VERT_HIGH_ACT)
		vdctrl0 |= VDCTRL0_VSYNC_ACT_HIGH;
	if (host->sync & MXSFB_SYNC_DATA_ENABLE_HIGH_ACT)
		vdctrl0 |= VDCTRL0_ENABLE_ACT_HIGH;
	if (host->sync & MXSFB_SYNC_DOTCLK_FALLING_ACT)
		vdctrl0 |= VDCTRL0_DOTCLK_ACT_FALLING;

	writel(vdctrl0, host->base + LCDC_VDCTRL0);

	/* frame length in lines */
	writel(fb_info->var.upper_margin + fb_info->var.vsync_len +
		fb_info->var.lower_margin + fb_info->var.yres,
		host->base + LCDC_VDCTRL1);

	/* line length in units of clocks or pixels */
	writel(set_hsync_pulse_width(host, fb_info->var.hsync_len) |
		VDCTRL2_SET_HSYNC_PERIOD(fb_info->var.left_margin +
		fb_info->var.hsync_len + fb_info->var.right_margin +
		fb_info->var.xres),
		host->base + LCDC_VDCTRL2);

	writel(SET_HOR_WAIT_CNT(fb_info->var.left_margin +
		fb_info->var.hsync_len) |
		SET_VERT_WAIT_CNT(fb_info->var.upper_margin +
			fb_info->var.vsync_len),
		host->base + LCDC_VDCTRL3);

	vdctrl4 = SET_DOTCLK_H_VALID_DATA_CNT(fb_info->var.xres);
	if (mxsfb_is_v4(host))
		vdctrl4 |= VDCTRL4_SET_DOTCLK_DLY(host->dotclk_delay);
	writel(vdctrl4, host->base + LCDC_VDCTRL4);

	writel(fb_info->fix.smem_start +
			fb_info->fix.line_length * fb_info->var.yoffset,
			host->base + host->devdata->next_buf);

	mxsfb_disable_axi_clk(host);

	if (reenable)
		mxsfb_enable_controller(fb_info);

	return 0;
}

static int mxsfb_setcolreg(u_int regno, u_int red, u_int green, u_int blue,
		u_int transp, struct fb_info *fb_info)
{
	unsigned int val;
	int ret = -EINVAL;

	/*
	 * If greyscale is true, then we convert the RGB value
	 * to greyscale no matter what visual we are using.
	 */
	if (fb_info->var.grayscale)
		red = green = blue = (19595 * red + 38470 * green +
					7471 * blue) >> 16;

	switch (fb_info->fix.visual) {
	case FB_VISUAL_TRUECOLOR:
		/*
		 * 12 or 16-bit True Colour.  We encode the RGB value
		 * according to the RGB bitfield information.
		 */
		if (regno < 16) {
			u32 *pal = fb_info->pseudo_palette;

			val  = chan_to_field(red, &fb_info->var.red);
			val |= chan_to_field(green, &fb_info->var.green);
			val |= chan_to_field(blue, &fb_info->var.blue);

			pal[regno] = val;
			ret = 0;
		}
		break;

	case FB_VISUAL_STATIC_PSEUDOCOLOR:
	case FB_VISUAL_PSEUDOCOLOR:
		break;
	}

	return ret;
}

static int mxsfb_blank(int blank, struct fb_info *fb_info)
{
	struct mxsfb_info *host = fb_info->par;

	switch (blank) {
	case FB_BLANK_POWERDOWN:
	case FB_BLANK_VSYNC_SUSPEND:
	case FB_BLANK_HSYNC_SUSPEND:
	case FB_BLANK_NORMAL:
		if (host->enabled)
			mxsfb_disable_controller(fb_info);
		break;

	case FB_BLANK_UNBLANK:
		if (!host->enabled)
			mxsfb_enable_controller(fb_info);
		break;
	}
	return 0;
}

static int mxsfb_pan_display(struct fb_var_screeninfo *var,
		struct fb_info *fb_info)
{
	struct mxsfb_info *host = fb_info->par;
	unsigned offset;

	if (var->xoffset != 0)
		return -EINVAL;

	offset = fb_info->fix.line_length * var->yoffset;

	mxsfb_enable_axi_clk(host);

	/* update on next VSYNC */
	writel(fb_info->fix.smem_start + offset,
			host->base + host->devdata->next_buf);

	mxsfb_disable_axi_clk(host);

	return 0;
}

static struct fb_ops mxsfb_ops = {
	.owner = THIS_MODULE,
	.fb_check_var = mxsfb_check_var,
	.fb_set_par = mxsfb_set_par,
	.fb_setcolreg = mxsfb_setcolreg,
	.fb_blank = mxsfb_blank,
	.fb_pan_display = mxsfb_pan_display,
	.fb_fillrect = cfb_fillrect,
	.fb_copyarea = cfb_copyarea,
	.fb_imageblit = cfb_imageblit,
};

static int mxsfb_restore_mode(struct fb_info *fb_info,
			struct fb_videomode *vmode)
{
	struct mxsfb_info *host = fb_info->par;
	unsigned line_count;
	unsigned period;
	unsigned long pa, fbsize;
	int bits_per_pixel, ofs, ret = 0;
	u32 transfer_count, vdctrl0, vdctrl2, vdctrl3, vdctrl4, ctrl;

	mxsfb_enable_axi_clk(host);

	/* Only restore the mode when the controller is running */
	ctrl = readl(host->base + LCDC_CTRL);
	if (!(ctrl & CTRL_RUN)) {
		ret = -EINVAL;
		goto err;
	}

	vdctrl0 = readl(host->base + LCDC_VDCTRL0);
	vdctrl2 = readl(host->base + LCDC_VDCTRL2);
	vdctrl3 = readl(host->base + LCDC_VDCTRL3);
	vdctrl4 = readl(host->base + LCDC_VDCTRL4);

	transfer_count = readl(host->base + host->devdata->transfer_count);

	vmode->xres = TRANSFER_COUNT_GET_HCOUNT(transfer_count);
	vmode->yres = TRANSFER_COUNT_GET_VCOUNT(transfer_count);

	switch (CTRL_GET_WORD_LENGTH(ctrl)) {
	case 0:
		bits_per_pixel = 16;
		break;
	case 3:
		bits_per_pixel = 32;
		break;
	case 1:
	default:
		ret = -EINVAL;
		goto err;
	}

	fb_info->var.bits_per_pixel = bits_per_pixel;

	vmode->pixclock = KHZ2PICOS(clk_get_rate(host->clk) / 1000U);
	vmode->hsync_len = get_hsync_pulse_width(host, vdctrl2);
	vmode->left_margin = GET_HOR_WAIT_CNT(vdctrl3) - vmode->hsync_len;
	vmode->right_margin = VDCTRL2_GET_HSYNC_PERIOD(vdctrl2) -
		vmode->hsync_len - vmode->left_margin - vmode->xres;
	vmode->vsync_len = VDCTRL0_GET_VSYNC_PULSE_WIDTH(vdctrl0);
	period = readl(host->base + LCDC_VDCTRL1);
	vmode->upper_margin = GET_VERT_WAIT_CNT(vdctrl3) - vmode->vsync_len;
	vmode->lower_margin = period - vmode->vsync_len -
		vmode->upper_margin - vmode->yres;

	vmode->vmode = FB_VMODE_NONINTERLACED;

	vmode->sync = 0;
	if (vdctrl0 & VDCTRL0_HSYNC_ACT_HIGH)
		vmode->sync |= FB_SYNC_HOR_HIGH_ACT;
	if (vdctrl0 & VDCTRL0_VSYNC_ACT_HIGH)
		vmode->sync |= FB_SYNC_VERT_HIGH_ACT;

	pr_debug("Reconstructed video mode:\n");
	pr_debug("%dx%d, hsync: %u left: %u, right: %u, vsync: %u, upper: %u, lower: %u\n",
		vmode->xres, vmode->yres, vmode->hsync_len, vmode->left_margin,
		vmode->right_margin, vmode->vsync_len, vmode->upper_margin,
		vmode->lower_margin);
	pr_debug("pixclk: %ldkHz\n", PICOS2KHZ(vmode->pixclock));

	host->ld_intf_width = CTRL_GET_BUS_WIDTH(ctrl);
	host->dotclk_delay = VDCTRL4_GET_DOTCLK_DLY(vdctrl4);

	fb_info->fix.line_length = vmode->xres * (bits_per_pixel >> 3);

	pa = readl(host->base + host->devdata->cur_buf);
	fbsize = fb_info->fix.line_length * vmode->yres;
	if (pa < fb_info->fix.smem_start) {
		ret = -EINVAL;
		goto err;
	}
	if (pa + fbsize > fb_info->fix.smem_start + fb_info->fix.smem_len) {
		ret = -EINVAL;
		goto err;
	}
	ofs = pa - fb_info->fix.smem_start;
	if (ofs) {
		memmove(fb_info->screen_base, fb_info->screen_base + ofs, fbsize);
		writel(fb_info->fix.smem_start, host->base + host->devdata->next_buf);
	}

	line_count = fb_info->fix.smem_len / fb_info->fix.line_length;
	fb_info->fix.ypanstep = 1;

	clk_prepare_enable(host->clk);
	host->enabled = 1;

err:
	if (ret)
		mxsfb_disable_axi_clk(host);

	return ret;
}

static int mxsfb_init_fbinfo_dt(struct fb_info *fb_info,
				struct fb_videomode *vmode)
{
	struct mxsfb_info *host = fb_info->par;
	struct fb_var_screeninfo *var = &fb_info->var;
	struct device *dev = &host->pdev->dev;
	struct device_node *np = host->pdev->dev.of_node;
	struct device_node *display_np;
	struct videomode vm;
	u32 width;
	int ret;

	display_np = of_parse_phandle(np, "display", 0);
	if (!display_np) {
		dev_err(dev, "failed to find display phandle\n");
		return -ENOENT;
	}

	ret = of_property_read_u32(display_np, "bus-width", &width);
	if (ret < 0) {
		dev_err(dev, "failed to get property bus-width\n");
		goto put_display_node;
	}

	switch (width) {
	case 8:
		host->ld_intf_width = STMLCDIF_8BIT;
		break;
	case 16:
		host->ld_intf_width = STMLCDIF_16BIT;
		break;
	case 18:
		host->ld_intf_width = STMLCDIF_18BIT;
		break;
	case 24:
		host->ld_intf_width = STMLCDIF_24BIT;
		break;
	default:
		dev_err(dev, "invalid bus-width value\n");
		ret = -EINVAL;
		goto put_display_node;
	}

	ret = of_property_read_u32(display_np, "bits-per-pixel",
				   &var->bits_per_pixel);
	if (ret < 0) {
		dev_err(dev, "failed to get property bits-per-pixel\n");
		goto put_display_node;
	}

	ret = of_get_videomode(display_np, &vm, OF_USE_NATIVE_MODE);
	if (ret) {
		dev_err(dev, "failed to get videomode from DT\n");
		goto put_display_node;
	}

	ret = fb_videomode_from_videomode(&vm, vmode);
	if (ret < 0)
		goto put_display_node;

	if (vm.flags & DISPLAY_FLAGS_DE_HIGH)
		host->sync |= MXSFB_SYNC_DATA_ENABLE_HIGH_ACT;

	/*
	 * The PIXDATA flags of the display_flags enum are controller
	 * centric, e.g. NEGEDGE means drive data on negative edge.
	 * However, the drivers flag is display centric: Sample the
	 * data on negative (falling) edge. Therefore, check for the
	 * POSEDGE flag:
	 * drive on positive edge => sample on negative edge
	 */
	if (vm.flags & DISPLAY_FLAGS_PIXDATA_POSEDGE)
		host->sync |= MXSFB_SYNC_DOTCLK_FALLING_ACT;

put_display_node:
	of_node_put(display_np);
	return ret;
}

static int mxsfb_init_fbinfo(struct fb_info *fb_info,
			struct fb_videomode *vmode)
{
	int ret;
	struct mxsfb_info *host = fb_info->par;
	struct device *dev = &host->pdev->dev;
	struct fb_var_screeninfo *var = &fb_info->var;
	dma_addr_t fb_phys;
	void *fb_virt;
	unsigned fb_size;

	fb_info->fbops = &mxsfb_ops;
	fb_info->flags = FBINFO_FLAG_DEFAULT | FBINFO_READS_FAST;
	strlcpy(fb_info->fix.id, "mxs", sizeof(fb_info->fix.id));
	fb_info->fix.type = FB_TYPE_PACKED_PIXELS;
	fb_info->fix.ypanstep = 1;
	fb_info->fix.visual = FB_VISUAL_TRUECOLOR,
	fb_info->fix.accel = FB_ACCEL_NONE;

	ret = mxsfb_init_fbinfo_dt(fb_info, vmode);
	if (ret)
		return ret;

	var->nonstd = 0;
	var->activate = FB_ACTIVATE_NOW;
	var->accel_flags = 0;
	var->vmode = FB_VMODE_NONINTERLACED;

	/* Memory allocation for framebuffer */
	fb_size = SZ_2M;
	fb_virt = dma_alloc_wc(dev, PAGE_ALIGN(fb_size), &fb_phys, GFP_KERNEL);
	if (!fb_virt)
		return -ENOMEM;

	fb_info->fix.smem_start = fb_phys;
	fb_info->screen_base = fb_virt;
	fb_info->screen_size = fb_info->fix.smem_len = fb_size;

	if (mxsfb_restore_mode(fb_info, vmode))
		memset(fb_virt, 0, fb_size);

	return 0;
}

static void mxsfb_free_videomem(struct fb_info *fb_info)
{
	struct mxsfb_info *host = fb_info->par;
	struct device *dev = &host->pdev->dev;

	dma_free_wc(dev, fb_info->screen_size, fb_info->screen_base,
		    fb_info->fix.smem_start);
}

static const struct platform_device_id mxsfb_devtype[] = {
	{
		.name = "imx23-fb",
		.driver_data = MXSFB_V3,
	}, {
		.name = "imx28-fb",
		.driver_data = MXSFB_V4,
	}, {
		/* sentinel */
	}
};
MODULE_DEVICE_TABLE(platform, mxsfb_devtype);

static const struct of_device_id mxsfb_dt_ids[] = {
	{ .compatible = "fsl,imx23-lcdif", .data = &mxsfb_devtype[0], },
	{ .compatible = "fsl,imx28-lcdif", .data = &mxsfb_devtype[1], },
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, mxsfb_dt_ids);

static int mxsfb_probe(struct platform_device *pdev)
{
	const struct of_device_id *of_id =
			of_match_device(mxsfb_dt_ids, &pdev->dev);
	struct resource *res;
	struct mxsfb_info *host;
	struct fb_info *fb_info;
	struct fb_videomode *mode;
	int ret;

	if (of_id)
		pdev->id_entry = of_id->data;

	fb_info = framebuffer_alloc(sizeof(struct mxsfb_info), &pdev->dev);
	if (!fb_info) {
		dev_err(&pdev->dev, "Failed to allocate fbdev\n");
		return -ENOMEM;
	}

	mode = devm_kzalloc(&pdev->dev, sizeof(struct fb_videomode),
			GFP_KERNEL);
	if (mode == NULL)
		return -ENOMEM;

	host = fb_info->par;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	host->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(host->base)) {
		ret = PTR_ERR(host->base);
		goto fb_release;
	}

	host->pdev = pdev;
	platform_set_drvdata(pdev, host);

	host->devdata = &mxsfb_devdata[pdev->id_entry->driver_data];

	host->clk = devm_clk_get(&host->pdev->dev, NULL);
	if (IS_ERR(host->clk)) {
		ret = PTR_ERR(host->clk);
		goto fb_release;
	}

	host->clk_axi = devm_clk_get(&host->pdev->dev, "axi");
	if (IS_ERR(host->clk_axi))
		host->clk_axi = NULL;

	host->clk_disp_axi = devm_clk_get(&host->pdev->dev, "disp_axi");
	if (IS_ERR(host->clk_disp_axi))
		host->clk_disp_axi = NULL;

	host->reg_lcd = devm_regulator_get(&pdev->dev, "lcd");
	if (IS_ERR(host->reg_lcd))
		host->reg_lcd = NULL;

	fb_info->pseudo_palette = devm_kcalloc(&pdev->dev, 16, sizeof(u32),
					       GFP_KERNEL);
	if (!fb_info->pseudo_palette) {
		ret = -ENOMEM;
		goto fb_release;
	}

	ret = mxsfb_init_fbinfo(fb_info, mode);
	if (ret != 0)
		goto fb_release;

	fb_videomode_to_var(&fb_info->var, mode);

	/* init the color fields */
	mxsfb_check_var(&fb_info->var, fb_info);

	platform_set_drvdata(pdev, fb_info);

	ret = register_framebuffer(fb_info);
	if (ret != 0) {
		dev_err(&pdev->dev,"Failed to register framebuffer\n");
		goto fb_destroy;
	}

	if (!host->enabled) {
		mxsfb_enable_axi_clk(host);
		writel(0, host->base + LCDC_CTRL);
		mxsfb_disable_axi_clk(host);
		mxsfb_set_par(fb_info);
		mxsfb_enable_controller(fb_info);
	}

	dev_info(&pdev->dev, "initialized\n");

	return 0;

fb_destroy:
	if (host->enabled)
		clk_disable_unprepare(host->clk);
fb_release:
	framebuffer_release(fb_info);

	return ret;
}

static int mxsfb_remove(struct platform_device *pdev)
{
	struct fb_info *fb_info = platform_get_drvdata(pdev);
	struct mxsfb_info *host = fb_info->par;

	if (host->enabled)
		mxsfb_disable_controller(fb_info);

	unregister_framebuffer(fb_info);
	mxsfb_free_videomem(fb_info);

	framebuffer_release(fb_info);

	return 0;
}

static void mxsfb_shutdown(struct platform_device *pdev)
{
	struct fb_info *fb_info = platform_get_drvdata(pdev);
	struct mxsfb_info *host = fb_info->par;

	mxsfb_enable_axi_clk(host);

	/*
	 * Force stop the LCD controller as keeping it running during reboot
	 * might interfere with the BootROM's boot mode pads sampling.
	 */
	writel(CTRL_RUN, host->base + LCDC_CTRL + REG_CLR);

	mxsfb_disable_axi_clk(host);
}

static struct platform_driver mxsfb_driver = {
	.probe = mxsfb_probe,
	.remove = mxsfb_remove,
	.shutdown = mxsfb_shutdown,
	.id_table = mxsfb_devtype,
	.driver = {
		   .name = DRIVER_NAME,
		   .of_match_table = mxsfb_dt_ids,
	},
};

module_platform_driver(mxsfb_driver);

MODULE_DESCRIPTION("Freescale mxs framebuffer driver");
MODULE_AUTHOR("Sascha Hauer, Pengutronix");
MODULE_LICENSE("GPL");
