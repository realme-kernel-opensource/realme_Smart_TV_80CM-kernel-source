// SPDX-License-Identifier: GPL-2.0
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

#include "../wifi.h"
#include "../pci.h"
#include "../base.h"
#include "reg.h"
#include "def.h"
#include "fw.h"

static bool _rtl8822be_check_fw_read_last_h2c(struct ieee80211_hw *hw,
					      u8 boxnum)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	u8 val_hmetfr;
	bool result = false;

	val_hmetfr = rtl_read_byte(rtlpriv, REG_HMETFR_8822B);
	if (((val_hmetfr >> boxnum) & BIT(0)) == 0)
		result = true;
	return result;
}

static void _rtl8822be_fill_h2c_command(struct ieee80211_hw *hw, u8 element_id,
					u32 cmd_len, u8 *cmdbuffer)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_hal *rtlhal = rtl_hal(rtl_priv(hw));
	u8 boxnum;
	u16 box_reg = 0, box_extreg = 0;
	u8 u1b_tmp;
	bool isfw_read;
	u8 buf_index = 0;
	bool bwrite_success = false;
	u8 wait_h2c_limmit = 100;
	u8 boxcontent[4], boxextcontent[4];
	u32 h2c_waitcounter = 0;
	unsigned long flag;
	u8 idx;

	/* 1. Prevent race condition in setting H2C cmd.
	 * (copy from MgntActSet_RF_State().)
	 */
	while (true) {
		spin_lock_irqsave(&rtlpriv->locks.h2c_lock, flag);
		if (rtlhal->h2c_setinprogress) {
			RT_TRACE(rtlpriv, COMP_CMD, DBG_LOUD,
				 "H2C set in progress! wait..H2C_ID=%d.\n",
				 element_id);

			while (rtlhal->h2c_setinprogress) {
				spin_unlock_irqrestore(&rtlpriv->locks.h2c_lock,
						       flag);
				h2c_waitcounter++;
				RT_TRACE(rtlpriv, COMP_CMD, DBG_LOUD,
					 "Wait 100 us (%d times)...\n",
					 h2c_waitcounter);
				udelay(100);

				if (h2c_waitcounter > 1000)
					return;
				spin_lock_irqsave(&rtlpriv->locks.h2c_lock,
						  flag);
			}
			spin_unlock_irqrestore(&rtlpriv->locks.h2c_lock, flag);
		} else {
			rtlhal->h2c_setinprogress = true;
			spin_unlock_irqrestore(&rtlpriv->locks.h2c_lock, flag);
			break;
		}
	}

	while (!bwrite_success) {
		/* 2. Find the last BOX number which has been written. */
		boxnum = rtlhal->last_hmeboxnum;
		switch (boxnum) {
		case 0:
			box_reg = REG_HMEBOX0_8822B;
			box_extreg = REG_HMEBOX_E0_8822B;
			break;
		case 1:
			box_reg = REG_HMEBOX1_8822B;
			box_extreg = REG_HMEBOX_E1_8822B;
			break;
		case 2:
			box_reg = REG_HMEBOX2_8822B;
			box_extreg = REG_HMEBOX_E2_8822B;
			break;
		case 3:
			box_reg = REG_HMEBOX3_8822B;
			box_extreg = REG_HMEBOX_E3_8822B;
			break;
		default:
			RT_TRACE(rtlpriv, COMP_ERR, DBG_LOUD,
				 "switch case not process\n");
			break;
		}

		/* 3. Check if the box content is empty. */
		u1b_tmp = rtl_read_byte(rtlpriv, REG_CR_8822B);

		if (u1b_tmp == 0xea) {
			if (rtl_read_byte(rtlpriv, REG_TXDMA_STATUS_8822B) ==
				    0xea ||
			    rtl_read_byte(rtlpriv, REG_TXPKT_EMPTY_8822B) ==
				    0xea)
				rtl_write_byte(rtlpriv, REG_SYS_CFG1_8822B + 3,
					       0xff);

			RT_TRACE(rtlpriv, COMP_CMD, DBG_LOUD,
				 "REG_CR is unavaliable\n");
			break;
		}

		wait_h2c_limmit = 100;
		isfw_read = _rtl8822be_check_fw_read_last_h2c(hw, boxnum);
		while (!isfw_read) {
			wait_h2c_limmit--;
			if (wait_h2c_limmit == 0) {
				RT_TRACE(rtlpriv, COMP_CMD, DBG_WARNING,
					 "Wait too long for FW clear MB%d!!!\n",
					 boxnum);
				break;
			}
			udelay(10);
			isfw_read =
				_rtl8822be_check_fw_read_last_h2c(hw, boxnum);
			u1b_tmp = rtl_read_byte(rtlpriv, 0x130);
			RT_TRACE(rtlpriv, COMP_CMD, DBG_LOUD,
				 "Waiting for FW clear MB%d!!! 0x130 = %2x\n",
				 boxnum, u1b_tmp);
		}

		/* If Fw has not read the last H2C cmd,
		 * break and give up this H2C.
		 */
		if (!isfw_read) {
			RT_TRACE(rtlpriv, COMP_CMD, DBG_LOUD,
				 "Write H2C reg BOX[%d] fail,Fw don't read.\n",
				 boxnum);
			break;
		}
		/* 4. Fill the H2C cmd into box */
		memset(boxcontent, 0, sizeof(boxcontent));
		memset(boxextcontent, 0, sizeof(boxextcontent));
		boxcontent[0] = element_id;
		RT_TRACE(rtlpriv, COMP_CMD, DBG_LOUD,
			 "Write element_id box_reg(%4x) = %2x\n", box_reg,
			 element_id);

		switch (cmd_len) {
		case 1:
		case 2:
		case 3:
			/*boxcontent[0] &= ~(BIT(7));*/
			memcpy((u8 *)(boxcontent) + 1, cmdbuffer + buf_index,
			       cmd_len);

			for (idx = 0; idx < 4; idx++) {
				rtl_write_byte(rtlpriv, box_reg + idx,
					       boxcontent[idx]);
			}
			break;
		case 4:
		case 5:
		case 6:
		case 7:
			/*boxcontent[0] |= (BIT(7));*/
			memcpy((u8 *)(boxextcontent), cmdbuffer + buf_index + 3,
			       cmd_len - 3);
			memcpy((u8 *)(boxcontent) + 1, cmdbuffer + buf_index,
			       3);

			for (idx = 0; idx < 4; idx++) {
				rtl_write_byte(rtlpriv, box_extreg + idx,
					       boxextcontent[idx]);
			}

			for (idx = 0; idx < 4; idx++) {
				rtl_write_byte(rtlpriv, box_reg + idx,
					       boxcontent[idx]);
			}
			break;
		default:
			RT_TRACE(rtlpriv, COMP_ERR, DBG_LOUD,
				 "switch case not process\n");
			break;
		}

		bwrite_success = true;

		rtlhal->last_hmeboxnum = boxnum + 1;
		if (rtlhal->last_hmeboxnum == 4)
			rtlhal->last_hmeboxnum = 0;

		RT_TRACE(rtlpriv, COMP_CMD, DBG_LOUD,
			 "pHalData->last_hmeboxnum  = %d\n",
			 rtlhal->last_hmeboxnum);
	}

	spin_lock_irqsave(&rtlpriv->locks.h2c_lock, flag);
	rtlhal->h2c_setinprogress = false;
	spin_unlock_irqrestore(&rtlpriv->locks.h2c_lock, flag);

	RT_TRACE(rtlpriv, COMP_CMD, DBG_LOUD, "go out\n");
}

