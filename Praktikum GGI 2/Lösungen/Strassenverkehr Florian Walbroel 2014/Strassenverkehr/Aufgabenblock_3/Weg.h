#pragma once

#include "AktivesVO.h"
#include "LazyListe.h"
#include "Kreuzung.h"

using namespace std;

class Fahrzeug;

class Weg : public AktivesVO
{
public:
	Weg(void){};
	Weg(string sName, double dLaenge);
	Weg(string sName, double dLaenge, Kreuzung* pt_Inter);
	~Weg(void) {};

	double GetLaenge() const;
	string GetName() const;
	double GetSchranke() const;
	Kreuzung* GetKreuzung() const;
	Weg* GetRueckweg() const;

	void SetSchranke(double dSchranke);
	void SetRueckweg(Weg* pt_Way);

	virtual void vAbfertigung();
	virtual ostream& ostreamAusgabe(ostream& Stream);
	virtual istream& istreamEingabe(istream& Stream);
	virtual void vAusgabe();

	void anlegen();
	void vAnnahme(Fahrzeug *ptCar);
	void vAnnahme(Fahrzeug *ptCar, double dStartzeit);
	void vAbgabe(Fahrzeug *ptCar);


protected:
	double p_dLaenge;
	double p_dSchranke;
	Kreuzung* p_ptKreuzung;
	Weg* p_ptRueckweg;
	LazyListe<Fahrzeug*> p_ptFahrzeuge;
	
};
