#pragma once
#include "Fahrzeug.h"
#include <string>


class PKW :
	public Fahrzeug
{
public:
	PKW(void);
	PKW(string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen = 55);
	
	virtual ~PKW(void);

	virtual void operator =(const PKW& VglFzg);
	

	virtual void vAbfertigung();
	virtual void vAusgabe(void);
	virtual double dTanken(double dMenge);
	virtual double dGeschwindigkeit();
	virtual double dGetGeschwindigkeit();
	virtual string sGetName();
	virtual ostream& ostreamAusgabe(ostream& output);


private:

	double p_dVerbrauch;
	double p_dTankinhalt;
	double p_dTankvolumen;
	double dVerbrauch();
};




