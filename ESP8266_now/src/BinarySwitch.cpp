#include "BinarySwitch.h"

void BinarySwitch::setup() {
    pinMode(pin, OUTPUT); // Set the pin as an output
}

void BinarySwitch::Received_data(const char* Rx_name, const char* Rx_cmd) {
    if (strcmp(Rx_name, this->name) == 0) {
        if (strcmp(Rx_cmd, "ON") == 0) {
            digitalWrite(pin, HIGH); // Turn LED ON
        } else if (strcmp(Rx_cmd, "OFF") == 0) {
            digitalWrite(pin, LOW); // Turn LED OFF
        } else if (strcmp(Rx_cmd, "TOGGLE") == 0) {
            digitalWrite(pin, !digitalRead(pin)); // Toggle LED
        }
        //Send back acknowledgment -> Example: {"type":"switch","name":"switch1","state":"ON"}
        StaticJsonDocument<128> doc;
        doc["type"] = "switch";                         // Message type
        doc["name"] = name;                        // Switch name
        doc["state"] = digitalRead(pin) ? "ON" : "OFF"; // Read pin state
        char buffer[128];
        serializeJson(doc, buffer); // Convert JSON to char[]
        sendMessage(buffer);
    }
}
