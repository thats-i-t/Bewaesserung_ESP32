void single_auto_mode(int th_pump, int nr)
{
    int wert = read_moist_sensor(nr);
    if (wert > th_pump) 
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
    // Sensor komplett trocken in Luft: Wert ist ca. 3400
    // Sensor komplett in Wasser: Wert ist ca. 1700

    //Pump 1 
    single_auto_mode(2000,1);
    //Pump 2
    // single_auto_mode(2000,2);
    //Pump 3
    // single_auto_mode(2000,3);
}
