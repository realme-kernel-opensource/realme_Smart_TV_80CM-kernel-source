# SPDX-License-Identifier: GPL-2.0
# Makefile for xmon

# Disable clang warning for using setjmp without setjmp.h header
subdir-ccflags-y := $(call cc-disable-warning, builtin-requires-header)

subdir-ccflags-$(CONFIG_PPC_WERROR) += -Werror

GCOV_PROFILE := n
UBSAN_SANITIZE := n

# Disable ftrace for the entire directory
ORIG_CFLAGS := $(KBUILD_CFLAGS)
KBUILD_CFLAGS = $(subst $(CC_FLAGS_FTRACE),,$(ORIG_CFLAGS))

ccflags-$(CONFIG_PPC64) := $(NO_MINIMAL_TOC)

obj-y			+= xmon.o nonstdio.o spr_access.o

ifdef CONFIG_XMON_DISASSEMBLY
obj-y			+= ppc-dis.o ppc-opc.o
obj-$(CONFIG_SPU_BASE)	+= spu-dis.o spu-opc.o
endif
