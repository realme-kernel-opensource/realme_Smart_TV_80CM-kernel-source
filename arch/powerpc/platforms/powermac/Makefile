# SPDX-License-Identifier: GPL-2.0
CFLAGS_bootx_init.o  		+= -fPIC

ifdef CONFIG_FUNCTION_TRACER
# Do not trace early boot code
CFLAGS_REMOVE_bootx_init.o = $(CC_FLAGS_FTRACE)
endif

obj-y				+= pic.o setup.o time.o feature.o pci.o \
				   sleep.o low_i2c.o cache.o pfunc_core.o \
				   pfunc_base.o udbg_scc.o udbg_adb.o
obj-$(CONFIG_PMAC_BACKLIGHT)	+= backlight.o
# CONFIG_NVRAM is an arch. independent tristate symbol, for pmac32 we really
# need this to be a bool.  Cheat here and pretend CONFIG_NVRAM=m is really
# CONFIG_NVRAM=y
obj-$(CONFIG_NVRAM:m=y)		+= nvram.o
# ppc64 pmac doesn't define CONFIG_NVRAM but needs nvram stuff
obj-$(CONFIG_PPC64)		+= nvram.o
obj-$(CONFIG_PPC32)		+= bootx_init.o
obj-$(CONFIG_SMP)		+= smp.o
