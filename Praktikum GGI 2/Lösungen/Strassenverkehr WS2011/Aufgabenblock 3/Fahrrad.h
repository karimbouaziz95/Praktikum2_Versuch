#pragma once
#include "Fahrzeug.h"
#include <math.h>
#include <iostream>

class Fahrrad :
	public Fahrzeug
{
public:
	Fahrrad();
	Fahrrad(string sName, double dMaxGeschwindigkeit = 0.0);
	~Fahrrad(void);
	virtual double dGeschwindigkeit(void);
	void vAusgabe(void);
	virtual void vZeichnen(Weg* pWeg);
	virtual ostream& ostreamAusgabe(ostream& Stream);
	virtual istream& istreamEingabe(istream& stream);
};

