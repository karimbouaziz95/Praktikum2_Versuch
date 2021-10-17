#include "Fahrrad.h"
#include <iostream>
#include <iomanip>
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

// Aktualisieren der Geschwindigkeit von Fahrrad und deren R�ckgabe
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
	Stream << resetiosflags(ios::right) << setiosflags(ios::left) //vorher rechts jetzt wieder linksb�ndig (1.5)
		   << setw(12)  << " "
		   << setw(12) << " " 
		   << setw(12) << dGeschwindigkeit() << endl;
	return Stream;
}




void Fahrrad::vAusgabe(void)
{
    Fahrzeug::vAusgabe();
    cout << resetiosflags(ios::right) << setiosflags(ios::left) //vorher rechts jetzt wieder linksb�ndig (1.5)
		   << setw(12)  << " "
		   << setw(12) << " " 
		   << setw(12) << dGeschwindigkeit() << endl;
    
}