#include "Streckenende.h"
#include "FahrAusnahme.h"
#include "Fahrzeug.h"
#include "Weg.h"




Streckenende::Streckenende(Weg* weg, Fahrzeug* fzg) : FahrAusnahme(weg,fzg)
{
}

Streckenende::~Streckenende()
{
}

void Streckenende::vBearbeiten()
{
	cout << endl << "STRECKENENDE: " << pFahrzeug->sGetName() << " erreicht Ende von " << pWeg->sGetName() << endl;

	pWeg->vAbgabe(pFahrzeug);
	
}
