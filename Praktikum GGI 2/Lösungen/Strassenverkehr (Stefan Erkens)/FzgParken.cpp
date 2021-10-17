#pragma once

#include "FzgParken.h"
#include "Fahrzeug.h"
#include "Losfahren.h"

class Fahrzeug;

extern double dGlobaleZeit;

FzgParken::FzgParken(Weg *p_pWeg, double dStartzeitpunkt):FzgVerhalten(p_pWeg)
{
	p_dStartzeitpunkt = dStartzeitpunkt;
}


double FzgParken::dStrecke(Fahrzeug* FzgPtr, double zeit)
{
	if(dGlobaleZeit >= p_dStartzeitpunkt)
		throw new Losfahren(FzgPtr, p_pWeg);

	return 0.0;
}