#pragma once
#include "Fahrzeug.h"
#include <string>

// Anlegen der Klasse PKW
class PKW : public Fahrzeug
{

public:
	//Konstruktor
    //PKW(void);
	PKW(string sName = "Karre", double dMaxGeschwindigkeit = 150, double dVerbrauch = 7.5, double dTankvolumen = 55);

	//Destruktor
	virtual ~PKW(void);

	virtual double dTanken(double dMenge);
	virtual void vAbfertigung(void);
    void PKW::vAusgabe(void);

	virtual ostream& PKW::ostreamAusgabe(ostream& Stream);

private:
    double p_dVerbrauch;
    double p_dTankinhalt;
    double p_dTankvolumen;
};


