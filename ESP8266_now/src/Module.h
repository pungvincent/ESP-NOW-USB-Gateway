#ifndef MODULE_H
#define MODULE_H

#include <cstring>  // For strncpy in C++

// Enum to differentiate between module types
enum ModuleType { 
    BINARY_SWITCH,
    DIMMABLELIGHT,
    RELAY,
    BUTTON,
    UNKNOWN 
};

class Module {
    protected:
        int pin; // Pin associated with the module
        ModuleType type; // Store the module type
        char name[20];    // Module name as a char array (adjust size as needed)
    public:
        Module(int pi, ModuleType t, const char* n) : pin(pi), type(t) {
            strncpy(name, n, sizeof(name) - 1); // Safe string copy
            name[sizeof(name) - 1] = '\0'; // Ensure null-termination
        }
    
        virtual void setup() = 0; // Pure virtual function for setup
        virtual ~Module() {} // Virtual destructor for proper cleanup
        ModuleType getType() { return type; } // Getter for the module type
    };
    

#endif // MODULE_H
