#pragma once

#include <list>
#include "AktivesVO.h"
//#include "FzgParken.h"
//#include "FzgFahren.h"
#include "FzgVerhalten.h"
#include "FahrAusnahme.h"
#include "LazyListe.h"

//class AktivesVO;
class PKW;
class FzgFahren;
class FzgParken;
class Fahrzeug;



#include <ostream> 


class Weg : public AktivesVO
{
public:
	Weg(void);
	virtual ~Weg(void);
	Weg(string sName,double dLaenge, double eLimit = Autobahn);
	ostream& Weg::ostreamAusgabe(ostream& Stream);
	void vAbfertigung();
	void vAnnahme(Fahrzeug* Fzg);
	void vAnnahme(Fahrzeug* Fzg, double dStart);
	void vAbgabe(Fahrzeug* Fzg);
	double GetLaenge() {return p_dLaenge;};
    double GetLimit();
	string GetName();



private:
	double p_dLaenge;
	static int p_iMaxID;
	LazyListe<Fahrzeug*> p_pFahrzeuge;
	//list<Fahrzeug*> p_pFahrzeuge;
	double p_eLimit;
	enum {Innerorts = 50, Landstrasse = 100, Autobahn = 9999}; // enum für Begrenzungen
};

