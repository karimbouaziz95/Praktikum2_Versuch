#include "PKW.h"
#include <string>
#include <iomanip>
#include <iostream>
extern double dGlobaleZeit;

//Konstruktor
/*
PKW::PKW(void)
{
    p_dTankinhalt=p_dTankvolumen/2;
}
*/

//Konstruktor mit Initialisierungsliste für FahrzeugKonstruktor
PKW::PKW(string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen):Fahrzeug(sName,dMaxGeschwindigkeit)
{
    p_dVerbrauch = dVerbrauch;
	p_dTankvolumen = dTankvolumen;
	p_dTankinhalt=p_dTankvolumen/2;
}

//destruktor
PKW::~PKW(void)
{
}

// Tanken für Fahrzeuge mit Tank
double PKW::dTanken(double dMenge)
{
	if(dMenge==0)
	{
		dMenge = p_dTankvolumen - p_dTankinhalt;
		p_dTankinhalt = p_dTankvolumen;
		return dMenge;
	}
	else
	{
		double rest = p_dTankvolumen - p_dTankinhalt;

		if(rest>=dMenge)
		{
			p_dTankinhalt = p_dTankinhalt + dMenge;
			return dMenge;
		}
		else
		{
			p_dTankinhalt = p_dTankvolumen;
			return rest;
		}
	}
}


// Abfertigung mit Aktualisierung des Tanks
void PKW::vAbfertigung()
{    
	if(p_dTankinhalt>0)
    {      
		double dAktuellerVerbrauch = (dGlobaleZeit-p_dZeit) * p_dMaxGeschwindigkeit * p_dVerbrauch / 100;
		p_dTankinhalt -= dAktuellerVerbrauch;
		if(p_dTankinhalt < 0)
			{
				p_dTankinhalt = 0;
			}
		Fahrzeug::vAbfertigung();
    }
	else
	{
		p_dTankinhalt = 0;
	}
}

// Ausgabe der speziellen PKW Informationen
ostream& PKW::ostreamAusgabe(ostream& Stream)
{
	Fahrzeug::ostreamAusgabe(Stream);
	Stream << resetiosflags(ios::right) << setiosflags(ios::left) //vorher rechts jetzt wieder linksbündig (1.5)
		   << setw(12)  << p_dVerbrauch
		   << setw(12)  << p_dTankinhalt << endl;
	return Stream;
}

void PKW::vAusgabe(void)
{
    Fahrzeug::vAusgabe();
    cout << resetiosflags(ios::right) << setiosflags(ios::left) //vorher rechts jetzt wieder linksbündig (1.5)
        << setw(12)  << p_dVerbrauch
        << setw(12) << p_dTankinhalt << endl;
    
}