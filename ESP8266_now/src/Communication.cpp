#include "Communication.h"
#include <Arduino.h>
#include "BinarySwitch.h"
#include "Relay.h"
#include <ArduinoJson.h>

std::vector<Module*> receivers; // List of registered receivers

void registerReceiver(Module* module) {
    receivers.push_back(module); // Add module to the list
}



// Callback for incoming ESP-NOW messages
void onDataRecv(uint8_t *mac, uint8_t *data, uint8_t len) {
    esp_now_message incomingData;
    memcpy(&incomingData, data, sizeof(incomingData)); // Copy raw data

    Serial.print("Raw message received: ");
    Serial.println(incomingData.msg);

    // Parse the JSON message from incomingData.msg
    StaticJsonDocument<256> doc;
    DeserializationError error = deserializeJson(doc, incomingData.msg);

    if (error) {
        Serial.print("JSON parsing failed: ");
        Serial.println(error.c_str());
        //return;
    }

    // Example of reading JSON fields
    const char* type = doc["type"];
    const char* name = doc["name"];
    const char* cmd = doc["cmd"];
    //float value = doc["value"];

    Serial.print("Parsed type: ");
    Serial.println(type);
    Serial.print("Parsed name: ");
    Serial.println(name);
    Serial.print("Parsed cmd: ");
    Serial.println(cmd);

    // Distribute the message to the relevant modules
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
