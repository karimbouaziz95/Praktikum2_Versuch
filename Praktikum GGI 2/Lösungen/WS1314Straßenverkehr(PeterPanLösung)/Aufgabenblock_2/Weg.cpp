#include "Weg.h"
#include "Fahrzeug.h"
#include "AktivesVO.h"
#include "FzgParken.h"
#include "FzgFahren.h"
#include "FzgVerhalten.h"
#include "PKW.h"
#include "FahrAusnahme.h"
#include "Streckenende.h"
#include "Losfahren.h"
#include "LazyListe.h"

#include <iomanip>
#include <iostream> 

int Weg::p_iMaxID = 1;

Weg::Weg(void)
{
}

Weg::Weg(string sName,double dLaenge,double eLimit)
{
	p_iID = p_iMaxID;
	p_iMaxID++;
	p_sName = sName;
	p_dLaenge = dLaenge;
	p_eLimit = eLimit;
}

Weg::~Weg(void)
{
}

//2.3 Weg Ausgabe !!!!

ostream& Weg::ostreamAusgabe(ostream& Stream)
{
	list<Fahrzeug*>::iterator Lpointer;
    AktivesVO::ostreamAusgabe(Stream);
	Stream << resetiosflags(ios::right) << setiosflags(ios::left) //vorher rechts- jetzt wieder linksbündig 
		   << setw(15) << p_dLaenge
		   << setw(2) << "(";
		   for (Lpointer=p_pFahrzeuge.begin(); Lpointer != p_pFahrzeuge.end(); ++Lpointer)
			  {
					Stream << (*Lpointer)->Fahrzeug::getName() << "  ";
			  }
		   Stream << ")" << endl;



	return Stream;
}


void Weg::vAbfertigung()
{   
		list<Fahrzeug*>::iterator Lpointer;
		for (Lpointer=p_pFahrzeuge.begin(); Lpointer != p_pFahrzeuge.end(); ++Lpointer)
			{
				try                                                            // try block soll immer ausgeführt werden
					{
						(*Lpointer)->vAbfertigung();
					}
				catch(FahrAusnahme *aktAusnahme)
					{
						aktAusnahme->vBearbeiten();                                         // catch Los/Ende
					}
			}
		p_pFahrzeuge.vAktualisieren();
}

// Annahmefunktion fahrendes Fahrzeug +++++++++++++++++++++++++++++++++++++
void Weg::vAnnahme(Fahrzeug* Fzg)
{
	Fzg->vNeueStrecke(this,new FzgFahren(this));
	p_pFahrzeuge.push_back(Fzg);
}
// Annahmefunktion parkendes Fahrzeug +++++++++++++++++++++++++++++++++++++
void Weg::vAnnahme(Fahrzeug* Fzg,double dStart)
{
	Fzg->vNeueStrecke(this,new FzgParken(this, dStart));
	p_pFahrzeuge.push_front(Fzg);
}

double Weg::GetLimit()
{
    return p_eLimit;
}

string Weg::GetName()
{
	return p_sName;
}

void Weg::vAbgabe(Fahrzeug* Fzg)
{
	list<Fahrzeug*>::iterator Lpointer;
	for (Lpointer=p_pFahrzeuge.begin(); Lpointer != p_pFahrzeuge.end(); ++Lpointer)
		{
			if( (*Lpointer) == Fzg)
			{
				p_pFahrzeuge.erase(Lpointer);
				//this->vAnnahme(Fzg);
			}
		}
}