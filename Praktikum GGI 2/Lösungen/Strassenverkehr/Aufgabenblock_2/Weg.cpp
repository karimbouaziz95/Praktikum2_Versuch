#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <list>
using namespace std;

#include "Weg.h"
#include "Fahrzeug.h"
#include "FzgParken.h"
#include "FzgFahren.h"
#include "FahrAusnahme.h"
#include "LazyListe.h"


Weg::Weg(string sName, double dLaenge, Begrenzung eLimit)
{
	p_sName = sName;
	p_dLaenge = dLaenge;
	p_eLimit = eLimit; 
}

void Weg::vAusgabe()
{
	cout.precision(2); // Auf zwei Nachkommastellen runden und immer anzeigen. (5.00)

	AktivesVO::vAusgabe();
	cout << setprecision(0)
		 << "  " << setw(10) << p_dLaenge 
		 << "  [ " ;

	LazyListe <Fahrzeug*>::iterator Lpointer;

	for(Lpointer = p_ptFahrzeuge.begin(); Lpointer != p_ptFahrzeuge.end(); ++Lpointer)
	{
		cout << (*Lpointer)->GetName() << " ";
	}
	cout << " ]" << endl;
}

void Weg::anlegen()
{
	string sName;
	double dLaenge;
	cout << endl << "********* Neuen Weg anlegen *********" << endl;
	cout << "Name  : ";
	cin >> sName;
	cout << endl << "Laenge  : ";
	cin >> dLaenge;
	cout << endl << "******* Weg angelegt (ID : " << p_iID << ") *******" << endl;

	p_sName = sName;
	p_dLaenge = dLaenge;
}

void Weg::vAbfertigung()
{
	LazyListe<Fahrzeug*>::iterator Lpointer;

	for(Lpointer = p_ptFahrzeuge.begin(); Lpointer != p_ptFahrzeuge.end(); ++Lpointer)
	{
		try
		{
			(*Lpointer)->vAbfertigung();
			(*Lpointer)->vZeichnen(this);
		}
		catch(FahrAusnahme *pAusnahme)
		{
			pAusnahme->vBearbeiten();
		}
	}

	p_ptFahrzeuge.vAktualisieren();
}

double Weg::GetLaenge() const
{
	return p_dLaenge;
}

string Weg::GetName() const
{
	return p_sName;
}


ostream& Weg::ostreamAusgabe(ostream& Stream)
{
	LazyListe<Fahrzeug*>::iterator Lpointer;
	p_ptFahrzeuge.vAktualisieren();
	AktivesVO::ostreamAusgabe(Stream) 
		 << setprecision(0)
		 << "  " << setw(10) << p_dLaenge 
		 << "  [ " ;

	for(Lpointer = p_ptFahrzeuge.begin(); Lpointer != p_ptFahrzeuge.end(); ++Lpointer)
	{
		Stream << (*Lpointer)->GetName() << " ";
	}
	Stream << " ]" << endl;
	return Stream;
}

//Fahrzeug auf Weg setzen und fahren lassen
void Weg::vAnnahme(Fahrzeug *ptCar)
{
	ptCar->vNeueStrecke(this,new FzgFahren(this));
	p_ptFahrzeuge.push_back(ptCar);
}

void Weg::vAnnahme(Fahrzeug *ptCar, double dStartzeit)
{
	ptCar->vNeueStrecke(this,new FzgParken(this, dStartzeit));
	p_ptFahrzeuge.push_front(ptCar);
}FzgFahren(this)

//Suche Fahrzeug in Liste und loesche es.
void Weg::vAbgabe(Fahrzeug *ptCar)
{
	LazyListe <Fahrzeug*>::iterator Lpointer;

	for(Lpointer = p_ptFahrzeuge.begin(); Lpointer != p_ptFahrzeuge.end(); ++Lpointer)
	{
		if((*Lpointer) == ptCar)
		{
			//Falls gefunden, loeschen und Pointer auf Ende umbiegen, dann abbrechen
			p_ptFahrzeuge.erase(Lpointer);
			break;
		}
	}
}