#include "esp32-hal.h"
#include "esp32-hal-gpio.h"
#include "Robot.h"

// Concstructor

Robot::Robot (byte tp1, byte ep1, byte tp2, byte ep2, int irp1, long irmod1, int irp2, long irmod2,
    int irp3, long irmod3, int irp4, long irmod4, int irp5, long irmod5, int irp6, long irmod6, 
    byte linep1, byte linep2, byte linep3, byte linep4, MODE mot1, uint8_t pwm1, uint8_t dir1, MODE mot2, uint8_t pwm2, uint8_t dir2) :
      leftUS(tp1, ep1),
      rightUS(tp2, ep2),
      sharpIR_one(irp1, irmod1),
      sharpIR_two(irp2, irmod2),
      sharpIR_three(irp3, irmod3),
      sharpIR_four(irp4, irmod4),
      sharpIR_five(irp5, irmod5),
      sharpIR_six(irp6, irmod6),
      LineSens_TL(linep1),
      LineSens_TR(linep2),
      /*LineSens_BL(linep3)*/,
      LineSens_BR(linep4),
      leftMotor(mot1, pwm1, dir1),
      rightMotor(mot2, pwm2, dir2) {
}

// Member Functions : Sensors Distance Measurements

void Robot::fstart(){
  leftUS.begin();
  rightUS.begin();
}

void Robot::stop(){
  leftMotor.setSpeed(0);
  rightMotor.setSpeed(0);
}

void Robot::forward(){
  leftMotor.setSpeed(255);
  rightMotor.setSpeed(255);
}

void Robot::backward(){
  leftMotor.setSpeed(-255);
  rightMotor.setSpeed(-255);
}

void Robot::Rclockwise(){
  leftMotor.setSpeed(255);
  rightMotor.setSpeed(-255);
}

void Robot::RcounterClockwise(){
  leftMotor.setSpeed(-255);
  rightMotor.setSpeed(255);
}

  // UltraSonic Sensors

byte Robot::dist_US1(){
  return leftUS.distanceReturn();
}

byte Robot:: dist_US2(){
  return rightUS.distanceReturn();
}

  // IR Sensors

int Robot::dist_IR1(){
  return sharpIR_one.distance();
}

int Robot::dist_IR2(){
  return sharpIR_two.distance();
}

int Robot::dist_IR3(){
  return sharpIR_three.distance();
}

int Robot::dist_IR4(){
  return sharpIR_four.distance();
}

int Robot::dist_IR5(){
  return sharpIR_five.distance();
}

int Robot::dist_IR6(){
  return sharpIR_six.distance();
}

  // Line Sensors Edge White Line Readings

bool Robot::WFlag_TL(){
  return LineSens_TL.WhiteFlag();
}

bool Robot::WFlag_TR(){
  return LineSens_TR.WhiteFlag();
}

bool Robot::WFlag_BL(){
  return LineSens_BL.WhiteFlag();
}

bool Robot::WFlag_BR(){
  return LineSens_BR.WhiteFlag();
}

void Robot:: WFlag_React(){
  if(WFlag_TL() && WFlag_TR()){
      stop();
      delay(100);
      backward(); // Move backward
      delay(1000);
      stop();
      delay(100);

    } /*else if (WFlag_TL() && WFlag_BL()) {
      stop();
      delay(100);
      Rclockwise(); // Move 90 deg clockwise
      delay(500);
      stop();
      delay(100);
      forward();
      delay(1000);
      stop();
      delay(100);
      
    }*/ else if (WFlag_TR() && WFlag_BR()) {
      stop();
      delay(100);
      RcounterClockwise(); // Move 90 deg counter clockwise
      delay(500);
      stop();
      delay(100);
      forward();
      delay(1000);
      stop();
      delay(100);
      
    } /*else if (WFlag_BR() && WFlag_BL()) {
      stop();
      delay(100);
      forward();
      delay(1000);
      stop();
      delay(100);*/

    } else if (WFlag_TL()) {
      stop();
      delay(100);
      Rclockwise(); // Move 135 deg clockwise
      delay(1000);
      stop();
      delay(100);
      forward();
      delay(1000);
      stop();
      delay(100);
      
    } else if (WFlag_TR()) {
      stop();
      delay(100);
      RcounterClockwise(); // Move 135 deg counter clockwise
      delay(1000);
      stop();
      delay(100);
      forward();
      delay(1000);
      stop();
      delay(100);

    } /*else if (WFlag_BL()) {
      stop();
      delay(100);
      Rclockwise(); // Move 45 deg clockwise
      delay(250);
      stop();
      delay(100);
      forward();
      delay(1000);
      stop();
      delay(100); */

    } else if (WFlag_BR()) {
      stop();
      delay(100);
      RcounterClockwise(); // Move 45 deg counter clockwise
      delay(250);
      stop();
      delay(100);
      forward();
      delay(1000);
      stop();
      delay(100);
    }
}

  // IR Sensors Opponent Flagging

bool Robot::OpponentFront(){
  if (dist_IR1() <= 59 && dist_IR2() <= 59) {
    return true;
  }

  return false;
}

void Robot::SearchOpponent(){
  if(dist_IR3() <= 30 || dist_US1() <= 59) {
    while (!OpponentFront()) {
      RcounterClockwise();
    }
    stop();
    delay(100);
  } else if (dist_IR4() <= 30 || dist_US2() <= 59) {
    while (!OpponentFront()) {
      Rclockwise();
    }
    stop();
    delay(100);
  } else if (dist_IR5() <= 59 || dist_IR6() <= 59) {
    while (!OpponentFront()) {
      Rclockwise();
    }
    stop();
    delay(100);
  }
}










