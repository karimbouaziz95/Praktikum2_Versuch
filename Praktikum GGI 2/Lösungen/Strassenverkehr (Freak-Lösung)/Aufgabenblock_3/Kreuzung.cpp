#include "Kreuzung.h"
#include "Weg.h"
#include "Fahrzeug.h"

extern bool bEqualsAbout(double d1, double d2);

// Konstruktor:
Kreuzung::Kreuzung(void) :
	AktivesVO(),
	p_dTankstelle(0.0)
{
}

// Konstruktor:
Kreuzung::Kreuzung(const string sName, const double dTankstelle) :
	AktivesVO(sName),
	p_dTankstelle(dTankstelle)
{
}

// Destruktor:
Kreuzung::~Kreuzung(void)
{
}

// Abfertigungsfunktion:
void Kreuzung::vAbfertigung()
{
	for(list<Weg*>::iterator it = p_pAbgehendeWege.begin(); it != p_pAbgehendeWege.end(); it++)
	{
		(*it)->vAbfertigung();
	}
}

// zwei Kreuzungen verbinden:
void Kreuzung::vVerbinde(string sWegHin, string sWegZurueck, double dLaenge, 
		Kreuzung *pKreuzung, Begrenzung enumBegrenzung, bool bUeberholverbot)
{
	Weg *wHin = new Weg(sWegHin, dLaenge, enumBegrenzung, bUeberholverbot);
	Weg *wZurueck = new Weg(sWegZurueck, dLaenge, enumBegrenzung, bUeberholverbot);

	// Rückweg setzen (nur in eine Richtung notwendig, Rest automatisch)
	wHin->setRueckweg(wZurueck);

	// Ziele der Wege setzen
	wZurueck->setZiel(this);
	wHin->setZiel(pKreuzung);

	// abgehenden Weg in Liste eintragen
	p_pAbgehendeWege.push_back(wHin);
	pKreuzung->vNeuerAbgehenderWeg(wZurueck);
}

void Kreuzung::vNeuerAbgehenderWeg(Weg *wWeg)
{
	p_pAbgehendeWege.push_back(wWeg);
}

// zufälligen Weg finden:
Weg* Kreuzung::pZufaelligerWeg(Weg* pHerkunft)
{
	// bei einer Sackgasse muss der gleiche Weg zurückgefahren werden:
	if(p_pAbgehendeWege.size() < 2) return pHerkunft->getRueckweg();

	// ansonsten suche zufällig einen anderen Weg:
	Weg* pZufWeg = NULL;
	do
	{
		srand((unsigned int)time(0));
		int iZufIndex = rand() % (p_pAbgehendeWege.size() - 1);
		list<Weg*>::iterator it = p_pAbgehendeWege.begin();
		for(int i = 0; i < iZufIndex; i++)	it++;

		if(*it == pHerkunft->getRueckweg()) it++;

		pZufWeg = *it;
	}
	while(pZufWeg == pHerkunft->getRueckweg());

	return pZufWeg;
}

// Fahrzeug annehmen (fahrend), dabei Tanken:
void Kreuzung::vAnnahme(Fahrzeug* fFahrzeug, Weg* pHerkunft, Weg* pWeiterfahrt)
{
	vTanken(fFahrzeug);

	if(pWeiterfahrt == NULL)
		if(pHerkunft == NULL)
			pWeiterfahrt = *(p_pAbgehendeWege.begin());
		else
			pWeiterfahrt = pZufaelligerWeg(pHerkunft);

	// auf den neuen Weg fahrend hinstellen:
	pWeiterfahrt->vAnnahme(fFahrzeug);
	fFahrzeug->vZeichnen();
	//pWeiterfahrt->vLazyListeAktualisieren();
}

// Fahrzeug annehmen (parkend), dabei Tanken:
void Kreuzung::vAnnahme(Fahrzeug* fFahrzeug, double dStartzeitpunkt, Weg* pWeiterfahrt)
{
	vTanken(fFahrzeug);

	if(pWeiterfahrt == NULL)
		pWeiterfahrt = *(p_pAbgehendeWege.begin());

	// auf den neuen Weg parkend hinstellen:
	pWeiterfahrt->vAnnahme(fFahrzeug, dStartzeitpunkt);
	pWeiterfahrt->vLazyListeAktualisieren();
}

// tanken:
void Kreuzung::vTanken(Fahrzeug *fFahrzeug)
{
	// Tanken überhaupt möglich?
	if(p_dTankstelle > 0.0)
	{
		p_dTankstelle -= fFahrzeug->dTanken();
		cout << "Inhalt der Tankstelle an " << p_sName << ": " << p_dTankstelle << "L" << endl;
	}
}

// neue Ausgabefunktion mit ostream:
ostream& Kreuzung::ostreamAusgabe(ostream& ostreamStream)
{
	AktivesVO::ostreamAusgabe(ostreamStream) << "      " <<
		// dritte Spalte (Tankstelleninhalt) rechtsbündig mit 2 Nachkommastellen:
		setprecision(2) <<
		resetiosflags(ios::left) << setiosflags(ios::right) << 
		setw(6) << fixed << p_dTankstelle << "L in Tankst." << endl << "      --> abgehende Wege:" << endl;

	// alle abgehenden Wege auflisten:
	for(list<Weg*>::iterator it = p_pAbgehendeWege.begin(); it != p_pAbgehendeWege.end(); it++)
	{
		ostreamStream << *(*it) << endl;
	}
	ostreamStream << endl;

	return ostreamStream;
}

// Eingabe:
istream& Kreuzung::istreamEingabe(istream& istreamStream)
{
    AktivesVO::istreamEingabe(istreamStream);
    istreamStream >> p_dTankstelle;
    return istreamStream;
}

// Getter:
double Kreuzung::getTankstelle()
{
	return p_dTankstelle;
}