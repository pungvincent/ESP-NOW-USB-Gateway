#include "Button.h"
#include "Communication.h"

void Button::setup() {
    pinMode(pin, INPUT_PULLUP);
}

void Button::loop() {
    static unsigned long lastPressTime = 0;
    if (digitalRead(pin) == HIGH && millis() - lastPressTime > 500) {
        sendMessage("BUTTON_PRESSED");
        lastPressTime = millis();
    }
}
