#pragma once
#include "aktivesvo.h"
#include <list>
#include "LazyListe.h"

using namespace std;

class Fahrzeug;
class Kreuzung;

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
	Weg(const string sName, const double dLaenge, const double dLimit = Autobahn, const bool bUeberholverbot = true);
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
	// Eingabe:
	virtual istream& istreamEingabe(istream& istreamStream);

	// Getter:
	double getLaenge();
	double getLimit();
	double getSchranke();
	Weg* getRueckweg();
	Kreuzung* getZiel();
	void setSchranke(double dSchranke);
	void setRueckweg(Weg *pRueckweg);
	void setZiel(Kreuzung *pKreuzung);

	// LazyListe von auﬂerhalb aktualisieren
	void vLazyListeAktualisieren();
private:
	double p_dLaenge;	// L‰nge des Wegs in km
	double p_dLimit;	// max. Geschwindigkeit, festgelegt durch "enum Begrenzung"
	bool p_bUeberholverbot; // ‹berholverbot
	double p_dSchranke;
	Weg *p_pRueckweg;
	Kreuzung *p_pZiel;

	// alle Fahrzeuge auf dem Weg (LazyListe, wird erst nach kompletter Abfertigung aktualisiert)
	LazyListe<Fahrzeug*> p_pFahrzeuge;
};

