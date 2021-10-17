#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <tchar.h>
using namespace std;

#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"

double dGlobaleZeit = 0.0;

void Tabellenkopf()
{
	cout << endl << " "
		 << setw(3)  << "ID" << "   "
		 << resetiosflags(ios::right) << setiosflags(ios::left) // linksbündig
		 << setw(15) << "Name" << ":    "
		 << setw(10) << "MaxKmh" << ""
		 << setw(10) << "Gesamtstrecke" << "  "
		 << setw(10) << "Gesamtverbrauch" << "  "
		 << setw(10) << "Tankinhalt" << "  "
		 << setw(10) << "Geschwindigkeit" << endl;
	cout << "------------------------------------------------"
		 << "------------------------------------------------";
	cout << endl;

}

void vAufgabe_1()
{
	Tabellenkopf();
	Fahrzeug * uwe  = new Fahrzeug("Uwe", 25.00);
	Fahrzeug * karl = new Fahrzeug("Karl", 30.02);
	Fahrzeug * mike = new Fahrzeug("Mike", 100.00);
	Fahrzeug * ben  = new Fahrzeug("Ben", 5.00);

	Fahrzeug pkw("Pkw", 100);

	pkw.vAusgabe();
	cout << endl;


	uwe->vAusgabe();
	cout << endl;
	karl->vAusgabe();
	cout << endl;
	mike->vAusgabe();
	cout << endl;
	ben->vAusgabe();
	cout << endl;

	cout << endl;
		
	while(dGlobaleZeit <= 5)
	{
		dGlobaleZeit += 1.0;
		uwe->vAbfertigung();
		karl->vAbfertigung();
		mike->vAbfertigung();
		ben->vAbfertigung();

		uwe->vAusgabe();
		cout << endl;
		karl->vAusgabe();
		cout << endl;
		mike->vAusgabe();
		cout << endl;
		ben->vAusgabe();
		cout << endl;

		cout << endl;
	}

delete uwe;
delete karl;
delete mike;
delete ben;

}


/*void vAufgabe_1_deb()
{
	Fahrzeug * cars[4];

	cars[0] = new Fahrzeug("Mike 2", 50.00);
	cars[1] = new Fahrzeug("Karl 2", 30.02);
	cars[2] = new Fahrzeug("Mike 2", 100.00);
	cars[3] = new Fahrzeug("Ben 2" , 5.00);

	Tabellenkopf();
	for(int i=0; i<4; i++)
	{
		cars[i]->vAusgabe();
		cout << endl;
	}

	//cars[2] = 0;
	cout << "Pointer manipuliert" << endl;

	//Tabellenkopf();
	for(int i=0; i<4; i++)
	{
		cars[i]->vAusgabe();
		cout << endl;
	}
	
	/////////////////////

	// DELETE !!! 

	/////////////////////
}*/


void vAufgabe_2()
{
	int iAnzahlPKW;
	int iAnzahlFR;
	Fahrrad* FRpointer;
	PKW* PKWpointer;

	do
	{
		cout << endl << "Wie viele PKW's sollen erstellt werden? ";
		cin >> iAnzahlPKW;
	}
	while (iAnzahlPKW<0);

	do
	{
		cout << endl << "Wie viele Fahrraeder sollen erstellt werden? ";
		cin >> iAnzahlFR;
	}
	while (iAnzahlFR<0);

	vector<Fahrzeug*> ListeFahrzeuge(iAnzahlPKW+iAnzahlFR);

	ListeFahrzeuge.clear();
	for (int i=0; i<iAnzahlPKW; i++)
	{
		PKWpointer = new PKW();
		PKWpointer->anlegen();
		ListeFahrzeuge.push_back(PKWpointer);
	}

	for (int j=0; j<iAnzahlFR; j++)
	{
		FRpointer = new Fahrrad();
		FRpointer->anlegen();
		ListeFahrzeuge.push_back(FRpointer);
	}

	vector<Fahrzeug*>::iterator Vpointer;
	Tabellenkopf();

	for (Vpointer=ListeFahrzeuge.begin(); Vpointer != ListeFahrzeuge.end(); ++Vpointer)
	{
		(*Vpointer)->vAusgabe();
	}
	cout << endl;

	while(dGlobaleZeit <= 2.5)
	{
		dGlobaleZeit += 0.5;
		for (Vpointer=ListeFahrzeuge.begin(); Vpointer != ListeFahrzeuge.end(); ++Vpointer)
		{
			(*Vpointer)->vAbfertigung();
			(*Vpointer)->vAusgabe();
		}
		cout << endl;
	}

	for (Vpointer=ListeFahrzeuge.begin(); Vpointer!=ListeFahrzeuge.begin()+iAnzahlPKW; ++Vpointer)
	{
		cout << (*Vpointer)->GetName() <<" hat " << (*Vpointer)->dTanken() << " Liter getankt." << endl;
	}

	cout << endl;
	for (Vpointer=ListeFahrzeuge.begin(); Vpointer != ListeFahrzeuge.end(); ++Vpointer)
	{
			(*Vpointer)->vAusgabe();
	}
	cout << endl;

}

/*void vAufgabe_3()
{
	Fahrzeug meinFahrzeug("Testfahrzeug",120);
	Fahrrad meinFahrrad("Testfahrrad",30);
	PKW meinPKW("Testpkw", 120, 100, 10);


	Tabellenkopf();

	cout << meinFahrzeug << endl;
	cout << meinFahrrad;
	cout << meinPKW << endl;

	PKW sarah("Sarah", 120,100,10);
	PKW sophie("Sophie", 150,100,10);
	PKW sophie2(" ",0);

	dGlobaleZeit += 0.5;

	sarah.vAbfertigung();
	sophie.vAbfertigung();

	sophie2 = sophie; 

	cout << sarah;
	cout << sophie;
	cout << sophie2;

	cout << endl;

	if (sarah < sophie)
	{
		cout << "Sarah liegt hinter Sophie" << endl << endl;
	}
	else 
	{
		cout << "Sarah liegt vorne." << endl << endl;
	}
}*/
void main()
{
	
	//vAufgabe_1();
	//vAufgabe_1_deb();
	vAufgabe_2();
	//vAufgabe_3();


	char c = getchar();
	cin.get(); //Auf Eingabe warten, damit Konsole nicht direkt verschwindet.
}
