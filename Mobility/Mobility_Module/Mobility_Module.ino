/**
 * Mobility Module
 * by Xavier Guay
 */

#include <Wire.h>

const int WIRE_BAUD = 9600;
const int MOBILITY_ADDRESS = 4;

//Pins
const int LED = 13; //LED

const int MOTOR1_ENABLE = 12;//Pin to enable motor 1
const int MOTOR2_ENABLE = 13;//Pin to enable motor 1

const int MOTOR1_SIDE1 = 3;//Runs one side of h-bridge
const int MOTOR1_SIDE2 = 9;//Runs one side of h-bridge
const int MOTOR2_SIDE1 = 10;//Runs one side of h-bridge
const int MOTOR2_SIDE2 = 11;//Runs one side of h-bridge
 

void setup() {
  //Initialize serial output
  Serial.begin(WIRE_BAUD);

  //setup pin types
  pinMode(LED, OUTPUT);

  pinMode(MOTOR1_ENABLE, OUTPUT);
  pinMode(MOTOR2_ENABLE, OUTPUT);

  pinMode(MOTOR1_SIDE1, OUTPUT);
  pinMode(MOTOR1_SIDE2, OUTPUT);

  pinMode(MOTOR2_SIDE1, OUTPUT);
  pinMode(MOTOR2_SIDE2, OUTPUT);
  
  
  //Setup I2C
  Wire.begin(MOBILITY_ADDRESS);
  Wire.onReceive(mobiltyI2CEvent);


  Serial.write("Finished set-up");
}

void loop() {
  //blink LED
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);
}

void mobiltyI2CEvent(int howMany){
  int leftPower = Wire.read();
  int rightPower = Wire.read();
  int msec = Wire.read();

  Serial.print("LPower:\t"); Serial.println(leftPower);
  Serial.print("RPower:\t"); Serial.println(rightPower);
  Serial.print("msec:\t"); Serial.println(msec);
  Serial.println();
  /**/  
  //move(leftPower,rightpower,msec);
}


