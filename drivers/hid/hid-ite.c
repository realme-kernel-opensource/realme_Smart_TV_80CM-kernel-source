/*
 * HID driver for some ITE "special" devices
 * Copyright (c) 2017 Hans de Goede <hdegoede@redhat.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/device.h>
#include <linux/input.h>
#include <linux/hid.h>
#include <linux/module.h>

#include "hid-ids.h"

static int ite_event(struct hid_device *hdev, struct hid_field *field,
		     struct hid_usage *usage, __s32 value)
{
	struct input_dev *input;

	if (!(hdev->claimed & HID_CLAIMED_INPUT) || !field->hidinput)
		return 0;

	input = field->hidinput->input;

	/*
	 * The ITE8595 always reports 0 as value for the rfkill button. Luckily
	 * it is the only button in its report, and it sends a report on
	 * release only, so receiving a report means the button was pressed.
	 */
	if (usage->hid == HID_GD_RFKILL_BTN) {
		input_event(input, EV_KEY, KEY_RFKILL, 1);
		input_sync(input);
		input_event(input, EV_KEY, KEY_RFKILL, 0);
		input_sync(input);
		return 1;
	}

	return 0;
}

static const struct hid_device_id ite_devices[] = {
	{ HID_USB_DEVICE(USB_VENDOR_ID_ITE, USB_DEVICE_ID_ITE8595) },
	{ HID_USB_DEVICE(USB_VENDOR_ID_258A, USB_DEVICE_ID_258A_6A88) },
	{ }
};
MODULE_DEVICE_TABLE(hid, ite_devices);

static struct hid_driver ite_driver = {
	.name = "itetech",
	.id_table = ite_devices,
	.event = ite_event,
};
module_hid_driver(ite_driver);

MODULE_LICENSE("GPL");
