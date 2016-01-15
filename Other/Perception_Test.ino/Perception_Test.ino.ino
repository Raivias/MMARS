/**
 * This code is designed to test that a perception module is
 * functional.
 */

#include <Wire.h>

const int DIG_OR_ANA = 1; //digital(1) or analog(0) read

const int WIRE_BAUD = 9600;
const int PERCEP_ADDRESS = 5;

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

  int topValue;
  int leftValue;
  int rightValue;
  int botValue;

  //get distances
  if(DIG_OR_ANA){
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

  //sizeof(int) * 4
  //Top Left Right Bottom
  Wire.write(topValue);
  Wire.write(leftValue);
  Wire.write(rightValue);
  Wire.write(botValue);
}

