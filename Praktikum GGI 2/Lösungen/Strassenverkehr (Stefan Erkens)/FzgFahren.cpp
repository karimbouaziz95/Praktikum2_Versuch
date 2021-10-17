#pragma once
#include "FzgFahren.h"
#include "Fahrzeug.h"
#include "Streckenende.h"

class Fahrzeug;


FzgFahren::FzgFahren(Weg* ptWay):FzgVerhalten(ptWay)
{
}


double FzgFahren::dStrecke(Fahrzeug* FzgPtr, double zeit)
{
	double result;
	result = (FzgPtr->dGeschwindigkeit()) * zeit;
	double wayLeft = p_pWeg->GetLaenge() - FzgPtr->GetAbschnittStrecke();
	if (result > wayLeft)
		result = wayLeft;

	if(wayLeft <= 0)
		throw new Streckenende(FzgPtr, p_pWeg);

	return result;
}