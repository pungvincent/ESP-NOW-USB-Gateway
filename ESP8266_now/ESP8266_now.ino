#include <ESP8266WiFi.h>
#include <espnow.h>

#define BUTTON_PIN 5
#define LED_PIN 4

uint8_t esp32Mac[] = {0xXX, 0xXX, 0xXX, 0xXX, 0xXX, 0xXX}; // Change ESP32 MAC address

typedef struct {
    char msg[32];
} esp_now_message;

// Send confirmation callback
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {
    Serial.print("Message send status: ");
    Serial.println(sendStatus == 0 ? "Success" : "Failed");
}

// Receive function
void onDataRecv(uint8_t *mac, uint8_t *data, uint8_t len) {
    esp_now_message incomingData;
    memcpy(&incomingData, data, sizeof(incomingData));
    Serial.print("Message received: ");
    Serial.println(incomingData.msg);
    
    if (strcmp(incomingData.msg, "LED_TOGGLE") == 0) {
        digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    }
    else if (strcmp(incomingData.msg, "LED_ON") == 0) {
        digitalWrite(LED_PIN, HIGH);
    }
    else if (strcmp(incomingData.msg, "LED_OFF") == 0) {
        digitalWrite(LED_PIN, LOW);
    }
}

// Send function
void sendMessage(const char *message) {
    esp_now_message mess;
    strncpy(mess.msg, message, sizeof(mess.msg));
    esp_now_send(esp32Mac, (uint8_t*)&mess, sizeof(mess));
    Serial.println("Message sent");
}

void setup() {
    Serial.begin(115200);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);

    WiFi.mode(WIFI_STA);
    if (esp_now_init() != 0) {
        Serial.println("ESP-NOW initialization failed");
        return;
    }

    esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
    esp_now_register_send_cb(OnDataSent);

    // Add ESP32 as a peer (old ESP8266 API)
    if (esp_now_add_peer(esp32Mac, ESP_NOW_ROLE_COMBO, 0, NULL, 0) != 0) {
        Serial.println("Failed to add ESP32 as a peer");
        return;
    }

    esp_now_register_recv_cb(onDataRecv);
}

void loop() {
    if (digitalRead(BUTTON_PIN) == HIGH) {
        sendMessage("BUTTON_PRESSED");
        delay(500); // Debounce delay
    }
}

