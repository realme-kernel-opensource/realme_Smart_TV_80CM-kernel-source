/*
 * test helper assembly functions
 *
 * Copyright (C) 2016 Simon Guo, IBM Corporation.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version
 * 2 of the License, or (at your option) any later version.
 */
#include <ppc-asm.h>
#include "reg.h"


/* Non volatile GPR - unsigned long buf[18] */
FUNC_START(load_gpr)
	ld	14, 0*8(3)
	ld	15, 1*8(3)
	ld	16, 2*8(3)
	ld	17, 3*8(3)
	ld	18, 4*8(3)
	ld	19, 5*8(3)
	ld	20, 6*8(3)
	ld	21, 7*8(3)
	ld	22, 8*8(3)
	ld	23, 9*8(3)
	ld	24, 10*8(3)
	ld	25, 11*8(3)
	ld	26, 12*8(3)
	ld	27, 13*8(3)
	ld	28, 14*8(3)
	ld	29, 15*8(3)
	ld	30, 16*8(3)
	ld	31, 17*8(3)
	blr
FUNC_END(load_gpr)

FUNC_START(store_gpr)
	std	14, 0*8(3)
	std	15, 1*8(3)
	std	16, 2*8(3)
	std	17, 3*8(3)
	std	18, 4*8(3)
	std	19, 5*8(3)
	std	20, 6*8(3)
	std	21, 7*8(3)
	std	22, 8*8(3)
	std	23, 9*8(3)
	std	24, 10*8(3)
	std	25, 11*8(3)
	std	26, 12*8(3)
	std	27, 13*8(3)
	std	28, 14*8(3)
	std	29, 15*8(3)
	std	30, 16*8(3)
	std	31, 17*8(3)
	blr
FUNC_END(store_gpr)

/* Single Precision Float - float buf[32] */
FUNC_START(load_fpr_single_precision)
	lfs 0, 0*4(3)
	lfs 1, 1*4(3)
	lfs 2, 2*4(3)
	lfs 3, 3*4(3)
	lfs 4, 4*4(3)
	lfs 5, 5*4(3)
	lfs 6, 6*4(3)
	lfs 7, 7*4(3)
	lfs 8, 8*4(3)
	lfs 9, 9*4(3)
	lfs 10, 10*4(3)
	lfs 11, 11*4(3)
	lfs 12, 12*4(3)
	lfs 13, 13*4(3)
	lfs 14, 14*4(3)
	lfs 15, 15*4(3)
	lfs 16, 16*4(3)
	lfs 17, 17*4(3)
	lfs 18, 18*4(3)
	lfs 19, 19*4(3)
	lfs 20, 20*4(3)
	lfs 21, 21*4(3)
	lfs 22, 22*4(3)
	lfs 23, 23*4(3)
	lfs 24, 24*4(3)
	lfs 25, 25*4(3)
	lfs 26, 26*4(3)
	lfs 27, 27*4(3)
	lfs 28, 28*4(3)
	lfs 29, 29*4(3)
	lfs 30, 30*4(3)
	lfs 31, 31*4(3)
	blr
FUNC_END(load_fpr_single_precision)

/* Single Precision Float - float buf[32] */
FUNC_START(store_fpr_single_precision)
	stfs 0, 0*4(3)
	stfs 1, 1*4(3)
	stfs 2, 2*4(3)
	stfs 3, 3*4(3)
	stfs 4, 4*4(3)
	stfs 5, 5*4(3)
	stfs 6, 6*4(3)
	stfs 7, 7*4(3)
	stfs 8, 8*4(3)
	stfs 9, 9*4(3)
	stfs 10, 10*4(3)
	stfs 11, 11*4(3)
	stfs 12, 12*4(3)
	stfs 13, 13*4(3)
	stfs 14, 14*4(3)
	stfs 15, 15*4(3)
	stfs 16, 16*4(3)
	stfs 17, 17*4(3)
	stfs 18, 18*4(3)
	stfs 19, 19*4(3)
	stfs 20, 20*4(3)
	stfs 21, 21*4(3)
	stfs 22, 22*4(3)
	stfs 23, 23*4(3)
	stfs 24, 24*4(3)
	stfs 25, 25*4(3)
	stfs 26, 26*4(3)
	stfs 27, 27*4(3)
	stfs 28, 28*4(3)
	stfs 29, 29*4(3)
	stfs 30, 30*4(3)
	stfs 31, 31*4(3)
	blr
FUNC_END(store_fpr_single_precision)

