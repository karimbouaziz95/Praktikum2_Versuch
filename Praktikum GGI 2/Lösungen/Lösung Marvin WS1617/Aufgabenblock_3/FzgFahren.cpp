// file:	FzgFahren.cpp
// author:	xxxxxx xxxxxx (xxxxxx)
// date:	09.09.2016

#include "FzgFahren.h"
#include "Fahrzeug.h"
#include "Streckenende.h"


FzgFahren::FzgFahren(Weg* pWeg)
	: FzgVerhalten(pWeg)
{
}

FzgFahren::~FzgFahren()
{
}

double FzgFahren::dStrecke(Fahrzeug* pFahrzeug, double dZeit) const
{
	// Strecke die das Fahrzeug mit normaler Geschwindigkeit zurücklegen würde
	double dStrecke = pFahrzeug->dGeschwindigkeit() * dZeit;

	if (bEqual(pFahrzeug->getAbschnittStrecke(), p_pWeg->getLaenge()))
	{
		throw Streckenende(pFahrzeug, p_pWeg); // Streckenende erreicht
	}
	else if (pFahrzeug->getAbschnittStrecke() + dStrecke > p_pWeg->getVirtuelleSchranke() - 1e-6)
	{
		dStrecke = p_pWeg->getVirtuelleSchranke() - pFahrzeug->getAbschnittStrecke(); // Fahrzeug darf nicht überholt werden oder Wegenede nicht überfahren werden
	}
	else
	{
		p_pWeg->setVirtuelleSchranke(pFahrzeug->getAbschnittStrecke() + dStrecke); // Fahre normale Strecke und setze die Schranke
	}

	return dStrecke;
}