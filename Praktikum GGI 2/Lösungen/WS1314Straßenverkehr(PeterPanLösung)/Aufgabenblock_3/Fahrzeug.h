#pragma once
#include <string>
using namespace std;
#include <ostream> 
class Weg;
#include "AktivesVO.h"
class FzgVerhalten;

// Anlegen der Klasse Fahrzeug 
class Fahrzeug : public AktivesVO
{

 public:
	//Konstruktoren
	Fahrzeug(void);
	Fahrzeug(string sName);
	Fahrzeug(string sName, double p_dMaxGeschwindigkeit); 
	

	//Destruktor
	virtual ~Fahrzeug(void);

	string getName();
	void setName();

	virtual void vAusgabe();
    virtual void vAbfertigung();
	virtual double dTanken(double dMenge = 0.0); 
	virtual double dGeschwindigkeit() {return p_dMaxGeschwindigkeit;};
	//void vNeueStrecke(Weg* ptWeg);
	void vNeueStrecke(Weg* ptWeg, FzgVerhalten* pBenehmen);
	double GetAbschnittStrecke() {return p_dAbschnittStrecke;};
	virtual void vZeichne(Weg* way) = 0;
    

	//Überladen
	virtual ostream& Fahrzeug::ostreamAusgabe(ostream& Stream);
	virtual istream& Fahrzeug::istreamEingabe(istream& Stream); 
	bool operator < (const Fahrzeug& vergleichsfahrzeug);
	void operator = (const Fahrzeug& vergleichsfahrzeug);

 private:
	
    Fahrzeug(Fahrzeug&);
	void vInitialisierung();

 protected:
	//Vererbbare Variablen
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dAbschnittStrecke;
    static int p_iMaxID;
    FzgVerhalten  *p_pVerhalten;
};



