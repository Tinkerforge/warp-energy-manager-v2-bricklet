#!/usr/bin/env python3
# -*- coding: utf-8 -*-

HOST = "seb-21VZ"
PORT = 4223
UID = "2yvwTP" 

from tinkerforge.ip_connection import IPConnection
from tinkerforge.bricklet_warp_energy_manager_v2 import BrickletWARPEnergyManagerV2
import time

if __name__ == "__main__":
    ipcon = IPConnection() # Create IP connection
    wem = BrickletWARPEnergyManagerV2(UID, ipcon) # Create device object

    ipcon.connect(HOST, PORT) # Connect to brickd
    # Don't use device before ipcon is connected

    while True:
        wem.set_relay_output(0, True)
        time.sleep(5)
        wem.set_relay_output(1, True)
        time.sleep(5)
        wem.set_sg_ready_output(0, True)
        time.sleep(5)
        wem.set_sg_ready_output(1, True)
        time.sleep(5)
        wem.set_relay_output(0, False)
        time.sleep(5)
        wem.set_relay_output(1, False)
        time.sleep(5)
        wem.set_sg_ready_output(0, False)
        time.sleep(5)
        wem.set_sg_ready_output(1, False)
        time.sleep(5)
