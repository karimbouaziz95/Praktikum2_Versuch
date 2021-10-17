#pragma once
#include <string>
#include <iostream>

#include "Fahrzeug.h"

using namespace std;

class PKW : public Fahrzeug
{
public:
	PKW(){};
	PKW(string sName, double dMaxSpeed);
	PKW(string sName, double dMaxSpeed, double dTankVolumen, double dVerbrauch);
	~PKW(void){};
	void anlegen();
	double dVerbrauch();

	virtual void vAusgabe();
	virtual void vAbfertigung();
	virtual double dTanken(double dMenge=0.0, bool status=false); // double dMenge=0.0
	virtual ostream& PKW::ostreamAusgabe(ostream& Stream);

private:
	virtual double dGeschwindigkeit();

	double p_dVerbrauch;
	double p_dTankinhalt;
	double p_dTankvolumen;

};
