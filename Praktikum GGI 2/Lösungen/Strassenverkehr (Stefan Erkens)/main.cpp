#include "AktivesVO.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "SimuClient.h"
#include "Windows.h"
#include "LazyListe.h"
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;

//Zeitabstand und Fahrzeugzahl definieren
#define TIMESTEP 0.3

//Initialisierung der Fahrzeugtenumeration
int AktivesVO::p_iMaxID = 0;
double dGlobaleZeit = 0.0;

void vAufgabe_4()
{
	//Tabellen-Kopf
	cout << "ID  Name     :  MaxKmh   G.strecke  G.Verb.  Tank   kmh    Ab.Str." << endl 
			 << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

	{
	/*
	Fahrrad test1 ("Fahrrad", 20);
	PKW test2("PKW1", 50);
	PKW test3;
	cout << test1 << endl << test2 << endl << test3 << endl << endl;

	system("PAUSE");

	dGlobaleZeit += TIMESTEP;

	test1.vAbfertigung();
	test2.vAbfertigung();
	test3.vAbfertigung();

	cout << test1 << endl << test2 << endl << test3 << endl << endl;

	if(test3 < test2)
		cout << "PKW1 ist weiter gefahren als 'PKW2'" << endl;
	else 
		cout << "PKW1 ist nicht weiter gefahren als 'PKW2'" << endl;

	system("PAUSE");

	dGlobaleZeit += TIMESTEP;

	test3 = test2;

	test1.vAbfertigung();
	test2.vAbfertigung();
	test3.vAbfertigung();

	cout << test1 << endl << test2 << endl << test3 << endl << endl;

	if(test3 < test2)
		cout << "PKW1 ist weiter gefahren als 'PKW2'" << endl;
	else 
		cout << "PKW1 ist nicht weiter gefahren als 'PKW2'" << endl;

	system("PAUSE");
	*/
	}

	//2 Fahrzeuge, 3 Wege Erzeugen
	PKW Auto1("Auto", 60, 6, 100);
	Fahrrad Rad1("Rad", 20);
	Weg Straße1("Strasse", 100, Innerorts);
	Weg Straße2("Weg", 100);
	Weg Straße3;

	//Alles ausgeben
	cout << Auto1 << endl << Rad1 << endl << Straße1 << endl << Straße2 << endl << Straße3 <<endl;

	system("PAUSE");

	//Beide Fahrzeuge auf einen Weg setzen
	Straße1.vAnnahme(&Auto1);
	Straße1.vAnnahme(&Rad1);
	
	//Parkendes Fahrzeug erzeugen und auch auf den Weg setzen
	PKW Parker("Parkt", 50,5,50);
	Straße1.vAnnahme(&Parker, 2);
	Straße1.vAbfertigung();


	//Alles erneut ausgeben
	cout << Auto1 << endl << Rad1 << endl << Parker << endl << Straße1 << endl << Straße2 << endl << Straße3 <<endl;

	system("PAUSE");

	while(1)
	{
		//Weg immer wieder abfertgen und ausgeben
		dGlobaleZeit += TIMESTEP;
		Straße1.vAbfertigung();
		cout << Auto1 << endl << Rad1 <<  endl << Parker <<  endl << Straße1 << endl << Straße2 << endl << Straße3 << endl << endl;
		system("PAUSE");
	}
}

void vAufgabe_5()
{

	//2 Wege mit jeweils einem Fahrzeug erzeugen
	Weg Weg1("Strasse1", 500);
	Weg Weg2("Strasse2", 500);
	PKW PKW1("Auto", 50, 6, 100);
	Fahrrad RAD1("Fahrrad", 20);
	Weg1.vAnnahme(&PKW1);
	Weg2.vAnnahme(&RAD1);

	bInitialisiereGrafik(800, 600, "localhost"); //Grafik starten (lokale IP)
	vSetzeZeit(dGlobaleZeit); //Zeit setzen
	int Koordinaten [4] = {700, 250, 200, 250}; //Straßenkoordianten
	bZeichneStrasse("Strasse1", "Strasse2", 500, 2, Koordinaten);

	while(1)
	{
		//Beide Wege abfertigen, 300ms warten
		dGlobaleZeit += TIMESTEP;
		vSetzeZeit(dGlobaleZeit);
		Weg1.vAbfertigung();
		Weg2.vAbfertigung();
		Sleep(300);
	}

	vBeendeGrafik();
}

void vAufgabe_6()
{
	//2 Wege, 3 Fahrzeuge erzeugen
	Weg Weg1("Strasse1", 500);
	Weg Weg2("Strasse2", 500);
	PKW PKW1("Auto", 50, 6, 20);
	Fahrrad RAD1("Fahrrad", 20);
	PKW PKW2("Auto2", 60, 6, 100);

	//Fahrzeuge auf Wege setzen, eines davon parkt
	Weg1.vAnnahme(&PKW1);
	Weg2.vAnnahme(&RAD1);
	Weg2.vAnnahme(&PKW2, 5);

	//Grafik initialisieren
	bInitialisiereGrafik(1000, 600, "localhost");
	vSetzeZeit(dGlobaleZeit);
	int Koordinaten [18] = {100,300, 300,100, 500,300, 700,500, 900,300, 700,100, 500,300, 300,500, 100,300};
	bZeichneStrasse("Strasse1", "Strasse2", 500, 9, Koordinaten);

	while(1)
	{
		//Wege abfertigen
		dGlobaleZeit += TIMESTEP;
		vSetzeZeit(dGlobaleZeit);
		Weg1.vAbfertigung();
		Weg2.vAbfertigung();
		Sleep(300);
		if((dGlobaleZeit - 5) < 0.1 && (dGlobaleZeit - 5) > 0)
			PKW1.dTanken();
		}

	vBeendeGrafik();

}

void vAufgabe_6a()
{
	//srand(time(0)); //Keine neuen Zufallszahlen

	LazyListe <int> rndList; //Neue Liste für das verzögerte Update
	LazyListe <int>::iterator iter; //Iterator für diese Liste

	for(int i = 0; i < 15; i++)
	{
		rndList.push_back(rand()%10+1); //Random Integer in der Liste einfügen
	}

	rndList.vAktualisieren(); //Liste updaten

	for(iter = rndList.begin(); iter != rndList.end(); iter++)
		cout << (*iter) << "   "; //Liste ausgeben
	cout << endl;

	for(iter = rndList.begin(); iter != rndList.end(); iter++)
		if((*iter)>5) //Alle Werte >5 löschen (vormerken)
			rndList.erase(iter);

	for(iter = rndList.begin(); iter != rndList.end(); iter++)
		cout << (*iter) << "   "; //nochmals ausgeben
	cout << endl;

	rndList.vAktualisieren(); //Löschen ausführen

	for(iter = rndList.begin(); iter != rndList.end(); iter++)
		cout << (*iter) << "   "; //ausgeben
	cout << endl;

	//Push-Test
	rndList.push_back(3);
	rndList.push_front(5);
	rndList.vAktualisieren();

	for(iter = rndList.begin(); iter != rndList.end(); iter++)
		cout << (*iter) << "   "; //Letztes mal ausgeben
	cout << endl;

	system("PAUSE");
}




int main()
{
	
	//vAufgabe_4();
	//vAufgabe_5();
	vAufgabe_6();
	//vAufgabe_6a();


	return 0; 
}