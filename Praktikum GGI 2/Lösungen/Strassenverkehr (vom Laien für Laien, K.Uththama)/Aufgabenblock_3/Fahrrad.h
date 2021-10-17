#pragma once
#include "Fahrzeug.h"

//Unterklasse <Fahrrad>
class Fahrrad : public Fahrzeug
{
public:
	//Konstruktor
	Fahrrad(void);
	Fahrrad(string sName , double MaxSpeed);

	//Destruktor
	virtual ~Fahrrad(void);

	//Methoden
	void vZeichnen(Weg*);
	void vAbfertigung();

	virtual double dGeschwindigkeit();
};

