# List of programs to build
hostprogs-$(CONFIG_SAMPLE_STATX) := test-statx

# Tell kbuild to always build the programs
always := $(hostprogs-y)

HOSTCFLAGS_test-statx.o += -I$(objtree)/usr/include
