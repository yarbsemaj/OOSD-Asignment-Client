#include "Observer.h"
#include "Aircraft.h"

Observer::Observer()
{
	observers = ClientNetwork();
	observers.start();
}


Observer::~Observer()
{
}

void Observer::update(Aircraft  aircraft)
{
	observers.update(aircraft);
	}
