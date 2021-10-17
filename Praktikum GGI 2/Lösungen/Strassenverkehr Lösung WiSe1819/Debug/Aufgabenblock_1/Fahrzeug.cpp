#include "Fahrzeug.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

static int p_iMaxID = 1;
extern double dGlobaleZeit;

Fahrzeug::Fahrzeug()
{
	vInitialisierung();
}

Fahrzeug::Fahrzeug(string sName)
{
	vInitialisierung();
	p_sName = sName;
}

Fahrzeug::Fahrzeug(string sName, double dMaxGeschwindigkeit)
{
	vInitialisierung();
	p_sName = sName;
	p_dMaxGeschwindigkeit = dMaxGeschwindigkeit;
}



Fahrzeug::~Fahrzeug()
{
	cout << "Fahrzeug " << p_iID << " wird geloescht" << endl;
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
	if (p_dZeit == dGlobaleZeit) //Mehrmalige verwendung des Autos in einer Zeiteinheit ausgeschließen
		return;
	double dDeltaTime = dGlobaleZeit - p_dZeit;
	p_dGesamtStrecke += dDeltaTime * dGeschwindigkeit();
	p_dGesamtZeit += dDeltaTime;
	//Zeit aktualisieren
	p_dZeit = dGlobaleZeit;
}

double Fahrzeug::dGeschwindigkeit()
{
	return p_dMaxGeschwindigkeit;
}

void Fahrzeug::vSetName(string sName)
{
	p_sName = sName;
}

void Fahrzeug::vSetGeschwindigkeit(double dGeschwindigkeit)
{
	p_dMaxGeschwindigkeit = dGeschwindigkeit;
}



void Fahrzeug::vInitialisierung()
{
	p_sName = "";
	p_dMaxGeschwindigkeit = 0;
	p_dGesamtStrecke = 0;
	p_dGesamtZeit = 0;
	p_dZeit = 0;
	p_iID = p_iMaxID;
	p_iMaxID++;
}

//Fahrzeug spezifische Ausgaben
ostream& Fahrzeug::ostreamAusgabe(ostream& output)
{

	cout << setfill(' '); // Reset Fill
	output << setfill(' ');
	output << left << setw(8) << setfill(' ') << p_iID;
	output << left << setw(8) << setfill(' ') << p_sName;
	output << left << setw(3) << setfill(' ') << ":";
	output << fixed;
	output << left << setw(12) << setfill(' ') << setprecision(2) << dGeschwindigkeit();
	output << left << setw(18) << setfill(' ') << setprecision(2) << p_dGesamtStrecke;
	return output;
}


/* Kopie Rückgabe
const ostream Fahrzeug::ostreamAusgabe(ostream){...}*/


//Überladen des Ausgabe-Operators "<<"
ostream& operator <<(ostream& output, Fahrzeug& Fzg)
{
	Fzg.ostreamAusgabe(output);
	return output;
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
	p_iID = p_iMaxID;
	p_iMaxID++;
}


//Überladen des Vergleichsoperators "="
void Fahrzeug::operator =(const Fahrzeug& VglFzg)
{
	p_sName = VglFzg.p_sName + "_duplicate";
	p_dMaxGeschwindigkeit = VglFzg.p_dMaxGeschwindigkeit;
	p_dGesamtStrecke = VglFzg.p_dGesamtStrecke;
	p_dGesamtZeit = VglFzg.p_dGesamtZeit;
}

