

#define TEMPERATURE 0

class typeMod
{
	private uint8_t module = -1;

	public float lecture;
    public float setpoint;
    public float taux_variation;
    public int cycle1;
    public float setpoint1;
    public int cycle2;
    public float setpoint2;
    public uint8_t start_cycles;
    public float calib_lecture1_mV;
    public float calib_lecture1_C;
    public float calib_lecture2_mV;
    public float calib_lecture2_C;
    public float lecture_now_mV;
    public float control_range;
    public float alarms_range;
    public uint8_t alarms;
    public uint8_t operating_mode;
    public uint8_t g_operating_mode;

	typeMod(uint8_t r_module)
	{
		module = r_module;
        switch(module)
        {
            case TEMPERATURE:
            
            break;
        }
	}

    

};
