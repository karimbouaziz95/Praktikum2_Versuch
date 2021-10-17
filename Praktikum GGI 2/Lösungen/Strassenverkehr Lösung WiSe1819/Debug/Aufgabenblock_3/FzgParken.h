#pragma once
#include "FzgVerhalten.h"
class FzgParken :
	public FzgVerhalten
{
public:
	FzgParken(Weg *pWeg);
	FzgParken(Weg *pWeg, double dStartZeit);
	virtual ~FzgParken();
	virtual double dStrecke(Fahrzeug *fahrzeug, double dZeitraum);

private:
	double p_dStartzeitpunkt;
};

