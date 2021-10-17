// file:	FzgVerhalten.h
// author:	xxxxxx xxxxxx (xxxxxx)
// date:	08.09.2016

#pragma once

#include "Weg.h"

// Diese Klasse stellt das Verhalten eines Fahrzeuges auf einem Weg dar.
class FzgVerhalten
{

public:
	
	// Erstellt eine Instanz und speichert einen Zeiger auf einen Weg.
	FzgVerhalten(Weg* pWeg);

	// Standard-Destruktor.
	virtual ~FzgVerhalten();

	// Diese Funktion berechnet die maximal mögliche Fahrstrecke für das Fahrzeug auf dem jeweiligen Weg.
	virtual double dStrecke(Fahrzeug* pFahrzeug, double dZeit) const = 0;

	// Diese Funktion gibt die Geschwindigkeitsbeschränkung auf dem aktuellen Weg zurück.
	double dGeschwindigkeitslimit();

protected:

	// Zeiger auf eine Weg-Instanz von dem das FzgVerhalten abhängt.
	Weg* p_pWeg;

};

