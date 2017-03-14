#pragma once
#include "Sensor.h"
class Altitude :
	public Sensor
{
public:
	Altitude() {};
	Altitude(float value)
		: Sensor(value) {};
	void update();
	~Altitude();
};

