#include "BinarySwitch.h"

void BinarySwitch::setup() {
    pinMode(pin, OUTPUT); // Set the pin as an output
}

void BinarySwitch::Received_data(esp_now_message incomingData) {
    
    if (strncmp(incomingData.msg, "LED_TOGGLE", sizeof(incomingData.msg)) == 0) {
        digitalWrite(pin, !digitalRead(pin)); // Toggle LED state
    } else if (strncmp(incomingData.msg, "LED_ON", sizeof(incomingData.msg)) == 0) {
        digitalWrite(pin, HIGH); // Turn LED ON
    } else if (strncmp(incomingData.msg, "LED_OFF", sizeof(incomingData.msg)) == 0) {
        digitalWrite(pin, LOW); // Turn LED OFF
    }
}
