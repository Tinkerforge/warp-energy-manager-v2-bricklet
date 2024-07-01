#!/usr/bin/env python3
# -*- coding: utf-8 -*-

HOST = "localhost"
PORT = 4223
UID = "YsA8F" 

from tinkerforge.ip_connection import IPConnection
from tinkerforge.bricklet_warp_energy_manager_v2 import BrickletWARPEnergyManagerV2
import time

if __name__ == "__main__":
    ipcon = IPConnection() # Create IP connection
    wem = BrickletWARPEnergyManagerV2(UID, ipcon) # Create device object

    ipcon.connect(HOST, PORT) # Connect to brickd
    # Don't use device before ipcon is connected

    while True:
        print('Input: ', wem.get_input())
        wem.set_relay_output((0, 1))
        print(wem.get_relay_output())
        wem.set_sg_ready_output((1, 0))
        print(wem.get_sg_ready_output())
        time.sleep(1)
        print('Input: ', wem.get_input())
        wem.set_relay_output((1, 0))
        print(wem.get_relay_output())
        wem.set_sg_ready_output((0, 1))
        print(wem.get_sg_ready_output())
        time.sleep(1)
