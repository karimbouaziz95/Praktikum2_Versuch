#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>



using namespace std;

#include "Welt.h"
#include "AktivesVO.h"
#include "Kreuzung.h"
#include "Fahrrad.h"
#include "Fahrzeug.h"
#include "PKW.h"
#include "Weg.h"
#include "LazyListe.h"
#include "SimuClient.h"

Welt::Welt(void)
{
}


void Welt::vEinlesen()
{
	char temp[100];
	cout << endl << "Gib Dateinamen ein: ";
	cin >> temp;

	ifstream infile("Simu.dat");
	//falls Datei nicht existiert, werfe exception
	if (!infile.good())
	{
		throw new string("Datei existiert nicht!");
	}
	//Datei auslesen, solange bis eof erreicht ist

	while (!infile.eof())
	{
		string schluessel;

		infile >> schluessel;

		if (schluessel == "KREUZUNG")
		{
			// neue Kreuzung erstellen, Werte einlesen und zur Liste hinzufuegen
			Kreuzung * pt_VO = new Kreuzung();
			infile >> *pt_VO;
			p_ptKreuzungen.push_back((Kreuzung*)pt_VO);
			cout << *pt_VO;
		}
		else if (schluessel == "STRASSE")
		{
			string sKreuzungA;
			string sKreuzungZ;
			string sWeg1;
			string sWeg2;

			int iLaenge;

			//Alle Daten aus Eingabe auslesen, besonders bei Eckpunkte Anzahl beachten
			infile >> sKreuzungA >> sKreuzungZ >> sWeg1 >> sWeg2 >> iLaenge;

			//Passende Pointer finden, zu Strassen und Kreuzungen
			Kreuzung * kreuz1 = (Kreuzung*)AktivesVO::ptObjekt(sKreuzungA);
			Kreuzung * kreuz2 = (Kreuzung*)AktivesVO::ptObjekt(sKreuzungZ);

			kreuz1->vVerbinde(sWeg1, sWeg2, iLaenge, kreuz2);

		}
		else if (schluessel == "PKW")
		{
			//Temporaere Variablen fuers Einlesen
			string sKreuzung;
			double dStartzeit;
			// neuen PKW ertellen, Werte einlesen und auf Strasse setzen
			PKW * pt_VO = new PKW("");

			infile >> *pt_VO;
			infile >> sKreuzung;
			infile >> dStartzeit;

			//Brauche Pointer von Kreuzung, also neue Fkt benutzen
			Kreuzung * kreuz = (Kreuzung*)AktivesVO::ptObjekt(sKreuzung);
			//Fahrzeug auf Kreuzung setzen
			kreuz->vAnnahme((Fahrzeug*)pt_VO, dStartzeit);

			cout << *pt_VO;
		}
		else if (schluessel == "FAHRRAD")
		{
			//Temporaere Variablen fuers Einlesen
			string sKreuzung;
			double dStartzeit;
			// neuen PKW ertellen, Werte einlesen und auf Strasse setzen
			Fahrrad * pt_VO = new Fahrrad("");

			infile >> *pt_VO;
			infile >> sKreuzung;
			infile >> dStartzeit;

			//Brauche Pointer von Kreuzung, also neue Fkt benutzen
			Kreuzung * kreuz = (Kreuzung*)AktivesVO::ptObjekt(sKreuzung);
			//Fahrzeug auf Kreuzung setzen
			kreuz->vAnnahme((Fahrzeug*)pt_VO, dStartzeit);

			cout << *pt_VO;
		}
		else if (schluessel != "")
		{
			cout << schluessel;
			throw new string("Schluessel existiert nicht.");
		}

	}

}


void Welt::vSimulation()
{
	list<Kreuzung*>::iterator Lpointer;

	for (Lpointer = p_ptKreuzungen.begin(); Lpointer != p_ptKreuzungen.end(); ++Lpointer)
	{
		(*Lpointer)->vAbfertigung();
	}
}

void Welt::vEinlesenMitGrafik()
{
	bInitialisiereGrafik(1200, 1200);

	ifstream infile("SimuDisplay.dat");
	
	if (!infile.good())
	{
		throw new string("Datei existiert nicht!");
	}
	

	while (!infile.eof())
	{
		string schluessel = "";
		infile >> schluessel;

		if (schluessel == "KREUZUNG")
		{
			
			Kreuzung * pt_VO = new Kreuzung("");
			int xKoord;
			int yKoord;
			infile >> *pt_VO;
			infile >> xKoord >> yKoord;
			bZeichneKreuzung(xKoord, yKoord);
			p_ptKreuzungen.push_back((Kreuzung*)pt_VO);

			cout <<"pt"<< *pt_VO;
			cout << xKoord << "  " << yKoord << endl;
		}
		else if (schluessel == "STRASSE")
		{
			string sKreuzungA;
			string sKreuzungZ;
			string sWeg1;
			string sWeg2;

			double dLaenge;
			int iAnzahl;

			//Alle Daten aus Eingabe auslesen, besonders bei Eckpunkte Anzahl beachten
			infile >> sKreuzungA >> sKreuzungZ >> sWeg1 >> sWeg2 >> dLaenge >> iAnzahl;

			cout << sKreuzungA << " " << sKreuzungZ
				<< " " << sWeg1
				<< " " << sWeg2
				<< " " << dLaenge
				<< " " << iAnzahl;

			int Koordinaten[40];
			for (int i = 0; i<2 * iAnzahl; ++i)
			{
				infile >> Koordinaten[i];
				cout << " " << Koordinaten[i];

			}


			bZeichneStrasse(sWeg1, sWeg2, (int)dLaenge, iAnzahl, Koordinaten);

			//Passende Pointer finden, zu Strassen und Kreuzungen
			Kreuzung * kreuz1 = (Kreuzung*)AktivesVO::ptObjekt(sKreuzungA);
			Kreuzung * kreuz2 = (Kreuzung*)AktivesVO::ptObjekt(sKreuzungZ);


			kreuz1->vVerbinde(sWeg1, sWeg2, (int)dLaenge, kreuz2);
		}


		else if (schluessel == "PKW")


		{
			//Temporaere Variablen fuers Einlesen
			string sKreuzung;
			double dStartzeit;
			// neuen PKW ertellen, Werte einlesen und auf Strasse setzen
			PKW * pt_VO = new PKW("");

			infile >> *pt_VO;
			infile >> sKreuzung;
			infile >> dStartzeit;

			//Brauche Pointer von Kreuzung, also neue Fkt benutzen
			Kreuzung * kreuz = (Kreuzung*)AktivesVO::ptObjekt(sKreuzung);
			//Fahrzeug auf Kreuzung setzen
			kreuz->vAnnahme((Fahrzeug*)pt_VO, dStartzeit);
		}
		else if (schluessel == "FAHRRAD")
		{
			


			string sKreuzung;
			double dStartzeit;
			

			Fahrrad * pt_VO = new Fahrrad("");

			infile >> *pt_VO;
			infile >> sKreuzung;
			infile >> dStartzeit;

			

			Kreuzung * kreuz = (Kreuzung*)AktivesVO::ptObjekt(sKreuzung);
			

			kreuz->vAnnahme((Fahrzeug*)pt_VO, dStartzeit);
		}
		else if (schluessel != "")
		{
			throw new string("Schluessel " + schluessel + " existiert nicht.");
		}
	}

}