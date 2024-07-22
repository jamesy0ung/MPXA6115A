#ifndef MPXA6115A_H
#define MPXA6115A_H

#include <Arduino.h>

class MPXA6115A {
public:
  MPXA6115A(int analogPin, float supplyVoltage = 5.0);
  float readPressure();
  float readPressureWithErrorComp(float temperature);

private:
  int _analogPin;
  float _supplyVoltage;
  float _tempErrorFactor(float temperature);
};

#endif