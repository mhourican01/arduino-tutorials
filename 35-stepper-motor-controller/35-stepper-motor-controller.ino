#include <Stepper.h>

int stepsPerRev = 2048;
int motorSpeed = 12;
int buttonPin = 2;
int motorDir = 1;
int buttonValNew;
int buttonValOld = 1;
Stepper myStepper(stepsPerRev, 8,10,9,11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myStepper.setSpeed(motorSpeed);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonValNew = digitalRead(buttonPin);
  if (buttonValOld == 1 && buttonValNew == 0) {
    motorDir = motorDir * (-1);
  }
  myStepper.step(motorDir*1);
  buttonValOld = buttonValNew;
}
