#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "AktivesVO.h"

using namespace std;

class Weg;
class FzgVerhalten;

class Fahrzeug : 
	public AktivesVO
{
public:
	Fahrzeug(void);
	Fahrzeug(string sName);
	Fahrzeug(string sName, double dMaxGeschwindigkeit);
	~Fahrzeug(void); 
	
    void vNeueStrecke(Weg* pWeg, FzgVerhalten* pFzgVerhalten);
	virtual void vAusgabe(void);
	virtual void vAbfertigung(void);
	virtual double dTanken(double dMenge=0.0);
	virtual double dGeschwindigkeit(void);
	virtual ostream& ostreamAusgabe(ostream& Stream);
	bool operator <(const Fahrzeug& fVergleichsFahrzeug);
	void operator =(const Fahrzeug& fVergleichsFahrzeug);
    virtual void vZeichnen(Weg* pWeg);
    double dGetAbschnittStrecke();

private:
	void vInitialisierung(void);

protected:
	double p_dAbschnittStrecke;
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
    FzgVerhalten* p_pVerhalten;
};

