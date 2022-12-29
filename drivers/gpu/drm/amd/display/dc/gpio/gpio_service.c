/*
 * Copyright 2012-15 Advanced Micro Devices, Inc.
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

/*
 * Pre-requisites: headers required by header of this unit
 */

#include "dm_services.h"
#include "include/gpio_interface.h"
#include "include/gpio_service_interface.h"
#include "hw_translate.h"
#include "hw_factory.h"

/*
 * Header of this unit
 */

#include "gpio_service.h"

/*
 * Post-requisites: headers required by this unit
 */

#include "hw_gpio.h"

/*
 * @brief
 * Public API.
 */

struct gpio_service *dal_gpio_service_create(
	enum dce_version dce_version_major,
	enum dce_version dce_version_minor,
	struct dc_context *ctx)
{
	struct gpio_service *service;

	uint32_t index_of_id;

	service = kzalloc(sizeof(struct gpio_service), GFP_KERNEL);

	if (!service) {
		BREAK_TO_DEBUGGER();
		return NULL;
	}

	if (!dal_hw_translate_init(&service->translate, dce_version_major,
			dce_version_minor)) {
		BREAK_TO_DEBUGGER();
		goto failure_1;
	}

	if (!dal_hw_factory_init(&service->factory, dce_version_major,
			dce_version_minor)) {
		BREAK_TO_DEBUGGER();
		goto failure_1;
	}

	/* allocate and initialize business storage */
	{
		const uint32_t bits_per_uint = sizeof(uint32_t) << 3;

		index_of_id = 0;
		service->ctx = ctx;

		do {
			uint32_t number_of_bits =
				service->factory.number_of_pins[index_of_id];

			uint32_t number_of_uints =
				(number_of_bits + bits_per_uint - 1) /
				bits_per_uint;

			uint32_t *slot;

			if (number_of_bits) {
				uint32_t index_of_uint = 0;

				slot = kcalloc(number_of_uints,
					       sizeof(uint32_t),
					       GFP_KERNEL);

				if (!slot) {
					BREAK_TO_DEBUGGER();
					goto failure_2;
				}

				do {
					slot[index_of_uint] = 0;

					++index_of_uint;
				} while (index_of_uint < number_of_uints);
			} else
				slot = NULL;

			service->busyness[index_of_id] = slot;

			++index_of_id;
		} while (index_of_id < GPIO_ID_COUNT);
	}

	return service;

failure_2:
	while (index_of_id) {
		uint32_t *slot;

		--index_of_id;

		slot = service->busyness[index_of_id];

		kfree(slot);
	}

failure_1:
	kfree(service);

	return NULL;
}

struct gpio *dal_gpio_service_create_irq(
	struct gpio_service *service,
	uint32_t offset,
	uint32_t mask)
{
	enum gpio_id id;
	uint32_t en;

	if (!service->translate.funcs->offset_to_id(offset, mask, &id, &en)) {
		ASSERT_CRITICAL(false);
		return NULL;
	}

	return dal_gpio_create_irq(service, id, en);
}

void dal_gpio_service_destroy(
	struct gpio_service **ptr)
{
	if (!ptr || !*ptr) {
		BREAK_TO_DEBUGGER();
		return;
	}

	/* free business storage */
	{
		uint32_t index_of_id = 0;

		do {
			uint32_t *slot = (*ptr)->busyness[index_of_id];

			kfree(slot);

			++index_of_id;
		} while (index_of_id < GPIO_ID_COUNT);
	}

	kfree(*ptr);

	*ptr = NULL;
}

/*
 * @brief
 * Private API.
 */

static bool is_pin_busy(
	const struct gpio_service *service,
	enum gpio_id id,
	uint32_t en)
{
	const uint32_t bits_per_uint = sizeof(uint32_t) << 3;

	const uint32_t *slot = service->busyness[id] + (en / bits_per_uint);

	return 0 != (*slot & (1 << (en % bits_per_uint)));
}

static void set_pin_busy(
	struct gpio_service *service,
	enum gpio_id id,
	uint32_t en)
{
	const uint32_t bits_per_uint = sizeof(uint32_t) << 3;

	service->busyness[id][en / bits_per_uint] |=
		(1 << (en % bits_per_uint));
}

static void set_pin_free(
	struct gpio_service *service,
	enum gpio_id id,
	uint32_t en)
{
	const uint32_t bits_per_uint = sizeof(uint32_t) << 3;

	service->busyness[id][en / bits_per_uint] &=
		~(1 << (en % bits_per_uint));
}

enum gpio_result dal_gpio_service_open(
	struct gpio_service *service,
	enum gpio_id id,
	uint32_t en,
	enum gpio_mode mode,
	struct hw_gpio_pin **ptr)
{
	struct hw_gpio_pin *pin;

	if (!service->busyness[id]) {
		ASSERT_CRITICAL(false);
		return GPIO_RESULT_OPEN_FAILED;
	}

