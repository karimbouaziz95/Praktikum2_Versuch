#include "Fahrzeug.h"
#include <string>
#include <iostream>
#include <iomanip>
#include "Fahrrad.h"
#include <vector>
#include "PKW.h"
#include <math.h>
#include "Weg.h"

using namespace std;

double dGlobaleZeit = 0.0;

void GrafikOberflaeche() 
{
	bInitialisiereGrafik(1800, 1200);
	int Koordinaten[] = { 750,250,100,250 };
	bZeichneStrasse("Weg1", "Weg2", 500, 2, Koordinaten);
}

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

void vTabellenFormatWeg()
{
	const char plus = '+';
	const char separator = ' ';
	cout << left << setw(8) << setfill(separator) << "ID";
	cout << left << setw(8) << setfill(separator) << "Name";
	cout << left << setw(3) << setfill(separator) << ":";
	cout << left << setw(12) << setfill(separator) << "Laenge";
	cout << left << setw(30) << setfill(separator) << "Geschwindigkeitsbegrenzung";
	cout << left << setw(30) << setfill(separator) << "Fahrzeuge auf diesem Weg" << endl;
	cout << left << setw(85) << setfill(plus) << "+" << endl;
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

void vAufgabe_4()
{
	//Erzeuge Weg
	Weg weg("Weg1", 300, 200);

	//Erzeuge Fahrzeuge
	PKW audi("Audi", 120, 5, 55);
	PKW ford("Ford", 80, 6, 60);
	Fahrrad fahrrad("Fahrrad", 26);

	//Setze Fahrzeuge auf die Straße
	weg.vAnnahme(&audi);
	weg.vAnnahme(&ford);
	weg.vAnnahme(&fahrrad);


	vTabellenFormatWeg();
	cout << weg << endl;
	cout << endl;

	vTabellenFormat();
	
	//Abfertigung des Weges und somit auch der Fahrzeuge auf dem Weg
	int iCounter = 0;
	for (dGlobaleZeit = 0; dGlobaleZeit < 8; dGlobaleZeit += 0.5) 
	{		
		iCounter++;
		
		weg.vAbfertigung();
		cout << endl << setprecision(0) << iCounter << ". Abfertigung" << endl;
		cout << audi << endl;
		cout << ford << endl;
		cout << fahrrad << endl;
		cout << endl;
	}
	


}

void vAufgabe_5()
{
	//erzeugen Sie nun zwei Wege(Laenge = 500.0 km)
	Weg weg1("Weg1", 500);
	Weg weg2("Weg2", 500, Autobahn);
	//auf die Sie jeweils ein parkendes und fahrendes Fahrzeug
	//mit unterschiedlichen Geschwindigkeiten setzen
	PKW *fzg1Weg1 = new PKW("Ford1", 140, 4);
	Fahrrad *fzg2Weg1 = new Fahrrad("BMX1", 30);
	PKW *fzg1Weg2 = new PKW("Ford2", 170, 5);
	PKW *fzg2Weg2 = new PKW("BMW2", 90, 8);
	//Weg 1
	weg1.vAnnahme(fzg1Weg1);//Fahrendes
	weg1.vAnnahme(fzg2Weg1, 3);//Parkendes 
	//Weg 2
	weg2.vAnnahme(fzg1Weg2);//Fahrendes
	weg2.vAnnahme(fzg2Weg2, 3);//Parkendes 
	//Die Wege fassen Sie grafisch zu einer Straße zusammen
	//(Hin - und Rückweg)
	GrafikOberflaeche();
	vTabellenFormat();
	for (dGlobaleZeit = 0; dGlobaleZeit <= 6.0; dGlobaleZeit += 0.25) {
		//Abfertigung
		weg1.vAbfertigung();
		weg2.vAbfertigung();
		//Zeichenen
		fzg1Weg1->vZeichnen(&weg1);
		fzg2Weg1->vZeichnen(&weg1);
		fzg1Weg2->vZeichnen(&weg2);
		fzg2Weg2->vZeichnen(&weg2);
		//Ausgabe
		cout << endl << " ----- Aktuelle Zeit: " << dGlobaleZeit << " -----" << endl;
		cout << *fzg1Weg1 << "Weg 1" << endl;
		cout << *fzg2Weg1 << "Weg 1" << endl;
		cout << *fzg1Weg2 << "Weg 2" << endl;
		cout << *fzg2Weg2 << "Weg 2" << endl;
		cout << endl;

		//Delay
		vSetzeZeit(dGlobaleZeit);
		vSleep(100);
	}
	vBeendeGrafik();
}

void vAufgabe_6() 
{
	//erzeugen Sie nun zwei Wege(Laenge = 500.0 km)
	Weg weg1("Weg1", 500);
	Weg weg2("Weg2", 500,80);
	//auf die Sie jeweils ein parkendes und fahrendes Fahrzeug
	//mit unterschiedlichen Geschwindigkeiten setzen
	PKW *fzg1Weg1 = new PKW("Ford1", 120,1);
	PKW *fzg2Weg1 = new PKW("BMW1", 200,1);
	PKW *fzg1Weg2 = new PKW("Ford2", 100,1);
	PKW *fzg2Weg2 = new PKW("BMW2", 230,1);
	//Weg 1
	weg1.vAnnahme(fzg1Weg1);//Fahrendes
	weg1.vAnnahme(fzg2Weg1,1);//Parkendes 
	//Weg 2
	weg2.vAnnahme(fzg1Weg2);//Fahrendes
	weg2.vAnnahme(fzg2Weg2, 2);//Parkendes 
	//Die Wege fassen Sie grafisch zu einer Straße zusammen
	//(Hin - und Rückweg)
	GrafikOberflaeche();
	for (dGlobaleZeit = 0; dGlobaleZeit <= 6.0; dGlobaleZeit += 0.3) {
		//Abfertigung
		weg1.vAbfertigung();
		weg2.vAbfertigung();
		//Zeichenen
		fzg1Weg1->vZeichnen(&weg1);
		fzg2Weg1->vZeichnen(&weg1);
		fzg1Weg2->vZeichnen(&weg2);
		fzg2Weg2->vZeichnen(&weg2);
		//Delay
		vSetzeZeit(dGlobaleZeit);
		vSleep(500);
	}
	vBeendeGrafik();
}

void vAufgabe_6a()
{
	//Initialisierung von rand
	srand((int)time(0)); //initialisierung mit der Zeit seit Nulldatum
	LazyListe<int> LListe;
	LazyListe<int>::iterator iterator;
	// Eine LazyListe von ganzzahligen Zufallszahlen zwischen 1 und 10 erzeugen
	for (int i = 1; i <= 10; i++) {
		LListe.push_front(rand() % 10 + 1);
	}
	//Liste Aktualisieren 
	//Sonst Ausgabe in den ersten zwei Zeilen Leer
	LListe.vAktualisieren();
	// Liste ausgeben
	for (iterator = LListe.begin(); iterator != LListe.end(); iterator++) {
		cout << (*iterator) << " ";
	}
	cout << endl;
	// innerhalb einer Schleife alle Elemente > 5 mit erase() loeschen
	for (iterator = LListe.begin(); iterator != LListe.end(); iterator++) {
		if (*iterator > 5) {
			LListe.erase(iterator);
		}
	}
	// Liste wieder ausgeben (da vAktualisieren() noch nicht ausgefuehrt wurde,
	// sollte hier dieselbe Ausgabe erfolgen)
	for (iterator = LListe.begin(); iterator != LListe.end(); iterator++) {
		cout << (*iterator) << " ";
	}
	cout << endl;
	//vAktualisieren() auf die LazyListe anwenden
	LListe.vAktualisieren();
	//Liste nochmal ausgeben (jetzt sollte sich die LazyListe geändert haben)
	for (iterator = LListe.begin(); iterator != LListe.end(); iterator++) {
		cout << (*iterator) << " ";
	}
	cout << endl;
	// Zum Schluss fügen Sie am Anfang und am Ende der Liste noch zwei beliebige
	// Zahlen ein ...
	LListe.push_back(10);
	LListe.push_front(1);
	LListe.vAktualisieren();
	// ...und geben die Liste zur Kontrolle nochmal aus.
	for (iterator = LListe.begin(); iterator != LListe.end(); iterator++) {
		cout << (*iterator) << " ";
	}
	cout << endl;
	


}

int main()
{
	//vAufgabe_1();
	//vAufgabe_1_deb();
	//vAufgabe_2();
	//vAufgabe_3();
	//vAufgabe_4(); 
	vAufgabe_5(); //Für Aufgabe 5 bei vAnnahme in Weg p_pFahrzeuge.vAktualisieren auskommentieren!
	//vAufgabe_6();	//Ident zu 5
	//vAufgabe_6a();
	//test();
	cout << endl;
	cout << "Programm mit beliebiger Eingabe beenden:" << endl;
	char c;
	cin >> c;
	
	return 0;
}