#pragma once
#include <string>
using namespace std ;

#define VOLLTANKEN 10000000000

//Basisklasse
class Fahrzeug
{
public:
	//Konstruktoren
	Fahrzeug(void);
	Fahrzeug(string sName);
	Fahrzeug(string sName , double MaxSpeed);

	//public Methoden
	void vgetName(string sName);
	void vsetName(); 
	void vgetspeed(double Maxspeed);
	virtual void vAusgabe(void);
	virtual void vAbfertigung();
	virtual double dTanken(double dMenge = VOLLTANKEN);
	virtual double dGeschwindigkeit();
	
	//Destruktor
	virtual ~Fahrzeug(void);

	//Überladen der Operatoren und des Copy-Konstruktors
	virtual ostream& ostreamAusgabe(ostream& output);  //Referenz-Rückgabe 
	bool  operator <(const Fahrzeug& VglFzg);
	virtual void operator =(const Fahrzeug& VglFzg);
	


	
protected:	

	//überladen des Copy-Konstruktors
	Fahrzeug(const Fahrzeug &Vehicle);
	
	//maximal fahrbare Geschwindigkeit
	double p_dMaxGeschwindigkeit;
	
	//gesamte gefahrene Strecke
	double p_dGesamtStrecke;
	
	//gesamte Abfertigungszeit
	double p_dGesamtZeit;
	
	//zuletzt abgefertigte Zeit
	double p_dZeit;
   
	//Name des jeweiligen Fahrzeugs
	string p_sName;
	
	//ID des jeweiligen Fahrzeugs
	int p_iID;
	

private:
	//Initialisierungsfunktion
	void vInitialisierung();
	
	//höchzählende  Klassenvariable -> ID 
	static int p_iMaxID;
};

ostream& operator <<(ostream& output , Fahrzeug& Fzg); //Operand kein Element der Klasse deshalb außerhalb