void rtl8822be_fill_h2c_cmd(struct ieee80211_hw *hw, u8 element_id, u32 cmd_len,
			    u8 *cmdbuffer)
{
	struct rtl_hal *rtlhal = rtl_hal(rtl_priv(hw));
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	u8 tmp_cmdbuf[8];

	if (!rtlhal->fw_ready) {
		WARN_ONCE(true,
			  "return H2C cmd because of Fw download fail!!!\n");
		return;
	}

	memset(tmp_cmdbuf, 0, 8);
	memcpy(tmp_cmdbuf, cmdbuffer, cmd_len);

	RT_TRACE(rtlpriv, COMP_CMD, DBG_DMESG,
		 "h2c cmd: len=%d %02X%02X%02X%02X %02X%02X%02X%02X\n", cmd_len,
		 tmp_cmdbuf[2], tmp_cmdbuf[1], tmp_cmdbuf[0], element_id,
		 tmp_cmdbuf[6], tmp_cmdbuf[5], tmp_cmdbuf[4], tmp_cmdbuf[3]);

	_rtl8822be_fill_h2c_command(hw, element_id, cmd_len, tmp_cmdbuf);
}

void rtl8822be_set_default_port_id_cmd(struct ieee80211_hw *hw)
{
	u8 h2c_set_default_port_id[H2C_DEFAULT_PORT_ID_LEN];

	SET_H2CCMD_DFTPID_PORT_ID(h2c_set_default_port_id, 0);
	SET_H2CCMD_DFTPID_MAC_ID(h2c_set_default_port_id, 0);

	rtl8822be_fill_h2c_cmd(hw, H2C_8822B_DEFAULT_PORT_ID,
			       H2C_DEFAULT_PORT_ID_LEN,
			       h2c_set_default_port_id);
}

