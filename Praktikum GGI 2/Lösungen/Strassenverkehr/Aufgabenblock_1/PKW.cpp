#include "PKW.h"
#include <string>
#include <iostream>
#include <iomanip>


extern double dGlobaleZeit;

// Standard Konstruktor mit Tankvolumen 55 Liter, Inhalt 27,5 Liter, Verbrauch 6 Liter
PKW::PKW(string sName, double dMaxSpeed):Fahrzeug(sName, dMaxSpeed)
{
	p_dTankvolumen = 55;
	p_dTankinhalt = p_dTankvolumen / 2;
	p_dVerbrauch = 6;
}

// Konstruktor 
PKW::PKW(std::string sName, double dMaxSpeed, double dTankVolumen, double dVerbrauch):Fahrzeug(sName,dMaxSpeed)
{
	p_dVerbrauch = dVerbrauch;
	p_dTankvolumen = dTankVolumen;
	p_dTankinhalt = p_dTankvolumen / 2;
}

// Gibt aktuelle Geschwindigkeit aus, bei PKW immer maximale Geschwindigkeit
double PKW::dGeschwindigkeit()
{
	return p_dMaxGeschwindigkeit;
}

//Gibt gesamten Verbrauch an, seit Beginn der Simulation
double PKW::dVerbrauch()
{
	return (p_dVerbrauch * p_dGesamtStrecke / 100);
}

//vAusgabe Erweiterung der Klasse Fahrzeug
void PKW::vAusgabe()
{
	Fahrzeug::vAusgabe();
	cout << "        "
		 << setw(10)<< fixed << dVerbrauch() << "    "
		 << setw(10)<< fixed << p_dTankinhalt <<
		 endl;
}

// Standardmaessig wird vollgetankt, wenn dMenge=0, sonst dMenge
// falls status=true, Kommentar wie viel getankt wurde
double PKW::dTanken(double dMenge, bool status)
{
	double dGetankt;

	if (dMenge == 0) //Default
	{
		dGetankt = p_dTankvolumen;
		p_dTankinhalt = p_dTankvolumen;
	}
	else if (dMenge > 0) //Bestimmte Menge tanken
	{
		dGetankt = dMenge;
		p_dTankinhalt += dMenge;

		if (p_dTankinhalt > p_dTankvolumen) //Falls zuviel getankt, setze auf voll getankt
			p_dTankinhalt = p_dTankvolumen;
	}

	if (status == true)
	{
		cout << "PKW " << p_sName << " hat " << dGetankt << " Liter getankt." << endl;
		return 0;
	}
	else
	{
		return dGetankt;
	}
}

//Abfertigen nur falls Tank noch nicht leer ist.
void PKW::vAbfertigung()
{
	if (p_dTankinhalt > 0)
	{
		//Berechne aktuellen Verbrauch auf letzter Strecke
		double dAktuellerVerbrauch = (dGlobaleZeit-p_dZeit)*p_dMaxGeschwindigkeit*p_dVerbrauch/100.0;
		//Tankinhalt aktualisieren
		p_dTankinhalt -= dAktuellerVerbrauch;
		//Falls Tankinhalt negativ, setze auf Null
		if(p_dTankinhalt < 0) p_dTankinhalt = 0;
		//verfahre sonst wie vAbfertigung aus Fahrzeug Klasse
		Fahrzeug::vAbfertigung();
	}
	else
	{
		p_dTankinhalt = 0;
	}
}

void PKW::anlegen()
{
	string sName;
	double dMaxSpeed, dTankvolumen, dVerbrauch;
	cout << endl << "********* Neuen PKW anlegen *********" << endl;
	cout << "Name  : ";
	cin >> sName;
	cout << endl << "Max. Geschwindigkeit  : ";
	cin >> dMaxSpeed;
	cout << endl << "Tankvolumen (default: 55L) : ";
	cin >> dTankvolumen;
	cout << endl << "Verbrauch (default: 6L) : ";
	cin >> dVerbrauch;
	cout << endl << "******* PKW angelegt (ID : " << p_iID << ") *******" << endl;

	p_sName = sName;
	p_dMaxGeschwindigkeit = dMaxSpeed;
	p_dTankvolumen = dTankvolumen;
	p_dTankinhalt = p_dTankvolumen / 2;
	p_dVerbrauch = dVerbrauch;
}

ostream& PKW::ostreamAusgabe(ostream& Stream)
{
	Fahrzeug::ostreamAusgabe(Stream)<< "        "
		 << setw(10)<< fixed << dVerbrauch() << "    "
		 << setw(10)<< fixed << p_dTankinhalt <<
		 endl;
	return Stream;
}
