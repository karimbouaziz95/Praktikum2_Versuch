#include "FahrAusnahme.h"



//Standardkostruktor
FahrAusnahme::FahrAusnahme(void)
{
}


//Konstruktor mit Zeiger auf Weg und Fahrzeug
FahrAusnahme::FahrAusnahme(Weg* Weg, Fahrzeug* Fzg)
{
	p_pWeg = Weg;
	p_pFzg = Fzg;
}


//Destruktor
FahrAusnahme::~FahrAusnahme(void)
{
}
