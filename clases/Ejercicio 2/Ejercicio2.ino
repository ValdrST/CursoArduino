//led y buzzer con dos botnes
const int boton1 = 12;
const int boton2 = 13;
const int led1 = 7;  
const int led2= 6;
const int buzzer=5; 
int fr=220;
int fr1=440;

 
void setup() {
  pinMode(led1, OUTPUT);          
  pinMode(led2, OUTPUT); 
  
}

void loop(){
 
  if((digitalRead(boton1)== 1)&&(digitalRead(boton2)== 1)){
     digitalWrite(led1,HIGH);
    delay(5000);
     digitalWrite(led1,HIGH);
    delay(5000);
    tone(buzzer,fr);
    delay(2000);
  }
    if(digitalRead(boton1)== 1){
    digitalWrite(led1,HIGH);
    delay(5000);
    noTone(buzzer); 
  }
  if(digitalRead(boton2)== 1){
    digitalWrite(led2,HIGH);
    delay(5000);
    noTone(buzzer); 
  }
  else {
    digitalWrite(led1, LOW);
    digitalWrite(led2,LOW);
   noTone(buzzer); 
  }
}
