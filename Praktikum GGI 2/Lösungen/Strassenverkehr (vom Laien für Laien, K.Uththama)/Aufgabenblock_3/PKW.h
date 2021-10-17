#pragma once
#include <string>
#include "Fahrzeug.h"

//Unterklasse <Fahrzeug>
class PKW : public Fahrzeug
{
public:
	//Standardkonstruktor
	PKW(void);

	//Konstrukor
	PKW(string sName ,  double dMaxSpeed , double dVerbrauch , double dTankVol = 55);

	//Destruktor
	virtual ~PKW(void);

	//Überladen des Operators
	virtual PKW& operator =(const PKW& VglFzg);

	//public Methoden
	virtual void vAbfertigung(void);
	virtual void vAusgabe(void);
	virtual double dTanken(double dMenge = VOLLTANKEN);
	virtual double dGeschwindigkeit();
	virtual ostream& ostreamAusgabe(ostream& output); 
	virtual istream& istreamEingabe(istream& input);
	void vZeichnen(Weg*);
	double dgetTank();

private:
	//Verbrauch pro 100 Km
	double p_dVerbrauch; 
	
	//maximales Tankvolumen
	double p_dTankvolumen;
	
	//aktueller Tankfüllstand
	double p_dTankinhalt; 

	//private Methoden
	double dVerbrauch();
};

