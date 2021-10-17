#pragma once
#include "AktivesVO.h"
#include <string>
#include <iostream>

using namespace std;
class Weg;
class FzgVerhalten;

class Fahrzeug : public AktivesVO
{
public:
	Fahrzeug(void);
	Fahrzeug(string sName);
	Fahrzeug(string sName, double dMaxSpeed);
	~Fahrzeug(void);

	string GetName() const;
	double GetAbschnittStrecke() const;
	void vNeueStrecke(Weg* ptWay, FzgVerhalten* ptFzgVerhalten);

	virtual void vAbfertigung();
	virtual void vAusgabe() const;
	virtual double GetTankinhalt() const {return 0.0;};
	virtual double dGeschwindigkeit() const;
	virtual double dTanken(double dMenge=0.0, bool status=false) { return 0.0;};
	virtual void vZeichnen(Weg* pWay) const {};
	virtual ostream& ostreamAusgabe(ostream& Stream);
	virtual istream& istreamEingabe(istream& Stream);

	virtual bool operator <(const Fahrzeug& fVergleich);
	virtual bool operator >(const Fahrzeug& fVergleich);
	virtual void operator =(const Fahrzeug& fVergleich);

protected:
	void vInitialisierung();

	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dZeit;
	double p_dAbschnittStrecke;
	FzgVerhalten *p_ptVerhalten;

private:
	Fahrzeug(const Fahrzeug&); //Copykonstruktor verbieten, da private.

};