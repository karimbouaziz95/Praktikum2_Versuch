#pragma once
#include "fahrausnahme.h"

class Streckenende : public FahrAusnahme
{
public:
	//Konstruktoren
	Streckenende(void);
	Streckenende(Weg* Weg, Fahrzeug* Fzg) : FahrAusnahme(Weg,Fzg){};

	//Methode
	void vBearbeiten();

	//Destruktor
	virtual ~Streckenende(void);
};

