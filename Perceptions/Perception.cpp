#include "Perception.h"

Perception::Perception()
{
    //ctor
}

void Perception::perceptionSlaveSetup()
{
    Wire.begin(WIRE_BAUD);
    Wire.onReceive(perceptionSlaveReceiveEvent);
    delay(100);
}

void Perception::perceptionSlaveLoop()
{
    while(1)
    {
        delay(100);
    }
}

void Perception::perceptionSlaveReceiveEvent()
{
    //Get data and send back all back
    pinMode(PIN_FRONT, INPUT);
	pinMode(PIN_BACK, INPUT);
	pinMode(PIN_LEFT, INPUT);
	pinMode(PIN_RIGHT, INPUT);

	//Get inputs
    percepValues currentPercep = getDistances();

    while(!Wire.available){
        delay(10);
    }
    Wire.write()

}

percepValues Perception::getDistances()
{
    percepValues currentValues;
	currentValues.iRFront = analogRead(PIN_FRONT);
	delay(10);
	currentValues.iRBack  = analogRead(PIN_BACK);
	delay(10);
	currentValues.iRLeft  = analogRead(PIN_LEFT);
	delay(10);
	currentValues.iRRight = analogRead(PIN_RIGHT);
	delay(10);

	return percepValues;
}
