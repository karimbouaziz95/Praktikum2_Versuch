#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

#include "Losfahren.h"
#include "Fahrzeug.h"
#include "Weg.h"

Losfahren::Losfahren(Fahrzeug *pCar, Weg *pWay) : FahrAusnahme(pCar, pWay)
{
}

void Losfahren::vBearbeiten()
{
	cout << endl << resetiosflags(ios::right) << setiosflags(ios::left) // wieder linksbündig
		<< "Fahrzeug : " << setw(12) << p_ptFahrzeug->GetName() << " - Weg : " << setw(12) << p_ptWeg->GetName() << " - Grund : Losfahren." <<  endl << endl;
	p_ptWeg->vAbgabe(p_ptFahrzeug);
	p_ptWeg->vAnnahme(p_ptFahrzeug);
}
