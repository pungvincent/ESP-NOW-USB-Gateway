# Retrieve MAC Addresses

To enable communication between ESP devices using ESP-NOW, you need the MAC address of each device.

## Step-by-step

1. Open the Arduino IDE.
2. Open the file `MAC_Address_ESP32.ino` if you're using an ESP32, or `MAC_Address_ESP8266.ino` for the ESP8266.
3. Connect your device via USB.
4. Select the correct board and COM port in **Tools**.
5. Upload the sketch.
6. Open the Serial Monitor (`Ctrl + Shift + M`).
7. The MAC address will be printed in the console.

📌 **Example output:**
```
MAC Address: 24:6F:28:AB:CD:EF
```

🔁 Repeat the same steps for the second device.

---
