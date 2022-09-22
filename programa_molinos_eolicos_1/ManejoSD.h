#define NombreArchivo "datalog.txt"
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#ifndef _MANEJOSD
#define _MANEJOSD


class Registro{
  public:
  String dataString;
  String Frecuencia;
  String Tension;
  String Cadena() {
	  return dataString + "," + Frecuencia + "," + Tension ;
    }
  };
 
const int chipSelect = 10; // 53;//
/*
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 10
 **
  */

void InicioSD();
void EscribirRegistro(Registro Dato);
void LeerRegistro(void);
void BorrarSD(void);


#endif // !_MANEJOSD
