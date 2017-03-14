#pragma once
class Sensor
{
public:
	Sensor() {}
	Sensor(float value);
	~Sensor();
	float getValue();
	void setValue(float value);
	virtual void update() = 0 {};
protected:
	float value;
};

