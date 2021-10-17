#include <iostream>
#include <math.h>
#include <vector>
#include "Fahrzeug.h"
#include "Fahrrad.h"
#include "PKW.h"

// epsilon-Konstante für Vergleiche:
#define EPSILON 0.000001

using namespace std;

// "Globale Uhr":
double dGlobaleZeit = 0.0;

// Vergleichsfunktion für floats:
bool bEqualsAbout(double d1, double d2)
{
	return abs(d1 - d2) < EPSILON;
}

// Kopfzeile der Tabelle ausgeben (mit stream):
ostream& ostreamKopfzeile(ostream& ostreamStream)
{
	ostreamStream << "ID  Name         :   MaxKmh   AktKmh  GesamtStrecke  Tankinhalt  GesVerbrauch" << endl <<
					 "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	return ostreamStream;
}

void vAufgabe_1()
{
	// Teste das Erzeugen und Löschen von Fahrzeugen
	Fahrrad fRobert("Robert", 25);
	PKW fAnna("Anna", 80);

	string sFahrzeugName;
	cout << "Name fuer das geklaute Fahrzeug eingeben: ";
	cin >> sFahrzeugName;
	PKW *fGeklaut = new PKW(sFahrzeugName, 50);
	PKW *fVergessen = new PKW();

	delete fVergessen;
	delete fGeklaut;

	// Ausgabe:
	// Kopfzeile:
	cout << "ID  Name         :   MaxKmh   AktKmh  GesamtStrecke  Tankinhalt  GesVerbrauch" << endl <<
		    "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;


	while(dGlobaleZeit < 8)
	{
		fRobert.vAbfertigung();
		fRobert.vAusgabe();
		cout << endl;
		fAnna.vAbfertigung();
		fAnna.vAusgabe();
		cout << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		dGlobaleZeit += 0.5;
	}
}

void vAufgabe_1_deb()
{
	Fahrzeug *fFahrzeuge[4];

	fFahrzeuge[0] = new PKW("Jans Auto", 50);
	fFahrzeuge[1] = new Fahrrad("Imkes E-Bike", 25);
	fFahrzeuge[2] = new PKW("Freds Motorrad", 55);
	fFahrzeuge[3] = new Fahrrad("Sebis E-Bike", 30);

	// Kopfzeile:
	cout << "ID  Name         :   MaxKmh   AktKmh   GesamtStrecke" << endl <<
		    "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

	for(int i = 0; i < 4; i++)
	{
		fFahrzeuge[i]->vAusgabe();
		cout << endl;
	}

	fFahrzeuge[2] = 0;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

	for(int i = 0; i < 4; i++)
	{
		fFahrzeuge[i]->vAusgabe();
		cout << endl;
	}

	// dynamische Objekte löschen:
	delete fFahrzeuge[0];
	delete fFahrzeuge[1];
	delete fFahrzeuge[2];
	delete fFahrzeuge[3];
}

void vAufgabe_2()
{
	// Eingabe über die Konsole:
	int iPKWNum, iFahrradNum;
	cout << "Wie viele PKWs sollen erzeugt werden? ";
	cin >>iPKWNum;
	cout << "Wie viele Fahrraeder sollen erzeugt werden? ";
	cin >> iFahrradNum;

	// vector erzeugen:
	vector<Fahrzeug*> vecFahrzeuge;

	// PKWs erzeugen:
	for(int i = 0; i < iPKWNum; i++)
	{
		PKW *PKWTmp = new PKW("PKW " + to_string(i+1), 60);
		vecFahrzeuge.push_back(PKWTmp);
	}

	// Fahrräder erzeugen:
	for(int i = 0; i < iFahrradNum; i++)
	{
		Fahrrad *FahrradTmp = new Fahrrad("FAHRRAD " + to_string(i+1), 22);
		vecFahrzeuge.push_back(FahrradTmp);
	}

	// Kopfzeile:
	cout << "ID  Name         :   MaxKmh   AktKmh  GesamtStrecke  Tankinhalt  GesVerbrauch" << endl <<
		    "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

	while(dGlobaleZeit < 8)
	{
		for(int i = 0; i < vecFahrzeuge.size(); i++)
		{
			// abfertigen:
			vecFahrzeuge[i]->vAbfertigung();

			// nach 3 Stunden volltanken:
			if(bEqualsAbout(dGlobaleZeit, 3.0))
			{
				vecFahrzeuge[i]->dTanken();
			}

			// ausgeben:
			vecFahrzeuge[i]->vAusgabe();
			cout << endl;
		}
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

		dGlobaleZeit += 0.5;
	}

	// dynamische Objekte löschen:
	for(int i = 0; i < vecFahrzeuge.size(); i++)
	{
		delete vecFahrzeuge[i];
	}
}

