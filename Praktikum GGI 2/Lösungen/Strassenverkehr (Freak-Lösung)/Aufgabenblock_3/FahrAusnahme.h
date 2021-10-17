#pragma once

class Fahrzeug;
class Weg;

// Basisklasse (abstrakt) für die zwei Ausnahmen Losfahren und Streckenende
class FahrAusnahme
{
public:
	// Konstruktor:
	FahrAusnahme(void);
	FahrAusnahme(Fahrzeug *fFahrzeug, Weg *wWeg);
	// Destruktor:
	virtual ~FahrAusnahme(void);
	
	// Funktion zum Abarbeiten der Ausnahme:
	virtual void vBearbeiten() = 0;
protected:
	Fahrzeug *p_fFahrzeug;	// das Fahrzeug, bei dem die Ausnahme auftrat
	Weg *p_wWeg;			// der Weg, auf dem sich das Fahrzeug gerade befand
};

