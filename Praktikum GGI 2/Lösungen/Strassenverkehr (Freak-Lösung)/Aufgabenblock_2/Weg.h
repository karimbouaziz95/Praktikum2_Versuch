#pragma once
#include "aktivesvo.h"
#include <list>
#include "LazyListe.h"

using namespace std;

class Fahrzeug;

// maximale Geschwindigkeiten festlegen:
enum Begrenzung {
	Innerorts = 50,
	Landstrasse = 100,
	Autobahn = -1		// unbegrenzt
};

class Weg :
	public AktivesVO
{
public:
	// Konstruktoren
	Weg(void);
	Weg(const string sName, const double dLaenge, const double dLimit = Autobahn);
	Weg(const Weg&); // Copykonstruktor
	// Destruktor
	virtual ~Weg(void);

	// Abfertigungsfunktion:
	virtual void vAbfertigung();

	// Annahme:
	void vAnnahme(Fahrzeug *fFahrzeug);
	void vAnnahme(Fahrzeug *fFahrzeug, const double dStartzeitpunkt);
	// Abgabe:
	void vAbgabe(Fahrzeug *fFahrzeug);
	
	// Ausgabefunktion:
	virtual ostream& ostreamAusgabe(ostream& ostreamStream);

	// Getter:
	double getLaenge();
	double getLimit();
protected:
	double p_dLaenge;	// Länge des Wegs in km
	double p_dLimit;	// max. Geschwindigkeit, festgelegt durch "enum Begrenzung"

	// alle Fahrzeuge auf dem Weg (LazyListe, wird erst nach kompletter Abfertigung aktualisiert)
	LazyListe<Fahrzeug*> p_pFahrzeuge;
};

