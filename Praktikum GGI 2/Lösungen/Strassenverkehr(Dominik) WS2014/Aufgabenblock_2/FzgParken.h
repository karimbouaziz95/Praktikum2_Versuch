#pragma once
#include "FzgVerhalten.h"
class FzgParken :
	public FzgVerhalten
{
public:
	FzgParken();
	FzgParken(Weg*,double);
	FzgParken(Fahrzeug*, Weg*);
	virtual ~FzgParken();

	double dStrecke(Fahrzeug*,double);

private:

	double p_dStartzeitpunkt;
};

