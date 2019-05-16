#!/usr/bin/env python

import serial, sys

serialPort = sys.argv[1]
print serialPort

ser = serial.Serial(
    port=serialPort,
    baudrate=1200,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS
)

ser.close()             # close port
