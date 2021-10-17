#pragma once
#include "Fahrzeug.h"

//Unterklasse Fahrrad wird angelegt
class Fahrrad : public Fahrzeug
{
public:
	//Konstruktor
	Fahrrad(void);
	Fahrrad(string sName , double MaxSpeed);

	//Destruktor
	virtual ~Fahrrad(void);

	virtual double dGeschwindigkeit();
};

