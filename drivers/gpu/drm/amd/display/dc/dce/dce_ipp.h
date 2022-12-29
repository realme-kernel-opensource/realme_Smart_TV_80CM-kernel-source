/*
 * Copyright 2017 Advanced Micro Devices, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: AMD
 *
 */

#ifndef _DCE_IPP_H_
#define _DCE_IPP_H_

#include "ipp.h"

#define TO_DCE_IPP(ipp)\
	container_of(ipp, struct dce_ipp, base)

#define IPP_COMMON_REG_LIST_DCE_BASE(id) \
	SRI(CUR_UPDATE, DCP, id), \
	SRI(CUR_CONTROL, DCP, id), \
	SRI(CUR_POSITION, DCP, id), \
	SRI(CUR_HOT_SPOT, DCP, id), \
	SRI(CUR_COLOR1, DCP, id), \
	SRI(CUR_COLOR2, DCP, id), \
	SRI(CUR_SIZE, DCP, id), \
	SRI(CUR_SURFACE_ADDRESS_HIGH, DCP, id), \
	SRI(CUR_SURFACE_ADDRESS, DCP, id), \
	SRI(PRESCALE_GRPH_CONTROL, DCP, id), \
	SRI(PRESCALE_VALUES_GRPH_R, DCP, id), \
	SRI(PRESCALE_VALUES_GRPH_G, DCP, id), \
	SRI(PRESCALE_VALUES_GRPH_B, DCP, id), \
	SRI(INPUT_GAMMA_CONTROL, DCP, id), \
	SRI(DC_LUT_WRITE_EN_MASK, DCP, id), \
	SRI(DC_LUT_RW_MODE, DCP, id), \
	SRI(DC_LUT_CONTROL, DCP, id), \
	SRI(DC_LUT_RW_INDEX, DCP, id), \
	SRI(DC_LUT_SEQ_COLOR, DCP, id), \
	SRI(DEGAMMA_CONTROL, DCP, id)

#define IPP_DCE100_REG_LIST_DCE_BASE(id) \
	IPP_COMMON_REG_LIST_DCE_BASE(id), \
	SRI(DCFE_MEM_PWR_CTRL, CRTC, id)

#define IPP_DCE110_REG_LIST_DCE_BASE(id) \
	IPP_COMMON_REG_LIST_DCE_BASE(id), \
	SRI(DCFE_MEM_PWR_CTRL, DCFE, id)

#define IPP_SF(reg_name, field_name, post_fix)\
	.field_name = reg_name ## __ ## field_name ## post_fix

