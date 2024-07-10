#include "inc/index.c"
#include "inc/ctrl_hardware.c"
#include "inc/read_dht.c"
#include "inc/wifi.c"
// #include "inc/webserver.c"
#include "inc/ota_update.c"


void setup() {
  Serial.begin(115200);
  init_dht();
  init_wifi();
  // init_webserver();
  init_OTA();
  init_hardware();
}

void loop()
{  
  // read_all_DHT();
  // if(Serial1) {
  //   Serial.println(getAllDataString());
  // }
  
  // ArduinoOTA.handle();
  server_ota.handleClient();

}
