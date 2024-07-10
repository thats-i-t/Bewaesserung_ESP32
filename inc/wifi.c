#include "WiFi.h"
// #include <ESPmDNS.h>
#include <WiFiUdp.h>

const char* ssid = "Pyramidenverleih Ramses";
const char* password = "Hallodu-10";


void init_wifi()
{
    WiFi.begin(ssid, password); // Connect to Wi-Fi
    WiFi.mode(WIFI_STA);
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("WiFi connecting..");
        delay(1000);
    }
    // while(WiFi.waitForConnectResult() != WL_CONNECTED)
    // {
    //     Serial.println("Connection Failed! Rebooting...");
    //     delay(5000);
    //     ESP.restart();        
    // }
    Serial.println(WiFi.localIP()); // Print IP
}
