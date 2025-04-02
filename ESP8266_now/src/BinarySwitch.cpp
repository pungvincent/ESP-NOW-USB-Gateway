#include "BinarySwitch.h"

#include "Communication.h"

void BinarySwitch::setup() {
    pinMode(pin, OUTPUT);
}

void BinarySwitch::Received_data(esp_now_message incomingData) {
    if (strcmp(incomingData.msg, "LED_TOGGLE") == 0) {
        digitalWrite(pin, !digitalRead(pin));
    }
    else if (strcmp(incomingData.msg, "LED_ON") == 0) {
        digitalWrite(pin, HIGH);
    }
    else if (strcmp(incomingData.msg, "LED_OFF") == 0) {
        digitalWrite(pin, LOW);
    }
}
