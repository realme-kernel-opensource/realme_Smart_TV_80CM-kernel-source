/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Common Intel AGPGART and GTT definitions.
 */
#ifndef _INTEL_AGP_H
#define _INTEL_AGP_H

/* Intel registers */
#define INTEL_APSIZE	0xb4
#define INTEL_ATTBASE	0xb8
#define INTEL_AGPCTRL	0xb0
#define INTEL_NBXCFG	0x50
#define INTEL_ERRSTS	0x91

/* Intel i830 registers */
#define I830_GMCH_CTRL			0x52
#define I830_GMCH_ENABLED		0x4
#define I830_GMCH_MEM_MASK		0x1
#define I830_GMCH_MEM_64M		0x1
#define I830_GMCH_MEM_128M		0
#define I830_GMCH_GMS_MASK		0x70
#define I830_GMCH_GMS_DISABLED		0x00
#define I830_GMCH_GMS_LOCAL		0x10
#define I830_GMCH_GMS_STOLEN_512	0x20
#define I830_GMCH_GMS_STOLEN_1024	0x30
#define I830_GMCH_GMS_STOLEN_8192	0x40
#define I830_RDRAM_CHANNEL_TYPE		0x03010
#define I830_RDRAM_ND(x)		(((x) & 0x20) >> 5)
#define I830_RDRAM_DDT(x)		(((x) & 0x18) >> 3)

/* This one is for I830MP w. an external graphic card */
#define INTEL_I830_ERRSTS	0x92

/* Intel 855GM/852GM registers */
#define I855_GMCH_GMS_MASK		0xF0
#define I855_GMCH_GMS_STOLEN_0M		0x0
#define I855_GMCH_GMS_STOLEN_1M		(0x1 << 4)
#define I855_GMCH_GMS_STOLEN_4M		(0x2 << 4)
#define I855_GMCH_GMS_STOLEN_8M		(0x3 << 4)
#define I855_GMCH_GMS_STOLEN_16M	(0x4 << 4)
#define I855_GMCH_GMS_STOLEN_32M	(0x5 << 4)
#define I85X_CAPID			0x44
#define I85X_VARIANT_MASK		0x7
#define I85X_VARIANT_SHIFT		5
#define I855_GME			0x0
#define I855_GM				0x4
#define I852_GME			0x2
#define I852_GM				0x5

/* Intel i845 registers */
#define INTEL_I845_AGPM		0x51
#define INTEL_I845_ERRSTS	0xc8

/* Intel i860 registers */
#define INTEL_I860_MCHCFG	0x50
#define INTEL_I860_ERRSTS	0xc8

/* Intel i810 registers */
#define I810_GMADR_BAR		0
#define I810_MMADR_BAR		1
#define I810_PTE_BASE		0x10000
#define I810_PTE_MAIN_UNCACHED	0x00000000
#define I810_PTE_LOCAL		0x00000002
#define I810_PTE_VALID		0x00000001
#define I830_PTE_SYSTEM_CACHED  0x00000006

#define I810_SMRAM_MISCC	0x70
#define I810_GFX_MEM_WIN_SIZE	0x00010000
#define I810_GFX_MEM_WIN_32M	0x00010000
#define I810_GMS		0x000000c0
#define I810_GMS_DISABLE	0x00000000
#define I810_PGETBL_CTL		0x2020
#define I810_PGETBL_ENABLED	0x00000001
/* Note: PGETBL_CTL2 has a different offset on G33. */
#define I965_PGETBL_CTL2	0x20c4
#define I965_PGETBL_SIZE_MASK	0x0000000e
#define I965_PGETBL_SIZE_512KB	(0 << 1)
#define I965_PGETBL_SIZE_256KB	(1 << 1)
#define I965_PGETBL_SIZE_128KB	(2 << 1)
#define I965_PGETBL_SIZE_1MB	(3 << 1)
#define I965_PGETBL_SIZE_2MB	(4 << 1)
#define I965_PGETBL_SIZE_1_5MB	(5 << 1)
#define G33_GMCH_SIZE_MASK	(3 << 8)
#define G33_GMCH_SIZE_1M	(1 << 8)
#define G33_GMCH_SIZE_2M	(2 << 8)
#define G4x_GMCH_SIZE_MASK	(0xf << 8)
#define G4x_GMCH_SIZE_1M	(0x1 << 8)
#define G4x_GMCH_SIZE_2M	(0x3 << 8)
#define G4x_GMCH_SIZE_VT_EN	(0x8 << 8)
#define G4x_GMCH_SIZE_VT_1M	(G4x_GMCH_SIZE_1M | G4x_GMCH_SIZE_VT_EN)
#define G4x_GMCH_SIZE_VT_1_5M	((0x2 << 8) | G4x_GMCH_SIZE_VT_EN)
#define G4x_GMCH_SIZE_VT_2M	(G4x_GMCH_SIZE_2M | G4x_GMCH_SIZE_VT_EN)

#define GFX_FLSH_CNTL		0x2170 /* 915+ */

#define I810_DRAM_CTL		0x3000
#define I810_DRAM_ROW_0		0x00000001
#define I810_DRAM_ROW_0_SDRAM	0x00000001

/* Intel 815 register */
#define INTEL_815_APCONT	0x51
#define INTEL_815_ATTBASE_MASK	~0x1FFFFFFF

/* Intel i820 registers */
#define INTEL_I820_RDCR		0x51
#define INTEL_I820_ERRSTS	0xc8

/* Intel i840 registers */
#define INTEL_I840_MCHCFG	0x50
#define INTEL_I840_ERRSTS	0xc8

