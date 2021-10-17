#pragma warning(disable:4786)
#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include "MyClass.h"
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "AktivesVO.h"
#include "Weg.h"
#include "SimuClient.h"
#include "LazyListe.h"
#include "LazyAktion.h"
#include "Welt.h"



using namespace std;
double dGlobaleZeit = 0.0;
void vGrafikOberflaeche()
{

	bInitialisiereGrafik(800,500);
	int Koordinaten[] = {750,250,100,250};
	bZeichneStrasse("Way_1","Way_2",500,2,Koordinaten);


}
void vUeberschrift(){
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout << setiosflags(ios::left) << setw(5) << "ID" << setw(10) << "Name" << setw(5) << ":" <<setw(13)<<"Laenge/Kmh"
		 << setw(20) << "Objekte(nur Weg)" << setw(10)<<"Strecke" <<setw(10)<< "Tankinhalt" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
}
/*void vAufgabe_6()
{
	vGrafikOberflaeche();
	Weg *Way_1 = new Weg("Way_1", 500.0);
	Weg *Way_2 = new Weg("Way_2", 500.0, Landstraﬂe);

	Fahrzeug * Auto_1 = new PKW("Auto_1", 100.0, 10.0);
	Fahrzeug * Auto_2 = new PKW("Auto_2", 200.0, 2.0);
	Fahrzeug * Fahrrad_1 = new Fahrrad(" Fahrrad_1",30.0);
	cout << "Fahrzeuge und Strassen erstellt" << endl;
	
	Way_1->vAnnahme(Auto_1,3.0);
	Way_2->vAnnahme(Auto_2);
	Way_2->vAnnahme(Fahrrad_1);
	

	for (dGlobaleZeit = 0; dGlobaleZeit <= 7.0; dGlobaleZeit += 0.2)
	{
		
		vSetzeZeit(dGlobaleZeit);
		vUeberschrift();
		Way_1->vAbfertigung();
		Way_2->vAbfertigung();
	

		vSleep(800);
		
	}


}
*/
/*
void vAufgabe_7()
{
	vGrafikOberflaeche();
	Weg *Way_1 = new Weg("Way_1", 500.0);
	Weg *Way_2 = new Weg("Way_2", 500.0, Landstraﬂe);

	Fahrzeug * Auto_1 = new PKW("Auto_1", 100.0, 10.0);
	Fahrzeug * Auto_2 = new PKW("Auto_2", 150.0, 2.0);
	Fahrzeug * Fahrrad_1 = new Fahrrad(" Fahrrad_1", 100.0);
	cout << "Fahrzeuge und Strassen erstellt" << endl;
    Way_1->vAnnahme(Auto_2,1.0);
	Way_1->vAnnahme(Auto_1);
	
	Way_1->vAnnahme(Fahrrad_1);


	for (dGlobaleZeit = 0; dGlobaleZeit <= 6.2; dGlobaleZeit += 0.2)
	{

		vSetzeZeit(dGlobaleZeit);
		vUeberschrift();
		Way_1->vAbfertigung();
		//Way_2->vAbfertigung();


		vSleep(1500);

	}







}
*/
void vAufgabe_8(){
//Lege alle Strassen und Kreuzungen an.
int strasse1[4] = { 680, 300, 680, 40 };
int strasse2[12] = { 680, 570, 850, 570, 970, 500, 970, 390, 850, 300, 680, 300 };
int strasse3[4] = { 680, 570, 680, 300 };
int strasse4[4] = { 320, 300, 680, 300 };
int strasse5[10] = { 320, 300, 320, 420, 350, 510, 500, 570, 680, 570 };
int strasse6[14] = { 320, 300, 170, 300, 70, 250, 80, 90, 200, 60, 320, 150, 320, 300 };

bInitialisiereGrafik(1000, 650);

bZeichneStrasse("Str1_W12", "Str1_W21", 40, 2, strasse1);
bZeichneStrasse("Str2_W23a", "Str2_W32a", 115, 6, strasse2);
bZeichneStrasse("Str3_W23b", "Str3_W32b", 40, 2, strasse3);
bZeichneStrasse("Str4_W24", "Str4_W42", 55, 2, strasse4);
bZeichneStrasse("Str5_W34", "Str5_W43", 85, 5, strasse5);
bZeichneStrasse("Str6_W44a", "Str6_W44b", 130, 7, strasse6);

Kreuzung * kreuzung1 = new Kreuzung("Kreuzung-1", 1000);
Kreuzung * kreuzung2 = new Kreuzung("Kreuzung-2");
Kreuzung * kreuzung3 = new Kreuzung("Kreuzung-3");
Kreuzung * kreuzung4 = new Kreuzung("Kreuzung-4");

//Kreuzung1
bZeichneKreuzung(680, 40);
kreuzung1->vVerbinde("Str1_W12", "Str1_W21", 40, kreuzung2);

//Kreuzung2
bZeichneKreuzung(680, 300);
kreuzung2->vVerbinde("Str2_W23a", "Str2_W32a", 115, kreuzung3);
kreuzung2->vVerbinde("Str3_W23b", "Str3_W32b", 40, kreuzung3);
kreuzung2->vVerbinde("Str4_W24", "Str4_W42", 55, kreuzung4);

//Kreuzung3
bZeichneKreuzung(680, 570);
kreuzung3->vVerbinde("Str5_W34", "Str5_W43", 85, kreuzung4);

//Kreuzung4
bZeichneKreuzung(320, 300);
kreuzung4->vVerbinde("Str6_W44a", "Str6_W44b", 130, kreuzung4);

Fahrzeug* pkw = new PKW("Auto_1", 120, 80, 10);
Fahrzeug* pkw2 = new PKW("Auto_2", 140, 80, 10);
Fahrzeug* fahrrad = new Fahrrad("Rad", 30);
kreuzung1->vAnnahme(pkw, 0.5);
kreuzung1->vAnnahme(pkw2, 0.75);
kreuzung1->vAnnahme(fahrrad, 0);



for (dGlobaleZeit = 0; dGlobaleZeit <= 10; dGlobaleZeit += (1.0 / 60.0))
{
	vSetzeZeit(dGlobaleZeit);
	kreuzung1->vAbfertigung();
	kreuzung2->vAbfertigung();
	kreuzung3->vAbfertigung();
	kreuzung4->vAbfertigung();
	
	//Sleep(300);
}


vBeendeGrafik();

}






	void vAufgabe_9()
	{
		cout << "Aufgabe 9" << endl;
		try
		{
			Welt *erde = new Welt();

			erde->vEinlesenMitGrafik();

			cout << endl << "---------------------------------------------------" << endl;

			
				resetiosflags(ios::right);
				setiosflags(ios::right);
				cout << endl << " "
					<< "ID" << "    "
					<< resetiosflags(ios::right) << setiosflags(ios::left)
					<< setw(15) << "Name" << "  "
					<< setw(12) << "Tankstelle" << "  "
					<< setw(10) << "Wege" << endl;
				cout << "----------------------------------------"
					<< "----------------------------------------";
				cout << endl;
			
			for (dGlobaleZeit = 0; dGlobaleZeit<10; dGlobaleZeit += (3.0 / 60.0))
			{
				vSetzeZeit(dGlobaleZeit);

				erde->vSimulation();
			}
		}


		catch (string * Fehlermeldung)
		{
			cout << *Fehlermeldung;
		}


		catch (string Fehlermeldung)
		{
			cout << Fehlermeldung;
		}
	}


int main()
{
	//vGrafikOberflaeche(); //2Straﬂen

	vAufgabe_9();

	int s = 0;
	cin >> s;
	return 0;

}

