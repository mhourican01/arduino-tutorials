int latchPin = 11;
int dataPin = 12;
int clockPin = 9;
byte myByte = 0b01010101;
byte myByteFlipped;
int dT = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, myByte);
  digitalWrite(latchPin, HIGH);
  delay(dT);
  
  myByteFlipped = 255 - myByte;
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, myByteFlipped);
  digitalWrite(latchPin, HIGH);
  delay(dT);
}
