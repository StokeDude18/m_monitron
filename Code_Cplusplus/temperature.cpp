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

string temperature::getName()
{
	return name;
}