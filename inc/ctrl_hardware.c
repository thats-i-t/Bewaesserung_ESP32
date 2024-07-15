
#define PIN_PUMP1 26
#define PIN_MOIST_SENSOR1 32

#define PUMP1_ON digitalWrite(PIN_PUMP1, HIGH)
#define PUMP1_OFF digitalWrite(PIN_PUMP1, LOW)

#define PUMP2_ON
#define PUMP2_OFF

#define PUMP3_ON
#define PUMP3_OFF


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

int read_moist_sensor2()
{
  return 0;
}

int read_moist_sensor3()
{
  return 0;
}

void read_moist_sensor(int nr)
{
  int value = 0;
  switch(nr)
  {
    case 1:      
      value = read_moist_sensor1();
      break;
    case 2:      
      value = read_moist_sensor2();
      break;    
    case 3:
      value = read_moist_sensor3();
      break;
  }
  return value;
}

void pump_on(int nr)
{
  switch(nr)
  {
    case 1:
      PUMP1_ON;
      break;
    case 2:
      PUMP2_ON;
      break;    
    case 3:
      PUMP3_ON;
      break;
  }
}

void pump_off(int nr)
{
  switch(nr)
  {
    case 1:
      PUMP1_OFF;
      break;
    case 2:
      PUMP2_OFF;
      break;    
    case 3:
      PUMP3_OFF;
      break;
  }
}

