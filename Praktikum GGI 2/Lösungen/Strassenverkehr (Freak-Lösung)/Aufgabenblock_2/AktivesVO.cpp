#include "AktivesVO.h"

extern bool bEqualsAbout(double d1, double d2);

int AktivesVO::p_iMaxID = 0;

// Konstruktor:
AktivesVO::AktivesVO(void)
{
	vInitialisierung();
}

// Konstruktor:
AktivesVO::AktivesVO(const string sName)
{
	vInitialisierung();
	p_sName = sName;
}

AktivesVO::AktivesVO(const AktivesVO& aktVO) :
	p_sName(aktVO.p_sName + " (KOPIE)"), // Kopie im Namen erkenntlich machen
	p_dGesamtZeit(aktVO.p_dGesamtZeit),
	p_dZeit(aktVO.p_dZeit),
	p_iID(++p_iMaxID) // damit alle Instanzen voneinander zu unterscheiden sind, ID hochzählen!
{
}

// Destruktor:
AktivesVO::~AktivesVO(void)
{
}

// Initialisierung:
void AktivesVO::vInitialisierung()
{
	p_iID = ++p_iMaxID;
	p_sName = "";
	p_dGesamtZeit = 0;
	p_dZeit = 0;
}

// Getter:
string AktivesVO::getName() 
{
	return p_sName;
}

// neue Ausgabefunktion mit ostream:
ostream& AktivesVO::ostreamAusgabe(ostream& ostreamStream)
{
	ostreamStream.precision(2);
	ostreamStream << 
		// erste Spalte (ID) rechtsbündig:
		resetiosflags(ios::left) << setiosflags(ios::right) << 
		setw(2) << p_iID << "  " <<
		// zweite Spalte (Name) linksbündig:
		resetiosflags(ios::right) << setiosflags(ios::left) <<
		setw(13) << p_sName << ":  ";

	return ostreamStream;
}

// Abfertigungsfunktion
void AktivesVO::vAbfertigung()
{
	// falls das VO in diesem Abfertigungsschritt bereits abgefertigt wurde, abbrechen:
	if(bEqualsAbout(dGlobaleZeit, p_dZeit)) return;

	double dZeitDifferenz = dGlobaleZeit - p_dZeit;

	p_dGesamtZeit += dZeitDifferenz;
	p_dZeit = dGlobaleZeit;
}

// Streamoperator überladen (außerhalb der Klasse!):
ostream& operator<<(ostream& ostreamStream, AktivesVO& aktVO)
{
	aktVO.ostreamAusgabe(ostreamStream);
	return ostreamStream;
}