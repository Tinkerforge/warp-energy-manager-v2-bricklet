/* hat-warp-energy-manager-v2-brick
 * Copyright (C) 2024 Olaf Lüke <olaf@tinkerforge.com>
 *
 * io.c: Driver for inputs, relays and sg ready
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "io.h"

#include "configs/config_io.h"

#include "xmc_gpio.h"

#include "bricklib2/hal/system_timer/system_timer.h"
#include "bricklib2/logging/logging.h"

IO io;

void io_init(void) {
	memset(&io, 0, sizeof(IO));
	const XMC_GPIO_CONFIG_t io_config_high = {
		.mode             = XMC_GPIO_MODE_OUTPUT_PUSH_PULL,
		.output_level     = XMC_GPIO_OUTPUT_LEVEL_HIGH,
	};

	const XMC_GPIO_CONFIG_t io_config_low = {
		.mode             = XMC_GPIO_MODE_OUTPUT_PUSH_PULL,
		.output_level     = XMC_GPIO_OUTPUT_LEVEL_LOW,
	};

	const XMC_GPIO_CONFIG_t io_config_input = {
		.mode             = XMC_GPIO_MODE_INPUT_TRISTATE,
		.input_hysteresis = XMC_GPIO_INPUT_HYSTERESIS_LARGE,
	};
	XMC_GPIO_Init(IO_RELAY0_PIN,  &io_config_high);
	XMC_GPIO_Init(IO_RELAY1_PIN,  &io_config_high);
	XMC_GPIO_Init(IO_SG_OUT0_PIN, &io_config_high);
	XMC_GPIO_Init(IO_SG_OUT1_PIN, &io_config_high);

	XMC_GPIO_Init(IO_IN0_PIN, &io_config_input);
	XMC_GPIO_Init(IO_IN1_PIN, &io_config_input);
	XMC_GPIO_Init(IO_IN2_PIN, &io_config_input);
	XMC_GPIO_Init(IO_IN3_PIN, &io_config_input);
}

void io_tick(void) {
	XMC_GPIO_SetOutputLevel(IO_RELAY0_PIN, io.relay[0] ? XMC_GPIO_OUTPUT_LEVEL_HIGH : XMC_GPIO_OUTPUT_LEVEL_LOW);
	XMC_GPIO_SetOutputLevel(IO_RELAY1_PIN, io.relay[1] ? XMC_GPIO_OUTPUT_LEVEL_HIGH : XMC_GPIO_OUTPUT_LEVEL_LOW);
	XMC_GPIO_SetOutputLevel(IO_SG_OUT0_PIN, io.sg_ready[0] ? XMC_GPIO_OUTPUT_LEVEL_HIGH : XMC_GPIO_OUTPUT_LEVEL_LOW);
	XMC_GPIO_SetOutputLevel(IO_SG_OUT1_PIN, io.sg_ready[1] ? XMC_GPIO_OUTPUT_LEVEL_HIGH : XMC_GPIO_OUTPUT_LEVEL_LOW);

	io.in[0] = XMC_GPIO_GetInput(IO_IN0_PIN);
	io.in[1] = XMC_GPIO_GetInput(IO_IN1_PIN);
	io.in[2] = XMC_GPIO_GetInput(IO_IN2_PIN);
	io.in[3] = XMC_GPIO_GetInput(IO_IN3_PIN);
}
