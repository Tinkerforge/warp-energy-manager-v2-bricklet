#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from common import get_first_wem2_bricklet
import time

if __name__ == "__main__":
    wem = get_first_wem2_bricklet()

    wem.set_sg_ready_output(0, 0)
    wem.set_sg_ready_output(1, 0)
    wem.set_relay_output(0, 0)
    wem.set_relay_output(1, 0)
    time.sleep(0.1)
    inp = wem.get_input()
    if inp == (False, False, False, False):
        print("Check 0000 OK")
    else:
        print("Check 0000 Failed", inp)

    wem.set_sg_ready_output(0, 1)
    wem.set_sg_ready_output(1, 0)
    wem.set_relay_output(0, 0)
    wem.set_relay_output(1, 0)
    time.sleep(0.1)
    inp = wem.get_input()
    if inp == (True, False, False, False):
        print("Check 1000 OK")
    else:
        print("Check 1000 Failed", inp)

    wem.set_sg_ready_output(0, 0)
    wem.set_sg_ready_output(1, 1)
    wem.set_relay_output(0, 0)
    wem.set_relay_output(1, 0)
    time.sleep(0.1)
    inp = wem.get_input()
    if inp == (False, True, False, False):
        print("Check 0100 OK")
    else:
        print("Check 0100 Failed", inp)

    wem.set_sg_ready_output(0, 0)
    wem.set_sg_ready_output(1, 0)
    wem.set_relay_output(0, 1)
    wem.set_relay_output(1, 0)
    time.sleep(0.1)
    inp = wem.get_input()
    if inp == (False, False, True, False):
        print("Check 0010 OK")
    else:
        print("Check 0010 Failed", inp)

    wem.set_sg_ready_output(0, 0)
    wem.set_sg_ready_output(1, 0)
    wem.set_relay_output(0, 0)
    wem.set_relay_output(1, 1)
    time.sleep(0.1)
    inp = wem.get_input()
    if inp == (False, False, False, True):
        print("Check 0001 OK")
    else:
        print("Check 0001 Failed", inp)

    sd_info = wem.get_sd_information()
    ret = wem.format_sd(0x4223ABCD)
    time.sleep(1.5)
    sd_info2 = wem.get_sd_information()
    if sd_info == sd_info2:
        print("SD OK")
    else:
        print("SD failed")
