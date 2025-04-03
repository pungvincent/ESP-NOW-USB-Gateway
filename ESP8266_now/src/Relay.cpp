#include "Relay.h"

void Relay::setup() {
    pinMode(pin, OUTPUT); // Set the pin as an output
}

void Relay::Received_data(esp_now_message incomingData) {
    if (strncmp(incomingData.msg, "RELAY_ON", sizeof(incomingData.msg)) == 0) {
        digitalWrite(pin, HIGH); // Turn relay ON
    } else if (strncmp(incomingData.msg, "RELAY_OFF", sizeof(incomingData.msg)) == 0) {
        digitalWrite(pin, LOW); // Turn relay OFF
    }
}
