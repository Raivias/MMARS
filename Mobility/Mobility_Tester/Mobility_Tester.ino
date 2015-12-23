
#include <Wire.h>

const int WIRE_BAUD = 9600;
const int MOBILITY_ADDRESS = 4;

//Pins
//const int LED1 = 1; //run LED
const int LED2 = 2;
const int LED3 = 4;

const int MOTOR1_ENABLE = 12;//Pin to enable motor 1
const int MOTOR2_ENABLE = 13;//Pin to enable motor 2

const int MOTOR1_SIDE1 = 3;//Runs one side of h-bridge
const int MOTOR1_SIDE2 = 9;//Runs one side of h-bridge
const int MOTOR2_SIDE1 = 10;//Runs one side of h-bridge
const int MOTOR2_SIDE2 = 11;//Runs one side of h-bridge
 

void setup() {
  //Initialize serial output
  //Serial.begin(WIRE_BAUD);

  //setup pin types
  //pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  pinMode(MOTOR1_ENABLE, OUTPUT);
  pinMode(MOTOR2_ENABLE, OUTPUT);

  pinMode(MOTOR1_SIDE1, OUTPUT);
  pinMode(MOTOR1_SIDE2, OUTPUT);

  pinMode(MOTOR2_SIDE1, OUTPUT);
  pinMode(MOTOR2_SIDE2, OUTPUT);
  
  
  //Setup I2C
  //Wire.begin(MOBILITY_ADDRESS);
  //Wire.onReceive(mobiltyI2CEvent);


  //Serial.write("Finished set-up");
}

void loop() {
  //blink LED
  digitalWrite(LED2, HIGH);
  engageMotor(MOTOR1_ENABLE, MOTOR1_SIDE1, MOTOR1_SIDE2);
  engageMotor(MOTOR1_ENABLE, MOTOR1_SIDE2, MOTOR1_SIDE1);
  digitalWrite(LED2, LOW);
  delay(10000);
  
  
  digitalWrite(LED3, HIGH);
  engageMotor(MOTOR2_ENABLE, MOTOR2_SIDE1, MOTOR2_SIDE2);
  engageMotor(MOTOR2_ENABLE, MOTOR2_SIDE2, MOTOR2_SIDE1);
  digitalWrite(LED3, LOW);
  delay(10000);

  
}

void mobiltyI2CEvent(int howMany){
  char buff[howMany];
  //put read data into buff
  for(int count = 0; count < howMany; count++){
    buff[count] = Wire.read();
    //Serial.print(buff[count]);
  }
  //Serial.print("\n");
  
  //do response
}

void engageMotor(int pin, int high, int low){
  //turn off motor
  digitalWrite(pin,LOW);
  //set pin high

  analogWrite(high, 190);
  //set pin low

  digitalWrite(low, LOW);
  //turn on motor
  digitalWrite(pin,HIGH);
  delay(1000);
  digitalWrite(pin,LOW);
}



