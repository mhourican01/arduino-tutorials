int trigPin = 12;
int echoPin = 11;
int travelT;
float travelDist;
float targetDist;
int delayT1 = 10;
int delayT2 = 25;
int delayT3 = 500;

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
  delayMicroseconds(delayT2);

  travelDist = (travelT * 765. * 5280. * 12) / (3600. * 1000000);
  targetDist = travelDist / 2;
  
  Serial.print(targetDist);
  Serial.println(" inches");
  delay(delayT3);
}
