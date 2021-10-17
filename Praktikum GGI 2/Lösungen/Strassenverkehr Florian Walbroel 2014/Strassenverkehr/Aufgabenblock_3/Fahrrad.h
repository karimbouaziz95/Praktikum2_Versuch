#pragma once
#include <string>
#include <iostream>

#include "Fahrzeug.h"

using namespace std;

class Weg;

class Fahrrad : public Fahrzeug
{
public:
	Fahrrad(void){};
	~Fahrrad(void){};
	Fahrrad(string sName);
	Fahrrad(string sName, double dMaxSpeed);
	void anlegen();

	virtual void vAusgabe();
	virtual void vZeichnen(Weg* pWay) const;
	virtual double GetTankinhalt() const {return 0.0;};
	virtual ostream& ostreamAusgabe(ostream& Stream);
	virtual istream& istreamEingabe(istream& Stream);

private:
	virtual double dGeschwindigkeit() const;
};
