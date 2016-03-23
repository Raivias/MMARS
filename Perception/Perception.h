#ifndef PERCEPTION_H
#define PERCEPTION_H
/**---------------- Perception.h ----------------
by: Xavier Guay
    MMARS Library

PURPOSE
This file provides the interface for Perception.cpp and will be used to
communicate between the different modules of the robot.
*/
#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

const int DEFAULT_PERCEP_ADDRESS    = 5;
const int PERCEP_SIZE   = sizeof(char)*4;


class Perception
    {
    public:
        void begin();
        void begin(int address);
        int i2cAdd;
        bool getFront(){return sendMsg(0);}
        bool getLeft() {return sendMsg(1);}
        bool getRight(){return sendMsg(2);}
        bool getBack() {return sendMsg(3);}
    private:
        bool sendMsg(int index);
    };
/**/
#endif 
// PERCEPTION_H
