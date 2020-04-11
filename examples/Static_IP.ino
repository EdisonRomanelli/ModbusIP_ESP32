/*
  Modbus-Arduino Example - Test Holding Register (Modbus IP ESP32)
  Configure Holding Register (offset 100) with initial value 0xABCD
  You can get or set this holding register
  Copyright by André Sarmento Barbosa
  http://github.com/andresarmento/modbus-arduino
*/


#include <Modbus.h>
#include <ModbusIP_ESP32.h>

// Modbus Registers Offsets (0-9999)
const int TEST_HREG = 0;

byte ip[]      = { 192, 168, 0, 120}; //Set IP
byte gateway[] = { 192, 168, 0, 1 };
byte subnet[]  = { 255, 255, 255, 0 };

//ModbusIP object
ModbusIP mb;

void setup() {
  Serial.begin(115200);

  //mb.config("SSID", "PASSWORD");
  mb.config("SSID", "PASSWORD", ip, gateway, subnet);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  mb.addHreg(TEST_HREG, 0);

}

void loop() {
   //Call once inside loop() - all magic here
   mb.task();
  mb.Hreg(TEST_HREG, random(1,100)); //Write random numbers (1~~100)
}
