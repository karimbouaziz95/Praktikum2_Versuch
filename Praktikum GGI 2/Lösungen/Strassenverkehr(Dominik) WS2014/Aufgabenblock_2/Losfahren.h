#pragma once
#include "FahrAusnahme.h"
class Losfahren :
	public FahrAusnahme
{
public:
	Losfahren();
	Losfahren(Fahrzeug*, Weg*);
	virtual ~Losfahren();


	void vBearbeiten();
};

