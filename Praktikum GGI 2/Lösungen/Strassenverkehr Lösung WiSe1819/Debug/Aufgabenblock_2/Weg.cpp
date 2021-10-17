#include <string>
#include <iomanip>
#include <iostream>
#include "Weg.h"
#include "Fahrzeug.h"

#include "FzgParken.h"
#include "FzgFahren.h"
#include "FahrAusnahme.h"

Weg::Weg() : AktivesVO() //Konstruktor von AktivesVO wird mit aufgerufen für Initialisierung und ID vergabe
{
	
}

Weg::Weg(string sName, double dLaenge, double dLimit) : AktivesVO(sName)
{
	p_sName = sName;
	p_dLaenge = dLaenge;
	p_dLimit = dLimit;
}

Weg::~Weg()
{
	cout << p_sName << " ID_" << p_iID << " wird geloescht" << endl;
}

// Abfertigung aller Fahrzeuge auf diesem Weg
void Weg::vAbfertigung()
{
	list<Fahrzeug*>::iterator iterator;
	for (iterator = p_pFahrzeuge.begin(); iterator != p_pFahrzeuge.end();iterator++) {
		(*iterator)->vAbfertigung();
	}
	p_pFahrzeuge.vAktualisieren();
}

ostream & Weg::ostreamAusgabe(ostream & output)
{
	cout << setfill(' '); // Reset Fill
	output << setfill(' ');
	output << left << setw(8) << setfill(' ') << p_iID;
	output << left << setw(8) << setfill(' ') << p_sName;
	output << left << setw(3) << setfill(' ') << ":";
	output << fixed;
	output << left << setw(12) << setfill(' ') << setprecision(2) << p_dLaenge;
	output << left << setw(30) << setfill(' ') << setprecision(2) << p_dLimit;

	//Ausgabe der Fahrzeuge auf dem Weg : ( Audi Ford )
	output << " ( ";
	list<Fahrzeug*>::iterator iterator;
	for (iterator = p_pFahrzeuge.begin(); iterator != p_pFahrzeuge.end(); iterator++) {
		output << (*iterator)->sGetName() << " ";
	}
	output << ")";
	return output;
}

// FAHRENDES Fahrzeug wird übergeben und in die Liste eingefügt
void Weg::vAnnahme(Fahrzeug *fzg)
{
	fzg->vNeueStrecke(this, new FzgFahren(this)); //Neues Fahr Verhalten erzeugt
	cout << "Fahrzeug " << fzg->sGetName() << " faehrt auf " << sGetName() << endl << endl;
	p_pFahrzeuge.push_back(fzg);
	//p_pFahrzeuge.vAktualisieren();
}

// PARKENDES Fahrzeug wird übergeben
void Weg::vAnnahme(Fahrzeug * fzg, double dStartzeit)
{
	fzg->vNeueStrecke(this, new FzgParken(this, dStartzeit)); //Neues Park Verhalten erzeugt mit StartZeit
	cout << "Fahrzeug " << fzg->sGetName() << " parkt auf " << sGetName() << endl << endl;
	p_pFahrzeuge.push_front(fzg);
	//p_pFahrzeuge.vAktualisieren();
}

void Weg::vAbgabe(Fahrzeug * fzg)
{
	list<Fahrzeug*>::iterator iterator;
	for (iterator = p_pFahrzeuge.begin();iterator != p_pFahrzeuge.end();iterator++)
	{
		if (*iterator == fzg) {
			cout << "Fahrzeug " << fzg->sGetName() << " verlaesst " << sGetName() << endl;
			p_pFahrzeuge.erase(iterator);
		}
	}
}

double Weg::GetLimit()
{
	return p_dLimit;
}

double Weg::GetLaenge()
{
	return p_dLaenge;
}

string Weg::sGetName()
{
	return p_sName;
}

void Weg::vInitialisierung()
{
	/*Nur neue Variablen werden auf 0 gesetzt. 
	 Sonstige werden durch den Konstruktor von AktivesVO Gesetzt
	 -> Kein redundanter Code*/
	p_sName = "";
	p_dLaenge = 0.0;
	p_dLimit = 0.0;
}
