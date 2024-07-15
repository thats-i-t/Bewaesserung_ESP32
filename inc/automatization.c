void single_auto_mode(int th_pump, int nr)
{
    int wert = read_moist_sensor(nr);
    if (wert < th_pump) 
    {
        pump_on(nr);
    }
    else
    {
        pump_off(nr); 
    }
}

void auto_mode()
{
    //Pump 1 
    single_auto_mode(1000,1);
    //Pump 2
    single_auto_mode(1000,2);
    //Pump 3
    single_auto_mode(1000,3);
}