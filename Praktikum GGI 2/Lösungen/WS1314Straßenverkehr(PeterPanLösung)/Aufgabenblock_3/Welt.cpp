#include "Welt.h"
#include "Kreuzung.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "Weg.h"
#include "SimuClient.h"


#include <fstream>
#include <iostream>
#include <map>
using namespace std;
#include <string>
#include <stdio.h>


Welt::Welt(void)
{
}


Welt::~Welt(void)
{
}

void Welt::vEinlesen()
{
	ifstream infile("SimuK.dat");

	string schluesselwort;

	while (!infile.eof())				//Solange lesen bis das Ende der Datei erreicht ist
	{
		infile >> schluesselwort;

		if (schluesselwort == "KREUZUNG")
		{
			// neue Kreuzung erstellen, Werte einlesen und zur Liste hinzufuegen
			Kreuzung * pt_aktVO = new Kreuzung();
			infile >> *pt_aktVO;

			if(dynamic_cast<Kreuzung*> ((AktivesVO*)AktivesVO::ptObjekt(pt_aktVO->GetName()))!=0)
				{
					p_ptKreuzungen.push_back((Kreuzung*) pt_aktVO);
					//cout << *pt_aktVO;
				}
			else
				{
					throw new string ("quellKreuzung konnte nicht auf Kreuzung gecastet werden!");
				}

			
		}
		else if (schluesselwort == "STRASSE")
			{
				

				string quellKreuzung, zielKreuzung;
				string weg1, weg2;
				int laenge, geschwLimitCode;
				double GeschwLimit;
				int Verbot;
				bool ueberhVerbot;

				//Daten einlesen
				infile >> quellKreuzung >> zielKreuzung >> weg1 >> weg2 >> laenge >> geschwLimitCode >> Verbot;

				if((Verbot!=0) && (Verbot!=1))
				{
					throw new string ("Falscher boolscher Wert fuer Ueberholverbot");
					ueberhVerbot = 1 ;
				}
				else 
				{
					ueberhVerbot = Verbot;
				}
				switch (geschwLimitCode)
				{
					case 1:
						GeschwLimit = 50;
						break;
					case 2:
						GeschwLimit = 100;
						break;
					case 3:
						GeschwLimit = 9999;
						break;
					default:
						throw new string("Fail bei Geschwindigkeitslimit!");
						break;
				}


				if( ( dynamic_cast<Kreuzung*> ((AktivesVO*)AktivesVO::ptObjekt(quellKreuzung))!=0 )  && ( dynamic_cast<Kreuzung*> ((AktivesVO*)AktivesVO::ptObjekt(zielKreuzung))!=0 ) )
				{
					
					//finden von passenden poitern
				Kreuzung * cross1 = (Kreuzung*) AktivesVO::ptObjekt(quellKreuzung);
				Kreuzung * cross2 = (Kreuzung*) AktivesVO::ptObjekt(zielKreuzung);

				cross1->vVerbinde(weg1,weg2,laenge,cross2,GeschwLimit,ueberhVerbot); // Kreuzungen verbinden und (Wege erstellen) 
				
				}
				else
				{
					throw new string (quellKreuzung+ " oder "+ zielKreuzung+" konnte nicht auf Kreuzung gecastet werden!");
				}
			}
				
		else if (schluesselwort == "PKW")
			{
				
				string sKreuzung;
				double dStartzeit;

				PKW * pt_aktVO = new PKW();

				infile >> *pt_aktVO;
				infile >> sKreuzung;
				infile >> dStartzeit;

				if(dynamic_cast<Kreuzung*> ((AktivesVO*)AktivesVO::ptObjekt(sKreuzung))!=0)
				{
			    //pointer von Kreuzung holen
				Kreuzung * kreuz = (Kreuzung*)AktivesVO::ptObjekt(sKreuzung);
				
				kreuz->vAnnahme((Fahrzeug*)pt_aktVO, dStartzeit);

				//cout << *pt_aktVO;
				}
				else
				{
				throw new string ("Kreuzung konnte nicht auf Kreuzung gecastet werden!");
				}
			}
			else if (schluesselwort == "FAHRRAD")
				{
					
					string sKreuzung;
					double dStartzeit;

					
					Fahrrad * pt_aktVO = new Fahrrad();

					infile >> *pt_aktVO;
					infile >> sKreuzung;
					infile >> dStartzeit;

					if(dynamic_cast<Kreuzung*> ((AktivesVO*)AktivesVO::ptObjekt(sKreuzung))!=0)
					{
						
						//pointer von Kreuzung holen
						Kreuzung * kreuz = (Kreuzung*)AktivesVO::ptObjekt(sKreuzung);
					
						kreuz->vAnnahme((Fahrzeug*)pt_aktVO, dStartzeit);

						//cout << *pt_aktVO;
					}
					else
					{
					   throw new string ("Kreuzung konnte nicht auf Kreuzung gecastet werden!");
					}
				}
		else 
		{
			throw new string("Das Schluesselwort: "+schluesselwort+" existiert nicht.");
		}

	}

}

// simulatoin *****************************************************************************
void Welt::vSimulation()
{
	list<Kreuzung*>::iterator Lpointer;

	for(Lpointer = p_ptKreuzungen.begin(); Lpointer != p_ptKreuzungen.end(); ++Lpointer)
	{
		(*Lpointer)->vAbfertigung();
	}
}

