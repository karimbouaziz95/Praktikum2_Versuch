#pragma once
#include <iomanip>
#include <iostream>
#include <list>
#include "LazyListe.h"
#include "AktivesVO.h"
#include "Kreuzung.h"
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
	Weg(string sName, double dLaenge, double p_dLimit = Autobahn,  bool bUeberholverbot = true, Kreuzung* kreuzung = 0);
	~Weg();

	virtual void vAbfertigung();
	virtual ostream& ostreamAusgabe(ostream& output);
	void vAnnahme(Fahrzeug* fzg);
	void vAnnahme(Fahrzeug* fzg, double dStartzeit);
	void vAbgabe(Fahrzeug* fzg);
	double GetLimit();
	double GetLaenge();
	double dGetSchranke();
	void SetRueckweg(Weg* rueckweg);
	Kreuzung* GetKreuzung();
	Weg* GetRueckWeg();


private: 
	void vInitialisierung();
	double p_dLaenge;
	double p_dLimit;
	double p_dSchranke;
	bool p_bUeberholverbot;
	Kreuzung* p_kreuzung;
	//Kreuzung* p_Kreuzung;
	Weg* p_Rueckweg;
	LazyListe<Fahrzeug*> p_pFahrzeuge;
	
};

