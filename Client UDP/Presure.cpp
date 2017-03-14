#include "Presure.h"
#include <random>



void Presure::update() {
	value = value + (rand() % 2 - 1);
}


Presure::~Presure()
{
}
