#pragma once
#include "FzgVerhalten.h"
#include "Weg.h"
 
class FzgFahren;

class FzgParken : public FzgVerhalten
{
public:
	FzgParken(void);
	FzgParken(Weg*, double);
	virtual ~FzgParken(void);
	double dgetstartTime();

private:
	virtual	double dStrecke(Fahrzeug* , double);
	double p_dStartzeitpunkt;
};

