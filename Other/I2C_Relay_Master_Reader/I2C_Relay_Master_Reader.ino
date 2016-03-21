/**
 * Xavier Guay
 * This code will take I@C data from the bus and relay it back
 * to the computer
 */

#include <Wire.h>

/*I2C Addresses*/
const int PERCEP_ADD = 5;
const int PERCEP_SIZE = 1;
const int RELAY_ADD = 10;

/*Other constants*/
const int BAUD_RATE = 9600;
const int LED_PIN = 13;

int reqFrom = PERCEP_ADD;
int reqSize = PERCEP_SIZE;

void setup() {
  Wire.begin();
  Serial.begin(BAUD_RATE);

  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  
  
  Wire.requestFrom(reqFrom, 4);

  char in;
  while(Wire.available()){
    in = Wire.read()-1;
    Serial.print(in,DEC);
    Serial.print(" ");
  }/**/
  Serial.println();

 // Serial.print("\n");
  digitalWrite(LED_PIN, LOW);
  delay(500);
  
}

