/*
 * Copyright (c) 2021 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <init.h>
#include <usb/usb_device.h>

#include <logging/log.h>
LOG_MODULE_REGISTER(peripheral_uart_thingy53);

static int usb_cdc_init(const struct device *dev)
{
	int err = usb_enable(NULL);

	if (err) {
		LOG_ERR("Failed to enable USB");
	}

	return err;
}

SYS_INIT(usb_cdc_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);