#pragma once
#include "FahrAusnahme.h"
#include "Weg.h"

class Streckenende : public FahrAusnahme
{
public:
	Streckenende(void);
	Streckenende(Fahrzeug* pFzg, Weg* pWeg) : FahrAusnahme(pFzg, pWeg) {};
	virtual ~Streckenende(void);
	void vBearbeiten();
};

