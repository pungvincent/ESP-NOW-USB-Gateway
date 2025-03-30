#include <ESP8266WiFi.h>
#include <espnow.h>

// Message structure
typedef struct Message {
    char text[32];
} Message;

Message message; // Message content

// Reception callback
void OnDataRecv(uint8_t *mac_addr, uint8_t *incomingData, uint8_t len) {
    memcpy(&message, incomingData, sizeof(message));
    Serial.print("Message received: ");
    Serial.println(message.text);
}

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA); // Station mode

    if (esp_now_init() != 0) {
        Serial.println("ESP-NOW initialization error");
        return;
    }

    esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
    esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
    // Nothing to do here, the callback handles reception
}
