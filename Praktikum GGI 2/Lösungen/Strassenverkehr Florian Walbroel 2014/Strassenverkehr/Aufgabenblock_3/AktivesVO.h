#pragma once
#include <string>
#include <iostream>
#include <map>

using namespace std;


class AktivesVO
{
public:
	AktivesVO();
	virtual ~AktivesVO(){};
	AktivesVO(string sName);

	virtual void vAbfertigung() = 0;
	virtual void vAusgabe();
	virtual ostream& ostreamAusgabe(ostream& Stream);
	virtual istream& istreamEingabe(istream& Stream);

	static AktivesVO* ptObjekt(string sName);

	string GetName() const;

protected:
	int p_iID;
	static int p_iMaxID;
	string p_sName;
	double p_dZeit;
	static map<string, AktivesVO*> VOmap;
};

ostream& operator<<(ostream& Stream, AktivesVO& VO);
istream& operator>>(istream& Stream, AktivesVO& VO);
