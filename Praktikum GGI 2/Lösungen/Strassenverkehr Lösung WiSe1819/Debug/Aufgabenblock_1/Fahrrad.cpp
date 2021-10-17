#include "Fahrrad.h"
#include <iostream>
#include <string>

#include <iomanip>



Fahrrad::Fahrrad()
{
}

Fahrrad::Fahrrad(string sName, double MaxSpeed)
{
	
	p_sName = sName;
	p_dMaxGeschwindigkeit = MaxSpeed;
}


Fahrrad::~Fahrrad()
{
}


double Fahrrad::dGeschwindigkeit() {
	
	double dGeschwindigkeit = p_dMaxGeschwindigkeit;
	int n = ((int)p_dGesamtStrecke / 20);
	for (int i = 0; i < n; i++) {
		
		dGeschwindigkeit *= 0.9;
	}

	if (dGeschwindigkeit < 12)
		dGeschwindigkeit = 12;

	return dGeschwindigkeit;

}

void Fahrrad::vGetName()
{
}

void Fahrrad::vGetGeschwindigkeit()
{
}
