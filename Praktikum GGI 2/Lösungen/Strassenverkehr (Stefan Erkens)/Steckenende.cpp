#pragma once
#include "Streckenende.h"

class Streckenende;

Streckenende::Streckenende(Fahrzeug* FzgPtr, Weg* WegPtr)
{
	p_pWeg = WegPtr;
	p_pFzg = FzgPtr;
}


void Streckenende::vBearbeiten()
{
	cout << "Streckenende:" << endl << (*p_pWeg) << endl << (*p_pFzg) << endl << endl;
	p_pWeg->vAbgabe(p_pFzg);

}