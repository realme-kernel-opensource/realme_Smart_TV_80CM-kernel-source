# SPDX-License-Identifier: GPL-2.0
vfio-platform-calxedaxgmac-y := vfio_platform_calxedaxgmac.o
vfio-platform-amdxgbe-y := vfio_platform_amdxgbe.o

ccflags-y += -Idrivers/vfio/platform

obj-$(CONFIG_VFIO_PLATFORM_CALXEDAXGMAC_RESET) += vfio-platform-calxedaxgmac.o
obj-$(CONFIG_VFIO_PLATFORM_AMDXGBE_RESET) += vfio-platform-amdxgbe.o
obj-$(CONFIG_VFIO_PLATFORM_BCMFLEXRM_RESET) += vfio_platform_bcmflexrm.o
