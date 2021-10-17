#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include "Fahrzeug.h"
#include "Fahrrad.h"
#include "PKW.h"
#include "Weg.h"
#include "SimuClient.h"
#include "LazyListe.h"

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
		for(unsigned int i = 0; i < vecFahrzeuge.size(); i++)
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
	for(unsigned int i = 0; i < vecFahrzeuge.size(); i++)
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
		for(unsigned int i = 0; i < vecFahrzeuge.size(); i++)
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
	for(unsigned int i = 0; i < vecFahrzeuge.size(); i++)
	{
		delete vecFahrzeuge[i];
	}
}

void vAufgabe_4()
{
	Weg *wTemplergraben = new Weg("TEMPLGR", 0.6, Innerorts);

	cout << endl << endl << "Erstelle Weg und gebe ihn aus..." << endl << *wTemplergraben << endl;
	
	PKW *pkwAudi = new PKW("Audi", 180);
	Fahrrad *frdMountainbike = new Fahrrad("Bike", 24);
	
	wTemplergraben->vAnnahme(pkwAudi);
	wTemplergraben->vAnnahme(frdMountainbike);
	
	dGlobaleZeit += 0.01;

	wTemplergraben->vAbfertigung();

	cout << endl << ostreamKopfzeile <<
		*pkwAudi << endl <<
		*frdMountainbike << endl <<
		*wTemplergraben << endl;

	dGlobaleZeit += 0.01;

	wTemplergraben->vAbfertigung();

	cout << endl << ostreamKopfzeile <<
		*pkwAudi << endl <<
		*frdMountainbike << endl <<
		*wTemplergraben << endl;

	dGlobaleZeit += 0.01;

	wTemplergraben->vAbfertigung();

	cout << endl << ostreamKopfzeile <<
		*pkwAudi << endl <<
		*frdMountainbike << endl <<
		*wTemplergraben << endl;

	delete wTemplergraben;
	delete pkwAudi;
	delete frdMountainbike;
}

void vAufgabe_5()
{
	Weg *wTemplergraben = new Weg("TEMPLGR", 0.6, Innerorts);
	PKW *pkwAudi = new PKW("Audi", 180);
	PKW *pkwVW = new PKW("VW", 130);
	Fahrrad *frdMountainbike = new Fahrrad("Bike", 24);
	
	wTemplergraben->vAnnahme(pkwAudi, 0.005);
	wTemplergraben->vAnnahme(pkwVW);
	wTemplergraben->vAnnahme(frdMountainbike);
	
	dGlobaleZeit += 0.01;

	wTemplergraben->vAbfertigung();

	cout << endl << ostreamKopfzeile <<
		*pkwAudi << endl <<
		*pkwVW << endl <<
		*frdMountainbike << endl <<
		*wTemplergraben << endl;

	dGlobaleZeit += 0.01;

	wTemplergraben->vAbfertigung();

	cout << endl << ostreamKopfzeile <<
		*pkwAudi << endl <<
		*pkwVW << endl <<
		*frdMountainbike << endl <<
		*wTemplergraben << endl;

	dGlobaleZeit += 0.01;

	wTemplergraben->vAbfertigung();

	cout << endl << ostreamKopfzeile <<
		*pkwAudi << endl <<
		*pkwVW << endl <<
		*frdMountainbike << endl <<
		*wTemplergraben << endl;


	// GRAFISCHE AUSGABE
	bInitialisiereGrafik(800, 500);
	int coord[] = {320, 300, 680, 300};
	bZeichneStrasse("W24", "W42", 500, 2, coord);
	Weg *w24 = new Weg("W24", 500, Landstrasse);
	Weg *w42 = new Weg("W42", 500, Landstrasse);

	Fahrzeug *fFahrzeuge[4];
	fFahrzeuge[0] = new PKW("PKW1", 120);
	fFahrzeuge[1] = new PKW("PKW2", 80);
	fFahrzeuge[2] = new PKW("PKW3", 150);
	fFahrzeuge[3] = new Fahrrad("FAHRRAD1", 26);

	w24->vAnnahme(fFahrzeuge[0], 2);
	w24->vAnnahme(fFahrzeuge[1]);
	w42->vAnnahme(fFahrzeuge[2], 3);
	w42->vAnnahme(fFahrzeuge[3]);

	for(dGlobaleZeit = 0.0; dGlobaleZeit < 10; dGlobaleZeit += 0.05)
	{
		vSetzeZeit(dGlobaleZeit);
		w24->vAbfertigung();
		w42->vAbfertigung();

		cout << "Globale Zeit: " << dGlobaleZeit << endl;
		cout << *w24 << endl << endl;

		vSleep(50);
	}


	cout << endl << endl << "Druecken Sie eine Taste, um die Simulation zu beenden..." << endl;
	getchar();
	vBeendeGrafik();

	delete wTemplergraben;
	delete pkwAudi;
	delete pkwVW;
	delete frdMountainbike;
	delete w24;
	delete w42;
	delete fFahrzeuge[0];
	delete fFahrzeuge[1];
	delete fFahrzeuge[2];
	delete fFahrzeuge[3];
}

