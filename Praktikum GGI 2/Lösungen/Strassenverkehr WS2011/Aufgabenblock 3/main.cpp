#include <iostream>
#include <stdlib.h>
#include "Fahrzeug.h"
#include "Fahrrad.h"
#include "PKW.h"
#include <vector>
#include "Weg.h"
#include "SimuClient.h"
#include <Windows.h>
#include "LazyAktion.h"
#include "LazyListe.h"
#include "Kreuzung.h"
#include <fstream>
#include <sstream>
#include "AktivesVO.h"
#include "Welt.h"
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>
#include "FzgVerhalten.h"
#include "FzgFahren.h"
#include <ctime>
using namespace std;


double dGlobaleZeit = 0.0;
double dZeitschritt = 0.05;

void vAufgabe_1()
{
	//Erzeugung der Fahrzeuge

	string sEingabe;
	
	Fahrzeug statisch1("statisch1",35.00);
	Fahrzeug statisch2("statisch2",15.00);

	Fahrzeug* pFahrzeugA;
	Fahrzeug* pFahrzeugB;
	
	cout << "Geben Sie den Namen des ersten Fahrzeugs ein:";
	cin >> sEingabe;

	pFahrzeugA =  new Fahrzeug(sEingabe,60.00);

	cout << "Geben Sie den Namen fuer ein zweites Fahrzeug ein:";
	cin >> sEingabe;

	pFahrzeugB = new Fahrzeug(sEingabe,27.84);

	//Abfertigung und Ausgabe bis t < 10h
	
	while(dGlobaleZeit<10.00)
	{
		statisch1.vAbfertigung();
		statisch2.vAbfertigung();
		pFahrzeugA->vAbfertigung();
		pFahrzeugB->vAbfertigung();
	
		cout << endl << "Zeitschritt:" << dGlobaleZeit << endl;
		cout << setw(4) << setiosflags(ios::left) << "ID" << setw(12) << setiosflags(ios::left) << "Name " << setw(3) << setiosflags(ios::left) 
			 << ":" << setw(13) << setiosflags(ios::left) << "MaxKmh" << setw(24) << setiosflags(ios::left) << "GesamtStrecke" << endl 
			 << "++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		statisch1.vAusgabe();
		cout << endl;
		statisch2.vAusgabe();
		cout << endl;
		pFahrzeugA->vAusgabe();
		cout << endl;
		pFahrzeugB->vAusgabe();
		cout << endl;
		dGlobaleZeit+= dZeitschritt;
	}

	//löschen auf dem Heap

	delete pFahrzeugB;
	delete pFahrzeugA;
	
;}

void vAufgabe_1_deb()
{
	int i;

	//Fahrzeuge auf Heap erzeugen, pointer im Feld ablegen

	Fahrzeug* feld_name[4];

	feld_name[0] = new Fahrzeug("A");
	feld_name[1] = new Fahrzeug("B");
	feld_name[2] = new Fahrzeug("C");
	feld_name[3] = new Fahrzeug("D");

	//Ausgabe des Feldinhalts

	cout << endl << setw(4) << setiosflags(ios::left) << "ID" << setw(12) << setiosflags(ios::left) << "Name " << setw(3) << setiosflags(ios::left) 
		 << ":" << setw(13) << setiosflags(ios::left) << "MaxKmh" << setw(24) << setiosflags(ios::left) << "GesamtStrecke" << endl 
		 << "++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	
	for(i=0;i<4;i++)
	{
		feld_name[i]->vAusgabe();
		cout << endl;
	}

	//Manipulation des Zeigers

	feld_name[2] = 0;

	//Ausgabe des Feldinhalts

	cout << endl << setw(4) << setiosflags(ios::left) << "ID" << setw(12) << setiosflags(ios::left) << "Name " << setw(3) << setiosflags(ios::left) 
		 << ":" << setw(13) << setiosflags(ios::left) << "MaxKmh" << setw(24) << setiosflags(ios::left) << "GesamtStrecke" << endl 
		 << "++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	
	for(i=0;i<4;i++)
	{
		feld_name[i]->vAusgabe();
		cout << endl;
	}
	
}

