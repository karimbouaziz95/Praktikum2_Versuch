#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include "AktivesVO.h"

using namespace std;

extern double dGlobaleZeit;

class FzgVerhalten;
class Weg;

class Fahrzeug : 
	public AktivesVO
{
public:
	// Konstruktoren:
	Fahrzeug(void);
	Fahrzeug(const string sName);
	Fahrzeug(const string sName, const double dMaxGeschwindigkeit);
	Fahrzeug(const Fahrzeug&); // Copykonstruktor
	// Destruktor:
	virtual ~Fahrzeug(void);

	// Ausgabefunktionen:
	virtual void vAusgabe();
	virtual ostream& ostreamAusgabe(ostream& ostreamStream);
	// Eingabe:
	virtual istream& istreamEingabe(istream& istreamStream);

	// Abfertigungsfunktion:
	virtual void vAbfertigung();

	// neuer Weg:
	void vNeueStrecke(Weg *wWeg);
	void vNeueStrecke(Weg *wWeg, const double dStartzeitpunkt);

	// Tanken
	// default-Menge 1000 garantiert Volltanken
	virtual double dTanken(const double dMenge = 1000);

	// Vergleichsoperatoren überladen:
	// Vergleich der Gesamtstrecken
	bool operator<(const Fahrzeug& fFahrzeug);
	bool operator>(const Fahrzeug& fFahrzeug);
	bool operator==(const Fahrzeug& fFahrzeug);

	// Zuweisungsoperator überladen:
	Fahrzeug& operator=(const Fahrzeug&);

	// Getter:
	double getAbschnittStrecke();
	double getGeschwindigkeit();
	Weg* getWeg();

	// akt. Geschw.:
	virtual double dGeschwindigkeit() = 0;

	// Zeichnen:
	virtual void vZeichnen() = 0;
protected:
	// Membervariablen:
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dAbschnittStrecke;
	FzgVerhalten *p_pVerhalten;
private:
	// Initialisierungsfunktion:
	void vInitialisierung();
};

// Streamoperator außerhalb der Klasse überladen
//ostream& operator<<(ostream& ostreamStream, Fahrzeug& fFahrzeug);