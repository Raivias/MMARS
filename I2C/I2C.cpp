/**---------------- I2C.cpp ----------------
by: Xavier Guay
    MMARS Library

PURPOSE
This file provides the functions to use the I2C library

*/

#include "I2C.h"

template<class msgT>
I2C::I2C()
{
    Wire.begin();
    Wire.onReceive(receiveEvent);
}

template<class msgT>
I2C::I2C(int address)
{
    Wire.begin(address);
    Wire.onReceive(receiveEvent);
}

template<class msgT>
int I2C<msgT>::sendMsg(int sendAddress, int msg){
    Wire.beginTransmission(sendAddress);
    Wire.write(msg);
    Write.endTransmission();
}

template<class msgT>
void I2C<msgT>::receiveEvent()
{
    //TODO
    //When data is received function must get it
    //Get message from buffer
    String msgBuffer = "";
    while (1 < Wire.available)
    {
        char c = Wire.read();
        msgBuffer += c;
    }
    //put data in template format
    msgT msg;
    msg = msg.convert(msgBuffer);

    //enqueue
    msgQueue.enqueue(msg);
}

template<class msgT>
msgT I2C<msgT>::getLastMessage()
{
    msgT retValue = msgQueue.front();
    msgQueue.pop();
    return retValue;
}

template<class msgT>
int I2C<msgT>::getNumOfMsgs()
{
    return msgQueue.size();
}
