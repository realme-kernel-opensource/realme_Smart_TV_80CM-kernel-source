# SPDX-License-Identifier: GPL-2.0
#
# Build the appropriate CPU version support
#

ifdef CONFIG_FUNCTION_TRACER
CFLAGS_REMOVE_cache.o = -pg
endif

ccflags-y := -DCPU_MAJOR=$(CPU_MAJOR) -DCPU_MINOR=$(CPU_MINOR) \
		-DCPU_REV=$(CPU_REV)

obj-y += cache.o cpuinfo.o cpuinfo-pvr-full.o cpuinfo-static.o mb.o pvr.o
