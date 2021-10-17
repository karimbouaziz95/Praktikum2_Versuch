#pragma once

#include "FzgVerhalten.h"

class Weg;
class Fahrzeug;

class FzgFahren : public FzgVerhalten
{
public:
	FzgFahren(Weg *p_pWeg);
	~FzgFahren(void){};
	virtual double dStrecke(Fahrzeug* FzgPtr, double zeit); //Errechnet die noch zur�cklegbare Strecke auf dem jew. Weg
};