//void vEinlesenMitGrafik();///////////////////////////////////////////////////////////////////////////////////////
void Welt::vEinlesenMitGrafik()
{
	bInitialisiereGrafik(1000,1000);

	ifstream infile("SimuDisplay.dat");

	string schluesselwort;

	while (!infile.eof())				//Solange lesen bis das Ende der Datei erreicht ist
	{
		infile >> schluesselwort;

		if (schluesselwort == "KREUZUNG")
		{
			int PosX,PosY;
			// neue Kreuzung erstellen, Werte einlesen und zur Liste hinzufuegen
			Kreuzung * pt_aktVO = new Kreuzung();
			infile >> *pt_aktVO;
			infile >> PosX >> PosY;

			if(dynamic_cast<Kreuzung*> ((AktivesVO*)AktivesVO::ptObjekt(pt_aktVO->GetName()))!=0)
				{
				     p_ptKreuzungen.push_back((Kreuzung*) pt_aktVO);
					 // Kreuzung Zeichnen *******
					 bZeichneKreuzung(PosX,PosY);
					//cout << *pt_aktVO;
				}
			else
				{
					throw new string ("quellKreuzung konnte nicht auf Kreuzung gecastet werden!");
				}

			
		}
		else if (schluesselwort == "STRASSE")
			{
				

				string quellKreuzung, zielKreuzung;
				string weg1, weg2;
				int laenge, geschwLimitCode;
				double GeschwLimit;
				int Verbot;
				bool ueberhVerbot;
				int anzahl;
				int array[30];

				//Daten einlesen
				infile >> quellKreuzung >> zielKreuzung >> weg1 >> weg2 >> laenge >> geschwLimitCode >> Verbot >> anzahl;
				for(int count=0; count < (2*anzahl); ++count)
				{
					infile >> array[count];
				}


				if((Verbot!=0) && (Verbot!=1))
				{
					throw new string ("Falscher boolscher Wert fuer Ueberholverbot");
					ueberhVerbot = 1 ;
				}
				else 
				{
					ueberhVerbot = Verbot;
				}
				switch (geschwLimitCode)
				{
					case 1:
						GeschwLimit = 50;
						break;
					case 2:
						GeschwLimit = 100;
						break;
					case 3:
						GeschwLimit = 9999;
						break;
					default:
						throw new string("Fail bei Geschwindigkeitslimit!");
						break;
				}


				if( ( dynamic_cast<Kreuzung*> ((AktivesVO*)AktivesVO::ptObjekt(quellKreuzung))!=0 )  && ( dynamic_cast<Kreuzung*> ((AktivesVO*)AktivesVO::ptObjekt(zielKreuzung))!=0 ) )
				{
					
					//finden von passenden poitern
				Kreuzung * cross1 = (Kreuzung*) AktivesVO::ptObjekt(quellKreuzung);
				Kreuzung * cross2 = (Kreuzung*) AktivesVO::ptObjekt(zielKreuzung);

				cross1->vVerbinde(weg2,weg1,laenge,cross2,GeschwLimit,ueberhVerbot); // Kreuzungen verbinden und (Wege erstellen) 
				// Straße Zeichnen *******
				bZeichneStrasse(weg1,weg2,laenge,anzahl,array);


				}
				else
				{
					throw new string (quellKreuzung+ " oder "+ zielKreuzung+" konnte nicht auf Kreuzung gecastet werden!");
				}
			}
				
		else if (schluesselwort == "PKW")
			{
				
				string sKreuzung;
				double dStartzeit;

				PKW * pt_aktVO = new PKW();

				infile >> *pt_aktVO;
				infile >> sKreuzung;
				infile >> dStartzeit;

				if(dynamic_cast<Kreuzung*> ((AktivesVO*)AktivesVO::ptObjekt(sKreuzung))!=0)
				{
			    //pointer von Kreuzung holen
				Kreuzung * kreuz = (Kreuzung*)AktivesVO::ptObjekt(sKreuzung);
				
				kreuz->vAnnahme((Fahrzeug*)pt_aktVO, dStartzeit);

				//cout << *pt_aktVO;
				}
				else
				{
				throw new string ("Kreuzung konnte nicht auf Kreuzung gecastet werden!");
				}
			}
			else if (schluesselwort == "FAHRRAD")
				{
					
					string sKreuzung;
					double dStartzeit;

					
					Fahrrad * pt_aktVO = new Fahrrad();

					infile >> *pt_aktVO;
					infile >> sKreuzung;
					infile >> dStartzeit;

					if(dynamic_cast<Kreuzung*> ((AktivesVO*)AktivesVO::ptObjekt(sKreuzung))!=0)
					{
						
						//pointer von Kreuzung holen
						Kreuzung * kreuz = (Kreuzung*)AktivesVO::ptObjekt(sKreuzung);
					
						kreuz->vAnnahme((Fahrzeug*)pt_aktVO, dStartzeit);

						//cout << *pt_aktVO;
					}
					else
					{
					   throw new string ("Kreuzung konnte nicht auf Kreuzung gecastet werden!");
					}
				}
		else 
		{
			throw new string("Das Schluesselwort: "+schluesselwort+" existiert nicht.");
		}

	}

}