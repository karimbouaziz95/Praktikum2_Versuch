#pragma once
#include <string>
#include <iostream>

#include "Fahrzeug.h"

using namespace std;

class PKW : public Fahrzeug
{
public:
	PKW(){};
	PKW(string sName);
	PKW(string sName, double dMaxSpeed);
	PKW(string sName, double dMaxSpeed, double dTankVolumen, double dVerbrauch);
	~PKW(void){};
	void anlegen();
	double dVerbrauch();
	virtual double GetTankinhalt() const;

	virtual void vAusgabe();
	virtual void vAbfertigung();
	virtual double dGeschwindigkeit() const;
	virtual double dTanken(double dMenge=0.0, bool status=false); // double dMenge=0.0
	virtual void vZeichnen(Weg* pWay) const;
	virtual ostream& ostreamAusgabe(ostream& Stream); 
	virtual istream& istreamEingabe(istream& Stream);

private:
	double p_dVerbrauch;
	double p_dTankinhalt;
	double p_dTankvolumen;

};