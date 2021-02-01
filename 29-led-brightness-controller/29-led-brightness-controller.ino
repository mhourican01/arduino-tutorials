int buttonPin1 = 12;
int buttonPin2 = 11;
int buttonVal1;
int buttonVal2;
int ledPin = 3;
int ledBright = 250;
int buzzPin = 2;
int dT = 250;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonVal1 = digitalRead(buttonPin1);
  buttonVal2 = digitalRead(buttonPin2);

  // Printing status of buttons
  // i.e. whether button is pressed
  Serial.print("Button 1: ");
  Serial.print(buttonVal1);
  Serial.print("; ");
  Serial.print("Button 2: ");
  Serial.println(buttonVal2);

  // Increments or decrements LED brightness
  // according to which button is pressed
  if (buttonVal1 == 0) {
    ledBright += 5;
  } else if (buttonVal2 == 0) {
    ledBright -= 5;
  }

  // Ensures that LED never exceeds max or min brightness
  // Buzzer warns user in the event
  if (ledBright > 255) {
    ledBright = 255;
    digitalWrite(buzzPin, HIGH);
    delay(dT);
    digitalWrite(buzzPin, LOW);
  } else if (ledBright < 0) {
    ledBright = 0;
    digitalWrite(buzzPin, HIGH);
    delay(dT);
    digitalWrite(buzzPin, LOW);
  }
  analogWrite(ledPin, ledBright);
}
