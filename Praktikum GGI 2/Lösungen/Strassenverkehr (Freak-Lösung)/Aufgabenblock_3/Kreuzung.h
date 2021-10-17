#pragma once
#include "aktivesvo.h"
#include "Weg.h"
#include <list>

using namespace std;

class Weg;
class Fahrzeug;

class Kreuzung :
	public AktivesVO
{
public:
	// Konstruktoren:
	Kreuzung(void);
	Kreuzung(const string sName, const double dTankstelle = 0.0);
	// Destruktor:
	virtual ~Kreuzung(void);

	// Abfertigungsfunktion:
	virtual void vAbfertigung();

	// Fahrzeug annehmen:
	void vAnnahme(Fahrzeug* fFahrzeug, Weg* pHerkunft = NULL, Weg* pWeiterfahrt = NULL); // fahrend
	void vAnnahme(Fahrzeug* fFahrzeug, double dStartzeitpunkt, Weg* pWeiterfahrt = NULL); // parkend

	// zwei Kreuzungen mit einem neuen Weg verbinden:
	void vVerbinde(string sWegHin, string sWegZurueck, double dLaenge, 
		Kreuzung *pKreuzung, Begrenzung enumBegrenzung = Autobahn, bool bUeberholverbot = true);

	// tanken beim Vorbeifahren:
	void vTanken(Fahrzeug* fFahrzeug);
	
	// Ausgabefunktion:
	virtual ostream& ostreamAusgabe(ostream& ostreamStream);
	// Eingabe:
	istream& istreamEingabe(istream& istreamStream);

	// Neuer abgehender Weg:
	void vNeuerAbgehenderWeg(Weg *wWeg);

	// finde zufälligen Weg:
	Weg* pZufaelligerWeg(Weg* pHerkunft);

	// Getter:
	double getTankstelle();
private:
	double p_dTankstelle; // Tankinhalt der Tankstelle
	list<Weg*> p_pAbgehendeWege; // alle Wege, die von der Kreuzung wegführen
};

