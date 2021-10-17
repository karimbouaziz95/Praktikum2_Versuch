//----- Aufgabenblock_1 -----//
#pragma once
#include "Fahrzeug.h"

#define PKW_STD_TANK_VOLUMEN		55.0
#define PKW_VOLL_TANKEN				-1.0

class PKW : public Fahrzeug {
public:
	/**
	 * @brief Konstruktor
	 */
	PKW(string sName, 
		double dMaxGeschwindigkeit);
	/**
	 * @brief Konstruktor
	 */
	PKW(string sName, 
		double dMaxGeschwindigkeit,
		double dVerbrauch,
		double dTankVolumen = PKW_STD_TANK_VOLUMEN);
	/**
	 * @brief Führt einen Abfertigungschritt aus
	 * @extern g_dGlobaleZeit - Globale Zeit
	 */
	void vAbfertigung();
	/**
	 * @brief Tankt den PKW um gewünschte Menge oder voll
	 * @param dMenge - gewünschte Menge
	 */
	double dTanken(double dMenge = PKW_VOLL_TANKEN);
	/**
	 * @brief Bisheriger Gesamtverbrauch
	 */
	double dVerbrauch() const;
	/**
	 * @brief Ausgabe des Fahrzeugs
	 */
	void vAusgabe(ostream& out = cout) const;
private:
	///Verbrauch (in Liter) pro 100 km
	double p_dVerbrauch;
	///Aktueller Inhalt des Tanks in Liter
	double p_dTankInhalt;
	///Volumen des Tanks in Liter
	double p_dTankVolumen;
};
