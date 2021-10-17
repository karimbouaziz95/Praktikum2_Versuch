#pragma once

#include "FzgVerhalten.h"

class Weg;
class Fahrzeug;

class FzgParken : public FzgVerhalten
{
public:
	FzgParken(Weg * ptWay, double dStartzeitpunkt);
	~FzgParken(void){};
	virtual double dStrecke(Fahrzeug *ptCar, double dZeit);

protected:
	double p_dStartzeitpunkt;
};
