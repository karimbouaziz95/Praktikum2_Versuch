// file:	Fahrzeug.h
// author:	xxxxxx xxxxxx (xxxxxx)
// date:	26.08.2016

#pragma once

#include <string>

using namespace std;

extern double dGlobaleZeit;
extern bool bEqual(double x, double y);

// Die Fahrzeug-Klasse bildet ein generisches Fahrzeug ab.
class Fahrzeug
{

public:

	// Erstellt ein neues Fahrzeug mit eindeutiger ID und leeren String als Namen.
	Fahrzeug();

	// Kopier-Konstruktor. Erstellt ein neues Fahrzeug nach Vorlage der rhs.
	Fahrzeug(const Fahrzeug& rhs);

	// Erstellt ein neues Fahrzeug mit eindeutiger ID und einem Namen.
	Fahrzeug(const string sName);

	// Erstellt ein neues Fahrzeug mit eindeutiger ID, dem Namen und der maximalen Geschwindigkeit.
	Fahrzeug(const string sName, const double dMaxGeschwindigkeit);

	// Standard-Destruktor.
	virtual ~Fahrzeug();

	// Die Ausgabefunktion gibt fahrzeugspezifische Daten auf cout aus.
	virtual void vAusgabe() const;

	// Diese Ausgabefunktion bildet die Basis für die Überladung des Stream-Operators.
	virtual ostream& ostreamAusgabe(ostream& out) const;

	// Die Abfertigungsfunktion lässt Fahrzeuge anhand der globalen Uhr fahren.
	virtual void vAbfertigung();

	// Diese Funktion betankt ein Fahrzeug und gibt die tatsächlich getankte Menge zurück.
	virtual double dTanken(double dMenge = -1.0);

	// Diese Funktion gibt die aktuelle Geschwindigkeit des Fahrzeuges zurück.
	virtual double dGeschwindigkeit() const;

	// Diese Operatorüberladung ermöglicht das direkte Zuweisen eines Fahrzeuges (assign).
	Fahrzeug& operator = (const Fahrzeug& rhs);

	// Diese Operatorüberladung ermöglicht den Vergleich zweier Fahrzeuge anhand der Gesamtfahrstrecke.
	bool operator < (const Fahrzeug& rhs) const;

	// Diese Funktion gibt einen Tabellenheader passend für die Ausgabefunktion aus.
	static void vHeaderAusgabe();

protected:

	// Eindeutige ID des Fahrzeugs.
	int p_iID;

	// Name des Fahrzeugs.
	string p_sName;

	// Maximale Geschwindigkeit, mit der das Fahrzeug fahren kann.
	double p_dMaxGeschwindigkeit;

	// Insgesamt vom Fahrzeug zurückgelegte Strecke.
	double p_dGesamtStrecke;

	// Gesamte Fahrzeit des Fahrzeugs.
	double p_dGesamtZeit;

	// Zeitpunkt der letzten Abfertigung.
	double p_dZeit;

private:

	// Aktuell höchste vergebene ID eines Fahrzeuges.
	static int p_iMaxID;

	// Initialisiert alle Membervariablen auf 0 bzw. "" und vergibt eindeutige IDs.
	void vInitialisierung();

};

// Die Operatorüberladung von << erlaubt die Ausgabe von Fahrzeugen über beliebige Streams.
ostream& operator << (ostream& out, const Fahrzeug& fzg);

/************************************************************************************/
/* ======== Informationen zum Kopierkonstruktor und dem Zuweisungsoperator ======== */
/* Der Kopierkonstruktor erstellt ein neues Fahrzeug mit eigenen (neuen) ID und     */
/* initialisierten Membervariablen, wovon nur der Name und die max. Geschwindigkeit */
/* vom ursprünglichen Fahrzeug übernommen werden. Denn die anderen Membervariablen  */
/* p_dGesamtStrecke, p_dGesamtZeit, p_dZeit sind sinnvollerweise null, da das       */
/* noch nicht abgefertigt wurde.                                                    */
/* Der Zuweisungsoperator wird äquivalent implementiert, sodass das Verhalten       */
/* unabhängig davon ist, ob intern der Kopierkonstruktor oder der Zuweisungsoperator*/
/* verwendet wurde. Es ist sichergestellt, dass jede ID absolut eindeutig ist.      */
/************************************************************************************/
