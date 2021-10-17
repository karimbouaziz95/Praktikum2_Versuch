// file:	Streckenende.h
// author:	xxxxxx xxxxxx (xxxxxx)
// date:	12.09.2016

#pragma once

#include "FahrAusnahme.h"

// Diese Klasse stellt eine Ausnahme, ausgelöst durch das Streckenende eines Weges, dar.
class Streckenende : public FahrAusnahme
{

public:

	// Erstellt ein Ausnahmeobjekt mit dem Zeiger auf ein Fahrzeug und einen Weg.
	Streckenende(Fahrzeug* pFahrzeug, Weg* pWeg);

	// Standard-Destruktor.
	virtual ~Streckenende();

	// Diese Funktion behandelt die Streckenende-Ausnahme.
	virtual void vBearbeiten();

};

