#ifndef I2C_H
#define I2C_H
/**---------------- I2C.h ----------------
by: Xavier Guay
    MMARS Library

PURPOSE
This file provides the interface for I2C.cpp and will be used to communicate
between the different modules of the robot.

TODO
    -Make sure msg templates work and are formatted correctly
*/

#import "Wire.h"
#import <std>
 //Constants


template<class msgT>
class I2C
{
    public:
        //Constructor
        I2C();
        I2C(int address);
        int sendMsg(int sendAddress, int msg);
        msgT getLastMessage();
        int getNumOfMsgs();

    protected:
    private:
        //message queue
        Queue<msgT> msgQueue;
        void receiveEvent();
};

#endif // I2C_H
