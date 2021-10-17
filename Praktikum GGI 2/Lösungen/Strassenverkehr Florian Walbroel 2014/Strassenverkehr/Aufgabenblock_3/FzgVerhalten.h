#pragma once

class Weg;
class Fahrzeug;

class FzgVerhalten
{
public:
	FzgVerhalten(Weg *WegPointer);
	~FzgVerhalten(void){};
	virtual double dStrecke(Fahrzeug * ptCar, double dZeit) = 0;

protected:
	Weg *p_ptWeg;
};
