#ifndef RELAY_H
#define RELAY_H

#include "Module.h"
#include "Communication.h"
#include <Arduino.h>

class Relay : public Module {
public:
    Relay(int pi, const char* n) : Module(pi, RELAY, n) {}  // Constructor

    void setup() override;
    void Received_data(esp_now_message incomingData);
};

#endif // RELAY_H
