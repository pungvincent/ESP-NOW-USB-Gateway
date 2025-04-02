#include <Arduino.h>
#include "src/BinarySwitch.h"
#include "src/Button.h"
#include "src/Communication.h"

uint8_t esp32Mac[] = {0xXX, 0xXX, 0xXX, 0xXX, 0xXX, 0xXX};


/*-----------------
Declare all modules
-----------------*/
BinarySwitch led(4);
Button button(5);

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    
    if (esp_now_init() != 0) {
        Serial.println("ESP-NOW initialization failed");
        return;
    }

    esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
    esp_now_register_send_cb(OnDataSent);

    if (esp_now_add_peer(esp32Mac, ESP_NOW_ROLE_COMBO, 0, NULL, 0) != 0) {
        Serial.println("Failed to add ESP32 as a peer");
        return;
    }

    esp_now_register_recv_cb(onDataRecv);
    
    /*---------------
    Setup all modules
    ---------------*/
    led.setup();
    button.setup();
}

void loop() {
    button.loop();
}
