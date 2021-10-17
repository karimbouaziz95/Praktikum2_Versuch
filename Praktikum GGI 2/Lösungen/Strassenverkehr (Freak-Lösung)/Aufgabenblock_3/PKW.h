#pragma once
#include <string>
#include "fahrzeug.h"

class PKW :
	public Fahrzeug
{
public:
	// Konstruktoren:
	PKW(void);
	PKW(const string sName, const double dMaxGeschwindigkeit);
	PKW(const string sName, const double dMaxGeschwindigkeit, const double dVerbrauch, const double dTankvolumen = 55);
	PKW(const PKW&); // Copykonstruktor
	// Destruktor:
	virtual ~PKW(void);

	// Ausgabefunktionen:
	virtual void vAusgabe();
	virtual ostream& ostreamAusgabe(ostream& ostreamStream);
	// Eingabe:
	istream& istreamEingabe(istream& istreamStream);

	// Abfertigungsfunktion:
	virtual void vAbfertigung();

	// Verbrauchsfunktion (ermittelt verbrauchten Sprit):
	double dVerbrauch();							// gibt den bisherigen Gesamtverbrauch aus

	// Tanken:
	virtual double dTanken(const double dMenge = 1000);	// tankt den PKW, maximal bis der Tank voll ist, gibt die tatsächlich getanke Menge zurück
	
	// Zuweisungsoperator:
	PKW& operator=(const PKW&);

	// Getter:
	double getTankinhalt();

	// Zeichnen:
	virtual void vZeichnen();
private:
	double p_dVerbrauch;							// Verbrauch in l/100km
	double p_dTankinhalt;
	double p_dTankvolumen;
	virtual double dGeschwindigkeit();				// ermittelt aktuelle Geschwindigkeit
};

istream& operator>>(istream& istreamStream, PKW& pPKW);
