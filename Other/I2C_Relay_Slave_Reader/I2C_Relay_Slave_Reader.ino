/**
 * Xavier Guay
 * This code will take I@C data from the bus and relay it back
 * to the computer
 */

#include <Wire.h>

/*I2C Addresses*/
const int PERCEP_ADDRESS = 5;
const int RELAY_ADD = 10;

/*Other constants*/
const int BAUD_RATE = 9600;
const int LED_PIN = 13;

void setup() {
  Wire.begin(RELAY_ADD);
  Wire.onReceive(receiveEvent);
  Serial.begin(BAUD_RATE);

  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}

void receiveEvent(int howMany){
  while (1< Wire.available()){
    char c = Wire.read();
    Serial.print(c);
  }
  char c = Wire.read();
  Serial.println(c);
}