void vAufgabe_6()
{
	// GRAFISCHE AUSGABE
	bInitialisiereGrafik(800, 500);
	int coord[] = {320, 300, 680, 300};
	bZeichneStrasse("W24", "W42", 500, 2, coord);
	Weg *w24 = new Weg("W24", 500, Autobahn);
	Weg *w42 = new Weg("W42", 500, Landstrasse);

	Fahrzeug *fFahrzeuge[4];
	fFahrzeuge[0] = new PKW("PKW1", 180, 8, 145);
	fFahrzeuge[1] = new PKW("PKW2", 80);
	fFahrzeuge[2] = new PKW("PKW3", 150);
	fFahrzeuge[3] = new Fahrrad("FAHRRAD1", 26);

	w24->vAnnahme(fFahrzeuge[0], 2);
	w24->vAnnahme(fFahrzeuge[1]);
	w42->vAnnahme(fFahrzeuge[2], 3);
	w42->vAnnahme(fFahrzeuge[3]);

	for(dGlobaleZeit = 0.0; true; dGlobaleZeit += 0.05)
	{
		vSetzeZeit(dGlobaleZeit);
		w24->vAbfertigung();
		w42->vAbfertigung();

		cout << "Globale Zeit: " << dGlobaleZeit << endl;
		cout << *w24 << endl << endl;

		vSleep(20);
	}


	cout << endl << endl << "Druecken Sie eine Taste, um die Simulation zu beenden..." << endl;
	getchar();
	vBeendeGrafik();

	delete w24;
	delete w42;
	delete fFahrzeuge[0];
	delete fFahrzeuge[1];
	delete fFahrzeuge[2];
	delete fFahrzeuge[3];
}

void vAufgabe_6a()
{
	LazyListe<int> myLazyListe;
	for(int i = 0; i < 10; i++)
	{
		myLazyListe.push_back(rand() % 10 + 1);
	}
	myLazyListe.vAktualisieren();

	cout << "LazyListe erstellt und mit Zufallswerten gefuellt. Ausgeben..." << endl;

	for(LazyListe<int>::iterator it = myLazyListe.begin(); it != myLazyListe.end(); it++)
	{
		cout << *it << endl;
	}

	cout << endl << endl << "Elemente > 5 zum Loeschen markieren..." << endl;

	for(LazyListe<int>::iterator it = myLazyListe.begin(); it != myLazyListe.end(); it++)
	{
		if(*it > 5) myLazyListe.erase(it);
	}

	cout << "Vorher nochmal ausgeben..." << endl;

	for(LazyListe<int>::iterator it = myLazyListe.begin(); it != myLazyListe.end(); it++)
	{
		cout << *it << endl;
	}

	cout << endl << endl << "Jetzt aktualisieren..." << endl;

	myLazyListe.vAktualisieren();

	cout << "Wieder ausgeben..." << endl;
	
	for(LazyListe<int>::iterator it = myLazyListe.begin(); it != myLazyListe.end(); it++)
	{
		cout << *it << endl;
	}

	cout << endl << endl << "77 am Anfang und 99 am Ende einfuegen, aktualisieren und ausgeben..." << endl;

	myLazyListe.push_front(77);
	myLazyListe.push_back(99);
	myLazyListe.vAktualisieren();

	for(LazyListe<int>::iterator it = myLazyListe.begin(); it != myLazyListe.end(); it++)
	{
		cout << *it << endl;
	}

}

int main()
{
	//vAufgabe_1();
	//vAufgabe_1_deb();
	//vAufgabe_2();
	//vAufgabe_3();
	//vAufgabe_4();
	//vAufgabe_5();
	vAufgabe_6();
	//vAufgabe_6a();
	return 0;
}