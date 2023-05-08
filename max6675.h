// this library is public domain. enjoy!
// https://learn.adafruit.com/thermocouple/

#ifndef ADAFRUIT_MAX6675_H
#define ADAFRUIT_MAX6675_H

#include "Arduino.h"
#include <Adafruit_SPIDevice.h>

/**************************************************************************/
/*!
    @brief  Class for communicating with thermocouple sensor
*/
/**************************************************************************/
class MAX6675 {
public:
  MAX6675(int8_t _sclk, int8_t _cs, int8_t _miso);
  MAX6675(int8_t _cs, SPIClass *_spi = &SPI);

  bool begin(void);
  float readCelsius(void);
  float readFahrenheit(void);

  /*!    @brief  For compatibility with older versions
         @returns Temperature in F or NAN on failure! */
  float readFarenheit(void) { return readFahrenheit(); }

private:
  Adafruit_SPIDevice spi_dev;
  bool initialized = false;
  uint16_t spiread16(void);
};

#endif
