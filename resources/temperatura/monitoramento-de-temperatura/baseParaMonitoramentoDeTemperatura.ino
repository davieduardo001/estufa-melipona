#include"LiquidCrystal.h"
LiquidCrystal lcd(8,7,6,5,4,3);
int sensorPin = 0;

void setup()
{
	Serial.begin(9600);
  	lcd.begin(16,2);
}

void loop()
{
	int reading = analogRead(sensorPin);
  	float voltage = reading * 4.68;
  	voltage /= 1024.0;
  	
  	float temperatureC = (voltage - 0.5) * 100;
  	Serial.print(temperatureC);
  	Serial.println(" *C");
  	
  	lcd.setCursor(0,0);
  	lcd.print("Temperature ");
  	lcd.setCursor(0,1);
  	lcd.print(" *C");
    lcd.setCursor(4,1);
  	lcd.print(temperatureC);
}
