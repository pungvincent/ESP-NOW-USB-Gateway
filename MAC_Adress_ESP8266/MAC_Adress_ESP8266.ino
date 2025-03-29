#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("ESP Board MAC Adress: ");
  //Wifi.mode(WIFI_MODE_STA);
  Serial.println(WiFi.macAddress());
}

void loop() {
  // put your main code here, to run repeatedly:

}
