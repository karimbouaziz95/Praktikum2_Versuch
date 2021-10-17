#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <map>

using namespace std;


class AktivesVO
{
public:
	AktivesVO(void);
	AktivesVO(string sName);
	virtual ~AktivesVO(void);

	virtual void vAbfertigung(void) = 0;
    virtual ostream& ostreamAusgabe(ostream& Stream);
	virtual istream& istreamEingabe(istream& Stream);
    string sGetName();
    void vInitialisierung();
	static AktivesVO* ptObjekt(string sName);
    
protected:
	string p_sName;
	int p_iID;
	double p_dZeit;
    double p_dGesamtZeit;
private:
	static int p_iMaxID;
	static map<string, AktivesVO*> mapVO;
};

ostream& operator<<(ostream& Stream, AktivesVO& AktivesVO_o);
istream& operator>>(istream& Stream, AktivesVO& AktivesVO_o);