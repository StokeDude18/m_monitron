#include "temperature.h"

temperature::temperature(int8_t trame[])
{
	position = trame[r_pos];
	id.b[0] = trame[r_id0];
	id.b[1] = trame[r_id1];
	id.b[2] = trame[r_id2];
	id.b[3] = trame[r_id3];
	name = "Temperature_" + id.i;
}

//temperature::temperature()



string temperature::getName()
{
	return name;
}

int8_t temperature::getPosition()
{

}

float temperature::getLecture()
{

}

float temperature::getSetpoint()
{

}

float temperature::getVarRate()
{

}


void temperature::getParams(string* pname, int8_t* pposition, float* plecture,float* psetpoint,float* ptaux_var)
{

}
