#include <Arduino.h>
#include "ManejoSD.h"
void InicioSD(){
  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
  };
void EscribirRegistro(Registro Dato){
	noInterrupts();
  File dataFile = SD.open(NombreArchivo, FILE_WRITE);
    
      // if the file is available, write to it:
      if (dataFile) {
        dataFile.println(Dato.Cadena());//dataString);
		delay(50);
        dataFile.close();
        // print to the serial port too:
        Serial.println(Dato.Cadena());
      }
      // if the file isn't open, pop up an error:
      else {
        Serial.println("error opening datalog.txt");
      };
	  interrupts();
      
};

  //	void LeerRegistro(void){
  //	File dataFile = SD.open(NombreArchivo, FILE_READ);
  //    char Dato;
  //    // if the file is available, write to it:
  //    if (dataFile) {
  //      //dataFile.println(Dato.Cadena());//dataString);
  //      
  //      while(dataFile.available()){
  //      // print to the serial port too:
  //        Dato=dataFile.read();
  //        Serial.write(Dato);
  //      }
  //      dataFile.close();
  //    }
  //    // if the file isn't open, pop up an error:
  //    else {
  //      Serial.println("error opening datalog.txt");
  //    };
  //    Serial.write('>');
  //	};
void LeerRegistro(void) {
	long TiempoActual;
	long TiempoInicio;
	File dataFile = SD.open(NombreArchivo, FILE_READ);
	char Dato;
	// if the file is available, write to it:
	if (dataFile) {
		//dataFile.println(Dato.Cadena());//dataString);

		while (dataFile.available()) {
			// print to the serial port too:
			Dato = dataFile.read();
			Serial.write(Dato);
			//delay(100);
			if (Dato == 13) {
				TiempoInicio = millis();
				while ((Serial.available() <= 0) && (TiempoInicio + 10 > TiempoActual)) {
					TiempoActual = millis();
				};
				(void)(Serial.read() == 0);
			}
		}
		dataFile.close();
	}
	// if the file isn't open, pop up an error:
	else {
		Serial.println("error opening datalog.txt");
	};
	Serial.write('>');
};


void BorrarSD(void){
       
       if (SD.exists(NombreArchivo))
       SD.remove(NombreArchivo);
       
       if (!SD.exists(NombreArchivo))
       Serial.print("K");
}
