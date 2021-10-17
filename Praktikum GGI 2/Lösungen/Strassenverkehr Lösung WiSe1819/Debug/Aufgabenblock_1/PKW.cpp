#include <string>
#include <iomanip>
#include <iostream>

#include "PKW.h"

extern double dGlobaleZeit;


//Konstruktor
PKW::PKW(void) : Fahrzeug()
{
}

PKW::PKW(string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dTankvolumen) : Fahrzeug(sName, dMaxGeschwindigkeit) //Initialisierungsliste
{
	p_dVerbrauch = dVerbrauch;
	p_dTankvolumen = dTankvolumen;
	p_dTankinhalt = 0.5*p_dTankvolumen;
}


//Destruktor
PKW::~PKW(void)
{
}


//Verbrauch pro Kilometer
double PKW::dVerbrauch()
{
	double dGesamtVerbrauch = 0;
	dGesamtVerbrauch = (p_dVerbrauch / 100)*p_dGesamtStrecke;
	return dGesamtVerbrauch;
}


//Tanken für Fahrzeuge mit Tank
double PKW::dTanken(double dMenge = VOLLTANKEN)
{
	if (dMenge == VOLLTANKEN || dMenge > p_dTankvolumen - p_dTankinhalt) {
		dMenge = p_dTankvolumen - p_dTankinhalt;
		p_dTankinhalt = p_dTankvolumen; // Gefüllt
		return dMenge;
	}
	else {
		p_dTankinhalt += dMenge; // Nicht Voll
	}

	return dMenge;
}


//Abfertigung mit Tankaktualisierung
void PKW::vAbfertigung()
{
	if (p_dTankinhalt > 0)
	{
		double deltaTankinhalt = -(((dGlobaleZeit - p_dZeit)*p_dMaxGeschwindigkeit*p_dVerbrauch) / 100);
		Fahrzeug::vAbfertigung();
		p_dTankinhalt += deltaTankinhalt;
		
		if (p_dTankinhalt <= 0)
		{
			p_dTankinhalt = 0;
		}
	}
	p_dZeit = dGlobaleZeit;
}


//Ausgabe mit Tankinhalt und Gesamtverbrauch
void PKW::vAusgabe(void)
{
	double dGesamtverbrauch = dVerbrauch();
	Fahrzeug::vAusgabe();
	cout << left << setw(18) << setfill(' ') << setprecision(2) << dGesamtverbrauch;
	cout << left << setw(18) << setfill(' ') << setprecision(2) << p_dTankinhalt;
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

double PKW::dGetGeschwindigkeit()
{
	return dGeschwindigkeit();
}

string PKW::sGetName()
{
	return p_sName;
}


//Spezifizierung der Ausgabe für PKW
ostream& PKW::ostreamAusgabe(ostream& output)
{

	cout << setfill(' '); // Reset Fill
	output << setfill(' ');
	output << left << setw(8) << setfill(' ') << p_iID;
	output << left << setw(8) << setfill(' ') << p_sName;
	output << left << setw(3) << setfill(' ') << ":";
	output << fixed;
	output << left << setw(12) << setfill(' ') << setprecision(2) << dGeschwindigkeit();
	output << left << setw(18) << setfill(' ') << setprecision(2) << p_dGesamtStrecke;
	output << left << setw(18) << setfill(' ') << setprecision(2) << dVerbrauch();
	output << left << setw(18) << setfill(' ') << setprecision(2) << p_dTankinhalt;
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
