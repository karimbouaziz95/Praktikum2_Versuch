#pragma once
#include <string>
#include <iostream>

using namespace std;

class Fahrzeug
{
public:
	Fahrzeug(void);
	Fahrzeug(string sName);
	Fahrzeug(string sName, double dMaxSpeed);
	~Fahrzeug(void);
	string GetName(){ return p_sName;};

	virtual void vAbfertigung();
	virtual void vAusgabe();
	virtual double dGeschwindigkeit();
	virtual double dTanken(double dMenge=0.0) { return 0.0;};
	virtual ostream& ostreamAusgabe(ostream& Stream);

	bool operator <(const Fahrzeug& fVergleich);
	bool operator >(const Fahrzeug& fVergleich);
	void operator =(const Fahrzeug& fVergleich);

private:
	void vInitialisierung();

protected:
	int p_iID;
	static int p_iMaxID;
	string p_sName;
	double p_dMaxGeschwindigkeit;
    double p_dGesamtStrecke;
    double p_dGesamtZeit;
	double p_dZeit;
};

ostream& operator<<(ostream& Stream, Fahrzeug& car);
