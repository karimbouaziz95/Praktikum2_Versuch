#pragma once

#include "Fahrrad.h"

double Fahrrad::dGeschwindigkeit()
{
	double speed = p_dMaxGeschwindigkeit;
	int temp = int (p_dGesamtStrecke / 20);
	while (temp > 0)
	{
		speed *= 0.9;
		temp --;
	}
	if (speed < 12)
		speed = 12;
	return speed;
}

void Fahrrad::vAbfertigung()
{
	Fahrzeug::vAbfertigung();
}

ostream& Fahrrad::ostreamAusgabe(ostream& data)
{
	Fahrzeug::ostreamAusgabe(data);
	data << setiosflags(ios::fixed) << setprecision(2) << left << setw(16) << " " << setw(10) << dGeschwindigkeit();

	return data;
}

void Fahrrad::vDraw(Weg* TrackPtr)
{
	bZeichneFahrrad(p_sName, TrackPtr->GetName(), p_dAbschnittStrecke / TrackPtr->GetLaenge(), dGeschwindigkeit());
}


