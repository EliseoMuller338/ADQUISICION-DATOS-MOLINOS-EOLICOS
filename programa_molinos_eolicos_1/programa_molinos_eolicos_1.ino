/*proyecto GELACC adquisición de datos molino
 * V1.0.0 al 31-05-2022
 * ********************************************
 * Medición de tensión
 * - Cada 1 minuto
 * - Filtro de mediciones 1 muestra cada 10 ms.
 * - Registro en SD 
 * ********************************************
 * Medición de frecuencia
 * - Cada 1 minuto
 * - Filtro de mediciones (conteo de pulsos durante 1 minuto Frecuencia=conteoDePulsos/60)
 * - Registro en SD
 * - Funcionamiento por interrupción Externa por flanco descendente.
 * Fecha y Hora
 * - Uso de funciones tomadas del ejemplo de RTClib.h en manejoCLock.h
 * - Configuración RTC
 * Manejo SD
 * - Funciones en manejoSD (configuración y almacenamiento de datos) 
 */
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
