#pragma once
#include "Sensor.h"
class Longitude :
	public Sensor
{
public:
	Longitude() {};
	Longitude(float value)
		: Sensor(value) {};
	void update();
	~Longitude();
};

