#include "FahrAusnahme.h"

// Konstruktor:
FahrAusnahme::FahrAusnahme(void)
{
}

// Konstruktor:
FahrAusnahme::FahrAusnahme(Fahrzeug *fFahrzeug, Weg *wWeg) :
	p_fFahrzeug(fFahrzeug), p_wWeg(wWeg)
{
}

// Destruktor:
FahrAusnahme::~FahrAusnahme(void)
{
}
