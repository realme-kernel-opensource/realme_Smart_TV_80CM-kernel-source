#
# Makefile for soundwire core
#

#Bus Objs
soundwire-bus-objs := bus_type.o bus.o slave.o mipi_disco.o stream.o
obj-$(CONFIG_SOUNDWIRE_BUS) += soundwire-bus.o

#Cadence Objs
soundwire-cadence-objs := cadence_master.o
obj-$(CONFIG_SOUNDWIRE_CADENCE) += soundwire-cadence.o

#Intel driver
soundwire-intel-objs :=	intel.o
obj-$(CONFIG_SOUNDWIRE_INTEL) += soundwire-intel.o

soundwire-intel-init-objs := intel_init.o
obj-$(CONFIG_SOUNDWIRE_INTEL) += soundwire-intel-init.o
