#include "DHT.h"
#define Type DHT11
#include <LiquidCrystal.h>
int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int sensePin = 2;
DHT HT(sensePin, DHT11);
float humidity;
float tempC;
float tempF;
int setupT = 500;
int dT = 500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HT.begin();
  delay(setupT);
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  tempF = HT.readTemperature(true);

  lcd.setCursor(0,0);
  lcd.print("Temp. (F): ");
  lcd.print(tempF);
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");
  delay(dT);
  lcd.clear();

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" Temperature (C): ");
  Serial.print(tempC);
  Serial.print(" Temperature (F): ");
  Serial.println(tempF);
}
