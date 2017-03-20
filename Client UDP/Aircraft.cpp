#include "Aircraft.h"
#include "ClientNetwork.h"
#include <iostream>
#include "Observer.h"

Aircraft::Aircraft(char registration[7], float presure, float longitude, float latitude, float speed, float altitude)
{
	//gets data and add it to class
	memcpy(this->registration, registration, 7);
	this->presure = Presure(presure);
	this->longitude = Longitude(longitude);
	this->latitude = Latitude(latitude);
	this->speed = Speed(speed);
	this->altitude = Altitude(altitude);
	//creates observer vector
	observers.push_back(new ClientNetwork);
}


Aircraft::~Aircraft()
{
}

void Aircraft::update()
{
	//updates all sensors
	this->presure.update();
	this->longitude.update();
	this->latitude.update();
	this->speed.update();
	this->altitude.update();
	//updates all observers
	for (std::vector<Observer*>::iterator it = observers.begin(); it != observers.end(); ++it)
		(*it)->update(*this);

}
