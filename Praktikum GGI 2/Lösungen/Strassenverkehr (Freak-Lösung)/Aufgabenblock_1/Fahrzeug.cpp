#include "Fahrzeug.h"

extern bool bEqualsAbout(double d1, double d2);

int Fahrzeug::p_iMaxID = 0;

// Konstruktor:
Fahrzeug::Fahrzeug(void)
{
	vInitialisierung();
}

// Konstruktor:
Fahrzeug::Fahrzeug(const string sName)
{
	vInitialisierung();
	p_sName = sName;
}

// Konstruktor:
Fahrzeug::Fahrzeug(const string sName, const double dMaxGeschwindigkeit)
{
	vInitialisierung();
	p_sName = sName;
	p_dMaxGeschwindigkeit = dMaxGeschwindigkeit;
}

// Copykonstruktor
Fahrzeug::Fahrzeug(const Fahrzeug& fFahrzeug) :
	p_dGesamtStrecke(fFahrzeug.p_dGesamtStrecke),				// \  
	p_dGesamtZeit(fFahrzeug.p_dGesamtZeit),						//  \ Neues Objekt ist eine Kopie, deshalb werden
	p_dMaxGeschwindigkeit(fFahrzeug.p_dMaxGeschwindigkeit),		//	/ alle Eigenschaften �bernommen
	p_dZeit(fFahrzeug.p_dZeit),									// /  
	p_sName(fFahrzeug.p_sName + " (KOPIE)"), // Kopie im Namen erkenntlich machen
	p_iID(++p_iMaxID) // damit alle Instanzen voneinander zu unterscheiden sind, ID hochz�hlen!
{

}

// Destruktor:
Fahrzeug::~Fahrzeug(void)
{
	// cout << "Destruktor meldet: Name: " << p_sName << ", ID: " << p_iID << endl;
}

// Initialisierung: Member nullen und ID setzen
void Fahrzeug::vInitialisierung()
{
	p_iID = ++p_iMaxID;
	p_sName = "";
	p_dGesamtStrecke = 0;
	p_dGesamtZeit = 0;
	p_dMaxGeschwindigkeit = 0;
	p_dZeit = 0;

	// cout << "Konstruktor meldet: Name: " << p_sName << ", ID: " << p_iID << endl;

}

// alte Ausgabefunktion:
void Fahrzeug::vAusgabe()
{
	cout.precision(2);
	cout << 
		// erste Spalte (ID) rechtsb�ndig:
		resetiosflags(ios::left) << setiosflags(ios::right) << 
		setw(2) << p_iID << "  " <<
		// zweite Spalte (Name) linksb�ndig:
		resetiosflags(ios::right) << setiosflags(ios::left) <<
		setw(13) << p_sName << ":  " <<
		// dritte Spalte (MaxKmh) rechtsb�ndig mit 2 Nachkommastellen:
		setprecision(2) <<
		resetiosflags(ios::left) << setiosflags(ios::right) << 
		setw(6) << fixed << p_dMaxGeschwindigkeit << "  " <<
		// vierte Spalte (AktKmh) rechtsb�ndig mit 2 Nachkommastellen:
		setw(6) << dGeschwindigkeit() << "  " <<
		// f�nfte Spalte (GesamtStrecke) rechtsb�ndig mit 2 Nachkommastellen:
		setw(11) << p_dGesamtStrecke;
		
}

// neue Ausgabefunktion mit ostream:
ostream& Fahrzeug::ostreamAusgabe(ostream& ostreamStream)
{
	ostreamStream.precision(2);
	ostreamStream << 
		// erste Spalte (ID) rechtsb�ndig:
		resetiosflags(ios::left) << setiosflags(ios::right) << 
		setw(2) << p_iID << "  " <<
		// zweite Spalte (Name) linksb�ndig:
		resetiosflags(ios::right) << setiosflags(ios::left) <<
		setw(13) << p_sName << ":  " <<
		// dritte Spalte (MaxKmh) rechtsb�ndig mit 2 Nachkommastellen:
		setprecision(2) <<
		resetiosflags(ios::left) << setiosflags(ios::right) << 
		setw(6) << fixed << p_dMaxGeschwindigkeit << "  " <<
		// vierte Spalte (AktKmh) rechtsb�ndig mit 2 Nachkommastellen:
		setw(6) << dGeschwindigkeit() << "  " <<
		// f�nfte Spalte (GesamtStrecke) rechtsb�ndig mit 2 Nachkommastellen:
		setw(11) << p_dGesamtStrecke;

	return ostreamStream;
}

// Abfertigungsfunktion (f�r jedes Fahrzeug!):
void Fahrzeug::vAbfertigung()
{
	// falls das Fahrzeug in diesem Abfertigungsschritt bereits abgefertigt wurde, abbrechen:
	if(bEqualsAbout(dGlobaleZeit, p_dZeit)) return;

	double dZeitDifferenz = dGlobaleZeit - p_dZeit;

	p_dGesamtZeit += dZeitDifferenz;
	p_dZeit = dGlobaleZeit;

	// s = t * v
	p_dGesamtStrecke += dZeitDifferenz * dGeschwindigkeit();
}

// Operator�berladungen:
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

// Zuweisungsoperator �berladen
// dabei werden die folgenden Member klassisch kopiert,
// aber die ID und der Name nicht.
// So werden quasi nur die technischen Daten des Fahrzeugs auf ein anderes �bertragen.
Fahrzeug& Fahrzeug::operator=(const Fahrzeug& fFahrzeug)
{
    p_dGesamtStrecke = fFahrzeug.p_dGesamtStrecke;
    p_dGesamtZeit = fFahrzeug.p_dGesamtZeit;
	p_dMaxGeschwindigkeit = fFahrzeug.p_dMaxGeschwindigkeit;
    p_dZeit = fFahrzeug.p_dZeit;

	return *this;
}

// Streamoperator �berladen (au�erhalb der Klasse!):
ostream& operator<<(ostream& ostreamStream, Fahrzeug& fFahrzeug)
{
	fFahrzeug.ostreamAusgabe(ostreamStream);
	return ostreamStream;
}