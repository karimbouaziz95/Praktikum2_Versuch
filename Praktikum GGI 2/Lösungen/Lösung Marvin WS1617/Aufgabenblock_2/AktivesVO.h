// file:	AktivesVO.h
// author:	xxxxxx xxxxxx (xxxxxx)
// date:	07.09.2016

#pragma once

#include <string>

using namespace std;

// Die AktivesVO-Klasse bildet ein aktives Verkehrsobjekt abstrakt ab.
class AktivesVO
{

public:

	// Erstellt ein neues Verkehrsobjekt mit eindeutiger ID und leerem String als Namen.
	AktivesVO();

	// Kopier-Konstruktor. Erstellt ein neues Verkehrsobjekt nach Vorlage der rhs.
	AktivesVO(const AktivesVO& rhs);

	// Erstellt ein neues Verkehrsobjekt mit eindeutiger ID und einem Namen.
	AktivesVO(const string sName);

	// Standard-Destruktor
	virtual ~AktivesVO();

	// Die Ausgabefunktion gibt die Daten des Verkehrsobjektes auf cout aus.
	virtual void vAusgabe() const;

	// Diese Ausgabefunktion bildet die Basis für die Überladung des Stream-Operators.
	virtual ostream& ostreamAusgabe(ostream& out) const;

	// Die Abfertigungsfunktion ist vollständig virtuell und muss von den Subklassen überschrieben werden.
	virtual void vAbfertigung() = 0;

	// Getter für den Namen des Verkehrsobjektes.
	string getName();

	// Diese Operatorüberladung ermöglicht das direkte Zuweisen eines Verkehrsobjektes (assign).
	AktivesVO& operator = (const AktivesVO& rhs);

protected:

	// Eindeutige ID des Verkehrsobjektes.
	int p_iID;

	// Name des Verkehrsobjektes.
	string p_sName;

	// Zeitpunkt der letzten Abfertigung.
	double p_dZeit;

private:

	// Aktuell höchste vergebene ID eines Verkehrsobjektes
	static int p_iMaxID;

	// Initialisiert alle Membervariablen auf 0 bzw. "" und vergibt eindeutige IDs.
	void vInitialisierung();

};

// Die Operatorüberladung von << erlaubt die Ausgabe von Verkehrsobjekten über beliebige Streams.
ostream& operator << (ostream& out, const AktivesVO& vo);
