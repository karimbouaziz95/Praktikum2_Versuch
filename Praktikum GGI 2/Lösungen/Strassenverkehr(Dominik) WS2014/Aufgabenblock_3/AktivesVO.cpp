#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "AktivesVO.h"


int AktivesVO::p_iMaxID = 0;

map<string, AktivesVO*> AktivesVO::VOmap;


//<Konstruktoren_Destruktoren>
AktivesVO::AktivesVO()
{
}
AktivesVO::~AktivesVO()
{
}
AktivesVO::AktivesVO(string sName)
{
	++p_iMaxID;
	p_iID = p_iMaxID;
	p_sName = sName;

	if (VOmap.find(p_sName) == VOmap.end())
	{
		VOmap[p_sName] = this;
	}
	else if (p_sName != "")
	{
		throw new string("Objekt mit " + p_sName + " existiert schon.");
	}
}
//</Konstruktoren_Destruktoren>



//<Allgemeine_Funktionen>
void AktivesVO::vInitialisierung()
{

	p_sName = "";
	p_iMaxID++;
	p_iID = p_iMaxID;
	
	

}
AktivesVO* AktivesVO::ptObjekt(string sName)
{
	if (VOmap.find(sName) == VOmap.end())
	{
		throw new string("Objekt mit " + sName + " existiert nicht!");
	}
	else
	{
		cout << "Objekt gefunden!";
		return VOmap.find(sName)->second;
	}
}
//</Allgemeine_Funktionen>



//<Setter_Getter_Funktionen>
string AktivesVO::getsName()const {


	return p_sName;


}
//</Setter_Getter_Funktionen>



//<Ueberladungen>
ostream& operator << (ostream& out, AktivesVO& x)
{
	return x.ostreamAusgabe(out);
}
istream& operator>>(istream& Stream, AktivesVO& VO)
{
	VO.istreamEingabe(Stream);
	return Stream;
}
ostream& AktivesVO::ostreamAusgabe(ostream& out)
{
	out << setiosflags(ios::left) <<
	setw(5) << p_iID << setw(10)
	<< p_sName << setw(5) << ":";
	return out;
}
istream& AktivesVO::istreamEingabe(istream& Stream)
{
	if (p_sName == "")
	{
		Stream >> p_sName;

		if (VOmap.find(p_sName) == VOmap.end())
		{
			VOmap[p_sName] = this;
		}
		else
		{
			throw new string("Objekt " + p_sName + " existiert schon");
		}
	}
	else
	{
		throw new string("Objekt " + p_sName + " hat schon einen Namen");
	}

	return Stream;
}
//</Ueberladungen>