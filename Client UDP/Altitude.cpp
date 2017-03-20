#pragma once
#include "Altitude.h"




void Altitude::update() {
	if (value < 38000) {
		value = value + 500;
	}
}

Altitude::~Altitude()
{
}
