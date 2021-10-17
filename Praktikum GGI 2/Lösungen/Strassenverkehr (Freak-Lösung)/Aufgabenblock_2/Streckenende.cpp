#include "Streckenende.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include <iostream>

using namespace std;

// Konstruktor:
Streckenende::Streckenende(void)
{
}

// Konstruktor:
Streckenende::Streckenende(Fahrzeug *fFahrzeug, Weg *wWeg) :
	FahrAusnahme(fFahrzeug, wWeg)
{
}

// Destruktor:
Streckenende::~Streckenende(void)
{
}

// nimmt Fahrzeug vom Weg:
void Streckenende::vBearbeiten()
{
	p_wWeg->vAbgabe(p_fFahrzeug);

	cout << endl << "Ausnahme: Streckenende, Weg und Fahrzeug:" << endl <<
		*p_wWeg << endl <<
		*p_fFahrzeug << endl << endl;
}