void rtl8822be_set_fw_pwrmode_cmd(struct ieee80211_hw *hw, u8 mode)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	u8 u1_h2c_set_pwrmode[H2C_8822B_PWEMODE_LENGTH] = {0};
	static u8 prev_h2c[H2C_8822B_PWEMODE_LENGTH] = {0};
	struct rtl_ps_ctl *ppsc = rtl_psc(rtl_priv(hw));
	u8 rlbm, power_state = 0, byte5 = 0;
	u8 awake_intvl; /* DTIM = (awake_intvl - 1) */
	u8 smart_ps = 0;
	struct rtl_btc_ops *btc_ops = rtlpriv->btcoexist.btc_ops;
	bool bt_ctrl_lps = (rtlpriv->cfg->ops->get_btc_status() ?
			    btc_ops->btc_is_bt_ctrl_lps(rtlpriv) : false);
	bool bt_lps_on = (rtlpriv->cfg->ops->get_btc_status() ?
			  btc_ops->btc_is_bt_lps_on(rtlpriv) : false);

	memset(u1_h2c_set_pwrmode, 0, H2C_8822B_PWEMODE_LENGTH);

	if (bt_ctrl_lps)
		mode = (bt_lps_on ? FW_PS_MIN_MODE : FW_PS_ACTIVE_MODE);

	RT_TRACE(rtlpriv, COMP_POWER, DBG_DMESG, "FW LPS mode = %d (coex:%d)\n",
		 mode, bt_ctrl_lps);

	switch (mode) {
	case FW_PS_MIN_MODE:
		rlbm = 0;
		awake_intvl = 2;
		smart_ps = ppsc->smart_ps;
		break;
	case FW_PS_MAX_MODE:
		rlbm = 1;
		awake_intvl = 2;
		smart_ps = ppsc->smart_ps;
		break;
	case FW_PS_DTIM_MODE:
		rlbm = 2;
		awake_intvl = ppsc->reg_max_lps_awakeintvl;
		/*
		 * hw->conf.ps_dtim_period or mac->vif->bss_conf.dtim_period
		 * is only used in swlps.
		 */
		smart_ps = ppsc->smart_ps;
		break;
	case FW_PS_ACTIVE_MODE:
		rlbm = 0;
		awake_intvl = 1;
		break;
	default:
		rlbm = 2;
		awake_intvl = 4;
		smart_ps = ppsc->smart_ps;
		break;
	}

	if (rtlpriv->mac80211.p2p) {
		awake_intvl = 2;
		rlbm = 1;
	}

	if (mode == FW_PS_ACTIVE_MODE) {
		byte5 = 0x40;
		power_state = FW_PWR_STATE_ACTIVE;
	} else {
		if (bt_ctrl_lps) {
			byte5 = btc_ops->btc_get_lps_val(rtlpriv);
			power_state = btc_ops->btc_get_rpwm_val(rtlpriv);

			if (rlbm == 2 && (byte5 & BIT(4))) {
				/* Keep awake interval to 1 to prevent from
				 * decreasing coex performance
				 */
				awake_intvl = 2;
				rlbm = 2;
			}
			smart_ps = 0;
		} else {
			byte5 = 0x40;
			power_state = FW_PWR_STATE_RF_OFF;
		}
	}

	SET_H2CCMD_PWRMODE_PARM_MODE(u1_h2c_set_pwrmode, ((mode) ? 1 : 0));
	SET_H2CCMD_PWRMODE_PARM_RLBM(u1_h2c_set_pwrmode, rlbm);
	SET_H2CCMD_PWRMODE_PARM_SMART_PS(u1_h2c_set_pwrmode, smart_ps);
	SET_H2CCMD_PWRMODE_PARM_AWAKE_INTERVAL(u1_h2c_set_pwrmode, awake_intvl);
	SET_H2CCMD_PWRMODE_PARM_ALL_QUEUE_UAPSD(u1_h2c_set_pwrmode, 0);
	SET_H2CCMD_PWRMODE_PARM_PWR_STATE(u1_h2c_set_pwrmode, power_state);
	SET_H2CCMD_PWRMODE_PARM_BYTE5(u1_h2c_set_pwrmode, byte5);

	RT_PRINT_DATA(rtlpriv, COMP_CMD, DBG_DMESG,
		      "rtl8822be_set_fw_pwrmode(): u1_h2c_set_pwrmode\n",
		      u1_h2c_set_pwrmode, H2C_8822B_PWEMODE_LENGTH);
	if (rtlpriv->cfg->ops->get_btc_status())
		btc_ops->btc_record_pwr_mode(rtlpriv, u1_h2c_set_pwrmode,
					     H2C_8822B_PWEMODE_LENGTH);

	if (!memcmp(prev_h2c, u1_h2c_set_pwrmode, H2C_8822B_PWEMODE_LENGTH))
		return;
	memcpy(prev_h2c, u1_h2c_set_pwrmode, H2C_8822B_PWEMODE_LENGTH);

	rtl8822be_set_default_port_id_cmd(hw);
	rtl8822be_fill_h2c_cmd(hw, H2C_8822B_SETPWRMODE,
			       H2C_8822B_PWEMODE_LENGTH, u1_h2c_set_pwrmode);
}

