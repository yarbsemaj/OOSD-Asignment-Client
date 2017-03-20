#include "Sensor.h"



//sensor construct, this is called by all sensors on creation
Sensor::Sensor(float value)
{
	this->value = value;
}

Sensor::~Sensor()
{
}

float Sensor::getValue()
{
	return value;
}

void Sensor::setValue(float value)
{
	this->value=value;
}
