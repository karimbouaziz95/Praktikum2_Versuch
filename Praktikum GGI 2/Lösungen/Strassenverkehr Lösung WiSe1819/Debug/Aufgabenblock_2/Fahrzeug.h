#pragma once
#include <string>
#include <sstream>
#include <iomanip>
#define VOLLTANKEN 10000
#include"AktivesVO.h"
#include "FzgVerhalten.h"

using namespace std;

//class Weg;
class Fahrzeug:
	public AktivesVO
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
	string sGetName();
	void vSetGeschwindigkeit(double geschwindigkeit);
	double dGetZeit();
	double dGetAbschnittStrecke();
	void vNeueStrecke(Weg* weg, FzgVerhalten* pVerhalten);

	void vNeueStrecke(Weg * weg);

	void vNeueStrecke(Weg * weg, double dStartTime);
	
	virtual void vZeichnen(Weg *pWeg) ;
	


	//�berladen der Operatoren und des Copy-Konstruktors
	virtual ostream& ostreamAusgabe(ostream& output);  //Referenz-R�ckgabe 
	bool  operator <(const Fahrzeug& VglFzg);
	virtual void operator =(const Fahrzeug& VglFzg);


protected:

	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dAbschnittStrecke;
	FzgVerhalten* p_pVerhalten;
	
	
	//�berladen des Copy-Konstruktors
	Fahrzeug(const Fahrzeug &Vehicle);

private:
	void vInitialisierung();
	//FzgVerhalten &p_pVerhalten;
};

