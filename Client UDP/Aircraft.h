#pragma once
#include<string>
#include"Sensor.h"
#include "Observer.h"
#include "Longitude.h"
#include "Latitude.h"
#include "Speed.h"
#include "Altitude.h"
#include "Presure.h"
class Aircraft
{
public:
	Aircraft(char registration[7], float presure, float longitude, float latitude, float speed, float altitude);
	~Aircraft();

	void update();

	char registration [7];
	Presure presure;
	Longitude longitude;
	Latitude latitude;
	Speed speed;
	Altitude altitude;
	Observer observer;

};

