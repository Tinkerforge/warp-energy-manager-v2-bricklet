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

#include "io.h"

BootloaderHandleMessageResponse handle_message(const void *message, void *response) {
	const uint8_t length = ((TFPMessageHeader*)message)->length;
	switch(tfp_get_fid_from_message(message)) {
		case FID_GET_ENERGY_METER_VALUES:                    return length != sizeof(GetEnergyMeterValues)                 ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : get_energy_meter_values(message, response);
		case FID_GET_ENERGY_METER_DETAILED_VALUES_LOW_LEVEL: return length != sizeof(GetEnergyMeterDetailedValuesLowLevel) ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : get_energy_meter_detailed_values_low_level(message, response);
		case FID_GET_ENERGY_METER_STATE:                     return length != sizeof(GetEnergyMeterState)                  ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : get_energy_meter_state(message, response);
		case FID_GET_INPUT:                                  return length != sizeof(GetInput)                             ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : get_input(message, response);
		case FID_SET_SG_READY_OUTPUT:                        return length != sizeof(SetSGReadyOutput)                     ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : set_sg_ready_output(message);
		case FID_GET_SG_READY_OUTPUT:                        return length != sizeof(GetSGReadyOutput)                     ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : get_sg_ready_output(message, response);
		case FID_SET_RELAY_OUTPUT:                           return length != sizeof(SetRelayOutput)                       ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : set_relay_output(message);
		case FID_GET_RELAY_OUTPUT:                           return length != sizeof(GetRelayOutput)                       ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : get_relay_output(message, response);
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
		case FID_GET_DATA_STORAGE:                           return length != sizeof(GetDataStorage)                       ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : get_data_storage(message, response);
		case FID_SET_DATA_STORAGE:                           return length != sizeof(SetDataStorage)                       ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : set_data_storage(message);
		case FID_RESET_ENERGY_METER_RELATIVE_ENERGY:         return length != sizeof(ResetEnergyMeterRelativeEnergy)       ? HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER : reset_energy_meter_relative_energy(message);
		default: return HANDLE_MESSAGE_RESPONSE_NOT_SUPPORTED;
	}
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
	response->input[0]      = io.in[0] | (io.in[1] << 1) | (io.in[2] << 2) | (io.in[3] << 3);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_sg_ready_output(const SetSGReadyOutput *data) {
	io.sg_ready[0] = data->output[0] & 1;
	io.sg_ready[1] = data->output[0] & 2;

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_sg_ready_output(const GetSGReadyOutput *data, GetSGReadyOutput_Response *response) {
	response->header.length = sizeof(GetSGReadyOutput_Response);
	response->output[0]     = io.sg_ready[0] | (io.sg_ready[1] << 1);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_relay_output(const SetRelayOutput *data) {
	io.relay[0] = data->output[0] & 1;
	io.relay[1] = data->output[1] & 2;;

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_relay_output(const GetRelayOutput *data, GetRelayOutput_Response *response) {
	response->header.length = sizeof(GetRelayOutput_Response);
	response->output[0]     = io.relay[0] | (io.relay[1] << 1);

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
