#include "time.h"

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 0;
const int   daylightOffset_sec = 3600;

void auto_mode_light(){
    // Init and get the time
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    
    struct tm timeinfo;
    getLocalTime(&timeinfo);
    char timeHour[3];
    strftime(timeHour,3, "%H", &timeinfo);
    writeLog(timeHour);
}
