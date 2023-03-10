# SPDX-License-Identifier: GPL-2.0
#
# Makefile for the m68knommu kernel.
#

#
# If you want to play with the HW breakpoints then you will
# need to add define this,  which will give you a stack backtrace
# on the console port whenever a DBG interrupt occurs. You have to
# set up you HW breakpoints to trigger a DBG interrupt:
#
# ccflags-y := -DTRAP_DBG_INTERRUPT
# asflags-y := -DTRAP_DBG_INTERRUPT
#

asflags-$(CONFIG_FULLDEBUG) := -DDEBUGGER_COMPATIBLE_CACHE=1

obj-$(CONFIG_COLDFIRE)	+= cache.o clk.o device.o dma.o entry.o vectors.o
obj-$(CONFIG_M5206)	+= m5206.o timers.o intc.o reset.o
obj-$(CONFIG_M5206e)	+= m5206.o timers.o intc.o reset.o
obj-$(CONFIG_M520x)	+= m520x.o pit.o intc-simr.o reset.o
obj-$(CONFIG_M523x)	+= m523x.o pit.o dma_timer.o intc-2.o reset.o
obj-$(CONFIG_M5249)	+= m5249.o timers.o intc.o intc-5249.o reset.o
obj-$(CONFIG_M525x)	+= m525x.o timers.o intc.o intc-525x.o reset.o
obj-$(CONFIG_M527x)	+= m527x.o pit.o intc-2.o reset.o
obj-$(CONFIG_M5272)	+= m5272.o intc-5272.o timers.o
obj-$(CONFIG_M528x)	+= m528x.o pit.o intc-2.o reset.o
obj-$(CONFIG_M5307)	+= m5307.o timers.o intc.o reset.o
obj-$(CONFIG_M53xx)	+= m53xx.o timers.o intc-simr.o reset.o
obj-$(CONFIG_M5407)	+= m5407.o timers.o intc.o reset.o
obj-$(CONFIG_M54xx)	+= m54xx.o sltimers.o intc-2.o
obj-$(CONFIG_M5441x)	+= m5441x.o pit.o intc-simr.o reset.o

obj-$(CONFIG_NETtel)	+= nettel.o
obj-$(CONFIG_CLEOPATRA)	+= nettel.o
obj-$(CONFIG_FIREBEE)	+= firebee.o
obj-$(CONFIG_MCF8390)	+= mcf8390.o
obj-$(CONFIG_AMCORE)	+= amcore.o
obj-$(CONFIG_STMARK2)	+= stmark2.o

obj-$(CONFIG_PCI)	+= pci.o

obj-y			+= gpio.o
extra-y := head.o
