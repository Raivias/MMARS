#ifndef PERCEPTION_H
#define PERCEPTION_H
/**---------------- Perception.h ----------------
by: Xavier Guay
    MMARS Library

PURPOSE
This file provides the interface for Perception.cpp and will be used to
communicate between the different modules of the robot.

TODO
    -Add algorithm to go from ADC to cm
*/
#include "Wire.h"

#ifndef WIREBAUD
#define WIREBAUD
const int WIRE_BAUD = 9600;
#endif // WIREBAUD

const int PERCEP_ADDRESS = 5;

//const int PIN_FRONT = A0; //A0
//const int PIN_BACK  = A1; //A1
//const int PIN_LEFT  = A2; //A2
//const int PIN_RIGHT = A3; //A3

class Perception
{
    protected:
        struct percepValues
        {
            int iRFront;
            int iRBack;
            int iRLeft;
            int iRRight;
        };

    public:
        Perception();
        void perceptionSlaveSetup();
        void perceptionSlaveLoop();

        percepValues getDistances();
    protected:
        void perceptionSlaveReceiveEvent();
    private:

};

#endif // PERCEPTION_H
