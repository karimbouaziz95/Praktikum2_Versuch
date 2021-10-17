#pragma once
#include "fahrausnahme.h"

class Losfahren : public FahrAusnahme
{
public:
	//Konstruktoren
	Losfahren(void);
	Losfahren(Weg* Weg, Fahrzeug* Fzg) : FahrAusnahme(Weg,Fzg){} ;

	//Methode
	void vBearbeiten();

	//Destruktor
	virtual ~Losfahren(void);
};

