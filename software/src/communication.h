/* warp-energy-manager-v2-bricklet
 * Copyright (C) 2024 Olaf Lüke <olaf@tinkerforge.com>
 *
 * communication.h: TFP protocol message handling
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

#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <stdint.h>
#include <stdbool.h>

#include "bricklib2/protocols/tfp/tfp.h"
#include "bricklib2/bootloader/bootloader.h"

// Default functions
BootloaderHandleMessageResponse handle_message(const void *data, void *response);
void communication_tick(void);
void communication_init(void);

// Constants

#define WARP_ENERGY_MANAGER_V2_ENERGY_METER_TYPE_NOT_AVAILABLE 0
#define WARP_ENERGY_MANAGER_V2_ENERGY_METER_TYPE_SDM72 1
#define WARP_ENERGY_MANAGER_V2_ENERGY_METER_TYPE_SDM630 2
#define WARP_ENERGY_MANAGER_V2_ENERGY_METER_TYPE_SDM72V2 3
#define WARP_ENERGY_MANAGER_V2_ENERGY_METER_TYPE_SDM72CTM 4
#define WARP_ENERGY_MANAGER_V2_ENERGY_METER_TYPE_SDM630MCTV2 5
#define WARP_ENERGY_MANAGER_V2_ENERGY_METER_TYPE_DSZ15DZMOD 6
#define WARP_ENERGY_MANAGER_V2_ENERGY_METER_TYPE_DEM4A 7
#define WARP_ENERGY_MANAGER_V2_ENERGY_METER_TYPE_DMED341MID7ER 8
#define WARP_ENERGY_MANAGER_V2_ENERGY_METER_TYPE_DSZ16DZE 9
#define WARP_ENERGY_MANAGER_V2_ENERGY_METER_TYPE_WM3M4C 10

#define WARP_ENERGY_MANAGER_V2_DATA_STATUS_OK 0
#define WARP_ENERGY_MANAGER_V2_DATA_STATUS_SD_ERROR 1
#define WARP_ENERGY_MANAGER_V2_DATA_STATUS_LFS_ERROR 2
#define WARP_ENERGY_MANAGER_V2_DATA_STATUS_QUEUE_FULL 3
#define WARP_ENERGY_MANAGER_V2_DATA_STATUS_DATE_OUT_OF_RANGE 4

#define WARP_ENERGY_MANAGER_V2_FORMAT_STATUS_OK 0
#define WARP_ENERGY_MANAGER_V2_FORMAT_STATUS_PASSWORD_ERROR 1
#define WARP_ENERGY_MANAGER_V2_FORMAT_STATUS_FORMAT_ERROR 2

#define WARP_ENERGY_MANAGER_V2_LED_PATTERN_OFF 0
#define WARP_ENERGY_MANAGER_V2_LED_PATTERN_ON 1
#define WARP_ENERGY_MANAGER_V2_LED_PATTERN_BLINKING 2
#define WARP_ENERGY_MANAGER_V2_LED_PATTERN_BREATHING 3

#define WARP_ENERGY_MANAGER_V2_DATA_STORAGE_STATUS_OK 0
#define WARP_ENERGY_MANAGER_V2_DATA_STORAGE_STATUS_NOT_FOUND 1
#define WARP_ENERGY_MANAGER_V2_DATA_STORAGE_STATUS_BUSY 2

#define WARP_ENERGY_MANAGER_V2_BOOTLOADER_MODE_BOOTLOADER 0
#define WARP_ENERGY_MANAGER_V2_BOOTLOADER_MODE_FIRMWARE 1
#define WARP_ENERGY_MANAGER_V2_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2
#define WARP_ENERGY_MANAGER_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3
#define WARP_ENERGY_MANAGER_V2_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

#define WARP_ENERGY_MANAGER_V2_BOOTLOADER_STATUS_OK 0
#define WARP_ENERGY_MANAGER_V2_BOOTLOADER_STATUS_INVALID_MODE 1
#define WARP_ENERGY_MANAGER_V2_BOOTLOADER_STATUS_NO_CHANGE 2
#define WARP_ENERGY_MANAGER_V2_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3
#define WARP_ENERGY_MANAGER_V2_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4
#define WARP_ENERGY_MANAGER_V2_BOOTLOADER_STATUS_CRC_MISMATCH 5

#define WARP_ENERGY_MANAGER_V2_STATUS_LED_CONFIG_OFF 0
#define WARP_ENERGY_MANAGER_V2_STATUS_LED_CONFIG_ON 1
#define WARP_ENERGY_MANAGER_V2_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2
#define WARP_ENERGY_MANAGER_V2_STATUS_LED_CONFIG_SHOW_STATUS 3

// Function and callback IDs and structs
#define FID_GET_ENERGY_METER_VALUES 1
#define FID_GET_ENERGY_METER_DETAILED_VALUES_LOW_LEVEL 2
#define FID_GET_ENERGY_METER_STATE 3
#define FID_GET_INPUT 4
#define FID_SET_SG_READY_OUTPUT 5
#define FID_GET_SG_READY_OUTPUT 6
#define FID_SET_RELAY_OUTPUT 7
#define FID_GET_RELAY_OUTPUT 8
#define FID_GET_INPUT_VOLTAGE 9
#define FID_GET_UPTIME 10
#define FID_GET_ALL_DATA_1 11
#define FID_GET_SD_INFORMATION 12
#define FID_SET_SD_WALLBOX_DATA_POINT 13
#define FID_GET_SD_WALLBOX_DATA_POINTS 14
#define FID_SET_SD_WALLBOX_DAILY_DATA_POINT 15
#define FID_GET_SD_WALLBOX_DAILY_DATA_POINTS 16
#define FID_SET_SD_ENERGY_MANAGER_DATA_POINT 17
#define FID_GET_SD_ENERGY_MANAGER_DATA_POINTS 18
#define FID_SET_SD_ENERGY_MANAGER_DAILY_DATA_POINT 19
#define FID_GET_SD_ENERGY_MANAGER_DAILY_DATA_POINTS 20
#define FID_FORMAT_SD 25
#define FID_SET_DATE_TIME 26
#define FID_GET_DATE_TIME 27
#define FID_GET_DATA_STORAGE 28
#define FID_SET_DATA_STORAGE 29
#define FID_RESET_ENERGY_METER_RELATIVE_ENERGY 30

#define FID_CALLBACK_SD_WALLBOX_DATA_POINTS_LOW_LEVEL 21
#define FID_CALLBACK_SD_WALLBOX_DAILY_DATA_POINTS_LOW_LEVEL 22
#define FID_CALLBACK_SD_ENERGY_MANAGER_DATA_POINTS_LOW_LEVEL 23
#define FID_CALLBACK_SD_ENERGY_MANAGER_DAILY_DATA_POINTS_LOW_LEVEL 24

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetEnergyMeterValues;

typedef struct {
	TFPMessageHeader header;
	float power;
	float current[3];
} __attribute__((__packed__)) GetEnergyMeterValues_Response;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetEnergyMeterDetailedValuesLowLevel;

typedef struct {
	TFPMessageHeader header;
	uint16_t values_chunk_offset;
	float values_chunk_data[15];
} __attribute__((__packed__)) GetEnergyMeterDetailedValuesLowLevel_Response;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetEnergyMeterState;

typedef struct {
	TFPMessageHeader header;
	uint8_t energy_meter_type;
	uint32_t error_count[6];
} __attribute__((__packed__)) GetEnergyMeterState_Response;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetInput;

typedef struct {
	TFPMessageHeader header;
	uint8_t input[1];
} __attribute__((__packed__)) GetInput_Response;

typedef struct {
	TFPMessageHeader header;
	uint8_t index;
	bool output;
} __attribute__((__packed__)) SetSGReadyOutput;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetSGReadyOutput;

typedef struct {
	TFPMessageHeader header;
	uint8_t output[1];
} __attribute__((__packed__)) GetSGReadyOutput_Response;

typedef struct {
	TFPMessageHeader header;
	uint8_t index;
	bool output;
} __attribute__((__packed__)) SetRelayOutput;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetRelayOutput;

typedef struct {
	TFPMessageHeader header;
	uint8_t output[1];
} __attribute__((__packed__)) GetRelayOutput_Response;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetInputVoltage;

typedef struct {
	TFPMessageHeader header;
	uint16_t voltage;
} __attribute__((__packed__)) GetInputVoltage_Response;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetUptime;

typedef struct {
	TFPMessageHeader header;
	uint32_t uptime;
} __attribute__((__packed__)) GetUptime_Response;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetAllData1;

typedef struct {
	TFPMessageHeader header;
	float power;
	float current[3];
	uint8_t energy_meter_type;
	uint32_t error_count[6];
	uint8_t input[1];
	uint8_t output_sg_ready[1];
	uint8_t output_relay[1];
	uint16_t voltage;
	uint32_t uptime;
} __attribute__((__packed__)) GetAllData1_Response;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetSDInformation;

typedef struct {
	TFPMessageHeader header;
	uint32_t sd_status;
	uint32_t lfs_status;
	uint16_t sector_size;
	uint32_t sector_count;
	uint32_t card_type;
	uint8_t product_rev;
	char product_name[5];
	uint8_t manufacturer_id;
} __attribute__((__packed__)) GetSDInformation_Response;

typedef struct {
	TFPMessageHeader header;
	uint32_t wallbox_id;
	uint8_t year;
	uint8_t month;
	uint8_t day;
	uint8_t hour;
	uint8_t minute;
	uint16_t flags;
	uint16_t power;
} __attribute__((__packed__)) SetSDWallboxDataPoint;

typedef struct {
	TFPMessageHeader header;
	uint8_t status;
} __attribute__((__packed__)) SetSDWallboxDataPoint_Response;

typedef struct {
	TFPMessageHeader header;
	uint32_t wallbox_id;
	uint8_t year;
	uint8_t month;
	uint8_t day;
	uint8_t hour;
	uint8_t minute;
	uint16_t amount;
} __attribute__((__packed__)) GetSDWallboxDataPoints;

typedef struct {
	TFPMessageHeader header;
	uint8_t status;
} __attribute__((__packed__)) GetSDWallboxDataPoints_Response;

typedef struct {
	TFPMessageHeader header;
	uint32_t wallbox_id;
	uint8_t year;
	uint8_t month;
	uint8_t day;
	uint32_t energy;
} __attribute__((__packed__)) SetSDWallboxDailyDataPoint;

typedef struct {
	TFPMessageHeader header;
	uint8_t status;
} __attribute__((__packed__)) SetSDWallboxDailyDataPoint_Response;

typedef struct {
	TFPMessageHeader header;
	uint32_t wallbox_id;
	uint8_t year;
	uint8_t month;
	uint8_t day;
	uint8_t amount;
} __attribute__((__packed__)) GetSDWallboxDailyDataPoints;

typedef struct {
	TFPMessageHeader header;
	uint8_t status;
} __attribute__((__packed__)) GetSDWallboxDailyDataPoints_Response;

typedef struct {
	TFPMessageHeader header;
	uint8_t year;
	uint8_t month;
	uint8_t day;
	uint8_t hour;
	uint8_t minute;
	uint16_t flags;
	int32_t power_grid;
	int32_t power_general[6];
	uint32_t price;
} __attribute__((__packed__)) SetSDEnergyManagerDataPoint;

typedef struct {
	TFPMessageHeader header;
	uint8_t status;
} __attribute__((__packed__)) SetSDEnergyManagerDataPoint_Response;

typedef struct {
	TFPMessageHeader header;
	uint8_t year;
	uint8_t month;
	uint8_t day;
	uint8_t hour;
	uint8_t minute;
	uint16_t amount;
} __attribute__((__packed__)) GetSDEnergyManagerDataPoints;

typedef struct {
	TFPMessageHeader header;
	uint8_t status;
} __attribute__((__packed__)) GetSDEnergyManagerDataPoints_Response;

typedef struct {
	TFPMessageHeader header;
	uint8_t year;
	uint8_t month;
	uint8_t day;
	uint32_t energy_grid_in;
	uint32_t energy_grid_out;
	uint32_t energy_general_in[6];
	uint32_t energy_general_out[6];
	uint32_t price;
} __attribute__((__packed__)) SetSDEnergyManagerDailyDataPoint;

typedef struct {
	TFPMessageHeader header;
	uint8_t status;
} __attribute__((__packed__)) SetSDEnergyManagerDailyDataPoint_Response;

typedef struct {
	TFPMessageHeader header;
	uint8_t year;
	uint8_t month;
	uint8_t day;
	uint8_t amount;
} __attribute__((__packed__)) GetSDEnergyManagerDailyDataPoints;

typedef struct {
	TFPMessageHeader header;
	uint8_t status;
} __attribute__((__packed__)) GetSDEnergyManagerDailyDataPoints_Response;

typedef struct {
	TFPMessageHeader header;
	uint16_t data_length;
	uint16_t data_chunk_offset;
	uint8_t data_chunk_data[60];
} __attribute__((__packed__)) SDWallboxDataPointsLowLevel_Callback;

typedef struct {
	TFPMessageHeader header;
	uint16_t data_length;
	uint16_t data_chunk_offset;
	uint32_t data_chunk_data[15];
} __attribute__((__packed__)) SDWallboxDailyDataPointsLowLevel_Callback;

typedef struct {
	TFPMessageHeader header;
	uint16_t data_length;
	uint16_t data_chunk_offset;
	uint8_t data_chunk_data[34];
} __attribute__((__packed__)) SDEnergyManagerDataPointsLowLevel_Callback;

typedef struct {
	TFPMessageHeader header;
	uint16_t data_length;
	uint16_t data_chunk_offset;
	uint32_t data_chunk_data[15];
} __attribute__((__packed__)) SDEnergyManagerDailyDataPointsLowLevel_Callback;

typedef struct {
	TFPMessageHeader header;
	uint32_t password;
} __attribute__((__packed__)) FormatSD;

typedef struct {
	TFPMessageHeader header;
	uint8_t format_status;
} __attribute__((__packed__)) FormatSD_Response;

typedef struct {
	TFPMessageHeader header;
	uint8_t seconds;
	uint8_t minutes;
	uint8_t hours;
	uint8_t days;
	uint8_t days_of_week;
	uint8_t month;
	uint16_t year;
} __attribute__((__packed__)) SetDateTime;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetDateTime;

typedef struct {
	TFPMessageHeader header;
	uint8_t seconds;
	uint8_t minutes;
	uint8_t hours;
	uint8_t days;
	uint8_t days_of_week;
	uint8_t month;
	uint16_t year;
} __attribute__((__packed__)) GetDateTime_Response;

typedef struct {
	TFPMessageHeader header;
	uint8_t page;
} __attribute__((__packed__)) GetDataStorage;

typedef struct {
	TFPMessageHeader header;
	uint8_t status;
	uint8_t data[63];
} __attribute__((__packed__)) GetDataStorage_Response;

typedef struct {
	TFPMessageHeader header;
	uint8_t page;
	uint8_t data[63];
} __attribute__((__packed__)) SetDataStorage;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) ResetEnergyMeterRelativeEnergy;


// Function prototypes
BootloaderHandleMessageResponse get_energy_meter_values(const GetEnergyMeterValues *data, GetEnergyMeterValues_Response *response);
BootloaderHandleMessageResponse get_energy_meter_detailed_values_low_level(const GetEnergyMeterDetailedValuesLowLevel *data, GetEnergyMeterDetailedValuesLowLevel_Response *response);
BootloaderHandleMessageResponse get_energy_meter_state(const GetEnergyMeterState *data, GetEnergyMeterState_Response *response);
BootloaderHandleMessageResponse get_input(const GetInput *data, GetInput_Response *response);
BootloaderHandleMessageResponse set_sg_ready_output(const SetSGReadyOutput *data);
BootloaderHandleMessageResponse get_sg_ready_output(const GetSGReadyOutput *data, GetSGReadyOutput_Response *response);
BootloaderHandleMessageResponse set_relay_output(const SetRelayOutput *data);
BootloaderHandleMessageResponse get_relay_output(const GetRelayOutput *data, GetRelayOutput_Response *response);
BootloaderHandleMessageResponse get_input_voltage(const GetInputVoltage *data, GetInputVoltage_Response *response);
BootloaderHandleMessageResponse get_uptime(const GetUptime *data, GetUptime_Response *response);
BootloaderHandleMessageResponse get_all_data_1(const GetAllData1 *data, GetAllData1_Response *response);
BootloaderHandleMessageResponse get_sd_information(const GetSDInformation *data, GetSDInformation_Response *response);
BootloaderHandleMessageResponse set_sd_wallbox_data_point(const SetSDWallboxDataPoint *data, SetSDWallboxDataPoint_Response *response);
BootloaderHandleMessageResponse get_sd_wallbox_data_points(const GetSDWallboxDataPoints *data, GetSDWallboxDataPoints_Response *response);
BootloaderHandleMessageResponse set_sd_wallbox_daily_data_point(const SetSDWallboxDailyDataPoint *data, SetSDWallboxDailyDataPoint_Response *response);
BootloaderHandleMessageResponse get_sd_wallbox_daily_data_points(const GetSDWallboxDailyDataPoints *data, GetSDWallboxDailyDataPoints_Response *response);
BootloaderHandleMessageResponse set_sd_energy_manager_data_point(const SetSDEnergyManagerDataPoint *data, SetSDEnergyManagerDataPoint_Response *response);
BootloaderHandleMessageResponse get_sd_energy_manager_data_points(const GetSDEnergyManagerDataPoints *data, GetSDEnergyManagerDataPoints_Response *response);
BootloaderHandleMessageResponse set_sd_energy_manager_daily_data_point(const SetSDEnergyManagerDailyDataPoint *data, SetSDEnergyManagerDailyDataPoint_Response *response);
BootloaderHandleMessageResponse get_sd_energy_manager_daily_data_points(const GetSDEnergyManagerDailyDataPoints *data, GetSDEnergyManagerDailyDataPoints_Response *response);
BootloaderHandleMessageResponse format_sd(const FormatSD *data, FormatSD_Response *response);
BootloaderHandleMessageResponse set_date_time(const SetDateTime *data);
BootloaderHandleMessageResponse get_date_time(const GetDateTime *data, GetDateTime_Response *response);
BootloaderHandleMessageResponse get_data_storage(const GetDataStorage *data, GetDataStorage_Response *response);
BootloaderHandleMessageResponse set_data_storage(const SetDataStorage *data);
BootloaderHandleMessageResponse reset_energy_meter_relative_energy(const ResetEnergyMeterRelativeEnergy *data);

// Callbacks
bool handle_sd_wallbox_data_points_low_level_callback(void);
bool handle_sd_wallbox_daily_data_points_low_level_callback(void);
bool handle_sd_energy_manager_data_points_low_level_callback(void);
bool handle_sd_energy_manager_daily_data_points_low_level_callback(void);

#define COMMUNICATION_CALLBACK_TICK_WAIT_MS 1
#define COMMUNICATION_CALLBACK_HANDLER_NUM 4
#define COMMUNICATION_CALLBACK_LIST_INIT \
	handle_sd_wallbox_data_points_low_level_callback, \
	handle_sd_wallbox_daily_data_points_low_level_callback, \
	handle_sd_energy_manager_data_points_low_level_callback, \
	handle_sd_energy_manager_daily_data_points_low_level_callback, \


#endif
