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
		 << "Objekt : " <<  p_pFzg->sgetName() << " ist am Ende des Weges "         << endl
		 << "Weg : "      << *p_pWeg             << "angekommen und wird geloescht !" << endl << endl;
	p_pWeg->vAbgabe(p_pFzg);
	//Umsetzen des Fahrzeugs auf zufaelligen Weg
	(p_pWeg->getzielKrz())->vUmsetzen(p_pFzg,p_pWeg);
}