void rtl8822be_set_fw_media_status_rpt_cmd(struct ieee80211_hw *hw, u8 mstatus)
{
	u8 parm[4] = {0, 0, 0, 0};
	/* parm[0]: bit0=0-->Disconnect, bit0=1-->Connect
	 *          bit1=0-->update Media Status to MACID
	 *          bit1=1-->update Media Status from MACID to MACID_End
	 * parm[1]: MACID, if this is INFRA_STA, MacID = 0
	 * parm[2]: MACID_End
	 * parm[3]: bit2-0: port ID
	 */

	SET_H2CCMD_MSRRPT_PARM_OPMODE(parm, mstatus);
	SET_H2CCMD_MSRRPT_PARM_MACID_IND(parm, 0);

	rtl8822be_fill_h2c_cmd(hw, H2C_8822B_MSRRPT, 4, parm);
}

static bool _rtl8822be_send_bcn_or_cmd_packet(struct ieee80211_hw *hw,
					      struct sk_buff *skb, u8 hw_queue)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_pci *rtlpci = rtl_pcidev(rtl_pcipriv(hw));
	struct rtl8192_tx_ring *ring;
	struct rtl_tx_desc *pdesc;
	struct rtl_tx_buffer_desc *pbd_desc;
	unsigned long flags;
	struct sk_buff *pskb = NULL;
	u8 *pdesc_or_bddesc;
	dma_addr_t dma_addr;

	if (hw_queue != BEACON_QUEUE && hw_queue != H2C_QUEUE)
		return false;

	ring = &rtlpci->tx_ring[hw_queue];

	spin_lock_irqsave(&rtlpriv->locks.irq_th_lock, flags);

	if (hw_queue == BEACON_QUEUE) {
		pdesc = &ring->desc[0];
		pbd_desc = &ring->buffer_desc[0];
		pdesc_or_bddesc = (u8 *)pbd_desc;

		/* free previous beacon queue */
		pskb = __skb_dequeue(&ring->queue);

		if (!pskb)
			goto free_prev_skb_done;

		dma_addr = rtlpriv->cfg->ops->get_desc(
				hw, (u8 *)pbd_desc, true, HW_DESC_TXBUFF_ADDR);

		pci_unmap_single(rtlpci->pdev, dma_addr, pskb->len,
				 PCI_DMA_TODEVICE);
		kfree_skb(pskb);

free_prev_skb_done:
		;

	} else { /* hw_queue == TXCMD_QUEUE */
		if (rtlpriv->cfg->ops->get_available_desc(hw, hw_queue) == 0) {
			RT_TRACE(rtlpriv, COMP_ERR, DBG_WARNING,
				 "get_available_desc fail hw_queue=%d\n",
				 hw_queue);
			spin_unlock_irqrestore(&rtlpriv->locks.irq_th_lock,
					       flags);
			return false;
		}

		pdesc = &ring->desc[ring->cur_tx_wp];
		pbd_desc = &ring->buffer_desc[ring->cur_tx_wp];
		pdesc_or_bddesc = (u8 *)pdesc;
	}

	rtlpriv->cfg->ops->fill_tx_special_desc(hw, (u8 *)pdesc, (u8 *)pbd_desc,
						skb, hw_queue);

	__skb_queue_tail(&ring->queue, skb);

	rtlpriv->cfg->ops->set_desc(hw, (u8 *)pdesc_or_bddesc, true,
				    HW_DESC_OWN, (u8 *)&hw_queue);

	spin_unlock_irqrestore(&rtlpriv->locks.irq_th_lock, flags);

	rtlpriv->cfg->ops->tx_polling(hw, hw_queue);

	return true;
}

bool rtl8822b_halmac_cb_write_data_rsvd_page(struct rtl_priv *rtlpriv, u8 *buf,
					     u32 size)
{
	struct sk_buff *skb = NULL;
	u8 u1b_tmp;
	int count;

	skb = dev_alloc_skb(size);
	if (!skb)
		return false;
	memcpy((u8 *)skb_put(skb, size), buf, size);

	if (!_rtl8822be_send_bcn_or_cmd_packet(rtlpriv->hw, skb, BEACON_QUEUE))
		return false;

	/* These code isn't actually need, because halmac will check
	 * BCN_VALID
	 */

	/* Polling Beacon Queue to send Beacon */
	u1b_tmp = rtl_read_byte(rtlpriv, REG_RX_RXBD_NUM_8822B + 1);
	count = 0;
	while ((count < 20) && (u1b_tmp & BIT(4))) {
		count++;
		udelay(10);
		u1b_tmp = rtl_read_byte(rtlpriv, REG_RX_RXBD_NUM_8822B + 1);
	}

	if (count >= 20)
		pr_err("%s polling beacon fail\n", __func__);

	return true;
}

