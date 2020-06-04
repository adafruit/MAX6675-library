// this library is public domain. enjoy!
// https://learn.adafruit.com/thermocouple/

#ifndef ADAFRUIT_MAX6675_H
#define ADAFRUIT_MAX6675_H

#include "Arduino.h"

class MAX6675 {
 public:
  MAX6675(int8_t SCLK, int8_t CS, int8_t MISO);

  float readCelsius(void);
  float readFahrenheit(void);
  // For compatibility with older versions:
  float readFarenheit(void) { return readFahrenheit(); }

 private:
  int8_t sclk, miso, cs;
  uint8_t spiread(void);
};

#endif
