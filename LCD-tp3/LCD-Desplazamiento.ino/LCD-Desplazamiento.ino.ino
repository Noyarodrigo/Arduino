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
  //Desplazamiento de izquierda a derecha
  lcd_1.clear();
  lcd_1.setCursor(10, 0);
  lcd_1.print("  -.Contador.-");   
  lcd_1.setCursor(13, 1);
  lcd_1.print("i: ");
  lcd_1.autoscroll();
  for (i=1; i<tope ; i++){
    lcd_1.print(i);
    delay(Delay);
  }
  lcd_1.noAutoscroll();
  lcd_1.clear();

  //cambio de linea y desplazamiento izquierda a derecha
  delay(1000);
  lcd_1.setCursor(10, 1);
  lcd_1.print("  -.Contador.-");
  lcd_1.setCursor(13, 0);
  lcd_1.print("i: ");
  lcd_1.autoscroll();
  for (i=1; i<tope ; i++){
    lcd_1.print(i);
    delay(Delay);
  }
  lcd_1.noAutoscroll();
  lcd_1.clear();
}
