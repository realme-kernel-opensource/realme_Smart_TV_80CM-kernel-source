#!/bin/sh
# SPDX-License-Identifier: GPL-2.0

echo "int foo(void) { char X[200]; return 3; }" | $* -S -x c -c -m32 -O0 -fstack-protector - -o - 2> /dev/null | grep -q "%gs"
