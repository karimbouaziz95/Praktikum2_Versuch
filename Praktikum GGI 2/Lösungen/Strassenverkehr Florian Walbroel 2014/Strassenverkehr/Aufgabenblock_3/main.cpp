#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

#include "AktivesVO.h"
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "Tabellenkopf.h"
#include "Weg.h"
#include "Kreuzung.h"
#include "SimuClient.h"
#include "LazyListe.h"
#include "Welt.h"


double dGlobaleZeit = 0;

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
	int mase[4] = {600, 250, 100, 250};
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
		zahl=(rand()%10 +1);
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
	}

}
void vAufgabe_7()
{
	Weg * Highway1a = new Weg("Highway-1a", 500);
	Weg * Highway1b = new Weg("Highway-1b", 500);

	Fahrzeug * parkend1 = new PKW("PKW", 100, 120, 9);
	Fahrzeug * parkend2 = new Fahrrad("Fahrrad", 100);

	Fahrzeug * haelfte = new PKW("Haelfte", 130, 200, 7.8);

	Highway1a->vAnnahme(parkend1,1);
	Highway1a->vAnnahme(parkend2);

	Tabellenkopf::weg();
	cout << *Highway1a << endl;

	bInitialisiereGrafik(800,500);
	int mase[4] = {600, 250, 100, 250};
	bZeichneStrasse("Highway-1a", "Highway-1b", 500, 2, mase);

	double dSchritte = 0.3;
	double dEnde = 8;

	for(dGlobaleZeit=0; dGlobaleZeit <= dEnde; dGlobaleZeit += dSchritte)
	{
		if (fabs(dGlobaleZeit - dEnde/2) < dSchritte/2)
		{
			Highway1a->vAnnahme(haelfte);
		}

		Highway1a->vAbfertigung();
		

		vSetzeZeit(dGlobaleZeit);
		Sleep(200);
		
		Tabellenkopf::weg();
		cout << *Highway1a << endl;
	}

	cout << endl;
	Tabellenkopf::weg();
	cout << *Highway1a << endl;

	vBeendeGrafik();

}
void vAufgabe_8()
{
	//Lege alle Strassen und Kreuzungen an.
	int strasse1[4]  = {680,300,680,40};
	int strasse2[12] = {680,570,850,570,970,500,970,390,850,300,680,300};
	int strasse3[4]  = {680,570,680,300};
	int strasse4[4]  = {320,300,680,300};
	int strasse5[10] = {320,300,320,420,350,510,500,570,680,570};
	int strasse6[14] = {320,300,170,300,70,250,80,90,200,60,320,150,320,300};

	bInitialisiereGrafik(1000,650);

	bZeichneStrasse("Str1_W12","Str1_W21",40,2,strasse1);
	bZeichneStrasse("Str2_W23a","Str2_W32a",115,6,strasse2);
	bZeichneStrasse("Str3_W23b","Str3_W32b",40,2,strasse3);
	bZeichneStrasse("Str4_W24","Str4_W42",55,2,strasse4);
	bZeichneStrasse("Str5_W34","Str5_W43",85,5,strasse5);
	bZeichneStrasse("Str6_W44a","Str6_W44b",130,7,strasse6);

	Kreuzung * kreuzung1 = new Kreuzung("Kreuzung-1",1000);
	Kreuzung * kreuzung2 = new Kreuzung("Kreuzung-2");
	Kreuzung * kreuzung3 = new Kreuzung("Kreuzung-3");
	Kreuzung * kreuzung4 = new Kreuzung("Kreuzung-4");

	//Kreuzung1
	bZeichneKreuzung(680,40);
	kreuzung1->vVerbinde("Str1_W12","Str1_W21",40,kreuzung2,Innerorts,true);

	//Kreuzung2
	bZeichneKreuzung(680,300); 
	kreuzung2->vVerbinde("Str2_W23a","Str2_W32a",115, kreuzung3,Autobahn,false);
	kreuzung2->vVerbinde("Str3_W23b","Str3_W32b",40, kreuzung3,Innerorts,true);
	kreuzung2->vVerbinde("Str4_W24","Str4_W42",55, kreuzung4,Innerorts,true);

	//Kreuzung3
	bZeichneKreuzung(680,570); 
	kreuzung3->vVerbinde("Str5_W34","Str5_W43", 85, kreuzung4,Autobahn, false);

	//Kreuzung4
	bZeichneKreuzung(320,300); 
	kreuzung4->vVerbinde("Str6_W44a","Str6_W44b", 130, kreuzung4,Landstraße,false);

	Fahrzeug* pkw = new PKW("VW", 120, 80, 10);
	Fahrzeug* pkw2 = new PKW("Audi", 140, 80, 10);
	Fahrzeug* fahrrad = new Fahrrad("Bike", 30);
	kreuzung1->vAnnahme(pkw, 0.5);
	kreuzung1->vAnnahme(pkw2, 0.75);
	kreuzung1->vAnnahme(fahrrad, 0);

	/*Tabellenkopf::weg();
	kreuzung1->vWegeAusgabe();
	kreuzung2->vWegeAusgabe();
	kreuzung3->vWegeAusgabe();
	kreuzung4->vWegeAusgabe();*/

	//Tabellenkopf::fahrzeug();

	for(dGlobaleZeit=0;dGlobaleZeit<=10;dGlobaleZeit += (1.0/60.0))
	{
		vSetzeZeit(dGlobaleZeit);
		kreuzung1->vAbfertigung();
		kreuzung2->vAbfertigung();
		kreuzung3->vAbfertigung();
		kreuzung4->vAbfertigung();
		//cout << *pkw;
		//Sleep(300);
	}


	vBeendeGrafik();

}
void vAufgabe_9()
{
	cout << "Aufgabe 9" << endl;
	try 
	{
		Welt *erde = new Welt();

		erde->vEinlesenMitGrafik();

		cout << endl << "---------------------------------------------------" << endl;

		Tabellenkopf::kreuzung();
		for(dGlobaleZeit=0;dGlobaleZeit<10;dGlobaleZeit += (3.0/60.0))
		{
			vSetzeZeit(dGlobaleZeit);
			erde->vSimulation();
		}
	}
	catch(string * Fehlermeldung)
	{
		cout << *Fehlermeldung;
	}
	catch(string Fehlermeldung)
	{
		cout << Fehlermeldung;
	}
}

void main()
{
	//vAufgabe_6();
	//vAufgabe_6a();
	//vAufgabe_7();
	//vAufgabe_8();
	vAufgabe_9();	
	
	char c = getchar();
	cin.get(); //Auf Eingabe warten, damit Konsole nicht direkt verschwindet.
}