#include "AktivesVO.h"
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "Weg.h"
#include "Welt.h"
#include "SimuClient.h"
#include "LazyListe.h"
#include "Kreuzung.h"
#include <fstream>
#include <map>



#include <string>
using namespace std;
#include <ostream> 



#include <iostream>
#include <istream>
#include <iomanip>
#include <vector>
#include <math.h>

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

void vAufgabe_7() 
{

	//erzeugen Sie nun zwei Wege(Laenge = 500.0 km)
	Weg weg1("Weg1", 500);
	Weg weg2("Weg2", 500,100000,false);
	weg1.SetRueckweg(&weg2);
	weg2.SetRueckweg(&weg1);
	//auf die Sie jeweils ein parkendes und fahrendes Fahrzeug
	//mit unterschiedlichen Geschwindigkeiten setzen
	PKW *fzg1Weg1 = new PKW("Ford1", 120, 1);
	PKW *fzg2Weg1 = new PKW("BMW1", 200, 1.5);
	//Weg 1
	weg1.vAnnahme(fzg1Weg1);//Fahrendes
	weg1.vAnnahme(fzg2Weg1, 1);//Parkendes 
	//Die Wege fassen Sie grafisch zu einer Straße zusammen
	//(Hin - und Rückweg)
	GrafikOberflaeche();
	for (dGlobaleZeit = 0; dGlobaleZeit <= 6.0; dGlobaleZeit += 0.1) {
		//Abfertigung
		weg1.vAbfertigung();
		weg2.vAbfertigung();
		//Zeichenen
		//Delay
		vSetzeZeit(dGlobaleZeit);
		vSleep(100);
	}
	delete fzg1Weg1;
	delete fzg2Weg1;
	vBeendeGrafik();
}


void vAufgabe_8()
{
	bInitialisiereGrafik(1000, 700);

	Kreuzung* Kr1 = new Kreuzung("Kr1");
	bZeichneKreuzung(680, 40);
	//Tankkapazität für Kreuzung Kr2 auf 1000 Liter
	Kreuzung* Kr2 = new Kreuzung("Kr2", 1000);
	bZeichneKreuzung(680, 40);
	Kreuzung* Kr3 = new Kreuzung("Kr3");
	bZeichneKreuzung(680, 40);
	Kreuzung* Kr4 = new Kreuzung("Kr4");
	bZeichneKreuzung(680, 40);

	//Koordinaten
	int strasse1[4] = { 680,300,680,40 };
	int strasse2[12] = { 680,570,850,570,970,500,970,390,850,300,680,300 };
	int strasse3[4] = { 680,570,680,300 };
	int strasse4[4] = { 320,300,680,300 };
	int strasse5[10] = { 320,300,320,420,350,510,500,570,680,570 };
	int strasse6[14] = { 320,300,170,300,70,250,80,90,200,60,320,150,320,300 };

	//Straße1: W12 / W21; 40km; 50km/h; schlecht 
	Kr1->vVerbinde("W12", "W21", 40, Kr2, 50, true);
	bZeichneStrasse("W12", "W21", 40, 2, strasse1);
	//Straße2: W23a / W32a; 115km; - ; gut
	Kr2->vVerbinde("W23a", "W32a", 115, Kr3, 120, false);
	bZeichneStrasse("W23a", "W32a", 115, 6, strasse2);
	//Straße3: W23b / W32b; 40km; 50km / h; schlecht 
	Kr2->vVerbinde("W23b", "W32b", 40, Kr3, 50, true);
	bZeichneStrasse("W23b", "W32b", 40, 2, strasse3);
	//Straße4 : W24 / W42; 55km; 50km / h; schlecht 
	Kr2->vVerbinde("W24", "W42", 55, Kr4, 50, true);
	bZeichneStrasse("W24", "W42", 55, 2, strasse4);
	//Straße5 : W34 / W43; 85km; -; gut
	Kr3->vVerbinde("W34", "W43", 85, Kr4, 120, false);
	bZeichneStrasse("W34", "W43", 85, 5, strasse5);
	//Straße6 : W44a / W44b; 130km; 100km / h; gut
	Kr4->vVerbinde("W44a", "W44b", 130, Kr4, 100, false);
	bZeichneStrasse("W44a", "W44b", 130, 7, strasse6);

	double totalZeit = 100;
	double nextSpawn = 0;
	list<Fahrzeug*> fahrzeuge;
	for (dGlobaleZeit = 0; dGlobaleZeit <= totalZeit; dGlobaleZeit += 0.1) 
	{
		cout << endl << " - - - - - - " << dGlobaleZeit << " - - - - - - " << endl;
		Kr1->vAbfertigung();
		Kr2->vAbfertigung();
		Kr3->vAbfertigung();
		Kr4->vAbfertigung();
		if (dGlobaleZeit > nextSpawn)
		{
			static int  n= 0;
			n++;
			string name = "PKW";
			name += to_string(n);
			PKW *pkw = new PKW(name, 50 + rand()%70, 1);
			fahrzeuge.push_front(pkw);
			Kr1->vAnnahme(pkw,1);
			nextSpawn += 5;
		}
		/*
		cout << *Kr1 << endl;
		cout << *Kr2 << endl;
		cout << *Kr3 << endl;
		cout << *Kr4 << endl;
		//*/
		vSetzeZeit(dGlobaleZeit);
	}
	vBeendeGrafik();
}

void vAufgabe_9()
{
	Fahrrad rad1;
	Kreuzung kr1;

	string name;
	int geschwindigkeit;
	int verb;
	int vol;
	string nameR;

	ifstream infile ("VO.dat");
	infile >> name >> geschwindigkeit >> verb >> vol >> nameR;

	cout << "Name:" << name << endl;
	cout << "Geschw:" << geschwindigkeit << endl;
	cout << "Verb:" << verb << endl;
	cout << "Vol:" << vol << endl;
	cout << "NameR:" << nameR << endl;

	PKW pkw1;
	PKW pkw2();
	try
	{
		cin >> pkw1;
	}
	catch (string* error)
	{
		cout << *error;
	}
	getchar();
}

void vAufgabe_9b()
{
	Welt world;

	try
	{
		world.vEinlesenMitGrafik();
	}
	catch (string* error)
	{
		cout << *error << endl;
	}


	for (dGlobaleZeit = 0; dGlobaleZeit < 25; dGlobaleZeit += 0.1)
	{
		world.vSimulation();
		vSetzeZeit(dGlobaleZeit);
	}
	vBeendeGrafik();

}

int main()
{
	//vAufgabe_1();
	//vAufgabe_1_deb();
	//vAufgabe_2();
	//vAufgabe_3();
	//vAufgabe_4(); 
	//vAufgabe_5(); //Für Aufgabe 5 bei vAnnahme in Weg p_pFahrzeuge.vAktualisieren auskommentieren!
	//vAufgabe_6();	//Ident zu 5
	//vAufgabe_6a();
	//vAufgabe_7();
	//vAufgabe_8();
	//vAufgabe_9();
	vAufgabe_9b();
	//test();
	cout << endl;
	cout << "Programm mit beliebiger Eingabe beenden:" << endl;
	char c;
	cin >> c;
	
	return 0;
}