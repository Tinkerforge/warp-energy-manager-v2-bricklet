/* warp-energy-manager-v2-bricklet
 * Copyright (C) 2024 Olaf Lüke <olaf@tinkerforge.com>
 *
 * communication.c: TFP protocol message handling
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

#include "communication.h"

#include "bricklib2/utility/communication_callback.h"
#include "bricklib2/protocols/tfp/tfp.h"

BootloaderHandleMessageResponse handle_message(const void *message, void *response) {
	const uint8_t length = ((TFPMessageHeader*)message)->length;
	switch(tfp_get_fid_from_message(message)) {
		case FID_SET_RGB_VALUE:                              return length != sizeof(SetRGBValue)                          ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : set_rgb_value(message);
		case FID_GET_RGB_VALUE:                              return length != sizeof(GetRGBValue)                          ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : get_rgb_value(message, response);
		case FID_GET_ENERGY_METER_VALUES:                    return length != sizeof(GetEnergyMeterValues)                 ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : get_energy_meter_values(message, response);
		case FID_GET_ENERGY_METER_DETAILED_VALUES_LOW_LEVEL: return length != sizeof(GetEnergyMeterDetailedValuesLowLevel) ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : get_energy_meter_detailed_values_low_level(message, response);
		case FID_GET_ENERGY_METER_STATE:                     return length != sizeof(GetEnergyMeterState)                  ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : get_energy_meter_state(message, response);
		case FID_GET_INPUT:                                  return length != sizeof(GetInput)                             ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : get_input(message, response);
		case FID_SET_OUTPUT:                                 return length != sizeof(SetOutput)                            ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : set_output(message);
		case FID_GET_OUTPUT:                                 return length != sizeof(GetOutput)                            ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : get_output(message, response);
		case FID_GET_INPUT_VOLTAGE:                          return length != sizeof(GetInputVoltage)                      ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : get_input_voltage(message, response);
		case FID_GET_UPTIME:                                 return length != sizeof(GetUptime)                            ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : get_uptime(message, response);
		case FID_GET_ALL_DATA_1:                             return length != sizeof(GetAllData1)                          ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : get_all_data_1(message);
		case FID_GET_SD_INFORMATION:                         return length != sizeof(GetSDInformation)                     ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : get_sd_information(message, response);
		case FID_SET_SD_WALLBOX_DATA_POINT:                  return length != sizeof(SetSDWallboxDataPoint)                ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : set_sd_wallbox_data_point(message, response);
		case FID_GET_SD_WALLBOX_DATA_POINTS:                 return length != sizeof(GetSDWallboxDataPoints)               ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : get_sd_wallbox_data_points(message, response);
		case FID_SET_SD_WALLBOX_DAILY_DATA_POINT:            return length != sizeof(SetSDWallboxDailyDataPoint)           ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : set_sd_wallbox_daily_data_point(message, response);
		case FID_GET_SD_WALLBOX_DAILY_DATA_POINTS:           return length != sizeof(GetSDWallboxDailyDataPoints)          ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : get_sd_wallbox_daily_data_points(message, response);
		case FID_SET_SD_ENERGY_MANAGER_DATA_POINT:           return length != sizeof(SetSDEnergyManagerDataPoint)          ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : set_sd_energy_manager_data_point(message, response);
		case FID_GET_SD_ENERGY_MANAGER_DATA_POINTS:          return length != sizeof(GetSDEnergyManagerDataPoints)         ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : get_sd_energy_manager_data_points(message, response);
		case FID_SET_SD_ENERGY_MANAGER_DAILY_DATA_POINT:     return length != sizeof(SetSDEnergyManagerDailyDataPoint)     ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : set_sd_energy_manager_daily_data_point(message, response);
		case FID_GET_SD_ENERGY_MANAGER_DAILY_DATA_POINTS:    return length != sizeof(GetSDEnergyManagerDailyDataPoints)    ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : get_sd_energy_manager_daily_data_points(message, response);
		case FID_FORMAT_SD:                                  return length != sizeof(FormatSD)                             ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : format_sd(message, response);
		case FID_SET_DATE_TIME:                              return length != sizeof(SetDateTime)                          ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : set_date_time(message);
		case FID_GET_DATE_TIME:                              return length != sizeof(GetDateTime)                          ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : get_date_time(message, response);
		case FID_SET_LED_STATE:                              return length != sizeof(SetLEDState)                          ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : set_led_state(message);
		case FID_GET_LED_STATE:                              return length != sizeof(GetLEDState)                          ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : get_led_state(message, response);
		case FID_GET_DATA_STORAGE:                           return length != sizeof(GetDataStorage)                       ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : get_data_storage(message, response);
		case FID_SET_DATA_STORAGE:                           return length != sizeof(SetDataStorage)                       ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : set_data_storage(message);
		case FID_RESET_ENERGY_METER_RELATIVE_ENERGY:         return length != sizeof(ResetEnergyMeterRelativeEnergy)       ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : reset_energy_meter_relative_energy(message);
		default: return HANDLE_MESSAGE_RESPONSE_NOT_SUPPORTED;
	}
}


BootloaderHandleMessageResponse set_rgb_value(const SetRGBValue *data) {

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_rgb_value(const GetRGBValue *data, GetRGBValue_Response *response) {
	response->header.length = sizeof(GetRGBValue_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse get_energy_meter_values(const GetEnergyMeterValues *data, GetEnergyMeterValues_Response *response) {
	response->header.length = sizeof(GetEnergyMeterValues_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse get_energy_meter_detailed_values_low_level(const GetEnergyMeterDetailedValuesLowLevel *data, GetEnergyMeterDetailedValuesLowLevel_Response *response) {
	response->header.length = sizeof(GetEnergyMeterDetailedValuesLowLevel_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse get_energy_meter_state(const GetEnergyMeterState *data, GetEnergyMeterState_Response *response) {
	response->header.length = sizeof(GetEnergyMeterState_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse get_input(const GetInput *data, GetInput_Response *response) {
	response->header.length = sizeof(GetInput_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_output(const SetOutput *data) {

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_output(const GetOutput *data, GetOutput_Response *response) {
	response->header.length = sizeof(GetOutput_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse get_input_voltage(const GetInputVoltage *data, GetInputVoltage_Response *response) {
	response->header.length = sizeof(GetInputVoltage_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse get_uptime(const GetUptime *data, GetUptime_Response *response) {
	response->header.length = sizeof(GetUptime_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse get_all_data_1(const GetAllData1 *data) {

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_sd_information(const GetSDInformation *data, GetSDInformation_Response *response) {
	response->header.length = sizeof(GetSDInformation_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_sd_wallbox_data_point(const SetSDWallboxDataPoint *data, SetSDWallboxDataPoint_Response *response) {
	response->header.length = sizeof(SetSDWallboxDataPoint_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse get_sd_wallbox_data_points(const GetSDWallboxDataPoints *data, GetSDWallboxDataPoints_Response *response) {
	response->header.length = sizeof(GetSDWallboxDataPoints_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_sd_wallbox_daily_data_point(const SetSDWallboxDailyDataPoint *data, SetSDWallboxDailyDataPoint_Response *response) {
	response->header.length = sizeof(SetSDWallboxDailyDataPoint_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse get_sd_wallbox_daily_data_points(const GetSDWallboxDailyDataPoints *data, GetSDWallboxDailyDataPoints_Response *response) {
	response->header.length = sizeof(GetSDWallboxDailyDataPoints_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_sd_energy_manager_data_point(const SetSDEnergyManagerDataPoint *data, SetSDEnergyManagerDataPoint_Response *response) {
	response->header.length = sizeof(SetSDEnergyManagerDataPoint_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse get_sd_energy_manager_data_points(const GetSDEnergyManagerDataPoints *data, GetSDEnergyManagerDataPoints_Response *response) {
	response->header.length = sizeof(GetSDEnergyManagerDataPoints_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_sd_energy_manager_daily_data_point(const SetSDEnergyManagerDailyDataPoint *data, SetSDEnergyManagerDailyDataPoint_Response *response) {
	response->header.length = sizeof(SetSDEnergyManagerDailyDataPoint_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse get_sd_energy_manager_daily_data_points(const GetSDEnergyManagerDailyDataPoints *data, GetSDEnergyManagerDailyDataPoints_Response *response) {
	response->header.length = sizeof(GetSDEnergyManagerDailyDataPoints_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse format_sd(const FormatSD *data, FormatSD_Response *response) {
	response->header.length = sizeof(FormatSD_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_date_time(const SetDateTime *data) {

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_date_time(const GetDateTime *data, GetDateTime_Response *response) {
	response->header.length = sizeof(GetDateTime_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_led_state(const SetLEDState *data) {

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_led_state(const GetLEDState *data, GetLEDState_Response *response) {
	response->header.length = sizeof(GetLEDState_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse get_data_storage(const GetDataStorage *data, GetDataStorage_Response *response) {
	response->header.length = sizeof(GetDataStorage_Response);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_data_storage(const SetDataStorage *data) {

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse reset_energy_meter_relative_energy(const ResetEnergyMeterRelativeEnergy *data) {

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}




bool handle_sd_wallbox_data_points_low_level_callback(void) {
	static bool is_buffered = false;
	static SDWallboxDataPointsLowLevel_Callback cb;

	if(!is_buffered) {
		tfp_make_default_header(&cb.header, bootloader_get_uid(), sizeof(SDWallboxDataPointsLowLevel_Callback), FID_CALLBACK_SD_WALLBOX_DATA_POINTS_LOW_LEVEL);
		// TODO: Implement SDWallboxDataPointsLowLevel callback handling

		return false;
	}

	if(bootloader_spitfp_is_send_possible(&bootloader_status.st)) {
		bootloader_spitfp_send_ack_and_message(&bootloader_status, (uint8_t*)&cb, sizeof(SDWallboxDataPointsLowLevel_Callback));
		is_buffered = false;
		return true;
	} else {
		is_buffered = true;
	}

	return false;
}

bool handle_sd_wallbox_daily_data_points_low_level_callback(void) {
	static bool is_buffered = false;
	static SDWallboxDailyDataPointsLowLevel_Callback cb;

	if(!is_buffered) {
		tfp_make_default_header(&cb.header, bootloader_get_uid(), sizeof(SDWallboxDailyDataPointsLowLevel_Callback), FID_CALLBACK_SD_WALLBOX_DAILY_DATA_POINTS_LOW_LEVEL);
		// TODO: Implement SDWallboxDailyDataPointsLowLevel callback handling

		return false;
	}

	if(bootloader_spitfp_is_send_possible(&bootloader_status.st)) {
		bootloader_spitfp_send_ack_and_message(&bootloader_status, (uint8_t*)&cb, sizeof(SDWallboxDailyDataPointsLowLevel_Callback));
		is_buffered = false;
		return true;
	} else {
		is_buffered = true;
	}

	return false;
}

bool handle_sd_energy_manager_data_points_low_level_callback(void) {
	static bool is_buffered = false;
	static SDEnergyManagerDataPointsLowLevel_Callback cb;

	if(!is_buffered) {
		tfp_make_default_header(&cb.header, bootloader_get_uid(), sizeof(SDEnergyManagerDataPointsLowLevel_Callback), FID_CALLBACK_SD_ENERGY_MANAGER_DATA_POINTS_LOW_LEVEL);
		// TODO: Implement SDEnergyManagerDataPointsLowLevel callback handling

		return false;
	}

	if(bootloader_spitfp_is_send_possible(&bootloader_status.st)) {
		bootloader_spitfp_send_ack_and_message(&bootloader_status, (uint8_t*)&cb, sizeof(SDEnergyManagerDataPointsLowLevel_Callback));
		is_buffered = false;
		return true;
	} else {
		is_buffered = true;
	}

	return false;
}

bool handle_sd_energy_manager_daily_data_points_low_level_callback(void) {
	static bool is_buffered = false;
	static SDEnergyManagerDailyDataPointsLowLevel_Callback cb;

	if(!is_buffered) {
		tfp_make_default_header(&cb.header, bootloader_get_uid(), sizeof(SDEnergyManagerDailyDataPointsLowLevel_Callback), FID_CALLBACK_SD_ENERGY_MANAGER_DAILY_DATA_POINTS_LOW_LEVEL);
		// TODO: Implement SDEnergyManagerDailyDataPointsLowLevel callback handling

		return false;
	}

	if(bootloader_spitfp_is_send_possible(&bootloader_status.st)) {
		bootloader_spitfp_send_ack_and_message(&bootloader_status, (uint8_t*)&cb, sizeof(SDEnergyManagerDailyDataPointsLowLevel_Callback));
		is_buffered = false;
		return true;
	} else {
		is_buffered = true;
	}

	return false;
}

void communication_tick(void) {
	communication_callback_tick();
}

void communication_init(void) {
	communication_callback_init();
}
