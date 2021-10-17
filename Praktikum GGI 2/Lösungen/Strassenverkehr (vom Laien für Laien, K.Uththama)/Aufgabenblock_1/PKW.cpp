#include <string>
#include <iomanip>
#include <iostream>

#include "PKW.h"

extern double dGlobaleZeit;


//Konstruktoren
PKW::PKW(void) : Fahrzeug()
{
}

PKW::PKW(string sName, double dMaxSpeed, double dVerbrauch , double dTankVol) : Fahrzeug(sName , dMaxSpeed) //Initialisierungsliste
{
	p_dVerbrauch = dVerbrauch;
	p_dTankvolumen =  dTankVol;
	p_dTankinhalt = 0.5*p_dTankvolumen;
}
 

//Destruktor
PKW::~PKW(void)
{
}


//Verbrauch des Fahrezugs pro Kilometer
double PKW::dVerbrauch()
{
	double dGesamtVerbrauch = 0;
	dGesamtVerbrauch = (p_dVerbrauch/100)*p_dGesamtStrecke;
	return dGesamtVerbrauch;
}


//Tanken für Fahrzeuge mit Tank
double PKW::dTanken(double dMenge = VOLLTANKEN)
{
	if (dMenge > 1000000)
	{ 
		dMenge = p_dTankvolumen-p_dTankinhalt;
		p_dTankinhalt = p_dTankvolumen;
		return (dMenge);
	}
	else 
	{
		if (dMenge < (p_dTankvolumen-p_dTankinhalt) )
		{
			p_dTankinhalt += dMenge;
		}
		else
		{
			dMenge = p_dTankvolumen-p_dTankinhalt;
			p_dTankinhalt = p_dTankvolumen;
			return (p_dTankvolumen-p_dTankinhalt);
		}
	}
    return (dMenge);
}


//Abfertigung mit Tankaktualisierung
void PKW::vAbfertigung()
{
	if (p_dTankinhalt > 0)
	{

		p_dTankinhalt = p_dTankinhalt - ((dGlobaleZeit - p_dZeit)*p_dMaxGeschwindigkeit*p_dVerbrauch/100);
		Fahrzeug::vAbfertigung();
		
		if (p_dTankinhalt <= 0)
		{
			p_dTankinhalt=0;
		}
	}
    p_dZeit = dGlobaleZeit;
}


//Ausgabe mit Tankinhalt und Gesamtverbrauch
void PKW::vAusgabe(void)
{
	double dGesamtverbrauch = dVerbrauch();
	Fahrzeug::vAusgabe();
	cout << setw(16) << dGesamtverbrauch
		 << setw(12) << p_dTankinhalt;
}


//Geschwindigkeitsanpassung
double PKW::dGeschwindigkeit()
{
	if (p_dTankinhalt <= 0)
	{ 
		return 0;
	}
	else
	{
		return p_dMaxGeschwindigkeit;
    }
}


//Spezifizierung der Ausgabe für PKW
ostream& PKW::ostreamAusgabe(ostream& output)
{
	double dGesamtverbrauch = dVerbrauch();
	output << resetiosflags(ios::right) << setiosflags(ios::left) //jetzt rechtsbündig -> aus Aufgabe 1.5
		   << setiosflags(ios::fixed) << setprecision(2)
		   << setw(5)  << p_iID 
	       << setw(14) << p_sName 
	       << setw(4)  << ":" 
           << setw(15) << p_dMaxGeschwindigkeit
		   << setw(17) << p_dGesamtStrecke
		   << setw(18) << dGeschwindigkeit()
		   << setw(16) << dGesamtverbrauch
		   << setw(12) << p_dTankinhalt
		   << endl << endl;
	return output;
}


//Überladen des Vergleichsoperators "="
void PKW::operator =(const PKW& VglFzg)
{
    p_sName = VglFzg.p_sName + "_duplicate";
	p_dMaxGeschwindigkeit = VglFzg.p_dMaxGeschwindigkeit;
	p_dGesamtStrecke = VglFzg.p_dGesamtStrecke;
	p_dGesamtZeit = VglFzg.p_dGesamtZeit;
	p_dTankvolumen = VglFzg.p_dTankvolumen;
	p_dTankinhalt = VglFzg.p_dTankinhalt;
	p_dVerbrauch = VglFzg.p_dVerbrauch;
	p_dZeit = VglFzg.p_dZeit;
}