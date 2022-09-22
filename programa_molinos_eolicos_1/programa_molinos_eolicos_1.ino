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
#include "ManejoClock.h"
#include "ManejoSD.h"
RTC_DS3231 rtc;
Registro Datos;
int pin = 3;
volatile int state = LOW;
unsigned long tiempoInicial;
int contadorPulso = 0;
int tension=0;
const unsigned long tiempoFrecuencia=2000;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  InicioSD();
  InicioRTC(rtc);
  pinMode(pin, INPUT);
  attachInterrupt(digitalPinToInterrupt(pin), cuentaPulso, RISING);
}

void loop() {
  
  if (millis() - tiempoInicial >= tiempoFrecuencia)
  {
    analogWrite(5, contadorPulso);
    tiempoInicial = millis();
    tension=analogRead(A0);
    Datos.dataString=TiempoActual(rtc);
    Datos.Frecuencia=String(contadorPulso);
    Datos.Tension=String(tension);
    EscribirRegistro(Datos);
    contadorPulso = 0;
  }
}

void cuentaPulso() {
  contadorPulso++;
}
