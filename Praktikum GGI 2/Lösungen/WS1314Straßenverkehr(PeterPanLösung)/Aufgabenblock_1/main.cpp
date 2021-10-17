#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <windows.h>

void vTabelle();
void vAusgabe();

void vAufgabe1();	
void vAufgabe_1_deb();
void vAufgabe2();
void vAufgabe3();

//Globale Uhr
extern double dGlobaleZeit = 0.0;

//Hauptprogramm ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main()
{
	
    //vAufgabe1();
    //vAufgabe_1_deb();
	//vAufgabe2();
	//vAufgabe3();
 	return 0;
}

// Tabellenausgabe +++++++++++++++++++++++++++++++++++++++++++++++++++++
void vTabelle()
{
	cout << resetiosflags(ios::right) << setiosflags(ios::left) //vorher rechts jetzt wieder linksbündig (1.5)
		 << endl 
		 << setw(4)  << "ID" 
		 << setw(7) << "Name"  
		 << setw(3)  << ":"
		 << setw(15) << "Max. Geschw."
		 << setw(15) << "Ges. Strecke" 
		 << setw(12) << "Verbrauch" 
		 << setw(12) << "Tankinhalt" 
		 << setw(12) << "Akt. Geschw." << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}

// Aufgabe 1 bis 3 ++++++++++++++++++++++++++++++++++++++++++++++++

// Aufgabe 1
void vAufgabe1()
{ 
    Fahrzeug Auto1;
	Fahrzeug Auto2("BMW");
	Fahrzeug *array[2];
	array[0] = new Fahrzeug;
	array[1] = new Fahrzeug("Masarati");

	for(int count = 0; count < 2; count++)
	{
		array[count]->setName();
	}

	vTabelle();
    Auto1.vAusgabe();
    Auto2.vAusgabe();
	array[0]->vAusgabe();
	array[1]->vAusgabe();

	delete array[1];
	delete array[0];

	cout << endl;
	cout << endl;
	cout << endl;



	Fahrzeug Auto3("Jaguar",250);
	Fahrzeug Auto4("Mercedes",150);

    for(dGlobaleZeit; dGlobaleZeit<=3; dGlobaleZeit=dGlobaleZeit+0.5)
    {
        vTabelle();
        Auto3.vAusgabe();
	    Auto4.vAusgabe();
		Auto3.vAbfertigung();
        Auto4.vAbfertigung();
    }
    
}

//Aufgabe_1_deb
void vAufgabe_1_deb()
{
    Fahrzeug ford("Ford", 100);
    Fahrzeug mazda("Mazda", 110);    
    Fahrzeug trabant("Trabant", 120);
    Fahrzeug chevrolet("Chevrolet", 130);
    Fahrzeug *feld[4];

    feld[0]=&ford;
    feld[1]=&mazda;
    feld[2]=&trabant;
    feld[3]=&chevrolet;

    feld[2] = 0;               // Hier Achtung feld[2] wird adresse null zugewiesen !!!
    vTabelle();
    for(int count=0; count<4; count++)
    {
        feld[count]->vAusgabe();
    }
}

//Aufgabe2
void vAufgabe2()
{
	int iAnzahlPKW, iAnzahlFahrrad;
	PKW* PKWPointer;
	Fahrrad* FahrradPointer;

	cout << "Wie viele PKW sollen erstellt werden?: " << endl;
	cin >> iAnzahlPKW;
	cout << "Wie viele Fahrräder sollen erstellt werden?: " << endl;
	cin >> iAnzahlFahrrad;

	//Erstellen und leeren des VehicleVekotors
	vector<Fahrzeug*> vehicle(iAnzahlPKW + iAnzahlFahrrad);
	vehicle.clear();

	// Autos erstellen
	for(int count=0; count < iAnzahlPKW; count++)
	{
		PKWPointer = new PKW;
		vehicle.push_back(PKWPointer);
	}

	//Fahrräder erstellen
	for(int count=0; count < iAnzahlFahrrad; count++)
	{
		FahrradPointer = new Fahrrad;
		vehicle.push_back(FahrradPointer);
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////

	vector<Fahrzeug*>::iterator Vpointer;
	vTabelle();
	while(dGlobaleZeit <= 6)
	{
		dGlobaleZeit += 0.5;
		for (Vpointer = vehicle.begin(); Vpointer != vehicle.end(); ++Vpointer)
		{
            (*Vpointer)->vAusgabe();
			(*Vpointer)->vAbfertigung();
		}

        if(dGlobaleZeit==3)
        {
	    for (Vpointer=vehicle.begin(); Vpointer!=vehicle.begin()+iAnzahlPKW; ++Vpointer)
	        {
		        cout << (*Vpointer)->getName() <<" hat " << (*Vpointer)->dTanken() << " Liter getankt." << endl;
	        }

        }
		cout << endl;
	}
    
}

//Aufgabe3
void vAufgabe3()
{
	Fahrzeug aFahrzeug("Veh.1",50);
	Fahrzeug bFahrzeug("Veh.2", 70);
	PKW aPKW("Auto1",100,8,100);
	PKW bPKW("Auto2");
	Fahrrad aFahrrad("Rad");

	//Überladene Ausgabe
	vTabelle();
	cout << aFahrzeug << endl; 
	cout << bFahrzeug << endl; 
	cout << aPKW << endl;
	cout << bPKW << endl;
	cout << aFahrrad << endl;

	// Copy-Konstruktor
	bFahrzeug = aFahrzeug;
	vTabelle();
	cout << aFahrzeug << endl; 
	cout << bFahrzeug << endl;
	cout << endl;
	cout << endl;

	//Vergleichs-Operator
	dGlobaleZeit+=3;
	aPKW.vAbfertigung();
	bPKW.vAbfertigung();

	if(aPKW < bPKW)
	{
		cout << "Es fuehrt " << bPKW.getName() << endl;
	}
	else if(bPKW < aPKW)
	{
		cout << "Es fuehrt " << aPKW.getName() << endl;
	}
	else 
	{
		cout << "Unentschieden!" << endl;
	}

	vTabelle();
	cout << aPKW << endl; 
	cout << bPKW << endl;

}
