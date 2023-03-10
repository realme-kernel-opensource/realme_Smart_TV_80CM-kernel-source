/*
 * VCE_3_0 Register documentation
 *
 * Copyright (C) 2014  Advanced Micro Devices, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
 * AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef VCE_3_0_SH_MASK_H
#define VCE_3_0_SH_MASK_H

#define VCE_STATUS__JOB_BUSY_MASK 0x1
#define VCE_STATUS__JOB_BUSY__SHIFT 0x0
#define VCE_STATUS__VCPU_REPORT_MASK 0xfe
#define VCE_STATUS__VCPU_REPORT__SHIFT 0x1
#define VCE_STATUS__UENC_BUSY_MASK 0x100
#define VCE_STATUS__UENC_BUSY__SHIFT 0x8
#define VCE_STATUS__VCE_CONFIGURATION_MASK 0xc00000
#define VCE_STATUS__VCE_CONFIGURATION__SHIFT 0x16
#define VCE_STATUS__VCE_INSTANCE_ID_MASK 0x3000000
#define VCE_STATUS__VCE_INSTANCE_ID__SHIFT 0x18
#define VCE_VCPU_CNTL__CLK_EN_MASK 0x1
#define VCE_VCPU_CNTL__CLK_EN__SHIFT 0x0
#define VCE_VCPU_CNTL__RBBM_SOFT_RESET_MASK 0x40000
#define VCE_VCPU_CNTL__RBBM_SOFT_RESET__SHIFT 0x12
#define VCE_VCPU_CACHE_OFFSET0__OFFSET_MASK 0xfffffff
#define VCE_VCPU_CACHE_OFFSET0__OFFSET__SHIFT 0x0
#define VCE_VCPU_CACHE_SIZE0__SIZE_MASK 0xffffff
#define VCE_VCPU_CACHE_SIZE0__SIZE__SHIFT 0x0
#define VCE_VCPU_CACHE_OFFSET1__OFFSET_MASK 0xfffffff
#define VCE_VCPU_CACHE_OFFSET1__OFFSET__SHIFT 0x0
#define VCE_VCPU_CACHE_SIZE1__SIZE_MASK 0xffffff
#define VCE_VCPU_CACHE_SIZE1__SIZE__SHIFT 0x0
#define VCE_VCPU_CACHE_OFFSET2__OFFSET_MASK 0xfffffff
#define VCE_VCPU_CACHE_OFFSET2__OFFSET__SHIFT 0x0
#define VCE_VCPU_CACHE_SIZE2__SIZE_MASK 0xffffff
#define VCE_VCPU_CACHE_SIZE2__SIZE__SHIFT 0x0
#define VCE_SOFT_RESET__ECPU_SOFT_RESET_MASK 0x1
#define VCE_SOFT_RESET__ECPU_SOFT_RESET__SHIFT 0x0
#define VCE_RB_BASE_LO2__RB_BASE_LO_MASK 0xffffffc0
#define VCE_RB_BASE_LO2__RB_BASE_LO__SHIFT 0x6
#define VCE_RB_BASE_HI2__RB_BASE_HI_MASK 0xffffffff
#define VCE_RB_BASE_HI2__RB_BASE_HI__SHIFT 0x0
#define VCE_RB_SIZE2__RB_SIZE_MASK 0x7ffff0
#define VCE_RB_SIZE2__RB_SIZE__SHIFT 0x4
#define VCE_RB_RPTR2__RB_RPTR_MASK 0x7ffff0
#define VCE_RB_RPTR2__RB_RPTR__SHIFT 0x4
#define VCE_RB_WPTR2__RB_WPTR_MASK 0x7ffff0
#define VCE_RB_WPTR2__RB_WPTR__SHIFT 0x4
#define VCE_RB_BASE_LO__RB_BASE_LO_MASK 0xffffffc0
#define VCE_RB_BASE_LO__RB_BASE_LO__SHIFT 0x6
#define VCE_RB_BASE_HI__RB_BASE_HI_MASK 0xffffffff
#define VCE_RB_BASE_HI__RB_BASE_HI__SHIFT 0x0
#define VCE_RB_SIZE__RB_SIZE_MASK 0x7ffff0
#define VCE_RB_SIZE__RB_SIZE__SHIFT 0x4
#define VCE_RB_RPTR__RB_RPTR_MASK 0x7ffff0
#define VCE_RB_RPTR__RB_RPTR__SHIFT 0x4
#define VCE_RB_WPTR__RB_WPTR_MASK 0x7ffff0
#define VCE_RB_WPTR__RB_WPTR__SHIFT 0x4
#define VCE_RB_ARB_CTRL__VCE_CGTT_OVERRIDE_MASK 0x10000
#define VCE_RB_ARB_CTRL__VCE_CGTT_OVERRIDE__SHIFT 0x10
#define VCE_RB_BASE_LO3__RB_BASE_LO_MASK 0xffffffc0
#define VCE_RB_BASE_LO3__RB_BASE_LO__SHIFT 0x6
#define VCE_RB_BASE_HI3__RB_BASE_HI_MASK 0xffffffff
#define VCE_RB_BASE_HI3__RB_BASE_HI__SHIFT 0x0
#define VCE_RB_SIZE3__RB_SIZE_MASK 0x7ffff0
#define VCE_RB_SIZE3__RB_SIZE__SHIFT 0x4
#define VCE_RB_RPTR3__RB_RPTR_MASK 0x7ffff0
#define VCE_RB_RPTR3__RB_RPTR__SHIFT 0x4
#define VCE_RB_WPTR3__RB_WPTR_MASK 0x7ffff0
#define VCE_RB_WPTR3__RB_WPTR__SHIFT 0x4
#define VCE_UENC_DMA_DCLK_CTRL__WRDMCLK_FORCEON_MASK 0x1
#define VCE_UENC_DMA_DCLK_CTRL__WRDMCLK_FORCEON__SHIFT 0x0
#define VCE_UENC_DMA_DCLK_CTRL__RDDMCLK_FORCEON_MASK 0x2
#define VCE_UENC_DMA_DCLK_CTRL__RDDMCLK_FORCEON__SHIFT 0x1
#define VCE_UENC_DMA_DCLK_CTRL__REGCLK_FORCEON_MASK 0x4
#define VCE_UENC_DMA_DCLK_CTRL__REGCLK_FORCEON__SHIFT 0x2
#define VCE_SYS_INT_EN__VCE_SYS_INT_TRAP_INTERRUPT_EN_MASK 0x8
#define VCE_SYS_INT_EN__VCE_SYS_INT_TRAP_INTERRUPT_EN__SHIFT 0x3
#define VCE_SYS_INT_STATUS__VCE_SYS_INT_TRAP_INTERRUPT_INT_MASK 0x8
#define VCE_SYS_INT_STATUS__VCE_SYS_INT_TRAP_INTERRUPT_INT__SHIFT 0x3
#define VCE_SYS_INT_ACK__VCE_SYS_INT_TRAP_INTERRUPT_ACK_MASK 0x8
#define VCE_SYS_INT_ACK__VCE_SYS_INT_TRAP_INTERRUPT_ACK__SHIFT 0x3
#define VCE_LMI_VCPU_CACHE_40BIT_BAR__BAR_MASK 0xffffffff
#define VCE_LMI_VCPU_CACHE_40BIT_BAR__BAR__SHIFT 0x0
#define VCE_LMI_CTRL2__STALL_ARB_UMC_MASK 0x100
#define VCE_LMI_CTRL2__STALL_ARB_UMC__SHIFT 0x8
#define VCE_LMI_SWAP_CNTL3__RD_MC_CID_SWAP_MASK 0x3
#define VCE_LMI_SWAP_CNTL3__RD_MC_CID_SWAP__SHIFT 0x0
#define VCE_LMI_CTRL__VCPU_DATA_COHERENCY_EN_MASK 0x200000
#define VCE_LMI_CTRL__VCPU_DATA_COHERENCY_EN__SHIFT 0x15
#define VCE_LMI_SWAP_CNTL__VCPU_W_MC_SWAP_MASK 0x3
#define VCE_LMI_SWAP_CNTL__VCPU_W_MC_SWAP__SHIFT 0x0
#define VCE_LMI_SWAP_CNTL__WR_MC_CID_SWAP_MASK 0x3ffc
#define VCE_LMI_SWAP_CNTL__WR_MC_CID_SWAP__SHIFT 0x2
#define VCE_LMI_SWAP_CNTL1__VCPU_R_MC_SWAP_MASK 0x3
#define VCE_LMI_SWAP_CNTL1__VCPU_R_MC_SWAP__SHIFT 0x0
#define VCE_LMI_SWAP_CNTL1__RD_MC_CID_SWAP_MASK 0x3ffc
#define VCE_LMI_SWAP_CNTL1__RD_MC_CID_SWAP__SHIFT 0x2
#define VCE_LMI_SWAP_CNTL2__WR_MC_CID_SWAP_MASK 0xff
#define VCE_LMI_SWAP_CNTL2__WR_MC_CID_SWAP__SHIFT 0x0
#define VCE_LMI_CACHE_CTRL__VCPU_EN_MASK 0x1
#define VCE_LMI_CACHE_CTRL__VCPU_EN__SHIFT 0x0

#endif /* VCE_3_0_SH_MASK_H */
