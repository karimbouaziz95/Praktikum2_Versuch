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

void vTabelle();
void vAusgabe();


void vAufgabe7();
void vAufgabe8();
void vAufgabe9();
void vAufgabe10();

//Globale Uhr
extern double dGlobaleZeit = 0.0;

//Hauptprogramm ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main()
{

 
    //vAufgabe7();
	//vAufgabe8();
	//vAufgabe9();
	vAufgabe10();
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



//Aufgabe7+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void vAufgabe7()
{
    PKW auto1("Porsche");
    Fahrrad fahr1("dieter");
    PKW auto2("VW");
	//auto1.dTanken();
    auto2.dTanken();
	Weg way1("way1",500);
	Weg way2("way2",500);
    way1.vAnnahme(&fahr1,1);
	way1.vAnnahme(&auto1,1);

	bInitialisiereGrafik(800,500);
	
	int tab[4] = {700, 250, 100, 250};
	bZeichneStrasse("way1","way2",500,2,tab);
    vTabelle();
    int dings = 0;

	

	for(dGlobaleZeit; dGlobaleZeit<=40; dGlobaleZeit=dGlobaleZeit+0.5)
    {    
        if((dGlobaleZeit>= 12.5)&&(dings<1))
        {
            way1.vAnnahme(&auto2,14);
            dings ++;
        }
        vSetzeZeit(dGlobaleZeit);
        way1.vAbfertigung();
		bZeichnePKW("Porsche","way1",auto1.GetAbschnittStrecke()/way1.GetLaenge(),auto1.dGeschwindigkeit(),auto1.GetTank());
        bZeichneFahrrad("dieter","way1",fahr1.GetAbschnittStrecke()/way1.GetLaenge(),fahr1.dGeschwindigkeit());
        if((dGlobaleZeit>= 12.5))
        {
            bZeichnePKW("VW","way1",auto2.GetAbschnittStrecke()/way1.GetLaenge(),auto2.dGeschwindigkeit(),auto2.GetTank());
        }
		vSleep(250);
	    cout << auto1 << endl;
        cout << fahr1 << endl;
        cout << auto2 << endl;
        cout << way1 << endl;
    }
    vBeendeGrafik();
}

void vAufgabe8()
{
	bInitialisiereGrafik(1000,700);
	enum {Innerorts = 50, Landstrasse = 100, Autobahn = 9999};

	//Strassen und Kreuzungen anlegen
	int strasse1[4]  = {680,300,680,40};
	int strasse2[12] = {680,570,850,570,970,500,970,390,850,300,680,300};
	int strasse3[4]  = {680,570,680,300};
	int strasse4[4]  = {320,300,680,300};
	int strasse5[10] = {320,300,320,420,350,510,500,570,680,570};
	int strasse6[14] = {320,300,170,300,70,250,80,90,200,60,320,150,320,300};

// Wege initialisieren
	Weg Str1_W12("Str1_W12",40,50,false);
	Weg Str1_W21("Str1_W21",40,50,false);
	Weg Str2_W23a("Str2_W23a",115,Autobahn ,false);
	Weg Str2_W32a("Str2_W32a",115,Autobahn ,false);
	Weg Str3_W23b("Str2_W23b",115,50 );
	Weg Str3_W32b("Str2_W32b",40,50 );
	Weg Str4_W24("Str4_W24",55,50 );
	Weg Str4_W42("Str4_W42",55,50 );
	Weg Str5_W34("Str5_W34",85,Autobahn ,false);
	Weg Str5_W43("Str5_W43",85,Autobahn ,false);
	Weg Str6_W44a("Str6_W44a",130,100 ,false);
	Weg Str6_W44b("Str6_W44b",130,100 ,false);


	bZeichneStrasse("Str1_W12","Str1_W21",40,2,strasse1);
	bZeichneStrasse("Str2_W23a","Str2_W32a",115,6,strasse2);
	bZeichneStrasse("Str3_W23b","Str3_W32b",40,2,strasse3);
	bZeichneStrasse("Str4_W24","Str4_W42",55,2,strasse4);
	bZeichneStrasse("Str5_W34","Str5_W43",85,5,strasse5);
	bZeichneStrasse("Str6_W44a","Str6_W44b",130,7,strasse6);


//neue Kreuzungen erstellen
	Kreuzung * kr1 = new Kreuzung("Kr-1",1000);
	Kreuzung * kr2 = new Kreuzung("Kr-2");
	Kreuzung * kr3 = new Kreuzung("Kr-3");
	Kreuzung * kr4 = new Kreuzung("Kr-4");

	//Kreuzung1 
	bZeichneKreuzung(680,40);
	kr1->vVerbinde("Str1_W12","Str1_W21",40,kr2,Str1_W12.GetLimit(),Str1_W12.GetUeberholverbot());

	//Kreuzung2
	bZeichneKreuzung(680,300); 
	kr2->vVerbinde("Str2_W23a","Str2_W32a",115, kr3,Str2_W23a.GetLimit(),Str2_W23a.GetUeberholverbot());
	kr2->vVerbinde("Str3_W23b","Str3_W32b",40, kr3,Str3_W23b.GetLimit(),Str3_W23b.GetUeberholverbot());
	kr2->vVerbinde("Str4_W24","Str4_W42",55, kr4,Str4_W24.GetLimit(),Str4_W24.GetUeberholverbot());

	//Kreuzung3
	bZeichneKreuzung(680,570); 
	kr3->vVerbinde("Str5_W34","Str5_W43", 85, kr4,Str5_W34.GetLimit(), Str5_W34.GetUeberholverbot());

	//Kreuzung4
	bZeichneKreuzung(320,300); 
	kr4->vVerbinde("Str6_W44a","Str6_W44b", 130, kr4,Str6_W44a.GetLimit(),Str6_W44a.GetUeberholverbot());


	/*
	//Kreuzung1 zeichnen
	bZeichneKreuzung(680,40);
	kr1->vVerbinde("Str1_W21","Str1_W12",40,kr2,Innerorts,true);

	//Kreuzung2
	bZeichneKreuzung(680,300); 
	kr2->vVerbinde("Str2_W32a","Str2_W23a",115, kr3,Autobahn,false);
	kr2->vVerbinde("Str3_W32b","Str3_W23b",40, kr3,Innerorts,true);
	kr2->vVerbinde("Str4_W42","Str4_W24",55, kr4,Innerorts,true);

	//Kreuzung3
	bZeichneKreuzung(680,570); 
	kr3->vVerbinde("Str5_W43","Str5_W34", 85, kr4,Autobahn, false);

	//Kreuzung4
	bZeichneKreuzung(320,300); 
	kr4->vVerbinde("Str6_W44b","Str6_W44a", 130, kr4,Landstrasse,false);*/


	/*
	Fahrzeug* pkw = new PKW("Porsche", 120, 80, 10);
	Fahrzeug* pkw2 = new PKW("Audi", 140, 80, 10);
	Fahrzeug* fahrrad = new Fahrrad("Emma", 30);*/

	PKW pkw("Porsche", 125, 0.1, 100);
	pkw.dTanken();
	PKW pkw2("Audi", 145, 0.1, 100);
	pkw2.dTanken();
	Fahrrad fahrrad("Emma",10);

	kr1->vAnnahme(&pkw, 0.5);
	kr1->vAnnahme(&pkw2, 0.75);
	kr1->vAnnahme(&fahrrad, 0.0);


	for(dGlobaleZeit=0;dGlobaleZeit<=25;dGlobaleZeit += 0.1)
	{
		vSetzeZeit(dGlobaleZeit); // zeige Zeit in Ausgabefenster
		kr1->vAbfertigung();
		kr2->vAbfertigung();
		kr3->vAbfertigung();
		kr4->vAbfertigung();
		//vSleep(600);
	}


	vBeendeGrafik();

}

void vAufgabe9()
{
	/*
	PKW auto1;
	Fahrrad rad1;
	Kreuzung kr1;

	string Name;
	int Geschw;
	int Verb;
	int Vol;
	string NameR;

	char array[2][200];
	ifstream infile ("VO.dat");
	infile >> Name >> Geschw>> Verb >> Vol>>NameR ;
	


	cout << "Name:" << Name<< endl;
	cout << "Geschw:" << Geschw << endl;
	cout << "Verb:" << Verb << endl;
	cout << "Vol:" << Vol << endl;
	cout << "NameR:" <<NameR<< endl;
	//cout << rad1 << endl;

	*/
	PKW auto2("porsche");
	PKW  auto1("");
	try
	{
		cin >> auto1;
	}
	catch (string* error)
	{cout << *error;}
	getchar();
}

void vAufgabe10()
{
	Welt world;

	try
	{
	world.vEinlesenMitGrafik();
	}
	catch(string* error)
	{
		cout << *error << endl;
	}


	for(dGlobaleZeit=0; dGlobaleZeit < 25; dGlobaleZeit +=0.1)
	{
		world.vSimulation();
		vSetzeZeit(dGlobaleZeit);
	}
		vBeendeGrafik();

}


		  