#ifndef PKW_H
#define PKW_H
#pragma once
#include "Fahrzeug.h"
#include <sstream>

extern double dGlobaleZeit;
class PKW :
	public Fahrzeug
{
public:
	//Konstruktoren
	PKW();
	PKW(string, double, double);
	PKW(string, double, double,double);


	//Destruktor
	virtual ~PKW();

	double dVerbrauch(double);
	double dTanken(double=-1.0);

	void vAbfertigung();

	//Ueberladungen
	ostream& ostreamAusgabe(ostream&);
	void PKW:: operator =(PKW&);

private:	
	double p_dVerbrauch;
	double p_dTankinhalt;
	double p_dTankvolumen;
	double p_dGesamtverbrauch;


	double dGeschwindigkeit();
};

#endif