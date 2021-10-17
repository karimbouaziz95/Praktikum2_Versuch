#include <string>
#include <iomanip>
#include <iostream>

#include "Tabellenkopf.h"

using namespace std;

void Tabellenkopf::fahrzeug()
{
	//Ausgabe des Tabellenkopf
	resetiosflags(ios::right); //vorher gesetzte Flags zurücksetzen.
	setiosflags(ios::right); //rechtsbündig
	cout << endl << " "
	     << "ID" << "    "
		 << resetiosflags(ios::right) << setiosflags(ios::left) // wieder linksbündig
		 << setw(15) << "Name" << ":    "
		 << setw(9) << "MaxKmh" << ""
		 << setw(9) << "(G)Strecke" << "  "
		 << setw(9) << "(A)Strecke" << "  "
		 << setw(9) << "(G)Verbrauch" << "  "
		 << setw(9) << "Tankinhalt" << "    "
		 << setw(9) << "Km/h" << endl;
	cout << "-------------------------------------------------"
		 << "-------------------------------------------------";
	cout << endl;
}

void Tabellenkopf::verkehrsobjekt()
{
	resetiosflags(ios::right); //vorher gesetzte Flags zurücksetzen.
	setiosflags(ios::right); //rechtsbündig
	cout << endl << " "
		 << "ID" << "    "
		 << resetiosflags(ios::right) << setiosflags(ios::left) // wieder linksbündig
		 << setw(15) << "Name" << endl;
	cout << "----------------------------------------"
		 << "----------------------------------------";
	cout << endl;
}

void Tabellenkopf::weg()
{
	//bla
	resetiosflags(ios::right); //vorher gesetzte Flags zurücksetzen.
	setiosflags(ios::right); //rechtsbündig
	cout << endl << " "
		 << "ID" << "    "
		 << resetiosflags(ios::right) << setiosflags(ios::left) // wieder linksbündig
		 << setw(15) << "Name" << "  "
		 << setw(10) << "Laenge" << "  "
		 << setw(10) << "Fahrzeuge" << endl;
	cout << "----------------------------------------"
		 << "----------------------------------------";
	cout << endl;
}

void Tabellenkopf::kreuzung()
{
	resetiosflags(ios::right);
	setiosflags(ios::right);
	cout << endl << " "
		 << "ID" << "    "
		 << resetiosflags(ios::right) << setiosflags(ios::left)
		 << setw(15) << "Name" << "  "
		 << setw(12) << "Tankstelle" << "  "
		 << setw(10) << "Wege" << endl;
	cout << "----------------------------------------"
		 << "----------------------------------------";
	cout << endl;	
}