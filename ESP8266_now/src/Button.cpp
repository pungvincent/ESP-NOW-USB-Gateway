#include "Button.h"
#include "Communication.h"

void Button::setup() {
    pinMode(pin, INPUT_PULLUP);
}

void Button::loop() {
    if (digitalRead(pin) == HIGH) {
        sendMessage("BUTTON_PRESSED");
        delay(500); // Debounce
    }
}