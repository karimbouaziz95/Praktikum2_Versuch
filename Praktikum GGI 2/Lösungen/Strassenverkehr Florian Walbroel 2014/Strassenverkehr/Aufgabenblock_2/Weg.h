#pragma once

#include "AktivesVO.h"
#include "LazyListe.h"

using namespace std;

class Fahrzeug;

class Weg : public AktivesVO
{
public:
	Weg(void){};
	Weg(string sName, double dLaenge);
	~Weg(void) {};
	double GetLaenge() const;
	string GetName() const;

	virtual void vAbfertigung();
	virtual ostream& ostreamAusgabe(ostream& Stream);
	virtual void vAusgabe();

	void anlegen();
	void vAnnahme(Fahrzeug *ptCar);
	void vAnnahme(Fahrzeug *ptCar, double dStartzeit);
	void vAbgabe(Fahrzeug *ptCar);


protected:
	double p_dLaenge;
	LazyListe<Fahrzeug*> p_ptFahrzeuge;
	
};
