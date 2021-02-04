#include <Servo.h>
int xPin = A0;
int yPin = A1;
int sPin = 2;
int servoPin = 9;
int buzzPin = 7;
int xVal;
int yVal;
int sVal;
// Write Value
int wV;
// Delay Time
int dT = 200;
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(sPin, INPUT);
  pinMode(servoPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
  myServo.attach(servoPin);
  digitalWrite(sPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  xVal = analogRead(xPin);
  // Calculating angle of Servo based on joystick position
  wV = 180./1023. * xVal;
  yVal = analogRead(yPin);
  sVal = digitalRead(sPin);
  delay(dT);

  myServo.write(wV);

  // Sound buzzer when joystick switch is pressed
  if (sVal == 0) {
    digitalWrite(buzzPin, HIGH);
  } else {
    digitalWrite(buzzPin, LOW);
  }

  Serial.print("x: ");
  Serial.print(xVal);
  Serial.print("; y: ");
  Serial.print(yVal);
  Serial.print("; s: ");
  Serial.println(sVal);
}
