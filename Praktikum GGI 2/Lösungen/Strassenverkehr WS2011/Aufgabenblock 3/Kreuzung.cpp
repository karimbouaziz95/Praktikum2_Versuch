#include "Kreuzung.h"
#include "Weg.h"
#include "Fahrzeug.h"

extern double dGlobaleZeit;

Kreuzung::Kreuzung()
{
	vInitialisierung();
	p_dTankstelle=0.0;
}

Kreuzung::Kreuzung(string Name, double Tank)
{
	vInitialisierung();
	p_sName=Name;
	p_dTankstelle=Tank;
}


Kreuzung::~Kreuzung(void)
{
}

void Kreuzung::vInitialisierung()
{
	AktivesVO::vInitialisierung();
	p_dTankstelle=0.0;
}

void Kreuzung::vVerbinde(string sWegHin, string sWegRueck, double dWegLaenge, Kreuzung* kPoint, Begrenzung Limit, bool bUebVer)
{
	Weg* pWegH = new Weg(sWegHin, dWegLaenge, kPoint, Limit, bUebVer);
	Weg* pWegR = new Weg(sWegRueck, dWegLaenge, this, Limit, bUebVer);

	pWegH->vSetzeRueck(pWegR);
	pWegR->vSetzeRueck(pWegH);

	p_wWege.push_back(pWegH);
	kPoint->p_wWege.push_back(pWegR);
}

void Kreuzung::vTanken(Fahrzeug* Fzg)
{
	if(p_dTankstelle > 0)
	{
		p_dTankstelle -= Fzg->dTanken();
	}	
	else
	{
		p_dTankstelle = 0;	
	}
}

void Kreuzung::vAnnahme(Fahrzeug* Fzg, double count)
{
	vTanken(Fzg);
	(*p_wWege.begin())->vAnnahme(Fzg, count);
}

void Kreuzung::vAnnahme(Fahrzeug* Fzg, double count, Weg* pWeg)
{
	vTanken(Fzg);
	(*ptZufaelligerWeg(pWeg)).vAnnahme(Fzg, count);
	cout << "FAHRZEUG  : " << *Fzg << endl;
}

void Kreuzung::vAbfertigung()
{
	list<Weg*>::iterator itL;
	for (itL=p_wWege.begin() ; itL != p_wWege.end() ; itL++)
	{
		(*itL)->vAbfertigung();
	}

}

ostream& Kreuzung::ostreamAusgabe(ostream& stream) 
{
	AktivesVO::ostreamAusgabe(stream) << "Tank: " << p_dTankstelle <<endl;
	for(list<Weg*>::iterator itL = p_wWege.begin(); itL != p_wWege.end(); itL++) 
	{
		(*itL)->ostreamAusgabe(stream) << endl;
	}
	return stream;
}

Weg* Kreuzung::ptZufaelligerWeg(Weg* pWeg)
{
	cout << "UMSETZUNG :" << endl
		 << "ZEIT      : " << dGlobaleZeit << endl
		 << "KREUZUNG  : " << sGetName() << " - " << p_dTankstelle << endl
		 << "WECHSEL   : " << pWeg->sGetName() << " -> ";
	
	if(p_wWege.size()>1)
	{
		list<Weg*>::iterator itL;
		do{
			itL = p_wWege.begin();
			int rnd = rand() % p_wWege.size();
			for(int i = 0; i < rnd; i++)
				itL++;
		}while(*itL == pWeg->pGetRueckweg());

		cout << (*itL)->sGetName() << endl;
		return *itL;
	}
	else
	{
		cout << pWeg->pGetRueckweg()->sGetName() << endl;
		return pWeg->pGetRueckweg();
	}
}

istream& Kreuzung::istreamEingabe(istream& stream) 
{
	AktivesVO::istreamEingabe(stream) >> p_dTankstelle;
	return stream;
}