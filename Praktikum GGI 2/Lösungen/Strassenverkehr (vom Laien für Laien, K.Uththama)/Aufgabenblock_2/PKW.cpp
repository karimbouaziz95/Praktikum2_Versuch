#include <string>
#include <iomanip>
#include <iostream>

#include "PKW.h"
#include "Weg.h"

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
	double dGesamtVerbrauch = (p_dVerbrauch/100)*p_dGesamtStrecke;
	return dGesamtVerbrauch;
}


//Tanken für Fahrzeuge mit Tank
double PKW::dTanken(double dMenge)
{
	if (dMenge > 1000000)
	{ 
		dMenge = p_dTankvolumen-p_dTankinhalt;
		p_dTankinhalt = p_dTankvolumen;
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
		}
	}
	cout << p_sName << " hat " << dMenge << " getankt !" << endl;
    return (dMenge);
}


//Abfertigung mit Tankaktualisierung
void PKW::vAbfertigung()
{
	if (p_dTankinhalt > 0)
	{
		double  Strecke = p_dAbschnittStrecke;
		Fahrzeug::vAbfertigung();
		p_dTankinhalt = p_dTankinhalt - ((p_dAbschnittStrecke - Strecke)*(p_dVerbrauch/100));
		p_dZeit = dGlobaleZeit;
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
	cout << setw(17) << dGesamtverbrauch
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
		int Limit = (p_pVerhalten->getWayPointer())->igetSpeedLimit();
		if (Limit > 10000)
		{ return p_dMaxGeschwindigkeit;}
		else
		{ return Limit; }
    }
}


//Spezifizierung der Ausgabe für PKW
ostream& PKW::ostreamAusgabe(ostream& output)
{
	
    Fahrzeug::ostreamAusgabe(output);
	double dGesamtverbrauch = dVerbrauch();
	cout   << setw(18) << dGesamtverbrauch
		   << setw(12) << p_dTankinhalt
		   << endl << endl;
	return output;
}


//Überladen des Vergleichsoperators "="
PKW& PKW::operator =(const PKW& VglFzg)
{
    p_sName = VglFzg.p_sName + "_duplicate";
	p_dMaxGeschwindigkeit = VglFzg.p_dMaxGeschwindigkeit;
	p_dGesamtStrecke = VglFzg.p_dGesamtStrecke;
	p_dGesamtZeit = VglFzg.p_dGesamtZeit;
	p_dTankvolumen = VglFzg.p_dTankvolumen;
	p_dTankinhalt = VglFzg.p_dTankinhalt;
	p_dVerbrauch = VglFzg.p_dVerbrauch;
	p_dZeit = VglFzg.p_dZeit;
	return *this;
}


//Zeichnen eines PKW´s
void PKW::vZeichnen(Weg* Weg)
{
	double RelPosition = p_dAbschnittStrecke/Weg->dgetlength();
	if(RelPosition > 1) {RelPosition = 1;}
	bZeichnePKW(p_sName, Weg->sgetName(), RelPosition, dGeschwindigkeit(), p_dTankinhalt);
}