#define IPP_COMMON_MASK_SH_LIST_DCE_COMMON_BASE(mask_sh) \
	IPP_SF(CUR_UPDATE, CURSOR_UPDATE_LOCK, mask_sh), \
	IPP_SF(CUR_CONTROL, CURSOR_EN, mask_sh), \
	IPP_SF(CUR_CONTROL, CURSOR_MODE, mask_sh), \
	IPP_SF(CUR_CONTROL, CURSOR_2X_MAGNIFY, mask_sh), \
	IPP_SF(CUR_CONTROL, CUR_INV_TRANS_CLAMP, mask_sh), \
	IPP_SF(CUR_POSITION, CURSOR_X_POSITION, mask_sh), \
	IPP_SF(CUR_POSITION, CURSOR_Y_POSITION, mask_sh), \
	IPP_SF(CUR_HOT_SPOT, CURSOR_HOT_SPOT_X, mask_sh), \
	IPP_SF(CUR_HOT_SPOT, CURSOR_HOT_SPOT_Y, mask_sh), \
	IPP_SF(CUR_COLOR1, CUR_COLOR1_BLUE, mask_sh), \
	IPP_SF(CUR_COLOR1, CUR_COLOR1_GREEN, mask_sh), \
	IPP_SF(CUR_COLOR1, CUR_COLOR1_RED, mask_sh), \
	IPP_SF(CUR_COLOR2, CUR_COLOR2_BLUE, mask_sh), \
	IPP_SF(CUR_COLOR2, CUR_COLOR2_GREEN, mask_sh), \
	IPP_SF(CUR_COLOR2, CUR_COLOR2_RED, mask_sh), \
	IPP_SF(CUR_SIZE, CURSOR_WIDTH, mask_sh), \
	IPP_SF(CUR_SIZE, CURSOR_HEIGHT, mask_sh), \
	IPP_SF(CUR_SURFACE_ADDRESS_HIGH, CURSOR_SURFACE_ADDRESS_HIGH, mask_sh), \
	IPP_SF(CUR_SURFACE_ADDRESS, CURSOR_SURFACE_ADDRESS, mask_sh), \
	IPP_SF(PRESCALE_GRPH_CONTROL, GRPH_PRESCALE_BYPASS, mask_sh), \
	IPP_SF(PRESCALE_VALUES_GRPH_R, GRPH_PRESCALE_SCALE_R, mask_sh), \
	IPP_SF(PRESCALE_VALUES_GRPH_R, GRPH_PRESCALE_BIAS_R, mask_sh), \
	IPP_SF(PRESCALE_VALUES_GRPH_G, GRPH_PRESCALE_SCALE_G, mask_sh), \
	IPP_SF(PRESCALE_VALUES_GRPH_G, GRPH_PRESCALE_BIAS_G, mask_sh), \
	IPP_SF(PRESCALE_VALUES_GRPH_B, GRPH_PRESCALE_SCALE_B, mask_sh), \
	IPP_SF(PRESCALE_VALUES_GRPH_B, GRPH_PRESCALE_BIAS_B, mask_sh), \
	IPP_SF(INPUT_GAMMA_CONTROL, GRPH_INPUT_GAMMA_MODE, mask_sh), \
	IPP_SF(DC_LUT_WRITE_EN_MASK, DC_LUT_WRITE_EN_MASK, mask_sh), \
	IPP_SF(DC_LUT_RW_MODE, DC_LUT_RW_MODE, mask_sh), \
	IPP_SF(DC_LUT_CONTROL, DC_LUT_DATA_R_FORMAT, mask_sh), \
	IPP_SF(DC_LUT_CONTROL, DC_LUT_DATA_G_FORMAT, mask_sh), \
	IPP_SF(DC_LUT_CONTROL, DC_LUT_DATA_B_FORMAT, mask_sh), \
	IPP_SF(DC_LUT_RW_INDEX, DC_LUT_RW_INDEX, mask_sh), \
	IPP_SF(DC_LUT_SEQ_COLOR, DC_LUT_SEQ_COLOR, mask_sh), \
	IPP_SF(DEGAMMA_CONTROL, GRPH_DEGAMMA_MODE, mask_sh), \
	IPP_SF(DEGAMMA_CONTROL, CURSOR_DEGAMMA_MODE, mask_sh), \
	IPP_SF(DEGAMMA_CONTROL, CURSOR2_DEGAMMA_MODE, mask_sh)

#define IPP_DCE100_MASK_SH_LIST_DCE_COMMON_BASE(mask_sh) \
	IPP_COMMON_MASK_SH_LIST_DCE_COMMON_BASE(mask_sh), \
	IPP_SF(DCFE_MEM_PWR_CTRL, DCP_LUT_MEM_PWR_DIS, mask_sh)