bool rtl8822b_halmac_cb_write_data_h2c(struct rtl_priv *rtlpriv, u8 *buf,
				       u32 size)
{
	struct sk_buff *skb = NULL;

	/* without GFP_DMA, pci_map_single() may not work */
	skb = __netdev_alloc_skb(NULL, size, GFP_ATOMIC | GFP_DMA);
	memcpy((u8 *)skb_put(skb, size), buf, size);

	return _rtl8822be_send_bcn_or_cmd_packet(rtlpriv->hw, skb, H2C_QUEUE);
}

/* Rsvd page HALMAC_RSVD_DRV_PGNUM_8822B occupies 16 page (2048 byte) */
#define BEACON_PG	0 /* ->1 */
#define PSPOLL_PG	2
#define NULL_PG	3
#define PROBERSP_PG	4 /* ->5 */
#define QOS_NULL_PG	6
#define BT_QOS_NULL_PG	7

#define TOTAL_RESERVED_PKT_LEN	1024

static u8 reserved_page_packet[TOTAL_RESERVED_PKT_LEN] = {/* page size = 128 */
	/* page 0 beacon */
	0x80, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
	0xFF, 0xFF, 0x00, 0xE0, 0x4C, 0x02, 0xB1, 0x78,
	0xEC, 0x1A, 0x59, 0x0B, 0xAD, 0xD4, 0x20, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x64, 0x00, 0x10, 0x04, 0x00, 0x05, 0x54, 0x65,
	0x73, 0x74, 0x32, 0x01, 0x08, 0x82, 0x84, 0x0B,
	0x16, 0x24, 0x30, 0x48, 0x6C, 0x03, 0x01, 0x06,
	0x06, 0x02, 0x00, 0x00, 0x2A, 0x01, 0x02, 0x32,
	0x04, 0x0C, 0x12, 0x18, 0x60, 0x2D, 0x1A, 0x6C,
	0x09, 0x03, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x3D, 0x00, 0xDD, 0x07, 0x00, 0xE0, 0x4C,
	0x02, 0x02, 0x00, 0x00, 0xDD, 0x18, 0x00, 0x50,
	0xF2, 0x01, 0x01, 0x00, 0x00, 0x50, 0xF2, 0x04,
	0x01, 0x00, 0x00, 0x50, 0xF2, 0x04, 0x01, 0x00,

	/* page 1 beacon */
	0x00, 0x50, 0xF2, 0x02, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x10, 0x00, 0x30, 0x84, 0x00, 0x12, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	/* page 2  ps-poll */
	0xA4, 0x10, 0x01, 0xC0, 0xEC, 0x1A, 0x59, 0x0B,
	0xAD, 0xD4, 0x00, 0xE0, 0x4C, 0x02, 0xB1, 0x78,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x18, 0x00, 0x30, 0x84, 0x00, 0x12, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	/* page 3  null */
	0x48, 0x01, 0x00, 0x00, 0xEC, 0x1A, 0x59, 0x0B,
	0xAD, 0xD4, 0x00, 0xE0, 0x4C, 0x02, 0xB1, 0x78,
	0xEC, 0x1A, 0x59, 0x0B, 0xAD, 0xD4, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x72, 0x00, 0x30, 0x84, 0x00, 0x12, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	/* page 4  probe_resp */
	0x50, 0x00, 0x00, 0x00, 0x00, 0x40, 0x10, 0x10,
	0x00, 0x03, 0x00, 0xE0, 0x4C, 0x76, 0x00, 0x42,
	0x00, 0x40, 0x10, 0x10, 0x00, 0x03, 0x00, 0x00,
	0x9E, 0x46, 0x15, 0x32, 0x27, 0xF2, 0x2D, 0x00,
	0x64, 0x00, 0x00, 0x04, 0x00, 0x0C, 0x6C, 0x69,
	0x6E, 0x6B, 0x73, 0x79, 0x73, 0x5F, 0x77, 0x6C,
	0x61, 0x6E, 0x01, 0x04, 0x82, 0x84, 0x8B, 0x96,
	0x03, 0x01, 0x01, 0x06, 0x02, 0x00, 0x00, 0x2A,
	0x01, 0x00, 0x32, 0x08, 0x24, 0x30, 0x48, 0x6C,
	0x0C, 0x12, 0x18, 0x60, 0x2D, 0x1A, 0x6C, 0x18,
	0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x3D, 0x00, 0xDD, 0x06, 0x00, 0xE0, 0x4C, 0x02,
	0x01, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	/* page 5  probe_resp */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x1A, 0x00, 0x30, 0x84, 0x00, 0x12, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	/* page 6 qos null data */
	0xC8, 0x01, 0x00, 0x00, 0x84, 0xC9, 0xB2, 0xA7,
	0xB3, 0x6E, 0x00, 0xE0, 0x4C, 0x02, 0x51, 0x02,
	0x84, 0xC9, 0xB2, 0xA7, 0xB3, 0x6E, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x1A, 0x00, 0x30, 0x84, 0x00, 0x12, 0x00, 0x00,
	0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	/* page 7 BT-qos null data */
	0xC8, 0x01, 0x00, 0x00, 0x84, 0xC9, 0xB2, 0xA7,
	0xB3, 0x6E, 0x00, 0xE0, 0x4C, 0x02, 0x51, 0x02,
	0x84, 0xC9, 0xB2, 0xA7, 0xB3, 0x6E, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

void rtl8822be_set_fw_rsvdpagepkt(struct ieee80211_hw *hw, bool b_dl_finished)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_mac *mac = rtl_mac(rtl_priv(hw));
	struct sk_buff *skb = NULL;

	u32 totalpacketlen;
	bool rtstatus;
	u8 u1_rsvd_page_loc[7] = {0};
	bool b_dlok = false;

	u8 *beacon;
	u8 *p_pspoll;
	u8 *nullfunc;
	u8 *p_probersp;
	u8 *qosnull;
	u8 *btqosnull;

	memset(u1_rsvd_page_loc, 0, sizeof(u1_rsvd_page_loc));

	/*---------------------------------------------------------
	 *			(1) beacon
	 *---------------------------------------------------------
	 */
	beacon = &reserved_page_packet[BEACON_PG * 128];
	SET_80211_HDR_ADDRESS2(beacon, mac->mac_addr);
	SET_80211_HDR_ADDRESS3(beacon, mac->bssid);

	/*-------------------------------------------------------
	 *			(2) ps-poll
	 *--------------------------------------------------------
	 */
	p_pspoll = &reserved_page_packet[PSPOLL_PG * 128];
	SET_80211_PS_POLL_AID(p_pspoll, (mac->assoc_id | 0xc000));
	SET_80211_PS_POLL_BSSID(p_pspoll, mac->bssid);
	SET_80211_PS_POLL_TA(p_pspoll, mac->mac_addr);

	SET_H2CCMD_RSVDPAGE_LOC_PSPOLL(u1_rsvd_page_loc, PSPOLL_PG);

	/*--------------------------------------------------------
	 *			(3) null data
	 *---------------------------------------------------------
	 */
	nullfunc = &reserved_page_packet[NULL_PG * 128];
	SET_80211_HDR_ADDRESS1(nullfunc, mac->bssid);
	SET_80211_HDR_ADDRESS2(nullfunc, mac->mac_addr);
	SET_80211_HDR_ADDRESS3(nullfunc, mac->bssid);

	SET_H2CCMD_RSVDPAGE_LOC_NULL_DATA(u1_rsvd_page_loc, NULL_PG);

	/*---------------------------------------------------------
	 *			(4) probe response
	 *----------------------------------------------------------
	 */
	p_probersp = &reserved_page_packet[PROBERSP_PG * 128];
	SET_80211_HDR_ADDRESS1(p_probersp, mac->bssid);
	SET_80211_HDR_ADDRESS2(p_probersp, mac->mac_addr);
	SET_80211_HDR_ADDRESS3(p_probersp, mac->bssid);

	SET_H2CCMD_RSVDPAGE_LOC_PROBE_RSP(u1_rsvd_page_loc, PROBERSP_PG);

	/*---------------------------------------------------------
	 *			(5) QoS null data
	 *----------------------------------------------------------
	 */
	qosnull = &reserved_page_packet[QOS_NULL_PG * 128];
	SET_80211_HDR_ADDRESS1(qosnull, mac->bssid);
	SET_80211_HDR_ADDRESS2(qosnull, mac->mac_addr);
	SET_80211_HDR_ADDRESS3(qosnull, mac->bssid);

	SET_H2CCMD_RSVDPAGE_LOC_QOS_NULL_DATA(u1_rsvd_page_loc, QOS_NULL_PG);

	/*---------------------------------------------------------
	 *			(6) BT QoS null data
	 *----------------------------------------------------------
	 */
	btqosnull = &reserved_page_packet[BT_QOS_NULL_PG * 128];
	SET_80211_HDR_ADDRESS1(btqosnull, mac->bssid);
	SET_80211_HDR_ADDRESS2(btqosnull, mac->mac_addr);
	SET_80211_HDR_ADDRESS3(btqosnull, mac->bssid);

	SET_H2CCMD_RSVDPAGE_LOC_BT_QOS_NULL_DATA(u1_rsvd_page_loc,
						 BT_QOS_NULL_PG);

	totalpacketlen = TOTAL_RESERVED_PKT_LEN;

	RT_PRINT_DATA(rtlpriv, COMP_CMD, DBG_LOUD,
		      "rtl8822be_set_fw_rsvdpagepkt(): HW_VAR_SET_TX_CMD: ALL\n",
		      &reserved_page_packet[0], totalpacketlen);
	RT_PRINT_DATA(rtlpriv, COMP_CMD, DBG_LOUD,
		      "rtl8822be_set_fw_rsvdpagepkt(): HW_VAR_SET_TX_CMD: ALL\n",
		      u1_rsvd_page_loc, 3);

	skb = dev_alloc_skb(totalpacketlen);
	if (!skb)
		return;
	memcpy((u8 *)skb_put(skb, totalpacketlen), &reserved_page_packet,
	       totalpacketlen);

	rtstatus = _rtl8822be_send_bcn_or_cmd_packet(hw, skb, BEACON_QUEUE);

	if (rtstatus)
		b_dlok = true;

	if (b_dlok) {
		RT_TRACE(rtlpriv, COMP_POWER, DBG_LOUD,
			 "Set RSVD page location to Fw.\n");
		RT_PRINT_DATA(rtlpriv, COMP_CMD, DBG_LOUD, "H2C_RSVDPAGE:\n",
			      u1_rsvd_page_loc, 3);
		rtl8822be_fill_h2c_cmd(hw, H2C_8822B_RSVDPAGE,
				       sizeof(u1_rsvd_page_loc),
				       u1_rsvd_page_loc);
	} else {
		RT_TRACE(rtlpriv, COMP_ERR, DBG_WARNING,
			 "Set RSVD page location to Fw FAIL!!!!!!.\n");
	}
}

