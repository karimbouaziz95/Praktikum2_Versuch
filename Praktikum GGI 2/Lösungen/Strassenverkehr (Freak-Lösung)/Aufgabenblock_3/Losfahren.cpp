#include "Losfahren.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include <iostream>

using namespace std;

// Konstruktor:
Losfahren::Losfahren(void)
{
}

// Konstruktor:
Losfahren::Losfahren(Fahrzeug *fFahrzeug, Weg *wWeg) :
	FahrAusnahme(fFahrzeug, wWeg)
{
}

// Destruktor:
Losfahren::~Losfahren(void)
{
}

// Abarbeiten der Ausnahme: lässt das Fahrzeug losfahren:
void Losfahren::vBearbeiten()
{
	// nehme Fahrzeug vom Weg und setze es als fahrendes Fahrzeug wieder drauf:
	p_wWeg->vAbgabe(p_fFahrzeug);
	p_wWeg->vAnnahme(p_fFahrzeug);

	cout << endl << "Ausnahme: Losfahren, Weg und Fahrzeug:" << endl <<
		*p_wWeg << endl <<
		*p_fFahrzeug << endl << endl;
}