#include "Communication.h"
#include <Arduino.h>
#include "BinarySwitch.h"
#include "Relay.h"
#include <ArduinoJson.h>

extern uint8_t esp32Mac[];

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
    const char* Rx_type = doc["type"];
    const char* Rx_name = doc["name"];
    const char* Rx_cmd = doc["cmd"];
    //float value = doc["value"];

    Serial.print("Parsed type: ");
    Serial.println(Rx_type);
    Serial.print("Parsed name: ");
    Serial.println(Rx_name);
    Serial.print("Parsed cmd: ");
    Serial.println(Rx_cmd);

    for (Module* receiver : receivers) {
        if (receiver->getType() == BINARY_SWITCH) {
            static_cast<BinarySwitch*>(receiver)->Received_data(Rx_name, Rx_cmd);
        } 
        else if (receiver->getType() == RELAY) {
            static_cast<Relay*>(receiver)->Received_data(Rx_name, Rx_cmd);
        }
    }
}



// Function to send an ESP-NOW message
bool sendMessage(const char *message) {
    esp_now_message mess;
    strncpy(mess.msg, message, sizeof(mess.msg));

    //Maximum ESP-NOW payload: ~250 bytes so we need to send only the actual length of the message
    // Send only the actual length (plus null terminator)
    int lengthToSend = strlen(mess.msg) + 1;

    uint8_t result = esp_now_send(esp32Mac, (uint8_t*)&mess, lengthToSend);

    Serial.println(result == 0 ? "Message sent!" : "Failed to send message");
    return result == 0 ;
}
