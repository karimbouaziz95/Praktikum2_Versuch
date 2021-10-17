#pragma once
#include <string>
#include <ostream> 

#include <map>

using namespace std;

class AktivesVO
{
public:
	AktivesVO(void);
	virtual ~AktivesVO(void);
	AktivesVO(string sName);

	
    virtual void vAbfertigung() = 0;    //wird nur an Fahrzeug und Weg vererbt // rein virtuell
	//virtual void vAusgabe();

	virtual ostream& AktivesVO::ostreamAusgabe(ostream& Stream);
	virtual istream& AktivesVO::istreamEingabe(istream& Stream);

	
	static AktivesVO* ptObjekt(string sName); //Liefert Pointer für den Namen
	
protected:
	string p_sName;
	int p_iID;
	double p_dZeit;
	static map<string, AktivesVO*> VOmap;
};

// operator<< außerhalb der Klasse überladen
ostream& operator << (ostream& Stream, AktivesVO& car);
istream& operator >> (istream& Stream, AktivesVO& car);