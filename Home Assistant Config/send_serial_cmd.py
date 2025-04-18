#!/usr/bin/env python3
import serial
import json
import sys

name = sys.argv[1] if len(sys.argv) > 1 else "unknown"
cmd = sys.argv[2] if len(sys.argv) > 2 else "UNKNOWN"

msg = {
    "type": "switch",
    "name": name,
    "cmd": cmd.upper()
}

ser = serial.Serial('/dev/ttyUSB0', 115200, timeout=1)
ser.write((json.dumps(msg) + "\n").encode())
ser.close()
