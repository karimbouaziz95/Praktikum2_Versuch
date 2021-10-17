//libraries
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <vector>
#include <math.h>
#include <stddef.h>

//header Dateien
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"


double dGlobaleZeit;


//Tabellen-Formatierung
void vTabellenformat()
{
	cout << resetiosflags(ios::right) << setiosflags(ios::left) //jetzt rechtsbündig -> aus Aufgabe 1.5
	     << setw(5)  << "ID" 
	     << setw(14) << "Name" 
	     << setw(4)  << ":" 
	     << setw(13) << "MaxKmh" 
	     << setw(17) << "Gesamtstrecke" 
		 << setw(17) << "Akt. Geschw."
		 << setw(17) << "Gesamtverbrauch " 
		 << setw(12) << "Tankinhalt "      
		 << endl 
		 << setfill('+') << setw(105) << "" << setfill (' ') << endl; 
}


//Aufgabe 1
void vAufgabe_1() 
{
	//statisch erzeugt
	Fahrzeug Fzg1;                  //Standardkosntruktor
	Fzg1.vgetName("Mercedes");
	Fzg1.vgetspeed(210.00);
	Fahrzeug Fzg2 ("Audi");         //Konstruktor mit Namen
	Fzg2.vgetspeed(222.00);
	Fahrzeug Fzg5 ("BMW" , 180.00); //Konstruktor mit Namen und Geschwindigkit


	//dynamisch erzeugt
	Fahrzeug* Fzg3;
	Fzg3 = new Fahrzeug () ;        //Standardkosntruktor
	Fzg3 ->vgetspeed(180.00);
	Fahrzeug* Fzg4;
	Fzg4 = new Fahrzeug ("");       //Konstruktor mit Namen
	Fzg4 ->vgetspeed(210.00);

	cout << endl;
	
	//Namen einlesen für dynamische Objekte 
	cout << "Geben Sie einen Namen fuer die Fahrzeuge ein !" << endl;
	Fzg3 ->vsetName();
	Fzg4 ->vsetName();
	cout << endl;

	dGlobaleZeit = 0;

	//Abfertigung
	while (dGlobaleZeit < 5)
	{
		dGlobaleZeit = dGlobaleZeit + 0.2;
		Fzg1.vAbfertigung();
		Fzg2.vAbfertigung();
		Fzg3 ->vAbfertigung();
		Fzg4 ->vAbfertigung();
		Fzg5.vAbfertigung();
	}


	// Tabellenausgabe
	vTabellenformat();
    Fzg1.vAusgabe();
	cout << endl;
	Fzg2.vAusgabe();
	cout << endl;
	Fzg5.vAusgabe();
	cout << endl;
	Fzg3 ->vAusgabe();
	cout << endl;
	Fzg4 ->vAusgabe();
	cout << endl;


	delete Fzg4;
	delete Fzg3;
}


//Aufgabe 1 Debugger
void vAufgabe_1_deb()
{
	Fahrzeug Fzg1_deb ("Pagani" , 310.00);
	Fahrzeug Fzg2_deb ("Koenigsegg" , 370.00);
	Fahrzeug Fzg3_deb ("Lotus" , 270.00);
	Fahrzeug Fzg4_deb ("Aston Martin" , 250.00);
	 
	//Zeiger auf Objekt
	Fahrzeug* Fzg1zeiger;
	Fahrzeug* Fzg2zeiger;
	Fahrzeug* Fzg3zeiger;
	Fahrzeug* Fzg4zeiger;
	
	Fzg1zeiger = &Fzg1_deb;
	Fzg2zeiger = &Fzg2_deb;
	Fzg3zeiger = &Fzg3_deb;
	Fzg4zeiger = &Fzg4_deb;

    //Feld Zeiger auf Objekt
	Fahrzeug* feld_name[4];

    feld_name [0] = Fzg1zeiger;
	feld_name [1] = Fzg2zeiger;
	feld_name [2] = Fzg3zeiger;
	feld_name [3] = Fzg4zeiger;

	vTabellenformat();
    for (int i = 0; i <= 3; i++)
	{
		feld_name[i] ->vAusgabe();
		cout << endl;
	}

	cout << endl << endl ;

	feld_name [2] = NULL;      //NULL-Zeiger derefenzieren UNGÜLTIG
	vTabellenformat();
	for (int i = 2 ; i<3; i++)
	{
		feld_name[i] ->vAusgabe();
		cout << endl;
	}

	cout << endl;
}


