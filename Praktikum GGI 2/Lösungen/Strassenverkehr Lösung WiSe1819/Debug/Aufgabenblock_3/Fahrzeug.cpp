#include "Fahrzeug.h"
#include <string>
#include <iostream>
#include <iomanip>


#include "FzgFahren.h"
#include "FzgParken.h"
#include "Weg.h"
#include "FahrAusnahme.h"
using namespace std;


extern double dGlobaleZeit;

Fahrzeug::Fahrzeug() : AktivesVO() //Konstruktor von AktivesVO wird mit aufgerufen für Initialisierung und ID-Vergabe
{
	vInitialisierung();
}

Fahrzeug::Fahrzeug(string sName) : AktivesVO(sName) //Konstruktor von AktivesVO wird mit aufgerufen für Initialisierung und ID vergabe
{
	vInitialisierung();
	p_sName = sName;
}

Fahrzeug::Fahrzeug(string sName, double dMaxGeschwindigkeit) : AktivesVO(sName) //Konstruktor von AktivesVO wird mit aufgerufen für Initialisierung und ID vergabe
{
	vInitialisierung();
	p_sName = sName;
	p_dMaxGeschwindigkeit = dMaxGeschwindigkeit;
}

Fahrzeug::~Fahrzeug()
{
	cout << p_sName << " ID_" << p_iID << " wird geloescht" << endl;

	delete p_pVerhalten; //Verhalten wird Mitgeloescht, SpeicherLoch Vermeidung
}

double Fahrzeug::dTanken(double dMenge)
{
	return 0.0;
}

void Fahrzeug::vAusgabe(void)
{
	const char separator = ' ';
	cout << left << setw(8) << setfill(separator) << p_iID;
	cout << left << setw(8) << setfill(separator) << p_sName;
	cout << left << setw(3) << setfill(separator) << ":";
	cout << fixed;
	cout << left << setw(12) << setfill(separator) << setprecision(2) << dGeschwindigkeit();
	cout << left << setw(18) << setfill(separator) << setprecision(2) << p_dGesamtStrecke;

}

void Fahrzeug::vAbfertigung()
{
	if (p_dZeit == dGlobaleZeit) //Mehrmalige verwendung des Autos in einer Zeiteinheit ausgeschloßen
		return;
	double dDeltaTime = dGlobaleZeit - p_dZeit;
	double dGefahreneStrecke = 0;
	try 
	{
		dGefahreneStrecke = p_pVerhalten->dStrecke(this, dDeltaTime);
	}
	catch (FahrAusnahme& e) //
	{
		e.vBearbeiten();       //vBearbeiten wird erst entsprechend zur Laufzeit aufgerufen --> in throw wird 
		p_dZeit = dGlobaleZeit;// entweder der Konstruktor Losfahren oder Streckenende aufgerufen
		p_dGesamtZeit += dDeltaTime;
		return; 
	}
	p_dAbschnittStrecke += dGefahreneStrecke;
	p_dGesamtStrecke += dGefahreneStrecke;

	p_dZeit = dGlobaleZeit;
	p_dGesamtZeit += dDeltaTime;
}

double Fahrzeug::dGeschwindigkeit()
{
	double dGeschwindigkeit = p_dMaxGeschwindigkeit;
	//Geschwindigkeitslimit
	if (p_pVerhalten->dGetLimit() < dGeschwindigkeit)
	{
		dGeschwindigkeit = p_pVerhalten->dGetLimit();
	}
	return dGeschwindigkeit;
}

void Fahrzeug::vNeueStrecke(Weg * weg, FzgVerhalten * pVerhalten)
{
	if (p_pVerhalten != 0) //Memoryleak vermeiden, wenn in p_pVerhalten noch Objekte 
		delete p_pVerhalten;

	p_pVerhalten = pVerhalten;
	p_dZeit = dGlobaleZeit;
	p_dAbschnittStrecke = 0;
}

