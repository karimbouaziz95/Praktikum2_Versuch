#include "Weg.h"
#include "Fahrrad.h"
#include "LazyListe.h"

// Konstruktor:
Weg::Weg(void) :
	AktivesVO(),
	p_dLaenge(0),
	p_dLimit(Autobahn),
	p_bUeberholverbot(true),
	p_dSchranke(0),
	p_pRueckweg(NULL)
{
}

// Konstruktor:
Weg::Weg(const string sName, const double dLaenge, const double dLimit, const bool bUeberholverbot) :
	AktivesVO(sName),
	p_dLaenge(dLaenge),
	p_dLimit(dLimit),
	p_bUeberholverbot(bUeberholverbot),
	p_dSchranke(dLaenge),
	p_pRueckweg(NULL)
{
}

// Destruktor:
Weg::~Weg(void)
{
}

// Abfertigungsfunktion: fertigt alle Fahrzeuge auf dem Weg ab
void Weg::vAbfertigung()
{
	p_dSchranke = p_dLaenge;

	for(LazyListe<Fahrzeug*>::iterator it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++)
	{
		(*it)->vAbfertigung();

		// f¸r die Simulation: zeichnen!
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

// Abgabe eines Fahrzeugs (Fahrzeug verl‰sst Weg):
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

// LazyListe von auﬂen aus aktualisieren:
void Weg::vLazyListeAktualisieren()
{
	p_pFahrzeuge.vAktualisieren();
}

// neue Ausgabefunktion mit ostream:
ostream& Weg::ostreamAusgabe(ostream& ostreamStream)
{
	AktivesVO::ostreamAusgabe(ostreamStream) << "      " <<
		// dritte Spalte (L‰nge) rechtsb¸ndig mit 2 Nachkommastellen:
		setprecision(2) <<
		resetiosflags(ios::left) << setiosflags(ios::right) << 
		setw(6) << fixed << p_dLaenge << "km    ( ";

	// alle Fahrzeuge auf Weg auflisten:
	for(list<Fahrzeug*>::iterator it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++)
	{
		ostreamStream << (*it)->getName() << " ";
	}
	ostreamStream << ")";

	return ostreamStream;
}

// Eingabe:
istream& Weg::istreamEingabe(istream& istreamStream)
{
    AktivesVO::istreamEingabe(istreamStream);
 
    return istreamStream;
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
double Weg::getSchranke()
{
	if(p_bUeberholverbot)
		return p_dSchranke;
	else
		return p_dLaenge;
}
Weg* Weg::getRueckweg()
{
	return p_pRueckweg;
}
Kreuzung* Weg::getZiel()
{
	return p_pZiel;
}

// Setter:
void Weg::setSchranke(double dSchranke)
{
	p_dSchranke = dSchranke;
}
void Weg::setRueckweg(Weg *pRueckweg)
{
	p_pRueckweg = pRueckweg;
	if(pRueckweg->getRueckweg() == NULL)
		pRueckweg->setRueckweg(this);
}
void Weg::setZiel(Kreuzung *pZiel)
{
	p_pZiel = pZiel;
}