#include <Servo.h>
Servo servoFront01;
Servo servoFront02;

Servo servoBack01;
Servo servoBack02;

const int pinLedRed = 12;
const int pinLedGreen = 13;
const int pinButton = 2;

const int releaseTime = 10;

void setup()
{ 
  pinMode(pinLedRed, OUTPUT);
  pinMode(pinLedGreen, OUTPUT);
  pinMode(pinButton, INPUT_PULLUP);

  digitalWrite(pinLedRed, LOW);
  digitalWrite(pinLedGreen, HIGH);
  
  servoFront01.attach(8);
  servoFront02.attach(11);

  servoFront01.write(0);
  servoFront02.write(90);

  servoBack01.attach(3);
  servoBack02.attach(4);
  
  servoBack01.write(90);
  servoBack02.write(0);

  Serial.begin(9600);
}

void loop()
{
  Serial.println(!digitalRead(pinButton));
  if(!digitalRead(pinButton)){
    releaseCan();
  }
}

void releaseCan() {
  digitalWrite(pinLedGreen, LOW);
  digitalWrite(pinLedRed, HIGH);
  servoFront01.write(90);
  servoFront02.write(0);
  delay(1000);
  servoFront01.write(0);
  servoFront02.write(90);
  prepareNextCan();
  digitalWrite(pinLedGreen, HIGH);
  digitalWrite(pinLedRed, LOW);
}

void prepareNextCan() {
  servoBack01.write(0);
  servoBack02.write(90);
  delay(1000);
  servoBack01.write(90);
  servoBack02.write(0);
}
