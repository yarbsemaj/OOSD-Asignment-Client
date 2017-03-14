#include "Aircraft.h"
#include <iostream>

Aircraft::Aircraft(char registration[7], float presure, float longitude, float latitude, float speed, float altitude)
{
	memcpy(this->registration, registration, 7);
	this->presure = Presure(presure);
	this->longitude = Longitude(longitude);
	this->latitude = Latitude(latitude);
	this->speed = Speed(speed);
	this->altitude = Altitude(altitude);
	observer = Observer();
}


Aircraft::~Aircraft()
{
}

void Aircraft::update()
{
	//std::cout << this->registration;
	this->presure.update();
	this->longitude.update();
	this->latitude.update();
	this->speed.update();
	this->altitude.update();
	observer.update(*this);
}
