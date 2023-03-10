/* SPDX-License-Identifier: GPL-2.0 */
/******************************************************************************
 *
 * Copyright(c) 2016  Realtek Corporation.
 *
 * Contact Information:
 * wlanfae <wlanfae@realtek.com>
 * Realtek Corporation, No. 2, Innovation Road II, Hsinchu Science Park,
 * Hsinchu 300, Taiwan.
 *
 * Larry Finger <Larry.Finger@lwfinger.net>
 *
 *****************************************************************************/
#ifndef __HALMAC_COM_REG_H__
#define __HALMAC_COM_REG_H__
/*-------------------------Modification Log-----------------------------------
 *	For Page0, it is based on Combo_And_WL_Only_Page0_Reg.xls SVN524
 *	The supported IC are 8723A, 8881A, 8723B, 8192E, 8881A
 *	8812A and 8188E is not included in page0 register
 *
 *	For other pages, it is based on MAC_Register.doc SVN502
 *	Most IC is the same with 8812A
 *-------------------------Modification Log-----------------------------------
 */

/*--------------------------Include File--------------------------------------*/
/*--------------------------Include File--------------------------------------*/

#define REG_SYS_ISO_CTRL				0x0000

#define REG_SDIO_TX_CTRL				0x10250000

#define REG_SYS_FUNC_EN				0x0002
#define REG_SYS_PW_CTRL				0x0004
#define REG_SYS_CLK_CTRL				0x0008
#define REG_SYS_EEPROM_CTRL				0x000A
#define REG_EE_VPD					0x000C
#define REG_SYS_SWR_CTRL1				0x0010
#define REG_SYS_SWR_CTRL2				0x0014

#define REG_SDIO_HIMR					0x10250014

#define REG_SYS_SWR_CTRL3				0x0018

#define REG_SDIO_HISR					0x10250018

#define REG_RSV_CTRL					0x001C

#define REG_SDIO_RX_REQ_LEN				0x1025001C

#define REG_RF_CTRL					0x001F

#define REG_SDIO_FREE_TXPG_SEQ_V1			0x1025001F

#define REG_AFE_LDO_CTRL				0x0020

#define REG_SDIO_FREE_TXPG				0x10250020

#define REG_AFE_CTRL1					0x0024

#define REG_SDIO_FREE_TXPG2				0x10250024

#define REG_AFE_CTRL2					0x0028

#define REG_SDIO_OQT_FREE_TXPG_V1			0x10250028

#define REG_AFE_CTRL3					0x002C
#define REG_EFUSE_CTRL					0x0030

#define REG_SDIO_HTSFR_INFO				0x10250030

#define REG_LDO_EFUSE_CTRL				0x0034
#define REG_PWR_OPTION_CTRL				0x0038

#define REG_SDIO_HCPWM1_V2				0x10250038
#define REG_SDIO_HCPWM2_V2				0x1025003A

#define REG_CAL_TIMER					0x003C
#define REG_ACLK_MON					0x003E
#define REG_GPIO_MUXCFG				0x0040

#define REG_SDIO_INDIRECT_REG_CFG			0x10250040

#define REG_GPIO_PIN_CTRL				0x0044

#define REG_SDIO_INDIRECT_REG_DATA			0x10250044

#define REG_GPIO_INTM					0x0048
#define REG_LED_CFG					0x004C
#define REG_FSIMR					0x0050
#define REG_FSISR					0x0054
#define REG_HSIMR					0x0058
#define REG_HSISR					0x005C
#define REG_GPIO_EXT_CTRL				0x0060

#define REG_SDIO_H2C					0x10250060

#define REG_PAD_CTRL1					0x0064

#define REG_SDIO_C2H					0x10250064

#define REG_WL_BT_PWR_CTRL				0x0068

#define REG_SDM_DEBUG					0x006C

#define REG_SYS_SDIO_CTRL				0x0070

#define REG_HCI_OPT_CTRL				0x0074

#define REG_AFE_CTRL4					0x0078

#define REG_LDO_SWR_CTRL				0x007C

#define REG_MCUFW_CTRL					0x0080

#define REG_SDIO_HRPWM1				0x10250080
#define REG_SDIO_HRPWM2				0x10250082

#define REG_MCU_TST_CFG				0x0084

#define REG_SDIO_HPS_CLKR				0x10250084
#define REG_SDIO_BUS_CTRL				0x10250085

#define REG_SDIO_HSUS_CTRL				0x10250086

#define REG_HMEBOX_E0_E1				0x0088

#define REG_SDIO_RESPONSE_TIMER			0x10250088

#define REG_SDIO_CMD_CRC				0x1025008A

#define REG_HMEBOX_E2_E3				0x008C
#define REG_WLLPS_CTRL					0x0090

#define REG_SDIO_HSISR					0x10250090
#define REG_SDIO_HSIMR					0x10250091

#define REG_AFE_CTRL5					0x0094

#define REG_GPIO_DEBOUNCE_CTRL				0x0098
#define REG_RPWM2					0x009C
#define REG_SYSON_FSM_MON				0x00A0

#define REG_AFE_CTRL6					0x00A4

#define REG_PMC_DBG_CTRL1				0x00A8

#define REG_AFE_CTRL7					0x00AC

#define REG_HIMR0					0x00B0
#define REG_HISR0					0x00B4
#define REG_HIMR1					0x00B8
#define REG_HISR1					0x00BC
#define REG_DBG_PORT_SEL				0x00C0

#define REG_SDIO_ERR_RPT				0x102500C0
#define REG_SDIO_CMD_ERRCNT				0x102500C1
#define REG_SDIO_DATA_ERRCNT				0x102500C2

#define REG_PAD_CTRL2					0x00C4

#define REG_SDIO_CMD_ERR_CONTENT			0x102500C4

#define REG_SDIO_CRC_ERR_IDX				0x102500C9
#define REG_SDIO_DATA_CRC				0x102500CA
#define REG_SDIO_DATA_REPLY_TIME			0x102500CB

