#include "Fahrzeug.h"
#include <iostream>
#include <iomanip>
using namespace std;
#include "Weg.h"
#include "FzgVerhalten.h"

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


Fahrzeug::Fahrzeug(string sName, double dMaxGeschwindigkeit) : AktivesVO(sName)
{
	vInitialisierung();
	//p_sName = sName;
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
	p_iMaxID+=1;
	p_dMaxGeschwindigkeit = 0;
	p_dGesamtStrecke = 0;
	p_dGesamtZeit = 0;
	p_dZeit = 0;
    //p_pVerhalten =&Liegen;
}

//Ausgabefunktion (gibt Fahrzeugdaten aus)
void Fahrzeug::vAusgabe(void)
{
	cout << resetiosflags(ios::right) << setiosflags(ios::left) //vorher rechts jetzt wieder linksbündig (1.5)
		 << setw(4)  << p_iID
		 << setw(7) << p_sName  
		 << setw(3) << ":"
		 << setw(15) << dGeschwindigkeit()
		 << setw(15) << p_dGesamtStrecke << endl;

}

//Standartabfertigung für alle Klassen (gesZeit; gesStrecke; eigZeit, werden aktualisiert) 
void Fahrzeug::vAbfertigung()
{
    if(p_dZeit!=dGlobaleZeit)
    {
		//p_dAbschnittStrecke += (dGlobaleZeit-p_dZeit)* dGeschwindigkeit();
		p_dGesamtStrecke += p_pVerhalten->dStrecke(this, dGlobaleZeit-p_dZeit);	
        p_dAbschnittStrecke += p_pVerhalten->dStrecke(this, dGlobaleZeit-p_dZeit);	
        p_dZeit = dGlobaleZeit;
        p_dGesamtZeit += dGlobaleZeit-p_dZeit;
		
    }
}

//Tanken für Fahrzeuge ohne Tank (Fahrräder)
double Fahrzeug::dTanken(double dMenge)
{
	return 0.0;
}


ostream& Fahrzeug::ostreamAusgabe(ostream& Stream)
{        
	AktivesVO::ostreamAusgabe(Stream);
	Stream << resetiosflags(ios::right) << setiosflags(ios::left) //vorher rechts- jetzt wieder linksbündig  
		   << setw(15) << p_dMaxGeschwindigkeit
		   << setw(15) << p_dGesamtStrecke;
	return Stream;
}

istream& Fahrzeug::istreamEingabe(istream& Stream) 
{
	AktivesVO::istreamEingabe(Stream);
	Stream >> p_dMaxGeschwindigkeit;
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

void Fahrzeug::vNeueStrecke(Weg* ptWeg, FzgVerhalten* pBenehmen)
{
    /*
	//Speicherlöcher vermeiden
	if(p_pVerhalten != 0)
	{
		delete (p_pVerhalten);
	}*/
	p_pVerhalten = pBenehmen;
	p_dZeit = dGlobaleZeit;
	p_dAbschnittStrecke = 0;

	//p_pVerhalten = &FzgVerhalten::FzgVerhalten(ptWeg);
}