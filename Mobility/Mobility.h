#ifndef MOBILITY_H
#define MOBILITY_H
/**---------------- Mobility.h ----------------
by: Xavier Guay
    MMARS Library

PURPOSE
This library contains functions for programming, running, and interfacing
with the mobility module

TODO
    -Insert function to transfer raw I2C msg to MobilityMsg
    -Make sure mobilitySetup will work
    -figure out datatype for mobData()
*/


#include "Wire.h"

#ifndef WIREBAUD
#define WIREBAUD
const int WIRE_BAUD = 9600;
#endif // WIREBAUD


//CONSTANTS
const int MOBILITY_ADDRESS = 4;//I@C address

const int MOTOR1_ENABLE = 5;//Pin to enable motor 1
const int MOTOR2_ENABLE = 6;//Pin to enable motor 1

const int MOTOR1_SIDE1 = 7;//Runs one side of h-bridge
const int MOTOR1_SIDE2 = 8;//Runs one side of h-bridge
const int MOTOR2_SIDE1 = 9;//Runs one side of h-bridge
const int MOTOR2_SIDE2 = 10;//Runs one side of h-bridge

class Mobility
{
    protected:
        struct MobilityMsg
        {
            const int MOB_MSG_BYTES = sizeof(int) * 4; //bytes to send over wire
            int speedR;
            int speedL;
            int timeLength;
            int timePrecision;
            MobilityMsg(){}
            MobilityMsg(rSpeed, lSpeed, timeL, timeP)
                :speedR(rSpeed), speedL(lSpeed), timeLength(timeL), timePrecision(timep) {}
        };

    public:
        Mobility();
        void mobilitySetup();
        // dattyoe mobData();
    protected:
        Wire coms;
        void moveWheels(MobilityMsg inMsg);
    private:

};

#endif // MOBILITY_H