#define REG_PMC_DBG_CTRL2				0x00CC
#define REG_BIST_CTRL					0x00D0
#define REG_BIST_RPT					0x00D4
#define REG_MEM_CTRL					0x00D8

#define REG_AFE_CTRL8					0x00DC

#define REG_USB_SIE_INTF				0x00E0
#define REG_PCIE_MIO_INTF				0x00E4
#define REG_PCIE_MIO_INTD				0x00E8

#define REG_WLRF1					0x00EC

#define REG_SYS_CFG1					0x00F0
#define REG_SYS_STATUS1				0x00F4
#define REG_SYS_STATUS2				0x00F8
#define REG_SYS_CFG2					0x00FC
#define REG_CR						0x0100

#define REG_PKT_BUFF_ACCESS_CTRL			0x0106

#define REG_TSF_CLK_STATE				0x0108
#define REG_TXDMA_PQ_MAP				0x010C
#define REG_TRXFF_BNDY					0x0114

#define REG_PTA_I2C_MBOX				0x0118

#define REG_RXFF_BNDY					0x011C

#define REG_FE1IMR					0x0120

#define REG_FE1ISR					0x0124

#define REG_CPWM					0x012C
#define REG_FWIMR					0x0130
#define REG_FWISR					0x0134
#define REG_FTIMR					0x0138
#define REG_FTISR					0x013C
#define REG_PKTBUF_DBG_CTRL				0x0140
#define REG_PKTBUF_DBG_DATA_L				0x0144
#define REG_PKTBUF_DBG_DATA_H				0x0148
#define REG_CPWM2					0x014C
#define REG_TC0_CTRL					0x0150
#define REG_TC1_CTRL					0x0154
#define REG_TC2_CTRL					0x0158
#define REG_TC3_CTRL					0x015C
#define REG_TC4_CTRL					0x0160
#define REG_TCUNIT_BASE				0x0164
#define REG_TC5_CTRL					0x0168
#define REG_TC6_CTRL					0x016C
#define REG_MBIST_FAIL					0x0170
#define REG_MBIST_START_PAUSE				0x0174
#define REG_MBIST_DONE					0x0178

#define REG_MBIST_FAIL_NRML				0x017C

#define REG_AES_DECRPT_DATA				0x0180
#define REG_AES_DECRPT_CFG				0x0184

#define REG_TMETER					0x0190
#define REG_OSC_32K_CTRL				0x0194
#define REG_32K_CAL_REG1				0x0198
#define REG_C2HEVT					0x01A0

#define REG_C2HEVT_1					0x01A4
#define REG_C2HEVT_2					0x01A8
#define REG_C2HEVT_3					0x01AC

#define REG_SW_DEFINED_PAGE1				0x01B8

#define REG_MCUTST_I					0x01C0
#define REG_MCUTST_II					0x01C4
#define REG_FMETHR					0x01C8
#define REG_HMETFR					0x01CC
#define REG_HMEBOX0					0x01D0
#define REG_HMEBOX1					0x01D4
#define REG_HMEBOX2					0x01D8
#define REG_HMEBOX3					0x01DC
#define REG_LLT_INIT					0x01E0

#define REG_LLT_INIT_ADDR				0x01E4

#define REG_BB_ACCESS_CTRL				0x01E8
#define REG_BB_ACCESS_DATA				0x01EC
#define REG_HMEBOX_E0					0x01F0
#define REG_HMEBOX_E1					0x01F4
#define REG_HMEBOX_E2					0x01F8
#define REG_HMEBOX_E3					0x01FC

#define REG_FIFOPAGE_CTRL_1				0x0200

#define REG_FIFOPAGE_CTRL_2				0x0204

#define REG_AUTO_LLT_V1				0x0208

#define REG_TXDMA_OFFSET_CHK				0x020C
#define REG_TXDMA_STATUS				0x0210

#define REG_TX_DMA_DBG					0x0214

#define REG_TQPNT1					0x0218
#define REG_TQPNT2					0x021C

#define REG_TQPNT3					0x0220

#define REG_TQPNT4					0x0224

#define REG_RQPN_CTRL_1				0x0228
#define REG_RQPN_CTRL_2				0x022C
#define REG_FIFOPAGE_INFO_1				0x0230
#define REG_FIFOPAGE_INFO_2				0x0234
#define REG_FIFOPAGE_INFO_3				0x0238
#define REG_FIFOPAGE_INFO_4				0x023C
#define REG_FIFOPAGE_INFO_5				0x0240

#define REG_H2C_HEAD					0x0244
#define REG_H2C_TAIL					0x0248
#define REG_H2C_READ_ADDR				0x024C
#define REG_H2C_WR_ADDR				0x0250
#define REG_H2C_INFO					0x0254

#define REG_RXDMA_AGG_PG_TH				0x0280
#define REG_RXPKT_NUM					0x0284
#define REG_RXDMA_STATUS				0x0288
#define REG_RXDMA_DPR					0x028C
#define REG_RXDMA_MODE					0x0290
#define REG_C2H_PKT					0x0294

#define REG_FWFF_C2H					0x0298
#define REG_FWFF_CTRL					0x029C
#define REG_FWFF_PKT_INFO				0x02A0

#define REG_PCIE_CTRL					0x0300

