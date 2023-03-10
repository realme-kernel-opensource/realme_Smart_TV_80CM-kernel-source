// SPDX-License-Identifier: GPL-2.0
#include <linux/dma-direct.h>

dma_addr_t __phys_to_dma(struct device *dev, phys_addr_t paddr)
{
	return paddr | 0x80000000;
}

phys_addr_t __dma_to_phys(struct device *dev, dma_addr_t dma_addr)
{
#if defined(CONFIG_CPU_LOONGSON2F) && defined(CONFIG_64BIT)
	if (dma_addr > 0x8fffffff)
		return dma_addr;
	return dma_addr & 0x0fffffff;
#else
	return dma_addr & 0x7fffffff;
#endif
}