void vAufgabe_3()
{
	// Eingabe über die Konsole:
	int iPKWNum, iFahrradNum;
	cout << "Wie viele PKWs sollen erzeugt werden? ";
	cin >>iPKWNum;
	cout << "Wie viele Fahrraeder sollen erzeugt werden? ";
	cin >> iFahrradNum;

	// vector erzeugen:
	vector<Fahrzeug*> vecFahrzeuge;

	// PKWs erzeugen:
	for(int i = 0; i < iPKWNum; i++)
	{
		PKW *PKWTmp = new PKW("PKW " + to_string(i+1), 60);
		vecFahrzeuge.push_back(PKWTmp);
	}

	// Fahrräder erzeugen:
	for(int i = 0; i < iFahrradNum; i++)
	{
		Fahrrad *FahrradTmp = new Fahrrad("FAHRRAD " + to_string(i+1), 22);
		vecFahrzeuge.push_back(FahrradTmp);
	}

	// Kopfzeile:
	ostreamKopfzeile(cout);

	while(dGlobaleZeit < 8)
	{
		for(int i = 0; i < vecFahrzeuge.size(); i++)
		{
			// abfertigen:
			vecFahrzeuge[i]->vAbfertigung();

			// nach 3 Stunden volltanken:
			if(bEqualsAbout(dGlobaleZeit, 3.0))
			{
				vecFahrzeuge[i]->dTanken();
			}

			// ausgeben:
			// Achtung: Zeiger verwenden!
			cout << *vecFahrzeuge[i] << endl;
		}
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

		dGlobaleZeit += 0.5;
	}

	PKW *PKW1 = new PKW("PKW1", 30, 8.5, 60);
	PKW *PKW2 = new PKW("PKW2", 20, 6.3, 35);

	PKW1->vAbfertigung();
	PKW2->vAbfertigung();

	cout << "\n\nTeste Vergleichsoperatoren...\n";
	ostreamKopfzeile(cout);
	cout << *PKW1 << endl << *PKW2 << endl;

	if(*PKW1 < *PKW2)
		cout << "\nErgebnis: PKW1 < PKW2" << endl;
	else if(*PKW1 > *PKW2)
		cout << "\nErgebnis: PKW1 > PKW2" << endl;
	else if(*PKW1 == *PKW2)
		cout << "\nErgebnis: PKW1 == PKW2" << endl;
	else
		cout << "\nErgebnis: Keine Abfrage ergibt TRUE." << endl;

	cout << "\n\nErstelle neuen PKW und nutze Zuweisungsoperator..." << endl;
	PKW *PKW3 = new PKW("PKW3", 10);
	*PKW3 = *PKW1;
	ostreamKopfzeile(cout);
	cout << *PKW3 << endl;

	cout << "\n\nErstelle neuen PKW mit Copykonstruktor..." << endl;
	PKW PKW4(*PKW2);
	ostreamKopfzeile(cout);
	cout << PKW4 << endl;

	// PKW 1-3 löschen, da diese dynamische Objekte sind:
	delete PKW1;
	delete PKW2;
	delete PKW3;
	// ebenso Fahrzeuge im vector:
	for(int i = 0; i < vecFahrzeuge.size(); i++)
	{
		delete vecFahrzeuge[i];
	}
}

int main()
{
	//vAufgabe_1();
	//vAufgabe_1_deb();
	//vAufgabe_2();
	vAufgabe_3();
	return 0;
}