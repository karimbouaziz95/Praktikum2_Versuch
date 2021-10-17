#include "AktivesVO.h"
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "Weg.h"
#include "SimuClient.h"
#include "LazyListe.h"
#include  <stdlib.h>
#include  <time.h>



#include <string>
using namespace std;
#include <ostream> 



#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>

void vTabelle();
void vAusgabe();

void vAufgabe1();	
void vAufgabe_1_deb();
void vAufgabe2();
void vAufgabe3();
void vAufgabe4();
void vAufgabe5();
void vAufgabe6();
void vAufgabe6a();


//Globale Uhr
extern double dGlobaleZeit = 0.0;

//Hauptprogramm ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main()
{
    //vAufgabe1();
    //vAufgabe_1_deb();
	//vAufgabe2();
	//vAufgabe3();
 	//vAufgabe4();
	//vAufgabe5();
	//vAufgabe6();
	vAufgabe6a();		//LazyListe ausprobieren
	return 0;
}

// Tabellenausgabe +++++++++++++++++++++++++++++++++++++++++++++++++++++
void vTabelle()
{
	cout << resetiosflags(ios::right) << setiosflags(ios::left) //vorher rechts jetzt wieder linksbündig (1.5)
		 << endl 
		 << setw(4)  << "ID" 
		 << setw(7)  << "Name"  
		 << setw(3)  << ":"
		 << setw(15) << "Max. Geschw."
		 << setw(15) << "Ges. Strecke" 
		 << setw(12) << "Verbrauch" 
		 << setw(12) << "Tankinhalt" 
		 << setw(12) << "Akt. Geschw." << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}

// Aufgabe 1 bis 3 ++++++++++++++++++++++++++++++++++++++++++++++++//

// Aufgabe 1++++++++++++++++++++++++++++++++++++++++++++++++++++++
void vAufgabe1()
{ 
    Fahrzeug Auto1;
	Fahrzeug Auto2("BMW");
	Fahrzeug *array[2];
	array[0]= new Fahrzeug();
	array[1] = new Fahrzeug("Masarati");

	for(int count = 0; count < 2; count++)
	{
		array[count]->setName();
	}

	vTabelle();
	array[0]->vAusgabe();
	array[1]->vAusgabe();

	delete array[0];
	delete array[1];

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

//Aufgabe_1_deb++++++++++++++++++++++++++++++++++++++
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

//Aufgabe2++++++++++++++++++++++++++++++++++++++++++++++++
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

	///////////////////////////////////////////////////////

	vector<Fahrzeug*>::iterator Vpointer;
	vTabelle();
	while(dGlobaleZeit <= 3)
	{
		
		for (Vpointer = vehicle.begin(); Vpointer != vehicle.end(); ++Vpointer)
		{
            (*Vpointer)->vAusgabe();
			(*Vpointer)->vAbfertigung();
		}
		cout << endl;
	}

	for (Vpointer=vehicle.begin(); Vpointer!=vehicle.begin()+iAnzahlPKW; ++Vpointer)
	{
		cout << (*Vpointer)->getName() <<" hat " << (*Vpointer)->dTanken() << " Liter getankt." << endl;
	}
}

//Aufgabe3++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
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
		cout << "Es führt " << bPKW.getName() << endl;
	}
	else if(bPKW < aPKW)
	{
		cout << "Es führt " << aPKW.getName() << endl;
	}
	else 
	{
		cout << "Unentschieden!" << endl;
	}

	vTabelle();
	cout << aPKW << endl; 
	cout << bPKW << endl;

}

//Aufgabe4+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void vAufgabe4()
{
	PKW auto1("Porsche");
	PKW auto2("Audi");

	Weg wMaxstrasse("Strasse",330);
	wMaxstrasse.vAnnahme(&auto1);
	wMaxstrasse.vAnnahme(&auto2);
    cout << wMaxstrasse;
    vTabelle();

    for(dGlobaleZeit; dGlobaleZeit<=3; dGlobaleZeit=dGlobaleZeit+0.3333564)
    {
        wMaxstrasse.vAbfertigung();
        
	    cout << auto1 <<endl;

    }
	
}

