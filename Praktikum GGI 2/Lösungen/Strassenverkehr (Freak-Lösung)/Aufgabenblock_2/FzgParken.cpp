#include "FzgParken.h"
#include "Losfahren.h"
#include <iostream>

extern double dGlobaleZeit;
extern bool bEqualsAbout(double d1, double d2);

// Konstruktor:
FzgParken::FzgParken(void) :
	FzgVerhalten(), p_dStartzeitpunkt(0)
{
}

// Konstruktor:
FzgParken::FzgParken(Weg *wWeg, const double dStartzeitpunkt) :
	FzgVerhalten(wWeg), p_dStartzeitpunkt(dStartzeitpunkt)
{
}

// Destruktor:
FzgParken::~FzgParken(void)
{
}

// berechnet fahrbare Strecke:
double FzgParken::dStrecke(Fahrzeug *fFahrzeug, double dZeitspanne)
{
	// überprüfe, ob das Fahrzeug nun losfahren soll:
	if(dGlobaleZeit > p_dStartzeitpunkt || bEqualsAbout(dGlobaleZeit, p_dStartzeitpunkt))
	{
		//cout << "EXIT 2";
		//exit(2);
		throw new Losfahren(fFahrzeug, p_wWeg);
	}

	// ansonsten fährt das Fahrzeug natürlich nicht (parkend!)
	return 0.0;
}