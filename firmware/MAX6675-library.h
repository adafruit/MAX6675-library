// this library is public domain. enjoy!
// www.ladyada.net/learn/sensors/thermocouple
// modified for the particle.io libary by Mike Seiler, MSEE

class MAX6675 {
 public:
//  MAX6675(int8_t SCLK, int8_t CS, int8_t MISO);
  MAX6675(int8_t SCLK, int8_t CS);

  double readCelsius(void);
  double readFahrenheit(void);
  // For compatibility with older versions:
  double readFarenheit(void) { return readFahrenheit(); }
 private:
  int8_t sclk, miso, cs;
  uint8_t spiread(void);
};