/* Should check FW support p2p or not. */
static void rtl8822be_set_p2p_ctw_period_cmd(struct ieee80211_hw *hw,
					     u8 ctwindow)
{
	u8 u1_ctwindow_period[1] = {ctwindow};

	rtl8822be_fill_h2c_cmd(hw, H2C_8822B_P2P_PS_CTW_CMD, 1,
			       u1_ctwindow_period);
}

void rtl8822be_set_p2p_ps_offload_cmd(struct ieee80211_hw *hw, u8 p2p_ps_state)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_ps_ctl *rtlps = rtl_psc(rtl_priv(hw));
	struct rtl_hal *rtlhal = rtl_hal(rtl_priv(hw));
	struct rtl_p2p_ps_info *p2pinfo = &rtlps->p2p_ps_info;
	struct p2p_ps_offload_t *p2p_ps_offload = &rtlhal->p2p_ps_offload;
	u8 i;
	u16 ctwindow;
	u32 start_time, tsf_low;

	switch (p2p_ps_state) {
	case P2P_PS_DISABLE:
		RT_TRACE(rtlpriv, COMP_FW, DBG_LOUD, "P2P_PS_DISABLE\n");
		memset(p2p_ps_offload, 0, sizeof(*p2p_ps_offload));
		break;
	case P2P_PS_ENABLE:
		RT_TRACE(rtlpriv, COMP_FW, DBG_LOUD, "P2P_PS_ENABLE\n");
		/* update CTWindow value. */
		if (p2pinfo->ctwindow > 0) {
			p2p_ps_offload->ctwindow_en = 1;
			ctwindow = p2pinfo->ctwindow;
			rtl8822be_set_p2p_ctw_period_cmd(hw, ctwindow);
		}
		/* hw only support 2 set of NoA */
		for (i = 0; i < p2pinfo->noa_num; i++) {
			/* To control the register setting for which NOA*/
			rtl_write_byte(rtlpriv, 0x5cf, (i << 4));
			if (i == 0)
				p2p_ps_offload->noa0_en = 1;
			else
				p2p_ps_offload->noa1_en = 1;
			/* config P2P NoA Descriptor Register */
			rtl_write_dword(rtlpriv, 0x5E0,
					p2pinfo->noa_duration[i]);
			rtl_write_dword(rtlpriv, 0x5E4,
					p2pinfo->noa_interval[i]);

			/*Get Current TSF value */
			tsf_low = rtl_read_dword(rtlpriv, REG_TSFTR_8822B);

			start_time = p2pinfo->noa_start_time[i];
			if (p2pinfo->noa_count_type[i] != 1) {
				while (start_time <= (tsf_low + (50 * 1024))) {
					start_time += p2pinfo->noa_interval[i];
					if (p2pinfo->noa_count_type[i] != 255)
						p2pinfo->noa_count_type[i]--;
				}
			}
			rtl_write_dword(rtlpriv, 0x5E8, start_time);
			rtl_write_dword(rtlpriv, 0x5EC,
					p2pinfo->noa_count_type[i]);
		}
		if (p2pinfo->opp_ps == 1 || p2pinfo->noa_num > 0) {
			/* rst p2p circuit */
			rtl_write_byte(rtlpriv, REG_DUAL_TSF_RST_8822B, BIT(4));
			p2p_ps_offload->offload_en = 1;

			if (rtlpriv->mac80211.p2p == P2P_ROLE_GO) {
				p2p_ps_offload->role = 1;
				p2p_ps_offload->allstasleep = 0;
			} else {
				p2p_ps_offload->role = 0;
			}
			p2p_ps_offload->discovery = 0;
		}
		break;
	case P2P_PS_SCAN:
		RT_TRACE(rtlpriv, COMP_FW, DBG_LOUD, "P2P_PS_SCAN\n");
		p2p_ps_offload->discovery = 1;
		break;
	case P2P_PS_SCAN_DONE:
		RT_TRACE(rtlpriv, COMP_FW, DBG_LOUD, "P2P_PS_SCAN_DONE\n");
		p2p_ps_offload->discovery = 0;
		p2pinfo->p2p_ps_state = P2P_PS_ENABLE;
		break;
	default:
		break;
	}

	rtl8822be_fill_h2c_cmd(hw, H2C_8822B_P2P_PS_OFFLOAD, 1,
			       (u8 *)p2p_ps_offload);
}

