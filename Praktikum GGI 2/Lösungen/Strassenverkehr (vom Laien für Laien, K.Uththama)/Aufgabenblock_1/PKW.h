#pragma once
#include <string>
#include "Fahrzeug.h"

//Unterklasse PKW wird angelegt
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
	virtual void operator =(const PKW& VglFzg);

	//public Methoden
	virtual void vAbfertigung();
	virtual void vAusgabe(void);
	virtual double dTanken(double dMenge);
	virtual double dGeschwindigkeit();
	virtual ostream& ostreamAusgabe(ostream& output); 

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

