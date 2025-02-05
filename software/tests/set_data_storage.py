#!/usr/bin/env python3
# -*- coding: utf-8 -*-

HOST = 'wem2-2b6f.localdomain'
PORT = 4223
EM_UID = 'YsA8F'

from collections import namedtuple
from tinkerforge.ip_connection import IPConnection
from tinkerforge.bricklet_warp_energy_manager_v2 import BrickletWARPEnergyManagerV2

WallboxDataPoint = namedtuple('WallboxDataPoint', ['wallbox_id', 'year', 'month', 'day', 'hour', 'minute', 'charge_tracker_id_start', 'charge_tracker_id_end', 'flags_start', 'flags_end', 'line_voltages', 'line_currents', 'line_power_factors', 'max_current', 'energy_abs'])

if __name__ == '__main__':
    ipcon = IPConnection()
    ipcon.connect(HOST, PORT)
    em = BrickletWARPEnergyManagerV2(EM_UID, ipcon)
    print(em.set_data_storage(1,63*[0]))