#define REG_INT_MIG					0x0304
#define REG_BCNQ_TXBD_DESA				0x0308
#define REG_MGQ_TXBD_DESA				0x0310
#define REG_VOQ_TXBD_DESA				0x0318
#define REG_VIQ_TXBD_DESA				0x0320
#define REG_BEQ_TXBD_DESA				0x0328
#define REG_BKQ_TXBD_DESA				0x0330
#define REG_RXQ_RXBD_DESA				0x0338
#define REG_HI0Q_TXBD_DESA				0x0340
#define REG_HI1Q_TXBD_DESA				0x0348
#define REG_HI2Q_TXBD_DESA				0x0350
#define REG_HI3Q_TXBD_DESA				0x0358
#define REG_HI4Q_TXBD_DESA				0x0360
#define REG_HI5Q_TXBD_DESA				0x0368
#define REG_HI6Q_TXBD_DESA				0x0370
#define REG_HI7Q_TXBD_DESA				0x0378
#define REG_MGQ_TXBD_NUM				0x0380
#define REG_RX_RXBD_NUM				0x0382
#define REG_VOQ_TXBD_NUM				0x0384
#define REG_VIQ_TXBD_NUM				0x0386
#define REG_BEQ_TXBD_NUM				0x0388
#define REG_BKQ_TXBD_NUM				0x038A
#define REG_HI0Q_TXBD_NUM				0x038C
#define REG_HI1Q_TXBD_NUM				0x038E
#define REG_HI2Q_TXBD_NUM				0x0390
#define REG_HI3Q_TXBD_NUM				0x0392
#define REG_HI4Q_TXBD_NUM				0x0394
#define REG_HI5Q_TXBD_NUM				0x0396
#define REG_HI6Q_TXBD_NUM				0x0398
#define REG_HI7Q_TXBD_NUM				0x039A
#define REG_TSFTIMER_HCI				0x039C
#define REG_BD_RWPTR_CLR				0x039C
#define REG_VOQ_TXBD_IDX				0x03A0
#define REG_VIQ_TXBD_IDX				0x03A4
#define REG_BEQ_TXBD_IDX				0x03A8
#define REG_BKQ_TXBD_IDX				0x03AC
#define REG_MGQ_TXBD_IDX				0x03B0
#define REG_RXQ_RXBD_IDX				0x03B4
#define REG_HI0Q_TXBD_IDX				0x03B8
#define REG_HI1Q_TXBD_IDX				0x03BC
#define REG_HI2Q_TXBD_IDX				0x03C0
#define REG_HI3Q_TXBD_IDX				0x03C4
#define REG_HI4Q_TXBD_IDX				0x03C8
#define REG_HI5Q_TXBD_IDX				0x03CC
#define REG_HI6Q_TXBD_IDX				0x03D0
#define REG_HI7Q_TXBD_IDX				0x03D4

#define REG_DBG_SEL_V1					0x03D8

#define REG_PCIE_HRPWM1_V1				0x03D9

#define REG_PCIE_HCPWM1_V1				0x03DA

#define REG_PCIE_CTRL2					0x03DB

#define REG_PCIE_HRPWM2_V1				0x03DC

#define REG_PCIE_HCPWM2_V1				0x03DE

#define REG_PCIE_H2C_MSG_V1				0x03E0

#define REG_PCIE_C2H_MSG_V1				0x03E4

#define REG_DBI_WDATA_V1				0x03E8

#define REG_DBI_RDATA_V1				0x03EC

#define REG_DBI_FLAG_V1				0x03F0

#define REG_MDIO_V1					0x03F4

#define REG_PCIE_MIX_CFG				0x03F8

#define REG_HCI_MIX_CFG				0x03FC

#define REG_Q0_INFO					0x0400
#define REG_Q1_INFO					0x0404
#define REG_Q2_INFO					0x0408
#define REG_Q3_INFO					0x040C
#define REG_MGQ_INFO					0x0410
#define REG_HIQ_INFO					0x0414
#define REG_BCNQ_INFO					0x0418
#define REG_TXPKT_EMPTY				0x041A
#define REG_CPU_MGQ_INFO				0x041C
#define REG_FWHW_TXQ_CTRL				0x0420

#define REG_DATAFB_SEL					0x0423

#define REG_BCNQ_BDNY_V1				0x0424

#define REG_LIFETIME_EN				0x0426

#define REG_SPEC_SIFS					0x0428
#define REG_RETRY_LIMIT				0x042A
#define REG_TXBF_CTRL					0x042C
#define REG_DARFRC					0x0430
#define REG_RARFRC					0x0438
#define REG_RRSR					0x0440
#define REG_ARFR0					0x0444
#define REG_ARFR1_V1					0x044C
#define REG_CCK_CHECK					0x0454

#define REG_AMPDU_MAX_TIME_V1				0x0455

#define REG_BCNQ1_BDNY_V1				0x0456

#define REG_AMPDU_MAX_LENGTH				0x0458
#define REG_ACQ_STOP					0x045C

#define REG_NDPA_RATE					0x045D

#define REG_TX_HANG_CTRL				0x045E
#define REG_NDPA_OPT_CTRL				0x045F

#define REG_RD_RESP_PKT_TH				0x0463
#define REG_CMDQ_INFO					0x0464
#define REG_Q4_INFO					0x0468
#define REG_Q5_INFO					0x046C
#define REG_Q6_INFO					0x0470
#define REG_Q7_INFO					0x0474

#define REG_WMAC_LBK_BUF_HD_V1				0x0478
#define REG_MGQ_BDNY_V1				0x047A

#define REG_TXRPT_CTRL					0x047C
#define REG_INIRTS_RATE_SEL				0x0480
#define REG_BASIC_CFEND_RATE				0x0481
#define REG_STBC_CFEND_RATE				0x0482
#define REG_DATA_SC					0x0483
#define REG_MACID_SLEEP3				0x0484
#define REG_MACID_SLEEP1				0x0488
#define REG_ARFR2_V1					0x048C
#define REG_ARFR3_V1					0x0494
#define REG_ARFR4					0x049C
#define REG_ARFR5					0x04A4
#define REG_TXRPT_START_OFFSET				0x04AC

#define REG_POWER_STAGE1				0x04B4

#define REG_POWER_STAGE2				0x04B8

#define REG_SW_AMPDU_BURST_MODE_CTRL			0x04BC
#define REG_PKT_LIFE_TIME				0x04C0
#define REG_STBC_SETTING				0x04C4
#define REG_STBC_SETTING2				0x04C5
#define REG_QUEUE_CTRL					0x04C6
#define REG_SINGLE_AMPDU_CTRL				0x04C7
#define REG_PROT_MODE_CTRL				0x04C8
#define REG_BAR_MODE_CTRL				0x04CC
#define REG_RA_TRY_RATE_AGG_LMT			0x04CF
#define REG_MACID_SLEEP2				0x04D0
#define REG_MACID_SLEEP				0x04D4

