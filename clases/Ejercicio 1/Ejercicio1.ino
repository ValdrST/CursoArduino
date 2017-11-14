//este codigo sirve para prender y apagar led con un boton
const int boton1=13;
const int led=7;

int boton=0;
void setup(){
  pinMode(led,OUTPUT);
  //pinMode(boton,INPUT);
}

void loop(){
  //boton=digitalRead(boton);
  if(digitalRead(boton)== 1){
    digitalWrite(led,HIGH);
    delay(5000);
  }
   else{
     digitalWrite(led,LOW);
   }
}
