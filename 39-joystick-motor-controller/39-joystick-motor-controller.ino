int speedPin = 5;
int dirPin1 = 4;
int dirPin2 = 3;
int mSpeed = 255;
int jPin = A1;
int jVal;

void setup() {
  Serial.begin(9600);
  pinMode(speedPin, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(jPin, INPUT);
}

void loop() {
  jVal = analogRead(jPin);
  Serial.println(jVal);

  if (jVal < 512) {
    digitalWrite(dirPin1, LOW);
    digitalWrite(dirPin2, HIGH);
    mSpeed = (-255./512.)*jVal+255;
  } else if (jVal >= 512) {
     digitalWrite(dirPin1, HIGH);
    digitalWrite(dirPin2, LOW);
    mSpeed = (255./512.)*jVal-255;
  }
 
  analogWrite(speedPin, mSpeed);
}
