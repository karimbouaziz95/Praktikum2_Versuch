#pragma once
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;


class AktivesVO
{
public:
	AktivesVO(void);
	virtual ~AktivesVO(void);

	virtual void vAbfertigung(void) = 0;
    virtual ostream& ostreamAusgabe(ostream& Stream);
    string sGetName();
    void vInitialisierung();
    
protected:
	string p_sName;
	int p_iID;
	double p_dZeit;
    double p_dGesamtZeit;
private:
	static int p_iMaxID;
};

ostream& operator<<(ostream& Stream, AktivesVO& AktivesVO_o);