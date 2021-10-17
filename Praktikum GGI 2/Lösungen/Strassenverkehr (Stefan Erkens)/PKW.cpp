#pragma once

#include "PKW.h"

PKW::PKW() : Fahrzeug()
{
	p_dTankvolumen = 55;
	p_dTankinhalt = 27.5;
	p_dVerbrauch = 5;
}

PKW::PKW(string name, double speed):Fahrzeug(name, speed)
{
	p_dTankvolumen = 55;
	p_dTankinhalt = 27.5;
	p_dVerbrauch = 5;
}


PKW::PKW(string name, double speed, double consumption, double volume = 55):Fahrzeug(name, speed)
{
	p_dTankvolumen = volume;
	p_dTankinhalt = p_dTankvolumen / 2;
	p_dVerbrauch = consumption;
}

double PKW::dVerbrauch()
{
	return (p_dGesamtStrecke * p_dVerbrauch / 100);
}

double PKW::dTanken(double dMenge)
{
	double amount;
	if(dMenge > 0.0000000001)
	{
		amount = dMenge;
		p_dTankinhalt += dMenge;
	}
	else 
	{
		amount = p_dTankvolumen - p_dTankinhalt;
		p_dTankinhalt = p_dTankvolumen;
	}
	return amount;
}

void PKW::vAbfertigung()
{
	if (p_dTankinhalt > 0)
	{
		p_dTankinhalt -= p_pVerhalten->dStrecke(this, dGlobaleZeit - p_dZeit)*p_dVerbrauch/100.0;
		if(p_dTankinhalt < 0) p_dTankinhalt = 0;
		Fahrzeug::vAbfertigung();
	}
	else
	p_dZeit = dGlobaleZeit;
}

double PKW::dGeschwindigkeit()
{
	if(this->p_pVerhalten != NULL && this->p_pVerhalten->p_pWeg != NULL)
	{
		double limit = this->p_pVerhalten->p_pWeg->getLimit();
		if(limit != 0)
		{
			if(p_dMaxGeschwindigkeit > limit)
				return limit;
		}
	}
	return p_dMaxGeschwindigkeit;
}

ostream& PKW::ostreamAusgabe(ostream& data)
{
	Fahrzeug::ostreamAusgabe(data);
	data << setiosflags(ios::fixed) << setprecision(2) << left << setw(9) << p_dGesamtStrecke * p_dVerbrauch / 100 
		<< setw(7) << p_dTankinhalt << setw(7) << dGeschwindigkeit() << setw(5) << p_dAbschnittStrecke;

	return data;
}

void PKW::vDraw(Weg* TrackPtr)
{
	bZeichnePKW(p_sName, TrackPtr->GetName(), p_dAbschnittStrecke / TrackPtr->GetLaenge(), dGeschwindigkeit(), p_dTankinhalt);
}



		

