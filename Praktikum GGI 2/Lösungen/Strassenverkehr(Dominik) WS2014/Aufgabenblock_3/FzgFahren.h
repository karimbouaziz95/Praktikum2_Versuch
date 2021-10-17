#pragma once
#include "FzgVerhalten.h"
class FzgFahren :
	public FzgVerhalten
{
public:
	FzgFahren();
	FzgFahren(Weg*);
	virtual ~FzgFahren();


	double dStrecke(Fahrzeug*,double);
};

