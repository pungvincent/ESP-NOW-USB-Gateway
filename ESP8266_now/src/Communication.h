#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <ESP8266WiFi.h>
#include <espnow.h>
#include <vector>
#include "Module.h"

// Struct for ESP-NOW messages
typedef struct {
    char msg[32]; // Message buffer (max 32 chars)
} esp_now_message;

// List of modules that receive messages
extern std::vector<Module*> receivers;

// Function prototypes
void registerReceiver(Module* module);
void onDataRecv(uint8_t *mac, uint8_t *data, uint8_t len);
bool sendMessage(const char *message);

#endif // COMMUNICATION_H
