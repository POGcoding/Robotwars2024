#include "Arduino.h"
#ifndef LineSensorH
#define LineSensorH

class LineSensor {

  public:
    // Constructor
    LineSensor(byte pinNumb);
    // Default Constructor
    LineSensor();
    // Member Functions
    bool WhiteFlag();
    int lineSensorReadout();
  
  private:
    byte pinNumb;
};

#endif