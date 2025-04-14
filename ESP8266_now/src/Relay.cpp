#include "Relay.h"

void Relay::setup() {
    pinMode(pin, OUTPUT); // Set the pin as an output
}

void Relay::Received_data(const char* Rx_name, const char* Rx_cmd) {
    if (strcmp(Rx_name, this->name) == 0) {
        if (strcmp(Rx_cmd, "ON") == 0) {
            digitalWrite(pin, HIGH); // Turn RELAY ON
        } else if (strcmp(Rx_cmd, "OFF") == 0) {
            digitalWrite(pin, LOW); // Turn RELAY OFF
        } else if (strcmp(Rx_cmd, "TOGGLE") == 0) {
            digitalWrite(pin, !digitalRead(pin)); // Toggle RELAY
        }
        //Send back acknowledgment -> Example: {"type":"relay","name":"relay1","state":"ON"}
        StaticJsonDocument<128> doc;
        doc["type"] = "relay";                         // Message type
        doc["name"] = name;                        // Switch name
        doc["state"] = digitalRead(pin) ? "ON" : "OFF"; // Read pin state
        char buffer[128];
        serializeJson(doc, buffer); // Convert JSON to char[]
        sendMessage(buffer);
    }
}