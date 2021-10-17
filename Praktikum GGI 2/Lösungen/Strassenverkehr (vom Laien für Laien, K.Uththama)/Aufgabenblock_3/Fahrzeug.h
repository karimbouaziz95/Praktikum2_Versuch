#pragma once
#include <string>
using namespace std;
#include <ostream> 
class Weg;
#include "AktivesVO.h"
#include "SimuClient.h"
class FzgVerhalten;

#define VOLLTANKEN 10000000000

//Unterklasse <AktivesVO>
class Fahrzeug : public AktivesVO
{
public:
	
	//Konstruktoren
	Fahrzeug(void);
	Fahrzeug(string sName);
	Fahrzeug(string sName , double MaxSpeed);

	//public Methoden
	void vsetName(string);
	string sgetName(void); 
	void vsetspeed(double);
	double dgetactLength(void);
	void vsetactLength(int);
	void vsetactTime(double);
	FzgVerhalten* getVerPtr(void);
	virtual void vAusgabe(void);
	virtual void vAbfertigung(void);
	virtual double dTanken(double dMenge = VOLLTANKEN);
	virtual double dGeschwindigkeit(void);
	void vNeueStrecke(Weg*);
	void vNeueStrecke(Weg*, double);
	virtual void vZeichnen(Weg*);
	virtual double dgetTank() {return 1;}
	
	//Destruktor
	virtual ~Fahrzeug(void);

	//�berladen der Operatoren und des Copy-Konstruktors
	virtual ostream& ostreamAusgabe(ostream&);  //Referenz-R�ckgabe 

	//�berladen des Eingabe-Operators
	virtual istream& istreamEingabe(istream& input);  //Referenz-R�ckgabe 

	bool  operator <(const Fahrzeug&);
	virtual Fahrzeug& operator =(const Fahrzeug&);
	
	
protected:	

	//�berladen des Copy-Konstruktors
	Fahrzeug(const Fahrzeug &Vehicle);
	
	//maximal fahrbare Geschwindigkeit
	double p_dMaxGeschwindigkeit;
	
	//gesamte gefahrene Strecke
	double p_dGesamtStrecke;
	
	//gesamte Abfertigungszeit
	double p_dGesamtZeit;

	//auf dem aktuellen Weg zur�ckgelegte Strecke
	double p_dAbschnittStrecke;

	//Fahrzeug Verhalten
	FzgVerhalten* p_pVerhalten;

private:
	//Initialisierungsfunktion
	void vInitialisierung();
};

