#pragma once
#include <string>
using namespace std;
#include <ostream> 

// Anlegen der Klasse Fahrzeug 
class Fahrzeug
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

	//Überladen
	virtual ostream& Fahrzeug::ostreamAusgabe(ostream& Stream);
	bool operator <(const Fahrzeug& vergleichsfahrzeug);
	void operator =(const Fahrzeug& vergleichsfahrzeug);

 private:
	
	void vInitialisierung();

 protected:
	//Vererbbare Variablen
	string p_sName;
	int p_iID;
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dZeit;
    static int p_iMaxID;
};

// operator<< außerhalb der Klasse überladen
ostream& operator<<(ostream& Stream, Fahrzeug& car);

