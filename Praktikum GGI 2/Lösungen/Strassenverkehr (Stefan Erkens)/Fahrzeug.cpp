#pragma once

#include "Fahrzeug.h"


Fahrzeug::Fahrzeug() : AktivesVO()
{
	vInitialisierung();
}

Fahrzeug::Fahrzeug(string name) : AktivesVO(name)
{
	vInitialisierung();
}

Fahrzeug::Fahrzeug(string name, double speed) : AktivesVO(name)
{
	vInitialisierung();
	p_dMaxGeschwindigkeit = speed;
}

void Fahrzeug::vInitialisierung()
{
	p_dMaxGeschwindigkeit = 0;
	p_dGesamtStrecke = 0;
	p_dAbschnittStrecke = 0;
	p_dGesamtZeit = 0;
	p_pVerhalten = NULL;
}

void Fahrzeug::vAbfertigung()
{
	double timeDiff = dGlobaleZeit - p_dZeit;
	if(timeDiff > 0.00000000001)
	{
		double wayLeft = this->p_pVerhalten->dStrecke(this, timeDiff);
		p_dGesamtStrecke += wayLeft;
		p_dAbschnittStrecke += wayLeft;
		p_dZeit = dGlobaleZeit;
		p_dGesamtZeit += timeDiff;
	}
}

ostream& Fahrzeug::ostreamAusgabe(ostream& data)
{
	AktivesVO::ostreamAusgabe(data);
	data << setiosflags(ios::fixed) << setprecision(2) << setw(9) << p_dMaxGeschwindigkeit << setw (11) << p_dGesamtStrecke;
	return data;
}

bool Fahrzeug::operator <(const Fahrzeug& compare)
{
	if (p_dGesamtStrecke < compare.p_dGesamtStrecke)
		return true;
	return false;
}

void Fahrzeug::operator = (const Fahrzeug& origin)
{
	p_sName = origin.p_sName + " (2)";
	p_dMaxGeschwindigkeit = origin.p_dMaxGeschwindigkeit;
	p_dGesamtStrecke = origin.p_dGesamtStrecke;
	p_dGesamtZeit = origin.p_dGesamtZeit;
	p_dZeit = origin.p_dZeit;
}

void Fahrzeug::vNeueStrecke(Weg* track)
{
	p_dAbschnittStrecke = 0;
	p_pVerhalten = new FzgFahren(track);
}


void Fahrzeug::vNeueStrecke(Weg* track, double dStartzeitpunkt)
{
	p_dAbschnittStrecke = 0;
	p_pVerhalten = new FzgParken(track, dStartzeitpunkt);
}

	