//Aufgabe 2
void vAufgabe_2()
{
	int iAnzPKW;
	int iAnzFahrrad;
	PKW* pPKW;
	Fahrrad* pFahrrad;
	dGlobaleZeit = 0.0;
	
	cout << endl << "Geben Sie die Anzahl ,der zu erzeugenden PKW's ein : ";
	cin  >> iAnzPKW;
	cout << endl << "Geben Sie die Anzahl ,der zu erzeugenden Fahrraeder ein : ";
	cin  >> iAnzFahrrad;
	cout << endl;


	//Vector mit erstellten Fahrzeugen und offener Größe
	vector<Fahrzeug*> vecFahrzeug;

    //Fahräder werden erstellt und der Zeiger wird dem Vector übergebn
	for (int i = 0; i < iAnzPKW; i++)
	{
		string sName;
		double dSpeed;
		double dVerbrauch;
		double dTankVol;
	    cout << "Geben Sie jeweils Namen, Geschwindigekit, Verbrauch Und Tankvolumen fuer die Pkw's ein !" << endl;
		cout << "Name: ";
		cin  >> sName;
		cout << "Geschwindigkeit: ";
		cin  >> dSpeed;
		cout << "Verbrauch: ";
		cin  >> dVerbrauch;
		cout << "Tankvolumen: ";
		cin  >> dTankVol;
		cout << endl;
		pPKW = new PKW(sName,dSpeed,dVerbrauch,dTankVol);
		vecFahrzeug.push_back(pPKW);
	}

	//Pkw's werden erstellt und der Zeiger wird dem Vector übergeben
	for (int i = 0; i < iAnzFahrrad; i++)
	{
		string sName;
		double dSpeed;
		cout << "Geben Sie jeweils Namen und Geschwindigkeit fuer die Fahrraeder ein !" << endl;
		cout << "Name: ";
		cin  >> sName;
		cout << "Geschwindigkeit: ";
		cin  >> dSpeed;
		cout << endl;
		pFahrrad = new Fahrrad(sName,dSpeed);
		vecFahrzeug.push_back(pFahrrad);
	}

	vector<Fahrzeug*>::iterator itVecF = vecFahrzeug.begin();

	int iZähler = 0;
	vTabellenformat();
	for (dGlobaleZeit = 0.5; dGlobaleZeit < 8; dGlobaleZeit += 0.5)
	{
		iZähler++;
		cout << setprecision(0) << iZähler << ". Abfertigung" << endl;
		for(itVecF = vecFahrzeug.begin(); itVecF != vecFahrzeug.end(); itVecF++)
		{
			(*itVecF)->vAbfertigung();
			(*itVecF)->vAusgabe();
			cout << endl;
			if (fabs(dGlobaleZeit-3) < 0.0001) //Absolutbetrag der Differenz
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
	//Wettrennen PKW
	cout << "Wettrennen fuer PKW !" << endl << endl;
	PKW Audi("Audi" , 220 , 7.6 , 55);
	PKW Ford = Audi;
	Ford.vgetspeed(225);
	Ford.vgetName("Ford");
	vTabellenformat();
	cout << endl << "Teilnehmer : " << endl << endl << Audi << Ford << endl;
    
	for (dGlobaleZeit = 0; dGlobaleZeit < 4; dGlobaleZeit++)
	{
		Audi.vAbfertigung();
		Ford.vAbfertigung();
	}
	
	cout << "Gewinner wird ermittelt !" << endl;
	bool winner1 = Audi < Ford;

	if (winner1)
	{ cout << "Gewinner : " << endl << endl << Ford;
	  cout << "Verlierer : " << endl << endl << Audi;
	}
	else 
	{ cout << "Gewinner : " << endl << endl << Audi;
	  cout << "Verlierer : " << endl << endl << Ford;
	}

	//Wettrennen Fahrrad
	cout << endl << endl << "Wettrennen fuer Fahrraeder !" << endl;
	Fahrrad Hans;
	Hans.vgetspeed(30);
	Hans.vgetName("Hans");
	Fahrrad Klaus;
	Klaus = Hans;
	Klaus.vgetspeed(25);
	cout << endl << "Teilnehmer : " << endl << endl << Hans << Klaus << endl;

	for (dGlobaleZeit = 0; dGlobaleZeit < 4; dGlobaleZeit++)
	{
		Hans.vAbfertigung();
		Klaus.vAbfertigung();
	}
	
	cout << "Gewinner wird ermittelt !" << endl;
	bool winner2 = Hans < Klaus;

	if (winner2)
	{ cout << "Gewinner : " << endl << endl << Klaus << endl;
	  cout << "Verlierer : " << endl << endl << Hans;
	}
	else 
	{ cout << "Gewinner : " << endl << endl << Hans << endl;
	  cout << "Verlierer : " << endl << endl << Klaus;
	}
}


// Main-Funktion
int main() 
{
	dGlobaleZeit = 0.0;

	//vAufgabe_1();
	//vAufgabe_1_deb();
	vAufgabe_2();
	//vAufgabe_3();
	cout << endl << "Druecken Sie eine Taste";
	getchar();
	getchar();
	
}
