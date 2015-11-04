/**---------------- Mobility.cpp ----------------
by: Xavier Guay
    MMARS Library

PURPOSE
This library contains functions for programming, running, and interfacing
with the mobility module

*/
#include "Mobility.h"

Mobility::Mobility()
{
    //ctor
}

void Mobility::mobilitySetup()
{
    //Set pins as outputs
    pinMode(MOTOR1_ENABLE, OUTPUT);
    pinMode(MOTOR2_ENABLE, OUTPUT);

    pinMode(MOTOR1_SIDE1, OUTPUT);
    pinMode(MOTOR1_SIDE2, OUTPUT);
    pinMode(MOTOR2_SIDE1, OUTPUT);
    pinMode(MOTOR2_SIDE2, OUTPUT);

    //Turn on I2C communication
    coms = new I2C<MobilityMsg>(MOBILITY_ADDRESS);
}

void Mobility::moveWheels(MobilityMsg inMsg)
{
    //Use data in msg to run the wheels
    //Disable wheels
    digitalWrite(MOTOR1_ENABLE, LOW);
    digitalWrite(MOTOR2_ENABLE, LOW);
    delay(10);

    //Set power on wheels
    if (inMsg.speedL < 0)
    {
        //Set side one as TODO
        digitalWrite(MOTOR1_SIDE1, );
        digitalWrite(MOTOR1_SIDE2, LOW);
    }
    else
    {
        //TODO
        digitalWrite(MOTOR1_SIDE1, LOW);
        digitalWrite(MOTOR1_SIDE2, );
    }

    if (inMsg.speedR < 0)
    {
        //Set side one as TODO
        digitalWrite(MOTOR2_SIDE1, );
        digitalWrite(MOTOR2_SIDE2, LOW);
    }
    else
    {
        //TODO
        digitalWrite(MOTOR2_SIDE1, LOW);
        digitalWrite(MOTOR2_SIDE2, );
    }

    //turn on and delay for time
    digitalWrite(MOTOR1_ENABLE, HIGH);
    digitalWrite(MOTOR2_ENABLE, HIGH);
    delay(inMsg.timeLength * (10^inMsg.timePrecision));

    //stop wheels
    digitalWrite(MOTOR1_ENABLE, LOW);
    digitalWrite(MOTOR2_ENABLE, LOW);
}

