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

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif


const int DEFAULT_MOBILITY_ADD  = 4;

class Mobility
{
public:
    void begin();
    void begin(int address);
    int move(bool lPos, unsigned char leftPower, bool rPos, unsigned char rightPower, unsigned char msec);
private:
    int i2cAdd;

};
/**/
#endif
// MOBILITY_H
