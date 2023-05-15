// primeiro pino (negativo)
// segundo pino (positivo) //OPCIONAL
// terceiro pino (contraste 0v-5v) utilizando ou o potenciometro ou o negativo
// RS pin (enviando texto, ou tratando do conteudo)
// RW pin (lendo ou recebendo info. do display)
// E pin (enable, o arduino envia para o display)
// os DBn são de dados (sendo que as 4 primeiras são opcionais)
// os ultimos 2 são de luz de fundo (como o led, anodo e catodo)

#include<LiquidCrystal.h>

LiquidCrystal lcd(2,4,10,11,12,13); //colocace os pinos dados e de contorle

void setup()
{
  	Serial.begin(9600); //SETUP SERIAL
	lcd.begin(16,2); //quantidade de colunas e de linhas
  	lcd.print("Ola mundo!");
  	//lcd.setCursor(0,1); //coloca o cursor no local indicado x,y
  	lcd.write('x'); //escreve apenas um char
}

void loop()
{
  	lcd.blink(); //pisca onde o cursor está
  	//lcd.displayCursor(); //mostra onde o cursor está  	
}
