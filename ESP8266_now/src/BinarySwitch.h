#ifndef BINARY_SWITCH_H
#define BINARY_SWITCH_H

#include "Module.h"
#include "Communication.h"
#include <Arduino.h>

class BinarySwitch : public Module {
public:
    BinarySwitch(int p) : Module(p, BINARY_SWITCH) {} // Set the type to BINARY_SWITCH
    
    void setup() override;
    void Received_data(esp_now_message incomingData);
};

#endif // BINARY_SWITCH_H
