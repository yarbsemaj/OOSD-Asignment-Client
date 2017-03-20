#pragma once
#include <vector>
//forward declaration of aircraft
//fixes circular includes
class Aircraft;

class Observer
{
public:
	Observer();
	~Observer();
	virtual void update(Aircraft  & aircraft) = 0 {};
};