void vAufgabe_2()
{ 
	int iEingabe;
	int i;
	int j;
	vector<Fahrzeug*> vFahrzeug;

	double dFahrradGeschwindigkeit = 12.00;
	double dPKWGeschwindigkeit = 30.00;
	double dPKWVerbrauch = 6.00;
	
	//Erzeugung neuer Fahrzeuge auf Heap, pointer speichern im vector

	cout << "Wie viele Fahrraeder sollen erzeugt werden?" << endl;
	cin >> iEingabe;

	for (i=0; i < (iEingabe); i++)
		{
			vFahrzeug.push_back(new Fahrrad("Fahrrad", dFahrradGeschwindigkeit));
			dFahrradGeschwindigkeit += 5.00;
		}

	cout << "Wie viele Autos sollen erzeugt werden?" << endl;
	cin >> iEingabe;

	for (j=1; j < (iEingabe+1); j++)
		{
			vFahrzeug.push_back(new PKW(dPKWVerbrauch ,"PKW", dPKWGeschwindigkeit));
			dPKWGeschwindigkeit += 5.00;
			dPKWVerbrauch += 3.00;
		}

	//Abfertigung und Ausgabe für t < 7h

	for(; dGlobaleZeit < 7.00; dGlobaleZeit += dZeitschritt)
		{
			cout << endl << "Zeitschritt:" << dGlobaleZeit << endl;
			cout << setw(4) << setiosflags(ios::left) << "ID" << setw(12) << setiosflags(ios::left) << "Name " << setw(3) << setiosflags(ios::left) 
				 << ":" << setw(13) << setiosflags(ios::left) << "MaxKmh" << setw(18) << setiosflags(ios::left) << "GesamtStrecke" << setw(14) 
				 << setiosflags(ios::left) << "Verbrauch" << setw(14) << setiosflags(ios::left) << "Tankinhalt" << endl 
				 << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			for(i=0; i < vFahrzeug.size(); i++)
				{
					vFahrzeug[i]->vAbfertigung();
					vFahrzeug[i]->vAusgabe();
				}

			//Volltanken bei t = 3h, erneute Ausgbae

			if(dGlobaleZeit==3.00)
				{
					cout << endl << "Tanken" << endl;
					for(i=0; i < vFahrzeug.size(); i++)
						{
							vFahrzeug[i]->dTanken();
						}
					cout << endl << "Zeitschritt:" << dGlobaleZeit << endl;
					cout << setw(4) << setiosflags(ios::left) << "ID" << setw(12) << setiosflags(ios::left) << "Name " << setw(3) << setiosflags(ios::left) 
						 << ":" << setw(13) << setiosflags(ios::left) << "MaxKmh" << setw(18) << setiosflags(ios::left) << "GesamtStrecke" << setw(14) 
						 << setiosflags(ios::left) << "Verbrauch" << setw(14) << setiosflags(ios::left) << "Tankinhalt" << endl 
						 << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
					for(i=0; i < vFahrzeug.size(); i++)
						{
							vFahrzeug[i]->vAusgabe();
						}
				}
		}
}

void vAufgabe_3()
{
	//Objekte erstellen

	Fahrzeug pFahrzeug("Fahrzeug",28.00);
	PKW pPKW(5.00,"PKW",24.00);
	Fahrrad pFahrrad("Fahrrad",50.00);
	cout << pFahrzeug << endl << pPKW << pFahrrad;

	//pFahrzeug kopieren in nFahrzeug

	Fahrzeug nFahrzeug; 
	nFahrzeug = pFahrzeug;
	cout << nFahrzeug << endl;

	//Verwendung <Operator

	if (pFahrzeug < pPKW)
		cout << "kleiner" << endl;
	else
		cout << "groesser/gleich" << endl;
}

void vAufgabe_4()
{
    Weg* pWeg;
    Fahrzeug* p1;
    Fahrzeug* p2;
    
    pWeg = new Weg("Weg1", 100);
    p1 = new Fahrzeug("Fahrzeug 1", 100);
    p2 = new Fahrzeug("Fahrzeug 2", 100);
    
    pWeg->vAnnahme(p1);
    pWeg->vAnnahme(p2);

	for(;dGlobaleZeit < 10; dGlobaleZeit+=dZeitschritt)
    {
        pWeg->vAbfertigung();
		
	}
    
    cout << *pWeg;
}

