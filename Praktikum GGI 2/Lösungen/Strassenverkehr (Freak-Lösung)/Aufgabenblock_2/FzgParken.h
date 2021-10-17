#pragma once
#include "fzgverhalten.h"

// Fahrzeugverhalten: parkend
class FzgParken :
	public FzgVerhalten
{
public:
	// Konstruktoren:
	FzgParken(void);
	FzgParken(Weg *wWeg, const double dStartzeitpunkt);
	// Destruktor:
	virtual ~FzgParken(void);
	// berechnet in Zeitspanne fahrbare Strecke (null, da parkend):
	double dStrecke(Fahrzeug *fFahrzeug, double dZeitspanne);
private:
	// Startzeitpunkt des Fahrzeugs
	const double p_dStartzeitpunkt;
};

