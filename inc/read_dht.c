#include <Adafruit_Sensor.h>
#include <DHT.h>

#define RX1 34
#define TX1 35
#define DHT_TYPE DHT11 // DHT11 or DHT22 (=AM2302) or DHT21 (=AM2301)

const int DHT_PINS[] = {27, 26, 25, 14, 33, 32};
const int NDht = 6; //sizeof(DHT_PINS) / sizeof(int);

DHT dhtSensors[] = {
  DHT(DHT_PINS[0], DHT_TYPE),
  DHT(DHT_PINS[1], DHT_TYPE),
  DHT(DHT_PINS[2], DHT_TYPE),
  DHT(DHT_PINS[3], DHT_TYPE),
  DHT(DHT_PINS[4], DHT_TYPE),
  DHT(DHT_PINS[5], DHT_TYPE)
};

float temperature[NDht];
float humidity[NDht];
int refreshed[NDht];
int loopCnt = 0;

void init_dht()
{ 
  for (int i; i < NDht; i++)
  {
    dhtSensors[i].begin();
  }
}

int read_DHT(DHT *dht, float *temp, float *humid) {
  *temp = dht->readTemperature();
  *humid = dht->readHumidity();
  int valid = isnan(*temp) ? 0 : 1;
  valid = isnan(*humid) ? 0 : valid;
  return valid;
}

void read_all_DHT()
{
  loopCnt++;
  
  float temp, humid;
  for(int i; i < NDht; i++)
  {
    if(read_DHT(&dhtSensors[i], &temp, &humid))
    {
      temperature[i] = temp;
      humidity[i] = humid;
      refreshed[i] = loopCnt;
    }
  }
}

String getSensorDataString(int i)
{
  String s = String(i+1) + "," + String(temperature[i]) + "," + String(humidity[i]) + "," + String(refreshed[i]);
  return s;
}

String getAllDataSimpleString()
{
  String s;
  for(int i = 0; i < NDht; i++)
  {
    s += getSensorDataString(i) + "\n";
  }
  return s;  
}

String getAllDataString()
{
  String s = "Sensor data:\n";
  s += "Number,Temperature,Humidity,RefreshCounter\n";
  s += getAllDataSimpleString();
  return s;
}

