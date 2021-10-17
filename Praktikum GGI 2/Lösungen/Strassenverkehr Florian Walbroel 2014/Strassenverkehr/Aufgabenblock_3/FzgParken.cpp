#pragma once
#include <iostream>

#include "Losfahren.h"
#include "FzgParken.h"
#include "FzgVerhalten.h"
#include "Fahrzeug.h"
#include "Weg.h"

using namespace std;

extern double dGlobaleZeit;

FzgParken::FzgParken(Weg * ptWay, double dStartzeitpunkt):FzgVerhalten(ptWay)
{
	p_dStartzeitpunkt = dStartzeitpunkt;
}

// Startet Fahrzeug, wenn Startzeitpunkt erreicht wird
double FzgParken::dStrecke(Fahrzeug * ptCar, double dZeit)
{
	if (p_dStartzeitpunkt > dGlobaleZeit)
	{
		return 0;
	}
	else
	{
		throw new Losfahren(ptCar, p_ptWeg);
	}
	
}