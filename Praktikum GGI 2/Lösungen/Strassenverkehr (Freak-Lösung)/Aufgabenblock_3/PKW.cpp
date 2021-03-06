#include "PKW.h"
#include "FzgVerhalten.h"
#include "Weg.h"
#include "SimuClient.h"

extern bool bEqualsAbout(double d1, double d2);

// Konstruktor:
PKW::PKW(void) : 
	Fahrzeug()
{
}

// Konstruktor:
PKW::PKW(const string sName, const double dMaxGeschwindigkeit) :
	Fahrzeug(sName, dMaxGeschwindigkeit), p_dVerbrauch(7), p_dTankvolumen(55), p_dTankinhalt(55 / 2)
{
}

// Konstruktor:
PKW::PKW(const string sName, const double dMaxGeschwindigkeit, const double dVerbrauch, const double dTankvolumen) :
	Fahrzeug(sName, dMaxGeschwindigkeit), p_dVerbrauch(dVerbrauch), p_dTankvolumen(dTankvolumen), p_dTankinhalt(dTankvolumen / 2)
{
}

// Copykonstruktor:
PKW::PKW(const PKW& p) :
	Fahrzeug(p),
	p_dVerbrauch(p.p_dVerbrauch),
	p_dTankvolumen(p.p_dTankvolumen),
	p_dTankinhalt(p.p_dTankinhalt)
{
}

// Zuweisungsoperator:
PKW& PKW::operator=(const PKW& p)
{
	Fahrzeug::operator=(p);
	p_dVerbrauch = p.p_dVerbrauch;
	p_dTankvolumen = p.p_dTankvolumen;
	p_dTankinhalt = p.p_dTankinhalt;

	return *this;
}

// Destruktor:
PKW::~PKW(void)
{
}

// Getter:
double PKW::getTankinhalt()
{
	return p_dTankinhalt;
}

// Abfertigungsfunktion:
void PKW::vAbfertigung()
{
	// nur Abfertigen, falls Sprit im Tank!
	if(p_dTankinhalt > 0)
	{
		// Gesamtstrecke merken
		double dGesamtStreckeTmp = p_dGesamtStrecke;
		// Funktion der Basisklasse aufrufen
		Fahrzeug::vAbfertigung();
		// verbrauchten Sprit berechnen
		p_dTankinhalt -= p_dVerbrauch / 100 * (p_dGesamtStrecke - dGesamtStreckeTmp);

		if(p_dTankinhalt < 0) 
			p_dTankinhalt = 0;
	}

}

// Gesamtverbrauch:
double PKW::dVerbrauch()
{
	// gibt den Gesamtverbrauch in Litern zur?ck
	return p_dVerbrauch / 100 * p_dGesamtStrecke;
}

// Tanken:
double PKW::dTanken(const double dMenge)
{
	// ?berpr?fe, wie viel maximal getankt werden kann:
	double dTankbareMenge = p_dTankvolumen - p_dTankinhalt;

	// passt die angeforderte Menge rein?
	if(dMenge > dTankbareMenge)
	{
		p_dTankinhalt = p_dTankvolumen;
		cout << "Fahrzeug " + p_sName + " getankt mit " + to_string(dTankbareMenge) + " Litern." << endl;
		return dTankbareMenge;
	}
	else
	{
		p_dTankinhalt += dMenge;
		cout << "Fahrzeug " + p_sName + " getankt mit " + to_string(dMenge) + " Litern." << endl;
		return dMenge;
	}
}

// akt. Geschwindigkeit ermitteln:
double PKW::dGeschwindigkeit()
{
	if(p_pVerhalten == NULL) return p_dMaxGeschwindigkeit;

	if(p_pVerhalten->getWeg()->getLimit() < p_dMaxGeschwindigkeit && p_pVerhalten->getWeg()->getLimit() > -1)
		return p_pVerhalten->getWeg()->getLimit();
	else
		return p_dMaxGeschwindigkeit;
}

// alte Ausgabefunktion:
void PKW::vAusgabe()
{
	Fahrzeug::vAusgabe();
	cout << "   " <<
		setw(10) << p_dTankinhalt << "  " <<
		setw(12) << dVerbrauch();
}

// neue Ausgabefunktion mit ostream:
ostream& PKW::ostreamAusgabe(ostream& ostreamStream)
{
	Fahrzeug::ostreamAusgabe(ostreamStream) << 
		"   " <<
		setw(10) << p_dTankinhalt << "  " <<
		setw(12) << dVerbrauch();
	return ostreamStream;
}

// Eingabe:
istream& PKW::istreamEingabe(istream& istreamStream)
{
    Fahrzeug::istreamEingabe(istreamStream);
    istreamStream >> p_dVerbrauch;
    istreamStream >> p_dTankvolumen;
    p_dTankinhalt = p_dTankvolumen/2;
    return istreamStream;
}

// Zeichnen:
void PKW::vZeichnen()
{
	Weg* wWeg = p_pVerhalten->getWeg();
	bZeichnePKW(p_sName, 
				wWeg->getName(), 
				min(1., p_dAbschnittStrecke / wWeg->getLaenge()), 
				dGeschwindigkeit(), 
				p_dTankinhalt);
}

// Eingabeoperator:
istream& operator>>(istream& istreamStream, PKW& pPKW)
{
    return pPKW.istreamEingabe(istreamStream);
}