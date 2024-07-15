#include <WiFi.h>
#include <HTTPClient.h>

String serverName = "https://dieterle.ws/tell_ip";

void tell_ip()
{
    if(WiFi.status() == WL_CONNECTED)
    {
        HTTPClient http;

        String serverPath = serverName + "?ip=123.456.789.000";
        
        // Your Domain name with URL path or IP address with path
        http.begin(serverPath.c_str());
        
        // If you need Node-RED/server authentication, insert user and password below
        //http.setAuthorization("REPLACE_WITH_SERVER_USERNAME", "REPLACE_WITH_SERVER_PASSWORD");
        
        // Send HTTP GET request
        int httpResponseCode = http.GET();
        
        if (httpResponseCode>0) {
            writeLog("HTTP Response code: ");
            writeLog(httpResponseCode);
            String payload = http.getString();
            writeLog(payload);
        }
        else {
            writeLog("Error code: ");
            writeLog(httpResponseCode);
        }
        // Free resources
        http.end();
    }
}