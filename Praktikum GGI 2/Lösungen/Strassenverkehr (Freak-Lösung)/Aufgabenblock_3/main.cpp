#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <string>
#include "Fahrzeug.h"
#include "Fahrrad.h"
#include "PKW.h"
#include "Weg.h"
#include "SimuClient.h"
#include "LazyListe.h"
#include "Kreuzung.h"
#include "Welt.h"

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

void vAufgabe_7()
{
	// GRAFISCHE AUSGABE
	bInitialisiereGrafik(800, 500);
	int coord[] = {320, 300, 680, 300};
	bZeichneStrasse("w24", "w42", 100, 2, coord);
	Weg *w24 = new Weg("w24", 100, Innerorts, true);
	Weg *w42 = new Weg("w42", 100, Innerorts);
	
	Fahrrad *f1 = new Fahrrad("f1", 28);
	PKW *p1 = new PKW("p1", 140, 8.4, 10);
	PKW *p2 = new PKW("p2", 120, 7.3, 40);

	w24->vAnnahme(f1, 1);
	w24->vAnnahme(p1, 0.8);

	for(dGlobaleZeit = 0.0; dGlobaleZeit <= 5.0; dGlobaleZeit += 0.05)
	{
		vSetzeZeit(dGlobaleZeit);
		w24->vAbfertigung();
		w42->vAbfertigung();

		cout << "Globale Zeit: " << dGlobaleZeit << endl;
		cout << *w24 << endl << endl;

		vSleep(20);

		if(bEqualsAbout(dGlobaleZeit, 2.0))
		{
			w24->vAnnahme(p2, 2.7);
		}
	}

	delete w24;
	delete w42;
	delete f1;
	delete p1;
	delete p2;
}

void vAufgabe_8()
{
	// GRAFISCHE AUSGABE
	bInitialisiereGrafik(1300, 800);

	Kreuzung *kr1 = new Kreuzung("kr1");
	bZeichneKreuzung(680, 40);
	Kreuzung *kr2 = new Kreuzung("kr2", 1000);
	bZeichneKreuzung(680, 300);
	Kreuzung *kr3 = new Kreuzung("kr3");
	bZeichneKreuzung(680, 570);
	Kreuzung *kr4 = new Kreuzung("kr4");
	bZeichneKreuzung(320, 300);
	
	// VERBINDEN   wHin		wZur	km		Krzg	Begrenzung		Überholv.
	kr1->vVerbinde("w12",	"w21",	40,		kr2,	Innerorts,		true);
	kr2->vVerbinde("w23a",	"w32a", 115,	kr3,	Autobahn,		false);
	kr2->vVerbinde("w23b",	"w32b", 40,		kr3,	Innerorts,		true);
	kr2->vVerbinde("w24",	"w42",	55,		kr4,	Innerorts,		true);
	kr3->vVerbinde("w34",	"w43",	85,		kr4,	Autobahn,		false);
	kr4->vVerbinde("w44a",	"w44b", 130,	kr4,	Landstrasse,	false);

	int coord1[] = {680, 40, 680, 300};
	bZeichneStrasse("w12", "w21", 40, 2, coord1);
	int coord2[] = {680, 300, 850, 300, 970, 390, 970, 500, 850, 570, 680, 570};
	bZeichneStrasse("w23a", "w32a", 115, 6, coord2);
	int coord3[] = {680, 300, 680, 570};
	bZeichneStrasse("w23b", "w32b", 40, 2, coord3);
	int coord4[] = {680, 300, 320, 300};
	bZeichneStrasse("w24", "w42", 55, 2, coord4);
	int coord5[] = {680, 570, 500, 570, 350, 510, 320, 420, 320, 300};
	bZeichneStrasse("w34", "w43", 85, 5, coord5);
	int coord6[] = {320, 300, 170, 300, 70, 250, 80, 90, 200, 60, 320, 150, 320, 300};
	bZeichneStrasse("w44a", "w44b", 130, 7, coord6);

	Fahrrad *f1 = new Fahrrad("f1", 28);
	PKW *p1 = new PKW("p1", 140, 8.4, 10);
	PKW *p2 = new PKW("p2", 120, 7.3, 40);
	
	kr1->vAnnahme(f1, 0.6);
	kr2->vAnnahme(p1, 1);
	kr4->vAnnahme(p2, 0.2);

	cout << "Kreuzungen ausgeben: " << endl;
	cout << *kr1 << endl
		 << *kr2 << endl
		 << *kr3 << endl
		 << *kr4 << endl;

	for(dGlobaleZeit = 0.0; true; dGlobaleZeit += 0.02)
	{
		vSetzeZeit(dGlobaleZeit);
		kr1->vAbfertigung();
		kr2->vAbfertigung();
		kr3->vAbfertigung();
		kr4->vAbfertigung();

		cout << "Globale Zeit: " << dGlobaleZeit << endl;

		vSleep(2);
	}

	cout << endl << endl << "Druecken Sie eine Taste, um die Simulation zu beenden..." << endl;
	getchar();
	vBeendeGrafik();

	delete kr1;
	delete kr2;
	delete kr3;
	delete kr4;
}

