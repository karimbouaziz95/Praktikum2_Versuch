#pragma once
#include "fahrausnahme.h"

class Fahrzeug;
class Weg;

// Ausnahme-Klasse für das Streckenende (Fahrendes Fahrzeug erreicht Ende eines Weges)
class Streckenende :
	public FahrAusnahme
{
public:
	// Konstruktoren:
	Streckenende(void);
	Streckenende(Fahrzeug *fFahrzeug, Weg *wWeg);
	// Destruktor:
	virtual ~Streckenende(void);
	
	// nimmt Fahrzeug vom Weg:
	virtual void vBearbeiten();
};

