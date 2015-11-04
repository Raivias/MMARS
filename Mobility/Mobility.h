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
*/


#import "I2C.h"

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
    private:
        struct MobilityMsg
        {
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

    protected:
    private:
        I2C coms;
        void moveWheels(MobilityMsg inMsg);
};

#endif // MOBILITY_H
