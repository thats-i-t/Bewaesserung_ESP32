#include <arduino-timer.h> // https://github.com/contrem/arduino-timer

Timer<> timer;

bool timerTask1(void *)
{
  tell_ip();
  return true; // to keep timer active
}

bool timerTask2(void *)
{

  return true; // to keep timer active
}

void init_timer()
{  
    timer.every(100000, timerTask1); // every 100 seconds
    timer.every(1000, timerTask2); // every 1 second
}
