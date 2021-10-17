#pragma once
#include "AktivesVO.h"
#include <list>
#include "LazyListe.h"

typedef enum Begrenzung {Innerorts, Landstrasse, Autobahn};

using namespace std;

class Fahrzeug;
class Kreuzung;

class Weg :
	public AktivesVO
{
public:
	Weg(void);
	Weg(string Name, double Laenge, Begrenzung Limit = Autobahn, bool Verbot = true);
	Weg(string Name, double Laenge, Kreuzung* pKreuz, Begrenzung Limit = Autobahn, bool Verbot = true);
	~Weg(void);
    void vInitialisierung();
	
	virtual void vAbfertigung();
	virtual ostream& ostreamAusgabe(ostream& Stream);
    
    double dGetLaenge();
	double dGetSchranke();
	bool bGetVerbot();
	void vSetzeSchranke(double dWert);
	void vSetzeRueck(Weg* Weg);
	Begrenzung eGetLimit();
	Kreuzung* kGetKreuzung();
	Weg* pGetRueckweg();

    void vAnnahme(Fahrzeug* pFahrzeug);
	void vAnnahme(Fahrzeug* pFahrzeug, double dStartzeit);
	void vAbgabe(Fahrzeug* pFahrzeug);


protected:
	double p_dLaenge;
	bool p_bUeberholverbot;
	double p_dSchranke;
	LazyListe<Fahrzeug*> p_pFahrzeuge;
	Begrenzung p_eLimit;
	Kreuzung* p_pkKreuzung;
	Weg* p_pwRueckWeg;
};

