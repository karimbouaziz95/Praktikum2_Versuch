#include "Fahrrad.h"


Fahrrad::Fahrrad(string sName, double dMaxGeschwindigkeit) : Fahrzeug(sName, dMaxGeschwindigkeit)
{
}

Fahrrad::~Fahrrad(void)
{
}

double Fahrrad::dGeschwindigkeit()
{
	double dCheck = p_dMaxGeschwindigkeit*pow(0.9,floor(p_dGesamtStrecke/20)); //Geschwindigkeit nimmt um Fakor 0,1 potentiell ab
	if (dCheck > 12)														   //Geschwindigkeit darf nicht unter 12km/h sinken
		return dCheck;
	else
		return 12.0;
}

void Fahrrad::vAusgabe()
{
	Fahrzeug::vAusgabe();
	cout << endl;
}

ostream& Fahrrad::ostreamAusgabe(ostream& Stream)
{ 
	Fahrzeug::ostreamAusgabe(Stream) << endl;
	return Stream;
}

