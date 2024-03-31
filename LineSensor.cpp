#include "LineSensor.h"

// Constructor
LineSensor::LineSensor(byte pinNumb) {
  this->pinNumb = pinNumb;
}

// Member Functions

bool LineSensor::WhiteFlag(){
  int readout = lineSensorReadout();
  if (readout < 100){
    return true;
  } else {
    return false;
  }
}

int LineSensor::lineSensorReadout(){
  pinMode(pinNumb, OUTPUT);
  digitalWrite(pinNumb, HIGH);
  delayMicroseconds(10);
  pinMode(pinNumb, INPUT);
  long time = micros();
  while (digitalRead(pinNumb) == HIGH && micros() - time < 3000);
  int diff = micros() - time;
  return diff;
}