#pragma once
#include <string>
#include <ostream> 
using namespace std;

class AktivesVO
{
public:
	AktivesVO(void);
	virtual ~AktivesVO(void);

	
    virtual void vAbfertigung() = 0;    //wird nur an Fahrzeug und Weg vererbt // rein virtuell
	//virtual void vAusgabe();

	virtual ostream& AktivesVO::ostreamAusgabe(ostream& Stream); 

protected:
	string p_sName;         // gemeinsame Membervariablen von Weg und Fahrzeug 
	int p_iID;
	double p_dZeit;
};

// operator<< außerhalb der Klasse überladen
ostream& operator << (ostream& Stream, AktivesVO& car);