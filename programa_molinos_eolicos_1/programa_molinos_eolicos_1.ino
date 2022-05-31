float B=0;
float C=0;
float A=0;

void setup() 
{
 Serial.begin(9600);
 pinMode(A0,INPUT);
 
}

void loop() 
{//entrada analogica
 B=analogRead(A0);
 A=((B*5)/1023);
 C=39.5*A;
 Serial.print(A);
 Serial.print("\t");
 Serial.println(C);
}
