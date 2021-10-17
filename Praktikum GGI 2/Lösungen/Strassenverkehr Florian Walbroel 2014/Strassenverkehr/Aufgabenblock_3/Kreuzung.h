#pragma once
#include "AktivesVO.h"
#include <list>

class Weg;
class Fahrzeug;

class Kreuzung : public AktivesVO
{
public:
	Kreuzung(void);
	~Kreuzung(void){};
	Kreuzung(string sName);
	Kreuzung(string sName, double dTankstelle);

	void vVerbinde(string sHin, string sZurueck,double dLaenge, Kreuzung* pt_Inter);
	void vTanken(Fahrzeug* ptCar);
	void vAnnahme(Fahrzeug* ptCar, double dStartzeit);
	void vAnnahme(Fahrzeug* ptCar, double dStartzeit, Weg* ptWeg);
	void vWegeAusgabe();

	virtual void vAbfertigung();
	virtual ostream& ostreamAusgabe(ostream& Stream);
	virtual istream& istreamEingabe(istream& Stream);

	Weg* ptZufaelligerWeg(Weg* ptWeg);

protected:
	double p_dTankstelle;
	list<Weg*> pt_Wegfuehrend;

};