void vAufgabe_5()
{
    Weg Weg1("Weg1", 500, Innerorts);
	Weg Weg2("Weg2", 500, Innerorts);
    PKW PKW1(6.00, "PKW1", 70, 20);  //PKW(Verbrauch,Name,Höchstgeschwindigkeit,Tankinhalt)
    PKW PKW2(6.00, "PKW2", 70, 20);
    Weg1.vAnnahme(&PKW1,4);
    Weg2.vAnnahme(&PKW2);
	int Array[4] = {700,250,100,250};
	bInitialisiereGrafik(800, 500);
	bZeichneStrasse("Weg1","Weg2",500, 2 , Array);
	
    for(;dGlobaleZeit < 10; dGlobaleZeit+=dZeitschritt)
    {
		vSetzeZeit(dGlobaleZeit);
        Weg1.vAbfertigung();
		Weg2.vAbfertigung();
		PKW1.vZeichnen(&Weg1);
		PKW2.vZeichnen(&Weg2);
		Sleep(500);
    }
	vBeendeGrafik();
}

void vAufgabe_6a()
{
	LazyListe<int> Zufallsliste;
	list<int>::iterator Literator;

	for (int i=0;i<10;i++)
	{
		Zufallsliste.push_back(rand() % 11);
	}
	Zufallsliste.vAktualisieren();

	for (Literator=Zufallsliste.begin(); Literator != Zufallsliste.end(); Literator++)
	{
		cout << *Literator << " , ";
	}
	cout << endl << endl;

	for (Literator=Zufallsliste.begin(); Literator != Zufallsliste.end(); Literator++)
	{
		if(*Literator > 5)
		{
			Zufallsliste.erase(Literator);
		}
	}

	for (Literator=Zufallsliste.begin(); Literator != Zufallsliste.end(); Literator++)
	{
		cout << *Literator << " , ";
	}
	cout << endl << endl;

	Zufallsliste.vAktualisieren();

	for (Literator=Zufallsliste.begin(); Literator != Zufallsliste.end(); Literator++)
	{
		cout << *Literator << " , ";
	}
	cout << endl << endl;

	Zufallsliste.push_front(rand() % 11);
	Zufallsliste.push_front(rand() % 11);
	Zufallsliste.push_back(rand() % 11);
	Zufallsliste.push_back(rand() % 11);
	Zufallsliste.vAktualisieren();

	for (Literator=Zufallsliste.begin(); Literator != Zufallsliste.end(); Literator++)
	{
		cout << *Literator << " , ";
	}
	cout << endl << endl;
}

void vAufgabe_7()
{
	int counter=0;
	list<int>::iterator Literator;

	Weg Weg1("Weg1", 200, Innerorts);
	Weg Weg2("Weg2", 200, Innerorts);
    PKW PKW1(6.00, "PKW", 70, 20);  //PKW(Verbrauch,Name,Höchstgeschwindigkeit,Tankinhalt)
    Fahrrad Fahrrad1("Fahrrad", 30);
	Fahrzeug Fahrzeug1("neuesFahrzeug", 40);
	Weg1.vAnnahme(&PKW1,4);
    Weg1.vAnnahme(&Fahrrad1,1);

	int Array[4] = {700,250,100,250};
	bInitialisiereGrafik(800, 500);
	bZeichneStrasse("Weg1","Weg2",500, 2 , Array);

	
	
    for(;dGlobaleZeit < 15; dGlobaleZeit+=dZeitschritt)
    {
		cout << dGlobaleZeit << endl;
		vSetzeZeit(dGlobaleZeit);
        
		Weg1.vAbfertigung();
		Weg2.vAbfertigung();
		
		PKW1.vZeichnen(&Weg1);
		Fahrrad1.vZeichnen(&Weg1);
		
		Sleep(500);
		
		counter++;
		if (counter==25)
		{
			cout << "neuesFahrzeug wird angenommen" << endl;
			Weg1.vAnnahme(&Fahrzeug1,16);
		}
    }
	vBeendeGrafik();
}

