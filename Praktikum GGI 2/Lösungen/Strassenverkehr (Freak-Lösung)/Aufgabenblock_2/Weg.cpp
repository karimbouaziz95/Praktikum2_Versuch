#include "Weg.h"
#include "Fahrrad.h"
#include "LazyListe.h"

// Konstruktor:
Weg::Weg(void) :
	AktivesVO(),
	p_dLaenge(0),
	p_dLimit(Autobahn)
{
}

// Konstruktor:
Weg::Weg(const string sName, const double dLaenge, const double dLimit) :
	AktivesVO(sName),
	p_dLaenge(dLaenge),
	p_dLimit(dLimit)
{
}

// Destruktor:
Weg::~Weg(void)
{
}

// Abfertigungsfunktion: fertigt alle Fahrzeuge auf dem Weg ab
void Weg::vAbfertigung()
{
	for(LazyListe<Fahrzeug*>::iterator it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++)
	{
		(*it)->vAbfertigung();
		// für die Simulation: zeichnen!
		(*it)->vZeichnen();
	}
	p_pFahrzeuge.vAktualisieren();
}

// Annahme eines Fahrzeugs: fahrend
void Weg::vAnnahme(Fahrzeug *fFahrzeug)
{
	p_pFahrzeuge.push_back(fFahrzeug);
	fFahrzeug->vNeueStrecke(this);
}
// Annahme eines Fahrzeugs: parkend
void Weg::vAnnahme(Fahrzeug *fFahrzeug, const double dStartzeitpunkt)
{
	p_pFahrzeuge.push_front(fFahrzeug);
	fFahrzeug->vNeueStrecke(this, dStartzeitpunkt);
}

// Abgabe eines Fahrzeugs (Fahrzeug verlässt Weg):
void Weg::vAbgabe(Fahrzeug *fFahrzeug)
{
	for(LazyListe<Fahrzeug*>::iterator it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++)
	{
		if(*it == fFahrzeug) 
		{
			p_pFahrzeuge.erase(it);
			break;
		}
	}
}

// neue Ausgabefunktion mit ostream:
ostream& Weg::ostreamAusgabe(ostream& ostreamStream)
{
	AktivesVO::ostreamAusgabe(ostreamStream) << "                     " <<
		// dritte Spalte (Länge) rechtsbündig mit 2 Nachkommastellen:
		setprecision(2) <<
		resetiosflags(ios::left) << setiosflags(ios::right) << 
		setw(6) << fixed << p_dLaenge << "      ( ";

	// alle Fahrzeuge auf Weg auflisten:
	for(list<Fahrzeug*>::iterator it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++)
	{
		ostreamStream << (*it)->getName() << " ";
	}
	ostreamStream << ")";

	return ostreamStream;
}

// Getter:
double Weg::getLaenge()
{
	return p_dLaenge;
}
double Weg::getLimit()
{
	return p_dLimit;
}