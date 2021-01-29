int lightPin = A0;
int buzzPin = 8;
int lightVal;
int delayT;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lightPin, INPUT);
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(lightVal);
  delayT = (9./550.) * lightVal - (9.*200./550.) + 1.;
  Serial.println(lightVal);
  
  digitalWrite(buzzPin, HIGH);
  delay(delayT);
  digitalWrite(buzzPin, LOW);
  delay(delayT);
}
