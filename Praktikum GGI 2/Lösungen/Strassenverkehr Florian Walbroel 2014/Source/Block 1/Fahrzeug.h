//----- Aufgabenblock_1 -----//
#pragma once

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//#define DEBUG
//#define DISABLE_COPY

#define FAHRZEUG_VOLL_TANKEN		-1.0

class Fahrzeug  {
public:
	/**
	  * @brief Konstruktor
	 */
	Fahrzeug();

	/**
	  * @brief Konstruktor
	  * @param sName - Name des Fahrzeugs
	 */
	Fahrzeug(string sName);

	/**
	  * @brief Konstruktor
	  * @param sName			   - Name des Fahrzeugs
	  * @param dMaxGeschwindigkeit - Maximale Geschwind.
	 */
	Fahrzeug(string sName, double dMaxGeschwindigkeit);

#ifndef DISABLE_COPY
	/**
	 * @brief Copy-Konstruktor
	 * @param das zu kopierende Fahrzeug
	 */
	Fahrzeug(const Fahrzeug&);
	/**
	 * @brief Assignment Operator
	 * @param das zu kopierende Fahrzeug
	 */
	Fahrzeug& operator = (const Fahrzeug&);	
#endif // ifndef DISABLE_COPY

	/**
	  * @brief Destruktor
	 */
	virtual ~Fahrzeug();

	/**
	 * @brief Vergleicht die Gesamtstrecke der Fahrzeuge
	 */
	bool operator < (const Fahrzeug&);

	/**
	  * @brief Führt einen Abfertigungschritt aus
	  * @extern g_dGlobaleZeit - Globale Zeit
	 */
	virtual void vAbfertigung();

	/**
	 * @brief Gibt die Geschwindigkeit des Fahrzeugs zurück
	 * @return die Geschwindigkeit
	 */
	virtual double dGeschwindigkeit() const { return p_dMaxGeschwindigkeit; }

	/**
	 * @brief Tankt das Fahrzeug um gewünschte Menge oder voll
	 * @param dMenge - gewünschte Menge
	 */
	virtual double dTanken(double dMenge = 
						   FAHRZEUG_VOLL_TANKEN) { return 0; }

	/**
	 * @brief gibt den Name zurück
	 * @return Name des Fahrzeugs
	 */
	string sName();

	/**
	 * @brief Ändert den Namen des Fahrzeugs
	 * @param sName - neuer Name
	 */
	void vNeuerName(string sName);

	/**
	  * @brief Ausgabe des Fahrzeugs
	  */
	virtual void vAusgabe(ostream& out = cout) const;
	//durch den Standard Parameter ist keine weite funktion nötig
	//-> virtual void ostreamAusgabe(ostream& out) const;

protected:
	///Mögliche Maximalgeschwindigkeit des Fahrzeugs
	double p_dMaxGeschwindigkeit;
	///Bisher zurückgelegte Gesamtstrecke
	double p_dGesamtStrecke;
	///Gesamte Fahrzeit des Fahrzeugs
	double p_dGesamtZeit;
	///Zeitpunkt der letzten Abfertigung
	double p_dZeit;
private:
	/**
	  * @brief Initialisiert alles mit Standardwerten
	  */
	void p_vInitialisierung();
		
#ifdef DISABLE_COPY
	/**
	  * @brief Verhindere Benutzung operator =
	  * Private Funktion und nicht implementiert
	  */
	Fahrzeug(const Fahrzeug&);
	Fahrzeug& operator = (const Fahrzeug&);
#endif // ifdef DISABLE_COPY

	///Name des Fahrzeugs
	string p_sName;
	///ID des Objekts
	int p_iID;
	///Maximale Momentane ID
	static int p_iMaxID;
};

ostream& operator << (ostream& out, const Fahrzeug& f);
