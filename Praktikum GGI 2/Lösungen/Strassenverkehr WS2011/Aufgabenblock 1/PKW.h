#pragma once
#include "Fahrzeug.h"
#include <iostream>
#include <string>
//#include "main.cpp"
using namespace std;

class PKW :
	public Fahrzeug
{
public:
	PKW(double dVerbrauch, string sName, double dMaxGeschwindigkeit, double dTankvolumen=55.0);
	~PKW(void);

	double dVerbrauch();
	virtual double dTanken(double dMenge = 0.0);
	virtual void vAbfertigung();
	virtual void vAusgabe();
	virtual double dGeschwindigkeit();
	virtual ostream& PKW::ostreamAusgabe(ostream& Stream);

private:
	double p_dVerbrauch;
	double p_dTankinhalt;
	double p_dTankvolumen;
};
