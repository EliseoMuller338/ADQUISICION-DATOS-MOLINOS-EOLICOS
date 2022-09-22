#include "ManejoClock.h"
//char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};  

void InicioRTC(RTC_DS3231 &rtc){
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    return;
  }
  Serial.println("RTC encontrada");
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  }
String TiempoActual(RTC_DS3231 &rtc){
    DateTime now = rtc.now();
    String dataString = "";
    String stryear=String(now.year());
    String strmonth=String(now.month());
    String strday=String(now.day());
    String strhour=String(now.hour());
    String strminute=String(now.minute());
    String strsecond=String(now.second());
    dataString=stryear+";"+strmonth+";"+strday+";";
    dataString+=strhour+";"+strminute+";"+strsecond;
    return dataString;
}

uint32_t TiempoActualUnix(RTC_DS3231 &rtc){
  DateTime now = rtc.now();
  return now.unixtime();
}
