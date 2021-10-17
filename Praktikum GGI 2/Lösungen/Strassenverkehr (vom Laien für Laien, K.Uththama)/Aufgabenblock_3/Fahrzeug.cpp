#include "Fahrzeug.h"
#include <iostream>
#include <iomanip>
using namespace std;
#include "Weg.h"
#include "FzgVerhalten.h"
#include "FzgParken.h"
#include "FzgFahren.h"

extern double dGlobaleZeit;


//Standardkonstruktor
Fahrzeug::Fahrzeug(void) : AktivesVO()
{
	vInitialisierung();
	p_sName = "";	
	//cout << "Fahrzeug erstellt !" << endl;
	//cout << p_sName << endl << p_iID << endl;
}


//Konstruktor mit Fahrzeugnamen
Fahrzeug::Fahrzeug(string sName) : AktivesVO(sName)
{
	vInitialisierung();	
	//cout << "Fahrzeug erstellt !" << endl;
	//cout << p_sName << endl << p_iID << endl;
}


//Konstruktor mit Namen und MaxGeschwindigkeit
Fahrzeug::Fahrzeug(string sName,double dMaxSpeed) : AktivesVO(sName)
{
	vInitialisierung();
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
void Fahrzeug::vsetName(string sName)
{
	p_sName = sName;
}


//Einagabefunktion für Namen
string Fahrzeug::sgetName()
{
	return p_sName;
	
}


//Funtion zum übergeben der Geschwindigkeit
void Fahrzeug::vsetspeed(double Maxspeed)
{
	p_dMaxGeschwindigkeit = Maxspeed;
}


//Initialisierungsfunktion
void Fahrzeug::vInitialisierung(void)
{
    p_dMaxGeschwindigkeit = 0;
    p_dGesamtStrecke = 0;
    p_dGesamtZeit = 0;
	p_dAbschnittStrecke = 0;
	p_pVerhalten = new FzgParken;
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
		 << setw(17) << dGeschwindigkeit()
	     << setw(19) << p_dAbschnittStrecke;
}


//Abfertigungsfunktion
void Fahrzeug::vAbfertigung()
{
	if (p_dZeit == dGlobaleZeit)
	{
		return; 
	}
	else 
	{
	double dMaxGeschwindigkeit = dGeschwindigkeit();
	p_dGesamtStrecke =  p_dGesamtStrecke + ((dGlobaleZeit - p_dZeit)*dMaxGeschwindigkeit);
	p_dGesamtZeit = (dGlobaleZeit - p_dZeit) + p_dGesamtZeit ;
	p_dAbschnittStrecke += p_pVerhalten->dStrecke(this,(dGlobaleZeit-p_dZeit)); 
	}
}


//automatisches Tanken ("Grundgerüst")
double Fahrzeug::dTanken(double dMenge )
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
	  AktivesVO::ostreamAusgabe(output);
	  cout << setw(4)  << ":" 
           << setw(15) << p_dMaxGeschwindigkeit
		   << setw(18) << p_dGesamtStrecke
		   << setw(18) << "0" /*dGeschwindigkeit()*/
	       << setw(19) << p_dAbschnittStrecke;
	return output;
}


//spezifische Eingaben
istream& Fahrzeug::istreamEingabe(istream& input)
{
	AktivesVO::istreamEingabe(input)
	>> p_dMaxGeschwindigkeit;
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
Fahrzeug::Fahrzeug(const Fahrzeug &Vehicle) : AktivesVO()
{
	p_sName = Vehicle.p_sName + "_duplicate";
	p_dMaxGeschwindigkeit = Vehicle.p_dMaxGeschwindigkeit;
	p_dGesamtStrecke = Vehicle.p_dGesamtStrecke;
	p_dGesamtZeit = Vehicle.p_dGesamtZeit;
	p_dZeit = Vehicle.p_dZeit;
}


//Überladen des Vergleichsoperators "="
Fahrzeug& Fahrzeug::operator =(const Fahrzeug& VglFzg)
{
    p_sName = VglFzg.p_sName + "_duplicate";
	p_dMaxGeschwindigkeit = VglFzg.p_dMaxGeschwindigkeit;
	p_dGesamtStrecke = VglFzg.p_dGesamtStrecke;
	p_dGesamtZeit = VglFzg.p_dGesamtZeit;
	return *this;
}


//Erzeugung eines fahrenden Fzg auf neuer Strecke
void Fahrzeug::vNeueStrecke(Weg* Weg)
{
	p_dAbschnittStrecke = 0;
	delete p_pVerhalten;  //altes Verhalten löschen
	p_pVerhalten = new FzgFahren(Weg);
}


//Erzeugung eines parkenden Fzg auf neuer Strecke
void Fahrzeug::vNeueStrecke(Weg* Weg, double dStart)
{
	p_dAbschnittStrecke = 0;
	delete p_pVerhalten;   //altes Verhalten löschen
	p_pVerhalten = new FzgParken(Weg, dStart);
}


//Übergabe der Abschnittstrecke 
double Fahrzeug::dgetactLength()
{
	return p_dAbschnittStrecke;
}


void Fahrzeug::vsetactLength(int length)
{
	p_dAbschnittStrecke = length;
}


void Fahrzeug::vsetactTime(double time)
{
	p_dZeit = time;
}


FzgVerhalten* Fahrzeug::getVerPtr()
{
	return p_pVerhalten;
}


//Virtuelle Zeichnen-Funktion
void Fahrzeug::vZeichnen(Weg* Weg)
{
}