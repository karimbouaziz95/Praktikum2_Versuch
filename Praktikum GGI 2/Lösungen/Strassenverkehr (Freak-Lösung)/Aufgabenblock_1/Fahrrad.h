#pragma once
#include "Fahrzeug.h"
class Fahrrad :
	public Fahrzeug
{
public:
	// Konstruktoren:
	Fahrrad(void);
	Fahrrad(const string sName, const double dMaxGeschwindigkeit);
	// Destruktor:
	virtual ~Fahrrad(void);
	
	// Abfertigungsfunktion:
	virtual void vAbfertigung();

	// Tanken (gibt null zurück, da Fahrrad!):
	virtual double dTanken(const double dMenge = 1000);
private:
	// akt. Geschwindigkeit ermitteln:
	virtual double dGeschwindigkeit();
};