/* Intel i850 registers */
#define INTEL_I850_MCHCFG	0x50
#define INTEL_I850_ERRSTS	0xc8

/* intel 915G registers */
#define I915_GMADR_BAR	2
#define I915_MMADR_BAR	0
#define I915_PTE_BAR	3
#define I915_GMCH_GMS_STOLEN_48M	(0x6 << 4)
#define I915_GMCH_GMS_STOLEN_64M	(0x7 << 4)
#define G33_GMCH_GMS_STOLEN_128M	(0x8 << 4)
#define G33_GMCH_GMS_STOLEN_256M	(0x9 << 4)
#define INTEL_GMCH_GMS_STOLEN_96M	(0xa << 4)
#define INTEL_GMCH_GMS_STOLEN_160M	(0xb << 4)
#define INTEL_GMCH_GMS_STOLEN_224M	(0xc << 4)
#define INTEL_GMCH_GMS_STOLEN_352M	(0xd << 4)

#define I915_IFPADDR    0x60
#define I830_HIC        0x70

/* Intel 965G registers */
#define I965_MSAC 0x62
#define I965_IFPADDR    0x70

/* Intel 7505 registers */
#define INTEL_I7505_APSIZE	0x74
#define INTEL_I7505_NCAPID	0x60
#define INTEL_I7505_NISTAT	0x6c
#define INTEL_I7505_ATTBASE	0x78
#define INTEL_I7505_ERRSTS	0x42
#define INTEL_I7505_AGPCTRL	0x70
#define INTEL_I7505_MCHCFG	0x50

/* pci devices ids */
#define PCI_DEVICE_ID_INTEL_E7221_HB	0x2588
#define PCI_DEVICE_ID_INTEL_E7221_IG	0x258a
#define PCI_DEVICE_ID_INTEL_82946GZ_HB      0x2970
#define PCI_DEVICE_ID_INTEL_82946GZ_IG      0x2972
#define PCI_DEVICE_ID_INTEL_82G35_HB     0x2980
#define PCI_DEVICE_ID_INTEL_82G35_IG     0x2982
#define PCI_DEVICE_ID_INTEL_82965Q_HB       0x2990
#define PCI_DEVICE_ID_INTEL_82965Q_IG       0x2992
#define PCI_DEVICE_ID_INTEL_82965G_HB       0x29A0
#define PCI_DEVICE_ID_INTEL_82965G_IG       0x29A2
#define PCI_DEVICE_ID_INTEL_82965GM_HB      0x2A00
#define PCI_DEVICE_ID_INTEL_82965GM_IG      0x2A02
#define PCI_DEVICE_ID_INTEL_82965GME_HB     0x2A10
#define PCI_DEVICE_ID_INTEL_82965GME_IG     0x2A12
#define PCI_DEVICE_ID_INTEL_82945GME_HB     0x27AC
#define PCI_DEVICE_ID_INTEL_82945GME_IG     0x27AE
#define PCI_DEVICE_ID_INTEL_PINEVIEW_M_HB        0xA010
#define PCI_DEVICE_ID_INTEL_PINEVIEW_M_IG        0xA011
#define PCI_DEVICE_ID_INTEL_PINEVIEW_HB         0xA000
#define PCI_DEVICE_ID_INTEL_PINEVIEW_IG         0xA001
#define PCI_DEVICE_ID_INTEL_G33_HB          0x29C0
#define PCI_DEVICE_ID_INTEL_G33_IG          0x29C2
#define PCI_DEVICE_ID_INTEL_Q35_HB          0x29B0
#define PCI_DEVICE_ID_INTEL_Q35_IG          0x29B2
#define PCI_DEVICE_ID_INTEL_Q33_HB          0x29D0
#define PCI_DEVICE_ID_INTEL_Q33_IG          0x29D2
#define PCI_DEVICE_ID_INTEL_B43_HB          0x2E40
#define PCI_DEVICE_ID_INTEL_B43_IG          0x2E42
#define PCI_DEVICE_ID_INTEL_B43_1_HB        0x2E90
#define PCI_DEVICE_ID_INTEL_B43_1_IG        0x2E92
#define PCI_DEVICE_ID_INTEL_GM45_HB         0x2A40
#define PCI_DEVICE_ID_INTEL_GM45_IG         0x2A42
#define PCI_DEVICE_ID_INTEL_EAGLELAKE_HB        0x2E00
#define PCI_DEVICE_ID_INTEL_EAGLELAKE_IG        0x2E02
#define PCI_DEVICE_ID_INTEL_Q45_HB          0x2E10
#define PCI_DEVICE_ID_INTEL_Q45_IG          0x2E12
#define PCI_DEVICE_ID_INTEL_G45_HB          0x2E20
#define PCI_DEVICE_ID_INTEL_G45_IG          0x2E22
#define PCI_DEVICE_ID_INTEL_G41_HB          0x2E30
#define PCI_DEVICE_ID_INTEL_G41_IG          0x2E32
#define PCI_DEVICE_ID_INTEL_IRONLAKE_D_HB	    0x0040
#define PCI_DEVICE_ID_INTEL_IRONLAKE_D2_HB	    0x0069
#define PCI_DEVICE_ID_INTEL_IRONLAKE_D_IG	    0x0042
#define PCI_DEVICE_ID_INTEL_IRONLAKE_M_HB	    0x0044
#define PCI_DEVICE_ID_INTEL_IRONLAKE_MA_HB	    0x0062
#define PCI_DEVICE_ID_INTEL_IRONLAKE_MC2_HB    0x006a
#define PCI_DEVICE_ID_INTEL_IRONLAKE_M_IG	    0x0046

#endif
