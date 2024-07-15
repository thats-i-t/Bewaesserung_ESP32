// Funktionen die du benutzen kannst:
//----------------------------------------
// PUMP1_ON;
// PUMP1_OFF;
// PUMP2_ON;
// PUMP2_OFF;
// PUMP3_ON;
// PUMP3_OFF;
// int wert_1 = read_moist_sensor1();
// int wert_2 = read_moist_sensor2();
// int wert_3 = read_moist_sensor3();

float waterInLiter = 1;

void single_auto_mode(
    int th_pump,
    int nr
    )
{
    int wert = read_moist_sensor(nr);
    char str_pump = nr;
    if (wert < th_pump) 
    {
        printf("Pumpe "+str_pump+" EIN\n");
        pump_on(nr);
    }
    else
    {
        printf("Pumpe "+str_pump+" OFF\n");
        pump_off(nr); 
    }
}

void auto_mode(){
    //Pump 1 
    single_auto_mode(1000,1);
    //Pump 2
    single_auto_mode(1000,2);
    //Pump 3
    single_auto_mode(1000,3);

}