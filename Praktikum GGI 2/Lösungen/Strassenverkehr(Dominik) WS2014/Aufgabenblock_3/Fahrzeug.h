#ifndef FAHRZEUG_H
#define FAHRZEUG_H
#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "AktivesVO.h"
#include "FzgVerhalten.h"
extern double dGlobaleZeit;

using namespace std;  
class FzgVerhalten;
class Weg;
class FzgFahren;
class FzgParken;
class Fahrzeug: public AktivesVO

{


public:
	Fahrzeug(); 
	Fahrzeug(string);
	Fahrzeug(string,double);
	virtual ~Fahrzeug();


	void   vAusgabe();
	void    virtual vAbfertigung();
	virtual double dTanken(double=-1.0);
	virtual double dGeschwindigkeit();
	void vNeueStrecke(Weg*);
	void vNeueStrecke(Weg*,double);
	virtual void vZeichnen(Weg*)=0;

	virtual ostream& ostreamAusgabe(ostream&);
	virtual istream& istreamEingabe(istream& Stream);
	bool operator <(const Fahrzeug&);
	virtual void  Fahrzeug:: operator =(Fahrzeug&);
	//get
	double getp_dAbschnittStrecke()const;
	
	string GetName() const;
	FzgVerhalten* getp_pVerhalten();
	//set
	void setp_pVerhalten(FzgVerhalten*);

	

protected:
	double p_dGefahreneStrecke;
	double p_dAbschnittStrecke;
	double p_dLetzeAbfertigung;
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke; 
	
	void   vInitialisierung();
	FzgVerhalten *p_pVerhalten;
	
	
};

ostream& operator << (ostream& out, Fahrzeug& x);




#endif