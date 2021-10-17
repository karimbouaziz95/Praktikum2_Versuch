#pragma once
#include "AktivesVO.h"
#include <list>
#include "LazyListe.h"

typedef enum Begrenzung {Innerorts, Landstrasse, Autobahn};

using namespace std;

class Fahrzeug;

class Weg :
	public AktivesVO
{
public:
	Weg(void);
	Weg(string Name, double Laenge, Begrenzung Limit = Autobahn);
	~Weg(void);
    void vInitialisierung();
	
	virtual void vAbfertigung();
	virtual ostream& ostreamAusgabe(ostream& Stream);
    
    double dGetLaenge();
    void vAnnahme(Fahrzeug* pFahrzeug);
	void vAnnahme(Fahrzeug* pFahrzeug, double dStartzeit);
    Begrenzung eGetLimit();
	void vAbgabe(Fahrzeug* pFahrzeug);

protected:
	double p_dLaenge;
	LazyListe<Fahrzeug*> p_pFahrzeuge;
	Begrenzung p_eLimit;
};

