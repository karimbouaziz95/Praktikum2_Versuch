#pragma once
#include "Fahrzeug.h"
class Weg;
// Anlegen der Klasse Fahrrad
class Fahrrad : public Fahrzeug
{
public:
	//Konstruktor
	//Fahrrad(void);
    Fahrrad(string sName="", double dMaxGeschwindigkeit = 30 );

	//Destruktor
    virtual ~Fahrrad(void);

	virtual double dGeschwindigkeit();
	virtual ostream& Fahrrad::ostreamAusgabe(ostream& Stream);
	virtual istream& Fahrrad::istreamEingabe(istream& Stream);
	void vZeichne(Weg* way);
};


