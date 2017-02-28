#pragma once
#include<string>
#include"Sensor.h"
class Aircraft
{
public:
	Aircraft();
	~Aircraft();

	void update(std::string type, std::string registration, float presure, float longitude, float latitude, float speed, float altitude);

private:
	std::string type;
	std::string registration;
	Sensor presure;
	Sensor longitude;
	Sensor latitude;
	Sensor speed;
	Sensor altitude;

};

