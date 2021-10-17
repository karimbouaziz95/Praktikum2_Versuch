#include <iostream>
#include <stdlib.h>
#include "Fahrzeug.h"
#include "Fahrrad.h"
#include "PKW.h"
#include <vector>
#include "Weg.h"
#include "SimuClient.h"
#include "windows.h"
#include "LazyAktion.h"
#include "LazyListe.h"
using namespace std;


double dGlobaleZeit = 0.0;
double dZeitschritt = 0.3;


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

int main()
{
	//vAufgabe_1();
	//vAufgabe_1_deb();
	//vAufgabe_2();
	//vAufgabe_3();
    //vAufgabe_4();
    //vAufgabe_5();
	vAufgabe_6a();
    return 0;
}