/**
   Mobility Module
   by Xavier Guay
*/

#include <Wire.h>

const int WIRE_BAUD = 9600;
const int MOBILITY_ADDRESS = 4;

//Pins
//const int LED = 13; //LED
const int LED = 4;
const int LED3 = 2;

const int MOTOR1_ENABLE = 12;//Pin to enable motor 1
const int MOTOR2_ENABLE = 13;//Pin to enable motor 1

const int MOTOR1_SIDE1 = 3;//Runs one side of h-bridge
const int MOTOR1_SIDE2 = 9;//Runs one side of h-bridge
const int MOTOR2_SIDE1 = 11;//Runs one side of h-bridge
const int MOTOR2_SIDE2 = 10;//Runs one side of h-bridge


bool newMsg = false;
bool lPos;
int leftPower;
bool rPos;
int rightPower;
int msec;

void setup() {
  //Initialize serial output
  Serial.begin(WIRE_BAUD);

  //setup pin types
  pinMode(LED, OUTPUT);
  pinMode(LED3, OUTPUT);

  pinMode(MOTOR1_ENABLE, OUTPUT);
  pinMode(MOTOR2_ENABLE, OUTPUT);

  pinMode(MOTOR1_SIDE1, OUTPUT);
  pinMode(MOTOR1_SIDE2, OUTPUT);

  pinMode(MOTOR2_SIDE1, OUTPUT);
  pinMode(MOTOR2_SIDE2, OUTPUT);


  //Setup I2C
  Wire.begin(MOBILITY_ADDRESS);
  Wire.onReceive(mobiltyI2CEvent);


  Serial.println("Finished set-up");
}

void loop() {
  //blink LED
  delay(100);
  if(newMsg){
    digitalWrite(LED, HIGH);
    move(leftPower,rightPower,msec);
    digitalWrite(LED,LOW);
    newMsg = false;
  }
}

void mobiltyI2CEvent(int howMany) {

    digitalWrite(LED3, HIGH);

    lPos = Wire.read();
    leftPower = Wire.read();
    rPos = Wire.read();
    rightPower = Wire.read();
    msec = Wire.read()*10;

    while(Wire.available()){
      Wire.read();
    }
    newMsg=true;
  /*
    Serial.print("lPos:\t"); Serial.println(lPos);
    Serial.print("LPower:\t"); Serial.println(leftPower,DEC);
    Serial.print("rPos:\t"); Serial.println(rPos);
    Serial.print("RPower:\t"); Serial.println(rightPower,DEC);
    Serial.print("msec:\t"); Serial.println(msec);
    Serial.println();
    /**/
  //delay(100);
  
  //move(leftPower,rightPower,msec);
  digitalWrite(LED3, LOW);
}


//move robot
int move(int lPower, int rPower, int msec) {
  if (lPower < -255 || lPower > 255) {
    return -1;
  }
  if (rPower < -255 || rPower > 255) {
    return -2;
  }
  if (msec <= 0) {
    return -3;
  }

  //engage motors depending on power level
  if (lPos) {
    engageMotor(abs(lPower), MOTOR1_ENABLE, MOTOR1_SIDE1, MOTOR1_SIDE2);
  } else {
    engageMotor(abs(lPower), MOTOR1_ENABLE, MOTOR1_SIDE2, MOTOR1_SIDE1);
  }

  if (rPos) {
    engageMotor(abs(rPower), MOTOR2_ENABLE, MOTOR2_SIDE1, MOTOR2_SIDE2);
  } else {
    engageMotor(abs(rPower), MOTOR2_ENABLE, MOTOR2_SIDE2, MOTOR2_SIDE1);
  }

  //wait for mseconds
  delay(msec);
  //turn off motors
  disengageMotor(MOTOR1_ENABLE);
  disengageMotor(MOTOR2_ENABLE);

}

//Setup motor for moving
void engageMotor(int power, int pin, int high, int low) {
  //turn off motor
  digitalWrite(pin, LOW);
  //set pin high

  analogWrite(high, power);
  //set pin low

  digitalWrite(low, LOW);
  //turn on motor
  digitalWrite(pin, HIGH);
}

void disengageMotor(int pin) {
  //turn off motor
  digitalWrite(pin, LOW);
}