void vAufgabe_9_1()
{
	// Testdatei einlesen
	ifstream ifstreamDatei("VO.dat");
	// überprüfe auf Erfolg:
	if(!ifstreamDatei.good())
	{
		cout << "Fehler beim Oeffnen der Datei." << endl;
		return;
	}

	// Daten einlesen:
	// Porsche 250 17 70
	// Rennrad 30
	// Kr1 800
	try {
		PKW* p1 = new PKW();
		Fahrrad* f1 = new Fahrrad();
		Kreuzung* kr1 = new Kreuzung();
		Kreuzung* kr1Nochmal = new Kreuzung("Kr1");

		ifstreamDatei >> *p1 >> *f1 >> *kr1;

		cout << ostreamKopfzeile 
			 << *p1 << endl
			 << *f1 << endl
			 << endl
			 << *kr1 << endl;
	}
	catch(string *sException)
	{
		cout << *sException << endl;
	}
}

void vAufgabe_9_3()
{
	// Datei einlesen
	ifstream ifstreamDatei("Simu1.dat");
	// überprüfe auf Erfolg:
	if(!ifstreamDatei.good())
	{
		cout << "Fehler beim Oeffnen der Datei." << endl;
		return;
	}

	Welt *w = new Welt();
	try {
		w->vEinlesen(ifstreamDatei);
	}
	catch(string *sException)
	{
		cout << *sException << endl;
	}
	/*
	for(dGlobaleZeit = 0; dGlobaleZeit <= 10; dGlobaleZeit += 0.02)
	{
		cout << "Globale Zeit: " << dGlobaleZeit << endl;
		w->vSimulation();
	}*/
}

void vAufgabe_9_6()
{
	// Datei einlesen
	ifstream ifstreamDatei("SimuDisplay.dat");
	// überprüfe auf Erfolg:
	if(!ifstreamDatei.good())
	{
		cout << "Fehler beim Oeffnen der Datei." << endl;
		return;
	}
	bInitialisiereGrafik(1000, 1000);

	Welt *w = new Welt();
	try {
		w->vEinlesenMitGrafik(ifstreamDatei);
	}
	catch(string *sException)
	{
		cout << *sException << endl;
	}


	for(dGlobaleZeit = 0; dGlobaleZeit <= 10; dGlobaleZeit += 0.02)
	{
		cout << "Globale Zeit: " << dGlobaleZeit << endl;
		//cout << ostreamKopfzeile << *((PKW*)AktivesVO::ptObjekt("Porsche")) << endl;
		vSetzeZeit(dGlobaleZeit);
		w->vSimulation();
	}

	cout << endl << endl << "Druecken Sie eine Taste, um die Simulation zu beenden..." << endl;
	getchar();
	vBeendeGrafik();
}

int main()
{
	//vAufgabe_1();
	//vAufgabe_1_deb();
	//vAufgabe_2();
	//vAufgabe_3();
	//vAufgabe_4();
	//vAufgabe_5();
	//vAufgabe_6();
	//vAufgabe_6a();
	//vAufgabe_7();
	//vAufgabe_8();
	//vAufgabe_9_1();
	//vAufgabe_9_3();
	vAufgabe_9_6();
	return 0;
}