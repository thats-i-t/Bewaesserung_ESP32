#include "time.h"

const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600;
const int   daylightOffset_sec = 3600;

void init_auto_mode_light(){
    // Init and get the time
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    
    struct tm timeinfo;
    getLocalTime(&timeinfo);
    char timeHour[3];
    strftime(timeHour,3, "%H", &timeinfo);
    String tmp=String(timeHour);
    writeLog(tmp);
}

static int temp_old = 0;

void auto_mode_light(){
    struct tm timeinfo;
    getLocalTime(&timeinfo);
    char timeHour[3];
    strftime(timeHour,3, "%H", &timeinfo);
    int tmp = atoi(timeHour);
    if (tmp == 20 && temp_old == 19){
        LIGHT_OFF;
    }
    if (tmp == 8 && temp_old == 7){
        LIGHT_ON;
    }
    temp_old = tmp;
}