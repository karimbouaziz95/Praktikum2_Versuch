#include "Kreuzung.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include "AktivesVO.h"
#include "PKW.h"
#include "Fahrrad.h"

#include <iostream>
#include <ostream>
using namespace std;
#include <iomanip>

extern double dGlobaleZeit;


Kreuzung::Kreuzung(void):AktivesVO()
{
}

Kreuzung::Kreuzung(string Name,double Tankstellenvolumen):AktivesVO()
{
	p_sName = Name;
	p_dTankstelle = Tankstellenvolumen;
}

Kreuzung::~Kreuzung(void)
{
}

void Kreuzung::vVerbinde(string Hinweg, string Rueckweg, double Weglaenge, Kreuzung* Cross, double GeschwLimit, bool UeVerbot)
{
	Weg* ptWegHin;
	Weg* ptWegZurueck;

	//Neue Wege erstellen mit den verbindenen Kreuzungen
	ptWegHin = new Weg(Hinweg,Weglaenge,this,GeschwLimit,UeVerbot);
	ptWegZurueck = new Weg(Rueckweg,Weglaenge,Cross,GeschwLimit,UeVerbot);

	//Rueckwege setzen
	ptWegHin->vSetRueckweg(ptWegZurueck);
	ptWegZurueck->vSetRueckweg(ptWegHin);

	//Zu Kreuzungslisten hinzufügen
	Cross->p_pWegWege.push_back(ptWegHin);
	p_pWegWege.push_back(ptWegZurueck);
}

void Kreuzung::vTanken(Fahrzeug* Fzg)
{
	if(p_dTankstelle > 0)
	{
		p_dTankstelle -= (Fzg->dTanken());
	}
	else 
	{
		p_dTankstelle = 0;
	}
}

void Kreuzung::vAnnahme(Fahrzeug* Fzg,Weg* way ,double Start)
{
	this->vTanken(Fzg);
	Weg* neu = (ptZufaelligerWeg(way));
	neu->vAnnahme(Fzg,Start);
	cout << "Globale Zeit:"<<"\t"<<dGlobaleZeit << endl;
	cout << "Kreuzung"<< "\t" << p_sName << endl;
	cout << "Wechsel:"<< "\t" << way->GetName()<< " -> "<<neu->GetName() << endl;
	cout << "Fahrzeug:"<< "\t" << Fzg->getName() << endl;
}

void Kreuzung::vAnnahme(Fahrzeug* Fzg,double Start)
{
	this->vTanken(Fzg);
	(*(p_pWegWege.begin()))->vAnnahme(Fzg,Start);
	
}

void Kreuzung::vAbfertigung()
{
	list<Weg*>::iterator Lpointer;
	cout << this->p_sName << "*************************************************" << endl; 
	cout << endl;
		for (Lpointer=p_pWegWege.begin(); Lpointer != p_pWegWege.end(); ++Lpointer)
			{	
				cout << ((*Lpointer)->GetName()) <<"_________________" << endl;
				(*Lpointer)->vAbfertigung();
				
            }

}

Weg* Kreuzung::ptZufaelligerWeg(Weg* way)
{
	

	
	if (p_pWegWege.size()==1)
	{
		return (*p_pWegWege.begin());
	}
	else
	{
		//Zufallszahl aus Anz. Wege In p_pWegwege Suchen 
		int zzahl = (rand() % (int)p_pWegWege.size());

		list<Weg*>::iterator Lpointer;
		Lpointer = p_pWegWege.begin();
		for(int count=0; count<zzahl; ++count)
		{
			++Lpointer;
		}

		// falls rueckweg == hinweg erneut aufrufen
		if((*Lpointer) == way->GetRueckweg())
		{
			return ptZufaelligerWeg(way);			// rekursives Aufrufen von sich selbst
		}
		else
		{
			return (*Lpointer);
		}
	}
}

istream& Kreuzung::istreamEingabe(istream& Stream) 
{
	AktivesVO::istreamEingabe(Stream);
	double tank;
	Stream >> tank;
	if((double)tank==tank)
	{
		p_dTankstelle=tank;
	}
	else throw new string("Fehler bei Tankstelle!!!");
	return Stream;
}


string Kreuzung::GetName()
{
	return p_sName;
}