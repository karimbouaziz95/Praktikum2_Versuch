#pragma once
#include <string>
#include <iostream>
#include <iomanip>

#include "AktivesVO.h"

using namespace std;

int AktivesVO::p_iMaxID = 0;
extern double dGlobaleZeit;

AktivesVO::AktivesVO()
{
	++p_iMaxID;
	p_iID = p_iMaxID;
}

//Ausgabe Operator
ostream& operator<<(ostream& Stream, AktivesVO& VO)
{
	VO.ostreamAusgabe(Stream);
	return Stream;
}

//ID und Namen ausgeben
ostream& AktivesVO::ostreamAusgabe(ostream& Stream)
{
	Stream << " " << resetiosflags(ios::right) << setiosflags(ios::right)
		 << setw(2) << p_iID << "    "
		 << resetiosflags(ios::right) << setiosflags(ios::left) 
		 << setw(15) << p_sName;
	return Stream;
}

string AktivesVO::GetName() const
{ 
	return p_sName;
}
