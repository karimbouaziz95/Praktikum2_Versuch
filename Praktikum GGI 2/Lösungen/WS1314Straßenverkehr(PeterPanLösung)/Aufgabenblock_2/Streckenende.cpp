#include "Streckenende.h"
#include "Fahrzeug.h"
#include "Weg.h"

#include <iostream>
using namespace std;


Streckenende::Streckenende(void)
{
}


Streckenende::~Streckenende(void)
{
}

void Streckenende::vBearbeiten()
{
	cout << "Ey "<< p_pFzg->getName() <<" auf "<< p_pWeg->GetName() << " Stopp" << endl;
	p_pWeg->vAbgabe(p_pFzg);
}
