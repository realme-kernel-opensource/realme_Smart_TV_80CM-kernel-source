/*
 *  Dell WMI descriptor driver
 *
 *  Copyright (c) 2017 Dell Inc.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 */

#ifndef _DELL_WMI_DESCRIPTOR_H_
#define _DELL_WMI_DESCRIPTOR_H_

#include <linux/wmi.h>

/* possible return values:
 *  -ENODEV: Descriptor GUID missing from WMI bus
 *  -EPROBE_DEFER: probing for dell-wmi-descriptor not yet run
 *  0: valid descriptor, successfully probed
 *  < 0: invalid descriptor, don't probe dependent devices
 */
int dell_wmi_get_descriptor_valid(void);

bool dell_wmi_get_interface_version(u32 *version);
bool dell_wmi_get_size(u32 *size);
bool dell_wmi_get_hotfix(u32 *hotfix);

#endif
