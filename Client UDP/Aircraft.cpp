#include "Aircraft.h"



Aircraft::Aircraft()
{
	presure = Sensor();
	longitude = Sensor();
	latitude = Sensor();
	speed = Sensor();
	altitude = Sensor();
}




Aircraft::~Aircraft()
{
}

void Aircraft::update(std::string type, std::string registration, float presure, float longitude, float latitude, float speed, float altitude)
{
	this->type = type;
	this->registration = registration;
	this->presure.setValue(presure);
	this->longitude.setValue(longitude);
	this->latitude.setValue(latitude);
	this->speed.setValue(speed);
	this->altitude.setValue(altitude);
}
