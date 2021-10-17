#pragma once

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Fahrzeug.h"
#include "Weg.h"
#include "FzgVerhalten.h"
#include "FzgParken.h"
#include "FzgFahren.h"

extern double dGlobaleZeit;

// Standard Konstruktor
Fahrzeug::Fahrzeug():AktivesVO()
{
	vInitialisierung();
}


//Konstruktor mit übergebenem Namen
Fahrzeug::Fahrzeug(string sName):AktivesVO(sName)
{
	vInitialisierung();
}

//Konstruktor mit übergebenem Namen und MaxGeschwindigkeit
Fahrzeug::Fahrzeug(string sName, double dMaxSpeed):AktivesVO(sName)
{
	vInitialisierung();
	p_dMaxGeschwindigkeit = dMaxSpeed;
}

// Destruktor
Fahrzeug::~Fahrzeug()
{
	cout << "Fahrzeug geloescht: ID: " << p_iID << " " << endl;
}

// Initialisierung für Konstruktoren
void Fahrzeug::vInitialisierung()
{
	p_dMaxGeschwindigkeit = 0;
	p_dGesamtStrecke = 0;
	p_dGesamtZeit = 0;
	p_dZeit = 0;
	p_dAbschnittStrecke = 0;
	p_ptVerhalten = 0;

}
// Tabellarische Ausgabe der Membervariablen
void Fahrzeug::vAusgabe() const
{
	cout.precision(2); // Auf zwei Nachkommastellen runden und immer anzeigen. (5.00)

	cout << " " << resetiosflags(ios::right) << setiosflags(ios::right)
		 << setw(2) << p_iID << "    "
		 << resetiosflags(ios::right) << setiosflags(ios::left) // wieder linksbündig
		 << setw(15) << p_sName << ":  "
		 << resetiosflags(ios::left) << setiosflags(ios::right) // wieder rechtsbündig
		 << setw(8) << fixed<< p_dMaxGeschwindigkeit << "   "
		 << setw(9)<< fixed << p_dGesamtStrecke << "    "
		 << setw(9)<< fixed << p_dAbschnittStrecke;
}

// Fahrzeug faehrt mit spezieller Geschwindigkeit, p_dZeit wird aktualisiert.
void Fahrzeug::vAbfertigung()
{
	if( (dGlobaleZeit-p_dZeit) > 0) // = 0, Fall egal. < 0 (?) keine Ahnung
	{
		double dStrecke = p_ptVerhalten->dStrecke(this, (dGlobaleZeit-p_dZeit));
		p_dGesamtStrecke += dStrecke;
		p_dAbschnittStrecke += dStrecke;
		p_dZeit=dGlobaleZeit;
		p_dGesamtZeit +=(dGlobaleZeit-p_dZeit);
	}
	
}

// Rueckgabe der beschuetzten Variable MaxGeschwindigkeit
double Fahrzeug::dGeschwindigkeit() const
{
	return p_dMaxGeschwindigkeit;
}

// Rueckgabe der beschuetzten Variable AbschnittStrecke
double Fahrzeug::GetAbschnittStrecke() const
{
	return p_dAbschnittStrecke;
}

// Rueckgabe der beschuetzten Variable Name
string Fahrzeug::GetName() const
{
	return p_sName;
}

// Liefert true, falls Gesamtstrecke von this < fVergleich
bool Fahrzeug::operator <(const Fahrzeug &fVergleich)
{
	if (this->p_dGesamtStrecke < fVergleich.p_dGesamtStrecke)
		return true;
	else
		return false;
}

// Liefert true, falls Gesamtstrecke von this > fVergleich
bool Fahrzeug::operator >(const Fahrzeug &fVergleich)
{
	if (this->p_dGesamtStrecke > fVergleich.p_dGesamtStrecke)
		return true;
	else
		return false;
}

//Zuweisungsoperator zum Kopieren von Fahrzeuginstanzen
void Fahrzeug::operator =(const Fahrzeug &fVergleich)
{
	this->p_sName = fVergleich.p_sName + " Kopie";
	this->p_dMaxGeschwindigkeit = fVergleich.p_dMaxGeschwindigkeit;
	this->p_dGesamtStrecke = fVergleich.p_dGesamtStrecke;
	this->p_dAbschnittStrecke = fVergleich.p_dAbschnittStrecke;
	this->p_dGesamtZeit = fVergleich.p_dGesamtZeit;
	this->p_dZeit = fVergleich.p_dZeit;
}
//Ausgabe durch ostream
ostream& Fahrzeug::ostreamAusgabe(ostream& Stream)
{
	Stream.precision(2); // Auf zwei Nachkommastellen runden und immer anzeigen. (5.00)

	Stream << " " << resetiosflags(ios::right) << setiosflags(ios::right)
		 << setw(2) << p_iID << "    "
		 << resetiosflags(ios::right) << setiosflags(ios::left) // wieder linksbuendig
		 << setw(15) << p_sName << ":  "
		 << resetiosflags(ios::left) << setiosflags(ios::right) // wieder rechtsbuendig
		 << setw(8) << fixed<< p_dMaxGeschwindigkeit << "  "
		 << setw(9)<< fixed << p_dGesamtStrecke << "   "
		 << setw(9)<< fixed << p_dAbschnittStrecke << "    ";
	return Stream;
}

istream& Fahrzeug::istreamEingabe(istream& Stream)
{
	AktivesVO::istreamEingabe(Stream);
	Stream >> p_dMaxGeschwindigkeit;
	return Stream;
}

//Neue Instanz von FzgVerhalten anlegen und in Fahrzeug speichern
//Letzte Abfertigungszeit setzen und Abschnittstrecke zuruecksetzen
//Alte Instanz FzgVerhalten loeschen, falls vorhanden
void Fahrzeug::vNeueStrecke(Weg *ptWay, FzgVerhalten *ptFzgVerhalten)
{
	if(p_ptVerhalten != 0)
	{
		delete (p_ptVerhalten);
	}
	p_ptVerhalten = ptFzgVerhalten;
	p_dZeit = dGlobaleZeit;
	p_dAbschnittStrecke = 0;

}