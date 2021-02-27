int speedPin = 5;
int dirPin1 = 4;
int dirPin2 = 3;
int mSpeed = 255;
int tiltPin = 2;
int tiltVal;

void setup() {
  pinMode(speedPin, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(tiltPin, INPUT);
  digitalWrite(tiltPin, HIGH);
}

void loop() {
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, HIGH);
  analogWrite(speedPin, mSpeed);
  tiltVal = digitalRead(tiltPin);
  if (tiltVal == 0) {
    analogWrite(speedPin, mSpeed);
  } else if (tiltVal == 1) {
    analogWrite(speedPin, 0);
  }
}
