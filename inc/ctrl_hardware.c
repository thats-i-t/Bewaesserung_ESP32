
#define PIN_PUMP1 26
#define PIN_MOIST_SENSOR1 32

#define PUMP1_ON digitalWrite(PIN_PUMP1, HIGH)
#define PUMP1_OFF digitalWrite(PIN_PUMP1, LOW)


int pump1_state = 0;

void init_hardware()
{
  pinMode(PIN_PUMP1, OUTPUT);
  PUMP1_OFF;
}

int set_pump1(int newState)
{
  pump1_state = newState;
  if(pump1_state == 1){
      PUMP1_ON;
      writeLog("PUMP switched on");
  }
  else{
      PUMP1_OFF;
      writeLog("PUMP switched off");
  }
  return pump1_state;
}

int read_moist_sensor1()
{  
  int value = analogRead(PIN_MOIST_SENSOR1);
  String str = "Read moist_sensor1 = ";
  str.concat(value);
  writeLog(str);  
  return value;
}
