#include "AktivesVO.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <map>

using namespace std;
static int p_iMaxID = 1;


map<string, AktivesVO*> AktivesVO::VOmap;

AktivesVO::AktivesVO(void)
{
	vInitialisierung();
}

AktivesVO::AktivesVO(const string sName)
{
	vInitialisierung();
	p_sName = sName;
	
	if (VOmap.find(p_sName) == VOmap.end())
	{
		VOmap[p_sName] = this;
	}
	else
	{
		if (p_sName != "")
		{
			throw new string("Objekt mit " + p_sName + " existiert bereits.");
		}
	}
}


AktivesVO::~AktivesVO()
{
}

void AktivesVO::vAbfertigung() //rein virtuelle Methode
{
	
}

ostream & AktivesVO::ostreamAusgabe(ostream & output)
{

	cout << setfill(' '); 
	output << setfill(' ');
	output << left << setw(8) << setfill(' ') << p_iID;
	output << left << setw(8) << setfill(' ') << p_sName;
	output << left << setw(3) << setfill(' ') << ":";
	output << fixed;
	return output;
}

istream& AktivesVO::istreamEingabe(istream& input)
{
	if (p_sName == "")
	{
		input >> p_sName;

		if (VOmap.find(p_sName) == VOmap.end())
		{
			VOmap[p_sName] = this;
		}
		else
		{
			throw new string("Objekt " + p_sName + " existiert schon");
		}
	}
	else throw new string("Das Objekt heißt bereits: " + p_sName);
	return input;
}

string AktivesVO::sGetName()
{
	return p_sName;
}

//Überladen des Ausgabe-Operators "<<"
ostream& operator <<(ostream& output, AktivesVO& aktVo)
{
	aktVo.ostreamAusgabe(output);
	return output;
}


istream& operator >>(istream& input, AktivesVO& aktVo)
{
	aktVo.istreamEingabe(input);
	return input;
}


void AktivesVO::vInitialisierung()
{

	p_sName = "";
	p_dZeit = 0;
	p_iID = p_iMaxID;
	p_iMaxID++;

}


AktivesVO* AktivesVO::ptObjekt(string sName)
{
	if (VOmap.find(sName) == VOmap.end())
	{
		throw new string("Objekt mit " + sName + " existiert nicht!");
	}
	else
	{
		//cout << "Objekt Gefunden!";
		return VOmap.find(sName)->second;
	}
}