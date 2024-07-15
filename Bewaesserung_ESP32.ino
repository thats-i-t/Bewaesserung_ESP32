#include "inc/log.c" // should be included before other includes
#include "inc/ctrl_hardware.c" // should be included before other includes

#include "inc/index.c"
#include "inc/read_dht.c"
#include "inc/wifi.c"
// #include "inc/webserver.c"
#include "inc/ota_update.c"
#include "inc/tell_ip.c"


void setup() {
  Serial.begin(115200);
  init_dht();
  init_wifi();
  // init_webserver();
  init_OTA();
  init_hardware();

  tell_ip();
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