#define REG_HW_SEQ0					0x04D8
#define REG_HW_SEQ1					0x04DA
#define REG_HW_SEQ2					0x04DC
#define REG_HW_SEQ3					0x04DE

#define REG_NULL_PKT_STATUS_V1				0x04E0

#define REG_PTCL_ERR_STATUS				0x04E2

#define REG_NULL_PKT_STATUS_EXTEND			0x04E3

#define REG_VIDEO_ENHANCEMENT_FUN			0x04E4

#define REG_BT_POLLUTE_PKT_CNT				0x04E8
#define REG_PTCL_DBG					0x04EC

#define REG_CPUMGQ_TIMER_CTRL2				0x04F4

#define REG_DUMMY_PAGE4_V1				0x04FC
#define REG_MOREDATA					0x04FE

#define REG_EDCA_VO_PARAM				0x0500
#define REG_EDCA_VI_PARAM				0x0504
#define REG_EDCA_BE_PARAM				0x0508
#define REG_EDCA_BK_PARAM				0x050C
#define REG_BCNTCFG					0x0510
#define REG_PIFS					0x0512
#define REG_RDG_PIFS					0x0513
#define REG_SIFS					0x0514
#define REG_TSFTR_SYN_OFFSET				0x0518
#define REG_AGGR_BREAK_TIME				0x051A
#define REG_SLOT					0x051B
#define REG_TX_PTCL_CTRL				0x0520
#define REG_TXPAUSE					0x0522
#define REG_DIS_TXREQ_CLR				0x0523
#define REG_RD_CTRL					0x0524
#define REG_MBSSID_CTRL				0x0526
#define REG_P2PPS_CTRL					0x0527
#define REG_PKT_LIFETIME_CTRL				0x0528
#define REG_P2PPS_SPEC_STATE				0x052B

#define REG_BAR_TX_CTRL				0x0530

#define REG_QUEUE_INCOL_THR				0x0538
#define REG_QUEUE_INCOL_EN				0x053C

#define REG_TBTT_PROHIBIT				0x0540
#define REG_P2PPS_STATE				0x0543
#define REG_RD_NAV_NXT					0x0544
#define REG_NAV_PROT_LEN				0x0546

#define REG_BCN_CTRL					0x0550

#define REG_BCN_CTRL_CLINT0				0x0551

#define REG_MBID_NUM					0x0552
#define REG_DUAL_TSF_RST				0x0553
#define REG_MBSSID_BCN_SPACE				0x0554
#define REG_DRVERLYINT					0x0558
#define REG_BCNDMATIM					0x0559
#define REG_ATIMWND					0x055A
#define REG_USTIME_TSF					0x055C
#define REG_BCN_MAX_ERR				0x055D
#define REG_RXTSF_OFFSET_CCK				0x055E
#define REG_RXTSF_OFFSET_OFDM				0x055F
#define REG_TSFTR					0x0560

#define REG_FREERUN_CNT				0x0568

#define REG_ATIMWND1_V1				0x0570

#define REG_TBTT_PROHIBIT_INFRA			0x0571

#define REG_CTWND					0x0572
#define REG_BCNIVLCUNT					0x0573
#define REG_BCNDROPCTRL				0x0574
#define REG_HGQ_TIMEOUT_PERIOD				0x0575

#define REG_TXCMD_TIMEOUT_PERIOD			0x0576
#define REG_MISC_CTRL					0x0577
#define REG_BCN_CTRL_CLINT1				0x0578
#define REG_BCN_CTRL_CLINT2				0x0579
#define REG_BCN_CTRL_CLINT3				0x057A

#define REG_EXTEND_CTRL				0x057B

#define REG_P2PPS1_SPEC_STATE				0x057C
#define REG_P2PPS1_STATE				0x057D
#define REG_P2PPS2_SPEC_STATE				0x057E
#define REG_P2PPS2_STATE				0x057F

#define REG_PS_TIMER0					0x0580

#define REG_PS_TIMER1					0x0584

#define REG_PS_TIMER2					0x0588

#define REG_TBTT_CTN_AREA				0x058C
#define REG_FORCE_BCN_IFS				0x058E
#define REG_TXOP_MIN					0x0590
#define REG_PRE_BKF_TIME				0x0592
#define REG_CROSS_TXOP_CTRL				0x0593

#define REG_ATIMWND2					0x05A0
#define REG_ATIMWND3					0x05A1
#define REG_ATIMWND4					0x05A2
#define REG_ATIMWND5					0x05A3
#define REG_ATIMWND6					0x05A4
#define REG_ATIMWND7					0x05A5
#define REG_ATIMUGT					0x05A6
#define REG_HIQ_NO_LMT_EN				0x05A7
#define REG_DTIM_COUNTER_ROOT				0x05A8
#define REG_DTIM_COUNTER_VAP1				0x05A9
#define REG_DTIM_COUNTER_VAP2				0x05AA
#define REG_DTIM_COUNTER_VAP3				0x05AB
#define REG_DTIM_COUNTER_VAP4				0x05AC
#define REG_DTIM_COUNTER_VAP5				0x05AD
#define REG_DTIM_COUNTER_VAP6				0x05AE
#define REG_DTIM_COUNTER_VAP7				0x05AF
#define REG_DIS_ATIM					0x05B0

#define REG_EARLY_128US				0x05B1
#define REG_P2PPS1_CTRL				0x05B2
#define REG_P2PPS2_CTRL				0x05B3
#define REG_TIMER0_SRC_SEL				0x05B4
#define REG_NOA_UNIT_SEL				0x05B5
#define REG_P2POFF_DIS_TXTIME				0x05B7
#define REG_MBSSID_BCN_SPACE2				0x05B8
#define REG_MBSSID_BCN_SPACE3				0x05BC

#define REG_ACMHWCTRL					0x05C0
#define REG_ACMRSTCTRL					0x05C1
#define REG_ACMAVG					0x05C2
#define REG_VO_ADMTIME					0x05C4
#define REG_VI_ADMTIME					0x05C6
#define REG_BE_ADMTIME					0x05C8
#define REG_EDCA_RANDOM_GEN				0x05CC
#define REG_TXCMD_NOA_SEL				0x05CF
#define REG_NOA_PARAM					0x05E0

