# SPDX-License-Identifier: GPL-2.0
obj-y				=  mce.o mce-severity.o mce-genpool.o

obj-$(CONFIG_X86_ANCIENT_MCE)	+= winchip.o p5.o
obj-$(CONFIG_X86_MCE_INTEL)	+= mce_intel.o
obj-$(CONFIG_X86_MCE_AMD)	+= mce_amd.o
obj-$(CONFIG_X86_MCE_THRESHOLD) += threshold.o
obj-$(CONFIG_X86_MCE_INJECT)	+= mce-inject.o

obj-$(CONFIG_X86_THERMAL_VECTOR) += therm_throt.o

obj-$(CONFIG_ACPI_APEI)		+= mce-apei.o

obj-$(CONFIG_X86_MCELOG_LEGACY)	+= dev-mcelog.o
