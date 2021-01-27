int analogPin = A2;
int redPin = 9;
int readVal;
float v2;
int wait = 750;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(analogPin, INPUT);
  pinMode(redPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(analogPin);
  v2 = (5./1023.) * readVal;
  Serial.println(v2);

  if (v2 >= 4.0) {
    digitalWrite(redPin, HIGH);
  } else {
    digitalWrite(redPin, LOW);
  } 
}
