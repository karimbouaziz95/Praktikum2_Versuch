// file:	PKW.cpp
// author:	xxxxxx xxxxxx (xxxxxx)
// date:	26.08.2016

#include "PKW.h"

#include <algorithm>
#include <iomanip>
#include <iostream>

#include "SimuClient.h"

using namespace std;


PKW::PKW()
	: Fahrzeug(), p_dVerbrauch(0), p_dTankvolumen(0), p_dTankinhalt(0)
{
}

PKW::PKW(const PKW& rhs)
	: Fahrzeug(rhs), p_dVerbrauch(rhs.p_dVerbrauch), p_dTankvolumen(rhs.p_dTankvolumen), p_dTankinhalt(rhs.p_dTankinhalt)
{
}

PKW::PKW(const string sName, const double dMaxGeschwindigkeit, const double dVerbrauch)
	: Fahrzeug(sName, dMaxGeschwindigkeit), p_dVerbrauch(dVerbrauch), p_dTankvolumen(55), p_dTankinhalt(55.0 / 2)
{
}

PKW::PKW(const string sName, const double dMaxGeschwindigkeit, const double dVerbrauch, const double dTankvolumen)
	: Fahrzeug(sName, dMaxGeschwindigkeit), p_dVerbrauch(dVerbrauch), p_dTankvolumen(dTankvolumen), p_dTankinhalt(dTankvolumen / 2)
{
}

PKW::~PKW()
{
}

void PKW::vAusgabe() const
{
	Fahrzeug::vAusgabe();
	cout << setprecision(2) << resetiosflags(ios::left) << setiosflags(ios::right)
		<< " : " << setw(12) << dVerbrauch() << " " << setw(12) << p_dTankinhalt;
}

ostream& PKW::ostreamAusgabe(ostream& out) const
{
	Fahrzeug::ostreamAusgabe(out) << setprecision(2) << resetiosflags(ios::left) << setiosflags(ios::right)
		<< " : " << setw(12) << dVerbrauch() << " " << setw(12) << p_dTankinhalt;
	return out;
}

istream& PKW::istreamEingabe(istream& in)
{
	Fahrzeug::istreamEingabe(in) >> p_dVerbrauch >> p_dTankvolumen;
	p_dTankinhalt = p_dTankvolumen / 2;
	return in;
}

void PKW::vAbfertigung()
{
	// PKWs fahren nur, wenn Kraftstoff vorhanden ist
	if (p_dTankinhalt > 0)
	{
		double dGesamtStreckeTemp = p_dGesamtStrecke; // Streckenz?hler zwischenspeichern

		Fahrzeug::vAbfertigung(); // Fahrzeug fahren lassen

		p_dTankinhalt -= (p_dGesamtStrecke - dGesamtStreckeTemp) * p_dVerbrauch / 100; // Verbrauch nachrechnen

		if (p_dTankinhalt < 0) p_dTankinhalt = 0; // keine negativen F?llst?nde zulassen
	}
}

double PKW::dVerbrauch() const
{
	return (p_dGesamtStrecke * p_dVerbrauch / 100);
}

double PKW::dTanken(double dMenge)
{
	double dMaxTankbar = p_dTankvolumen - p_dTankinhalt;

	if ( (dMenge != -1.0) && (dMenge < dMaxTankbar) )
	{
		// Normaler Tankvorgang
		p_dTankinhalt += dMenge;
	}
	else
	{
		// Volltanken
		dMenge = dMaxTankbar;
		p_dTankinhalt = p_dTankvolumen;
	}

	return dMenge;
}

void PKW::vZeichnen(const Weg* pWeg) const
{
	double dRelPos = p_dAbschnittStrecke / pWeg->getLaenge();

	if (dRelPos < 0) dRelPos = 0;
	if (dRelPos > 1) dRelPos = 1;

	bZeichnePKW(p_sName, pWeg->getName(), dRelPos, dGeschwindigkeit(), p_dTankinhalt);
}

PKW& PKW::operator = (const PKW& rhs)
{
	Fahrzeug::operator=(rhs);
	p_dVerbrauch = rhs.p_dVerbrauch;
	p_dTankvolumen = rhs.p_dTankvolumen;
	p_dTankinhalt = rhs.p_dTankinhalt;
	return *this;
}
