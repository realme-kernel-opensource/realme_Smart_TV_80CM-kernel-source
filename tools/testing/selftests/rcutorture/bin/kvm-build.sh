#!/bin/bash
#
# Build a kvm-ready Linux kernel from the tree in the current directory.
#
# Usage: kvm-build.sh config-template build-dir resdir
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, you can access it online at
# http://www.gnu.org/licenses/gpl-2.0.html.
#
# Copyright (C) IBM Corporation, 2011
#
# Authors: Paul E. McKenney <paulmck@linux.vnet.ibm.com>

config_template=${1}
if test -z "$config_template" -o ! -f "$config_template" -o ! -r "$config_template"
then
	echo "kvm-build.sh :$config_template: Not a readable file"
	exit 1
fi
builddir=${2}
resdir=${3}

T=${TMPDIR-/tmp}/test-linux.sh.$$
trap 'rm -rf $T' 0
mkdir $T

cp ${config_template} $T/config
cat << ___EOF___ >> $T/config
CONFIG_INITRAMFS_SOURCE="$TORTURE_INITRD"
CONFIG_VIRTIO_PCI=y
CONFIG_VIRTIO_CONSOLE=y
___EOF___

configinit.sh $T/config O=$builddir $resdir
retval=$?
if test $retval -gt 1
then
	exit 2
fi
ncpus=`cpus2use.sh`
make O=$builddir -j$ncpus $TORTURE_KMAKE_ARG > $resdir/Make.out 2>&1
retval=$?
if test $retval -ne 0 || grep "rcu[^/]*": < $resdir/Make.out | egrep -q "Stop|Error|error:|warning:" || egrep -q "Stop|Error|error:" < $resdir/Make.out
then
	echo Kernel build error
	egrep "Stop|Error|error:|warning:" < $resdir/Make.out
	echo Run aborted.
	exit 3
fi
