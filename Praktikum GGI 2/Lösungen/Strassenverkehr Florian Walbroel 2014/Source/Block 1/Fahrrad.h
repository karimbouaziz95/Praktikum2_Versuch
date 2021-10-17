//----- Aufgabenblock_1 -----//
#pragma once

#include "Fahrzeug.h"

class Fahrrad : public Fahrzeug {
public:
	/**
	 * @brief Konstruktor
	 */
	Fahrrad(string sName,
		    double dMaxGeschwindigkeit);
	/**
	 * @brief Geschwindigkeit Abh�ngigkeit der Gesamt Strecke
	 * @return aktuelle Geschwindigkeit
	 */
	double dGeschwindigkeit() const;
};
