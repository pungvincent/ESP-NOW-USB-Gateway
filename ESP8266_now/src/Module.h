#ifndef MODULE_H
#define MODULE_H

class Module {
protected:
    int pin;
public:
    Module(int p) : pin(p) {}
    virtual void setup() = 0;
};

#endif // MODULE_H