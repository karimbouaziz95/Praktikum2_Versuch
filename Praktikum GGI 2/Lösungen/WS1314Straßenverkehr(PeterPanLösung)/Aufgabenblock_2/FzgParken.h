#pragma once
#include "FzgVerhalten.h"
#include "Weg.h"

class FzgFahren;

class FzgParken : public FzgVerhalten
{
public:
	FzgParken(void);
	FzgParken(Weg *way, double dStart);
	virtual ~FzgParken(void);
    virtual double dStrecke(Fahrzeug* Fzg,double zeitraum);

private:
	double p_dStartzeitpunkt;
};

