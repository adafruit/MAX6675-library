// this library is public domain. enjoy!
// based on www.ladyada.net/learn/sensors/thermocouple
// modified for the particle.io libary by Mike Seiler, MSEE
#define NAN 999999
#include <stdlib.h>
#include "max6675.h"

//MAX6675::MAX6675(int8_t SCLK, int8_t CS, int8_t MISO) {
MAX6675::MAX6675(int8_t SCLK, int8_t CS) {
  // photon pins - A5 (MOSI) A4 (MISO) A3 (SCK)
  sclk = SCLK;
  cs = CS;
  miso = A4; //miso = MISO;

  //define pin modes
  pinMode(cs, OUTPUT);
  pinMode(sclk, OUTPUT); 
  pinMode(miso, INPUT);

  digitalWrite(cs, HIGH);
}
double MAX6675::readCelsius(void) {

  uint16_t v;

  digitalWrite(cs, LOW);
  delay(1);

  v = spiread();
  v <<= 8;
  v |= spiread();

  digitalWrite(cs, HIGH);

  if (v & 0x4) {
    // uh oh, no thermocouple attached!
    return NAN; 
  }

  v >>= 3;

  return v*0.25;
}

double MAX6675::readFahrenheit(void) {
  return readCelsius() * 9.0/5.0 + 32;
}

byte MAX6675::spiread(void) { 
  int i;
  byte d = 0;

  for (i=7; i>=0; i--)
  {
    digitalWrite(sclk, LOW);
    delay(1);
    if (digitalRead(miso)) {
      //set the bit to 0 no matter what
      d |= (1 << i);
    }

    digitalWrite(sclk, HIGH);
    delay(1);
  }

  return d;
}