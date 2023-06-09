#include "DHT.h"
#define DHTPIN 2     // Pino digital sensor DHT

# define DHTTYPE DHT11


DHT dht(DHTPIN, DHTTYPE);

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Definir o endereço do LCD para 0x27 para um display de 16 caracteres e 2 linhas
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx teste!"));

  dht.begin();
  lcd.begin();
}

void loop() {
  // tempo entre medições de temperatura e humidade
  // delay(2000);

  // A leitura da temperatura ou umidade leva cerca de 250 milissegundos!
  // O sensor pode ter um atraso de até 2 segundos para a leitura
  
  float h = dht.readHumidity();
  // Temperatura em celcius (default)
  float t = dht.readTemperature();

  // Verifique se alguma leitura falhou e tenta novamente.
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Falha de leitura do sensor DHT!"));
    return;
  }

  // computar a temperatura em Celcius (isFahré eit = false)
  float hic = dht.computé eatIndex(t, h, false);

  Serial.print(F("Umidade: "));
  Serial.print(h);
  Serial.print(F("%  Temperatura: "));
  Serial.print(t);
  Serial.print(F("°C "));

  lcd.setBacklight(HIGH);

  lcd.setCursor(0, 0);
  lcd.print(F("Humidade: "));
  lcd.setCursor(10, 0);
  lcd.print(round(h));
  lcd.setCursor(12, 0);
  lcd.print(F(" %"));
  delay(3000);

  lcd.setCursor(0, 1);
  lcd.print(F("Tempo: "));
  lcd.setCursor(7, 1);
  lcd.print(round(t));
  lcd.setCursor(9, 1);
  lcd.write(32);  // Caracter espaço
  lcd.write(223); // Caracter °
  lcd.print(F("C"));
  delay(3000);
}
