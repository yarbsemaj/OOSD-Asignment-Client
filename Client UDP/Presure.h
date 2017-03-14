#pragma once
#include "Sensor.h"
class Presure :
	public Sensor
{
public:
	Presure(float value)
		: Sensor(value) {};
	Presure() {};
	void update();
	~Presure();
};

