#include "Communication.h"
#include "BinarySwitch.h"
#include <Arduino.h>

extern uint8_t esp32Mac[];

/*--------------------
All extern Rx modules
--------------------*/
extern BinarySwitch led;

void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {
    Serial.print("Message send status: ");
    Serial.println(sendStatus == 0 ? "Success" : "Failed");
}

void onDataRecv(uint8_t *mac, uint8_t *data, uint8_t len) {
    esp_now_message incomingData;
    memcpy(&incomingData, data, sizeof(incomingData));
    Serial.print("Message received: ");
    Serial.println(incomingData.msg);

    /*-------------
    All Rx modules
    -------------*/
    led.Received_data(incomingData);

}

void sendMessage(const char *message) {
    esp_now_message mess;
    strncpy(mess.msg, message, sizeof(mess.msg));
    esp_now_send(esp32Mac, (uint8_t*)&mess, sizeof(mess));
    Serial.println("Message sent");
}