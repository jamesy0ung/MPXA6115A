#include <MPXA6115A.h>

const int analogPin = A0; 
MPXA6115A pressureSensor(analogPin); 

void setup() {
  Serial.begin(9600);
}

void loop() {
  float compensatedPressure = pressureSensor.readPressureWithErrorComp(25.0); 
  Serial.print("Compensated Pressure: ");
  Serial.print(compensatedPressure);
  Serial.println(" kPa");
  delay(2000);
}