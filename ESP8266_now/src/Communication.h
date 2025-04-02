// Communication.h
#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <ESP8266WiFi.h>
#include <espnow.h>

typedef struct {
    char msg[32];
} esp_now_message;


void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus);
void onDataRecv(uint8_t *mac, uint8_t *data, uint8_t len);
void sendMessage(const char *message);

#endif // COMMUNICATION_H