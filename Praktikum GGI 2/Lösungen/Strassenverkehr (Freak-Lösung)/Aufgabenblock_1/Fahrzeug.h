#pragma once
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

extern double dGlobaleZeit;

class Fahrzeug
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

	// Abfertigungsfunktion:
	virtual void vAbfertigung();

	// Tanken (abstrakt!)
	// default-Menge 1000 garantiert Volltanken
	virtual double dTanken(const double dMenge = 1000) = 0;

	// Vergleichsoperatoren überladen:
	// Vergleich der Gesamtstrecken
	bool operator<(const Fahrzeug& fFahrzeug);
	bool operator>(const Fahrzeug& fFahrzeug);
	bool operator==(const Fahrzeug& fFahrzeug);

	// Zuweisungsoperator überladen:
	Fahrzeug& operator=(const Fahrzeug&);
protected:
	// Membervariablen:
	string p_sName;
	int p_iID;
	double p_dMaxGeschwindigkeit;
	double p_dGesamtStrecke;
	double p_dGesamtZeit;
	double p_dZeit; // Zeit, zu der das Fahrzeug zuletzt abgefertigt wurde
	// akt. Geschw.:
	virtual double dGeschwindigkeit() = 0;
private:
	// statische Klassenvariable:
	static int p_iMaxID;
	// Initialisierungsfunktion:
	void vInitialisierung();
};

// Streamoperator außerhalb der Klasse überladen
ostream& operator<<(ostream& ostreamStream, Fahrzeug& fFahrzeug);