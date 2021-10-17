#pragma once
#include "FahrAusnahme.h"

class Losfahren : public FahrAusnahme
{
public:
	Losfahren(void);
	Losfahren(Fahrzeug* pFzg, Weg* pWeg) : FahrAusnahme(pFzg, pWeg) {};
	virtual ~Losfahren(void);
	void vBearbeiten();

};

