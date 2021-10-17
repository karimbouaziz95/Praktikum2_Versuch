#pragma once
#include "FahrAusnahme.h"

class Streckenende : public FahrAusnahme
{
public:
	Streckenende(Fahrzeug *pCar, Weg *pWay);
	~Streckenende(void){};

	virtual void vBearbeiten();
};
