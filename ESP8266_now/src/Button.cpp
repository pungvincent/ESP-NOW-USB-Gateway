#include "Button.h"
#include "Communication.h"

void Button::setup() {
    pinMode(pin, INPUT_PULLUP);
}

void Button::loop() {
    static unsigned long lastPressTime = 0;
    static bool buttonState = LOW;  // Variable to track the previous button state
    
    bool currentState = digitalRead(pin);  // Read the current state of the button

    // Check if the button state has changed from LOW to HIGH (pressed)
    if (currentState == HIGH && buttonState == LOW && millis() - lastPressTime > 500) {
        sendMessage("BUTTON_PRESSED");
        lastPressTime = millis();  // Update the last press time
    }

    // Update the button state
    buttonState = currentState;
}