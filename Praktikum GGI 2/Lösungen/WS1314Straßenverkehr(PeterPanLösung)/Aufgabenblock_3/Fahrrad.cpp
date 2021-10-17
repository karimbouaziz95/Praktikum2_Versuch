#include "Fahrrad.h"
#include <iostream>
#include <iomanip>
#include "SimuClient.h"
#include "Weg.h"
using namespace std;

extern double dGlobaleZeit;

//Konstruktor
Fahrrad::Fahrrad (string sName, double dMaxGeschwindigkeit)
{
    p_sName = sName;
    p_dMaxGeschwindigkeit = dMaxGeschwindigkeit;
}

//destruktor
Fahrrad::~Fahrrad(void)
{
}

// Aktualisieren der Geschwindigkeit von Fahrrad und deren Rückgabe
double Fahrrad::dGeschwindigkeit()
{
    double dAktGeschw = p_dMaxGeschwindigkeit;
    for(int count = fabs(p_dGesamtStrecke/20); count > 0; count--)
    {
        dAktGeschw = dAktGeschw * 0.9;
	    if(dAktGeschw<12)
	    {
		    dAktGeschw = 12.0;
	    }
    }
    
	return dAktGeschw;
}

// Ausgabe der speziellen Fahrrad Informationen
ostream& Fahrrad::ostreamAusgabe(ostream& Stream)
{
	Fahrzeug::ostreamAusgabe(Stream);
	Stream << resetiosflags(ios::right) << setiosflags(ios::left) //vorher rechts jetzt wieder linksbündig (1.5)
		   << setw(12)  << " "
		   << setw(12) << " " 
		   << setw(12) << dGeschwindigkeit() << endl;
	return Stream;
}

istream& Fahrrad::istreamEingabe(istream& Stream) 
{
	Fahrzeug::istreamEingabe(Stream);
	return Stream;
}

void Fahrrad::vZeichne(Weg* way)
{
	bZeichneFahrrad(getName(), way->GetName(),p_dAbschnittStrecke/way->GetLaenge(), dGeschwindigkeit());
}