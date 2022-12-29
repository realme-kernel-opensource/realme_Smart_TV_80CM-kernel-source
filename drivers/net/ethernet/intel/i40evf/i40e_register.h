/* SPDX-License-Identifier: GPL-2.0 */
/* Copyright(c) 2013 - 2018 Intel Corporation. */

#ifndef _I40E_REGISTER_H_
#define _I40E_REGISTER_H_

#define I40E_VFMSIX_PBA1(_i) (0x00002000 + ((_i) * 4)) /* _i=0...19 */ /* Reset: VFLR */
#define I40E_VFMSIX_PBA1_MAX_INDEX 19
#define I40E_VFMSIX_PBA1_PENBIT_SHIFT 0
#define I40E_VFMSIX_PBA1_PENBIT_MASK I40E_MASK(0xFFFFFFFF, I40E_VFMSIX_PBA1_PENBIT_SHIFT)
#define I40E_VFMSIX_TADD1(_i) (0x00002100 + ((_i) * 16)) /* _i=0...639 */ /* Reset: VFLR */
#define I40E_VFMSIX_TADD1_MAX_INDEX 639
#define I40E_VFMSIX_TADD1_MSIXTADD10_SHIFT 0
#define I40E_VFMSIX_TADD1_MSIXTADD10_MASK I40E_MASK(0x3, I40E_VFMSIX_TADD1_MSIXTADD10_SHIFT)
#define I40E_VFMSIX_TADD1_MSIXTADD_SHIFT 2
#define I40E_VFMSIX_TADD1_MSIXTADD_MASK I40E_MASK(0x3FFFFFFF, I40E_VFMSIX_TADD1_MSIXTADD_SHIFT)
#define I40E_VFMSIX_TMSG1(_i) (0x00002108 + ((_i) * 16)) /* _i=0...639 */ /* Reset: VFLR */
#define I40E_VFMSIX_TMSG1_MAX_INDEX 639
#define I40E_VFMSIX_TMSG1_MSIXTMSG_SHIFT 0
#define I40E_VFMSIX_TMSG1_MSIXTMSG_MASK I40E_MASK(0xFFFFFFFF, I40E_VFMSIX_TMSG1_MSIXTMSG_SHIFT)
#define I40E_VFMSIX_TUADD1(_i) (0x00002104 + ((_i) * 16)) /* _i=0...639 */ /* Reset: VFLR */
#define I40E_VFMSIX_TUADD1_MAX_INDEX 639
#define I40E_VFMSIX_TUADD1_MSIXTUADD_SHIFT 0
#define I40E_VFMSIX_TUADD1_MSIXTUADD_MASK I40E_MASK(0xFFFFFFFF, I40E_VFMSIX_TUADD1_MSIXTUADD_SHIFT)
#define I40E_VFMSIX_TVCTRL1(_i) (0x0000210C + ((_i) * 16)) /* _i=0...639 */ /* Reset: VFLR */
#define I40E_VFMSIX_TVCTRL1_MAX_INDEX 639
#define I40E_VFMSIX_TVCTRL1_MASK_SHIFT 0
#define I40E_VFMSIX_TVCTRL1_MASK_MASK I40E_MASK(0x1, I40E_VFMSIX_TVCTRL1_MASK_SHIFT)
#define I40E_VF_ARQBAH1 0x00006000 /* Reset: EMPR */
#define I40E_VF_ARQBAH1_ARQBAH_SHIFT 0
#define I40E_VF_ARQBAH1_ARQBAH_MASK I40E_MASK(0xFFFFFFFF, I40E_VF_ARQBAH1_ARQBAH_SHIFT)
#define I40E_VF_ARQBAL1 0x00006C00 /* Reset: EMPR */
#define I40E_VF_ARQBAL1_ARQBAL_SHIFT 0
#define I40E_VF_ARQBAL1_ARQBAL_MASK I40E_MASK(0xFFFFFFFF, I40E_VF_ARQBAL1_ARQBAL_SHIFT)
#define I40E_VF_ARQH1 0x00007400 /* Reset: EMPR */
#define I40E_VF_ARQH1_ARQH_SHIFT 0
#define I40E_VF_ARQH1_ARQH_MASK I40E_MASK(0x3FF, I40E_VF_ARQH1_ARQH_SHIFT)
#define I40E_VF_ARQLEN1 0x00008000 /* Reset: EMPR */
#define I40E_VF_ARQLEN1_ARQLEN_SHIFT 0
#define I40E_VF_ARQLEN1_ARQLEN_MASK I40E_MASK(0x3FF, I40E_VF_ARQLEN1_ARQLEN_SHIFT)
#define I40E_VF_ARQLEN1_ARQVFE_SHIFT 28
#define I40E_VF_ARQLEN1_ARQVFE_MASK I40E_MASK(0x1, I40E_VF_ARQLEN1_ARQVFE_SHIFT)
#define I40E_VF_ARQLEN1_ARQOVFL_SHIFT 29
#define I40E_VF_ARQLEN1_ARQOVFL_MASK I40E_MASK(0x1, I40E_VF_ARQLEN1_ARQOVFL_SHIFT)
#define I40E_VF_ARQLEN1_ARQCRIT_SHIFT 30
#define I40E_VF_ARQLEN1_ARQCRIT_MASK I40E_MASK(0x1, I40E_VF_ARQLEN1_ARQCRIT_SHIFT)
#define I40E_VF_ARQLEN1_ARQENABLE_SHIFT 31
#define I40E_VF_ARQLEN1_ARQENABLE_MASK I40E_MASK(0x1, I40E_VF_ARQLEN1_ARQENABLE_SHIFT)
#define I40E_VF_ARQT1 0x00007000 /* Reset: EMPR */
#define I40E_VF_ARQT1_ARQT_SHIFT 0
#define I40E_VF_ARQT1_ARQT_MASK I40E_MASK(0x3FF, I40E_VF_ARQT1_ARQT_SHIFT)
#define I40E_VF_ATQBAH1 0x00007800 /* Reset: EMPR */
#define I40E_VF_ATQBAH1_ATQBAH_SHIFT 0
#define I40E_VF_ATQBAH1_ATQBAH_MASK I40E_MASK(0xFFFFFFFF, I40E_VF_ATQBAH1_ATQBAH_SHIFT)
#define I40E_VF_ATQBAL1 0x00007C00 /* Reset: EMPR */
#define I40E_VF_ATQBAL1_ATQBAL_SHIFT 0
#define I40E_VF_ATQBAL1_ATQBAL_MASK I40E_MASK(0xFFFFFFFF, I40E_VF_ATQBAL1_ATQBAL_SHIFT)
#define I40E_VF_ATQH1 0x00006400 /* Reset: EMPR */
#define I40E_VF_ATQH1_ATQH_SHIFT 0
#define I40E_VF_ATQH1_ATQH_MASK I40E_MASK(0x3FF, I40E_VF_ATQH1_ATQH_SHIFT)
#define I40E_VF_ATQLEN1 0x00006800 /* Reset: EMPR */
#define I40E_VF_ATQLEN1_ATQLEN_SHIFT 0
#define I40E_VF_ATQLEN1_ATQLEN_MASK I40E_MASK(0x3FF, I40E_VF_ATQLEN1_ATQLEN_SHIFT)
#define I40E_VF_ATQLEN1_ATQVFE_SHIFT 28
#define I40E_VF_ATQLEN1_ATQVFE_MASK I40E_MASK(0x1, I40E_VF_ATQLEN1_ATQVFE_SHIFT)
#define I40E_VF_ATQLEN1_ATQOVFL_SHIFT 29
#define I40E_VF_ATQLEN1_ATQOVFL_MASK I40E_MASK(0x1, I40E_VF_ATQLEN1_ATQOVFL_SHIFT)
#define I40E_VF_ATQLEN1_ATQCRIT_SHIFT 30
#define I40E_VF_ATQLEN1_ATQCRIT_MASK I40E_MASK(0x1, I40E_VF_ATQLEN1_ATQCRIT_SHIFT)
#define I40E_VF_ATQLEN1_ATQENABLE_SHIFT 31
#define I40E_VF_ATQLEN1_ATQENABLE_MASK I40E_MASK(0x1, I40E_VF_ATQLEN1_ATQENABLE_SHIFT)
#define I40E_VF_ATQT1 0x00008400 /* Reset: EMPR */
#define I40E_VF_ATQT1_ATQT_SHIFT 0
#define I40E_VF_ATQT1_ATQT_MASK I40E_MASK(0x3FF, I40E_VF_ATQT1_ATQT_SHIFT)
#define I40E_VFGEN_RSTAT 0x00008800 /* Reset: VFR */
#define I40E_VFGEN_RSTAT_VFR_STATE_SHIFT 0
#define I40E_VFGEN_RSTAT_VFR_STATE_MASK I40E_MASK(0x3, I40E_VFGEN_RSTAT_VFR_STATE_SHIFT)
#define I40E_VFINT_DYN_CTL01 0x00005C00 /* Reset: VFR */
#define I40E_VFINT_DYN_CTL01_INTENA_SHIFT 0
#define I40E_VFINT_DYN_CTL01_INTENA_MASK I40E_MASK(0x1, I40E_VFINT_DYN_CTL01_INTENA_SHIFT)
#define I40E_VFINT_DYN_CTL01_CLEARPBA_SHIFT 1
#define I40E_VFINT_DYN_CTL01_CLEARPBA_MASK I40E_MASK(0x1, I40E_VFINT_DYN_CTL01_CLEARPBA_SHIFT)
#define I40E_VFINT_DYN_CTL01_SWINT_TRIG_SHIFT 2
#define I40E_VFINT_DYN_CTL01_SWINT_TRIG_MASK I40E_MASK(0x1, I40E_VFINT_DYN_CTL01_SWINT_TRIG_SHIFT)
#define I40E_VFINT_DYN_CTL01_ITR_INDX_SHIFT 3
#define I40E_VFINT_DYN_CTL01_ITR_INDX_MASK I40E_MASK(0x3, I40E_VFINT_DYN_CTL01_ITR_INDX_SHIFT)
#define I40E_VFINT_DYN_CTL01_INTERVAL_SHIFT 5
#define I40E_VFINT_DYN_CTL01_INTERVAL_MASK I40E_MASK(0xFFF, I40E_VFINT_DYN_CTL01_INTERVAL_SHIFT)
#define I40E_VFINT_DYN_CTL01_SW_ITR_INDX_ENA_SHIFT 24
#define I40E_VFINT_DYN_CTL01_SW_ITR_INDX_ENA_MASK I40E_MASK(0x1, I40E_VFINT_DYN_CTL01_SW_ITR_INDX_ENA_SHIFT)
#define I40E_VFINT_DYN_CTL01_SW_ITR_INDX_SHIFT 25
#define I40E_VFINT_DYN_CTL01_SW_ITR_INDX_MASK I40E_MASK(0x3, I40E_VFINT_DYN_CTL01_SW_ITR_INDX_SHIFT)
#define I40E_VFINT_DYN_CTL01_INTENA_MSK_SHIFT 31
#define I40E_VFINT_DYN_CTL01_INTENA_MSK_MASK I40E_MASK(0x1, I40E_VFINT_DYN_CTL01_INTENA_MSK_SHIFT)
#define I40E_VFINT_DYN_CTLN1(_INTVF) (0x00003800 + ((_INTVF) * 4)) /* _i=0...15 */ /* Reset: VFR */
#define I40E_VFINT_DYN_CTLN1_MAX_INDEX 15
#define I40E_VFINT_DYN_CTLN1_INTENA_SHIFT 0
#define I40E_VFINT_DYN_CTLN1_INTENA_MASK I40E_MASK(0x1, I40E_VFINT_DYN_CTLN1_INTENA_SHIFT)
#define I40E_VFINT_DYN_CTLN1_CLEARPBA_SHIFT 1
#define I40E_VFINT_DYN_CTLN1_CLEARPBA_MASK I40E_MASK(0x1, I40E_VFINT_DYN_CTLN1_CLEARPBA_SHIFT)
#define I40E_VFINT_DYN_CTLN1_SWINT_TRIG_SHIFT 2
#define I40E_VFINT_DYN_CTLN1_SWINT_TRIG_MASK I40E_MASK(0x1, I40E_VFINT_DYN_CTLN1_SWINT_TRIG_SHIFT)
#define I40E_VFINT_DYN_CTLN1_ITR_INDX_SHIFT 3
#define I40E_VFINT_DYN_CTLN1_ITR_INDX_MASK I40E_MASK(0x3, I40E_VFINT_DYN_CTLN1_ITR_INDX_SHIFT)
#define I40E_VFINT_DYN_CTLN1_INTERVAL_SHIFT 5
#define I40E_VFINT_DYN_CTLN1_INTERVAL_MASK I40E_MASK(0xFFF, I40E_VFINT_DYN_CTLN1_INTERVAL_SHIFT)
#define I40E_VFINT_DYN_CTLN1_SW_ITR_INDX_ENA_SHIFT 24
#define I40E_VFINT_DYN_CTLN1_SW_ITR_INDX_ENA_MASK I40E_MASK(0x1, I40E_VFINT_DYN_CTLN1_SW_ITR_INDX_ENA_SHIFT)
#define I40E_VFINT_DYN_CTLN1_SW_ITR_INDX_SHIFT 25
#define I40E_VFINT_DYN_CTLN1_SW_ITR_INDX_MASK I40E_MASK(0x3, I40E_VFINT_DYN_CTLN1_SW_ITR_INDX_SHIFT)
#define I40E_VFINT_DYN_CTLN1_INTENA_MSK_SHIFT 31
#define I40E_VFINT_DYN_CTLN1_INTENA_MSK_MASK I40E_MASK(0x1, I40E_VFINT_DYN_CTLN1_INTENA_MSK_SHIFT)
#define I40E_VFINT_ICR0_ENA1 0x00005000 /* Reset: CORER */
#define I40E_VFINT_ICR0_ENA1_LINK_STAT_CHANGE_SHIFT 25
#define I40E_VFINT_ICR0_ENA1_LINK_STAT_CHANGE_MASK I40E_MASK(0x1, I40E_VFINT_ICR0_ENA1_LINK_STAT_CHANGE_SHIFT)
#define I40E_VFINT_ICR0_ENA1_ADMINQ_SHIFT 30
#define I40E_VFINT_ICR0_ENA1_ADMINQ_MASK I40E_MASK(0x1, I40E_VFINT_ICR0_ENA1_ADMINQ_SHIFT)
#define I40E_VFINT_ICR0_ENA1_RSVD_SHIFT 31
#define I40E_VFINT_ICR0_ENA1_RSVD_MASK I40E_MASK(0x1, I40E_VFINT_ICR0_ENA1_RSVD_SHIFT)
#define I40E_VFINT_ICR01 0x00004800 /* Reset: CORER */
#define I40E_VFINT_ICR01_INTEVENT_SHIFT 0
#define I40E_VFINT_ICR01_INTEVENT_MASK I40E_MASK(0x1, I40E_VFINT_ICR01_INTEVENT_SHIFT)
#define I40E_VFINT_ICR01_QUEUE_0_SHIFT 1
#define I40E_VFINT_ICR01_QUEUE_0_MASK I40E_MASK(0x1, I40E_VFINT_ICR01_QUEUE_0_SHIFT)
#define I40E_VFINT_ICR01_QUEUE_1_SHIFT 2
#define I40E_VFINT_ICR01_QUEUE_1_MASK I40E_MASK(0x1, I40E_VFINT_ICR01_QUEUE_1_SHIFT)
#define I40E_VFINT_ICR01_QUEUE_2_SHIFT 3
#define I40E_VFINT_ICR01_QUEUE_2_MASK I40E_MASK(0x1, I40E_VFINT_ICR01_QUEUE_2_SHIFT)
#define I40E_VFINT_ICR01_QUEUE_3_SHIFT 4
#define I40E_VFINT_ICR01_QUEUE_3_MASK I40E_MASK(0x1, I40E_VFINT_ICR01_QUEUE_3_SHIFT)
#define I40E_VFINT_ICR01_LINK_STAT_CHANGE_SHIFT 25
#define I40E_VFINT_ICR01_LINK_STAT_CHANGE_MASK I40E_MASK(0x1, I40E_VFINT_ICR01_LINK_STAT_CHANGE_SHIFT)
#define I40E_VFINT_ICR01_ADMINQ_SHIFT 30
#define I40E_VFINT_ICR01_ADMINQ_MASK I40E_MASK(0x1, I40E_VFINT_ICR01_ADMINQ_SHIFT)
#define I40E_VFINT_ICR01_SWINT_SHIFT 31
#define I40E_VFINT_ICR01_SWINT_MASK I40E_MASK(0x1, I40E_VFINT_ICR01_SWINT_SHIFT)
#define I40E_VFINT_ITR01(_i) (0x00004C00 + ((_i) * 4)) /* _i=0...2 */ /* Reset: VFR */
#define I40E_VFINT_ITR01_MAX_INDEX 2
#define I40E_VFINT_ITR01_INTERVAL_SHIFT 0
#define I40E_VFINT_ITR01_INTERVAL_MASK I40E_MASK(0xFFF, I40E_VFINT_ITR01_INTERVAL_SHIFT)
#define I40E_VFINT_ITRN1(_i, _INTVF) (0x00002800 + ((_i) * 64 + (_INTVF) * 4)) /* _i=0...2, _INTVF=0...15 */ /* Reset: VFR */
#define I40E_VFINT_ITRN1_MAX_INDEX 2
#define I40E_VFINT_ITRN1_INTERVAL_SHIFT 0
#define I40E_VFINT_ITRN1_INTERVAL_MASK I40E_MASK(0xFFF, I40E_VFINT_ITRN1_INTERVAL_SHIFT)
#define I40E_VFINT_STAT_CTL01 0x00005400 /* Reset: CORER */
#define I40E_VFINT_STAT_CTL01_OTHER_ITR_INDX_SHIFT 2
#define I40E_VFINT_STAT_CTL01_OTHER_ITR_INDX_MASK I40E_MASK(0x3, I40E_VFINT_STAT_CTL01_OTHER_ITR_INDX_SHIFT)
#define I40E_QRX_TAIL1(_Q) (0x00002000 + ((_Q) * 4)) /* _i=0...15 */ /* Reset: CORER */
#define I40E_QRX_TAIL1_MAX_INDEX 15
#define I40E_QRX_TAIL1_TAIL_SHIFT 0
#define I40E_QRX_TAIL1_TAIL_MASK I40E_MASK(0x1FFF, I40E_QRX_TAIL1_TAIL_SHIFT)
#define I40E_QTX_TAIL1(_Q) (0x00000000 + ((_Q) * 4)) /* _i=0...15 */ /* Reset: PFR */
#define I40E_QTX_TAIL1_MAX_INDEX 15
#define I40E_QTX_TAIL1_TAIL_SHIFT 0
#define I40E_QTX_TAIL1_TAIL_MASK I40E_MASK(0x1FFF, I40E_QTX_TAIL1_TAIL_SHIFT)
#define I40E_VFMSIX_PBA 0x00002000 /* Reset: VFLR */
#define I40E_VFMSIX_PBA_PENBIT_SHIFT 0
#define I40E_VFMSIX_PBA_PENBIT_MASK I40E_MASK(0xFFFFFFFF, I40E_VFMSIX_PBA_PENBIT_SHIFT)
#define I40E_VFMSIX_TADD(_i) (0x00000000 + ((_i) * 16)) /* _i=0...16 */ /* Reset: VFLR */
#define I40E_VFMSIX_TADD_MAX_INDEX 16
#define I40E_VFMSIX_TADD_MSIXTADD10_SHIFT 0
#define I40E_VFMSIX_TADD_MSIXTADD10_MASK I40E_MASK(0x3, I40E_VFMSIX_TADD_MSIXTADD10_SHIFT)
#define I40E_VFMSIX_TADD_MSIXTADD_SHIFT 2
#define I40E_VFMSIX_TADD_MSIXTADD_MASK I40E_MASK(0x3FFFFFFF, I40E_VFMSIX_TADD_MSIXTADD_SHIFT)
#define I40E_VFMSIX_TMSG(_i) (0x00000008 + ((_i) * 16)) /* _i=0...16 */ /* Reset: VFLR */
#define I40E_VFMSIX_TMSG_MAX_INDEX 16
#define I40E_VFMSIX_TMSG_MSIXTMSG_SHIFT 0
#define I40E_VFMSIX_TMSG_MSIXTMSG_MASK I40E_MASK(0xFFFFFFFF, I40E_VFMSIX_TMSG_MSIXTMSG_SHIFT)
#define I40E_VFMSIX_TUADD(_i) (0x00000004 + ((_i) * 16)) /* _i=0...16 */ /* Reset: VFLR */
#define I40E_VFMSIX_TUADD_MAX_INDEX 16
#define I40E_VFMSIX_TUADD_MSIXTUADD_SHIFT 0
#define I40E_VFMSIX_TUADD_MSIXTUADD_MASK I40E_MASK(0xFFFFFFFF, I40E_VFMSIX_TUADD_MSIXTUADD_SHIFT)
#define I40E_VFMSIX_TVCTRL(_i) (0x0000000C + ((_i) * 16)) /* _i=0...16 */ /* Reset: VFLR */
#define I40E_VFMSIX_TVCTRL_MAX_INDEX 16
#define I40E_VFMSIX_TVCTRL_MASK_SHIFT 0
#define I40E_VFMSIX_TVCTRL_MASK_MASK I40E_MASK(0x1, I40E_VFMSIX_TVCTRL_MASK_SHIFT)
#define I40E_VFCM_PE_ERRDATA 0x0000DC00 /* Reset: VFR */
#define I40E_VFCM_PE_ERRDATA_ERROR_CODE_SHIFT 0
#define I40E_VFCM_PE_ERRDATA_ERROR_CODE_MASK I40E_MASK(0xF, I40E_VFCM_PE_ERRDATA_ERROR_CODE_SHIFT)
#define I40E_VFCM_PE_ERRDATA_Q_TYPE_SHIFT 4
#define I40E_VFCM_PE_ERRDATA_Q_TYPE_MASK I40E_MASK(0x7, I40E_VFCM_PE_ERRDATA_Q_TYPE_SHIFT)
#define I40E_VFCM_PE_ERRDATA_Q_NUM_SHIFT 8
#define I40E_VFCM_PE_ERRDATA_Q_NUM_MASK I40E_MASK(0x3FFFF, I40E_VFCM_PE_ERRDATA_Q_NUM_SHIFT)
#define I40E_VFCM_PE_ERRINFO 0x0000D800 /* Reset: VFR */
#define I40E_VFCM_PE_ERRINFO_ERROR_VALID_SHIFT 0
#define I40E_VFCM_PE_ERRINFO_ERROR_VALID_MASK I40E_MASK(0x1, I40E_VFCM_PE_ERRINFO_ERROR_VALID_SHIFT)
#define I40E_VFCM_PE_ERRINFO_ERROR_INST_SHIFT 4
#define I40E_VFCM_PE_ERRINFO_ERROR_INST_MASK I40E_MASK(0x7, I40E_VFCM_PE_ERRINFO_ERROR_INST_SHIFT)
#define I40E_VFCM_PE_ERRINFO_DBL_ERROR_CNT_SHIFT 8
#define I40E_VFCM_PE_ERRINFO_DBL_ERROR_CNT_MASK I40E_MASK(0xFF, I40E_VFCM_PE_ERRINFO_DBL_ERROR_CNT_SHIFT)
#define I40E_VFCM_PE_ERRINFO_RLU_ERROR_CNT_SHIFT 16
#define I40E_VFCM_PE_ERRINFO_RLU_ERROR_CNT_MASK I40E_MASK(0xFF, I40E_VFCM_PE_ERRINFO_RLU_ERROR_CNT_SHIFT)
#define I40E_VFCM_PE_ERRINFO_RLS_ERROR_CNT_SHIFT 24
#define I40E_VFCM_PE_ERRINFO_RLS_ERROR_CNT_MASK I40E_MASK(0xFF, I40E_VFCM_PE_ERRINFO_RLS_ERROR_CNT_SHIFT)
#define I40E_VFQF_HENA(_i) (0x0000C400 + ((_i) * 4)) /* _i=0...1 */ /* Reset: CORER */
#define I40E_VFQF_HENA_MAX_INDEX 1
#define I40E_VFQF_HENA_PTYPE_ENA_SHIFT 0
#define I40E_VFQF_HENA_PTYPE_ENA_MASK I40E_MASK(0xFFFFFFFF, I40E_VFQF_HENA_PTYPE_ENA_SHIFT)
#define I40E_VFQF_HKEY(_i) (0x0000CC00 + ((_i) * 4)) /* _i=0...12 */ /* Reset: CORER */
#define I40E_VFQF_HKEY_MAX_INDEX 12
#define I40E_VFQF_HKEY_KEY_0_SHIFT 0
#define I40E_VFQF_HKEY_KEY_0_MASK I40E_MASK(0xFF, I40E_VFQF_HKEY_KEY_0_SHIFT)
#define I40E_VFQF_HKEY_KEY_1_SHIFT 8
#define I40E_VFQF_HKEY_KEY_1_MASK I40E_MASK(0xFF, I40E_VFQF_HKEY_KEY_1_SHIFT)
#define I40E_VFQF_HKEY_KEY_2_SHIFT 16
#define I40E_VFQF_HKEY_KEY_2_MASK I40E_MASK(0xFF, I40E_VFQF_HKEY_KEY_2_SHIFT)
#define I40E_VFQF_HKEY_KEY_3_SHIFT 24
#define I40E_VFQF_HKEY_KEY_3_MASK I40E_MASK(0xFF, I40E_VFQF_HKEY_KEY_3_SHIFT)
#define I40E_VFQF_HLUT(_i) (0x0000D000 + ((_i) * 4)) /* _i=0...15 */ /* Reset: CORER */
#define I40E_VFQF_HLUT_MAX_INDEX 15
#define I40E_VFQF_HLUT_LUT0_SHIFT 0
#define I40E_VFQF_HLUT_LUT0_MASK I40E_MASK(0xF, I40E_VFQF_HLUT_LUT0_SHIFT)
#define I40E_VFQF_HLUT_LUT1_SHIFT 8
#define I40E_VFQF_HLUT_LUT1_MASK I40E_MASK(0xF, I40E_VFQF_HLUT_LUT1_SHIFT)
#define I40E_VFQF_HLUT_LUT2_SHIFT 16
#define I40E_VFQF_HLUT_LUT2_MASK I40E_MASK(0xF, I40E_VFQF_HLUT_LUT2_SHIFT)
#define I40E_VFQF_HLUT_LUT3_SHIFT 24
#define I40E_VFQF_HLUT_LUT3_MASK I40E_MASK(0xF, I40E_VFQF_HLUT_LUT3_SHIFT)
#define I40E_VFQF_HREGION(_i) (0x0000D400 + ((_i) * 4)) /* _i=0...7 */ /* Reset: CORER */
#define I40E_VFQF_HREGION_MAX_INDEX 7
#define I40E_VFQF_HREGION_OVERRIDE_ENA_0_SHIFT 0
#define I40E_VFQF_HREGION_OVERRIDE_ENA_0_MASK I40E_MASK(0x1, I40E_VFQF_HREGION_OVERRIDE_ENA_0_SHIFT)
#define I40E_VFQF_HREGION_REGION_0_SHIFT 1
#define I40E_VFQF_HREGION_REGION_0_MASK I40E_MASK(0x7, I40E_VFQF_HREGION_REGION_0_SHIFT)
#define I40E_VFQF_HREGION_OVERRIDE_ENA_1_SHIFT 4
#define I40E_VFQF_HREGION_OVERRIDE_ENA_1_MASK I40E_MASK(0x1, I40E_VFQF_HREGION_OVERRIDE_ENA_1_SHIFT)
#define I40E_VFQF_HREGION_REGION_1_SHIFT 5
#define I40E_VFQF_HREGION_REGION_1_MASK I40E_MASK(0x7, I40E_VFQF_HREGION_REGION_1_SHIFT)
#define I40E_VFQF_HREGION_OVERRIDE_ENA_2_SHIFT 8
#define I40E_VFQF_HREGION_OVERRIDE_ENA_2_MASK I40E_MASK(0x1, I40E_VFQF_HREGION_OVERRIDE_ENA_2_SHIFT)
#define I40E_VFQF_HREGION_REGION_2_SHIFT 9
#define I40E_VFQF_HREGION_REGION_2_MASK I40E_MASK(0x7, I40E_VFQF_HREGION_REGION_2_SHIFT)
#define I40E_VFQF_HREGION_OVERRIDE_ENA_3_SHIFT 12
#define I40E_VFQF_HREGION_OVERRIDE_ENA_3_MASK I40E_MASK(0x1, I40E_VFQF_HREGION_OVERRIDE_ENA_3_SHIFT)
#define I40E_VFQF_HREGION_REGION_3_SHIFT 13
#define I40E_VFQF_HREGION_REGION_3_MASK I40E_MASK(0x7, I40E_VFQF_HREGION_REGION_3_SHIFT)
#define I40E_VFQF_HREGION_OVERRIDE_ENA_4_SHIFT 16
#define I40E_VFQF_HREGION_OVERRIDE_ENA_4_MASK I40E_MASK(0x1, I40E_VFQF_HREGION_OVERRIDE_ENA_4_SHIFT)
#define I40E_VFQF_HREGION_REGION_4_SHIFT 17
#define I40E_VFQF_HREGION_REGION_4_MASK I40E_MASK(0x7, I40E_VFQF_HREGION_REGION_4_SHIFT)
#define I40E_VFQF_HREGION_OVERRIDE_ENA_5_SHIFT 20
#define I40E_VFQF_HREGION_OVERRIDE_ENA_5_MASK I40E_MASK(0x1, I40E_VFQF_HREGION_OVERRIDE_ENA_5_SHIFT)
#define I40E_VFQF_HREGION_REGION_5_SHIFT 21
#define I40E_VFQF_HREGION_REGION_5_MASK I40E_MASK(0x7, I40E_VFQF_HREGION_REGION_5_SHIFT)
#define I40E_VFQF_HREGION_OVERRIDE_ENA_6_SHIFT 24
#define I40E_VFQF_HREGION_OVERRIDE_ENA_6_MASK I40E_MASK(0x1, I40E_VFQF_HREGION_OVERRIDE_ENA_6_SHIFT)
#define I40E_VFQF_HREGION_REGION_6_SHIFT 25
#define I40E_VFQF_HREGION_REGION_6_MASK I40E_MASK(0x7, I40E_VFQF_HREGION_REGION_6_SHIFT)
#define I40E_VFQF_HREGION_OVERRIDE_ENA_7_SHIFT 28
#define I40E_VFQF_HREGION_OVERRIDE_ENA_7_MASK I40E_MASK(0x1, I40E_VFQF_HREGION_OVERRIDE_ENA_7_SHIFT)
#define I40E_VFQF_HREGION_REGION_7_SHIFT 29
#define I40E_VFQF_HREGION_REGION_7_MASK I40E_MASK(0x7, I40E_VFQF_HREGION_REGION_7_SHIFT)
#define I40E_VFINT_DYN_CTL01_WB_ON_ITR_SHIFT 30
#define I40E_VFINT_DYN_CTL01_WB_ON_ITR_MASK I40E_MASK(0x1, I40E_VFINT_DYN_CTL01_WB_ON_ITR_SHIFT)
#define I40E_VFINT_DYN_CTLN1_WB_ON_ITR_SHIFT 30
#define I40E_VFINT_DYN_CTLN1_WB_ON_ITR_MASK I40E_MASK(0x1, I40E_VFINT_DYN_CTLN1_WB_ON_ITR_SHIFT)
#define I40E_VFPE_AEQALLOC1 0x0000A400 /* Reset: VFR */
#define I40E_VFPE_AEQALLOC1_AECOUNT_SHIFT 0
#define I40E_VFPE_AEQALLOC1_AECOUNT_MASK I40E_MASK(0xFFFFFFFF, I40E_VFPE_AEQALLOC1_AECOUNT_SHIFT)
#define I40E_VFPE_CCQPHIGH1 0x00009800 /* Reset: VFR */
#define I40E_VFPE_CCQPHIGH1_PECCQPHIGH_SHIFT 0
#define I40E_VFPE_CCQPHIGH1_PECCQPHIGH_MASK I40E_MASK(0xFFFFFFFF, I40E_VFPE_CCQPHIGH1_PECCQPHIGH_SHIFT)
#define I40E_VFPE_CCQPLOW1 0x0000AC00 /* Reset: VFR */
#define I40E_VFPE_CCQPLOW1_PECCQPLOW_SHIFT 0
#define I40E_VFPE_CCQPLOW1_PECCQPLOW_MASK I40E_MASK(0xFFFFFFFF, I40E_VFPE_CCQPLOW1_PECCQPLOW_SHIFT)
#define I40E_VFPE_CCQPSTATUS1 0x0000B800 /* Reset: VFR */
#define I40E_VFPE_CCQPSTATUS1_CCQP_DONE_SHIFT 0
#define I40E_VFPE_CCQPSTATUS1_CCQP_DONE_MASK I40E_MASK(0x1, I40E_VFPE_CCQPSTATUS1_CCQP_DONE_SHIFT)
#define I40E_VFPE_CCQPSTATUS1_HMC_PROFILE_SHIFT 4
#define I40E_VFPE_CCQPSTATUS1_HMC_PROFILE_MASK I40E_MASK(0x7, I40E_VFPE_CCQPSTATUS1_HMC_PROFILE_SHIFT)
#define I40E_VFPE_CCQPSTATUS1_RDMA_EN_VFS_SHIFT 16
#define I40E_VFPE_CCQPSTATUS1_RDMA_EN_VFS_MASK I40E_MASK(0x3F, I40E_VFPE_CCQPSTATUS1_RDMA_EN_VFS_SHIFT)
#define I40E_VFPE_CCQPSTATUS1_CCQP_ERR_SHIFT 31
#define I40E_VFPE_CCQPSTATUS1_CCQP_ERR_MASK I40E_MASK(0x1, I40E_VFPE_CCQPSTATUS1_CCQP_ERR_SHIFT)
#define I40E_VFPE_CQACK1 0x0000B000 /* Reset: VFR */
#define I40E_VFPE_CQACK1_PECQID_SHIFT 0
#define I40E_VFPE_CQACK1_PECQID_MASK I40E_MASK(0x1FFFF, I40E_VFPE_CQACK1_PECQID_SHIFT)
#define I40E_VFPE_CQARM1 0x0000B400 /* Reset: VFR */
#define I40E_VFPE_CQARM1_PECQID_SHIFT 0
#define I40E_VFPE_CQARM1_PECQID_MASK I40E_MASK(0x1FFFF, I40E_VFPE_CQARM1_PECQID_SHIFT)
#define I40E_VFPE_CQPDB1 0x0000BC00 /* Reset: VFR */
#define I40E_VFPE_CQPDB1_WQHEAD_SHIFT 0
#define I40E_VFPE_CQPDB1_WQHEAD_MASK I40E_MASK(0x7FF, I40E_VFPE_CQPDB1_WQHEAD_SHIFT)
#define I40E_VFPE_CQPERRCODES1 0x00009C00 /* Reset: VFR */
#define I40E_VFPE_CQPERRCODES1_CQP_MINOR_CODE_SHIFT 0
#define I40E_VFPE_CQPERRCODES1_CQP_MINOR_CODE_MASK I40E_MASK(0xFFFF, I40E_VFPE_CQPERRCODES1_CQP_MINOR_CODE_SHIFT)
#define I40E_VFPE_CQPERRCODES1_CQP_MAJOR_CODE_SHIFT 16
#define I40E_VFPE_CQPERRCODES1_CQP_MAJOR_CODE_MASK I40E_MASK(0xFFFF, I40E_VFPE_CQPERRCODES1_CQP_MAJOR_CODE_SHIFT)
#define I40E_VFPE_CQPTAIL1 0x0000A000 /* Reset: VFR */
#define I40E_VFPE_CQPTAIL1_WQTAIL_SHIFT 0
#define I40E_VFPE_CQPTAIL1_WQTAIL_MASK I40E_MASK(0x7FF, I40E_VFPE_CQPTAIL1_WQTAIL_SHIFT)
#define I40E_VFPE_CQPTAIL1_CQP_OP_ERR_SHIFT 31
#define I40E_VFPE_CQPTAIL1_CQP_OP_ERR_MASK I40E_MASK(0x1, I40E_VFPE_CQPTAIL1_CQP_OP_ERR_SHIFT)
#define I40E_VFPE_IPCONFIG01 0x00008C00 /* Reset: VFR */
#define I40E_VFPE_IPCONFIG01_PEIPID_SHIFT 0
#define I40E_VFPE_IPCONFIG01_PEIPID_MASK I40E_MASK(0xFFFF, I40E_VFPE_IPCONFIG01_PEIPID_SHIFT)
#define I40E_VFPE_IPCONFIG01_USEENTIREIDRANGE_SHIFT 16
#define I40E_VFPE_IPCONFIG01_USEENTIREIDRANGE_MASK I40E_MASK(0x1, I40E_VFPE_IPCONFIG01_USEENTIREIDRANGE_SHIFT)
#define I40E_VFPE_MRTEIDXMASK1 0x00009000 /* Reset: VFR */
#define I40E_VFPE_MRTEIDXMASK1_MRTEIDXMASKBITS_SHIFT 0
#define I40E_VFPE_MRTEIDXMASK1_MRTEIDXMASKBITS_MASK I40E_MASK(0x1F, I40E_VFPE_MRTEIDXMASK1_MRTEIDXMASKBITS_SHIFT)
#define I40E_VFPE_RCVUNEXPECTEDERROR1 0x00009400 /* Reset: VFR */
#define I40E_VFPE_RCVUNEXPECTEDERROR1_TCP_RX_UNEXP_ERR_SHIFT 0
#define I40E_VFPE_RCVUNEXPECTEDERROR1_TCP_RX_UNEXP_ERR_MASK I40E_MASK(0xFFFFFF, I40E_VFPE_RCVUNEXPECTEDERROR1_TCP_RX_UNEXP_ERR_SHIFT)
#define I40E_VFPE_TCPNOWTIMER1 0x0000A800 /* Reset: VFR */
#define I40E_VFPE_TCPNOWTIMER1_TCP_NOW_SHIFT 0
#define I40E_VFPE_TCPNOWTIMER1_TCP_NOW_MASK I40E_MASK(0xFFFFFFFF, I40E_VFPE_TCPNOWTIMER1_TCP_NOW_SHIFT)
#define I40E_VFPE_WQEALLOC1 0x0000C000 /* Reset: VFR */
#define I40E_VFPE_WQEALLOC1_PEQPID_SHIFT 0
#define I40E_VFPE_WQEALLOC1_PEQPID_MASK I40E_MASK(0x3FFFF, I40E_VFPE_WQEALLOC1_PEQPID_SHIFT)
#define I40E_VFPE_WQEALLOC1_WQE_DESC_INDEX_SHIFT 20
#define I40E_VFPE_WQEALLOC1_WQE_DESC_INDEX_MASK I40E_MASK(0xFFF, I40E_VFPE_WQEALLOC1_WQE_DESC_INDEX_SHIFT)
#endif /* _I40E_REGISTER_H_ */
