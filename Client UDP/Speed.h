#pragma once
#include "Sensor.h"
class Speed :
	public Sensor
{
public:
	Speed() {};
	Speed(float value)
		: Sensor(value) {};
	void update();
	~Speed();
};

