#ifndef FAHRZEUG_H
#define FAHRZEUG_H
#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

extern double dGlobaleZeit;
using namespace std;  
class Fahrzeug
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
	//Überladungen
	virtual ostream& ostreamAusgabe(ostream&);
	bool operator <(const Fahrzeug&);
	virtual void  Fahrzeug:: operator =(Fahrzeug&);

protected:

	string p_sName;
	int p_iID;
	static int p_iMaxID;

	double p_dLetzeAbfertigung;
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke; 
	double p_dGesamtZeit;
	double p_dZeit;


	void   p_vInitialisierung();
	
};

ostream& operator << (ostream& out, Fahrzeug& x);









#endif