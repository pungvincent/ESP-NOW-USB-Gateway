#ifndef BINARY_SWITCH_H
#define BINARY_SWITCH_H

#include "Module.h"
#include <Arduino.h>
#include "Communication.h"

class BinarySwitch : public Module {
public:
    BinarySwitch(int p) : Module(p) {}
    void setup() override;
    void Received_data(esp_now_message incomingData);
};

#endif