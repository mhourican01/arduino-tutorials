String msg = "How many blinks do you want?";
int numBlinks;
int redPin = 12;
int wait = 500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(msg);
  
  while (Serial.available() == 0) {
    
  }

  numBlinks = Serial.parseInt();
  
  for (int i = 1; i <= numBlinks; i += 1) {
    digitalWrite(redPin, HIGH);
    delay(wait);
    digitalWrite(redPin, LOW);
    delay(wait);
  }
}
