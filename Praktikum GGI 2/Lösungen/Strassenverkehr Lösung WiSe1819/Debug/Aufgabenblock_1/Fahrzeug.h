#pragma once
#include <string>
#define VOLLTANKEN 55

using namespace std;

class Fahrzeug
{
public:
	Fahrzeug(); //Standard Konstruktor 
	Fahrzeug(string sName);
	Fahrzeug(string sName, double dMaxGeschwindigkeit);
	virtual ~Fahrzeug(); //Destruktor
	virtual double dTanken(double dMenge = VOLLTANKEN);
	virtual void vAusgabe(void);
	virtual void vAbfertigung();
	virtual double dGeschwindigkeit();
	void vSetName(string sName);
	void vSetGeschwindigkeit(double geschwindigkeit);


	//�berladen der Operatoren und des Copy-Konstruktors
	virtual ostream& ostreamAusgabe(ostream& output);  //Referenz-R�ckgabe 
	bool  operator <(const Fahrzeug& VglFzg);
	virtual void operator =(const Fahrzeug& VglFzg);


protected:
	string p_sName;
	int p_iID;
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dZeit;
	//�berladen des Copy-Konstruktors
	Fahrzeug(const Fahrzeug &Vehicle);



private:
	
	void vInitialisierung();

	
};

ostream& operator <<(ostream& output, Fahrzeug& Fzg); //Operand kein Element der Klasse 
