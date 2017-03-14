#pragma once
#include <vector>
#include "ClientNetwork.h"

class Observer
{
public:
	Observer();
	~Observer();
	void update(Aircraft  aircraft);
	ClientNetwork observers;
};

