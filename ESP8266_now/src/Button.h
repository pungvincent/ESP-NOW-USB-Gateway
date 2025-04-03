#ifndef BUTTON_H
#define BUTTON_H

#include "Module.h"
#include <Arduino.h>
#include "Communication.h"

class Button : public Module {
public:
    Button(int p) : Module(p, BUTTON) {} // Constructor

    void setup() override;
    void loop();
};

#endif // BUTTON_H
