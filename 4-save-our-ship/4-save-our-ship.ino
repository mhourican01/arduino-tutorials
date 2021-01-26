int redLED = 4;
int shortBlink = 50;
int longBlink = 150;
int wait = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(redLED, HIGH);
  delay(shortBlink);
  digitalWrite(redLED, LOW);
  delay(shortBlink);

  digitalWrite(redLED, HIGH);
  delay(shortBlink);
  digitalWrite(redLED, LOW);
  delay(shortBlink);

  digitalWrite(redLED, HIGH);
  delay(shortBlink);
  digitalWrite(redLED, LOW);
  delay(shortBlink);

  digitalWrite(redLED, HIGH);
  delay(longBlink);
  digitalWrite(redLED, LOW);
  delay(longBlink);

  digitalWrite(redLED, HIGH);
  delay(longBlink);
  digitalWrite(redLED, LOW);
  delay(longBlink);

  digitalWrite(redLED, HIGH);
  delay(longBlink);
  digitalWrite(redLED, LOW);
  delay(longBlink);

  digitalWrite(redLED, HIGH);
  delay(shortBlink);
  digitalWrite(redLED, LOW);
  delay(shortBlink);

  digitalWrite(redLED, HIGH);
  delay(shortBlink);
  digitalWrite(redLED, LOW);
  delay(shortBlink);

  digitalWrite(redLED, HIGH);
  delay(shortBlink);
  digitalWrite(redLED, LOW);
  delay(shortBlink);  

  delay(wait);
}
