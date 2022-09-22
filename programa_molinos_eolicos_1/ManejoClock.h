#include <Wire.h>
#include <RTClib.h>
#ifndef _MANEJOCLOCK
#define _MANEJOCLOCK
	enum dias {LUNES,MARTES, MIERCOLES, JUEVES, VIERNES, SABADO , DOMINGO};
	void InicioRTC(RTC_DS3231 &rtc);
	String TiempoActual(RTC_DS3231 &rtc);
	uint32_t TiempoActualUnix(RTC_DS3231 &rtc);
#endif
