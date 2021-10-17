#pragma once
#include "aktivesvo.h"
#include <list>
#include "Weg.h"

class Weg;
class Fahrzeug;

class Kreuzung :
	public AktivesVO
{
public:
	Kreuzung();
	Kreuzung(string Name, double Tank=0.0);
	~Kreuzung(void);
	void vInitialisierung();
	void vVerbinde(string sWegHin, string sWegRueck, double dWegLaenge, Kreuzung* kPoint, Begrenzung Limit, bool bUebVer = true);
	void vTanken(Fahrzeug* Fzg);
	void vAnnahme(Fahrzeug* Fzg, double count);
	void vAnnahme(Fahrzeug* Fzg, double count, Weg* pWeg);
	void vAbfertigung();
	virtual ostream& ostreamAusgabe(ostream& stream);
	virtual istream& istreamEingabe(istream& Stream);
	Weg* ptZufaelligerWeg(Weg* pWeg);

protected:
	double p_dTankstelle;
	list <Weg*> p_wWege;
};

