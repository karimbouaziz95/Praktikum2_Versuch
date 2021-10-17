#include "Fahrzeug.h"
#include <string>
#include <iostream>
#include <iomanip>
#include "Fahrrad.h"
#include <vector>
#include "PKW.h"
#include <math.h>

using namespace std;

double dGlobaleZeit = 0.0;


void vTabellenFormat() {

	const char plus = '+';
	const char separator = ' ';
	cout << left << setw(8)  << setfill(separator) << "ID";
	cout << left << setw(8)  << setfill(separator) << "Name";
	cout << left << setw(3)  << setfill(separator) << ":";
	cout << left << setw(12) << setfill(separator) << "Akt. Kmh";
	cout << left << setw(18) << setfill(separator) << "GesamtStrecke";
	cout << left << setw(18) << setfill(separator) << "GesamtVerbrauch";
	cout << left << setw(18) << setfill(separator) << "TankInhalt" << endl;
	cout << left << setw(80) << setfill(plus)      << "+" << endl;
}

void vAufgabe_1()
{
	string sName1 = "";
	string sName2 = "";
	string sName3 = "";

	Fahrzeug fahrzeug_1("Auto1");
	Fahrzeug fahrzeug_2("Auto2");
	Fahrzeug fahrzeug_3("Auto3");

	cout << "Name fuer Fahrzeug 4:" << endl;
	cin  >> sName1;
	cout << "Name fuer Fahrzeug 5:" << endl;
	cin  >> sName2;
	cout << "Name fuer Fahrzeug 6:" << endl;
	cin  >> sName3;

	Fahrzeug *fahrzeug_4 = new Fahrzeug(sName1, 140.5);
	Fahrzeug *fahrzeug_5 = new Fahrzeug(sName2, 40.42);
	Fahrzeug *fahrzeug_6 = new Fahrzeug(sName3, 60.00);

	while (dGlobaleZeit < 24)
	{
		fahrzeug_4->vAbfertigung();
		fahrzeug_5->vAbfertigung();
		fahrzeug_6->vAbfertigung();

		dGlobaleZeit += 0.25;
	}

	vTabellenFormat();
	fahrzeug_1.vAusgabe(); cout << endl;
	fahrzeug_2.vAusgabe(); cout << endl;
	fahrzeug_3.vAusgabe(); cout << endl;
	fahrzeug_4->vAusgabe(); cout << endl;
	fahrzeug_5->vAusgabe(); cout << endl;
	fahrzeug_6->vAusgabe(); cout << endl;

	cout << "Beliebige Eingabe zum Loeschen aller Fahrzeuge:" << endl;
	char d;
	cin >> d;

	delete fahrzeug_6;
	delete fahrzeug_5;
	delete fahrzeug_4;
}

void vAufgabe_1_deb()
{
	Fahrzeug f1 ("A", 2.0);
	Fahrzeug f2 ("B", 4.32);
	Fahrzeug f3 ("C", 1.35);
	Fahrzeug f4 ("D", 3.51);

	//Fahrzeug Zeiger
	Fahrzeug* fZeiger1;
	Fahrzeug* fZeiger2;
	Fahrzeug* fZeiger3;
	Fahrzeug* fZeiger4;

	fZeiger1 = &f1;
	fZeiger2 = &f2;
	fZeiger3 = &f3;
	fZeiger4 = &f4;

	//Feldzeiger auf Objekt
	Fahrzeug* fahrzeuge[4];
	fahrzeuge[0] = fZeiger1;
	fahrzeuge[1] = fZeiger2;
	fahrzeuge[2] = fZeiger3;
	fahrzeuge[3] = fZeiger4;

	vTabellenFormat();
	for (int i = 0; i < 4; i++)
	{
		fahrzeuge[i]->vAusgabe();
		cout << endl;

	}

	fahrzeuge[2] = NULL;

	vTabellenFormat();
	for (int i = 0; i < 4; i++)
	{
		fahrzeuge[i]->vAusgabe();
		cout << endl;
	}

}



