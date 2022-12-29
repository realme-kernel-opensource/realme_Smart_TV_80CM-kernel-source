#!/bin/bash
#
# Analyze a given results directory for rcutorture progress.
#
# Usage: kvm-recheck-rcu.sh resdir
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
# Copyright (C) IBM Corporation, 2014
#
# Authors: Paul E. McKenney <paulmck@linux.vnet.ibm.com>

i="$1"
if test -d "$i" -a -r "$i"
then
	:
else
	echo Unreadable results directory: $i
	exit 1
fi
. functions.sh

configfile=`echo $i | sed -e 's/^.*\///'`
ngps=`grep ver: $i/console.log 2> /dev/null | tail -1 | sed -e 's/^.* ver: //' -e 's/ .*$//'`
stopstate="`grep 'End-test grace-period state: g' $i/console.log 2> /dev/null |
	    tail -1 | sed -e 's/^\[[ 0-9.]*] //' |
	    awk '{ print \"[\" $1 \" \" $5 \" \" $6 \" \" $7 \"]\"; }' |
	    tr -d '\012\015'`"
if test -z "$ngps"
then
	echo "$configfile ------- " $stopstate
else
	title="$configfile ------- $ngps GPs"
	dur=`sed -e 's/^.* rcutorture.shutdown_secs=//' -e 's/ .*$//' < $i/qemu-cmd 2> /dev/null`
	if test -z "$dur"
	then
		:
	else
		ngpsps=`awk -v ngps=$ngps -v dur=$dur '
			BEGIN { print ngps / dur }' < /dev/null`
		title="$title ($ngpsps/s)"
	fi
	echo $title $stopstate
	nclosecalls=`grep --binary-files=text 'torture: Reader Batch' $i/console.log | tail -1 | awk '{for (i=NF-8;i<=NF;i++) sum+=$i; } END {print sum}'`
	if test -z "$nclosecalls"
	then
		exit 0
	fi
	if test "$nclosecalls" -eq 0
	then
		exit 0
	fi
	# Compute number of close calls per tenth of an hour
	nclosecalls10=`awk -v nclosecalls=$nclosecalls -v dur=$dur 'BEGIN { print int(nclosecalls * 36000 / dur) }' < /dev/null`
	if test $nclosecalls10 -gt 5 -a $nclosecalls -gt 1
	then
		print_bug $nclosecalls "Reader Batch close calls in" $(($dur/60)) minute run: $i
	else
		print_warning $nclosecalls "Reader Batch close calls in" $(($dur/60)) minute run: $i
	fi
	echo $nclosecalls "Reader Batch close calls in" $(($dur/60)) minute run: $i > $i/console.log.rcu.diags
fi
