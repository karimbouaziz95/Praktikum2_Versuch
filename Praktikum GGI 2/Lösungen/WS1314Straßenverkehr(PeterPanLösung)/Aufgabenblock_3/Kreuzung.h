#pragma once
#include "AktivesVO.h"

class Weg;
class Fahrzeug;
class PKW;
class Fahrzeug;
class Fahrrad;




#include <ostream> 
#include <list>


class Kreuzung : public AktivesVO
{
public:
	Kreuzung(void);
	Kreuzung(string Name,double Tankstellenvolumen=0);
	virtual ~Kreuzung(void);
	void vVerbinde(string Hinweg, string Rueckweg, double Weglaenge, Kreuzung* Cross, double GeschwLimit, bool UeVerbot);
	void vTanken(Fahrzeug* Fzg);
	void vAnnahme(Fahrzeug* Fzg, double Start=0);
	void vAnnahme(Fahrzeug* Fzg,Weg* way, double Start=0);
	void vAbfertigung();
	Weg* ptZufaelligerWeg(Weg* way);
	virtual istream& Kreuzung::istreamEingabe(istream& Stream);
	string GetName();


private:
	double p_dTankstelle;
    list<Weg*> p_pWegWege;

};

