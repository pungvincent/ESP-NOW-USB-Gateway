#ifndef RELAY_H
#define RELAY_H

#include "Module.h"
#include "Communication.h"
#include <Arduino.h>
#include <ArduinoJson.h>

class Relay : public Module {
public:
    Relay(int pi, const char* n) : Module(pi, RELAY, n) {}  // Constructor

    void setup() override;
    void Received_data(const char* Rx_name, const char* Rx_cmd);
};

#endif // RELAY_H
