#ifndef RELAY_H
#define RELAY_H

#include "Module.h"
#include "Communication.h"
#include <Arduino.h>

class Relay : public Module {
public:
    Relay(int p) : Module(p, RELAY) {}  // Constructor

    void setup() override;
    void Received_data(esp_now_message incomingData);
};

#endif // RELAY_H
