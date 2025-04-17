#ifndef DIMMABLE_LIGHT_H
#define DIMMABLE_LIGHT_H

#include "Module.h"
#include "Communication.h"
#include <Arduino.h>
#include <ArduinoJson.h>

class DimmableLight : public Module {
private:
    int luminosity;
public:
    DimmableLight(int pi, const char* n) : Module(pi, DIMMABLELIGHT, n) {
        luminosity = 1023; //max luminosity
    } // Set the type to DIMMABLELIGHT
    
    void setup() override;
    void Received_data(const char* Rx_name, const char* Rx_cmd, int Rx_luminosity);
};

#endif // DIMMABLE_LIGHT_H
