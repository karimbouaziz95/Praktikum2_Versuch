#pragma once
#include "Fahrzeug.h"
#include <string>

class FzgVerhalten;

// Anlegen der Klasse PKW
class PKW : public Fahrzeug
{

public:
	//Konstruktor
    PKW(void);
	PKW(string sName , double dMaxGeschwindigkeit = 150, double dVerbrauch = 7.5, double dTankvolumen = 55);

	//Destruktor
	virtual ~PKW(void);

	virtual double dTanken(double dMenge=0);
	virtual void vAbfertigung(void);

	virtual ostream& PKW::ostreamAusgabe(ostream& Stream);
	virtual istream& PKW::istreamEingabe(istream& Stream) ;
    double dGeschwindigkeit();
	double GetTank();
	void vZeichne(Weg* way);

private:
    double p_dVerbrauch;
    double p_dTankinhalt;
    double p_dTankvolumen;

};


