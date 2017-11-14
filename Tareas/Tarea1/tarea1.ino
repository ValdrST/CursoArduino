int buzzer = 8;
int Do = 261;      //frecuencias estandar de notas
int Re = 293;
int Mi = 329;
int Fa = 349;
int Sol = 391;

void setup()
{
}

void loop()
{
    tone(buzzer,Do);
    delay(1000);    
	tone(buzzer,Re);
    delay(1000);    
    tone(buzzer,Mi);
    delay(1000);
    tone(buzzer,Fa);
    delay(1000);
    tone(buzzer,Sol);
    delay(1000);
    tone(buzzer,Li);
    delay(1000);
    tone(buzzer,Si);
    delay(1000);
    noTone(buzzer);
    delay(5000);
}
