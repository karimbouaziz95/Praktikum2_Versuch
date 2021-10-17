#pragma once
#include <iomanip>
#include <iostream>
#include <list>
#include "Fahrzeug.h"
class Kreuzung : public AktivesVO
{
public:
	Kreuzung();
	Kreuzung(string sName, double tankstelle = 0);
	~Kreuzung();
	void vVerbinde(string hinweg, string rueckweg, double laenge, Kreuzung* kreuzung, double speedLimit = 10000, bool ueberholverbot = true);
	void vTanken(Fahrzeug* fzg);
	void wegHinzufuegen(Weg* weg);
	void vAnnahme(Fahrzeug* fzg, double zeit);
	void vAbfertigung();
	virtual ostream& ostreamAusgabe(ostream& output);
	virtual istream& istreamEingabe(istream& input);
	Weg* ptZufaelligerWeg(Weg* weg);
	double dGetTankstelle();

private:
	double p_dTankstelle;
	list<Weg*> p_abgehendeWege;
};

