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
  
  
  Wire.requestFrom(reqFrom, 1);

  byte in;
  while(Wire.available()){
    in = Wire.read();
    Serial.print(in, BIN);
  }/**/

  int data[4];
  ByteToData(data, in);

  Serial.print(" ");
  Serial.print(data[0]);
  Serial.print(data[1]);
  Serial.print(data[2]);
  Serial.print(data[3]);
  /*
  for(int counter = 0; counter < 4; counter++){
    Serial.print(" ");
    Serial.print(data[counter]);
  }/**/
  

  Serial.print("\n");
  digitalWrite(LED_PIN, LOW);
  
  
}

void ByteToData(int data[4], byte bData){
  byte topMask = 0b1000;
  byte leftMask = 0b0100;
  byte rightMask = 0b0010;
  byte botMask = 0b0001;

  data[0] = (bData & topMask  ) >> 3;
  data[1] = (bData & leftMask ) >> 2;
  data[2] = (bData & rightMask) >> 1;
  data[3] = bData & botMask;

  return;
}

