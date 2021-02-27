int speedPin = 5;
int dirPin1 = 4;
int dirPin2 = 3;
int bPin1 = 9;
int bPin2 = 8;
int bVal1;
int bVal2;
int mSpeed = 0;
int dT = 500;

void setup() {
  Serial.begin(9600);
  pinMode(speedPin, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(bPin1, INPUT);
  pinMode(bPin2, INPUT);
  digitalWrite(bPin1, HIGH);
  digitalWrite(bPin2, HIGH);
}

void loop() {
  bVal1 = digitalRead(bPin1);
  bVal2 = digitalRead(bPin2);

  Serial.print("Motor speed: ");
  Serial.println(mSpeed);

  // Decrement speed when button 1 is pressed
  if (bVal1 == 0) {
    mSpeed -= 10;
    delay(dT);
  }
  // Increment speed when button 2 is pressed
  if (bVal2 == 0) {
    mSpeed += 10;
    delay(dT);
  }
  // Cap max and min speeds
  if (mSpeed > 255) {
    mSpeed = 255;
  } else if (mSpeed < -255) {
    mSpeed = -255;
  }
  // Boost motor to self-starting speed
  if (mSpeed == 10) {
    mSpeed = 170;
  } else if (mSpeed == -10) {
    mSpeed = -170;
  }
  // Stop motor when too slow to run
  if (mSpeed == 160 || mSpeed == 165) {
    mSpeed = 0;
  } else if (mSpeed == -160 || mSpeed == -165) {
    mSpeed = 0;
  }
 
  if (mSpeed == 0) {
    digitalWrite(speedPin, LOW);
  }
  // Change motor direction depending on whether speed is pos. or neg.
  else if (mSpeed > 0) {
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, HIGH);
  } else if (mSpeed < 0) {
    digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, LOW);
  }
  
  analogWrite(speedPin, abs(mSpeed));
}
