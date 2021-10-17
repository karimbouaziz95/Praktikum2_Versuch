#include "Fahrzeug.h"
#include "FzgFahren.h"
#include "FzgParken.h"
#include "FahrAusnahme.h"
#include "Weg.h"

extern bool bEqualsAbout(double d1, double d2);

// Konstruktor:
Fahrzeug::Fahrzeug(void) :
	AktivesVO()
{
	vInitialisierung();
}

// Konstruktor:
Fahrzeug::Fahrzeug(const string sName) :
	AktivesVO(sName)
{
	vInitialisierung();
}

// Konstruktor:
Fahrzeug::Fahrzeug(const string sName, const double dMaxGeschwindigkeit) :
	AktivesVO(sName)
{
	vInitialisierung();
	p_dMaxGeschwindigkeit = dMaxGeschwindigkeit;
}

// Copykonstruktor
Fahrzeug::Fahrzeug(const Fahrzeug& fFahrzeug) :
	AktivesVO(fFahrzeug),
	p_dGesamtStrecke(fFahrzeug.p_dGesamtStrecke),				//  \ Neues Objekt ist eine Kopie, deshalb werden
	p_dAbschnittStrecke(fFahrzeug.p_dAbschnittStrecke),			//   >
	p_dMaxGeschwindigkeit(fFahrzeug.p_dMaxGeschwindigkeit)		//	/ alle Eigenschaften übernommen
{
}

// Destruktor:
Fahrzeug::~Fahrzeug(void)
{
}

// Initialisierung: Member nullen und ID setzen
void Fahrzeug::vInitialisierung()
{
	p_dGesamtStrecke = 0;
	p_dMaxGeschwindigkeit = 0;
	p_dAbschnittStrecke = 0;
	p_pVerhalten = NULL;
}

// alte Ausgabefunktion:
void Fahrzeug::vAusgabe()
{
	cout.precision(2);
	cout << 
		// erste Spalte (ID) rechtsbündig:
		resetiosflags(ios::left) << setiosflags(ios::right) << 
		setw(2) << p_iID << "  " <<
		// zweite Spalte (Name) linksbündig:
		resetiosflags(ios::right) << setiosflags(ios::left) <<
		setw(13) << p_sName << ":  " <<
		// dritte Spalte (MaxKmh) rechtsbündig mit 2 Nachkommastellen:
		setprecision(2) <<
		resetiosflags(ios::left) << setiosflags(ios::right) << 
		setw(6) << fixed << p_dMaxGeschwindigkeit << "  " <<
		// vierte Spalte (AktKmh) rechtsbündig mit 2 Nachkommastellen:
		setw(6) << dGeschwindigkeit() << "  " <<
		// fünfte Spalte (GesamtStrecke) rechtsbündig mit 2 Nachkommastellen:
		setw(11) << p_dGesamtStrecke;
		
}

// neue Ausgabefunktion mit ostream:
ostream& Fahrzeug::ostreamAusgabe(ostream& ostreamStream)
{
	AktivesVO::ostreamAusgabe(ostreamStream) <<
		// dritte Spalte (MaxKmh) rechtsbündig mit 2 Nachkommastellen:
		setprecision(2) <<
		resetiosflags(ios::left) << setiosflags(ios::right) << 
		setw(6) << fixed << p_dMaxGeschwindigkeit << "  " <<
		// vierte Spalte (AktKmh) rechtsbündig mit 2 Nachkommastellen:
		setw(6) << dGeschwindigkeit() << "  " <<
		// fünfte Spalte (GesamtStrecke) rechtsbündig mit 2 Nachkommastellen:
		setw(11) << p_dGesamtStrecke;

	return ostreamStream;
}

// Eingabe:
istream& Fahrzeug::istreamEingabe(istream& istreamStream)
{
    AktivesVO::istreamEingabe(istreamStream);
    istreamStream >> p_dMaxGeschwindigkeit;
    return istreamStream;
}

