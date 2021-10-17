#include "Losfahren.h"
#include "Fahrzeug.h"
#include "Weg.h"

#include <iostream>
using namespace std;

Losfahren::Losfahren(void)
{
}


Losfahren::~Losfahren(void)
{
}

void Losfahren::vBearbeiten()
{
	cout <<"Bitte "<<p_pFzg->getName() <<" auf "<< p_pWeg->GetName() << " losfahren !!" << endl;
	p_pWeg->vAbgabe(p_pFzg);
    p_pWeg->vAnnahme(p_pFzg);
}

 