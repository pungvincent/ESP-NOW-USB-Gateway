#include <Arduino.h>
#include "src/BinarySwitch.h"
#include "src/Button.h"
#include "src/Relay.h"
#include "src/Communication.h"

uint8_t esp32Mac[] = {0xXX, 0xXX, 0xXX, 0xXX, 0xXX, 0xXX}; // Replace with actual MAC address
/* -----------------
   Declare all modules
   ----------------- */
BinarySwitch led(4,"Switch1"); // LED switch on pin 4
Button button(5, "Button1");    // Button on pin 5
Relay relay(16, "Relay1");      // Relay on pin 16

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA); // Set WiFi mode to station
    
    if (esp_now_init() != 0) {
        Serial.println("ESP-NOW initialization failed");
        return;
    }

    esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
    esp_now_register_recv_cb(onDataRecv);

    if (esp_now_add_peer(esp32Mac, ESP_NOW_ROLE_COMBO, 0, NULL, 0) != 0) {
        Serial.println("Failed to add ESP32 as a peer");
        return;
    }

    /* -----------------
       Setup all modules
       ----------------- */
    led.setup();
    button.setup();
    relay.setup();

    /* ----------------------------
       Register modules as receivers
       ---------------------------- */
    registerReceiver(&led);
    registerReceiver(&relay);
}

void loop() {
    button.loop(); // Read button state
}
