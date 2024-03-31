#include "Arduino.h"
#ifndef UltraSensorH
#define UltraSensorH

const byte MAX_DISTANCE = 150; // For the wall around the arena, probably have to define it in robot class
const byte MIN_DISTANCE = 2;

class UltraSensor {
    public:
        // Constructor 
        UltraSensor(byte trigPin, byte echoPin);

        // Default Constructor
        UltraSensor();

        // Member Functions
        byte distanceReturn();
        void begin();

    private: 
        byte trigPin, echoPin;
};
#endif