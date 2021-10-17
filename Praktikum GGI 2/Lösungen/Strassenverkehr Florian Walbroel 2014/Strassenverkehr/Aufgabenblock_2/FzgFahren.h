#pragma once

#include "FzgVerhalten.h"

class Weg;
class Fahrzeug;

class FzgFahren : public FzgVerhalten
{
public:
	FzgFahren(Weg * ptWay);
	~FzgFahren(void){};
	virtual double dStrecke(Fahrzeug *ptCar, double dZeit);
};
