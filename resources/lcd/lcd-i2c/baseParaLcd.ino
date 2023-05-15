// INCLUSÃO DE BIBLIOTECAS
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// INSTANCIANDO OBJETOS 
LiquidCrystal_I2C lcd(34, 16, 2); // tem um codigo de verificação da porta nessa mesma pasta 
                                  // mas geralmente é a porta 0x27

void setup() {
  lcd.init(); // INICIA A COMUNICAÇÃO COM O DISPLAY
  lcd.backlight(); // LIGA A ILUMINAÇÃO DO DISPLAY
  lcd.clear(); // LIMPA O DISPLAY

  lcd.print("- Ola, Mundo! -");
  delay(5000); // DELAY DE 5 SEGUNDOS
  lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 2
  lcd.print("Fim do Setup ()");
  delay(5000); // DELAY DE 5 SEGUNDOS
  
  lcd.noBacklight(); // DESLIGA A ILUMINAÇÃO DO DISPLAY
  delay(2000); // DELAY DE 2 SEGUNDOS
  lcd.backlight(); // LIGA A ILUMINAÇÃO DO DISPLAY
  delay(2000); // DELAY DE 2 SEGUNDOS
  
  lcd.clear(); // LIMPA O DISPLAY
  //lcd.noBacklight(); // DESLIGA A ILUMINAÇÃO DO DISPLAY
}

void loop() {

  //lcd.clear();
  lcd.print("- Ola, Mundo! -");
  lcd.setCursor(0, 1); // POSICIONA O CURSOR NA PRIMEIRA COLUNA DA LINHA 2
  lcd.print("Fim do Setup ()");

}