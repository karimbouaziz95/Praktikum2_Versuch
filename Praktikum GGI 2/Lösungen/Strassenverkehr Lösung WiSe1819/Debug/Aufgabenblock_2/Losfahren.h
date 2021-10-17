#pragma once
#include "FahrAusnahme.h"
class Losfahren : public FahrAusnahme
{
public:
	Losfahren(Weg *weg, Fahrzeug *fzg);
	void vBearbeiten();
};

