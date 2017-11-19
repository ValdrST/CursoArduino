int display[]={30,32,34,36,31,33,35,37};
int boton=2;
int estado=0;
int unidades=14;
int decenas=15;
int contador=0;
int num[][7]={{0,1,1,1,1,1,1},{0,0,0,1,0,0,1},{1,0,1,1,1,1,0},{1,0,1,1,0,1,1},{1,1,0,1,0,0,1},{1,1,1,0,0,1,1},{1,1,1,0,1,1,1},{0,0,1,1,0,0,1},{1,1,1,1,1,1,1},{1,1,1,1,0,0,1},{1,0,0,0,0,0,0}};
void setup() {
  Serial.begin(9600);
  for(int i=0; i<7; i++){
    pinMode(display[i],OUTPUT);
  }
  pinMode(boton,OUTPUT);
  pinMode(unidades,OUTPUT);
  pinMode(decenas,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(boton),aumentar,RISING);
}

void loop() {
  
  int unit=contador%10;
  int dec=(contador-unit)/10;
    if(estado==0){
      digitalWrite(boton,estado);
      numero(num[unit]);
      digitalWrite(decenas,1);
      digitalWrite(unidades,0);
      estado=1;
    }else if(estado==1){
      digitalWrite(decenas,estado);
      numero(num[dec]);
      digitalWrite(decenas,0);
      digitalWrite(unidades,1);
      estado=0;
    }
    if(contador>99){
      contador=0;
    }
  Serial.println(contador);
  delay(10);
  
}

void numero (int num[]) {
    digitalWrite (display[0],num[0]);   
    digitalWrite (display[1],num[1]);   
    digitalWrite (display[2],num[2]);
    digitalWrite (display[3],num[3]);
    digitalWrite (display[4],num[4]);
    digitalWrite (display[5],num[5]);
    digitalWrite (display[6],num[6]);
}

void aumentar(){
  contador=contador+1;
}

