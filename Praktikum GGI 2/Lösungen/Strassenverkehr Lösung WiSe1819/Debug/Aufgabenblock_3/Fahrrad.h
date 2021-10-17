#pragma once
#include "Fahrzeug.h"
#include "SimuClient.h"
class Fahrrad :
	public Fahrzeug
{
public:
	Fahrrad(void);

	Fahrrad(string sName, double MaxSpeed);

	~Fahrrad();

	virtual double dGeschwindigkeit();
	virtual void vZeichnen(Weg* pWeg);

	virtual ostream& ostreamAusgabe(ostream& output);
	virtual istream& istreamEingabe(istream& input);
	
};
