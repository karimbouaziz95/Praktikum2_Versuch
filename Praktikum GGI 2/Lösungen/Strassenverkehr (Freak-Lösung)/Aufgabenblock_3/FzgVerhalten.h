#pragma once

using namespace std;

class Weg;
class Fahrzeug;

// Fahrzeugverhalten: Basisklasse (abstrakt) f�r parkende und fahrende Fahrzeuge
class FzgVerhalten
{
public:
	// Konstruktoren:
	FzgVerhalten(void);
	FzgVerhalten(Weg *wWeg);
	// Destruktor:
	virtual ~FzgVerhalten(void);

	// berechnet die fahrbare Strecke:
	virtual double dStrecke(Fahrzeug *fFahrzeug, double dZeitspanne) = 0;

	// Getter:
	Weg* getWeg();
protected:
	// der Weg, auf dem das Fahrzeug f�hrt
	Weg *p_wWeg;
};

