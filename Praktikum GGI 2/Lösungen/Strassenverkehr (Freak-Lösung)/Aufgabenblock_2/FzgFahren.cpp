#include "FzgFahren.h"

// Konstruktor:
FzgFahren::FzgFahren(void) :
	FzgVerhalten()
{
}

// Konstruktor:
FzgFahren::FzgFahren(Weg *wWeg) :
	FzgVerhalten(wWeg)
{
}

// Destruktor:
FzgFahren::~FzgFahren(void)
{
}

// berechnet fahrbare Strecke in gegebener Zeitspanne:
double FzgFahren::dStrecke(Fahrzeug *fFahrzeug, double dZeitspanne)
{
	return FzgVerhalten::dStrecke(fFahrzeug, dZeitspanne);
}