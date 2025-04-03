#include "Communication.h"
#include <Arduino.h>
#include "BinarySwitch.h"
#include "Relay.h"


std::vector<Module*> receivers; // List of registered receivers

void registerReceiver(Module* module) {
    receivers.push_back(module); // Add module to the list
}

// Callback for incoming ESP-NOW messages
void onDataRecv(uint8_t *mac, uint8_t *data, uint8_t len) {
    esp_now_message incomingData;
    memcpy(&incomingData, data, sizeof(incomingData)); // Copy received data

    Serial.print("Message received: ");
    Serial.println(incomingData.msg);

    // Distribute the message to all registered modules
    for (Module* receiver : receivers) {
        if (receiver->getType() == BINARY_SWITCH) {
            static_cast<BinarySwitch*>(receiver)->Received_data(incomingData);
        } 
        else if (receiver->getType() == RELAY) {
            static_cast<Relay*>(receiver)->Received_data(incomingData);
        }
    }
}


// Function to send an ESP-NOW message
bool sendMessage(const char *message) {
    esp_now_message mess;
    strncpy(mess.msg, message, sizeof(mess.msg));

    if (esp_now_send(NULL, (uint8_t*)&mess, sizeof(mess)) == 0) {
        Serial.println("Message sent successfully");
        return true;
    } else {
        Serial.println("Message failed to send");
        return false;
    }
}
