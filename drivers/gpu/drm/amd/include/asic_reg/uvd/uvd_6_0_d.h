/*
 * UVD_6_0 Register documentation
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

#ifndef UVD_6_0_D_H
#define UVD_6_0_D_H

#define mmUVD_SEMA_ADDR_LOW                                                     0x3bc0
#define mmUVD_SEMA_ADDR_HIGH                                                    0x3bc1
#define mmUVD_SEMA_CMD                                                          0x3bc2
#define mmUVD_GPCOM_VCPU_CMD                                                    0x3bc3
#define mmUVD_GPCOM_VCPU_DATA0                                                  0x3bc4
#define mmUVD_GPCOM_VCPU_DATA1                                                  0x3bc5
#define mmUVD_ENGINE_CNTL                                                       0x3bc6
#define mmUVD_UDEC_ADDR_CONFIG                                                  0x3bd3
#define mmUVD_UDEC_DB_ADDR_CONFIG                                               0x3bd4
#define mmUVD_UDEC_DBW_ADDR_CONFIG                                              0x3bd5
#define mmUVD_POWER_STATUS_U                                                    0x3bfd
#define mmUVD_NO_OP                                                             0x3bff
#define mmUVD_RB_BASE_LO2                                                       0x3c21
#define mmUVD_RB_BASE_HI2                                                       0x3c22
#define mmUVD_RB_SIZE2                                                          0x3c23
#define mmUVD_RB_RPTR2                                                          0x3c24
#define mmUVD_RB_WPTR2                                                          0x3c25
#define mmUVD_RB_BASE_LO                                                        0x3c26
#define mmUVD_RB_BASE_HI                                                        0x3c27
#define mmUVD_RB_SIZE                                                           0x3c28
#define mmUVD_RB_RPTR                                                           0x3c29
#define mmUVD_RB_WPTR                                                           0x3c2a
#define mmUVD_LMI_RBC_RB_64BIT_BAR_LOW                                          0x3c69
#define mmUVD_LMI_RBC_RB_64BIT_BAR_HIGH                                         0x3c68
#define mmUVD_LMI_RBC_IB_64BIT_BAR_LOW                                          0x3c67
#define mmUVD_LMI_RBC_IB_64BIT_BAR_HIGH                                         0x3c66
#define mmUVD_LMI_VCPU_CACHE_64BIT_BAR_LOW                                      0x3c5f
#define mmUVD_LMI_VCPU_CACHE_64BIT_BAR_HIGH                                     0x3c5e
#define mmUVD_SEMA_CNTL                                                         0x3d00
#define mmUVD_RB_WPTR3                                                          0x3d1c
#define mmUVD_RB_RPTR3                                                          0x3d1b
#define mmUVD_RB_BASE_LO3                                                       0x3d1d
#define mmUVD_RB_BASE_HI3                                                       0x3d1e
#define mmUVD_RB_SIZE3                                                          0x3d1f
#define mmUVD_LMI_EXT40_ADDR                                                    0x3d26
#define mmUVD_CTX_INDEX                                                         0x3d28
#define mmUVD_CTX_DATA                                                          0x3d29
#define mmUVD_CGC_GATE                                                          0x3d2a
#define mmUVD_CGC_STATUS                                                        0x3d2b
#define mmUVD_CGC_CTRL                                                          0x3d2c
#define mmUVD_CGC_UDEC_STATUS                                                   0x3d2d
#define mmUVD_LMI_CTRL2                                                         0x3d3d
#define mmUVD_MASTINT_EN                                                        0x3d40
#define mmUVD_LMI_ADDR_EXT                                                      0x3d65
#define mmUVD_LMI_CTRL                                                          0x3d66
#define mmUVD_LMI_STATUS                                                        0x3d67
#define mmUVD_LMI_SWAP_CNTL                                                     0x3d6d
#define mmUVD_MP_SWAP_CNTL                                                      0x3d6f
#define mmUVD_MPC_CNTL                                                          0x3d77
#define mmUVD_MPC_SET_MUXA0                                                     0x3d79
#define mmUVD_MPC_SET_MUXA1                                                     0x3d7a
#define mmUVD_MPC_SET_MUXB0                                                     0x3d7b
#define mmUVD_MPC_SET_MUXB1                                                     0x3d7c
#define mmUVD_MPC_SET_MUX                                                       0x3d7d
#define mmUVD_MPC_SET_ALU                                                       0x3d7e
#define mmUVD_VCPU_CACHE_OFFSET0                                                0x3d82
#define mmUVD_VCPU_CACHE_SIZE0                                                  0x3d83
#define mmUVD_VCPU_CACHE_OFFSET1                                                0x3d84
#define mmUVD_VCPU_CACHE_SIZE1                                                  0x3d85
#define mmUVD_VCPU_CACHE_OFFSET2                                                0x3d86
#define mmUVD_VCPU_CACHE_SIZE2                                                  0x3d87
#define mmUVD_VCPU_CNTL                                                         0x3d98
#define mmUVD_SOFT_RESET                                                        0x3da0
#define mmUVD_LMI_RBC_IB_VMID                                                   0x3da1
#define mmUVD_RBC_IB_SIZE                                                       0x3da2
#define mmUVD_LMI_RBC_RB_VMID                                                   0x3da3
#define mmUVD_RBC_RB_RPTR                                                       0x3da4
#define mmUVD_RBC_RB_WPTR                                                       0x3da5
#define mmUVD_RBC_RB_WPTR_CNTL                                                  0x3da6
#define mmUVD_RBC_RB_CNTL                                                       0x3da9
#define mmUVD_RBC_RB_RPTR_ADDR                                                  0x3daa
#define mmUVD_STATUS                                                            0x3daf
#define mmUVD_SEMA_TIMEOUT_STATUS                                               0x3db0
#define mmUVD_SEMA_WAIT_INCOMPLETE_TIMEOUT_CNTL                                 0x3db1
#define mmUVD_SEMA_WAIT_FAULT_TIMEOUT_CNTL                                      0x3db2
#define mmUVD_SEMA_SIGNAL_INCOMPLETE_TIMEOUT_CNTL                               0x3db3
#define mmUVD_CONTEXT_ID                                                        0x3dbd
#define mmUVD_RBC_IB_SIZE_UPDATE                                                0x3df1
#define mmUVD_SUVD_CGC_GATE                                                     0x3be4
#define mmUVD_SUVD_CGC_STATUS                                                   0x3be5
#define mmUVD_SUVD_CGC_CTRL                                                     0x3be6
#define ixUVD_LMI_VMID_INTERNAL                                                 0x99
#define ixUVD_LMI_VMID_INTERNAL2                                                0x9a
#define ixUVD_LMI_CACHE_CTRL                                                    0x9b
#define ixUVD_LMI_SWAP_CNTL2                                                    0xaa
#define ixUVD_LMI_ADDR_EXT2                                                     0xab
#define ixUVD_CGC_MEM_CTRL                                                      0xc0
#define ixUVD_CGC_CTRL2                                                         0xc1
#define ixUVD_LMI_VMID_INTERNAL3                                                0x162
#define mmUVD_PGFSM_CONFIG                                                      0x38c0
#define mmUVD_PGFSM_READ_TILE1                                                  0x38c2
#define mmUVD_PGFSM_READ_TILE2                                                  0x38c3
#define mmUVD_POWER_STATUS                                                      0x38c4
#define mmUVD_PGFSM_READ_TILE3                                                  0x38c5
#define mmUVD_PGFSM_READ_TILE4                                                  0x38c6
#define mmUVD_PGFSM_READ_TILE5                                                  0x38c8
#define mmUVD_PGFSM_READ_TILE6                                                  0x38ee
#define mmUVD_PGFSM_READ_TILE7                                                  0x38ef
#define mmUVD_MIF_CURR_ADDR_CONFIG                                              0x3992
#define mmUVD_MIF_REF_ADDR_CONFIG                                               0x3993
#define mmUVD_MIF_RECON1_ADDR_CONFIG                                            0x39c5
#define ixUVD_MIF_SCLR_ADDR_CONFIG                                              0x4
#define mmUVD_JPEG_ADDR_CONFIG                                                  0x3a1f
#define mmUVD_GP_SCRATCH8                                                       0x3c0a
#define mmUVD_GP_SCRATCH9                                                       0x3c0b
#define mmUVD_GP_SCRATCH4                                                       0x3d38

#endif /* UVD_6_0_D_H */
