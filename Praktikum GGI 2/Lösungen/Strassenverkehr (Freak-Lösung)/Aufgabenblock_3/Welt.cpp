#include "Welt.h"
#include "Kreuzung.h"
#include "Weg.h"
#include "PKW.h"
#include "Fahrrad.h"
#include "SimuClient.h"
#include <string>
#include <istream>
#include <list>

using namespace std;

// Konstruktor:
Welt::Welt(void)
{
}

// Destruktor:
Welt::~Welt(void)
{
}

// Einlesen der Daten aus Stream:
void Welt::vEinlesen(istream& istreamStream)
{
	string keyword = "";

	while(!istreamStream.eof())
	{
		istreamStream >> keyword;
	
		if(keyword == "KREUZUNG")
		{
			Kreuzung *kr = new Kreuzung();
			istreamStream >> *kr;

			p_pKreuzungen.push_back(kr);
		}
		else if(keyword == "STRASSE")
		{
			string sNameQ, sNameZ, sNameW1, sNameW2;
			int iLaenge, iLimit, iUeberholverbot;

			istreamStream >> sNameQ >> sNameZ >> sNameW1 >> sNameW2 >> iLaenge >> iLimit >> iUeberholverbot;

			// Suche Kreuzungen:
			Kreuzung *kr1 = dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sNameQ));
			Kreuzung *kr2 = dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sNameZ));
			
			if(kr1 == NULL) throw new string("Bezeichnung <<" + sNameQ + ">> ist keine Kreuzung.");
			if(kr2 == NULL) throw new string("Bezeichnung <<" + sNameZ + ">> ist keine Kreuzung.");


			bool bUeberholverbot = (iUeberholverbot == 1) ? true : false;

			kr1->vVerbinde(sNameW1, sNameW2, iLaenge, kr2, (Begrenzung)(iLimit - 1), bUeberholverbot); 
		}
		else if(keyword == "PKW")
		{
			string sNameKr;
			double dStartzeitpunkt;

			PKW *p = new PKW();

			istreamStream >> *p >> sNameKr >> dStartzeitpunkt;

			Kreuzung *kr = dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sNameKr));

			if(kr == NULL) throw new string("Bezeichnung <<" + sNameKr + ">> ist keine Kreuzung.");

			kr->vAnnahme(p, dStartzeitpunkt);
		}
		else if(keyword == "FAHRRAD")
		{
			string sNameKr;
			double dStartzeitpunkt;

			Fahrrad *f = new Fahrrad();

			istreamStream >> *f >> sNameKr >> dStartzeitpunkt;

			Kreuzung *kr = dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sNameKr));

			if(kr == NULL) throw new string("Bezeichnung <<" + sNameKr + ">> ist keine Kreuzung.");

			kr->vAnnahme(f, dStartzeitpunkt);
		}
		else
		{
			throw new string("Schluesselwort nicht erkannt: " + keyword);
		}
	}
	
}

// Einlesen der Daten aus Stream, mit Grafik:
void Welt::vEinlesenMitGrafik(istream& istreamStream)
{
	string keyword = "";

	while(!istreamStream.eof())
	{
		istreamStream >> keyword;
	
		if(keyword == "KREUZUNG")
		{
			int iX, iY;
			Kreuzung *kr = new Kreuzung();
			istreamStream >> *kr >> iX >> iY;

			p_pKreuzungen.push_back(kr);

			bZeichneKreuzung(iX, iY);
		}
		else if(keyword == "STRASSE")
		{
			string sNameQ, sNameZ, sNameW1, sNameW2;
			int iLaenge, iLimit, iUeberholverbot, iAnzWegpunkte;

			istreamStream >> sNameQ >> sNameZ >> sNameW1 >> sNameW2 >> iLaenge >> iLimit >> iUeberholverbot >> iAnzWegpunkte;

			int iWegpunkte[100];

			for(int i = 0; i < 2 * iAnzWegpunkte; i++)
			{
				istreamStream >> iWegpunkte[i];
			}

			bZeichneStrasse(sNameW1, sNameW2, iLaenge, iAnzWegpunkte, iWegpunkte);

			// Suche Kreuzungen:
			Kreuzung *kr1 = dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sNameQ));
			Kreuzung *kr2 = dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sNameZ));
			
			if(kr1 == NULL) throw new string("Bezeichnung <<" + sNameQ + ">> ist keine Kreuzung.");
			if(kr2 == NULL) throw new string("Bezeichnung <<" + sNameZ + ">> ist keine Kreuzung.");


			bool bUeberholverbot = (iUeberholverbot == 1) ? true : false;

			Begrenzung enumLimit;

			switch(iLimit)
			{
				case 1:
					enumLimit = Innerorts;
					break;
				case 2:
					enumLimit = Landstrasse;
					break;
				case 3:
					enumLimit = Autobahn;
					break;
				default:
					enumLimit = Autobahn;
					break;
			}


			kr1->vVerbinde(sNameW1, sNameW2, iLaenge, kr2, enumLimit, bUeberholverbot);
		}
		else if(keyword == "PKW")
		{
			string sNameKr;
			double dStartzeitpunkt;

			PKW *p = new PKW();

			istreamStream >> *p >> sNameKr >> dStartzeitpunkt;

			Kreuzung *kr = dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sNameKr));

			if(kr == NULL) throw new string("Bezeichnung <<" + sNameKr + ">> ist keine Kreuzung.");

			kr->vAnnahme(p, dStartzeitpunkt);
		}
		else if(keyword == "FAHRRAD")
		{
			string sNameKr;
			double dStartzeitpunkt;

			Fahrrad *f = new Fahrrad();

			istreamStream >> *f >> sNameKr >> dStartzeitpunkt;

			Kreuzung *kr = dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sNameKr));

			if(kr == NULL) throw new string("Bezeichnung <<" + sNameKr + ">> ist keine Kreuzung.");

			kr->vAnnahme(f, dStartzeitpunkt);
		}
		else
		{
			throw new string("Schluesselwort nicht erkannt: " + keyword);
		}
	}
	
}

// Simulation:
void Welt::vSimulation()
{
	// Starte die Abfertigung für alle Kreuzungen:
	for(list<Kreuzung*>::iterator it = p_pKreuzungen.begin(); it != p_pKreuzungen.end(); it++)
	{
		(*it)->vAbfertigung();
	}
}