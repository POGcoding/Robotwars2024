#include <SharpIR.h>
#include "Arduino.h"
#include "CytronMotorDriver.h"
#include "UltraSensor.h"
#include "SharpIR.h"
#include "LineSensor.h"

#ifndef RobotH
#define RobotH

class Robot {
  public:
    // Constructor
    Robot (byte tp1, byte ep1, byte tp2, byte ep2, int irp1, long irmod1, int irp2, long irmod2,
    int irp3, long irmod3, int irp4, long irmod4, int irp5, long irmod5, int irp6, long irmod6, 
    byte linep1, byte linep2, byte linep3, byte linep4, MODE mot1, uint8_t pwm1, uint8_t dir1, MODE mot2, uint8_t pwm2, uint8_t dir2);

    // Default Constructor
    Robot ();

    // Member Functions
    void fstart();
    void stop();
    void forward();
    void backward();
    void Rclockwise();
    void RcounterClockwise();

    // UltraSonic Sensors Distance Readings
    byte dist_US1();
    byte dist_US2();

    // IR Sensors Distance Readings 
    int dist_IR1();
    int dist_IR2();
    int dist_IR3();
    int dist_IR4();
    int dist_IR5();
    int dist_IR6();

    // Line Sensors Edge White Line Readings
    bool WFlag_TL();
    bool WFlag_TR();
    bool WFlag_BL();
    bool WFlag_BR();
    void WFlag_React();

    // IR Receiver Start/Stop
    bool RoundStart();
    bool RoundStop();

    // IR Sensors Opponent Flagging
    bool OpponentFront();
    void SearchOpponent();

  private:
    UltraSensor leftUS;
    UltraSensor rightUS;
    SharpIR sharpIR_one;
    SharpIR sharpIR_two;
    SharpIR sharpIR_three;
    SharpIR sharpIR_four;
    SharpIR sharpIR_five;
    SharpIR sharpIR_six;
    LineSensor LineSens_TL;
    LineSensor LineSens_TR;
    LineSensor LineSens_BL;
    LineSensor LineSens_BR;
    CytronMD leftMotor;
    CytronMD rightMotor;
};

#endif