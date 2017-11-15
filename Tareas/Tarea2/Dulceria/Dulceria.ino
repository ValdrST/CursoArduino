int Btn1=18;
int Btn2=19;
int Btn3=20;
int Btn4=21;
int Led1=4;
int Led2=5;
int Led3=6;
int Led4=7;
int Sensor=2;
int credito;
void setup() {
  pinMode(Led1,OUTPUT);          
  pinMode(Led2,OUTPUT);
  pinMode(Led3,OUTPUT);
  pinMode(Led4,OUTPUT);
  Serial.begin(9600);//PARA EL SENSOR
  attachInterrupt(digitalPinToInterrupt(Btn1),diminuir5,RISING);
  attachInterrupt(digitalPinToInterrupt(Btn2),diminuir6,RISING); 
  attachInterrupt(digitalPinToInterrupt(Btn3),diminuir7,RISING); 
  attachInterrupt(digitalPinToInterrupt(Btn4),diminuir8,RISING);
  attachInterrupt(digitalPinToInterrupt(Sensor),aumentar,FALLING);
}
void loop() {
  Serial.println(credito);
   if(credito>=5){
    digitalWrite(Led1,HIGH);
   }else{
    digitalWrite(Led1,LOW);
   }
   if(credito>=6){
    digitalWrite(Led2,HIGH);
   }else{
    digitalWrite(Led2,LOW);
   }
   if(credito>=7){
    digitalWrite(Led3,HIGH);
   }else{
    digitalWrite(Led3,LOW);
   }
   if(credito>=8){
    digitalWrite(Led4,HIGH);
   }else{
    digitalWrite(Led4,LOW);
   }
   if(credito<0)
    credito=0;
   delay(1);
}
void diminuir5(){
  if(credito>=5)
    credito-=5;
}
void diminuir6(){
  if(credito>=6)
    credito-=6;
}
void diminuir7(){
  if(credito>=7)
    credito-=7;
}
void diminuir8(){
  if(credito>=8)
    credito-=8;
}
void aumentar(){
  credito++;
}

