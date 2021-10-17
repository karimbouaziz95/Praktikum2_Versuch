#include "AktivesVO.h"

extern bool bEqualsAbout(double d1, double d2);

int AktivesVO::p_iMaxID = 0;
map<string, AktivesVO*> AktivesVO::p_mapVO;

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

	// �berpr�fe, ob ein VO mit diesem Namen bereits existiert:
	if(p_mapVO.find(p_sName) == p_mapVO.end())
    {
		// nicht gefunden: f�ge neues VO in map ein
        p_mapVO[p_sName] = this;
    }
    else if(p_sName != "")
    {
            throw new string("Es gibt bereits ein VO mit dem Namen: " + p_sName);
    }
}

AktivesVO::AktivesVO(const AktivesVO& aktVO) :
	p_sName(aktVO.p_sName + " (KOPIE)"), // Kopie im Namen erkenntlich machen
	p_dGesamtZeit(aktVO.p_dGesamtZeit),
	p_dZeit(aktVO.p_dZeit),
	p_iID(++p_iMaxID) // damit alle Instanzen voneinander zu unterscheiden sind, ID hochz�hlen!
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
		// erste Spalte (ID) rechtsb�ndig:
		resetiosflags(ios::left) << setiosflags(ios::right) << 
		setw(2) << p_iID << "  " <<
		// zweite Spalte (Name) linksb�ndig:
		resetiosflags(ios::right) << setiosflags(ios::left) <<
		setw(13) << p_sName << ":  ";

	return ostreamStream;
}

// Eingabefunktion:
istream& AktivesVO::istreamEingabe(istream& istreamStream)
{
	if(p_sName == "")
	{
		istreamStream >> p_sName;

		// �berpr�fe, ob bereits ein VO mit diesem Namen existiert:
		if(p_mapVO.find(p_sName) == p_mapVO.end())
        {
			// nicht gefunden: f�ge dieses VO neu hinzu
            p_mapVO[p_sName] = this;
        }
        else
        {
            throw new string("Es gibt bereits ein VO mit dem Namen: " + p_sName);
        }
	}
	else
	{
		throw new string("Objekt hat schon einen Namen!");
	}

	return istreamStream;
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

// STATISCHE FUNKTION: liefert Pointer von VO anhand eines Strings (Name):
AktivesVO* AktivesVO::ptObjekt(string sName)
{
	// Suche anhand des Strings in der map:
	map<string, AktivesVO*>::iterator it = p_mapVO.find(sName);

	// �berpr�fe, ob etwas gefunden wurde:
    if(it == p_mapVO.end())
    {
        throw new string("Es gibt kein VO mit Namen: " + sName);
    }
    else
    {
		// Pointer des gefundenen VOs zur�ckgeben:
        return it->second;
    }
}

// Streamoperator �berladen (au�erhalb der Klasse!):
ostream& operator<<(ostream& ostreamStream, AktivesVO& aktVO)
{
	aktVO.ostreamAusgabe(ostreamStream);
	return ostreamStream;
}
istream& operator>>(istream& istreamStream, AktivesVO& aktVO)
{
	aktVO.istreamEingabe(istreamStream);
	return istreamStream;
}