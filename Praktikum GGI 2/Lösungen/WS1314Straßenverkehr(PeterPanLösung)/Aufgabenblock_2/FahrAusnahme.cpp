#include "FahrAusnahme.h"


FahrAusnahme::FahrAusnahme(void)
{
}

FahrAusnahme::FahrAusnahme(Fahrzeug* pFzg, Weg* pWeg)
{
	p_pFzg = pFzg;
	p_pWeg = pWeg;
}

FahrAusnahme::~FahrAusnahme(void)
{
}
