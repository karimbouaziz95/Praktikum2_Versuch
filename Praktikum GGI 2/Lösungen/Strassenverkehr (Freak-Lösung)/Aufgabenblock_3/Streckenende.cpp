#include "Streckenende.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include "Kreuzung.h"
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
	p_wWeg->getZiel()->vAnnahme(p_fFahrzeug, p_wWeg);

	/*cout << endl << "Ausnahme: Streckenende, Weg und Fahrzeug:" << endl <<
		*p_wWeg << endl <<
		*p_fFahrzeug << endl << endl;*/

	cout << "=== STRECKENENDE ===" << endl
		 << "ZEIT        : " << dGlobaleZeit << endl
		 << "KREUZUNG    : " << p_wWeg->getZiel()->getName() << ", " << p_wWeg->getZiel()->getTankstelle() << "L" << endl
		 << "WECHSEL     : " << p_wWeg->getName() << " -> " << p_fFahrzeug->getWeg()->getName() << endl
		 << "FAHRZEUG    : " << endl << *p_fFahrzeug << endl;
}