#include "Presure.h"
#include <random>



void Presure::update() {
	value = value + (rand() % 2 - 1);
	if (value <= 0) value = 0;
	if (value >= 3) value = 3;
}


Presure::~Presure()
{
}