void vAufgabe_8()
{
	Kreuzung* Kr1 = new Kreuzung("Kr1");
	Kreuzung* Kr2 = new Kreuzung("Kr2", 1000);
	Kreuzung* Kr3 = new Kreuzung("Kr3");
	Kreuzung* Kr4 = new Kreuzung("Kr4");

	Kr1->vVerbinde("W12", "W21", 40, Kr2, Innerorts);
	Kr2->vVerbinde("W23a", "W32a", 115, Kr3, Autobahn, false);
	Kr2->vVerbinde("W23b", "W32b", 40, Kr3, Innerorts);
	Kr2->vVerbinde("W24", "W42", 55, Kr4, Innerorts);
	Kr3->vVerbinde("W34", "W43", 85, Kr4, Autobahn, false);
	Kr4->vVerbinde("W44a", "W44b", 130, Kr4, Landstrasse, false);

	int s1[] = {680, 40, 680, 300};
	int s2[] = {680, 300, 850, 300, 970, 390, 970, 500, 850, 570, 680, 570};
	int s3[] = {680, 300, 680, 570};
	int s4[] = {680, 300, 320, 300};
	int s5[] = {680, 570, 500, 570, 350, 510, 320, 420, 320, 300};
	int s6[] = {320, 300, 170, 300, 70, 250, 80, 90, 200, 60, 320, 150, 320, 300};

	bInitialisiereGrafik(1100, 700);

	bZeichneStrasse("W12", "W21", 40, 2, s1);
	bZeichneStrasse("W23a", "W32a", 115, 6, s2);
	bZeichneStrasse("W23b", "W32b", 40, 2, s3);
	bZeichneStrasse("W24", "W42", 55, 2, s4);
	bZeichneStrasse("W34", "W43", 85, 5, s5);
	bZeichneStrasse("W44a", "W44b", 130, 7, s6);

	bZeichneKreuzung(680, 40);
	bZeichneKreuzung(680, 300);
	bZeichneKreuzung(680, 570);
	bZeichneKreuzung(320, 300);

	PKW* PKW1 = new PKW(10,"PKW",100, 100);
	Fahrrad* Fahrrad1 = new Fahrrad("Fahrrad", 30);

	Kr1->vAnnahme(PKW1, 0);
	Kr1->vAnnahme(Fahrrad1, 3);

	Kr1->vAbfertigung();

	cout << *PKW1 << endl << *Fahrrad1 << endl << endl;
	cout << *Kr1 << endl << endl
		 << *Kr2 << endl << endl
		 << *Kr3 << endl << endl
		 << *Kr4 << endl << endl;


	while(dGlobaleZeit < 15) 
	{
		vSetzeZeit(dGlobaleZeit);
		Kr1->vAbfertigung();
		Kr2->vAbfertigung();
		Kr3->vAbfertigung();
		Kr4->vAbfertigung();

		dGlobaleZeit += dZeitschritt;

		Sleep(500);
	
		cout << dGlobaleZeit << endl;
		cout <<*PKW1 <<*Fahrrad1 << endl;
	}

	vBeendeGrafik();
	delete PKW1, Fahrrad1, Kr1, Kr2, Kr3, Kr4;
}

void vAufgabe_9() 
{
	try
	{
		PKW* car = new PKW("");
		Fahrrad* bike = new Fahrrad("");
		Kreuzung* x = new Kreuzung("");

		ifstream fin("VO.dat");

		if(!fin.good())
		{
			throw string("Error: Datei konnte nicht geoeffnet werden!\n");
		}

		fin >> *car >> *bike >> *x;
		cout << *car << endl << *bike << endl << *x << endl << endl;
		cout << *AktivesVO::ptObjekt("Porsche") << endl;
		cout << *AktivesVO::ptObjekt("Rennrad") << endl;
		cout << *AktivesVO::ptObjekt("Kr1") << endl;

		delete car, bike, x;

	}catch(string s) {cout << s;}

}

void simu()
{
	try
	{
	ifstream fin("Simu.dat");
	if(!fin.good())
	{
		throw string("Error: Datei konnte nicht geoeffnet werden!\n");
	}
	Welt* neueWelt= new Welt();
	neueWelt->vEinlesen(fin);
	}catch(string s) {cout << s;}
}

void simuGrafik()
{
	bInitialisiereGrafik(1000,1000);
	try
	{
	ifstream fin("SimuDisplay.dat");
	if(!fin.good())
	{
		throw string("Error: Datei konnte nicht geoeffnet werden!\n");
	}
	
	Welt* neueWelt= new Welt();
	neueWelt->vEinlesenMitGrafik(fin);
	
	for (;dGlobaleZeit<120;dGlobaleZeit+=dZeitschritt)
	{
		vSetzeZeit(dGlobaleZeit);
		neueWelt->vSimulation();
	}

	}catch(string s) {cout << s;}
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
	//vAufgabe_6a();
	//vAufgabe_7();
	//vAufgabe_8();
	//vAufgabe_9();
    //simu();
	simuGrafik();
	return 0;
}