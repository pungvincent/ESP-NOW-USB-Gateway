#ifndef BINARY_SWITCH_H
#define BINARY_SWITCH_H

#include "Module.h"
#include "Communication.h"
#include <Arduino.h>

class BinarySwitch : public Module {
public:
    BinarySwitch(int pi, const char* n) : Module(pi, BINARY_SWITCH, n) {} // Set the type to BINARY_SWITCH
    
    void setup() override;
    void Received_data(esp_now_message incomingData);
};

#endif // BINARY_SWITCH_H
