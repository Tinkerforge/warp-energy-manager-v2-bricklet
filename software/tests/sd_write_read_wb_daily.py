#!/usr/bin/env python3
# -*- coding: utf-8 -*-

HOST = 'seb-2b6s'
PORT = 4223
EM_UID = '2kUNJR'
#EM_UID = '2qcheb'
import time
import sys
import traceback

from collections import namedtuple
from tinkerforge.ip_connection import IPConnection
from tinkerforge.bricklet_warp_energy_manager_v2 import BrickletWARPEnergyManagerV2

WallboxDailyDataPoint = namedtuple('WallboxDailyDataPoint', ['wallbox_id', 'year', 'month', 'day', 'energy'])

def cb_wallbox_daily_data_points(data):
    print(data)

if __name__ == '__main__':
    ipcon = IPConnection()
    ipcon.connect(HOST, PORT)
    em = BrickletWARPEnergyManagerV2(EM_UID, ipcon)
    em.register_callback(em.CALLBACK_SD_WALLBOX_DAILY_DATA_POINTS, cb_wallbox_daily_data_points)

    em.set_response_expected_all(True)
    sd_info = em.get_sd_information()
    print(sd_info)

    for i in range(30):
        ret = em.get_sd_wallbox_daily_data_points(1, 22, i, 1, 30)
        print(ret)
        if ret != 0:
            print("ret {0}".format(ret))
        time.sleep(1)

