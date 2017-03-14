#include "Speed.h"
#include <random>




void Speed::update() {
	value = value + (rand() % 20 - 10);
}

Speed::~Speed()
{
}
