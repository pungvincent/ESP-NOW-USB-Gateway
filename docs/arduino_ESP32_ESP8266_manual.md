# Installing Dependencies for ESP32 and ESP8266 with Arduino

To use this project, you need to install the Arduino IDE and all necessary dependencies for the ESP32 and ESP8266.

There are multiple ways to work with ESP32 and ESP8266 devices, but we’ll use the most common and straightforward method.

---

## 1. Install the Arduino IDE

Download it from the official website:  
https://www.arduino.cc/en/software

---

## 2. Add Board URLs

Open **File > Preferences**, and in the **Additional Board URLs** field, add the following:

- **ESP8266**: `http://arduino.esp8266.com/stable/package_esp8266com_index.json`  
- **ESP32**: `https://dl.espressif.com/dl/package_esp32_index.json`

> If you already have URLs there, separate each one with a comma.

---

## 3. Install Board Packages

Go to **Tools > Board > Board Manager**, then search for:

- **"esp8266 by ESP8266 Community"**
- **"esp32 by Espressif Systems"**

Click **Install** for both if they are not already installed.

---

## USB Drivers (if needed)

If your board isn’t recognized by your computer, you may need to install the appropriate USB driver:

- **CP210x (Silicon Labs)**: https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers  
- **CH340 (WCH)**: http://www.wch.cn/downloads/CH341SER_EXE.html

> The required driver depends on your specific board. Refer to your board's datasheet or documentation for details.

---

## 4. Testing

To verify your setup:

- Open **File > Examples**
- Try **ESP8266 > Blink** or **ESP32 > WiFiScan** to test your board.

---

## ✅ Done!

You're now ready to develop and upload Arduino sketches to your ESP32 and ESP8266 boards!
