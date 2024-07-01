/* warp-energy-manager-v2-bricklet
 * Copyright (C) 2024 Olaf Lüke <olaf@tinkerforge.com>
 *
 * config_io.h: Config for inputs, relays and sg ready
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

#ifndef CONFIG_RELAY_H
#define CONFIG_RELAY_H

#include "xmc_gpio.h"

#define IO_IN0_PIN     P2_4
#define IO_IN1_PIN     P2_5
#define IO_IN2_PIN     P2_6
#define IO_IN3_PIN     P2_7

#define IO_RELAY0_PIN  P1_2
#define IO_RELAY1_PIN  P1_3
#define IO_SG_OUT0_PIN P1_4
#define IO_SG_OUT1_PIN P1_5

#endif