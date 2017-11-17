int ledRojo = 12;
int ledVerde = 13;
int in2 = 6;
int in7 = 7;
int proxi = A0;
int potenciometro = A1;
int fotoResis = A2;
int disponible = 1;
int ilum = 0;
int boton=21;
int pwm1, pwm2, encendido;
void setup() {
  pinMode(proxi,INPUT);
  pinMode(fotoResis,INPUT);
  pinMode(potenciometro,INPUT);
  pinMode(ledRojo,OUTPUT);
  pinMode(ledVerde,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in7,OUTPUT);
  pinMode(boton,INPUT);
  Serial.begin(9600);
}

void loop() {
  int proxiSense = analogRead(proxi);
  int brillo = map(analogRead(fotoResis),500,1023,0,100);
  if(proxiSense<=500)
    ocupado();
  else if(proxiSense>500)
    libre();
  if(brillo<=50){
    ilum=0;
  }else if(brillo>50){
    ilum=1;
  }
  if(ilum==1)
    prender();
  else if(ilum==0)
    apagar();
  if(encendido==1||digitalRead(boton)==1){
    pwm1 = map(analogRead(potenciometro), 0, 1023, 0, 255);
    pwm2 = map(analogRead(potenciometro), 0, 1023, 255, 0);
    analogWrite(in2,pwm2);
    analogWrite(in7,pwm1);
  }else if(encendido==0){
    analogWrite(in2,0);
    analogWrite(in7,0);
  }
  Serial.println(digitalRead(boton));
  delay(1);
}

void ocupado(){
  analogWrite(ledRojo,HIGH);
  analogWrite(ledVerde,LOW);
  disponible = 0;
}

void libre(){
  analogWrite(ledRojo,LOW);
  analogWrite(ledVerde,HIGH);
  disponible = 1;
}

void prender(){
  encendido=1;
}
void apagar(){
  encendido=0;
}


