#include "Fahrzeug.h"
#include <iostream>
#include <iomanip>
using namespace std;

int Fahrzeug::p_iMaxID = 1;
extern double dGlobaleZeit;


//Konstruktoren+++++++++++++++++++++++++++++++++
Fahrzeug::Fahrzeug(void)    // Standartkonstruktor
{
	//p_sName = "";
	vInitialisierung();
	//cout << p_sName << endl;
}

Fahrzeug::Fahrzeug(string sName)
{
	vInitialisierung();
	p_sName = sName;
	//cout << p_sName << endl;
}


Fahrzeug::Fahrzeug(string sName, double dMaxGeschwindigkeit)
{
	vInitialisierung();
	p_sName = sName;
	p_dMaxGeschwindigkeit = dMaxGeschwindigkeit;
}

//Destruktor+++++++++++++++++++++++++++++++++++++
Fahrzeug::~Fahrzeug(void)
{
	//cout << p_sName << endl;
}

// Ließt Name ein
void Fahrzeug:: setName()
{
	cin >> p_sName; 
}

//Gibt Name zurück
string Fahrzeug::getName(void)
{
	return p_sName;
}



//Initialisiert alles mit 0 und vergibt ID
void Fahrzeug::vInitialisierung(void)
{
	p_sName = "";
	p_iID = p_iMaxID;
	p_iMaxID +=1;
	p_dMaxGeschwindigkeit = 0;
	p_dGesamtStrecke = 0;
	p_dGesamtZeit = 0;
	p_dZeit = 0;
}

//Ausgabefunktion (gibt Fahrzeugdaten aus)
void Fahrzeug::vAusgabe(void)
{
	cout << resetiosflags(ios::right) << setiosflags(ios::left) //vorher rechts jetzt wieder linksbündig (1.5)
		 << setw(4)  << p_iID
		 << setw(7) << p_sName  
		 << setw(3) << ":"
		 << setw(15) << dGeschwindigkeit()
		 << setw(15) << p_dGesamtStrecke ;

}

//Standartabfertigung für alle Klassen (gesZeit; gesStrecke; eigZeit, werden aktualisiert) 
void Fahrzeug::vAbfertigung()
{
    
    if(p_dZeit!=dGlobaleZeit)
    {
		p_dGesamtStrecke += (dGlobaleZeit-p_dZeit)* dGeschwindigkeit(); 
        p_dZeit = dGlobaleZeit;
        p_dGesamtZeit += dGlobaleZeit-p_dZeit;
    }
}

//Tanken für Fahrzeuge ohne Tank (Fahrräder)
double Fahrzeug::dTanken(double dMenge)
{
	return 0.0;
}


ostream& operator<<(ostream& Stream, Fahrzeug& car)
{
	car.ostreamAusgabe(Stream);
	return Stream;
}

ostream& Fahrzeug::ostreamAusgabe(ostream& Stream)
{
	Stream << resetiosflags(ios::right) << setiosflags(ios::left) //vorher rechts jetzt wieder linksbündig (1.5)
		   << setw(4)  << p_iID
		   << setw(7) << p_sName  
		   << setw(3) << ":"
		   << setw(15) << p_dMaxGeschwindigkeit
		   << setw(15) << p_dGesamtStrecke;
	return Stream;
}

bool Fahrzeug::operator <(const Fahrzeug& vergleichsfahrzeug)
{
	if(this->p_dGesamtStrecke < vergleichsfahrzeug.p_dGesamtStrecke)
	{
		return true;
	}
	return false;
}


void Fahrzeug::operator =(const Fahrzeug& vergleichsfahrzeug)
{
	this->p_sName = vergleichsfahrzeug.p_sName + "K";
	this->p_dMaxGeschwindigkeit = vergleichsfahrzeug.p_dMaxGeschwindigkeit;
	this->p_dGesamtStrecke = vergleichsfahrzeug.p_dGesamtStrecke;
	this->p_dGesamtZeit = vergleichsfahrzeug.p_dGesamtZeit;
}