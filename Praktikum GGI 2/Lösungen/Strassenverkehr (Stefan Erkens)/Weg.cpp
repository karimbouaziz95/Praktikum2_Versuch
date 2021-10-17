#include "Weg.h"
#include "FahrAusnahme.h"

class Fahrzeug;

Weg::Weg() : AktivesVO()
{
	p_dLaenge = 0;
	p_eLimit = Autobahn;
}

Weg::Weg(string name, double length, double limit) : AktivesVO(name)
{
	p_dLaenge = length;
	p_eLimit = limit;
}

void Weg::vAbfertigung()
{
	list<Fahrzeug*>::iterator iter;
	for( iter = p_pFahrzeuge.begin(); iter != p_pFahrzeuge.end(); iter++ ) 
	{
		try
		{
			(*iter)->vAbfertigung();
			(*iter)->vDraw(this);
		}
		catch (FahrAusnahme* pException)
		{
			pException->vBearbeiten();
			delete pException;
		}
	}
	p_pFahrzeuge.vAktualisieren();
}

ostream& Weg::ostreamAusgabe(ostream& data)
{
	AktivesVO::ostreamAusgabe(data);
	data << setiosflags(ios::fixed) << setprecision(2) << setw(13) << p_dLaenge << "   ( ";
	list<Fahrzeug*>::iterator iter;
	for( iter = p_pFahrzeuge.begin(); iter != p_pFahrzeuge.end(); iter++ ) 
	{
		cout << (*iter)->GetName() << " ";
	} 
	cout << ")";
	return data;
}

void Weg::vAnnahme(Fahrzeug* vhc)
{
	vhc->vNeueStrecke(this);
	p_pFahrzeuge.push_back(vhc);
}

void Weg::vAnnahme(Fahrzeug* vhc, double dStartzeitpunkt)
{
	vhc->vNeueStrecke(this, dStartzeitpunkt);
	p_pFahrzeuge.push_front(vhc);
}

void Weg::vAbgabe(Fahrzeug* vhc)
{
	list<Fahrzeug*>::iterator iter;
	for( iter = p_pFahrzeuge.begin(); iter != p_pFahrzeuge.end(); iter++ ) 
	{
		if(*iter == vhc)
		{
			(*iter)->ClearBehaviour();
			p_pFahrzeuge.erase(iter);
		}
	}
}
	