	if (is_pin_busy(service, id, en)) {
		ASSERT_CRITICAL(false);
		return GPIO_RESULT_DEVICE_BUSY;
	}

	switch (id) {
	case GPIO_ID_DDC_DATA:
		pin = service->factory.funcs->create_ddc_data(
			service->ctx, id, en);
		service->factory.funcs->define_ddc_registers(pin, en);
	break;
	case GPIO_ID_DDC_CLOCK:
		pin = service->factory.funcs->create_ddc_clock(
			service->ctx, id, en);
		service->factory.funcs->define_ddc_registers(pin, en);
	break;
	case GPIO_ID_GENERIC:
		pin = service->factory.funcs->create_generic(
			service->ctx, id, en);
	break;
	case GPIO_ID_HPD:
		pin = service->factory.funcs->create_hpd(
			service->ctx, id, en);
		service->factory.funcs->define_hpd_registers(pin, en);
	break;
	case GPIO_ID_SYNC:
		pin = service->factory.funcs->create_sync(
			service->ctx, id, en);
	break;
	case GPIO_ID_GSL:
		pin = service->factory.funcs->create_gsl(
			service->ctx, id, en);
	break;
	default:
		ASSERT_CRITICAL(false);
		return GPIO_RESULT_NON_SPECIFIC_ERROR;
	}

	if (!pin) {
		ASSERT_CRITICAL(false);
		return GPIO_RESULT_NON_SPECIFIC_ERROR;
	}

	if (!pin->funcs->open(pin, mode)) {
		ASSERT_CRITICAL(false);
		dal_gpio_service_close(service, &pin);
		return GPIO_RESULT_OPEN_FAILED;
	}

	set_pin_busy(service, id, en);
	*ptr = pin;
	return GPIO_RESULT_OK;
}

void dal_gpio_service_close(
	struct gpio_service *service,
	struct hw_gpio_pin **ptr)
{
	struct hw_gpio_pin *pin;

	if (!ptr) {
		ASSERT_CRITICAL(false);
		return;
	}

	pin = *ptr;

	if (pin) {
		set_pin_free(service, pin->id, pin->en);

		pin->funcs->close(pin);

		pin->funcs->destroy(ptr);
	}
}


enum dc_irq_source dal_irq_get_source(
	const struct gpio *irq)
{
	enum gpio_id id = dal_gpio_get_id(irq);

	switch (id) {
	case GPIO_ID_HPD:
		return (enum dc_irq_source)(DC_IRQ_SOURCE_HPD1 +
			dal_gpio_get_enum(irq));
	case GPIO_ID_GPIO_PAD:
		return (enum dc_irq_source)(DC_IRQ_SOURCE_GPIOPAD0 +
			dal_gpio_get_enum(irq));
	default:
		return DC_IRQ_SOURCE_INVALID;
	}
}

enum dc_irq_source dal_irq_get_rx_source(
	const struct gpio *irq)
{
	enum gpio_id id = dal_gpio_get_id(irq);

	switch (id) {
	case GPIO_ID_HPD:
		return (enum dc_irq_source)(DC_IRQ_SOURCE_HPD1RX +
			dal_gpio_get_enum(irq));
	default:
		return DC_IRQ_SOURCE_INVALID;
	}
}

enum gpio_result dal_irq_setup_hpd_filter(
	struct gpio *irq,
	struct gpio_hpd_config *config)
{
	struct gpio_config_data config_data;

	if (!config)
		return GPIO_RESULT_INVALID_DATA;

	config_data.type = GPIO_CONFIG_TYPE_HPD;
	config_data.config.hpd = *config;

	return dal_gpio_set_config(irq, &config_data);
}

/*
 * @brief
 * Creation and destruction
 */

struct gpio *dal_gpio_create_irq(
	struct gpio_service *service,
	enum gpio_id id,
	uint32_t en)
{
	struct gpio *irq;

	switch (id) {
	case GPIO_ID_HPD:
	case GPIO_ID_GPIO_PAD:
	break;
	default:
		id = GPIO_ID_HPD;
		ASSERT_CRITICAL(false);
		return NULL;
	}

	irq = dal_gpio_create(
		service, id, en, GPIO_PIN_OUTPUT_STATE_DEFAULT);

	if (irq)
		return irq;

	ASSERT_CRITICAL(false);
	return NULL;
}

void dal_gpio_destroy_irq(
	struct gpio **irq)
{
	if (!irq || !*irq) {
		ASSERT_CRITICAL(false);
		return;
	}

	dal_gpio_close(*irq);
	dal_gpio_destroy(irq);
	kfree(*irq);

	*irq = NULL;
}

struct ddc *dal_gpio_create_ddc(
	struct gpio_service *service,
	uint32_t offset,
	uint32_t mask,
	struct gpio_ddc_hw_info *info)
{
	enum gpio_id id;
	uint32_t en;
	struct ddc *ddc;

	if (!service->translate.funcs->offset_to_id(offset, mask, &id, &en))
		return NULL;

