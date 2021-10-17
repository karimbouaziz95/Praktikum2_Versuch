#pragma once

#include "FzgVerhalten.h"

class Weg;
class Fahrzeug;

class FzgParken : public FzgVerhalten
{
public:
	FzgParken(Weg *p_pWeg, double dStartzeitpunkt);
	~FzgParken(){};
	virtual double dStrecke(Fahrzeug* FzgPtr, double zeit); //Liefert bis zum Start 0 zurück, erzeugt sonst eine Exception

protected:
	double p_dStartzeitpunkt;
};