//Aufgabe 2
void vAufgabe_2()
{

	int iAnzPKW;
	int iAnzFahrrad;
	PKW* pPKW;
	Fahrrad* pFahrrad;
	dGlobaleZeit = 0.0;

	cout << endl << "Geben Sie die Anzahl der zu erzeugenden PKW ein : ";
	cin  >> iAnzPKW;
	cout << endl << "Geben Sie die Anzahl der zu erzeugenden Fahrraeder ein : ";
	cin  >> iAnzFahrrad;
	cout << endl;


	//Vector mit erstellten Fahrzeugen und offener Größe
	vector<Fahrzeug*> vecFahrzeug;

	//Pkw's werden erstellt und der Zeiger wird dem Vector übergeben
	for (int i = 0; i < iAnzPKW; i++)
	{
		string sName;
		double dGeschwindigkeit;
		double dVerbrauch;
		double dTankvolumen;

		cout << "Geben Sie jeweils Namen, Geschwindigkeit, Verbrauch Und Tankvolumen fuer die PKW ein !" << endl;
		cout << "Name: ";
		cin  >> sName;
		cout << "Geschwindigkeit: ";
		cin  >> dGeschwindigkeit;
		cout << "Verbrauch: ";
		cin  >> dVerbrauch;
		cout << "Tankvolumen: ";
		cin  >> dTankvolumen;
		cout << endl;
		
		pPKW = new PKW(sName, dGeschwindigkeit, dVerbrauch, dTankvolumen);
		vecFahrzeug.push_back(pPKW);
	}


	//Fahräder werden erstellt und der Zeiger wird dem Vector übergeben
	for (int i = 0; i < iAnzFahrrad; i++)
	{
		string sName;
		double dGeschwindigkeit;

		cout << "Geben Sie jeweils Namen und Geschwindigkeit fuer die Fahrraeder ein !" << endl;
		cout << "Name: ";
		cin  >> sName;
		cout << "Geschwindigkeit: ";
		cin  >> dGeschwindigkeit;
		cout << endl;

		pFahrrad = new Fahrrad(sName, dGeschwindigkeit);
		vecFahrzeug.push_back(pFahrrad);
	}

	vector<Fahrzeug*>::iterator itVecF = vecFahrzeug.begin();

	int iCounter = 0;
	vTabellenFormat();
	for (dGlobaleZeit = 0.5; dGlobaleZeit < 8; dGlobaleZeit += 0.5)
	{
		iCounter++;
		cout << setprecision(0) << iCounter << ". Abfertigung" << endl;
		for (itVecF = vecFahrzeug.begin(); itVecF != vecFahrzeug.end(); itVecF++)
		{
			(*itVecF)->vAbfertigung();
			(*itVecF)->vAusgabe();
			cout << endl;
			if (fabs(dGlobaleZeit - 3) < 0.0001) //Absolutbetrag der Differenz
			{
				(*itVecF)->dTanken();
			}
		}
		cout << endl;
	}

}


//Aufgabe 3
void vAufgabe_3()
{
	//Ford
	PKW ford ("Ford", 120, 7, 55);
	//Audi + Zuweisungsoperator
	PKW audi = ford;
	audi.vSetGeschwindigkeit(230);
	audi.vSetName("Audi");
	//Fahrrad
	Fahrrad fahrrad ("Fahrrad", 20);


	//Abfertigung
	for (dGlobaleZeit = 0.5; dGlobaleZeit < 7; dGlobaleZeit += 0.5)
	{

		ford.vAbfertigung();
		audi.vAbfertigung();
		fahrrad.vAbfertigung();

	}

	// Ausgabeoperator '<<'
	vTabellenFormat();
	cout << setfill(' '); //Reset Fill
	cout << ford << endl;
	cout << audi << endl;
	cout << fahrrad << endl ;

	// Vergleich '<'
	if (audi < ford)
		cout << endl << "Ford ist am weitesten gefahren" << endl;
	else
		cout << endl << "Audi ist am weitesten gefahren" << endl;



}

/*void test() 
{
	PKW* a = new PKW("A", 60, 7, 10);
	PKW m("M", 120, 7, 10);
	PKW* b = new PKW("B", 120, 7, 10);

	dGlobaleZeit = 1;
	a->vAbfertigung();
	b->vAbfertigung();
	dGlobaleZeit = 2;
	a->vAbfertigung();
	b->vAbfertigung();
	dGlobaleZeit = 3;
	//cout << m;
	//cout << *a;
	if (*a < *b)
		cout <<"Max: " << *b;
	else
		cout << "Max: " << *a;

}*/


int main()
{
	//vAufgabe_1();
	//vAufgabe_1_deb();
	vAufgabe_2();
	//vAufgabe_3();
	//test();
	cout << "Programm mit beliebiger Eingabe beenden:" << endl;
	char c;
	cin >> c;
	return 0;
}