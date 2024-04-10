#include "Robot.h"

Robot RobotFinal(13, 12, 14, 27, 34, 1080, 35, 1080, 32, 430, 33, 430, 25, 430, 26, 430, 19, 21, 22, 23, PWM_DIR, 0, 2, PWM_DIR, 16, 4);

const int irPin = 15;
volatile bool roundState = false;
volatile bool isFirstIteration = false;

// Interrupt handler
void IRAM_ATTR handleInterrupt() {
  if (digitalRead(irPin) == HIGH) {
    roundState = true;
    isFirstIteration = true;
  } else {
    roundState = false;
  }
}

void setup() {
  Serial.begin(115200); 
  RobotFinal.fstart();
  pinMode(irPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(15), handleInterrupt, CHANGE);
}

void loop() {
  if (roundState && isFirstIteration) {
    delay(3000);
    isFirstIteration = false;
  }

  if (roundState){
    RobotFinal.SearchOpponent();
    RobotFinal.forward();
    RobotFinal.WFlag_React();
  } else {
    RobotFinal.stop();
  }
}