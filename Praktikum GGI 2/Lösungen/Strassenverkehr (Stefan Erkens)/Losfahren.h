#pragma once
#include "FahrAusnahme.h"

class Losfahren : public FahrAusnahme
{
	public:
		Losfahren(Fahrzeug* FzgPtr, Weg* WegPtr);
		~Losfahren(){};
		virtual void vBearbeiten(); //Gibt die Exception aus und setzt das Fahrzeug neu auf den Weg


};