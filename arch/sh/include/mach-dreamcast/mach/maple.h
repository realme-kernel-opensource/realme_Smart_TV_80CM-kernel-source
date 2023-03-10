/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __ASM_MAPLE_H
#define __ASM_MAPLE_H

#define MAPLE_PORTS 4
#define MAPLE_PNP_INTERVAL HZ
#define MAPLE_MAXPACKETS 8
#define MAPLE_DMA_ORDER 14
#define MAPLE_DMA_SIZE (1 << MAPLE_DMA_ORDER)
#define MAPLE_DMA_PAGES ((MAPLE_DMA_ORDER > PAGE_SHIFT) ? \
			  MAPLE_DMA_ORDER - PAGE_SHIFT : 0)

/* Maple Bus registers */
#define MAPLE_BASE     0xa05f6c00
#define MAPLE_DMAADDR  (MAPLE_BASE+0x04)
#define MAPLE_TRIGTYPE (MAPLE_BASE+0x10)
#define MAPLE_ENABLE   (MAPLE_BASE+0x14)
#define MAPLE_STATE    (MAPLE_BASE+0x18)
#define MAPLE_SPEED    (MAPLE_BASE+0x80)
#define MAPLE_RESET    (MAPLE_BASE+0x8c)

#define MAPLE_MAGIC    0x6155404f
#define MAPLE_2MBPS    0
#define MAPLE_TIMEOUT(n) ((n)<<15)

/* Function codes */
#define MAPLE_FUNC_CONTROLLER 0x001
#define MAPLE_FUNC_MEMCARD    0x002
#define MAPLE_FUNC_LCD        0x004
#define MAPLE_FUNC_CLOCK      0x008
#define MAPLE_FUNC_MICROPHONE 0x010
#define MAPLE_FUNC_ARGUN      0x020
#define MAPLE_FUNC_KEYBOARD   0x040
#define MAPLE_FUNC_LIGHTGUN   0x080
#define MAPLE_FUNC_PURUPURU   0x100
#define MAPLE_FUNC_MOUSE      0x200

#endif /* __ASM_MAPLE_H */