#define IPP_DCE120_MASK_SH_LIST_SOC_BASE(mask_sh) \
	IPP_SF(DCP0_CUR_UPDATE, CURSOR_UPDATE_LOCK, mask_sh), \
	IPP_SF(DCP0_CUR_CONTROL, CURSOR_EN, mask_sh), \
	IPP_SF(DCP0_CUR_CONTROL, CURSOR_MODE, mask_sh), \
	IPP_SF(DCP0_CUR_CONTROL, CURSOR_2X_MAGNIFY, mask_sh), \
	IPP_SF(DCP0_CUR_CONTROL, CUR_INV_TRANS_CLAMP, mask_sh), \
	IPP_SF(DCP0_CUR_POSITION, CURSOR_X_POSITION, mask_sh), \
	IPP_SF(DCP0_CUR_POSITION, CURSOR_Y_POSITION, mask_sh), \
	IPP_SF(DCP0_CUR_HOT_SPOT, CURSOR_HOT_SPOT_X, mask_sh), \
	IPP_SF(DCP0_CUR_HOT_SPOT, CURSOR_HOT_SPOT_Y, mask_sh), \
	IPP_SF(DCP0_CUR_COLOR1, CUR_COLOR1_BLUE, mask_sh), \
	IPP_SF(DCP0_CUR_COLOR1, CUR_COLOR1_GREEN, mask_sh), \
	IPP_SF(DCP0_CUR_COLOR1, CUR_COLOR1_RED, mask_sh), \
	IPP_SF(DCP0_CUR_COLOR2, CUR_COLOR2_BLUE, mask_sh), \
	IPP_SF(DCP0_CUR_COLOR2, CUR_COLOR2_GREEN, mask_sh), \
	IPP_SF(DCP0_CUR_COLOR2, CUR_COLOR2_RED, mask_sh), \
	IPP_SF(DCP0_CUR_SIZE, CURSOR_WIDTH, mask_sh), \
	IPP_SF(DCP0_CUR_SIZE, CURSOR_HEIGHT, mask_sh), \
	IPP_SF(DCP0_CUR_SURFACE_ADDRESS_HIGH, CURSOR_SURFACE_ADDRESS_HIGH, mask_sh), \
	IPP_SF(DCP0_CUR_SURFACE_ADDRESS, CURSOR_SURFACE_ADDRESS, mask_sh), \
	IPP_SF(DCP0_PRESCALE_GRPH_CONTROL, GRPH_PRESCALE_BYPASS, mask_sh), \
	IPP_SF(DCP0_PRESCALE_VALUES_GRPH_R, GRPH_PRESCALE_SCALE_R, mask_sh), \
	IPP_SF(DCP0_PRESCALE_VALUES_GRPH_R, GRPH_PRESCALE_BIAS_R, mask_sh), \
	IPP_SF(DCP0_PRESCALE_VALUES_GRPH_G, GRPH_PRESCALE_SCALE_G, mask_sh), \
	IPP_SF(DCP0_PRESCALE_VALUES_GRPH_G, GRPH_PRESCALE_BIAS_G, mask_sh), \
	IPP_SF(DCP0_PRESCALE_VALUES_GRPH_B, GRPH_PRESCALE_SCALE_B, mask_sh), \
	IPP_SF(DCP0_PRESCALE_VALUES_GRPH_B, GRPH_PRESCALE_BIAS_B, mask_sh), \
	IPP_SF(DCP0_INPUT_GAMMA_CONTROL, GRPH_INPUT_GAMMA_MODE, mask_sh), \
	IPP_SF(DCFE0_DCFE_MEM_PWR_CTRL, DCP_LUT_MEM_PWR_DIS, mask_sh), \
	IPP_SF(DCP0_DC_LUT_WRITE_EN_MASK, DC_LUT_WRITE_EN_MASK, mask_sh), \
	IPP_SF(DCP0_DC_LUT_RW_MODE, DC_LUT_RW_MODE, mask_sh), \
	IPP_SF(DCP0_DC_LUT_CONTROL, DC_LUT_DATA_R_FORMAT, mask_sh), \
	IPP_SF(DCP0_DC_LUT_CONTROL, DC_LUT_DATA_G_FORMAT, mask_sh), \
	IPP_SF(DCP0_DC_LUT_CONTROL, DC_LUT_DATA_B_FORMAT, mask_sh), \
	IPP_SF(DCP0_DC_LUT_RW_INDEX, DC_LUT_RW_INDEX, mask_sh), \
	IPP_SF(DCP0_DC_LUT_SEQ_COLOR, DC_LUT_SEQ_COLOR, mask_sh), \
	IPP_SF(DCP0_DEGAMMA_CONTROL, GRPH_DEGAMMA_MODE, mask_sh), \
	IPP_SF(DCP0_DEGAMMA_CONTROL, CURSOR_DEGAMMA_MODE, mask_sh), \
	IPP_SF(DCP0_DEGAMMA_CONTROL, CURSOR2_DEGAMMA_MODE, mask_sh)

