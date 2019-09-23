#include <LiquidCrystal.h>


const int rs = 11, en = 10, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //definición de pines para manejo de dsplay 16x2
LiquidCrystal lcd_1(rs, en, d4, d5, d6, d7); //definicion de parametros para manejo de display 16x2

int i=0;
int Delay= 333;
float tmp=0,tmp1=0;
int sensor=0;


void setup() {
//escriba aqui la configuración  para las constantes,variables y pines que utilizará en el proyecto
  
  Serial.begin(9600);
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
  lcd_1.print("-*.Temperatura.*-");
  tmp=analogRead(sensor);
  
  tmp1 = (tmp * 5.0 * 100.0) / 1023.0;  
  Serial.print(tmp1);
  // Salto de línea
  Serial.print("\n");
  lcd_1.setCursor(0,1);
  lcd_1.print("T:");
  lcd_1.setCursor(3, 1);
  lcd_1.print(tmp1);
  delay(Delay);    
    
}