//NeueStrecke mit fahrendem Auto
void Fahrzeug::vNeueStrecke(Weg * weg) 
{
	if (p_pVerhalten != 0)
		delete p_pVerhalten;
	weg->vAnnahme(this);
}

//NeueStrecke mit parkendem Auto 
void Fahrzeug::vNeueStrecke(Weg * weg, double dStartTime)
{
	if (p_pVerhalten != 0)
		delete p_pVerhalten;
	weg->vAnnahme(this, dStartTime);
}

// Getter und Setter
void Fahrzeug::vSetName(string sName)
{
	p_sName = sName;
}

string Fahrzeug::sGetName()
{
	return p_sName;
}

void Fahrzeug::vSetGeschwindigkeit(double dGeschwindigkeit)
{
	p_dMaxGeschwindigkeit = dGeschwindigkeit;
}

double Fahrzeug::dGetZeit()
{
	return p_dZeit;
}

double Fahrzeug::dGetAbschnittStrecke()
{
	return p_dAbschnittStrecke;
}

bool Fahrzeug::bKannFahren() {
	//Checkt ob das Fahrzeug am Fahren ist.
	return dynamic_cast<FzgFahren*>(p_pVerhalten);
}

void Fahrzeug::vInitialisierung()  
{
	//Nur die neuen Variablen werden auf 0 gesetzt. 
	//Sonstige werden durch den Konstruktor von AktivesVO Gesetzt
	// -> Code recycling, jeder bekommt selbe funktion für ID vergabe.
	// -> Kein redundanter Code
	p_pVerhalten = 0;
	p_dMaxGeschwindigkeit = 0;
	p_dGesamtStrecke = 0;
	p_dAbschnittStrecke = 0;
	p_dGesamtZeit = 0;
	
}

//Fahrzeug spezifische Ausgaben
ostream& Fahrzeug::ostreamAusgabe(ostream& output) 
{
	AktivesVO::ostreamAusgabe(output);
	cout << setfill(' '); // Reset Fill
	output << setfill(' ');
	output << fixed;
	output << left << setw(12) << setfill(' ') << setprecision(2) << dGeschwindigkeit();
	output << left << setw(18) << setfill(' ') << setprecision(2) << p_dGesamtStrecke;
	output << left << setw(18) << setfill(' ') << setprecision(2) << "---";
	output << left << setw(18) << setfill(' ') << setprecision(2) << "---";

	return output;
}

istream & Fahrzeug::istreamEingabe(istream & input)
{
	AktivesVO::istreamEingabe(input);
	input >> p_dMaxGeschwindigkeit;
	return input;
}









//Überladen des Vergleich-Operators "<"
bool Fahrzeug::operator <(const Fahrzeug& VglFzg)
{
	if (this->p_dGesamtStrecke < VglFzg.p_dGesamtStrecke) //
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Überladen des Copy-Konstruktors
Fahrzeug::Fahrzeug(const Fahrzeug &Vehicle)
{
	p_sName = Vehicle.p_sName + "_duplicate";
	p_dMaxGeschwindigkeit = Vehicle.p_dMaxGeschwindigkeit;
	p_dGesamtStrecke = Vehicle.p_dGesamtStrecke;
	p_dGesamtZeit = Vehicle.p_dGesamtZeit;
	p_dZeit = Vehicle.p_dZeit;
	//p_iID = p_iMaxID;
	//p_iMaxID++;
}


//Überladen des Vergleichsoperators "="
void Fahrzeug::operator =(const Fahrzeug& VglFzg)
{
	p_sName = VglFzg.p_sName + "_duplicate";
	p_dMaxGeschwindigkeit = VglFzg.p_dMaxGeschwindigkeit;
	p_dGesamtStrecke = VglFzg.p_dGesamtStrecke;
	p_dGesamtZeit = VglFzg.p_dGesamtZeit;
}

void Fahrzeug::vZeichnen(Weg* pWeg)
{
	
}