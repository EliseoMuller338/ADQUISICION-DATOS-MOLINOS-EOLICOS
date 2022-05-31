float B=0;
float C=0;
float A=0;

void setup() 
{
 Serial.begin(9600);
 pinMode(A0,INPUT);
 
}

void loop() 
{
 B=analogRead(A0);
 A=(B*0.004887585);
 C=36*A;
 Serial.print(A);
 Serial.print("\t");
 Serial.println(C);
}
%hola
