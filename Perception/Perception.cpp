#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
#include "Perception.h"
#include "Wire.h"


void Perception::begin(){
    Wire.begin();
    this->i2cAdd = DEFAULT_PERCEP_ADDRESS;
}

void Perception::begin(int address){
    Wire.begin();
    this->i2cAdd = address;
}

bool Perception::sendMsg(int index)
{
    bool buf[PERCEP_SIZE/sizeof(char)];
    Wire.requestFrom(this->i2cAdd, PERCEP_SIZE);

    for(int i = 0; i < PERCEP_SIZE/sizeof(char); i++){
        buf[i] = Wire.read() -1;
    }

    return buf[index]>0?true:false;
}
/**/