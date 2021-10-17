#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Fahrzeug.h"

int Fahrzeug::p_iMaxID = 0;
extern double dGlobaleZeit;

// Standard Konstruktor
Fahrzeug::Fahrzeug()
{
	vInitialisierung();
}


//Konstruktor mit übergebenem Namen
Fahrzeug::Fahrzeug(string sName)
{
	vInitialisierung();
	p_sName = sName; 
}

//Konstruktor mit übergebenem Namen und MaxGeschwindigkeit
Fahrzeug::Fahrzeug(string sName, double dMaxSpeed)
{
	vInitialisierung();
	p_sName = sName;
	p_dMaxGeschwindigkeit = dMaxSpeed;
}

// Destruktor
Fahrzeug::~Fahrzeug()
{
	cout << "Fahrzeug geloescht: ID: " << p_iID << " , Name: " << p_sName << endl;
}

// Initialisierung für Konstruktoren
void Fahrzeug::vInitialisierung()
{
	p_sName = " ";
	p_iMaxID+=1;
	p_iID = p_iMaxID;
	p_dMaxGeschwindigkeit = 0;
	p_dGesamtStrecke = 0;
	p_dGesamtZeit = 0;
	p_dZeit = 0;
}
// Tabellarische Ausgabe der Membervariablen
void Fahrzeug::vAusgabe()
{
	cout.precision(2); // Auf zwei Nachkommastellen runden und immer anzeigen. (5.00)

	cout << " " << resetiosflags(ios::right) << setiosflags(ios::right)
		 << setw(2) << p_iID << "    "
		 << resetiosflags(ios::right) << setiosflags(ios::left) // wieder linksbündig
		 << setw(15) << p_sName << ":  "
		 << resetiosflags(ios::left) << setiosflags(ios::right) // wieder rechtsbündig
		 << setw(8) << fixed<< p_dMaxGeschwindigkeit << "  "
		 << setw(10)<< fixed << p_dGesamtStrecke;
}

// Fahrzeug faehrt mit spezieller Geschwindigkeit, p_dZeit wird aktualisiert.
void Fahrzeug::vAbfertigung()
{
	if( (dGlobaleZeit-p_dZeit) > 0) // = 0, Fall egal. < 0 (?) keine Ahnung
	{
		p_dGesamtStrecke += (dGlobaleZeit-p_dZeit)*dGeschwindigkeit();
		p_dZeit=dGlobaleZeit;
		p_dGesamtZeit += (dGlobaleZeit-p_dZeit);
	}
	
}

double Fahrzeug::dGeschwindigkeit()
{
	return p_dMaxGeschwindigkeit;
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
	this->p_dGesamtZeit = fVergleich.p_dGesamtZeit;
	this->p_dZeit = fVergleich.p_dZeit;
}

ostream& operator<<(ostream& Stream, Fahrzeug& car)
{
	car.ostreamAusgabe(Stream);
	return Stream;
}

ostream& Fahrzeug::ostreamAusgabe(ostream& Stream)
{
	Stream.precision(2); // Auf zwei Nachkommastellen runden und immer anzeigen. (5.00)

	Stream << " " << resetiosflags(ios::right) << setiosflags(ios::right)
		 << setw(2) << p_iID << "    "
		 << resetiosflags(ios::right) << setiosflags(ios::left) // wieder linksbündig
		 << setw(15) << p_sName << ":  "
		 << resetiosflags(ios::left) << setiosflags(ios::right) // wieder rechtsbündig
		 << setw(8) << fixed<< p_dMaxGeschwindigkeit << "  "
		 << setw(10)<< fixed << p_dGesamtStrecke;
	return Stream;
}