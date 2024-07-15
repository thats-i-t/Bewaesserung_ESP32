
#define PIN_PUMP1 25
#define PIN_PUMP2 26
#define PIN_PUMP3 14 //27
#define PIN_VENT 27 //14

#define PIN_MOIST_SENSOR1 33 //32
#define PIN_MOIST_SENSOR2 32 //33 
#define PIN_MOIST_SENSOR3 35

#define PUMP1_ON  digitalWrite(PIN_PUMP1, HIGH);writeLog("PUMP 1 switched on")
#define PUMP1_OFF digitalWrite(PIN_PUMP1, LOW);writeLog("PUMP 1 switched off")

#define PUMP2_ON  digitalWrite(PIN_PUMP2, HIGH);writeLog("PUMP 2 switched on")
#define PUMP2_OFF digitalWrite(PIN_PUMP2, LOW);writeLog("PUMP 2 switched off")

#define PUMP3_ON  digitalWrite(PIN_PUMP3, HIGH);writeLog("PUMP 3 switched on")
#define PUMP3_OFF digitalWrite(PIN_PUMP3, LOW);writeLog("PUMP 3 switched off")

#define VENT_ON  digitalWrite(PIN_VENT, HIGH);writeLog("VENT switched on")
#define VENT_OFF digitalWrite(PIN_VENT, LOW);writeLog("VENT switched off")


void init_hardware()
{
  pinMode(PIN_PUMP1, OUTPUT);
  PUMP1_OFF;

  pinMode(PIN_PUMP2, OUTPUT);
  PUMP2_OFF;

  pinMode(PIN_PUMP3, OUTPUT);
  PUMP3_OFF;

  pinMode(PIN_VENT, OUTPUT);
  VENT_OFF;
}

int set_pump1(int newState)
{
  if(newState == 1){
      PUMP1_ON;
  }
  else{
      PUMP1_OFF;
  }
  return newState;
}

int set_pump2(int newState)
{
  if(newState == 1){
      PUMP2_ON;
  }
  else{
      PUMP2_OFF;
  }
  return newState;
}

int set_pump3(int newState)
{
  if(newState == 1){
      PUMP3_ON;
  }
  else{
      PUMP3_OFF;
  }
  return newState;
}

int set_vent(int newState)
{
  if(newState == 1){
      VENT_ON;
  }
  else{
      VENT_OFF;
  }
  return newState;
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
  int value = analogRead(PIN_MOIST_SENSOR2);
  String str = "Read moist_sensor2 = ";
  str.concat(value);
  writeLog(str);  
  return value;
}

int read_moist_sensor3()
{  
  int value = analogRead(PIN_MOIST_SENSOR3);
  String str = "Read moist_sensor3 = ";
  str.concat(value);
  writeLog(str);  
  return value;
}

int read_moist_sensor(int nr)
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

