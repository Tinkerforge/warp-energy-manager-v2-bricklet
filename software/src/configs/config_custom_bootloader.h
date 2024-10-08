/* warp-energy-manager-v2-bricklet
 * Copyright (C) 2024 Olaf Lüke <olaf@tinkerforge.com>
 *
 * config_custom_bootloader.h: Bootloader configurations for
 *                             WARP Energy Manager Bricklet 2.0
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

#ifndef CONFIG_CUSTOM_BOOTLOADER_H
#define CONFIG_CUSTOM_BOOTLOADER_H

#include "xmc_gpio.h"

// --- Basic defines ---
#define BOOTLOADER_DEVICE_IDENTIFIER   2178
#define BOOTLOADER_HW_VERSION_MAJOR    1
#define BOOTLOADER_HW_VERSION_MINOR    0
#define BOOTLOADER_HW_VERSION_REVISION 0

#define BOOTLOADER_STATUS_LED_PIN      P1_6
#define BOOTLOADER_BOOT_PAD_PIN        P0_7

#define BOOTLOADER_FLASH_EEPROM_SIZE   (4*256)
#define BOOTLOADER_FLASH_SIZE          (200*1024 - BOOTLOADER_FLASH_EEPROM_SIZE)

#define BOOTLOADER_FIX_POINTER_END

// --- Oscilater defines ---
#define OSCHP_FREQUENCY 16000000
#define DCLK_CLOCK_SRC  1
#define DCO1_CAL_SRC    1
#define RTC_CLOCK_SRC   5 // use external 32.768kHz oscillator

// --- SPITFP ---
#define SPITFP_USIC_CHANNEL         USIC0_CH0
#define SPITFP_USIC                 XMC_SPI0_CH0

#define SPITFP_SCLK_PIN             P0_14
#define SPITFP_SCLK_INPUT           XMC_USIC_CH_INPUT_DX1
#define SPITFP_SCLK_SOURCE          0b000 // DX1A

#define SPITFP_SELECT_PIN           P0_13
#define SPITFP_SELECT_INPUT         XMC_USIC_CH_INPUT_DX2
#define SPITFP_SELECT_SOURCE        0b101 // DX2F

#define SPITFP_MOSI_PIN             P0_15
#define SPITFP_MOSI_INPUT           XMC_USIC_CH_INPUT_DX0
#define SPITFP_MOSI_SOURCE          0b001 // DX0B

#define SPITFP_MISO_PIN             P2_0
#define SPITFP_MISO_PIN_AF          (XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT6 | P2_0_AF_U0C0_DOUT0)

#define SPITFP_RECEIVE_BUFFER_SIZE  1024
#define SPITFP_RECEIVE_BUFFER_MASK  (SPITFP_RECEIVE_BUFFER_SIZE-1) // If size is power of 2

#define SPITFP_SERVICE_REQUEST_RX   2
#define SPITFP_SERVICE_REQUEST_TX   3

#define SPITFP_IRQ_NON_STANDARD
#define SPITFP_IRQ_RX               17
#define SPITFP_IRQ_RX_PRIORITY      2
#define SPITFP_IRQ_RX_SCU_CTRL      XMC_SCU_IRQCTRL_USIC0_SR2_IRQ17
#define SPITFP_IRQ_RX_HANDLER       IRQ_Hdlr_17
#define SPITFP_IRQ_TX               18
#define SPITFP_IRQ_TX_PRIORITY      3
#define SPITFP_IRQ_TX_SCU_CTRL      XMC_SCU_IRQCTRL_USIC0_SR3_IRQ18
#define SPITFP_IRQ_TX_HANDLER       IRQ_Hdlr_18

#define SPITFP_TX_DATA_POINTER      48
#define SPITFP_TX_SIZE              XMC_USIC_CH_FIFO_SIZE_16WORDS
#define SPITFP_TX_LIMIT             8

#define SPITFP_RX_DATA_POINTER      32
#define SPITFP_RX_SIZE              XMC_USIC_CH_FIFO_SIZE_16WORDS
#define SPITFP_RX_LIMIT             0

// --- BOOTLOADER FUNCTIONS ---

// define bootloader functions to put them into the BootloaderFunctions struct
// These functions are in the bootloader code and can be used from the firmware

#define BOOTLOADER_FUNCTION_SPITFP_TICK
#define BOOTLOADER_FUNCTION_SEND_ACK_AND_MESSAGE
#define BOOTLOADER_FUNCTION_SPITFP_IS_SEND_POSSIBLE
#define BOOTLOADER_FUNCTION_AEABI_IDIV
#define BOOTLOADER_FUNCTION_AEABI_UIDIV
#define BOOTLOADER_FUNCTION_AEABI_IDIVMOD
#define BOOTLOADER_FUNCTION_AEABI_UIDIVMOD
#define BOOTLOADER_FUNCTION_GET_UID
#define BOOTLOADER_FUNCTION_READ_EEPROM_PAGE
#define BOOTLOADER_FUNCTION_WRITE_EEPROM_PAGE

#endif
