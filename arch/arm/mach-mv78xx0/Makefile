# SPDX-License-Identifier: GPL-2.0
ccflags-$(CONFIG_ARCH_MULTIPLATFORM) := -I$(srctree)/arch/arm/plat-orion/include

obj-y				+= common.o mpp.o irq.o pcie.o
obj-$(CONFIG_MACH_DB78X00_BP)	+= db78x00-bp-setup.o
obj-$(CONFIG_MACH_RD78X00_MASA)	+= rd78x00-masa-setup.o
obj-$(CONFIG_MACH_TERASTATION_WXL) += buffalo-wxl-setup.o
