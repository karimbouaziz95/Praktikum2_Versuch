#include "Fahrrad.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

extern double dGlobaleZeit;

Fahrrad::Fahrrad(string sName, double dMaxSpeed):Fahrzeug(sName, dMaxSpeed)
{
}

void Fahrrad::vAusgabe()
{
	Fahrzeug::vAusgabe();
	cout << "        "
		 << setw(10)<< fixed << "-" << "    "
		 << setw(10)<< fixed << "-" << "    "
		 << setw(10)<< fixed << dGeschwindigkeit() <<
		 endl;
}

double Fahrrad::dGeschwindigkeit()
{
	double dSpeed;
	double exponent = floor(p_dGesamtStrecke/20.00)+1;
	dSpeed = p_dMaxGeschwindigkeit*pow(0.9,floor(p_dGesamtStrecke/20));

	if (dSpeed <= 12) return 12;
	else return dSpeed;
}

void Fahrrad::anlegen()
{
	string sName;
	double dMaxSpeed;
	cout << endl << "******* Neues Fahrrad anlegen *******" << endl;
	cout << "Name  : ";
	cin >> sName;
	cout << endl << "Max. Geschwindigkeit  : ";
	cin >> dMaxSpeed;
	cout << endl << "***** Fahrrad angelegt (ID : " << p_iID << ") *****" << endl;

	p_sName = sName;
	p_dMaxGeschwindigkeit = dMaxSpeed;
}

ostream& Fahrrad::ostreamAusgabe(ostream& Stream)
{
	Fahrzeug::ostreamAusgabe(Stream) 
		 << "        "
		 << setw(10)<< fixed << "-" << "    "
		 << setw(10)<< fixed << "-" << "    "
		 << setw(10)<< fixed << dGeschwindigkeit() <<
		 endl;
	return Stream;
}