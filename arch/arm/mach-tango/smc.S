/* SPDX-License-Identifier: GPL-2.0 */
#include <linux/linkage.h>

ENTRY(tango_smc)
	push	{lr}
	mov	ip, r1
	dsb	/* This barrier is probably unnecessary */
	smc	#0
	pop	{pc}
ENDPROC(tango_smc)
