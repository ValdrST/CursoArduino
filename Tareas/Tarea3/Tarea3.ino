#include <LiquidCrystal.h>
const int d7 = 2, d6 = 3, d5 = 4, d4 = 5, en = 11,rs = 12;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int buzzer = 7;
int fotoLed = 6;
int potencioLed = 10;
int sensorFoto = A0;
int potenciometro = A1;
int sensorProxi = A2;
int herradura = A3; 
int boton[]={18,19,20,21};
int opcion=0;
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(herradura,INPUT);
  pinMode(potenciometro,INPUT);
  pinMode(sensorFoto,INPUT);
  pinMode(sensorProxi,INPUT);
  pinMode(fotoLed,OUTPUT);
  pinMode(potencioLed,OUTPUT);
  pinMode(buzzer,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(boton[0]),caso1,CHANGE);
  attachInterrupt(digitalPinToInterrupt(boton[1]),caso2,CHANGE); 
  attachInterrupt(digitalPinToInterrupt(boton[2]),caso3,CHANGE); 
  attachInterrupt(digitalPinToInterrupt(boton[3]),caso4,CHANGE);
}

void loop() {
  float sFoto=map(analogRead(sensorFoto),1023,0,0,255);
  float sPotencio=analogRead(potenciometro)/4;
  float sHerradura=digitalRead(herradura);
  float sProxi=analogRead(sensorProxi);
  analogWrite(fotoLed,sFoto);
  analogWrite(potencioLed,sPotencio);
  digitalWrite(buzzer,sHerradura);
  switch(opcion){
    case 1:
      lcd.setCursor(0,0);
      lcd.write("fotoresistencia");
      lcd.setCursor(2,1);
      Serial.println(String(sFoto));
      lcd.print(sFoto);
      break;
    case 2:
      lcd.setCursor(0,0);
      lcd.write("sensorProximidad");
      lcd.setCursor(2,1);
      Serial.println(sProxi);
        lcd.print(sProxi);
      break;
    case 3:
      lcd.setCursor(0,0);
      lcd.write("Potenciometro");
      lcd.setCursor(2,1);
      Serial.println(sPotencio);
        lcd.print(sPotencio);

      break;
    case 4:
      lcd.setCursor(0,0);
      lcd.write("Herradura");
      lcd.setCursor(2,1);
       Serial.println(sHerradura);
        lcd.print(sHerradura);
      break;
    default:
      break;
    }
    delay(10);
}

void caso1(){
  lcd.clear();
  opcion=1;
}
void caso2(){
  lcd.clear();
  opcion=2;
}
void caso3(){
  lcd.clear();
  opcion=3;
}
void caso4(){
  lcd.clear();
  opcion=4;
}

