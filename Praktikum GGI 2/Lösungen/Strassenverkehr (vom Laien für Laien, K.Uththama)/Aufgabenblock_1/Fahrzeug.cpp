#include <stdio.h>
#include <iostream>
#include <iomanip>

#include "Fahrzeug.h"

int Fahrzeug::p_iMaxID = 0;
extern double dGlobaleZeit;


//Standardkonstruktor
Fahrzeug::Fahrzeug(void)
{
	vInitialisierung();
	p_sName = "";	
	//cout << "Fahrzeug erstellt !" << endl;
	//cout << p_sName << endl << p_iID << endl;
}


//Konstruktor mit Fahrzeugnamen
Fahrzeug::Fahrzeug(string sName)
{
	vInitialisierung();
	p_sName = sName ;	
	//cout << "Fahrzeug erstellt !" << endl;
	//cout << p_sName << endl << p_iID << endl;
}


//Konstruktor mit Namen und MaxGeschwindigkeit
Fahrzeug::Fahrzeug(string sName,double dMaxSpeed)
{
	vInitialisierung();
	p_sName = sName;
	p_dMaxGeschwindigkeit = dMaxSpeed;	
	//cout << "Fahrzeug erstellt !" << endl;
	//cout << p_sName << endl << p_iID << endl;
}


//Destruktor
Fahrzeug::~Fahrzeug(void)
{
	//cout << "Fahrzeug geloescht !" << endl;
	//cout <<"Name : " << p_sName << endl;
	//cout <<"ID : " << p_iID << endl << endl;
}


//Funktion zum übergben des Namen
void Fahrzeug::vgetName(string sName)
{
	p_sName = sName;
}


//Einagabefunktion für Namen
void Fahrzeug::vsetName()
{
	cin >> p_sName;
	
}


//Funtion zum übergeben der Geschwindigkeit
void Fahrzeug::vgetspeed(double Maxspeed)
{
	p_dMaxGeschwindigkeit = Maxspeed;
}


//Initialisierungsfunktion
void Fahrzeug::vInitialisierung(void)
{
	p_iMaxID++;
    p_sName = "";
    p_iID = p_iMaxID;
    p_dMaxGeschwindigkeit = 0;
    p_dGesamtStrecke = 0;
    p_dGesamtZeit = 0;
    p_dZeit = 0;
}


//Ausgabefunktion 
void Fahrzeug::vAusgabe(void)
{
	cout << resetiosflags(ios::right) << setiosflags(ios::left) //jetzt rechtsbündig -> aus Aufgabe 1.5
		 << setiosflags(ios::fixed) << setprecision(2)
		 << setw(5)  << p_iID 
	     << setw(14) << p_sName 
	     << setw(4)  << ":" 
         << setw(15) << p_dMaxGeschwindigkeit
		 << setw(17) << p_dGesamtStrecke
		 << setw(19) << dGeschwindigkeit();
}


//Abfertigungsfunktion
void Fahrzeug::vAbfertigung()
{
	if (p_dZeit == dGlobaleZeit)
	{
		return ;
	}
	else 
	{
	double dMaxGeschwindigkeit = dGeschwindigkeit();
	p_dGesamtStrecke =  p_dGesamtStrecke + ((dGlobaleZeit - p_dZeit)*dMaxGeschwindigkeit);
	p_dGesamtZeit = (dGlobaleZeit - p_dZeit) + p_dGesamtZeit ;
	p_dZeit = dGlobaleZeit;
	}
}


//automatisches Tanken ("Grundgerüst")
double Fahrzeug::dTanken(double dMenge)
{
	return 0;
}


//Geschwindigkeitsanpassung ("Grundgerüst")
double Fahrzeug::dGeschwindigkeit()
{
	return p_dMaxGeschwindigkeit;
}


//Fahrzeug spezifische Ausgaben
ostream& Fahrzeug::ostreamAusgabe(ostream& output)
{
	output << resetiosflags(ios::right) << setiosflags(ios::left) //jetzt rechtsbündig -> aus Aufgabe 1.5
		   << setiosflags(ios::fixed) << setprecision(2)
		   << setw(5)  << p_iID 
	       << setw(14) << p_sName 
	       << setw(4)  << ":" 
           << setw(15) << p_dMaxGeschwindigkeit
		   << setw(17) << p_dGesamtStrecke
		   << setw(30) << dGeschwindigkeit()
		   << endl;
	return output;
}


/* Kopie Rückgabe
const ostream Fahrzeug::ostreamAusgabe(ostream){...}*/


//Überladen des Ausgabe-Operators "<<"
ostream& operator <<(ostream& output , Fahrzeug& Fzg)
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
	p_iMaxID++;
    p_iID = p_iMaxID;
}


//Überladen des Vergleichsoperators "="
void Fahrzeug::operator =(const Fahrzeug& VglFzg)
{
    p_sName = VglFzg.p_sName + "_duplicate";
	p_dMaxGeschwindigkeit = VglFzg.p_dMaxGeschwindigkeit;
	p_dGesamtStrecke = VglFzg.p_dGesamtStrecke;
	p_dGesamtZeit = VglFzg.p_dGesamtZeit;
}