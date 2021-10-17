#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Fahrzeug
{
public:
	Fahrzeug(void);
	Fahrzeug(string sName);
	Fahrzeug(string sName, double dMaxGeschwindigkeit);
	~Fahrzeug(void); 
	
	virtual void vAusgabe(void);
	virtual void vAbfertigung(void);
	virtual double dTanken(double dMenge=0.0);
	virtual double dGeschwindigkeit(void);
	virtual ostream& ostreamAusgabe(ostream& Stream);
	bool operator <(const Fahrzeug& fVergleichsFahrzeug);
	void operator =(const Fahrzeug& fVergleichsFahrzeug);

private:
	static int p_iMaxID;
	void vInitialisierung(void);

protected:
	string p_sName;
	int p_iID;
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtzeit;
	double p_dZeit;
};

ostream& operator<<(ostream& Stream, Fahrzeug& Fahrzeug_o);