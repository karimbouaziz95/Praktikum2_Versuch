#pragma once
#include <list>
#include "AktivesVO.h"
#include "FzgVerhalten.h"
#include "LazyListe.h"

#include <list>
#include <string>
#include <iostream>
#include <iomanip>
#define UNBEGRENZT 1000000
class Fahrzeug;
class FzgVerhalten;

using namespace std ;

//Geschwindigkeitslimit
enum Begrenzung { Innerorts = 50, Landstra�e = 100, Autobahn = UNBEGRENZT};

//Unterklasse <AktivesVO>
class Weg :
	public AktivesVO
{
public:
	//Konstruktoren
	Weg(void);
	Weg(string sName, double dLaenge, int iSpeedlimit = Autobahn);

	//Destrukor
	virtual ~Weg(void);

	//Methoden
	void vAbfertigung();
	double dgetlength();
	void vAnnahme(Fahrzeug*);
	void vAnnahme(Fahrzeug*, double);
	int igetSpeedLimit();
	string sgetName();
	void vAbgabe(Fahrzeug*);

	//�berladen der Ausgabe
	virtual ostream& ostreamAusgabe(ostream& output);  //Referenz-R�ckgabe 
   

private:
	//L�nge in Km
	double p_dLaenge;

	//Liste von Fahrzeugen
	LazyListe<Fahrzeug*> p_pFahrzeuge;

	//zul�ssige Geschw.
	int p_eLimit;

};

