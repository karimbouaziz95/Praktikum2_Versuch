#pragma once
#include "Fahrzeug.h"

// Anlegen der Klasse Fahrrad
class Fahrrad : public Fahrzeug
{
public:
	//Konstruktor
    Fahrrad(string sName = "Rad", double dMaxGeschwindigkeit = 30 );

	//Destruktor
    virtual ~Fahrrad(void);

	virtual double dGeschwindigkeit();
	virtual ostream& Fahrrad::ostreamAusgabe(ostream& Stream);
    void vAusgabe(void);
};


