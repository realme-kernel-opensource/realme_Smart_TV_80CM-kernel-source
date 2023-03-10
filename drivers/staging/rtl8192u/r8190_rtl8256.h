/*
 *	 This is part of the rtl8180-sa2400 driver
 *	 released under the GPL (See file COPYING for details).
 *	 Copyright (c) 2005 Andrea Merello <andrea.merello@gmail.com>
 *
 *
 *	 This files contains programming code for the rtl8256
 *	 radio frontend.
 *
 *	 *Many* thanks to Realtek Corp. for their great support!
 */

#ifndef RTL8225H
#define RTL8225H

#define RTL819X_TOTAL_RF_PATH 2 /* for 8192U */
void PHY_SetRF8256Bandwidth(struct net_device *dev, enum ht_channel_width Bandwidth);
void PHY_RF8256_Config(struct net_device *dev);
void phy_RF8256_Config_ParaFile(struct net_device *dev);
void PHY_SetRF8256CCKTxPower(struct net_device *dev, u8	powerlevel);
void PHY_SetRF8256OFDMTxPower(struct net_device *dev, u8 powerlevel);

#endif
