/*
 * Copyright (c) 2012 Broadcom Corporation
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */


#ifndef FWSIGNAL_H_
#define FWSIGNAL_H_

struct brcmf_fws_info *brcmf_fws_attach(struct brcmf_pub *drvr);
void brcmf_fws_detach_pre_delif(struct brcmf_fws_info *fws);
void brcmf_fws_detach_post_delif(struct brcmf_fws_info *fws);
void brcmf_fws_debugfs_create(struct brcmf_pub *drvr);
bool brcmf_fws_queue_skbs(struct brcmf_fws_info *fws);
bool brcmf_fws_fc_active(struct brcmf_fws_info *fws);
void brcmf_fws_hdrpull(struct brcmf_if *ifp, s16 siglen, struct sk_buff *skb);
int brcmf_fws_process_skb(struct brcmf_if *ifp, struct sk_buff *skb);

void brcmf_fws_reset_interface(struct brcmf_if *ifp);
void brcmf_fws_add_interface(struct brcmf_if *ifp);
void brcmf_fws_del_interface(struct brcmf_if *ifp);
void brcmf_fws_bustxfail(struct brcmf_fws_info *fws, struct sk_buff *skb);
void brcmf_fws_bus_blocked(struct brcmf_pub *drvr, bool flow_blocked);
void brcmf_fws_rxreorder(struct brcmf_if *ifp, struct sk_buff *skb);

#endif /* FWSIGNAL_H_ */
