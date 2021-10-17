#include "FahrAusnahme.h"
#include "Fahrzeug.h"
#include "Weg.h"



FahrAusnahme::FahrAusnahme(Weg *weg, Fahrzeug *fzg)
{
	pWeg = weg;
	pFahrzeug = fzg;
}


FahrAusnahme::~FahrAusnahme()
{
}
