#include <esp_now.h>
#include <WiFi.h>

// MAC addresses of the peers
uint8_t peerMac1[] = {0xXX, 0xXX, 0xXX, 0xXX, 0xXX, 0xXX}; // Replace with the MAC address of ESP8266-1
uint8_t peerMac2[] = {0xXX, 0xXX, 0xXX, 0xXX, 0xXX, 0xXX}; // Replace with the MAC address of ESP8266-2

// Structure for ESP-NOW messages
typedef struct {
    char msg[256];
} esp_now_message;

// Callback function for receiving data
void onDataRecv(const esp_now_recv_info_t *info, const uint8_t *data, int len) {
    esp_now_message incomingData;
    memcpy(&incomingData, data, sizeof(incomingData));
    Serial.println(incomingData.msg);
}

// Function to send a message to a specific MAC address
void sendMessage(const char *message, uint8_t *mac) {
    esp_now_message msg;
    strncpy(msg.msg, message, sizeof(msg.msg));

    //Maximum ESP-NOW payload: ~250 bytes so we need to send only the actual length of the message
    // Send only the actual length (plus null terminator)
    int lengthToSend = strlen(msg.msg) + 1;
    esp_err_t result = esp_now_send(mac, (uint8_t*)&msg, lengthToSend);

    Serial.println(result == ESP_OK ? "Message sent!" : "Failed to send message");
}


void setup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);

    // Initialize ESP-NOW
    if (esp_now_init() != ESP_OK) {
        Serial.println("ESP-NOW initialization failed");
        return;
    }

    esp_now_peer_info_t peerInfo;
    memset(&peerInfo, 0, sizeof(peerInfo));
    peerInfo.channel = 0;
    peerInfo.encrypt = false; // Encryption Off

    // Add the first peer
    memcpy(peerInfo.peer_addr, peerMac1, 6);
    esp_now_add_peer(&peerInfo);

    // Add the second peer
    memcpy(peerInfo.peer_addr, peerMac2, 6);
    esp_now_add_peer(&peerInfo);

    // Register the receive callback function
    esp_now_register_recv_cb(onDataRecv);
}

void loop() {
    if (Serial.available()) {
        String input = Serial.readStringUntil('\n');
        input.trim();
        sendMessage(input.c_str(), peerMac1);
        sendMessage(input.c_str(), peerMac2);
    }
}