/* VMX/VSX registers - unsigned long buf[128] */
FUNC_START(loadvsx)
	lis	4, 0
	LXVD2X	(0,(4),(3))
	addi	4, 4, 16
	LXVD2X	(1,(4),(3))
	addi	4, 4, 16
	LXVD2X	(2,(4),(3))
	addi	4, 4, 16
	LXVD2X	(3,(4),(3))
	addi	4, 4, 16
	LXVD2X	(4,(4),(3))
	addi	4, 4, 16
	LXVD2X	(5,(4),(3))
	addi	4, 4, 16
	LXVD2X	(6,(4),(3))
	addi	4, 4, 16
	LXVD2X	(7,(4),(3))
	addi	4, 4, 16
	LXVD2X	(8,(4),(3))
	addi	4, 4, 16
	LXVD2X	(9,(4),(3))
	addi	4, 4, 16
	LXVD2X	(10,(4),(3))
	addi	4, 4, 16
	LXVD2X	(11,(4),(3))
	addi	4, 4, 16
	LXVD2X	(12,(4),(3))
	addi	4, 4, 16
	LXVD2X	(13,(4),(3))
	addi	4, 4, 16
	LXVD2X	(14,(4),(3))
	addi	4, 4, 16
	LXVD2X	(15,(4),(3))
	addi	4, 4, 16
	LXVD2X	(16,(4),(3))
	addi	4, 4, 16
	LXVD2X	(17,(4),(3))
	addi	4, 4, 16
	LXVD2X	(18,(4),(3))
	addi	4, 4, 16
	LXVD2X	(19,(4),(3))
	addi	4, 4, 16
	LXVD2X	(20,(4),(3))
	addi	4, 4, 16
	LXVD2X	(21,(4),(3))
	addi	4, 4, 16
	LXVD2X	(22,(4),(3))
	addi	4, 4, 16
	LXVD2X	(23,(4),(3))
	addi	4, 4, 16
	LXVD2X	(24,(4),(3))
	addi	4, 4, 16
	LXVD2X	(25,(4),(3))
	addi	4, 4, 16
	LXVD2X	(26,(4),(3))
	addi	4, 4, 16
	LXVD2X	(27,(4),(3))
	addi	4, 4, 16
	LXVD2X	(28,(4),(3))
	addi	4, 4, 16
	LXVD2X	(29,(4),(3))
	addi	4, 4, 16
	LXVD2X	(30,(4),(3))
	addi	4, 4, 16
	LXVD2X	(31,(4),(3))
	addi	4, 4, 16
	LXVD2X	(32,(4),(3))
	addi	4, 4, 16
	LXVD2X	(33,(4),(3))
	addi	4, 4, 16
	LXVD2X	(34,(4),(3))
	addi	4, 4, 16
	LXVD2X	(35,(4),(3))
	addi	4, 4, 16
	LXVD2X	(36,(4),(3))
	addi	4, 4, 16
	LXVD2X	(37,(4),(3))
	addi	4, 4, 16
	LXVD2X	(38,(4),(3))
	addi	4, 4, 16
	LXVD2X	(39,(4),(3))
	addi	4, 4, 16
	LXVD2X	(40,(4),(3))
	addi	4, 4, 16
	LXVD2X	(41,(4),(3))
	addi	4, 4, 16
	LXVD2X	(42,(4),(3))
	addi	4, 4, 16
	LXVD2X	(43,(4),(3))
	addi	4, 4, 16
	LXVD2X	(44,(4),(3))
	addi	4, 4, 16
	LXVD2X	(45,(4),(3))
	addi	4, 4, 16
	LXVD2X	(46,(4),(3))
	addi	4, 4, 16
	LXVD2X	(47,(4),(3))
	addi	4, 4, 16
	LXVD2X	(48,(4),(3))
	addi	4, 4, 16
	LXVD2X	(49,(4),(3))
	addi	4, 4, 16
	LXVD2X	(50,(4),(3))
	addi	4, 4, 16
	LXVD2X	(51,(4),(3))
	addi	4, 4, 16
	LXVD2X	(52,(4),(3))
	addi	4, 4, 16
	LXVD2X	(53,(4),(3))
	addi	4, 4, 16
	LXVD2X	(54,(4),(3))
	addi	4, 4, 16
	LXVD2X	(55,(4),(3))
	addi	4, 4, 16
	LXVD2X	(56,(4),(3))
	addi	4, 4, 16
	LXVD2X	(57,(4),(3))
	addi	4, 4, 16
	LXVD2X	(58,(4),(3))
	addi	4, 4, 16
	LXVD2X	(59,(4),(3))
	addi	4, 4, 16
	LXVD2X	(60,(4),(3))
	addi	4, 4, 16
	LXVD2X	(61,(4),(3))
	addi	4, 4, 16
	LXVD2X	(62,(4),(3))
	addi	4, 4, 16
	LXVD2X	(63,(4),(3))
	blr
FUNC_END(loadvsx)

