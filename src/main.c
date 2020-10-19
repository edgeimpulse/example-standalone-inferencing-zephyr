/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <sys/printk.h>

//#include "ei_run_classifier.h"
#include "../source/porting/ei_classifier_porting.h"
#include "numpy.hpp"

void main(void)
{
	printk("Hello World! %s\n", CONFIG_BOARD);
}