// Abfertigungsfunktion (für jedes Fahrzeug!):
void Fahrzeug::vAbfertigung()
{
	double dZeitVorher = p_dZeit;

	AktivesVO::vAbfertigung();

	double dZeitDifferenz = p_dZeit - dZeitVorher;

	// try catch behandelt zwei Ausnahmefälle:
	// 1) Fahrzeug parkt und soll nun losfahren
	// 2) Fahrzeug erreicht das Streckenende
	try
	{
		// fahrbare Strecke:
		double dFahrbareStrecke = p_pVerhalten->dStrecke(this, dZeitDifferenz);

		p_dGesamtStrecke += dFahrbareStrecke;
		p_dAbschnittStrecke += dFahrbareStrecke;

		// setze virtuelle Schranke neu, aber nur, wenn der Wagen sich überhaupt fortbewegt hat
		// (sonst hat er einen leeren Tank und kann überholt werden):
		if(!bEqualsAbout(dFahrbareStrecke, 0.0))
		{
			p_pVerhalten->getWeg()->setSchranke(p_dAbschnittStrecke);
		}
	}
	catch(FahrAusnahme *pAusnahme)
	{
		pAusnahme->vBearbeiten();
	}
}

// Neuer Weg: fahrendes Fahrzeug
void Fahrzeug::vNeueStrecke(Weg *wWeg)
{
	if(p_pVerhalten != NULL)
		delete p_pVerhalten;

	p_pVerhalten = new FzgFahren(wWeg);
	p_dAbschnittStrecke = 0;
}

// Neuer Weg: parkendes Fahrzeug
void Fahrzeug::vNeueStrecke(Weg *wWeg, const double dStartzeitpunkt)
{
	if(p_pVerhalten != NULL)
		delete p_pVerhalten;

	p_pVerhalten = new FzgParken(wWeg, dStartzeitpunkt);
	p_dAbschnittStrecke = 0;
}

// Tanken:
double Fahrzeug::dTanken(double dMenge)
{
	return 0;
}

// Getter:
double Fahrzeug::getAbschnittStrecke()
{
	return p_dAbschnittStrecke;
}
double Fahrzeug::getGeschwindigkeit()
{
	return dGeschwindigkeit();
}
Weg* Fahrzeug::getWeg()
{
	Weg* wWeg = p_pVerhalten->getWeg();
	return wWeg;
}

// Operatorüberladungen:
bool Fahrzeug::operator<(const Fahrzeug& fFahrzeug)
{
	return p_dGesamtStrecke < fFahrzeug.p_dGesamtStrecke;
}
bool Fahrzeug::operator>(const Fahrzeug& fFahrzeug)
{
	return p_dGesamtStrecke > fFahrzeug.p_dGesamtStrecke;
}
bool Fahrzeug::operator==(const Fahrzeug& fFahrzeug)
{
	return bEqualsAbout(p_dGesamtStrecke, fFahrzeug.p_dGesamtStrecke);
}

// Zuweisungsoperator überladen
// dabei werden die folgenden Member klassisch kopiert,
// aber die ID und der Name nicht.
// So werden quasi nur die technischen Daten des Fahrzeugs auf ein anderes übertragen.
Fahrzeug& Fahrzeug::operator=(const Fahrzeug& fFahrzeug)
{
    p_dGesamtStrecke = fFahrzeug.p_dGesamtStrecke;
	p_dAbschnittStrecke = fFahrzeug.p_dAbschnittStrecke;
    p_dGesamtZeit = fFahrzeug.p_dGesamtZeit;
	p_dMaxGeschwindigkeit = fFahrzeug.p_dMaxGeschwindigkeit;
    p_dZeit = fFahrzeug.p_dZeit;

	return *this;
}

// Streamoperator überladen (außerhalb der Klasse!):
/*ostream& operator<<(ostream& ostreamStream, Fahrzeug& fFahrzeug)
{
	fFahrzeug.ostreamAusgabe(ostreamStream);
	return ostreamStream;
}*/