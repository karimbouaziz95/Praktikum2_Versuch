#pragma once
#include "fzgverhalten.h"

// Fahrzeugverhalten: fahrend
class FzgFahren :
	public FzgVerhalten
{
public:
	// Konstruktoren:
	FzgFahren(void);
	FzgFahren(Weg *wWeg);
	// Destruktor:
	virtual ~FzgFahren(void);
	
	// berechnet fahrbare Strecke:
	virtual double dStrecke(Fahrzeug *fFahrzeug, double dZeitspanne);
};

