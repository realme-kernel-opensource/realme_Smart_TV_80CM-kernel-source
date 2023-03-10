/*
 * Random Number Generator driver for the Keystone SOC
 *
 * Copyright (C) 2016 Texas Instruments Incorporated - http://www.ti.com
 *
 * Authors:	Sandeep Nair
 *		Vitaly Andrianov
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 */

#include <linux/hw_random.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/io.h>
#include <linux/platform_device.h>
#include <linux/clk.h>
#include <linux/pm_runtime.h>
#include <linux/err.h>
#include <linux/regmap.h>
#include <linux/mfd/syscon.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/delay.h>

#define SA_CMD_STATUS_OFS			0x8

/* TRNG enable control in SA System module*/
#define SA_CMD_STATUS_REG_TRNG_ENABLE		BIT(3)

/* TRNG start control in TRNG module */
#define TRNG_CNTL_REG_TRNG_ENABLE		BIT(10)

/* Data ready indicator in STATUS register */
#define TRNG_STATUS_REG_READY			BIT(0)

/* Data ready clear control in INTACK register */
#define TRNG_INTACK_REG_READY			BIT(0)

/*
 * Number of samples taken to gather entropy during startup.
 * If value is 0, the number of samples is 2^24 else
 * equals value times 2^8.
 */
#define TRNG_DEF_STARTUP_CYCLES			0
#define TRNG_CNTL_REG_STARTUP_CYCLES_SHIFT	16

/*
 * Minimum number of samples taken to regenerate entropy
 * If value is 0, the number of samples is 2^24 else
 * equals value times 2^6.
 */
#define TRNG_DEF_MIN_REFILL_CYCLES		1
#define TRNG_CFG_REG_MIN_REFILL_CYCLES_SHIFT	0

/*
 * Maximum number of samples taken to regenerate entropy
 * If value is 0, the number of samples is 2^24 else
 * equals value times 2^8.
 */
#define TRNG_DEF_MAX_REFILL_CYCLES		0
#define TRNG_CFG_REG_MAX_REFILL_CYCLES_SHIFT	16

/* Number of CLK input cycles between samples */
#define TRNG_DEF_CLK_DIV_CYCLES			0
#define TRNG_CFG_REG_SAMPLE_DIV_SHIFT		8

/* Maximum retries to get rng data */
#define SA_MAX_RNG_DATA_RETRIES			5
/* Delay between retries (in usecs) */
#define SA_RNG_DATA_RETRY_DELAY			5

struct trng_regs {
	u32	output_l;
	u32	output_h;
	u32	status;
	u32	intmask;
	u32	intack;
	u32	control;
	u32	config;
};

struct ks_sa_rng {
	struct device	*dev;
	struct hwrng	rng;
	struct clk	*clk;
	struct regmap	*regmap_cfg;
	struct trng_regs *reg_rng;
};

static int ks_sa_rng_init(struct hwrng *rng)
{
	u32 value;
	struct device *dev = (struct device *)rng->priv;
	struct ks_sa_rng *ks_sa_rng = dev_get_drvdata(dev);

	/* Enable RNG module */
	regmap_write_bits(ks_sa_rng->regmap_cfg, SA_CMD_STATUS_OFS,
			  SA_CMD_STATUS_REG_TRNG_ENABLE,
			  SA_CMD_STATUS_REG_TRNG_ENABLE);

	/* Configure RNG module */
	writel(0, &ks_sa_rng->reg_rng->control);
	value = TRNG_DEF_STARTUP_CYCLES << TRNG_CNTL_REG_STARTUP_CYCLES_SHIFT;
	writel(value, &ks_sa_rng->reg_rng->control);

	value =	(TRNG_DEF_MIN_REFILL_CYCLES <<
		 TRNG_CFG_REG_MIN_REFILL_CYCLES_SHIFT) |
		(TRNG_DEF_MAX_REFILL_CYCLES <<
		 TRNG_CFG_REG_MAX_REFILL_CYCLES_SHIFT) |
		(TRNG_DEF_CLK_DIV_CYCLES <<
		 TRNG_CFG_REG_SAMPLE_DIV_SHIFT);

	writel(value, &ks_sa_rng->reg_rng->config);

	/* Disable all interrupts from TRNG */
	writel(0, &ks_sa_rng->reg_rng->intmask);

	/* Enable RNG */
	value = readl(&ks_sa_rng->reg_rng->control);
	value |= TRNG_CNTL_REG_TRNG_ENABLE;
	writel(value, &ks_sa_rng->reg_rng->control);

	return 0;
}

