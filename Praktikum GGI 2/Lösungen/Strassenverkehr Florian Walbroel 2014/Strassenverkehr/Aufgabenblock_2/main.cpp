#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <windows.h>

//fuer zufallszahlen
#include <stdlib.h>
#include <time.h>

using namespace std;

#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "Tabellenkopf.h"
#include "Weg.h"
#include "SimuClient.h"
#include "LazyListe.h"


double dGlobaleZeit = 0;

void vAufgabe_3()
{
	Fahrzeug meinFahrzeug("Testfahrzeug",120);
	Fahrrad meinFahrrad("Testfahrrad",30);
	PKW meinPKW("Testpkw", 120, 100, 10);


	Tabellenkopf::fahrzeug();

	cout << meinFahrzeug << endl;
	cout << meinFahrrad;
	cout << meinPKW << endl;

	Fahrzeug * sarah = new PKW("Sarah", 120,100,10);
	Fahrzeug * sophie = new PKW("Sophie", 150,100,10);
	Fahrzeug * sophie2 = new PKW(" ",0);

	Weg * Highway1a = new Weg("Highway-1a", 500);
	Weg * Highway1b = new Weg("Highway-1b", 500);

	cout << *sarah;
	cout << *sophie;
	cout << *sophie2 << endl;

	Highway1a->vAnnahme(sarah);
	Highway1a->vAnnahme(sophie);
	Highway1b->vAnnahme(sophie2);

	dGlobaleZeit += 0.5;

	Highway1a->vAbfertigung();
	Highway1b->vAbfertigung();

	*sophie2 = *sophie; 

	cout << *sarah;
	cout << *sophie;
	cout << *sophie2;

	cout << endl;

	if (sarah < sophie)
	{
		cout << "Sarah liegt hinter Sophie" << endl << endl;
	}
	else 
	{
		cout << "Sarah liegt vorne." << endl << endl;
	}

	delete sophie2;
	delete sophie;
	delete sarah;	
}

void vAufgabe_4()
{
	Weg * way = new Weg("Highway to Hell", 200);
	Fahrzeug * pkw1 = new PKW("Fahrzeug1", 100, 80, 9);
	Fahrzeug * pkw2 = new PKW("Fahrzeug2", 150, 80, 9);

	//Tabellenkopf::weg();
	//cout << *way << endl;

	Tabellenkopf::fahrzeug();
	cout << *pkw1 << *pkw2 << endl;

	way->vAnnahme(pkw1);
	way->vAnnahme(pkw2);

	Tabellenkopf::weg();
	cout << *way << endl;


	for(dGlobaleZeit=0; dGlobaleZeit <= 3; dGlobaleZeit += 20.0/60.0)
	{
		cout << endl << endl;
		cout << "+---------------------+" << endl
			 <<	"+ Globale Zeit:  " << setw(4) << dGlobaleZeit << " +" << endl
			 << "+---------------------+" << endl;

		way->vAbfertigung();
		//Tabellenkopf::weg();
		//cout << *way << endl;

		Tabellenkopf::fahrzeug();
		cout << *pkw1 << *pkw2 << endl;
	}

}
void vAufgabe_5()
{
	Weg * Highway1a = new Weg("Highway-1a", 500);
	Weg * Highway1b = new Weg("Highway-1b", 500);

	Fahrzeug * pkw1 = new PKW("Audi", 140, 120, 9);
	Fahrzeug * pkw2 = new PKW("Porsche", 140, 120, 9);

	Fahrzeug * pkw3 = new PKW("Twingo", 160, 200, 7.8);

	Highway1a->vAnnahme(pkw1);
	Highway1a->vAnnahme(pkw2, 1);

	Highway1b->vAnnahme(pkw3);

	Tabellenkopf::weg();
	cout << *Highway1a << endl
		 << *Highway1b << endl;

	bInitialisiereGrafik(800,500);
	int mase[4] = {600, 250, 100, 250};
	bZeichneStrasse("Highway-1a", "Highway-1b", 500, 2, mase);

	Tabellenkopf::fahrzeug();

	for(dGlobaleZeit=0; dGlobaleZeit <= 6; dGlobaleZeit += 0.3)
	{
		Highway1a->vAbfertigung();
		Highway1b->vAbfertigung();
		
		vSetzeZeit(dGlobaleZeit);
		Sleep(500);
		
		cout << *pkw1 << *pkw2 << *pkw3 << endl;
	}

	vBeendeGrafik();

}

