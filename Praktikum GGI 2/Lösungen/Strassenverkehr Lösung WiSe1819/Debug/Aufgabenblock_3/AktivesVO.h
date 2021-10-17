#pragma once
#include <string>
#include <iomanip>
#include <iostream>

#include <map>

using namespace std; 
extern double dGlobaleZeit;

class AktivesVO
{
public:
	AktivesVO(void);
	AktivesVO(const string sName);
	virtual ~AktivesVO(void);

	virtual void vAbfertigung() = 0;
	virtual ostream& ostreamAusgabe(ostream& output);
	virtual istream& istreamEingabe(istream& input);
	string sGetName();
	static AktivesVO* ptObjekt(string sName);

protected:

	string p_sName;
	int p_iID;

	//double p_dGesamtZeit;
	double p_dZeit;
	static map<string, AktivesVO*> VOmap;
	
	
	

private:
	// Initialisierungsfunktion:
	virtual void vInitialisierung();
};


ostream& operator <<(ostream& output, AktivesVO& aktVo); //Operand kein Element der Klasse 


istream& operator >>(istream& input, AktivesVO& aktVo);