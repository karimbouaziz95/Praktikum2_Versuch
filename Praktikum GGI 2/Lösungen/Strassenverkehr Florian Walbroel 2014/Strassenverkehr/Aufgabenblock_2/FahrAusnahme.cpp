#include "FahrAusnahme.h"
#include "Fahrzeug.h"
#include "Weg.h"

FahrAusnahme::FahrAusnahme(Fahrzeug* pCar, Weg* pWay)
{
	p_ptFahrzeug = pCar;
	p_ptWeg = pWay;
}
