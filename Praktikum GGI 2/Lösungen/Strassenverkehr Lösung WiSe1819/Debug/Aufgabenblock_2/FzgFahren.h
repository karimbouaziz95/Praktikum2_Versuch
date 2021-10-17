#pragma once
#include "FzgVerhalten.h"
class FzgFahren :
	public FzgVerhalten
{
public:
	FzgFahren(Weg *pWeg);
	virtual ~FzgFahren();
	virtual double dStrecke(Fahrzeug *fahrzeug, double dZeitraum);
};

