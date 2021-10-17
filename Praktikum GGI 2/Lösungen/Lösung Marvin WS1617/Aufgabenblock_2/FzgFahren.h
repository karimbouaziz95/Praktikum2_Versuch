// file:	FzgFahren.h
// author:	xxxxxx xxxxxx (xxxxxx)
// date:	09.09.2016

#pragma once
#include "FzgVerhalten.h"

// Diese Klasse stellt das Verhalten eines fahrenden Fahrzeuges auf einem Weg dar.
class FzgFahren : public FzgVerhalten
{

public:

	// Erstellt eine Instanz und speichert einen Zeiger auf einen Weg.
	FzgFahren(Weg* pWeg);

	// Standard-Destruktor
	virtual ~FzgFahren();

	// Diese Funktion berechnet die maximal mögliche Fahrstrecke für das Fahrzeug auf dem jeweiligen Weg.
	virtual double dStrecke(Fahrzeug* pFahrzeug, double dZeit) const;

};

