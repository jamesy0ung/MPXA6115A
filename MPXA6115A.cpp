#include "MPXA6115A.h"

MPXA6115A::MPXA6115A(int analogPin, float supplyVoltage)
  : _analogPin(analogPin), _supplyVoltage(supplyVoltage) {}

float MPXA6115A::readPressure() {
  int adcValue = analogRead(_analogPin);
  float voltage = (adcValue / 1023.0) * _supplyVoltage;
  float pressure = ((voltage / (_supplyVoltage * 0.009) + 0.095) / 0.009) / 100.0;
  return pressure;
}

float MPXA6115A::readPressureWithErrorComp(float temperature) {
  float pressure = readPressure();
  float tef = _tempErrorFactor(temperature);
  float error = (1.5 * tef * 0.009 * _supplyVoltage) / 100.0;
  return pressure + error;
}

float MPXA6115A::_tempErrorFactor(float temperature) {
  if (temperature < -40) {
    return 3.0;
  } else if (temperature < 0) {
    return 3.0 - (temperature + 40) * (2.0 / 40);
  } else if (temperature <= 85) {
    return 1.0;
  } else if (temperature <= 125) {
    return 1.0 + (temperature - 85) * (0.75 / 40);
  } else {
    return 1.75;
  }
}