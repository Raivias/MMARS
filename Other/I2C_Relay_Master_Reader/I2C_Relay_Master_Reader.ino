/**
 * Xavier Guay
 * This code will take I@C data from the bus and relay it back
 * to the computer
 */

#include <Wire.h>

/*I2C Addresses*/
const int PERCEP_ADD = 5;
const int PERCEP_SIZE = sizeof(char)*4;
const int RELAY_ADD = 10;

/*Other constants*/
const int BAUD_RATE = 9600;
const int LED_PIN = 13;

 char front;
 char left;
 char right;
 char back;

void setup() {
  Wire.begin();
  Serial.begin(BAUD_RATE);

  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  
  Wire.requestFrom(PERCEP_ADD, 4);

  front = Wire.read()-1;
  left = Wire.read()-1;
  right = Wire.read()-1;
  back = Wire.read()-1;
  
  Serial.print("front:\t"); Serial.println(front,DEC);
  Serial.print("left:\t"); Serial.println(left,DEC);
  Serial.print("right:\t"); Serial.println(right,DEC);
  Serial.print("back:\t"); Serial.println(back,DEC);
  Serial.println();

 // Serial.print("\n");
  digitalWrite(LED_PIN, LOW);
  delay(500);
  
}

