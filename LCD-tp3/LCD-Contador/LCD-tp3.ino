#include <LiquidCrystal.h>


const int rs = 11, en = 10, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //definición de pines para manejo de dsplay 16x2
LiquidCrystal lcd_1(rs, en, d4, d5, d6, d7); //definicion de parametros para manejo de display 16x2

int i=0;
int Delay= 333;
int tope = 11;

void setup() {
//escriba aqui la configuración  para las constantes,variables y pines que utilizará en el proyecto
  
  lcd_1.begin(16,2);
  
  lcd_1.clear();
  lcd_1.home();
  lcd_1.print("Bienvenidos !");
  lcd_1.setCursor(0, 1);
  lcd_1.print("U. de Mendoza");
  delay(3000);
}

void loop() {
  lcd_1.clear();
  lcd_1.print("  -.Contador.-");
  for (i=1; i<tope ; i++){
    
    lcd_1.setCursor(0, 1);
    lcd_1.print("i: ");
    lcd_1.setCursor(2, 1);
    lcd_1.print(i);
    lcd_1.setCursor(5, 1);
    lcd_1.print("D: ms");
    lcd_1.setCursor(10, 1);
    lcd_1.print(Delay);
    delay(Delay);    
  }
    
}