#define REG_P2P_RST					0x05F0
#define REG_SCHEDULER_RST				0x05F1

#define REG_SCH_TXCMD					0x05F8
#define REG_PAGE5_DUMMY				0x05FC
#define REG_WMAC_CR					0x0600

#define REG_WMAC_FWPKT_CR				0x0601

#define REG_BWOPMODE					0x0603

#define REG_TCR					0x0604
#define REG_RCR					0x0608
#define REG_RX_PKT_LIMIT				0x060C
#define REG_RX_DLK_TIME				0x060D
#define REG_RX_DRVINFO_SZ				0x060F
#define REG_MACID					0x0610
#define REG_BSSID					0x0618
#define REG_MAR					0x0620
#define REG_MBIDCAMCFG_1				0x0628
#define REG_MBIDCAMCFG_2				0x062C

#define REG_WMAC_TCR_TSFT_OFS				0x0630
#define REG_UDF_THSD					0x0632
#define REG_ZLD_NUM					0x0633

#define REG_STMP_THSD					0x0634
#define REG_WMAC_TXTIMEOUT				0x0635
#define REG_MCU_TEST_2_V1				0x0636

#define REG_USTIME_EDCA				0x0638

#define REG_MAC_SPEC_SIFS				0x063A
#define REG_RESP_SIFS_CCK				0x063C
#define REG_RESP_SIFS_OFDM				0x063E
#define REG_ACKTO					0x0640
#define REG_CTS2TO					0x0641
#define REG_EIFS					0x0642

#define REG_NAV_CTRL					0x0650
#define REG_BACAMCMD					0x0654
#define REG_BACAMCONTENT				0x0658
#define REG_LBDLY					0x0660

#define REG_WMAC_BACAM_RPMEN				0x0661

#define REG_TX_RX					0x0662

#define REG_WMAC_BITMAP_CTL				0x0663

#define REG_RXERR_RPT					0x0664
#define REG_WMAC_TRXPTCL_CTL				0x0668
#define REG_CAMCMD					0x0670
#define REG_CAMWRITE					0x0674
#define REG_CAMREAD					0x0678
#define REG_CAMDBG					0x067C
#define REG_SECCFG					0x0680

#define REG_RXFILTER_CATEGORY_1			0x0682
#define REG_RXFILTER_ACTION_1				0x0683
#define REG_RXFILTER_CATEGORY_2			0x0684
#define REG_RXFILTER_ACTION_2				0x0685
#define REG_RXFILTER_CATEGORY_3			0x0686
#define REG_RXFILTER_ACTION_3				0x0687
#define REG_RXFLTMAP3					0x0688
#define REG_RXFLTMAP4					0x068A
#define REG_RXFLTMAP5					0x068C
#define REG_RXFLTMAP6					0x068E

#define REG_WOW_CTRL					0x0690

#define REG_NAN_RX_TSF_FILTER				0x0691

#define REG_PS_RX_INFO					0x0692
#define REG_WMMPS_UAPSD_TID				0x0693
#define REG_LPNAV_CTRL					0x0694

#define REG_WKFMCAM_CMD				0x0698
#define REG_WKFMCAM_RWD				0x069C

#define REG_RXFLTMAP0					0x06A0
#define REG_RXFLTMAP1					0x06A2
#define REG_RXFLTMAP					0x06A4
#define REG_BCN_PSR_RPT				0x06A8

#define REG_FLC_RPC					0x06AC
#define REG_FLC_RPCT					0x06AD
#define REG_FLC_PTS					0x06AE
#define REG_FLC_TRPC					0x06AF

#define REG_RXPKTMON_CTRL				0x06B0

#define REG_STATE_MON					0x06B4

#define REG_ERROR_MON					0x06B8
#define REG_SEARCH_MACID				0x06BC

#define REG_BT_COEX_TABLE				0x06C0

#define REG_RXCMD_0					0x06D0
#define REG_RXCMD_1					0x06D4

#define REG_WMAC_RESP_TXINFO				0x06D8

#define REG_BBPSF_CTRL					0x06DC

#define REG_P2P_RX_BCN_NOA				0x06E0
#define REG_ASSOCIATED_BFMER0_INFO			0x06E4
#define REG_ASSOCIATED_BFMER1_INFO			0x06EC
#define REG_TX_CSI_RPT_PARAM_BW20			0x06F4
#define REG_TX_CSI_RPT_PARAM_BW40			0x06F8
#define REG_TX_CSI_RPT_PARAM_BW80			0x06FC
#define REG_MACID1					0x0700

#define REG_BSSID1					0x0708

#define REG_BCN_PSR_RPT1				0x0710
#define REG_ASSOCIATED_BFMEE_SEL			0x0714
#define REG_SND_PTCL_CTRL				0x0718
#define REG_RX_CSI_RPT_INFO				0x071C
#define REG_NS_ARP_CTRL				0x0720
#define REG_NS_ARP_INFO				0x0724

#define REG_BEAMFORMING_INFO_NSARP_V1			0x0728

#define REG_BEAMFORMING_INFO_NSARP			0x072C

#define REG_WMAC_RTX_CTX_SUBTYPE_CFG			0x0750

#define REG_WMAC_SWAES_CFG				0x0760

#define REG_BT_COEX_V2					0x0762

#define REG_BT_COEX					0x0764

#define REG_WLAN_ACT_MASK_CTRL				0x0768

#define REG_BT_COEX_ENHANCED_INTR_CTRL			0x076E

#define REG_BT_ACT_STATISTICS				0x0770

#define REG_BT_STATISTICS_CONTROL_REGISTER		0x0778

#define REG_BT_STATUS_REPORT_REGISTER			0x077C

#define REG_BT_INTERRUPT_CONTROL_REGISTER		0x0780

#define REG_WLAN_REPORT_TIME_OUT_CONTROL_REGISTER	0x0784

#define REG_BT_ISOLATION_TABLE_REGISTER_REGISTER	0x0785

