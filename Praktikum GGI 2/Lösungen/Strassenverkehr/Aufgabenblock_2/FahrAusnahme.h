#pragma once

class Fahrzeug;
class Weg;

class FahrAusnahme
{
public:
	FahrAusnahme(Fahrzeug* pCar, Weg* pWay);
	~FahrAusnahme(void){};

	virtual void vBearbeiten() = 0;

protected:
	Fahrzeug *p_ptFahrzeug;
	Weg *p_ptWeg;
};
