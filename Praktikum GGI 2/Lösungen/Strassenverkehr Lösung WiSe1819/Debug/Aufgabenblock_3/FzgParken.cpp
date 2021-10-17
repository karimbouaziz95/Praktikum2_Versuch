#include "FzgParken.h"
#include "Losfahren.h"
#include <iostream>
using namespace std;


extern double dGlobaleZeit;

//Konstruktor mit aufruf von FzgVerhalten, pWeg wird gesetzt
FzgParken::FzgParken(Weg * pWeg) : FzgVerhalten(pWeg)
{

}

//Konstruktor mit aufruf von FzgVerhalten, pWeg wird gesetzt
FzgParken::FzgParken(Weg * pWeg, double dStartZeit) : FzgVerhalten(pWeg)
{
	p_dStartzeitpunkt = dStartZeit;
}

FzgParken::~FzgParken()
{
}

double FzgParken::dStrecke(Fahrzeug * fahrzeug, double dZeitraum)
{

	if (p_dStartzeitpunkt <= dGlobaleZeit)
	{
		throw Losfahren(p_pWeg, fahrzeug); //exit(2);
	}

	return 0.0;
}
