#pragma once

#include "Weg.h"
#include "Fahrzeug.h"

class FahrAusnahme
{
	public:
		virtual void vBearbeiten(){}; //Trivialer Funktionsstumpf

	protected:
		Weg* p_pWeg; //Weg, auf dem das Fahrzeug ist
		Fahrzeug* p_pFzg; //Fahrzeug, zu dem das Verhalten gehört

};