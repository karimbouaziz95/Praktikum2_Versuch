#pragma once
#include "FahrAusnahme.h"
class Streckenende :
	public FahrAusnahme
{
public:
	Streckenende();
	Streckenende(Fahrzeug* drivething, Weg* Way);
	virtual ~Streckenende();


	void vBearbeiten();
};

