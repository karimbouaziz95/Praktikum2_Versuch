#include "FzgVerhalten.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include "Streckenende.h"

extern bool bEqualsAbout(double d1, double d2);

// Konstruktor:
FzgVerhalten::FzgVerhalten(void) :
	p_wWeg(NULL)
{
}

// Konstruktor:
FzgVerhalten::FzgVerhalten(Weg *wWeg) :
	p_wWeg(wWeg)
{
}

// Destruktor:
FzgVerhalten::~FzgVerhalten(void)
{
}

// berechnet fahrbare Strecke in gegebener Zeitspanne:
double FzgVerhalten::dStrecke(Fahrzeug *fFahrzeug, double dZeitspanne)
{
	// überprüfe, ob das Streckenende erreicht wurde:
	if(bEqualsAbout(fFahrzeug->getAbschnittStrecke(), p_wWeg->getLaenge()))
	{
		//cout << "EXIT 1";
		//exit(1);
		throw new Streckenende(fFahrzeug, p_wWeg);
	}

	// ansonsten berechne wie gewöhnlich:
	// s = v * t
	double dMaxStrecke = fFahrzeug->dGeschwindigkeit() * dZeitspanne;

	// fahre maximal bis zur virtuellen Schranke
	// (bei Überholverbot vorausfahrendes Fahrzeug,
	// ansonsten Wegende)
	double dSchranke = p_wWeg->getSchranke();
	if(fFahrzeug->getAbschnittStrecke() + dMaxStrecke > dSchranke)
	{
		dMaxStrecke = dSchranke - fFahrzeug->getAbschnittStrecke();
	}

	// Streckenende darf nicht überschritten werden, fahre maximal bis dorthin:
	/*
	if(fFahrzeug->getAbschnittStrecke() + dMaxStrecke > p_wWeg->getLaenge())
	{
		dMaxStrecke = p_wWeg->getLaenge() - fFahrzeug->getAbschnittStrecke();
	}
	*/

	return dMaxStrecke;
}

// Getter:
Weg* FzgVerhalten::getWeg()
{
	return p_wWeg;
}