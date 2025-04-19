#!/usr/bin/env python3
import serial
import json
import sys

name = sys.argv[1] if len(sys.argv) > 1 else "unknown"
cmd = sys.argv[2] if len(sys.argv) > 2 else "UNKNOWN"
luminosity = sys.argv[3] if len(sys.argv) > 3 else "0"

msg = {
    "type": "switch",
    "name": name,
    "cmd": cmd.upper(),
    "luminosity": luminosity
}

ser = serial.Serial('/dev/ttyUSB0', 115200, timeout=1)
ser.write((json.dumps(msg) + "\n").encode())
ser.close()
