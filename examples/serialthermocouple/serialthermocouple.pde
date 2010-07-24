// this example is public domain. enjoy!
// www.ladyada.net/learn/sensors/thermocouple

#include "max6675.h"

MAX6675 thermocouple(14, 15, 16);
int vccPin = 17;
int gndPin = 18;
  
void setup() {
  Serial.begin(9600);
  pinMode(vccPin, OUTPUT); digitalWrite(vccPin, HIGH);
  pinMode(gndPin, OUTPUT); digitalWrite(gndPin, LOW);
  
  // toss out first reading
  thermocouple.readCelsius();
}

void loop() {
   Serial.print("C = "); 
   Serial.println(thermocouple.readCelsius());
   Serial.print("F = ");
   Serial.println(thermocouple.readFarenheit());
 
   delay(1000);
}
