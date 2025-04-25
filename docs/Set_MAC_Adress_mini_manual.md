# Set MAC Addresses in the Code

Now that you have the MAC addresses of both devices, you'll need to insert them into the corresponding files.

## ESP32_now.ino

1. Locate the line where the MAC address of the ESP8266 receiver is defined:
```cpp
uint8_t peerMac1[] = {0xXX, 0xXX, 0xXX, 0xXX, 0xXX, 0xXX};
```
2. Replace the values with the actual MAC address of your ESP8266 (converted to hexadecimal format and split).

## ESP8266_now.ino

1. Locate the line where the MAC address of the ESP32 receiver is defined:
```cpp
uint8_t esp32Mac[] = {0xXX, 0xXX, 0xXX, 0xXX, 0xXX, 0xXX}; 
```
2. Replace with the actual MAC address of your ESP32.

✅ **Double check:** The address should be enclosed in curly braces, with each byte separated by a comma and prefixed by `0x`.

---