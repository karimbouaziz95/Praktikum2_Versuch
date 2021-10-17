//libraries
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <vector>
#include <math.h>
#include <stddef.h>
#include <stddef.h>
#include  <time.h>

//header Dateien
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "AktivesVO.h"
#include "Weg.h"



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
		 << setw(19) << "Abschnitsstrecke"
		 << setw(19) << "Gesamtverbrauch " 
		 << setw(12) << "Tankinhalt "      
		 << endl 
		 << setfill('+') << setw(120) << "" << setfill (' ') << endl; 
}


//Aufgabe 1
void vAufgabe_1() 
{
	//statisch erzeugt
	Fahrzeug Fzg1;                  //Standardkosntruktor
	Fzg1.vsetName("Mercedes");
	Fzg1.vsetspeed(210.00);
	Fahrzeug Fzg2 ("Audi");         //Konstruktor mit Namen
	Fzg2.vsetspeed(222.00);
	Fahrzeug Fzg5 ("BMW" , 180.00); //Konstruktor mit Namen und Geschwindigkit


	//dynamisch erzeugt
	Fahrzeug* Fzg3;
	Fzg3 = new Fahrzeug () ;        //Standardkosntruktor
	Fzg3 ->vsetspeed(180.00);
	Fahrzeug* Fzg4;
	Fzg4 = new Fahrzeug ("");       //Konstruktor mit Namen
	Fzg4 ->vsetspeed(210.00);

	cout << endl;
	
	//Namen einlesen für dynamische Objekte 
	cout << "Geben Sie einen Namen fuer die Fahrzeuge ein !" << endl;
	string a ,b;
	cin >> a;
	Fzg3 ->vsetName(a);
	cin >> b;
	Fzg4 ->vsetName(b);
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
	Ford.vsetspeed(225);
	Ford.vsetName("Ford");
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
	{ cout << "Gewinner : " << endl << endl << Ford << endl;
	  cout << "Verlierer : " << endl << endl << Audi;
	}
	else 
	{ cout << "Gewinner : " << endl << endl << Audi << endl;
	  cout << "Verlierer : " << endl << endl << Ford;
	}

	//Wettrennen Fahrrad
	cout << endl << endl << "Wettrennen fuer Fahrraeder !" << endl;
	Fahrrad Hans;
	Hans.vsetspeed(30);
	Hans.vsetName("Hans");
	Fahrrad Klaus;
	Klaus = Hans;
	Klaus.vsetspeed(25);
	cout << endl << "Teilnehmer : " << endl << endl << Hans << endl << endl << Klaus << endl;

	for (dGlobaleZeit = 0; dGlobaleZeit < 4; dGlobaleZeit++)
	{
		Hans.vAbfertigung();
		Klaus.vAbfertigung();
	}
	
	cout << "Gewinner wird ermittelt !" << endl << endl;
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


//Aufgabe 4
void vAufgabe_4()
{
	vTabellenformat();
	dGlobaleZeit = 2;
	Weg Wüllnerstraße("Stadt",100,Innerorts);
	PKW Auto1("Audi", 220, 8);
	PKW Auto2("Benz", 220, 6.53);
	PKW* FZG1;
	PKW* FZG2;
	FZG1 = &Auto1;
	FZG2 = &Auto2;
	Wüllnerstraße.vAnnahme(FZG1);
	Wüllnerstraße.vAnnahme(FZG2, 1);
	Wüllnerstraße.vAbfertigung();
	cout << Auto1 << endl << Auto2 << Wüllnerstraße << endl;
	dGlobaleZeit++;
	Wüllnerstraße.vAbfertigung();
	cout << Auto1 << endl << Auto2 << Wüllnerstraße;
}


//Aufgabe 5
void vAufgabe_5()
{
	//Weg
	Weg Templergraben("Templergraben",190,Innerorts);
	
	//Fahrzeuge
	PKW* FZG1;
	PKW* FZG2;

		//Fahrendes Fahrzeug
		FZG1 = new PKW("Audi_f", 230, 7.6);

		//Parkendes Fahrzeug
		FZG2 = new PKW("Opel_p", 180, 5.6);

	//Annahme der Fahrzeuge
	Templergraben.vAnnahme(FZG1);
	Templergraben.vAnnahme(FZG2, 3);  //Startzeitpunkt 3

	//Tabellenkopf
	vTabellenformat();

	//Abfertigungsschleife
	for(dGlobaleZeit = 1; dGlobaleZeit < 5; dGlobaleZeit += 0.3 )
	{
		Templergraben.vAbfertigung();
		//Ausgabe
		cout << dGlobaleZeit << ". Abfertigung !" << endl
			 << *FZG1 << endl 
			 << *FZG2 << endl << endl;
	}	
}


//Aufgabe 5 Grafikausgabe
void vAufgabe_5_Gra()
{
	//Wege
	Weg* Strasse_hin;
	Strasse_hin = new Weg("Strasse1",500,Innerorts);
	Weg* Strasse_zur;
	Strasse_zur = new Weg("Strasse2",500);
	
	//Fahrzeuge
	PKW* FZG1;
	Fahrrad* FRAD2;
	PKW* FZG3;
	Fahrrad* FRAD4;

		//Fahrendes Fahrzeug
		FZG1 = new PKW("Audi_f", 230, 7.6);
		FRAD2 = new Fahrrad("Hans_f", 30);

		//Parkendes Fahrzeug
		FZG3 = new PKW("Opel_p", 180, 5.6);
		FRAD4 = new Fahrrad("Franz_p", 35);

	//Annahme der Fahrzeuge
	Strasse_hin->vAnnahme(FZG1);
	Strasse_hin->vAnnahme(FRAD2);
	Strasse_zur->vAnnahme(FZG3, 3);                                            //Startzeitpunkt 3
	Strasse_zur->vAnnahme(FRAD4, 2);                                           //Startzeitpunkt 2

	//Grafikausgabe
	bInitialisiereGrafik(800, 500);                                           //Initialisierung
	vSetzeZeit(dGlobaleZeit);                                               
	int Koordinaten [4] = {200, 250, 700, 250};                               //Koordinaten
	bZeichneStrasse("Strasse1", "Strasse2", 500, 2, Koordinaten);			  //Strasse zeichnen
	

	//Abfertigungsschleife
	for(dGlobaleZeit = 0; dGlobaleZeit < 5; dGlobaleZeit += 0.1 )
	{
		vSetzeZeit(dGlobaleZeit);
		Strasse_hin->vAbfertigung();
		Strasse_zur->vAbfertigung();
		FZG1->vZeichnen(Strasse_hin);
		FRAD2->vZeichnen(Strasse_hin);
		FZG3->vZeichnen(Strasse_zur);
		FRAD4->vZeichnen(Strasse_zur);
		vSleep(100);
	}
}


//Aufgabe 6a
void vAufgabe_6a()
{
	srand((int)time(0));
	LazyListe<int> Lazylist;
	
	//Füllen der Liste und Aktualisieren.
	for(int zaehler = 1; zaehler < 11; ++zaehler)
    {
		Lazylist.push_front(rand() % 10);
    }
    Lazylist.vAktualisieren();

	//Liste ausgeben 
	LazyListe<int>::iterator iter;
	for(iter = Lazylist.begin(); iter != Lazylist.end(); ++iter)
    {
        cout << (*iter) << endl;
    } 
	cout << endl;

	//Löschen der Elemente < 5
	for(iter = Lazylist.begin(); iter != Lazylist.end(); ++iter)
    {
		if((*iter) < 5) 
		{
			Lazylist.erase(iter);
		}
    }

	//Ausgeben, es sollten keine Veränderungen sichtbar sein.
	for(iter = Lazylist.begin(); iter != Lazylist.end(); ++iter)
    {
        cout << (*iter) << endl;
    }  
	cout << endl;

	//Lazylist aktualisieren und ausgeben
	Lazylist.vAktualisieren();
	for(iter = Lazylist.begin(); iter != Lazylist.end(); ++iter)
    {
        cout << (*iter) << endl;
    } 
	cout << endl;

	//Zahlen am Anfang und am Ende anfügen und ausgeben
	Lazylist.push_front(100);;
    Lazylist.push_back(200);
    Lazylist.vAktualisieren();

	for(iter = Lazylist.begin(); iter != Lazylist.end(); ++iter)
    {
        cout << (*iter) << endl;
    } 
	cout << endl;
}


//Aufgabe 6 
void vAufgabe_6()
{
	//Wege
	Weg* Strasse_hin;
	Strasse_hin = new Weg("Strasse1",500,Innerorts);
	Weg* Strasse_zur;
	Strasse_zur = new Weg("Strasse2",500);
	Weg* Strasse_hin2;
	Strasse_hin2 = new Weg("Strasse3",500,Landstraße);
	Weg* Strasse_zur2;
	Strasse_zur2 = new Weg("Strasse4",500);
	
	//Fahrzeuge
	PKW* FZG1;
	Fahrrad* FRAD2;
	PKW* FZG3;
	Fahrrad* FRAD4;

		//Fahrendes Fahrzeug
		FZG1 = new PKW("Audi_f", 230, 8.6);
		FRAD2 = new Fahrrad("Hans_f", 30);

		//Parkendes Fahrzeug
		FZG3 = new PKW("Opel_p", 180, 5.6, 90);
		FRAD4 = new Fahrrad("Franz_p", 35);

	//Annahme der Fahrzeuge
	Strasse_hin->vAnnahme(FZG1);
	Strasse_hin->vAnnahme(FRAD2);
	Strasse_zur->vAnnahme(FZG3, 3);                                            //Startzeitpunkt 3
	Strasse_zur->vAnnahme(FRAD4, 2);                                           //Startzeitpunkt 2

	//Grafikausgabe
	bInitialisiereGrafik(900, 900);                                          //Initialisierung
	vSetzeZeit(dGlobaleZeit);                                               
	int Koordinaten [4] = {200, 250, 700, 250};                                //Koordinaten
	bZeichneStrasse("Strasse1", "Strasse2", 500, 2, Koordinaten);			   //Strasse zeichnen
	int Koordinaten2 [4] = {700, 250, 700, 750};                               //Koordinaten
	bZeichneStrasse("Strasse3", "Strasse4", 500, 2, Koordinaten2);			   //Strasse zeichnen

	//Abfertigungsschleife
	for(dGlobaleZeit = 0; dGlobaleZeit < 8; dGlobaleZeit +=1 )
	{
		vSetzeZeit(dGlobaleZeit);
		Strasse_hin->vAbfertigung();
		Strasse_zur->vAbfertigung();
		FZG1->vZeichnen(Strasse_hin);
		FRAD2->vZeichnen(Strasse_hin);
		FZG3->vZeichnen(Strasse_zur);
		FRAD4->vZeichnen(Strasse_zur);
		vSleep(10);
	}

	//Annahme auf der Zweiten Strasse
	Strasse_hin2->vAnnahme(FZG3);     
	
	//Abfertigungsschleife 2
	for(dGlobaleZeit = 7.2; dGlobaleZeit < 22; dGlobaleZeit +=0.2 )
	{
		vSetzeZeit(dGlobaleZeit);
		Strasse_hin2->vAbfertigung();
		Strasse_zur2->vAbfertigung();
		Strasse_hin->vAbfertigung();
		Strasse_zur->vAbfertigung();
		FZG1->vZeichnen(Strasse_hin);
		FRAD2->vZeichnen(Strasse_hin);
		FZG3->vZeichnen(Strasse_zur2);
		FRAD4->vZeichnen(Strasse_zur);
		vSleep(10);
	}
}



// Main-Funktion
int main() 
{
	dGlobaleZeit = 0.0;

	//vAufgabe_1();
	//vAufgabe_1_deb();
	//vAufgabe_2();
	//vAufgabe_3();
	//vAufgabe_4();
	//vAufgabe_5();
	//vAufgabe_5_Gra();
	//vAufgabe_6a();
	vAufgabe_6();
	getchar();
}
