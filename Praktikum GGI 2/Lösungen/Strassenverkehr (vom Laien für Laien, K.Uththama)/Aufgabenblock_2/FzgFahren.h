#pragma once
#include "FzgVerhalten.h"
#include "Weg.h"
class FzgParken;

class FzgFahren : public FzgVerhalten
{
public:
	FzgFahren(void);
	FzgFahren(Weg*);
	virtual ~FzgFahren(void);
	virtual	double dStrecke(Fahrzeug* , double);
	double dgetstartTime();
};