static void ks_sa_rng_cleanup(struct hwrng *rng)
{
	struct device *dev = (struct device *)rng->priv;
	struct ks_sa_rng *ks_sa_rng = dev_get_drvdata(dev);

	/* Disable RNG */
	writel(0, &ks_sa_rng->reg_rng->control);
	regmap_write_bits(ks_sa_rng->regmap_cfg, SA_CMD_STATUS_OFS,
			  SA_CMD_STATUS_REG_TRNG_ENABLE, 0);
}

static int ks_sa_rng_data_read(struct hwrng *rng, u32 *data)
{
	struct device *dev = (struct device *)rng->priv;
	struct ks_sa_rng *ks_sa_rng = dev_get_drvdata(dev);

	/* Read random data */
	data[0] = readl(&ks_sa_rng->reg_rng->output_l);
	data[1] = readl(&ks_sa_rng->reg_rng->output_h);

	writel(TRNG_INTACK_REG_READY, &ks_sa_rng->reg_rng->intack);

	return sizeof(u32) * 2;
}

static int ks_sa_rng_data_present(struct hwrng *rng, int wait)
{
	struct device *dev = (struct device *)rng->priv;
	struct ks_sa_rng *ks_sa_rng = dev_get_drvdata(dev);

	u32	ready;
	int	j;

	for (j = 0; j < SA_MAX_RNG_DATA_RETRIES; j++) {
		ready = readl(&ks_sa_rng->reg_rng->status);
		ready &= TRNG_STATUS_REG_READY;

		if (ready || !wait)
			break;

		udelay(SA_RNG_DATA_RETRY_DELAY);
	}

	return ready;
}

static int ks_sa_rng_probe(struct platform_device *pdev)
{
	struct ks_sa_rng	*ks_sa_rng;
	struct device		*dev = &pdev->dev;
	int			ret;
	struct resource		*mem;

	ks_sa_rng = devm_kzalloc(dev, sizeof(*ks_sa_rng), GFP_KERNEL);
	if (!ks_sa_rng)
		return -ENOMEM;

	ks_sa_rng->dev = dev;
	ks_sa_rng->rng = (struct hwrng) {
		.name = "ks_sa_hwrng",
		.init = ks_sa_rng_init,
		.data_read = ks_sa_rng_data_read,
		.data_present = ks_sa_rng_data_present,
		.cleanup = ks_sa_rng_cleanup,
	};
	ks_sa_rng->rng.priv = (unsigned long)dev;

	mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	ks_sa_rng->reg_rng = devm_ioremap_resource(dev, mem);
	if (IS_ERR(ks_sa_rng->reg_rng))
		return PTR_ERR(ks_sa_rng->reg_rng);

	ks_sa_rng->regmap_cfg =
		syscon_regmap_lookup_by_phandle(dev->of_node,
						"ti,syscon-sa-cfg");

	if (IS_ERR(ks_sa_rng->regmap_cfg)) {
		dev_err(dev, "syscon_node_to_regmap failed\n");
		return -EINVAL;
	}

	pm_runtime_enable(dev);
	ret = pm_runtime_get_sync(dev);
	if (ret < 0) {
		dev_err(dev, "Failed to enable SA power-domain\n");
		pm_runtime_disable(dev);
		return ret;
	}

	platform_set_drvdata(pdev, ks_sa_rng);

	return devm_hwrng_register(&pdev->dev, &ks_sa_rng->rng);
}

static int ks_sa_rng_remove(struct platform_device *pdev)
{
	pm_runtime_put_sync(&pdev->dev);
	pm_runtime_disable(&pdev->dev);

	return 0;
}

static const struct of_device_id ks_sa_rng_dt_match[] = {
	{
		.compatible = "ti,keystone-rng",
	},
	{ },
};
MODULE_DEVICE_TABLE(of, ks_sa_rng_dt_match);

static struct platform_driver ks_sa_rng_driver = {
	.driver		= {
		.name	= "ks-sa-rng",
		.of_match_table = ks_sa_rng_dt_match,
	},
	.probe		= ks_sa_rng_probe,
	.remove		= ks_sa_rng_remove,
};

module_platform_driver(ks_sa_rng_driver);

MODULE_DESCRIPTION("Keystone NETCP SA H/W Random Number Generator driver");
MODULE_AUTHOR("Vitaly Andrianov <vitalya@ti.com>");
MODULE_LICENSE("GPL");
