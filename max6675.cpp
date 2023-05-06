// this library is public domain. enjoy!
// https://learn.adafruit.com/thermocouple/

#include "max6675.h"

/**************************************************************************/
/*!
    @brief  Initialize a MAX6675 sensor
    @param   SCLK The Arduino pin connected to Clock
    @param   CS The Arduino pin connected to Chip Select
    @param   MISO The Arduino pin connected to Data Out
*/
/**************************************************************************/
MAX6675::MAX6675(int8_t _sclk, int8_t _cs, int8_t _miso)
  : spi_dev(_cs, _sclk, _miso, -1, 1000000) {
}

/**************************************************************************/
/*!
    @brief  Initialize a MAX6675 sensor using hardware SPI.

    @param _cs The pin to use for SPI Chip Select.
    @param _spi which spi buss to use.
*/
/**************************************************************************/
MAX6675::MAX6675(int8_t _cs, SPIClass* _spi)
  : spi_dev(_cs, 1000000, SPI_BITORDER_MSBFIRST, SPI_MODE0, _spi) {
}

/**************************************************************************/
/*!
    @brief  Setup the HW

    @return True if the device was successfully initialized, otherwise false.
*/
/**************************************************************************/
bool MAX6675::begin(void) {
  return initialized = spi_dev.begin();
}

/**************************************************************************/
/*!
    @brief  Read the Celsius temperature
    @returns Temperature in C or NAN on failure!
*/
/**************************************************************************/
float MAX6675::readCelsius(void) {

  uint16_t v = spiread16();

  if (v & 0x4) {
    // uh oh, no thermocouple attached!
    return NAN;
    // return -100;
  }

  v >>= 3;

  return v * .25f;
}

/**************************************************************************/
/*!
    @brief  Read the Fahenheit temperature
    @returns Temperature in F or NAN on failure!
*/
/**************************************************************************/
float MAX6675::readFahrenheit(void) { return readCelsius() * 9.f / 5.f + 32.f; }

uint16_t MAX6675::spiread16(void) {
  uint16_t d = 0;
  uint8_t buf[2];

  // backcompatibility!
  if (!initialized) {
    begin();
  }

  spi_dev.read(buf, 2);

  d = buf[0];
  d <<= 8;
  d |= buf[1];

  return d;
}
