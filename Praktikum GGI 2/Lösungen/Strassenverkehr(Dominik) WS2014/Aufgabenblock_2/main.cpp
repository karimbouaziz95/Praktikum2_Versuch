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
void vAufgabe_4()
{
	int iAnzahlPKW = 0, iAnzahlFahrrad = 0;

	cout << "Geben Sie die Anzahl der PKW´s an(mindestens 2): ";
	cin >> iAnzahlPKW;

	cout << "Geben Sie die Anzahl der Fahrraeder an(mindestens 2): ";
	cin >> iAnzahlFahrrad;

	
	Weg Weg1("Way One", 100.0);
	cout << Weg1;

	vector <PKW*> Autos;
	vector <Fahrrad*> Fahrraeder;
	
	for (int j = 0; j < iAnzahlPKW; j++)
	{

		string name = "Auto_"+to_string(j);
		Autos.push_back(new PKW(name, 100 + j * 10, 40.0, 55.0));
	}
	
	for (int i = 0; i < iAnzahlFahrrad; i++)
	{

		string name = "Rad_" + to_string(i);
		Fahrraeder.push_back(new Fahrrad(name, 20 + i * 10));
	}


	vUeberschrift();
	for (dGlobaleZeit = 0.0; dGlobaleZeit < 4; dGlobaleZeit += (1.0 / 6.0))
	{
		//Ausgabe Zeit
		cout << "Globalzeit: " << dGlobaleZeit << endl;

		//Abfertigung Autos
		for (int i = 0; i < iAnzahlPKW; i++)
		{
			Autos[i]->vAbfertigung();
			cout << *Autos[i] << endl;

		}


		//Abfertigung Fahrraeder
		for (int j = 0; j < iAnzahlFahrrad; j++)
		{

			Fahrraeder[j]->vAbfertigung();
			cout << *Fahrraeder[j] << endl;
		}

		//Volltanken nach 3 Stunden
		if (fabs(dGlobaleZeit - 3.0) < 0.01)
		{
			//Tanken

			for (int i = 0; i < iAnzahlPKW; i++)
			{
				Autos[i]->dTanken();
			}
		}


	}//Zeitschleife
	if (Autos.size()>2){
		if (Autos[0] < Autos[1])
		{
			cout << "Auto 1 ist weniger gefahren";
		}
		else if (Autos[2] < Autos[1])
		{
			cout << "Auto 2 ist weniger gefahren";
		}
		else
		{
			cout << "Beide Autos sind gleichweit gefahren";
		}
	}
}
void vAufgabe_4_7()
{

	Weg *Way_1 = new Weg("Way_1", 100.0);

	Fahrzeug * Auto_1 = new PKW("Auto_1",25.0,120.0);
	Fahrzeug * Auto_2 = new PKW("Auto_2",25.0,100.0);

	Auto_1->vNeueStrecke(Way_1);
	Auto_2->vNeueStrecke(Way_1);

	Way_1->vAbfertigung();
	cout << *Way_1;




}
void vAufgabe_4_9()
{



 Weg *Way_1 = new Weg("Way_1", 100.0);

 Fahrzeug * Auto_1 = new PKW("Auto_1",50.0, 2.0);
 Fahrzeug * Auto_2 = new PKW("Auto_2", 25.0, 2.0);

 Auto_1->vNeueStrecke(Way_1,0.4);
 Auto_2->vNeueStrecke(Way_1);

 
 for (dGlobaleZeit = 0; dGlobaleZeit < 3.0; dGlobaleZeit += 0.2)
 {
	 Way_1->vAbfertigung();
	 cout << *Way_1;
	 cout << *Auto_1  << *Auto_2<<endl;
 }


}
void vAufgabe_5()
{
vGrafikOberflaeche();

Weg *Way_1 = new Weg("Way_1", 500.0);
Weg *Way_2 = new Weg("Way_2", 500.0,Landstraße);

Fahrzeug * Auto_1 = new PKW("Auto_1", 100.0, 8.0);
Fahrzeug * Auto_2 = new PKW("Auto_2", 25.0, 5.0);
cout << "Fahrzeuge und Straßen erstellt"<<endl;
//Auto_1->vNeueStrecke(Way_1);
cout << "Auto_1 auf Weg_1" << endl;
//Auto_2->vNeueStrecke(Way_2);
Way_1->vAnnahme(Auto_1,1.0);
Way_2->vAnnahme(Auto_2);
//Auto_2->vZeichnen(Way_1);

for (dGlobaleZeit = 0; dGlobaleZeit < 7.0; dGlobaleZeit += 0.2)
{
	Auto_1->vZeichnen(Way_1);
	vSetzeZeit(dGlobaleZeit); 
	cout << "abfertigungsschleife" << endl;
	Way_1->vAbfertigung();
	//Way_2->vAbfertigung();
	
	vSleep(3000);
	cout << *Way_1;
 cout << *Auto_1 << endl;
}


}
void vAufgabe_6()
{
	vGrafikOberflaeche();
	Weg *Way_1 = new Weg("Way_1", 500.0);
	Weg *Way_2 = new Weg("Way_2", 500.0, Landstraße);

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
void vAufgabe_6a()
{
	
//	srand(time(0)); //geseedete Zuffalsfolge

	LazyListe <int> rndList;		//Neue Liste für das verzögerte Update
	LazyListe <int>::iterator It; //Iterator

	for (int i = 0; i < 15; i++)
	{
		rndList.push_back(rand() % 10 + 1); //Random Integer in der Liste einfügen
	}

	rndList.vAktualisieren(); //Liste updaten






	for (It = rndList.begin(); It != rndList.end(); It++)
		cout << (*It) << "   "; 
	cout << endl;

	for (It = rndList.begin(); It != rndList.end(); It++)
		if ((*It)>5) //Alle Werte >5 löschen
			rndList.erase(It);

	for (It = rndList.begin(); It != rndList.end(); It++)
		cout << (*It) << "   "; //nochmal ausgeben
	cout << endl;

	rndList.vAktualisieren(); //Löschen

	for (It = rndList.begin(); It != rndList.end(); It++)
		cout << (*It) << "   "; //ausgeben
	cout << endl;

	
	rndList.push_back(3);
	rndList.push_front(5);
	rndList.vAktualisieren();

	for (It = rndList.begin(); It != rndList.end(); It++)
		cout << (*It) << "   "; //ausgeben
	cout << endl;



}

int main()
{
	//vGrafikOberflaeche(); //2Straßen

	vAufgabe_6();

	int s = 0;
	cin >> s;
	return 0;

}

