#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

#include "Streckenende.h"
#include "Fahrzeug.h"
#include "Weg.h"

Streckenende::Streckenende(Fahrzeug *pCar, Weg *pWay) : FahrAusnahme(pCar, pWay)
{
}

void Streckenende::vBearbeiten()
{
	cout << endl << resetiosflags(ios::right) << setiosflags(ios::left) // wieder linksbündig
		<< "Fahrzeug : " << setw(12) << p_ptFahrzeug->GetName() << " - Weg : " << setw(12) << p_ptWeg->GetName() << " - Grund : Streckenende." <<  endl << endl;

	p_ptWeg->vAbgabe(p_ptFahrzeug);
	//p_ptWeg->getKreuzung()->vAnnahme(p_ptFahrzeug, 0.0);
}
