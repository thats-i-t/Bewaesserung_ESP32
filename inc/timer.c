#include <arduino-timer.h> // https://github.com/contrem/arduino-timer

Timer<> timer;

bool timerTask1(void *)
{
  tell_ip();
  return true; // to keep timer active
}

bool timerTask2(void *)
{
  if(operation_mode == MODE_AUTOMATIC)
  {
    auto_mode();
  }
  return true; // to keep timer active
}

bool timerTask3(void *)
{
  meas_and_filter_moist_sensor();
  return true; // to keep timer active
}

bool timerTask4(void *)
{
  read_all_DHT();
  // getSensorDataString();
  if(Serial1) {
    Serial.println(getAllDataString());
  }
}

void init_timer()
{  
    timer.every(100000, timerTask1); // every 100 seconds
    timer.every(1000, timerTask2); // every 1 second
    timer.every(10, timerTask3); // every 10 milli sec
    timer.every(2000, timerTask4); // every 3 sec
}
