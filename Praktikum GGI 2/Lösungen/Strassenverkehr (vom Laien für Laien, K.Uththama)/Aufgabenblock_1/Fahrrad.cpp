#include <string>

#include "Fahrrad.h"


//Konstruktor
Fahrrad::Fahrrad(void)
{
}


//Konstruktor mit Namen und MaxGeschwindigkeit
Fahrrad::Fahrrad(string sName,double dMaxSpeed)
{
	p_sName = sName;
	p_dMaxGeschwindigkeit = dMaxSpeed;	
}


//Destruktor
Fahrrad::~Fahrrad(void)
{
}


//Anpassung der Geschwindigkeit nach 20 Km
double Fahrrad::dGeschwindigkeit()
{ 
	double dGesamtStrecke = p_dGesamtStrecke;
	double dAktGeschwindigkeit = p_dMaxGeschwindigkeit;
	
	while (dGesamtStrecke >= 20)
	{ 
		dAktGeschwindigkeit = dAktGeschwindigkeit*0.9;
		dGesamtStrecke -= 20;
	}

	if (dAktGeschwindigkeit < 12)
	{
		dAktGeschwindigkeit = 12;
	}

	return dAktGeschwindigkeit;
}