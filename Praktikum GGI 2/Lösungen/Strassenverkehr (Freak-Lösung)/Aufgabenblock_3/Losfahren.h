#pragma once
#include "fahrausnahme.h"

class Fahrzeug;
class Weg;

// Ausnahme-Klasse, wird genutzt, wenn ein parkendes Fahrzeug losfahren soll
class Losfahren :
	public FahrAusnahme
{
public:
	// Konstruktoren:
	Losfahren(void);
	Losfahren(Fahrzeug *fFahrzeug, Weg *wWeg);
	// Destruktor:
	virtual ~Losfahren(void);

	// lässt das Fahrzeug losfahren:
	virtual void vBearbeiten();
};

