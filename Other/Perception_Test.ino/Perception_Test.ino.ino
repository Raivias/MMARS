
/**
 * This code is designed to test that a perception module is
 * functional.
 */

#include <Wire.h>

const int DIG_OR_ANA = 1; //digital(1) or analog(0) read

const int WIRE_BAUD = 9600;
const int PERCEP_ADDRESS = 5;
const int RELAY_ADDRESS = 10;

//Pins
const int DIG_PERCP_PIN_TOP = 4;
const int DIG_PERCP_PIN_LEFT = 13;
const int DIG_PERCP_PIN_RIGH = 3;
const int DIG_PERCP_PIN_BOT = 2;

const int ANA_PERCP_PIN_TOP = A1;
const int ANA_PERCP_PIN_LEFT = A0;
const int ANA_PERCP_PIN_RIGH = A2;
const int ANA_PERCP_PIN_BOT = A3;

void setup() {
  pinMode(DIG_PERCP_PIN_TOP, INPUT);
  pinMode(DIG_PERCP_PIN_LEFT, INPUT);
  pinMode(DIG_PERCP_PIN_RIGH, INPUT);
  pinMode(DIG_PERCP_PIN_BOT, INPUT);

  pinMode(ANA_PERCP_PIN_TOP, INPUT);
  pinMode(ANA_PERCP_PIN_LEFT, INPUT);
  pinMode(ANA_PERCP_PIN_RIGH, INPUT);
  pinMode(ANA_PERCP_PIN_BOT, INPUT);

 //Set up serial
  Serial.begin(WIRE_BAUD);

 //set up I2C
 Wire.begin(PERCEP_ADDRESS);
 Wire.onRequest(i2CRequestEvent);

}

void loop() {
  delay(100);

}

void i2CRequestEvent(){
  //clear buffer
  //Clear Buffer
  while(Wire.available() > 0){
    Wire.read();
  }
  Serial.println("request event");

  char buf[4];
  sprintf(buf, "0000");
  bool front = digitalRead(DIG_PERCP_PIN_TOP)==HIGH?true:false;
  buf[0] = front+1;
  bool left = digitalRead(DIG_PERCP_PIN_LEFT)==HIGH?false:true;
  buf[1] = left+1;
  bool right = digitalRead(DIG_PERCP_PIN_RIGH)==HIGH?true:false;
  buf[2] = right+1;
  bool back = digitalRead(DIG_PERCP_PIN_BOT)==HIGH?true:false;
  buf[3] = back+1;
  Wire.write(buf);
  
  return;
}

