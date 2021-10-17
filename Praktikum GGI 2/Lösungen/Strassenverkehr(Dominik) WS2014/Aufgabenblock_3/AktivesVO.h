#ifndef AKTIVESVO_H
#define AKTIVESVO_H
#pragma once
#include <sstream>
#include <iomanip>
#include <string>
#include <iostream>
#include <map>

using namespace std;

class AktivesVO
{

public:
	AktivesVO();
	AktivesVO(string);
	virtual ~AktivesVO();

	virtual void vAbfertigung() = 0;

	virtual ostream& ostreamAusgabe(ostream&);
	virtual istream& istreamEingabe(istream& Stream);
	void vInitialisierung();
	
	string p_sName;
	static AktivesVO* ptObjekt(string sName);
	string getsName()const;

protected:
	
	int p_iID;
	static int p_iMaxID;
	double p_dZeit;
	static map<string, AktivesVO*> VOmap;
};


ostream& operator << (ostream& out, AktivesVO& x);
istream& operator>>(istream& Stream, AktivesVO& VO);




#endif