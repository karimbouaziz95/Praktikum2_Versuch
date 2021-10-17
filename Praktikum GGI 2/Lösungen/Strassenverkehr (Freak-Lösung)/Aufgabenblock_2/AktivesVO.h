#pragma once
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

extern double dGlobaleZeit;

// Aktives Verkehrsobjekt: abstrakte Oberklasse für Fahrzeuge und Wege
class AktivesVO
{
public:
	// Konstruktoren:
	AktivesVO(void);
	AktivesVO(const string sName);
	AktivesVO(const AktivesVO&); // Copykonstruktor
	virtual ~AktivesVO(void);

	// Ausgabefunktion:
	virtual ostream& ostreamAusgabe(ostream& ostreamStream);

	// Abfertigungsfunktion:
	virtual void vAbfertigung() = 0;

	// Getter:
	string getName();
protected:
	// Membervariablen:
	string p_sName;
	int p_iID;
	double p_dGesamtZeit;
	double p_dZeit; // Zeit, zu der das VO zuletzt abgefertigt wurde
private:
	// statische Klassenvariable:
	static int p_iMaxID;
	// Initialisierungsfunktion:
	void vInitialisierung();
};

// Streamoperator außerhalb der Klasse überladen
ostream& operator<<(ostream& ostreamStream, AktivesVO& aVO);
