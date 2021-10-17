#include "Welt.h"
#include <string>
#include "Fahrrad.h"
#include "PKW.h"
#include "AktivesVO.h"
#include "Kreuzung.h"
#include "Weg.h"
#include "SimuClient.h"

using namespace std;

Welt::Welt(void)
{
}

Welt::~Welt(void)
{
	for(list<Kreuzung*>::iterator i = p_lKreuzung.begin(); i != p_lKreuzung.end(); i++)
	{
		delete *i;
	}
	p_lKreuzung.clear();
}

void Welt::vEinlesen(ifstream& Stream)
{
	while(!Stream.eof()) 
	{
		string key;
		Stream >> key;

		if(key == "KREUZUNG") 
		{
			Kreuzung* pKR = new Kreuzung();
			Stream >> *pKR;

			p_lKreuzung.push_back(pKR);
		}

		

		else if(key == "PKW") 
		{
			PKW* PKW1 = new PKW();
			string sStartKr;
			double dStartzeit;

			Stream >> *PKW1 >> sStartKr >> dStartzeit;

			static_cast<Kreuzung*>(AktivesVO::ptObjekt(sStartKr))->vAnnahme(PKW1, dStartzeit);
		}

		else if(key == "FAHRRAD") {
			Fahrrad* Fahrrad1 = new Fahrrad();
			string sStartKr;

			double dStartzeit;

			Stream >> *Fahrrad1 >> sStartKr >> dStartzeit;

			static_cast<Kreuzung*>(AktivesVO::ptObjekt(sStartKr))->vAnnahme(Fahrrad1, dStartzeit);
		}

		else if(key == "STRASSE") 
		{
			string sQuellKr, sZielKr, sNameHin, sNameRueck;
			double dLaenge;
			int iLimit, iUeberholverbot;
			bool bUeberholverbot;
			Begrenzung eLimit;

			Stream >> sQuellKr >> sZielKr >> sNameHin >> sNameRueck >> dLaenge >> iLimit >> iUeberholverbot;

			switch(iLimit) 
			{
				case 1:
					eLimit = Innerorts;
					break;
				case 2:
					eLimit = Landstrasse;
					break;
				case 3:
					eLimit = Autobahn;
					break;
				default:
					throw string("Error: Geschwindigkeitsbegrenzung konnte nicht eingelesen werden: Straﬂe: " + sNameHin + "\n");
			}

			switch(iUeberholverbot) 
			{
				case 0:
					bUeberholverbot = false;
					break;
				case 1:
					bUeberholverbot = true;
					break;
				default:
					throw string("Error: Ueberholverbot konnte nicht eingelesen werden: Straﬂe :" + sNameHin + "\n");
			}

			if(!dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sZielKr)) || !dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sQuellKr)))
			{
				throw string("Error: Eine Kreuzung ist kein Kreuzung* Objekt!\n");
			}

			dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sQuellKr))->vVerbinde(sNameHin, sNameRueck, dLaenge, dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sZielKr)), eLimit, bUeberholverbot);
		}

		else
		{
			throw string("Error: Falscher Schluessel beim Einlesen: " + key + "\n");
		}
	}

}

void Welt::vEinlesenMitGrafik(ifstream& Stream)
{
	while(!Stream.eof()) 
	{
		string key;
		Stream >> key;

		if(key == "KREUZUNG") 
		{
			Kreuzung* pKR = new Kreuzung();
			double dx, dy;
			Stream >> *pKR >> dx >> dy;
			bZeichneKreuzung(dx,dy);
			p_lKreuzung.push_back(pKR);
		}

		

		else if(key == "PKW") 
		{
			PKW* PKW1 = new PKW();
			string sStartKr;
			double dStartzeit;

			Stream >> *PKW1 >> sStartKr >> dStartzeit;

			static_cast<Kreuzung*>(AktivesVO::ptObjekt(sStartKr))->vAnnahme(PKW1, dStartzeit);
		}

		else if(key == "FAHRRAD") {
			Fahrrad* Fahrrad1 = new Fahrrad();
			string sStartKr;

			double dStartzeit;

			Stream >> *Fahrrad1 >> sStartKr >> dStartzeit;

			static_cast<Kreuzung*>(AktivesVO::ptObjekt(sStartKr))->vAnnahme(Fahrrad1, dStartzeit);
		}

		else if(key == "STRASSE") 
		{
			string sQuellKr, sZielKr, sNameHin, sNameRueck;
			double dLaenge;
			int iLimit, iUeberholverbot, iPaare;
			bool bUeberholverbot;
			Begrenzung eLimit;

			Stream >> sQuellKr >> sZielKr >> sNameHin >> sNameRueck >> dLaenge >> iLimit >> iUeberholverbot >> iPaare;
			
			int* Array = new int[iPaare*2];
			for (int i=0;i<(iPaare*2);i++)
			{
				Stream >> Array[i];
			}

			switch(iLimit) 
			{
				case 1:
					eLimit = Innerorts;
					break;
				case 2:
					eLimit = Landstrasse;
					break;
				case 3:
					eLimit = Autobahn;
					break;
				default:
					throw string("Error: Geschwindigkeitsbegrenzung konnte nicht eingelesen werden: Straﬂe: " + sNameHin + "\n");
			}

			switch(iUeberholverbot) 
			{
				case 0:
					bUeberholverbot = false;
					break;
				case 1:
					bUeberholverbot = true;
					break;
				default:
					throw string("Error: Ueberholverbot konnte nicht eingelesen werden: Straﬂe :" + sNameHin + "\n");
			}

			if(!dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sZielKr)) || !dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sQuellKr)))
			{
				throw string("Error: Eine Kreuzung ist kein Kreuzung* Objekt!\n");
			}

			dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sQuellKr))->vVerbinde(sNameHin, sNameRueck, dLaenge, dynamic_cast<Kreuzung*>(AktivesVO::ptObjekt(sZielKr)), eLimit, bUeberholverbot);
			
			bZeichneStrasse(sNameHin,sNameRueck,dLaenge,iPaare,Array);
		}

		else
		{
			throw string("Error: Falscher Schluessel beim Einlesen: " + key + "\n");
		}
	}

}

void Welt::vSimulation()
{
	
	for(list<Kreuzung*>::iterator it=p_lKreuzung.begin();it!=p_lKreuzung.end();it++)
	{
		(*it)->vAbfertigung();
		cout << *(*it) << endl;
	}
}	