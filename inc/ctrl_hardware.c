
#define PIN_PUMP1 26

#define PUMP1_ON digitalWrite(PIN_PUMP1, HIGH)
#define PUMP1_OFF digitalWrite(PIN_PUMP1, LOW)


void init_hardware()
{
  pinMode(PIN_PUMP1, OUTPUT);
}

