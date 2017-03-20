#pragma once
class Sensor
{
public:
	Sensor() {}
	Sensor(float value);
	~Sensor();
	float getValue();
	void setValue(float value);
	//This update methord is overwriten by all atached sensors
	virtual void update() = 0 {};
protected:
	float value;
};