#define REG_BT_INTERRUPT_STATUS_REGISTER		0x078F

#define REG_BT_TDMA_TIME_REGISTER			0x0790

#define REG_BT_ACT_REGISTER				0x0794

#define REG_OBFF_CTRL_BASIC				0x0798

#define REG_OBFF_CTRL2_TIMER				0x079C

#define REG_LTR_CTRL_BASIC				0x07A0

#define REG_LTR_CTRL2_TIMER_THRESHOLD			0x07A4

#define REG_LTR_IDLE_LATENCY_V1			0x07A8
#define REG_LTR_ACTIVE_LATENCY_V1			0x07AC

#define REG_ANTENNA_TRAINING_CONTROL_REGISTER		0x07B0

#define REG_WMAC_PKTCNT_RWD				0x07B8
#define REG_WMAC_PKTCNT_CTRL				0x07BC

#define REG_IQ_DUMP					0x07C0

#define REG_WMAC_FTM_CTL				0x07CC

#define REG_WMAC_IQ_MDPK_FUNC				0x07CE

#define REG_WMAC_OPTION_FUNCTION			0x07D0

#define REG_RX_FILTER_FUNCTION				0x07DA

#define REG_NDP_SIG					0x07E0
#define REG_TXCMD_INFO_FOR_RSP_PKT			0x07E4

#define REG_RTS_ADDRESS_0				0x07F0

#define REG_RTS_ADDRESS_1				0x07F8

#define REG__RPFM_MAP1					0x07FE

#define REG_SYS_CFG3					0x1000
#define REG_SYS_CFG4					0x1034

#define REG_SYS_CFG5					0x1070

#define REG_CPU_DMEM_CON				0x1080

#define REG_BOOT_REASON				0x1088
#define REG_NFCPAD_CTRL				0x10A8

#define REG_HIMR2					0x10B0
#define REG_HISR2					0x10B4
#define REG_HIMR3					0x10B8
#define REG_HISR3					0x10BC
#define REG_SW_MDIO					0x10C0
#define REG_SW_FLUSH					0x10C4

#define REG_H2C_PKT_READADDR				0x10D0
#define REG_H2C_PKT_WRITEADDR				0x10D4

#define REG_MEM_PWR_CRTL				0x10D8

#define REG_FW_DBG0					0x10E0
#define REG_FW_DBG1					0x10E4
#define REG_FW_DBG2					0x10E8
#define REG_FW_DBG3					0x10EC
#define REG_FW_DBG4					0x10F0
#define REG_FW_DBG5					0x10F4
#define REG_FW_DBG6					0x10F8
#define REG_FW_DBG7					0x10FC
#define REG_CR_EXT					0x1100
#define REG_FWFF					0x1114

#define REG_RXFF_PTR_V1				0x1118
#define REG_RXFF_WTR_V1				0x111C

#define REG_FE2IMR					0x1120
#define REG_FE2ISR					0x1124
#define REG_FE3IMR					0x1128
#define REG_FE3ISR					0x112C
#define REG_FE4IMR					0x1130
#define REG_FE4ISR					0x1134
#define REG_FT1IMR					0x1138
#define REG_FT1ISR					0x113C
#define REG_SPWR0					0x1140
#define REG_SPWR1					0x1144
#define REG_SPWR2					0x1148
#define REG_SPWR3					0x114C
#define REG_POWSEQ					0x1150

#define REG_TC7_CTRL_V1				0x1158
#define REG_TC8_CTRL_V1				0x115C

#define REG_FT2IMR					0x11E0
#define REG_FT2ISR					0x11E4

#define REG_MSG2					0x11F0
#define REG_MSG3					0x11F4
#define REG_MSG4					0x11F8
#define REG_MSG5					0x11FC
#define REG_DDMA_CH0SA					0x1200
#define REG_DDMA_CH0DA					0x1204
#define REG_DDMA_CH0CTRL				0x1208
#define REG_DDMA_CH1SA					0x1210
#define REG_DDMA_CH1DA					0x1214
#define REG_DDMA_CH1CTRL				0x1218
#define REG_DDMA_CH2SA					0x1220
#define REG_DDMA_CH2DA					0x1224
#define REG_DDMA_CH2CTRL				0x1228
#define REG_DDMA_CH3SA					0x1230
#define REG_DDMA_CH3DA					0x1234
#define REG_DDMA_CH3CTRL				0x1238
#define REG_DDMA_CH4SA					0x1240
#define REG_DDMA_CH4DA					0x1244
#define REG_DDMA_CH4CTRL				0x1248
#define REG_DDMA_CH5SA					0x1250
#define REG_DDMA_CH5DA					0x1254

#define REG_REG_DDMA_CH5CTRL				0x1258

#define REG_DDMA_INT_MSK				0x12E0
#define REG_DDMA_CHSTATUS				0x12E8
#define REG_DDMA_CHKSUM				0x12F0
#define REG_DDMA_MONITOR				0x12FC

#define REG_STC_INT_CS					0x1300
#define REG_ST_INT_CFG					0x1304
#define REG_CMU_DLY_CTRL				0x1310
#define REG_CMU_DLY_CFG				0x1314
#define REG_H2CQ_TXBD_DESA				0x1320
#define REG_H2CQ_TXBD_NUM				0x1328
#define REG_H2CQ_TXBD_IDX				0x132C
#define REG_H2CQ_CSR					0x1330

#define REG_CHANGE_PCIE_SPEED				0x1350

#define REG_OLD_DEHANG					0x13F4

#define REG_Q0_Q1_INFO					0x1400
#define REG_Q2_Q3_INFO					0x1404
#define REG_Q4_Q5_INFO					0x1408
#define REG_Q6_Q7_INFO					0x140C
#define REG_MGQ_HIQ_INFO				0x1410
#define REG_CMDQ_BCNQ_INFO				0x1414
#define REG_USEREG_SETTING				0x1420
#define REG_AESIV_SETTING				0x1424
#define REG_BF0_TIME_SETTING				0x1428
#define REG_BF1_TIME_SETTING				0x142C
#define REG_BF_TIMEOUT_EN				0x1430
#define REG_MACID_RELEASE0				0x1434
#define REG_MACID_RELEASE1				0x1438
#define REG_MACID_RELEASE2				0x143C
#define REG_MACID_RELEASE3				0x1440
#define REG_MACID_RELEASE_SETTING			0x1444
#define REG_FAST_EDCA_VOVI_SETTING			0x1448
#define REG_FAST_EDCA_BEBK_SETTING			0x144C
#define REG_MACID_DROP0				0x1450
#define REG_MACID_DROP1				0x1454
#define REG_MACID_DROP2				0x1458
#define REG_MACID_DROP3				0x145C

