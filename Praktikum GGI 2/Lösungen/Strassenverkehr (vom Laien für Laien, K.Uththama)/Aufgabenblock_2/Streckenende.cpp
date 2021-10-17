#include "Streckenende.h"

//Std.Kontruktor
Streckenende::Streckenende(void)
{
}


//Destruktor
Streckenende::~Streckenende(void)
{
}


void Streckenende::vBearbeiten()
{
	cout << "Fahrausnahme : Streckenende"        << endl
		 << "Fahrzeug : " <<  p_pFzg->sgetName() << endl << "ist am Ende des Weges "
		 << "Weg : "      << *p_pWeg             << "angekommen !" << endl << endl;
	p_pWeg->vAbgabe(p_pFzg);
}