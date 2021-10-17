#pragma once
#include "aktivesvo.h"
#include "Fahrzeug.h"
#include "AktivesVO.h"
#include <iomanip>
#include <list>
class Weg;



class Kreuzung :
	public AktivesVO
{
public:
	//Konstruktoren
	Kreuzung(void);
	Kreuzung(string);
	Kreuzung(string, double);

	//Destruktor
	virtual ~Kreuzung(void);

	//Methode zum Verbinden
	void vVerbinde(string,string,double,Kreuzung*,int,bool = true);

	//Methode zum Tanken
	void vTanken(Fahrzeug*);

	//schreiben der abführenden Wege auf die Liste
	void vfillList(Weg*);

	//Umsetzen eines Fahrzeugs
	void vAnnahme(Fahrzeug*,double);

	//Abfertigung
	void vAbfertigung(void);

	//Überladen der Ausgabe
	virtual ostream& ostreamAusgabe(ostream& output);  //Referenz-Rückgabe

	//Überladen des Eingabe-Operators
	virtual istream& istreamEingabe(istream& input);  //Referenz-Rückgabe 

	//Zufaelliges Umsetzen
	Weg* ptZuefaelligerWeg(Weg*);

	//Umsetzen
	void vUmsetzen(Fahrzeug*,Weg*);

	//Übergabe des Namen
	string sgetName(void);

protected:
	//Liste mit WEGFÜHRENDEN Wegen
	list<Weg*> p_awaylist;

	//Tankinhalt der Tankstelle
	double p_dTankstelle;
};

