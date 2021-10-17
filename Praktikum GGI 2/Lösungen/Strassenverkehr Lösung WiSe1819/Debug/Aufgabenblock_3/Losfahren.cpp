#include "Losfahren.h"
#include"FahrAusnahme.h"
#include "Fahrzeug.h"
#include "Weg.h"


Losfahren::Losfahren(Weg * weg, Fahrzeug * fzg) : FahrAusnahme(weg,fzg)
{
}


void Losfahren::vBearbeiten()
{

	cout << endl << "LOSFAHREN: "<< pFahrzeug->sGetName() << " faehrt auf " << pWeg->sGetName() << " los" << endl;

	pWeg->vAbgabe(pFahrzeug);
	pWeg->vAnnahme(pFahrzeug);
}