#define IPP_REG_FIELD_LIST(type) \
	type CURSOR_UPDATE_LOCK; \
	type CURSOR_EN; \
	type CURSOR_X_POSITION; \
	type CURSOR_Y_POSITION; \
	type CURSOR_HOT_SPOT_X; \
	type CURSOR_HOT_SPOT_Y; \
	type CURSOR_MODE; \
	type CURSOR_2X_MAGNIFY; \
	type CUR_INV_TRANS_CLAMP; \
	type CUR_COLOR1_BLUE; \
	type CUR_COLOR1_GREEN; \
	type CUR_COLOR1_RED; \
	type CUR_COLOR2_BLUE; \
	type CUR_COLOR2_GREEN; \
	type CUR_COLOR2_RED; \
	type CURSOR_WIDTH; \
	type CURSOR_HEIGHT; \
	type CURSOR_SURFACE_ADDRESS_HIGH; \
	type CURSOR_SURFACE_ADDRESS; \
	type GRPH_PRESCALE_BYPASS; \
	type GRPH_PRESCALE_SCALE_R; \
	type GRPH_PRESCALE_BIAS_R; \
	type GRPH_PRESCALE_SCALE_G; \
	type GRPH_PRESCALE_BIAS_G; \
	type GRPH_PRESCALE_SCALE_B; \
	type GRPH_PRESCALE_BIAS_B; \
	type GRPH_INPUT_GAMMA_MODE; \
	type DCP_LUT_MEM_PWR_DIS; \
	type DC_LUT_WRITE_EN_MASK; \
	type DC_LUT_RW_MODE; \
	type DC_LUT_DATA_R_FORMAT; \
	type DC_LUT_DATA_G_FORMAT; \
	type DC_LUT_DATA_B_FORMAT; \
	type DC_LUT_RW_INDEX; \
	type DC_LUT_SEQ_COLOR; \
	type GRPH_DEGAMMA_MODE; \
	type CURSOR_DEGAMMA_MODE; \
	type CURSOR2_DEGAMMA_MODE

struct dce_ipp_shift {
	IPP_REG_FIELD_LIST(uint8_t);
};

struct dce_ipp_mask {
	IPP_REG_FIELD_LIST(uint32_t);
};

struct dce_ipp_registers {
	uint32_t CUR_UPDATE;
	uint32_t CUR_CONTROL;
	uint32_t CUR_POSITION;
	uint32_t CUR_HOT_SPOT;
	uint32_t CUR_COLOR1;
	uint32_t CUR_COLOR2;
	uint32_t CUR_SIZE;
	uint32_t CUR_SURFACE_ADDRESS_HIGH;
	uint32_t CUR_SURFACE_ADDRESS;
	uint32_t PRESCALE_GRPH_CONTROL;
	uint32_t PRESCALE_VALUES_GRPH_R;
	uint32_t PRESCALE_VALUES_GRPH_G;
	uint32_t PRESCALE_VALUES_GRPH_B;
	uint32_t INPUT_GAMMA_CONTROL;
	uint32_t DCFE_MEM_PWR_CTRL;
	uint32_t DC_LUT_WRITE_EN_MASK;
	uint32_t DC_LUT_RW_MODE;
	uint32_t DC_LUT_CONTROL;
	uint32_t DC_LUT_RW_INDEX;
	uint32_t DC_LUT_SEQ_COLOR;
	uint32_t DEGAMMA_CONTROL;
};

struct dce_ipp {
	struct input_pixel_processor base;
	const struct dce_ipp_registers *regs;
	const struct dce_ipp_shift *ipp_shift;
	const struct dce_ipp_mask *ipp_mask;
};

void dce_ipp_construct(struct dce_ipp *ipp_dce,
	struct dc_context *ctx,
	int inst,
	const struct dce_ipp_registers *regs,
	const struct dce_ipp_shift *ipp_shift,
	const struct dce_ipp_mask *ipp_mask);

void dce_ipp_destroy(struct input_pixel_processor **ipp);

#endif /* _DCE_IPP_H_ */