static
void rtl8822be_c2h_content_parsing_ext(struct ieee80211_hw *hw,
				       u8 c2h_sub_cmd_id,
				       u8 c2h_cmd_len,
				       u8 *c2h_content_buf)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_halmac_ops *halmac_ops;

	switch (c2h_sub_cmd_id) {
	case 0x0F:
		RT_TRACE(rtlpriv, COMP_FW, DBG_TRACE,
			 "[C2H], C2H_8822BE_TX_REPORT!\n");
		rtl_tx_report_handler(hw, c2h_content_buf, c2h_cmd_len);
		break;
	default:
		/* indicate c2h pkt + rx desc to halmac */
		halmac_ops = rtlpriv->halmac.ops;
		halmac_ops->halmac_c2h_handle(rtlpriv,
					      c2h_content_buf - 24 - 2 - 2,
					      c2h_cmd_len + 24 + 2 + 2);
		break;
	}
}

void rtl8822be_c2h_content_parsing(struct ieee80211_hw *hw, u8 c2h_cmd_id,
				   u8 c2h_cmd_len, u8 *tmp_buf)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_btc_ops *btc_ops = rtlpriv->btcoexist.btc_ops;

	if (c2h_cmd_id == 0xFF) {
		rtl8822be_c2h_content_parsing_ext(hw, tmp_buf[0],
						  c2h_cmd_len - 2,
						  tmp_buf + 2);
		return;
	}

	switch (c2h_cmd_id) {
	case C2H_8822B_DBG:
		RT_TRACE(rtlpriv, COMP_FW, DBG_TRACE,
			 "[C2H], C2H_8822BE_DBG!!\n");
		break;
	case C2H_8822B_TXBF:
		RT_TRACE(rtlpriv, COMP_FW, DBG_TRACE,
			 "[C2H], C2H_8822B_TXBF!!\n");
		break;
	case C2H_8822B_BT_INFO:
		RT_TRACE(rtlpriv, COMP_FW, DBG_TRACE,
			 "[C2H], C2H_8822BE_BT_INFO!!\n");
		if (rtlpriv->cfg->ops->get_btc_status())
			btc_ops->btc_btinfo_notify(rtlpriv, tmp_buf,
						   c2h_cmd_len);
		break;
	case C2H_8822B_BT_MP:
		RT_TRACE(rtlpriv, COMP_FW, DBG_TRACE,
			 "[C2H], C2H_8822BE_BT_MP!!\n");
		if (rtlpriv->cfg->ops->get_btc_status())
			btc_ops->btc_btmpinfo_notify(rtlpriv, tmp_buf,
						     c2h_cmd_len);
		break;
	default:
		if (!rtlpriv->phydm.ops->phydm_c2h_content_parsing(
			    rtlpriv, c2h_cmd_id, c2h_cmd_len, tmp_buf))
			break;

		RT_TRACE(rtlpriv, COMP_FW, DBG_TRACE,
			 "[C2H], Unknown packet!! CmdId(%#X)!\n", c2h_cmd_id);
		break;
	}
}

