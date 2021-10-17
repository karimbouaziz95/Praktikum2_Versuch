#pragma once
#include "Losfahren.h"

Losfahren::Losfahren(Fahrzeug* FzgPtr, Weg* WegPtr)
{
	p_pWeg = WegPtr;
	p_pFzg = FzgPtr;
}


void Losfahren::vBearbeiten()
{
	cout << "Losfahren: " << endl << (*p_pWeg) << endl << (*p_pFzg) << endl << "Startzeitpunkt: " << dGlobaleZeit << endl << endl;
	p_pWeg->vAbgabe(p_pFzg);
	p_pWeg->vAnnahme(p_pFzg);

}