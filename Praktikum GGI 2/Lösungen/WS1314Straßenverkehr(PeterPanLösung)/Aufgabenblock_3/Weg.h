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
class Kreuzung;



#include <ostream> 


class Weg : public AktivesVO
{
public:
	Weg(void);
	virtual ~Weg(void);
	Weg(string sName , double dLaenge  , Kreuzung* cross , double eLimit = Autobahn , bool Ueberholverbot = true );
	Weg(string sName , double dLaenge , double eLimit = Autobahn,bool Ueberholverbot = true);
	ostream& Weg::ostreamAusgabe(ostream& Stream);
	void vAbfertigung();
	double GetLaenge() {return p_dLaenge;};
	void vAnnahme(Fahrzeug* Fzg);
	void vAnnahme(Fahrzeug* Fzg, double dStart);
	void vAbgabe(Fahrzeug* Fzg);
    double GetLimit();
	string GetName();
    void SetSchranke(double aktSchranke );
    double GetSchranke() {return p_dSchranke;};
	void vSetRueckweg(Weg* Rueckweg);
	Kreuzung GetpersCross();
	Weg* GetRueckweg();
	bool GetUeberholverbot();

private:
	double p_dLaenge;
	static int p_iMaxID;
	LazyListe<Fahrzeug*> p_pFahrzeuge;
	//list<Fahrzeug*> p_pFahrzeuge;
	double p_eLimit;
	enum {Innerorts = 50, Landstrasse = 100, Autobahn = 9999};
    bool p_bUeberholverbot;
    double p_dSchranke ;
	Weg *p_persRueckweg;
	Kreuzung *p_persCross;
     
};

