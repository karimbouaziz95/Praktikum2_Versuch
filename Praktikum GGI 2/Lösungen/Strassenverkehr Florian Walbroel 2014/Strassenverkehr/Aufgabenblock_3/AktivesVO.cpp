#pragma once
#include <string>
#include <iostream>
#include <iomanip>

#include "AktivesVO.h"

using namespace std;

int AktivesVO::p_iMaxID = 0;
extern double dGlobaleZeit;
map<string, AktivesVO*> AktivesVO::VOmap;

AktivesVO::AktivesVO()
{
	++p_iMaxID;
	p_iID = p_iMaxID;
	p_sName = "";
}

AktivesVO::AktivesVO(string sName)
{
	++p_iMaxID;
	p_iID = p_iMaxID;
	p_sName = sName;

	if(VOmap.find(p_sName) == VOmap.end())
	{
		VOmap[p_sName] = this;
	}
	else if(p_sName != "")
	{
			throw new string ("Objekt mit " + p_sName + " existiert schon.");
	}
}

void AktivesVO::vAusgabe()
{
	cout.precision(2); // Auf zwei Nachkommastellen runden und immer anzeigen. (5.00)

	cout << " " << resetiosflags(ios::right) << setiosflags(ios::right)
		 << setw(2) << p_iID << "    "
		 << resetiosflags(ios::right) << setiosflags(ios::left) // wieder linksbündig
		 << setw(15) << p_sName;
}

ostream& operator<<(ostream& Stream, AktivesVO& VO)
{
	VO.ostreamAusgabe(Stream);
	return Stream;
}

istream& operator>>(istream& Stream, AktivesVO& VO)
{
	VO.istreamEingabe(Stream);
	return Stream;
}

ostream& AktivesVO::ostreamAusgabe(ostream& Stream)
{
	Stream.precision(2); // Auf zwei Nachkommastellen runden und immer anzeigen. (5.00)

	Stream << " " << resetiosflags(ios::right) << setiosflags(ios::right)
		 << setw(2) << p_iID << "    "
		 << resetiosflags(ios::right) << setiosflags(ios::left) // wieder linksbündig
		 << setw(15) << p_sName;
	return Stream;
}

istream& AktivesVO::istreamEingabe(istream& Stream)
{
	if(p_sName=="")
	{
		Stream >> p_sName;

		if(VOmap.find(p_sName)==VOmap.end())
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
		throw new string ("Objekt " + p_sName + " hat schon einen Namen");
	}

	return Stream;
}

string AktivesVO::GetName() const
{ 
	return p_sName;
}

AktivesVO* AktivesVO::ptObjekt(string sName)
{
	if(VOmap.find(sName) == VOmap.end())
	{
		throw new string("Objekt mit " + sName + " existiert nicht!");
	}
	else
	{
		cout << "basdl";
		return VOmap.find(sName)->second;
	}
}