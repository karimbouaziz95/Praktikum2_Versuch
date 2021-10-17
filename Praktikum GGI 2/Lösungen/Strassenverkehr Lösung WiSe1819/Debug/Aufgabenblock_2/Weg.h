#pragma once
#include <iomanip>
#include <iostream>
#include <list>
#include "LazyListe.h"
#include "AktivesVO.h"
#define UNBEGRENZT 1000000

using namespace std;

class Fahrzeug;

enum Begrenzung 
{
	Innerorts = 50,
	Ausserorts = 100,
	Autobahn = UNBEGRENZT
};

class Weg: 
	public AktivesVO
{
public:
	Weg(void);
	Weg(string sName, double dLaenge, double p_dLimit = Autobahn);
	~Weg();

	virtual void vAbfertigung();
	virtual ostream& ostreamAusgabe(ostream& output);
	void vAnnahme(Fahrzeug* fzg);
	void vAnnahme(Fahrzeug* fzg, double dStartzeit);
	void vAbgabe(Fahrzeug* fzg);
	double GetLimit();
	double GetLaenge();
	string sGetName();


private: 
	void vInitialisierung();
	double p_dLaenge;
	double p_dLimit;
	LazyListe<Fahrzeug*> p_pFahrzeuge;
	
};

