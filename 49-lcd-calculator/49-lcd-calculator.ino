#include <LiquidCrystal.h>
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;
int dT = 5000;

float firstNum;
float secondNum;
float answer;
String op;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print("Input 1st number");
  while (Serial.available() == 0) {
    
  }
  firstNum = Serial.parseFloat();
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Input 2nd number");
  while (Serial.available() == 0) {
    
  }
  secondNum = Serial.parseFloat();
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Input +, -, *, /");
  while (Serial.available() == 0) {
    
  }
  op = Serial.readString();

  if (op == "+") {
    answer = firstNum + secondNum;
  } else if (op == "-") {
    answer = firstNum - secondNum;
  } else if (op == "*") {
    answer = firstNum * secondNum;
  } else if (op == "/") {
    answer = firstNum / secondNum;
  }

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(firstNum);
  lcd.print(op);
  lcd.print(secondNum);
  lcd.print("=");
  lcd.print(answer);

  delay(dT);
  lcd.clear();
}
