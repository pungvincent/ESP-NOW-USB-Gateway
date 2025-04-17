#include "DimmableLight.h"

void DimmableLight::setup() {
    pinMode(pin, OUTPUT); // Set the pin as an output
}

void DimmableLight::Received_data(const char* Rx_name, const char* Rx_cmd, int Rx_luminosity) {
        if (strcmp(Rx_name, this->name) == 0) {
            if (strcmp(Rx_cmd, "ON") == 0) {
                this->luminosity = 1023;  
            } else if (strcmp(Rx_cmd, "OFF") == 0) {
                this->luminosity = 0;
            } else if (strcmp(Rx_cmd, "TOGGLE") == 0) {
                this->luminosity = 0;
            } else if (strcmp(Rx_cmd, "CHANGE") == 0) {
                this->luminosity = Rx_luminosity;
            }
            //Send the value
            analogWrite(pin, this->luminosity);
            //Send back acknowledgment -> Example: {"type":"dimmablelight","name":"dimmablelight1","state":"ON"}
            StaticJsonDocument<128> doc;
            doc["type"] = "dimmablelight";                         // Message type
            doc["name"] = name;                        // Switch name
            doc["state"] = (this->luminosity == 0) ? "OFF" : "ON"; // Read pin state
            doc["luminosity"] = this->luminosity;    
            char buffer[128];
            serializeJson(doc, buffer); // Convert JSON to char[]
            sendMessage(buffer);
    }
}
