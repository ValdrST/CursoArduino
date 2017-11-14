//led controlado con potenciometro
int led=8;
int potenciometro=7;
int brillo;  

void setup ()  {
  pinMode (led, OUTPUT); 
}

void loop (){
  brillo = analogRead(potenciometro)/4; 
  analogWrite(led, brillo);
}
