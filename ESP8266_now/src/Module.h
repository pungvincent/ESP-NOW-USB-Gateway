#ifndef MODULE_H
#define MODULE_H

// Enum to differentiate between module types
enum ModuleType { 
    BINARY_SWITCH,
    RELAY,
    BUTTON,
    UNKNOWN 
};

class Module {
protected:
    int pin; // Pin associated with the module
    ModuleType type; // Store the module type
public:
    Module(int p, ModuleType t) : pin(p), type(t) {} // Constructor initializes pin and type
    virtual void setup() = 0; // Pure virtual function for setup
    virtual ~Module() {} // Virtual destructor for proper cleanup
    ModuleType getType() { return type; } // Getter for the module type
};

#endif // MODULE_H
