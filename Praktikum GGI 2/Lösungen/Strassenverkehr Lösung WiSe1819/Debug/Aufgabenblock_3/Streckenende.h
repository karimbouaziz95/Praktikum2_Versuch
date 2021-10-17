#pragma once
#include"FahrAusnahme.h"
#include "SimuClient.h"

class Streckenende :
	public FahrAusnahme
{
public:
	Streckenende(Weg* weg, Fahrzeug* fzg);
	virtual ~Streckenende();
	void vBearbeiten();


};