void vAufgabe_6()
{
	Weg * Highway1a = new Weg("Highway-1a", 500);
	Weg * Highway1b = new Weg("Highway-1b", 500);

	Fahrzeug * pkw1 = new PKW("Audi", 140, 120, 9);
	Fahrzeug * pkw2 = new PKW("Porsche", 140, 120, 9);

	Fahrzeug * pkw3 = new PKW("Twingo", 160, 200, 7.8);
	Fahrzeug * fahrrad = new Fahrrad("Bike", 200);

	Highway1a->vAnnahme(pkw1);
	Highway1a->vAnnahme(pkw2, 1);

	Highway1b->vAnnahme(pkw3);
	Highway1b->vAnnahme(fahrrad);

	Tabellenkopf::weg();
	cout << *Highway1a << *Highway1b << endl;

	bInitialisiereGrafik(800,500);
	zzu
	bZeichneStrasse("Highway-1a", "Highway-1b", 500, 2, mase);


	for(dGlobaleZeit=0; dGlobaleZeit <= 6; dGlobaleZeit += 0.3)
	{
		Highway1a->vAbfertigung();
		Highway1b->vAbfertigung();
		
		vSetzeZeit(dGlobaleZeit);
		Sleep(500);
		
		Tabellenkopf::fahrzeug();
		cout << *pkw1 << *pkw2 << *pkw3 << *fahrrad << endl;
		Tabellenkopf::weg();
		cout << *Highway1a << *Highway1b << endl;
	}

	cout << endl;
	Tabellenkopf::weg();
	cout << *Highway1a << *Highway1b << endl;

	vBeendeGrafik();
}



void vAufgabe_6a()
{
	srand((int)time(0));
	LazyListe<int> zufall;
	LazyListe<int>::iterator Lpointer;
	int zahl;

	// Liste mit 20 Zufallszahlen fuellen (zwischen 1 und 10)
	for (int i=0; i<20; ++i)
	{
		zahl=(rand()%11);
		zufall.push_back(zahl);
	}
	zufall.vAktualisieren();

	//Liste ausgeben
	cout << "Liste mit Zufallszahlen: " << endl;

	for(Lpointer = zufall.begin(); Lpointer != zufall.end(); ++Lpointer)
	{
		cout << (*Lpointer) << " ";
		if((*Lpointer) > 5)
		{
			zufall.erase(Lpointer);
		}
	}
	cout << endl << endl << "Alle Zahlen groesser 5 loeschen, ohne Aktualisieren." << endl;

	//Zahlen >5 loeschen und erneut ausgeben
	for(Lpointer = zufall.begin(); Lpointer != zufall.end(); ++Lpointer)
	{
		cout << (*Lpointer) << " ";
	}

	cout << endl << "Liste aktualisiert." << endl;
	zufall.vAktualisieren();

	for(Lpointer = zufall.begin(); Lpointer != zufall.end(); ++ Lpointer)
	{
		cout << (*Lpointer) << " ";
	}

	zahl=(rand()%10 +1);
	zufall.push_front(zahl);
	zahl=(rand()%10 +1);
	zufall.push_back(zahl);


	cout << endl << "Liste aktualisiert. Neue Zahlen." << endl;
	zufall.vAktualisieren();

	for(Lpointer = zufall.begin(); Lpointer != zufall.end(); ++ Lpointer)
	{
		cout << (*Lpointer) << " ";
	};
	getchar();


}
void main()
{
	//vAufgabe_3();
	//vAufgabe_4();
	//vAufgabe_5();
	vAufgabe_6();
	//vAufgabe_6a();
	
	system("pause");
	char c = getchar();
	cin.get(); //Auf Eingabe warten, damit Konsole nicht direkt verschwindet.
}