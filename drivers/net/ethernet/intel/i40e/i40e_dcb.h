/* SPDX-License-Identifier: GPL-2.0 */
/* Copyright(c) 2013 - 2018 Intel Corporation. */

#ifndef _I40E_DCB_H_
#define _I40E_DCB_H_

#include "i40e_type.h"

#define I40E_DCBX_STATUS_NOT_STARTED	0
#define I40E_DCBX_STATUS_IN_PROGRESS	1
#define I40E_DCBX_STATUS_DONE		2
#define I40E_DCBX_STATUS_MULTIPLE_PEERS	3
#define I40E_DCBX_STATUS_DISABLED	7

#define I40E_TLV_TYPE_END		0
#define I40E_TLV_TYPE_ORG		127

#define I40E_IEEE_8021QAZ_OUI		0x0080C2
#define I40E_IEEE_SUBTYPE_ETS_CFG	9
#define I40E_IEEE_SUBTYPE_ETS_REC	10
#define I40E_IEEE_SUBTYPE_PFC_CFG	11
#define I40E_IEEE_SUBTYPE_APP_PRI	12

#define I40E_CEE_DCBX_OUI		0x001b21
#define I40E_CEE_DCBX_TYPE		2

#define I40E_CEE_SUBTYPE_CTRL		1
#define I40E_CEE_SUBTYPE_PG_CFG		2
#define I40E_CEE_SUBTYPE_PFC_CFG	3
#define I40E_CEE_SUBTYPE_APP_PRI	4

#define I40E_CEE_MAX_FEAT_TYPE		3
/* Defines for LLDP TLV header */
#define I40E_LLDP_TLV_LEN_SHIFT		0
#define I40E_LLDP_TLV_LEN_MASK		(0x01FF << I40E_LLDP_TLV_LEN_SHIFT)
#define I40E_LLDP_TLV_TYPE_SHIFT	9
#define I40E_LLDP_TLV_TYPE_MASK		(0x7F << I40E_LLDP_TLV_TYPE_SHIFT)
#define I40E_LLDP_TLV_SUBTYPE_SHIFT	0
#define I40E_LLDP_TLV_SUBTYPE_MASK	(0xFF << I40E_LLDP_TLV_SUBTYPE_SHIFT)
#define I40E_LLDP_TLV_OUI_SHIFT		8
#define I40E_LLDP_TLV_OUI_MASK		(0xFFFFFF << I40E_LLDP_TLV_OUI_SHIFT)

/* Defines for IEEE ETS TLV */
#define I40E_IEEE_ETS_MAXTC_SHIFT	0
#define I40E_IEEE_ETS_MAXTC_MASK	(0x7 << I40E_IEEE_ETS_MAXTC_SHIFT)
#define I40E_IEEE_ETS_CBS_SHIFT		6
#define I40E_IEEE_ETS_CBS_MASK		BIT(I40E_IEEE_ETS_CBS_SHIFT)
#define I40E_IEEE_ETS_WILLING_SHIFT	7
#define I40E_IEEE_ETS_WILLING_MASK	BIT(I40E_IEEE_ETS_WILLING_SHIFT)
#define I40E_IEEE_ETS_PRIO_0_SHIFT	0
#define I40E_IEEE_ETS_PRIO_0_MASK	(0x7 << I40E_IEEE_ETS_PRIO_0_SHIFT)
#define I40E_IEEE_ETS_PRIO_1_SHIFT	4
#define I40E_IEEE_ETS_PRIO_1_MASK	(0x7 << I40E_IEEE_ETS_PRIO_1_SHIFT)
#define I40E_CEE_PGID_PRIO_0_SHIFT	0
#define I40E_CEE_PGID_PRIO_0_MASK	(0xF << I40E_CEE_PGID_PRIO_0_SHIFT)
#define I40E_CEE_PGID_PRIO_1_SHIFT	4
#define I40E_CEE_PGID_PRIO_1_MASK	(0xF << I40E_CEE_PGID_PRIO_1_SHIFT)
#define I40E_CEE_PGID_STRICT		15

/* Defines for IEEE TSA types */
#define I40E_IEEE_TSA_STRICT		0
#define I40E_IEEE_TSA_ETS		2

/* Defines for IEEE PFC TLV */
#define I40E_IEEE_PFC_CAP_SHIFT		0
#define I40E_IEEE_PFC_CAP_MASK		(0xF << I40E_IEEE_PFC_CAP_SHIFT)
#define I40E_IEEE_PFC_MBC_SHIFT		6
#define I40E_IEEE_PFC_MBC_MASK		BIT(I40E_IEEE_PFC_MBC_SHIFT)
#define I40E_IEEE_PFC_WILLING_SHIFT	7
#define I40E_IEEE_PFC_WILLING_MASK	BIT(I40E_IEEE_PFC_WILLING_SHIFT)

/* Defines for IEEE APP TLV */
#define I40E_IEEE_APP_SEL_SHIFT		0
#define I40E_IEEE_APP_SEL_MASK		(0x7 << I40E_IEEE_APP_SEL_SHIFT)
#define I40E_IEEE_APP_PRIO_SHIFT	5
#define I40E_IEEE_APP_PRIO_MASK		(0x7 << I40E_IEEE_APP_PRIO_SHIFT)


#pragma pack(1)

/* IEEE 802.1AB LLDP Organization specific TLV */
struct i40e_lldp_org_tlv {
	__be16 typelength;
	__be32 ouisubtype;
	u8 tlvinfo[1];
};

struct i40e_cee_tlv_hdr {
	__be16 typelen;
	u8 operver;
	u8 maxver;
};

struct i40e_cee_ctrl_tlv {
	struct i40e_cee_tlv_hdr hdr;
	__be32 seqno;
	__be32 ackno;
};

struct i40e_cee_feat_tlv {
	struct i40e_cee_tlv_hdr hdr;
	u8 en_will_err; /* Bits: |En|Will|Err|Reserved(5)| */
#define I40E_CEE_FEAT_TLV_ENABLE_MASK	0x80
#define I40E_CEE_FEAT_TLV_WILLING_MASK	0x40
#define I40E_CEE_FEAT_TLV_ERR_MASK	0x20
	u8 subtype;
	u8 tlvinfo[1];
};

struct i40e_cee_app_prio {
	__be16 protocol;
	u8 upper_oui_sel; /* Bits: |Upper OUI(6)|Selector(2)| */
#define I40E_CEE_APP_SELECTOR_MASK	0x03
	__be16 lower_oui;
	u8 prio_map;
};
#pragma pack()

i40e_status i40e_get_dcbx_status(struct i40e_hw *hw,
					   u16 *status);
i40e_status i40e_lldp_to_dcb_config(u8 *lldpmib,
					      struct i40e_dcbx_config *dcbcfg);
i40e_status i40e_aq_get_dcb_config(struct i40e_hw *hw, u8 mib_type,
					     u8 bridgetype,
					     struct i40e_dcbx_config *dcbcfg);
i40e_status i40e_get_dcb_config(struct i40e_hw *hw);
i40e_status i40e_init_dcb(struct i40e_hw *hw);
#endif /* _I40E_DCB_H_ */
