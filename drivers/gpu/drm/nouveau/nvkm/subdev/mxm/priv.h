/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __NVKM_MXM_PRIV_H__
#define __NVKM_MXM_PRIV_H__
#define nvkm_mxm(p) container_of((p), struct nvkm_mxm, subdev)
#include <subdev/mxm.h>

#define MXM_SANITISE_DCB 0x00000001

struct nvkm_mxm {
	struct nvkm_subdev subdev;
	u32 action;
	u8 *mxms;
};

int nvkm_mxm_new_(struct nvkm_device *, int index, struct nvkm_mxm **);
#endif
