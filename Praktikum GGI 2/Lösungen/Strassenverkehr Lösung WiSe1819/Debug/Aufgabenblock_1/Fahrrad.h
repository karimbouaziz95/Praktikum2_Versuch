#pragma once
#include "Fahrzeug.h"
class Fahrrad :
	public Fahrzeug
{
public:
	Fahrrad(void);

	Fahrrad(string sName, double MaxSpeed);

	~Fahrrad();

	virtual double dGeschwindigkeit();
	virtual void vGetName();
	virtual void vGetGeschwindigkeit();
	
};

