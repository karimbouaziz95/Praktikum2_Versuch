#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include "MyClass.h"
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrrad.h"



using namespace std;
double dGlobaleZeit = 0.0;
//double dMaxSpeed = 50.0

void vUeberschrift(){
	
	cout << setiosflags(ios::left) << setw(5) << "ID" << setw(10) << "Name" << setw(5) << ":" <<setw(9)<<"Kmh"
		 << setw(20) << "GesamtStrecke" << setw(10) << "Tankinhalt" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
}
void vAufgabe_1()
{

//	Fahrzeug Auto_1;
	//Fahrzeug Auto_2;
	Fahrzeug Auto_3("Auto_3",50.0);
	Fahrzeug Auto_4("Auto_4",70.0);
	/*
	Fahrzeug *pAuto_5 = new Fahrzeug();
	Fahrzeug *pAuto_6 = new Fahrzeug();
	Fahrzeug *pAuto_7 = new Fahrzeug("Auto7");
	Fahrzeug *pAuto_8 = new Fahrzeug("Auto8");
	*/
	for (dGlobaleZeit=0.0;dGlobaleZeit < 20 ;dGlobaleZeit+= (0.5) )
	{

		Auto_3.vAbfertigung();
		Auto_4.vAbfertigung();
	
		Auto_3.vAusgabe();
		Auto_4.vAusgabe();

	}
	

	/*
	delete	pAuto_8;
	delete	pAuto_7;
	delete	pAuto_6;
	delete	pAuto_5;
	*/
}
void vAufgabe_1_deb()
{
	Fahrzeug *Autos[4];
	Autos[0] = new Fahrzeug("Auto  0");
	Autos[1] = new Fahrzeug("Auto  1");
	Autos[2] = new Fahrzeug("Auto  2");
	Autos[3] = new Fahrzeug("Auto  3");
	Autos[2] = 0;
	for (int i = 0; i <= 3; i++)
	{
		Autos[i]->vAusgabe();
	}
}
void vAufgabe_2()
{
	int iAnzahlPKW = 0, iAnzahlFahrrad=0;

	cout << "Geben Sie die Anzahl der PKW´s an: ";
	cin >> iAnzahlPKW;

	cout << "Geben Sie die Anzahl der Fahrraeder an: ";
	cin >> iAnzahlFahrrad ;

	vector <Fahrzeug*> Autos;
	vector <Fahrzeug*> Fahrraeder;

	for (int j = 0; j < iAnzahlPKW; j++)
	{

		string name = "Auto_" ;
		Autos.push_back(new PKW(name, 120 + j * 2, 40.0, 55.0));
	}

	for (int i=0; i < iAnzahlFahrrad; i++)
	{

		string name = "Rad_";
		Fahrraeder.push_back(new Fahrrad(name, 100+ i* 2));
	}


	vUeberschrift();

	//Abfertigung und Ausgabe
	for (dGlobaleZeit = 0.0; dGlobaleZeit < 4; dGlobaleZeit+=(1.0/6.0))
	{
		//Ausgabe Zeit
		cout << dGlobaleZeit << endl;

		//Abfertigung Autos
		for (int i =0;i < iAnzahlPKW; i++)
		{
			Autos[i]->vAbfertigung();
			Autos[i]->vAusgabe();
			
		}


		//Abfertigung Fahrraeder
		for (int j = 0; j < iAnzahlFahrrad;j++)
		{

			Fahrraeder[j]->vAbfertigung();
			Fahrraeder[j]->vAusgabe();
		}

		//Volltanken nach 3 Stunden
		if (fabs(dGlobaleZeit-3.0)<0.01)
		{
			//Tanken
			
			for (int i = 0; i < iAnzahlPKW; i++)
			{
				Autos[i]->dTanken();
				

			}


		}
		

	}//Zeitschleife



	//cout << (Autos[1] < Autos[0]);




}
void vAufgabe_3()
{
	int iAnzahlPKW = 0, iAnzahlFahrrad = 0;

	cout << "Geben Sie die Anzahl der PKW´s an: ";
	cin >> iAnzahlPKW;

	cout << "Geben Sie die Anzahl der Fahrraeder an: ";
	cin >> iAnzahlFahrrad;

	vector <PKW*> Autos;
	vector <Fahrrad*> Fahrraeder;
	
	for (int j = 0; j < iAnzahlPKW; j++)
	{

		string name = "Auto_" + to_string(j);
		Autos.push_back(new PKW(name, 100 + j * 10, 40.0, 55.0));
	}

	if (Autos.size() >1){
		*Autos[1] = *Autos[0];
	}
	for (int i = 0; i < iAnzahlFahrrad; i++)
	{

		string name = "Rad_"+to_string(i);
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
			cout << *Autos[i]<<endl;

		}


		//Abfertigung Fahrraeder
		for (int j = 0; j < iAnzahlFahrrad; j++)
		{

			Fahrraeder[j]->vAbfertigung();
			cout << *Fahrraeder[j]<<endl;
		}

		//Volltanken nach 3 Stunden
		if (fabs(dGlobaleZeit - 3.0)<0.01)
		{
			//Tanken

			for (int i = 0; i < iAnzahlPKW; i++)
			{
				Autos[i]->dTanken();


			}


		}


	}//Zeitschleife

	if(Autos.size() >2 ){
		if (Autos[1] < Autos[2])
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
int main()
{
	

	//Fahrzeug Auto("Test");
	//vAufgabe_1();
	
	//Fahrzeug Auto_3("Auto_3");
	//Fahrzeug Auto_4("Auto_4");
	/*
	vUeberschrift();
	Auto_3.vAusgabe();
	Auto_4.vAusgabe();
	*/
	//vAufgabe_1();
	//vAufgabe_1_deb();
	//vAufgabe_2();
	vAufgabe_3();
//	Fahrzeug *pAuto_1 = new PKW("Auto_1",120.0,20.0);
//	Fahrzeug *pAuto_2 = new PKW("Auto_1", 240.0, 20.0);
	//Fahrzeug *pRad_1 = new Fahrrad("Fahrrad_1",20.0);
//	pAuto_1->vAbfertigung();
//	pAuto_2->vAbfertigung();
	// cout << (*pAuto_1 < *pAuto_2);
	//vUeberschrift();
	//cout << *pAuto_1;
	int s = 0;
	cin >> s;
	return 0;

}