//Aufgabe5+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void vAufgabe5()
{
	PKW auto1("Porsche");
	PKW auto2("Audi");
    Fahrrad fahr1("gretel");
    Fahrrad fahr2("wurst");

	Weg wMaxstrasse("Strasse",330);
	wMaxstrasse.vAnnahme(&auto1);
	wMaxstrasse.vAnnahme(&auto2,1);
    wMaxstrasse.vAnnahme(&fahr1);
    wMaxstrasse.vAnnahme(&fahr2,1);

    cout << wMaxstrasse;
    vTabelle();

    for(dGlobaleZeit; dGlobaleZeit<=3; dGlobaleZeit=dGlobaleZeit+0.3333564)
    {
        wMaxstrasse.vAbfertigung();
	    cout << auto1 << endl;
		cout << auto2 << endl;
        cout << fahr1 << endl;
		cout << fahr2 << endl;
    }
}
 //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void vAufgabe6()
{
	PKW auto1("Porsche");
    Fahrrad fahr1("dieter");
	auto1.dTanken();
	Weg way1("way1",500);
	Weg way2("way2",500);
	way1.vAnnahme(&auto1);
    way1.vAnnahme(&fahr1,1);
	bInitialisiereGrafik(800,500);
	int tab[4] = {700, 250, 100, 250};
	bZeichneStrasse("way1","way2",500,2,tab);

	for(dGlobaleZeit; dGlobaleZeit<=5; dGlobaleZeit=dGlobaleZeit+0.3)
    {
        vSetzeZeit(dGlobaleZeit);
        way1.vAbfertigung();
		bZeichnePKW("Porsche","way1",auto1.GetAbschnittStrecke() / way1.GetLaenge(),auto1.dGeschwindigkeit(),auto1.GetTank()); // siehe Seite 33 oben
        bZeichneFahrrad("dieter","way1",fahr1.GetAbschnittStrecke() / way1.GetLaenge() + 0.5,fahr1.dGeschwindigkeit());
		vSleep(500);
	    cout << auto1 << endl;
        cout << fahr1 << endl;
    }
    vBeendeGrafik();
}

void vAufgabe6a()
{
	srand((int)time(0));
	LazyListe<int> LListe;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// pusht zusafllszahlen in Liste und Aktualiesiert 
	for(int count=1; count < 11; ++count)
	{
		LListe.push_front(rand() % 11);
	}
	LListe.vAktualisieren();


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// gibt Liste aus und setzt alle > 5 auf Aktion_liste zum löschen
	// gibt Liste erneut aus(ohne veränderung)
	LazyListe<int>::iterator iter;
	for(iter = LListe.begin(); iter != LListe.end(); ++iter)
	{
		cout << (*iter) << endl;
		if((*iter) > 5)
		{
			LListe.erase(iter);
		}
	}

	cout << endl;
	cout << endl;

	for(iter = LListe.begin(); iter != LListe.end(); ++iter)
	{
		cout << (*iter) << endl;
	}

	cout << endl;
	cout << endl;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//Aktualiesierung/ löschen alles Zahlen <5
	LListe.vAktualisieren();

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//Aktualiesierte Liste ausgeben
	for(iter = LListe.begin(); iter != LListe.end(); ++iter)
	{
		cout << (*iter) << endl;
	}

	cout << endl;
	cout << endl;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//PushFront und PushBack auprobieren, aktualisieren und ausgeben
	LListe.push_front(100);;
	LListe.push_back(200);
	LListe.vAktualisieren();

	for(iter = LListe.begin(); iter != LListe.end(); ++iter)
	{
		cout << (*iter) << endl;
	}

}