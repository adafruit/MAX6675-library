// this library is public domain. enjoy!
// www.ladyada.net/learn/sensors/thermocouple


#include <WProgram.h>

class MAX6675 {
 public:
  MAX6675(int8_t SCLK, int8_t CS, int8_t MISO);

  double readCelsius(void);
  double readFarenheit(void);
 private:
  int8_t sclk, miso, cs;
  uint8_t spiread(void);
};
