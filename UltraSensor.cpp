#include "UltraSensor.h"

// Constructor
UltraSensor::UltraSensor(byte trigPin, byte echoPin) {
  this->trigPin = trigPin;
  this->echoPin = echoPin;
}

// Member Functions

void UltraSensor::begin(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

byte UltraSensor::distanceReturn(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  byte dist = ((duration/2)/29.1);
  if (dist > MAX_DISTANCE){
    return MAX_DISTANCE;
  } else {
    return dist;
  }
}



