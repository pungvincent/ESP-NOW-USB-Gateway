#include <ESP8266WiFi.h>
#include <espnow.h>

// Receiver MAC address
uint8_t receiverMAC[] = {0xXX, 0xXX, 0xXX, 0xXX, 0xXX, 0xXX};   //Change MAC adress here


// Message structure
typedef struct Message {
    char text[32];
} Message;

Message message; // Message content

// Send confirmation callback
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {
    Serial.print("Message send status: ");
    Serial.println(sendStatus == 0 ? "Success" : "Failed");
}

void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA); // Station mode

    if (esp_now_init() != 0) {
        Serial.println("ESP-NOW initialization error");
        return;
    }

    esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
    esp_now_register_send_cb(OnDataSent);
    esp_now_add_peer(receiverMAC, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);

    strcpy(message.text, "Hello ESP-NOW!");
}

void loop() {
    esp_now_send(receiverMAC, (uint8_t *)&message, sizeof(message));
    delay(2000); // Send every 2s
}
