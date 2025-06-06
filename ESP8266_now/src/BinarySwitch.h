#ifndef BINARY_SWITCH_H
#define BINARY_SWITCH_H

#include "Module.h"
#include "Communication.h"
#include <Arduino.h>
#include <ArduinoJson.h>

class BinarySwitch : public Module {
public:
    BinarySwitch(int pi, const char* n) : Module(pi, BINARY_SWITCH, n) {} // Set the type to BINARY_SWITCH
    
    void setup() override;
    void Received_data(const char* Rx_name, const char* Rx_cmd);
};

#endif // BINARY_SWITCH_H
