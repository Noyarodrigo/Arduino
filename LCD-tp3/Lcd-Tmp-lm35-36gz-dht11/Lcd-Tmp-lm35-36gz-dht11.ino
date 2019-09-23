#include <DHT.h>
#include <DHT_U.h>

#include <LiquidCrystal.h>


const int rs = 11, en = 10, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //definición de pines para manejo de dsplay 16x2
LiquidCrystal lcd_1(rs, en, d4, d5, d6, d7); //definicion de parametros para manejo de display 16x2

#define DHTPIN 52
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

//contador
int i=0;
//delay de medicion
int Delay= 2000;

//cantidad de variables
int var=0;

float tmplm35=0,tmp1=0;
int sensor=0;
float dhttmp=0;
float dhthum=0;

void setup() {
//escriba aqui la configuración  para las constantes,variables y pines que utilizará en el proyecto
  
  Serial.begin(9600);
  dht.begin();
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
  lcd_1.print(" -*.Sensores.*-");
  tmplm35 = analogRead(sensor);
  dhttmp = dht.readTemperature();
  dhthum = dht.readHumidity();
  
  //lm35
  tmp1 = (tmplm35 * 5.0 * 100.0) / 1023.0;  
  
 //lcd
  Serial.print("LM35: ");
  Serial.print(tmp1);
  Serial.print("\t");
  Serial.print("DHT tmp: ");
  Serial.print(dhttmp);
  Serial.print("\t");
  Serial.print("DHT Humedad: ");
  Serial.print(dhthum);
  Serial.print("\n");

  display();
  var++;
  
  delay(Delay);    
    
}

void display(){
  if (var>2) {
    var = 0;
    }
  
  if (var==0) {
    lcd_1.setCursor(0,1);
    lcd_1.print("LM35:");
    lcd_1.setCursor(6, 1);
    lcd_1.print(tmp1);
  }

  if (var==1) {
    lcd_1.setCursor(0,1);
    lcd_1.print("DHTT:");
    lcd_1.setCursor(6, 1);
    lcd_1.print(dhttmp);
  }

  if (var==2) {
    lcd_1.setCursor(0,1);
    lcd_1.print("DHTH:");
    lcd_1.setCursor(6, 1);
    lcd_1.print(dhthum);
  }
}
