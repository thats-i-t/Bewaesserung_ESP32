#include "ESPAsyncWebServer.h"

AsyncWebServer server(80); // AsyncWebServer on port 80

void init_webserver()
{    
    server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
        // request->send_P(200, "text/plain", getAllDataString().c_str());
        request->send_P(200, "text/html", index_html);  
    });


    server.on("/sensor", HTTP_GET, [](AsyncWebServerRequest * request) { // http://esp32-wohnzimmer/sensor?nr=1
        int reqValid = 0;
        int NParams = request->params();
        if(NParams == 1)
        {
            AsyncWebParameter* p = request->getParam(0);
            int sensorNr = p->value().toInt();
            if(sensorNr >= 1 && sensorNr <= NDht)
            {
                // Serial.println(p->name());
                request->send_P(200, "text/plain", getSensorDataString(sensorNr-1).c_str());  
                reqValid = 1;    
            }
        }
        if(0 == reqValid)
        {
            String s = "Passed wrong sensor number!";
            request->send_P(200, "text/plain", s.c_str());      
        }
    });

    server.begin(); // Start Webserver
}