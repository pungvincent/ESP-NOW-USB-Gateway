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
    }
}