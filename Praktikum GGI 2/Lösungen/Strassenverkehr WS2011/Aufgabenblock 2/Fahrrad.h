#pragma once
#include "Fahrzeug.h"
#include <math.h>
#include <iostream>

class Fahrrad :
	public Fahrzeug
{
public:
	Fahrrad(string sName, double dMaxGeschwindigkeit);
	~Fahrrad(void);
	virtual double dGeschwindigkeit(void);
	void vAusgabe(void);
	virtual void vZeichnen(Weg* pWeg);
	virtual ostream& Fahrrad::ostreamAusgabe(ostream& Stream);
};

