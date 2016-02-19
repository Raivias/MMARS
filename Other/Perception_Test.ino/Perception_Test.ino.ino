
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

  bool topValue;
  bool leftValue;
  bool rightValue;
  bool botValue;

  //get distances
  if(1){//(DIG_OR_ANA){
    topValue = digitalRead(DIG_PERCP_PIN_TOP);
    delay(10);
    leftValue = digitalRead(DIG_PERCP_PIN_LEFT);
    delay(10);
    rightValue = digitalRead(DIG_PERCP_PIN_RIGH);
    delay(10);
    botValue = digitalRead(DIG_PERCP_PIN_BOT);
    delay(10);
  }
  else {
    topValue = analogRead(ANA_PERCP_PIN_TOP);
    delay(10);
    leftValue = analogRead(ANA_PERCP_PIN_LEFT);
    delay(10);
    rightValue = analogRead(ANA_PERCP_PIN_RIGH);
    delay(10);
    botValue = analogRead(ANA_PERCP_PIN_BOT);
    delay(10);
  }

  byte sendData = DataToBytes(topValue,leftValue,rightValue,botValue);
  Serial.println(sendData, BIN);
  Wire.write(sendData);

  return;
}

byte DataToBytes(bool top, bool left, bool right, bool bot){
  byte topMask = 0b1000;
  byte leftMask = 0b0100;
  byte rightMask = 0b0010;
  byte botMask = 0b0001;

  byte retByte;
  
  retByte = top << 3;
  retByte = retByte | (left << 2);
  retByte = retByte | (right << 1);
  retByte = retByte | bot;
  
  return retByte;
}
