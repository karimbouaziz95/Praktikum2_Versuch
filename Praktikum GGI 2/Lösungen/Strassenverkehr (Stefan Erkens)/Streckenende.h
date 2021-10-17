#pragma once
#include "FahrAusnahme.h"

class Streckenende : public FahrAusnahme
{
	public:
		Streckenende(Fahrzeug* FzgPtr, Weg* WegPtr);
		~Streckenende(){};
		virtual void vBearbeiten(); //Gibt die Exception aus und nimmt das Fahrzeug von dem Weg

};