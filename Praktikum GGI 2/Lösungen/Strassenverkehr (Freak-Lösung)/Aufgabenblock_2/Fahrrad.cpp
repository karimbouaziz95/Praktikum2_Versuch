#include "Fahrrad.h"
#include "SimuClient.h"
#include "Weg.h"

// Konstruktor:
Fahrrad::Fahrrad(void) :
	Fahrzeug()
{
}

// Konstruktor:
Fahrrad::Fahrrad(const string sName, const double dMaxGeschwindigkeit) : 
	Fahrzeug(sName, dMaxGeschwindigkeit)
{
}

// Destruktor:
Fahrrad::~Fahrrad(void)
{
}

// Abfertigungsfunktion:
void Fahrrad::vAbfertigung()
{
	Fahrzeug::vAbfertigung();
}

// Tanken:
double Fahrrad::dTanken(const double dMenge)
{
	// ein Fahrrad kann nicht getankt werden
	return 0;
}

// akt. Geschwindigkeit ermitteln (Radfahrer werden müde):
double Fahrrad::dGeschwindigkeit()
{
	// Geschwindigkeit soll pro gefahrenen 20km um 10% abnehmen
	// --> Geschwindigkeit alle 20km mit 0.9 multiplizieren
	// --> d.h. aktuelle Geschwindigkeit = max. Geschwindigkeit * 0.9 ^ (wie oft 20km)

	// wie oft wurden schon 20km gefahren?
	int iFinished20Km = int(p_dGesamtStrecke / 20);

	//berechne nun aktuelle Geschwindigkeit nach obiger Formel:
	double dAktGeschw = p_dMaxGeschwindigkeit * pow(0.9, iFinished20Km);

	if(dAktGeschw < 12)
		dAktGeschw = 12;

	return dAktGeschw;
}

void Fahrrad::vZeichnen()
{
	bZeichneFahrrad(p_sName,
		getWeg()->getName(),
		min(1., p_dAbschnittStrecke / getWeg()->getLaenge()),
		dGeschwindigkeit());
}