#define REG_R_MACID_RELEASE_SUCCESS_0			0x1460
#define REG_R_MACID_RELEASE_SUCCESS_1			0x1464
#define REG_R_MACID_RELEASE_SUCCESS_2			0x1468
#define REG_R_MACID_RELEASE_SUCCESS_3			0x146C
#define REG_MGG_FIFO_CRTL				0x1470
#define REG_MGG_FIFO_INT				0x1474
#define REG_MGG_FIFO_LIFETIME				0x1478
#define REG_R_MACID_RELEASE_SUCCESS_CLEAR_OFFSET	0x147C

#define REG_MACID_SHCUT_OFFSET				0x1480

#define REG_MU_TX_CTL					0x14C0
#define REG_MU_STA_GID_VLD				0x14C4
#define REG_MU_STA_USER_POS_INFO			0x14C8
#define REG_MU_TRX_DBG_CNT				0x14D0

#define REG_CPUMGQ_TX_TIMER				0x1500
#define REG_PS_TIMER_A					0x1504
#define REG_PS_TIMER_B					0x1508
#define REG_PS_TIMER_C					0x150C
#define REG_PS_TIMER_ABC_CPUMGQ_TIMER_CRTL		0x1510
#define REG_CPUMGQ_TX_TIMER_EARLY			0x1514
#define REG_PS_TIMER_A_EARLY				0x1515
#define REG_PS_TIMER_B_EARLY				0x1516
#define REG_PS_TIMER_C_EARLY				0x1517

#define REG_BCN_PSR_RPT2				0x1600
#define REG_BCN_PSR_RPT3				0x1604
#define REG_BCN_PSR_RPT4				0x1608
#define REG_A1_ADDR_MASK				0x160C
#define REG_MACID2					0x1620
#define REG_BSSID2					0x1628
#define REG_MACID3					0x1630
#define REG_BSSID3					0x1638
#define REG_MACID4					0x1640
#define REG_BSSID4					0x1648

#define REG_NOA_REPORT					0x1650
#define REG_PWRBIT_SETTING				0x1660
#define REG_WMAC_MU_BF_OPTION				0x167C

#define REG_WMAC_MU_ARB				0x167E
#define REG_WMAC_MU_OPTION				0x167F
#define REG_WMAC_MU_BF_CTL				0x1680

#define REG_WMAC_MU_BFRPT_PARA				0x1682

#define REG_WMAC_ASSOCIATED_MU_BFMEE2			0x1684
#define REG_WMAC_ASSOCIATED_MU_BFMEE3			0x1686
#define REG_WMAC_ASSOCIATED_MU_BFMEE4			0x1688
#define REG_WMAC_ASSOCIATED_MU_BFMEE5			0x168A
#define REG_WMAC_ASSOCIATED_MU_BFMEE6			0x168C
#define REG_WMAC_ASSOCIATED_MU_BFMEE7			0x168E

#define REG_TRANSMIT_ADDRSS_0				0x16A0
#define REG_TRANSMIT_ADDRSS_1				0x16A8
#define REG_TRANSMIT_ADDRSS_2				0x16B0
#define REG_TRANSMIT_ADDRSS_3				0x16B8
#define REG_TRANSMIT_ADDRSS_4				0x16C0

#define REG_WL2LTECOEX_INDIRECT_ACCESS_CTRL_V1	0x1700
#define REG_WL2LTECOEX_INDIRECT_ACCESS_WRITE_DATA_V1	0x1704
#define REG_WL2LTECOEX_INDIRECT_ACCESS_READ_DATA_V1	0x1708

/* ----------------------------------------------------- */
/*	*/
/* 0xFB00h ~ 0xFCFFh	TX/RX packet buffer affress */
/*	*/
/* ----------------------------------------------------- */
#define REG_RXPKTBUF_STARTADDR	0xFB00
#define REG_TXPKTBUF_STARTADDR	0xFC00

/* ----------------------------------------------------- */
/*	*/
/* 0xFD00h ~ 0xFDFFh	8051 CPU Local REG */
/*	*/
/* ----------------------------------------------------- */
#define REG_SYS_CTRL		0xFD00
#define REG_PONSTS_RPT1		0xFD01
#define REG_PONSTS_RPT2		0xFD02
#define REG_PONSTS_RPT3		0xFD03
#define REG_PONSTS_RPT4		0xFD04	/* 0x84 */
#define REG_PONSTS_RPT5		0xFD05	/* 0x85 */
#define REG_8051ERRFLAG		0xFD08
#define REG_8051ERRFLAG_MASK	0xFD09
#define REG_TXADDRH		0xFD10	/* Tx Packet High address */
#define REG_RXADDRH		0xFD11	/* Rx Packet High address */
#define REG_TXADDRH_EXT		0xFD12	/* 0xFD12[0] : for 8051 access txpktbuf
					 * high64k as external register
					 */

#define REG_U3_STATE		0xFD48	/* (Read only)
					 * [7:4] : usb3 changed last state.
					 * [3:0] : usb3 state
					 */

/* for MAILBOX */
#define REG_OUTDATA0		0xFD50
#define REG_OUTDATA1		0xFD54
#define REG_OUTRDY		0xFD58	/* bit[0] : OutReady,
					 * bit[1] : OutEmptyIntEn
					 */

#define REG_INDATA0		0xFD60
#define REG_INDATA1		0xFD64
#define REG_INRDY		0xFD68	/* bit[0] : InReady,
					 * bit[1] : InRdyIntEn
					 */

