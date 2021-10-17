#pragma once
class Fahrzeug;
class Weg;
class FzgVerhalten
{
public:
	FzgVerhalten(Weg *weg);
	virtual ~FzgVerhalten();
	virtual double dStrecke(Fahrzeug *fahrzeug, double dZeitraum) = 0;
	double dGetLimit();

protected:
	Weg *p_pWeg;
};