void rtl8822be_c2h_packet_handler(struct ieee80211_hw *hw, u8 *buffer, u8 len)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	u8 c2h_cmd_id = 0, c2h_cmd_seq = 0, c2h_cmd_len = 0;
	u8 *tmp_buf = NULL;

	c2h_cmd_id = buffer[0];
	c2h_cmd_seq = buffer[1];
	c2h_cmd_len = len - 2;
	tmp_buf = buffer + 2;

	RT_TRACE(rtlpriv, COMP_FW, DBG_TRACE,
		 "[C2H packet], c2hCmdId=0x%x, c2hCmdSeq=0x%x, c2hCmdLen=%d\n",
		 c2h_cmd_id, c2h_cmd_seq, c2h_cmd_len);

	RT_PRINT_DATA(rtlpriv, COMP_FW, DBG_TRACE,
		      "[C2H packet], Content Hex:\n", tmp_buf, c2h_cmd_len);

	switch (c2h_cmd_id) {
	case C2H_8822B_BT_INFO:
	case C2H_8822B_BT_MP:
		rtl_c2hcmd_enqueue(hw, c2h_cmd_id, c2h_cmd_len, tmp_buf);
		break;
	default:
		rtl8822be_c2h_content_parsing(hw, c2h_cmd_id, c2h_cmd_len,
					      tmp_buf);
		break;
	}
}