/* MCU ERROR debug REG */
#define REG_MCUERR_PCLSB	0xFD90	/* PC[7:0] */
#define REG_MCUERR_PCMSB	0xFD91	/* PC[15:8] */
#define REG_MCUERR_ACC		0xFD92
#define REG_MCUERR_B		0xFD93
#define REG_MCUERR_DPTRLSB	0xFD94	/* DPTR[7:0] */
#define REG_MCUERR_DPTRMSB	0xFD95	/* DPTR[15:8] */
#define REG_MCUERR_SP		0xFD96	/* SP[7:0] */
#define REG_MCUERR_IE		0xFD97	/* IE[7:0] */
#define REG_MCUERR_EIE		0xFD98	/* EIE[7:0] */
#define REG_VERA_SIM		0xFD9F
/* 0xFD99~0xFD9F are reserved.. */

/* ----------------------------------------------------- */
/*	*/
/* 0xFE00h ~ 0xFEFFh	USB Configuration */
/*	*/
/* ----------------------------------------------------- */

/* RTS5101 USB Register Definition */
#define REG_USB_SETUP_DEC_INT		0xFE00
#define REG_USB_DMACTL			0xFE01
#define REG_USB_IRQSTAT0		0xFE02
#define REG_USB_IRQSTAT1		0xFE03
#define REG_USB_IRQEN0			0xFE04
#define REG_USB_IRQEN1			0xFE05
#define REG_USB_AUTOPTRL		0xFE06
#define REG_USB_AUTOPTRH		0xFE07
#define REG_USB_AUTODAT			0xFE08

#define REG_USB_SCRATCH0		0xFE09
#define REG_USB_SCRATCH1		0xFE0A
#define REG_USB_SEEPROM			0xFE0B
#define REG_USB_GPIO0			0xFE0C
#define REG_USB_GPIO0DIR		0xFE0D
#define REG_USB_CLKSEL			0xFE0E
#define REG_USB_BOOTCTL			0xFE0F

#define REG_USB_USBCTL			0xFE10
#define REG_USB_USBSTAT			0xFE11
#define REG_USB_DEVADDR			0xFE12
#define REG_USB_USBTEST			0xFE13
#define REG_USB_FNUM0			0xFE14
#define REG_USB_FNUM1			0xFE15

#define REG_USB_EP_IDX			0xFE20
#define REG_USB_EP_CFG			0xFE21
#define REG_USB_EP_CTL			0xFE22
#define REG_USB_EP_STAT			0xFE23
#define REG_USB_EP_IRQ			0xFE24
#define REG_USB_EP_IRQEN		0xFE25
#define REG_USB_EP_MAXPKT0		0xFE26
#define REG_USB_EP_MAXPKT1		0xFE27
#define REG_USB_EP_DAT			0xFE28
#define REG_USB_EP_BC0			0xFE29
#define REG_USB_EP_BC1			0xFE2A
#define REG_USB_EP_TC0			0xFE2B
#define REG_USB_EP_TC1			0xFE2C
#define REG_USB_EP_TC2			0xFE2D
#define REG_USB_EP_CTL2			0xFE2E

#define REG_USB_INFO			0xFE17
#define REG_USB_SPECIAL_OPTION		0xFE55
#define REG_USB_DMA_AGG_TO		0xFE5B
#define REG_USB_AGG_TO			0xFE5C
#define REG_USB_AGG_TH			0xFE5D

#define REG_USB_VID			0xFE60
#define REG_USB_PID			0xFE62
#define REG_USB_OPT			0xFE64
#define REG_USB_CONFIG			0xFE65	/* RX EP setting.
						 * 0xFE65 Bit[3:0] : RXQ,
						 *        Bit[7:4] : INTQ
						 */
						/* TX EP setting.
						 * 0xFE66 Bit[3:0] : TXQ0,
						 *        Bit[7:4] : TXQ1,
						 * 0xFE67 Bit[3:0] : TXQ2
						 */
#define REG_USB_PHY_PARA1 0xFE68 /* Bit[7:4]: XCVR_SEN	(USB PHY 0xE2[7:4]),
				  * Bit[3:0]: XCVR_SH	(USB PHY 0xE2[3:0])
				  */
#define REG_USB_PHY_PARA2 0xFE69 /* Bit[7:5]: XCVR_BG	(USB PHY 0xE3[5:3]),
				  * Bit[4:2]: XCVR_DR	(USB PHY 0xE3[2:0]),
				  * Bit[1]: SE0_LVL	(USB PHY 0xE5[7]),
				  * Bit[0]: FORCE_XTL_ON (USB PHY 0xE5[1])
				  */
#define REG_USB_PHY_PARA3 0xFE6A /* Bit[7:5]: XCVR_SRC	(USB PHY 0xE5[4:2]),
				  * Bit[4]: LATE_DLLEN	(USB PHY 0xF0[4]),
				  * Bit[3]: HS_LP_MODE	(USB PHY 0xF0[3]),
				  * Bit[2]: UTMI_POS_OUT (USB PHY 0xF1 [7]),
				  * Bit[1:0]: TX_DELAY	(USB PHY 0xF1 [2:1])
				  */
#define REG_USB_PHY_PARA4		0xFE6B	/* (USB PHY 0xE7[7:0]) */
#define REG_USB_OPT2			0xFE6C
#define REG_USB_MAC_ADDR			0xFE70	/* 0xFE70~0xFE75 */
#define REG_USB_MANUFACTURE_SETTING	0xFE80	/* 0xFE80~0xFE90 Max: 32 bytes*/
#define REG_USB_PRODUCT_STRING		0xFEA0	/* 0xFEA0~0xFECF Max: 48 bytes*/
#define REG_USB_SERIAL_NUMBER_STRING	0xFED0	/* 0xFED0~0xFEDF Max: 12 bytes*/

#define REG_USB_ALTERNATE_SETTING	0xFE4F
#define REG_USB_INT_BINTERVAL		0xFE6E
#define REG_USB_GPS_EP_CONFIG		0xFE6D

#endif	/* __HALMAC_COM_REG_H__ */
