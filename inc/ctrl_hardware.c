
#define PIN_PUMP1 25
#define PIN_PUMP2 26
#define PIN_PUMP3 14
#define PIN_VENT 27
#define PIN_LIGHT 19

#define PIN_MOIST_SENSOR1 33
#define PIN_MOIST_SENSOR2 32
#define PIN_MOIST_SENSOR3 35

#define PUMP1_ON  digitalWrite(PIN_PUMP1, HIGH);writeLog("PUMP 1 switched on")
#define PUMP1_OFF digitalWrite(PIN_PUMP1, LOW);writeLog("PUMP 1 switched off")

#define PUMP2_ON  digitalWrite(PIN_PUMP2, HIGH);writeLog("PUMP 2 switched on")
#define PUMP2_OFF digitalWrite(PIN_PUMP2, LOW);writeLog("PUMP 2 switched off")

#define PUMP3_ON  digitalWrite(PIN_PUMP3, HIGH);writeLog("PUMP 3 switched on")
#define PUMP3_OFF digitalWrite(PIN_PUMP3, LOW);writeLog("PUMP 3 switched off")

#define VENT_ON  digitalWrite(PIN_VENT, HIGH);writeLog("VENT switched on")
#define VENT_OFF digitalWrite(PIN_VENT, LOW);writeLog("VENT switched off")

#define LIGHT_ON  digitalWrite(PIN_LIGHT, HIGH);writeLog("LIGHT switched on")
#define LIGHT_OFF digitalWrite(PIN_LIGHT, LOW);writeLog("LIGHT switched off")


float moist_sens_filt[3] = { 0, 0, 0 };


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

  pinMode(PIN_LIGHT, OUTPUT);
  LIGHT_OFF;
}

int get_vent_state()
{
  return digitalRead(PIN_VENT);
}

int get_light_state()
{
  return digitalRead(PIN_LIGHT);
}

int get_pump_state(int nr)
{
  int value = 0;
  switch(nr)
  {
    case 1:
      value = digitalRead(PIN_PUMP1);
      break;
    case 2:
      value = digitalRead(PIN_PUMP2);
      break;
    case 3:
      value = digitalRead(PIN_PUMP3);
      break;
  }
  return value;
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

int set_light(int newState)
{
  if(newState == 1){
      LIGHT_ON;
  }
  else{
      LIGHT_OFF;
  }
  return newState;
}

void meas_and_filter_moist_sensor()
{
  int i;
  float cFilt = 0.95; // large value means more filtering
  int u_new, y_old, y_new;
  for(i = 0; i < 3; i++)
  {
    if(i == 0)
      u_new = analogRead(PIN_MOIST_SENSOR1);
    else if(i == 1)      
      u_new = analogRead(PIN_MOIST_SENSOR2);
    else   
      u_new = analogRead(PIN_MOIST_SENSOR3);

    moist_sens_filt[i] = (1-cFilt) * u_new + cFilt * moist_sens_filt[i];
  }
}

int read_moist_sensor1()
{  
  int value = (int)moist_sens_filt[0];
  String str = "Read moist_sensor1 = ";
  str.concat(value);
  writeLog(str);  
  return value;
}

int read_moist_sensor2()
{  
  int value = (int)moist_sens_filt[1];
  String str = "Read moist_sensor2 = ";
  str.concat(value);
  writeLog(str);  
  return value;
}

int read_moist_sensor3()
{  
  int value = (int)moist_sens_filt[2];
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

