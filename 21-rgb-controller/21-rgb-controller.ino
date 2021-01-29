int redPin = 8;
int greenPin = 9;
int bluePin = 10;
String myColour;
String msg = "What colour do you want?";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);

  while (Serial.available() == 0) {

  }
  
  myColour = Serial.readString();

  if (myColour == "red") {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  } else if (myColour == "green") {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
  } else if (myColour == "blue") {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
  } else if (myColour == "aqua") {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 80);
  } else if (myColour == "yellow") {
    analogWrite(redPin, 255);
    analogWrite(greenPin, 100);
    analogWrite(bluePin, 0);
  } else if (myColour == "cyan") {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);
  } else if (myColour == "magenta") {
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 100);
  }
}
