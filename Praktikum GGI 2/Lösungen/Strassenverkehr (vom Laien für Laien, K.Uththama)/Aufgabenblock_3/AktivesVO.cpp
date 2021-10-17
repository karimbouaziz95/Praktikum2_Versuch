#include "AktivesVO.h"
#include <string>
#include <iomanip>
#include <iostream>

int AktivesVO::p_iMaxID = 0;

//Konstruktoren
AktivesVO::AktivesVO(void)
{
	vInitialisierung();
}

AktivesVO::AktivesVO(string sName)
{
	vInitialisierung();
	int i = mapVO.count(sName);
	if(mapVO.count(sName) == 0)
	{
		mapVO[sName] = this;
	}
	else 
	{
		string sMeldung = " -----Fehler : Versuch ein Objekt zu Erstellen. Es ist bereits ein Objekt unter dem Namen (" + sName + ") in der Map gespeichert !-----";
		throw sMeldung;
	}
	p_sName = sName;
}

//Destruktor
AktivesVO::~AktivesVO(void)
{
}

//Initialisierungsfunktion
void AktivesVO::vInitialisierung(void)
{
	p_iMaxID++;
    p_sName = "";
    p_iID = p_iMaxID;
    p_dZeit = 0;
}

//spezifische Ausgaben
ostream& AktivesVO::ostreamAusgabe(ostream& output)
{
	output << resetiosflags(ios::right) << setiosflags(ios::left) //jetzt rechtsbündig -> aus Aufgabe 1.5
		   << setiosflags(ios::fixed) << setprecision(2)
		   << setw(5)  << p_iID 
	       << setw(14) << p_sName;
	return output;
}

//Überladen des Ausgabe-Operators "<<"
ostream& operator <<(ostream& output , AktivesVO& Object)
{
	Object.ostreamAusgabe(output);
	return output;
}

//spezifische Eingaben
istream& AktivesVO::istreamEingabe(istream& input)
{
	bool b = p_sName.empty();
	if(p_sName.empty())
	{
		input  >> p_sName;
		if(mapVO.count(p_sName) == 0)
		{
			mapVO[p_sName] = this;
		}
		else 
		{
			string sMeldung = " -----Fehler : Versuch ein Objekt zu sepzifizieren. Es ist bereits ein Objekt unter dem Namen (" + p_sName + ") gespeichert !-----";
			throw sMeldung ;
		}
		return input;
	}
	else
	{ 
		string sMeldung =" ------Fehler : Versuch ein Objekt zu spezifizieren. Sie Versuchen ein bereits spezifiziertes Objekt zu veraendern (" + p_sName + ") !------";
		throw sMeldung;
	}
	return input;
}

//Überladen des Eingabe-Operators ">>"
istream& operator >>(istream& input , AktivesVO& Object)
{
	Object.istreamEingabe(input);
	return input;
}

//Zeiger finden -> Funktion
AktivesVO* AktivesVO::ptObjekt(string sName)
{
	map<string,AktivesVO*>::iterator itMap;
	itMap = mapVO.find(sName);
	if(itMap == mapVO.end())
	{
		string sMeldung = " -----Fehler : Versuch einen Zeiger eines Objektes zu finden. Es ist kein Objekt unter dem Namen (" + sName + ") gespeichert !-----";
		throw sMeldung;
	}
	else
	{
		return itMap->second;
	}
}