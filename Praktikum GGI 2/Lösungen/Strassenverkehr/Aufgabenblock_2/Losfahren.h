#pragma once
#include "FahrAusnahme.h"

class Losfahren : public FahrAusnahme
{
public:
	Losfahren(Fahrzeug *pCar, Weg *pWay);
	~Losfahren(void){};

	virtual void vBearbeiten();
};
