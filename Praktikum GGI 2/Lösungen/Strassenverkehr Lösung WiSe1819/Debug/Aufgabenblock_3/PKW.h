#pragma once
#include "Fahrzeug.h"
#include "SimuClient.h"
#include <string>


class PKW :
	public Fahrzeug
{
public:
	PKW(void);
	PKW(string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen = 55);
	
	virtual ~PKW(void);

	virtual void operator =(const PKW& VglFzg);
	

	void vAbfertigung();
	void vAusgabe(void);
	double dTanken(double dMenge);
	double dGeschwindigkeit();
	double dGetGeschwindigkeit();
	string sGetName();
	virtual ostream& ostreamAusgabe(ostream& output);
	virtual istream& istreamEingabe(istream& input);
	bool bKannFahren();
	virtual void vZeichnen(Weg* pWeg);


private:

	double p_dVerbrauch;
	double p_dTankinhalt;
	double p_dTankvolumen;
	double dVerbrauch();
};




