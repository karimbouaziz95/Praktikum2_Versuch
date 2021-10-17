#include <string>

#include "Fahrrad.h"
#include "Weg.h"

extern double dGlobaleZeit;


//Konstruktor
Fahrrad::Fahrrad(void)
{
}


//Konstruktor mit Namen und MaxGeschwindigkeit
Fahrrad::Fahrrad(string sName,double dMaxSpeed)
{
	p_sName = sName;
	p_dMaxGeschwindigkeit = dMaxSpeed;	
}//Anpassung der Geschwindigkeit nach 20 Km



//Destruktor
Fahrrad::~Fahrrad(void)
{
}


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


void Fahrrad::vAbfertigung()
{
	Fahrzeug::vAbfertigung();
	p_dZeit = dGlobaleZeit;
}


//Zeichnen für Fahrräder
void Fahrrad::vZeichnen(Weg* Weg)
{
	double RelPosition = p_dAbschnittStrecke/Weg->dgetlength();
	if(RelPosition > 1) {RelPosition = 1;}
	bZeichneFahrrad(p_sName, Weg->sgetName(), RelPosition, dGeschwindigkeit());
}