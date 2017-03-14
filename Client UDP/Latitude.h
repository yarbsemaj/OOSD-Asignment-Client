#pragma once
#include "Sensor.h"
class Latitude :
	public Sensor
{
public:
	Latitude() {};
	Latitude(float value)
		: Sensor(value) {};
	void update();
	~Latitude();
};