	ddc = kzalloc(sizeof(struct ddc), GFP_KERNEL);

	if (!ddc) {
		BREAK_TO_DEBUGGER();
		return NULL;
	}

	ddc->pin_data = dal_gpio_create(
		service, GPIO_ID_DDC_DATA, en, GPIO_PIN_OUTPUT_STATE_DEFAULT);

	if (!ddc->pin_data) {
		BREAK_TO_DEBUGGER();
		goto failure_1;
	}

	ddc->pin_clock = dal_gpio_create(
		service, GPIO_ID_DDC_CLOCK, en, GPIO_PIN_OUTPUT_STATE_DEFAULT);

	if (!ddc->pin_clock) {
		BREAK_TO_DEBUGGER();
		goto failure_2;
	}

	ddc->hw_info = *info;

	ddc->ctx = service->ctx;

	return ddc;

failure_2:
	dal_gpio_destroy(&ddc->pin_data);

failure_1:
	kfree(ddc);

	return NULL;
}

void dal_gpio_destroy_ddc(
	struct ddc **ddc)
{
	if (!ddc || !*ddc) {
		BREAK_TO_DEBUGGER();
		return;
	}

	dal_ddc_close(*ddc);
	dal_gpio_destroy(&(*ddc)->pin_data);
	dal_gpio_destroy(&(*ddc)->pin_clock);
	kfree(*ddc);

	*ddc = NULL;
}

enum gpio_result dal_ddc_open(
	struct ddc *ddc,
	enum gpio_mode mode,
	enum gpio_ddc_config_type config_type)
{
	enum gpio_result result;

	struct gpio_config_data config_data;
	struct hw_gpio *hw_data;
	struct hw_gpio *hw_clock;

	result = dal_gpio_open_ex(ddc->pin_data, mode);

	if (result != GPIO_RESULT_OK) {
		BREAK_TO_DEBUGGER();
		return result;
	}

	result = dal_gpio_open_ex(ddc->pin_clock, mode);

	if (result != GPIO_RESULT_OK) {
		BREAK_TO_DEBUGGER();
		goto failure;
	}

	/* DDC clock and data pins should belong
	 * to the same DDC block id,
	 * we use the data pin to set the pad mode. */

	if (mode == GPIO_MODE_INPUT)
		/* this is from detect_sink_type,
		 * we need extra delay there */
		config_data.type = GPIO_CONFIG_TYPE_I2C_AUX_DUAL_MODE;
	else
		config_data.type = GPIO_CONFIG_TYPE_DDC;

	config_data.config.ddc.type = config_type;

	hw_data = FROM_HW_GPIO_PIN(ddc->pin_data->pin);
	hw_clock = FROM_HW_GPIO_PIN(ddc->pin_clock->pin);

	config_data.config.ddc.data_en_bit_present = hw_data->store.en != 0;
	config_data.config.ddc.clock_en_bit_present = hw_clock->store.en != 0;

	result = dal_gpio_set_config(ddc->pin_data, &config_data);

	if (result == GPIO_RESULT_OK)
		return result;

	BREAK_TO_DEBUGGER();

	dal_gpio_close(ddc->pin_clock);

failure:
	dal_gpio_close(ddc->pin_data);

	return result;
}

enum gpio_result dal_ddc_change_mode(
	struct ddc *ddc,
	enum gpio_mode mode)
{
	enum gpio_result result;

	enum gpio_mode original_mode =
		dal_gpio_get_mode(ddc->pin_data);

	result = dal_gpio_change_mode(ddc->pin_data, mode);

	/* [anaumov] DAL2 code returns GPIO_RESULT_NON_SPECIFIC_ERROR
	 * in case of failures;
	 * set_mode() is so that, in case of failure,
	 * we must explicitly set original mode */

	if (result != GPIO_RESULT_OK)
		goto failure;

	result = dal_gpio_change_mode(ddc->pin_clock, mode);

	if (result == GPIO_RESULT_OK)
		return result;

	dal_gpio_change_mode(ddc->pin_clock, original_mode);

failure:
	dal_gpio_change_mode(ddc->pin_data, original_mode);

	return result;
}

enum gpio_ddc_line dal_ddc_get_line(
	const struct ddc *ddc)
{
	return (enum gpio_ddc_line)dal_gpio_get_enum(ddc->pin_data);
}

enum gpio_result dal_ddc_set_config(
	struct ddc *ddc,
	enum gpio_ddc_config_type config_type)
{
	struct gpio_config_data config_data;

	config_data.type = GPIO_CONFIG_TYPE_DDC;

	config_data.config.ddc.type = config_type;
	config_data.config.ddc.data_en_bit_present = false;
	config_data.config.ddc.clock_en_bit_present = false;

	return dal_gpio_set_config(ddc->pin_data, &config_data);
}

void dal_ddc_close(
	struct ddc *ddc)
{
	dal_gpio_close(ddc->pin_clock);
	dal_gpio_close(ddc->pin_data);
}

