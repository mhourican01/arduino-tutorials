int trigPin = 12;
int echoPin = 11;
int travelT;
int delayT1 = 10;
int delayT2 = 25;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(delayT1);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(delayT1);
  digitalWrite(trigPin, LOW);
  travelT = pulseIn(echoPin, HIGH);
  Serial.println(travelT);
  delayMicroseconds(delayT2);
}
