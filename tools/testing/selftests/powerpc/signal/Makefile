# SPDX-License-Identifier: GPL-2.0
TEST_PROGS := signal signal_tm

all: $(TEST_PROGS)

$(TEST_PROGS): ../harness.c ../utils.c signal.S

CFLAGS += -maltivec
signal_tm: CFLAGS += -mhtm

top_srcdir = ../../../../..
include ../../lib.mk

clean:
	rm -f $(TEST_PROGS) *.o
