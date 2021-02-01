int ledState = 0;
int ledPin = 8;
int buttonPin = 12;
int buttonNew;
int buttonOld = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonNew = digitalRead(buttonPin);
  Serial.println(buttonNew);
  
  if (buttonOld == 0 and buttonNew == 1) {
    if (ledState == 0) {
      digitalWrite(ledPin, HIGH);
      ledState = 1;
    } else {
      digitalWrite(ledPin, LOW);
      ledState = 0;
    }
  }

  buttonOld = buttonNew;
}
