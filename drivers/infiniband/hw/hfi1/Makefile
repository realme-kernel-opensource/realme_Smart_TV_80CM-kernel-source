# SPDX-License-Identifier: GPL-2.0
#
# HFI driver
#
#
#
# Called from the kernel module build system.
#
obj-$(CONFIG_INFINIBAND_HFI1) += hfi1.o

hfi1-y := affinity.o chip.o device.o driver.o efivar.o \
	eprom.o exp_rcv.o file_ops.o firmware.o \
	init.o intr.o mad.o mmu_rb.o pcie.o pio.o pio_copy.o platform.o \
	qp.o qsfp.o rc.o ruc.o sdma.o sysfs.o trace.o \
	uc.o ud.o user_exp_rcv.o user_pages.o user_sdma.o verbs.o \
	verbs_txreq.o vnic_main.o vnic_sdma.o

ifdef CONFIG_DEBUG_FS
hfi1-y += debugfs.o
ifdef CONFIG_FAULT_INJECTION
ifdef CONFIG_FAULT_INJECTION_DEBUG_FS
hfi1-y += fault.o
endif
endif
endif

CFLAGS_trace.o = -I$(src)
ifdef MVERSION
CFLAGS_driver.o = -DHFI_DRIVER_VERSION_BASE=\"$(MVERSION)\"
endif
