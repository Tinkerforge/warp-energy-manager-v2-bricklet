#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from tinkerforge.ip_connection import IPConnection
from tinkerforge.bricklet_warp_energy_manager_v2 import BrickletWARPEnergyManagerV2
import time

HOST = "localhost"
PORT = 4223

found_uid = None

def cb_enumerate(uid, connected_uid, position, hardware_version, firmware_version, device_identifier, enumeration_type):
    global found_uid

    if device_identifier == BrickletWARPEnergyManagerV2.DEVICE_IDENTIFIER:
        found_uid = uid

def get_first_wem2_bricklet():
    global found_uid

    ipcon = IPConnection()
    ipcon.connect(HOST, PORT)
    ipcon.register_callback(IPConnection.CALLBACK_ENUMERATE, cb_enumerate)
    ipcon.enumerate()
    for i in range(100):
        if found_uid != None:
            return BrickletWARPEnergyManagerV2(found_uid, ipcon)
        time.sleep(0.01)

    return None

if __name__ == "__main__":
    wem2 = get_first_wem2_bricklet()
    print('Found', wem2)
