/**---------------- Mobility.cpp ----------------
by: Xavier Guay
    MMARS Library

PURPOSE
This library contains functions for programming, running, and interfacing
with the mobility module

*/
#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
#include "Mobility.h"
#include "Wire.h"


void Mobility::begin(){
    Wire.begin();
    this->i2cAdd = DEFAULT_MOBILITY_ADD;
}

void Mobility::begin(int address){
    Wire.begin();
    this->i2cAdd = address;
}

int Mobility::move(bool lPos, unsigned char leftPower,bool rPos, unsigned char rightPower, unsigned char msec){
  if (leftPower < -255 || leftPower > 255){
    return -1;
  }
  if (rightPower < -255 || rightPower > 255){
    return -2;
  }
  if(msec <= 0){
    return -3;
  }
  
  Wire.beginTransmission(this->i2cAdd);
  Wire.write(lPos);
  Wire.write(leftPower);
  Wire.write(rPos);
  Wire.write(rightPower);
  Wire.write(msec);
  Wire.endTransmission();
  return 0;
}
/**/