FUNC_START(storevsx)
	lis	4, 0
	STXVD2X	(0,(4),(3))
	addi	4, 4, 16
	STXVD2X	(1,(4),(3))
	addi	4, 4, 16
	STXVD2X	(2,(4),(3))
	addi	4, 4, 16
	STXVD2X	(3,(4),(3))
	addi	4, 4, 16
	STXVD2X	(4,(4),(3))
	addi	4, 4, 16
	STXVD2X	(5,(4),(3))
	addi	4, 4, 16
	STXVD2X	(6,(4),(3))
	addi	4, 4, 16
	STXVD2X	(7,(4),(3))
	addi	4, 4, 16
	STXVD2X	(8,(4),(3))
	addi	4, 4, 16
	STXVD2X	(9,(4),(3))
	addi	4, 4, 16
	STXVD2X	(10,(4),(3))
	addi	4, 4, 16
	STXVD2X	(11,(4),(3))
	addi	4, 4, 16
	STXVD2X	(12,(4),(3))
	addi	4, 4, 16
	STXVD2X	(13,(4),(3))
	addi	4, 4, 16
	STXVD2X	(14,(4),(3))
	addi	4, 4, 16
	STXVD2X	(15,(4),(3))
	addi	4, 4, 16
	STXVD2X	(16,(4),(3))
	addi	4, 4, 16
	STXVD2X	(17,(4),(3))
	addi	4, 4, 16
	STXVD2X	(18,(4),(3))
	addi	4, 4, 16
	STXVD2X	(19,(4),(3))
	addi	4, 4, 16
	STXVD2X	(20,(4),(3))
	addi	4, 4, 16
	STXVD2X	(21,(4),(3))
	addi	4, 4, 16
	STXVD2X	(22,(4),(3))
	addi	4, 4, 16
	STXVD2X	(23,(4),(3))
	addi	4, 4, 16
	STXVD2X	(24,(4),(3))
	addi	4, 4, 16
	STXVD2X	(25,(4),(3))
	addi	4, 4, 16
	STXVD2X	(26,(4),(3))
	addi	4, 4, 16
	STXVD2X	(27,(4),(3))
	addi	4, 4, 16
	STXVD2X	(28,(4),(3))
	addi	4, 4, 16
	STXVD2X	(29,(4),(3))
	addi	4, 4, 16
	STXVD2X	(30,(4),(3))
	addi	4, 4, 16
	STXVD2X	(31,(4),(3))
	addi	4, 4, 16
	STXVD2X	(32,(4),(3))
	addi	4, 4, 16
	STXVD2X	(33,(4),(3))
	addi	4, 4, 16
	STXVD2X	(34,(4),(3))
	addi	4, 4, 16
	STXVD2X	(35,(4),(3))
	addi	4, 4, 16
	STXVD2X	(36,(4),(3))
	addi	4, 4, 16
	STXVD2X	(37,(4),(3))
	addi	4, 4, 16
	STXVD2X	(38,(4),(3))
	addi	4, 4, 16
	STXVD2X	(39,(4),(3))
	addi	4, 4, 16
	STXVD2X	(40,(4),(3))
	addi	4, 4, 16
	STXVD2X	(41,(4),(3))
	addi	4, 4, 16
	STXVD2X	(42,(4),(3))
	addi	4, 4, 16
	STXVD2X	(43,(4),(3))
	addi	4, 4, 16
	STXVD2X	(44,(4),(3))
	addi	4, 4, 16
	STXVD2X	(45,(4),(3))
	addi	4, 4, 16
	STXVD2X	(46,(4),(3))
	addi	4, 4, 16
	STXVD2X	(47,(4),(3))
	addi	4, 4, 16
	STXVD2X	(48,(4),(3))
	addi	4, 4, 16
	STXVD2X	(49,(4),(3))
	addi	4, 4, 16
	STXVD2X	(50,(4),(3))
	addi	4, 4, 16
	STXVD2X	(51,(4),(3))
	addi	4, 4, 16
	STXVD2X	(52,(4),(3))
	addi	4, 4, 16
	STXVD2X	(53,(4),(3))
	addi	4, 4, 16
	STXVD2X	(54,(4),(3))
	addi	4, 4, 16
	STXVD2X	(55,(4),(3))
	addi	4, 4, 16
	STXVD2X	(56,(4),(3))
	addi	4, 4, 16
	STXVD2X	(57,(4),(3))
	addi	4, 4, 16
	STXVD2X	(58,(4),(3))
	addi	4, 4, 16
	STXVD2X	(59,(4),(3))
	addi	4, 4, 16
	STXVD2X	(60,(4),(3))
	addi	4, 4, 16
	STXVD2X	(61,(4),(3))
	addi	4, 4, 16
	STXVD2X	(62,(4),(3))
	addi	4, 4, 16
	STXVD2X	(63,(4),(3))
	blr
FUNC_END(storevsx)
