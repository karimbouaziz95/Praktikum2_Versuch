#include "Weg.h"
#include "Fahrzeug.h"
#include "FzgFahren.h"
#include "FzgParken.h"
#include "FahrAusnahme.h"
#include "FzgVerhalten.h"

Weg::Weg(void)
{
    vInitialisierung();
}

Weg::Weg(string sName, double dLaenge, Begrenzung Limit)
{
    vInitialisierung();
	p_sName = sName;
	p_dLaenge = dLaenge;
	p_eLimit = Limit;
}

Weg::~Weg(void)
{
}

void Weg::vInitialisierung()
{
    AktivesVO::vInitialisierung();
    p_dLaenge = 0.0;
    p_eLimit = Autobahn;
}

void Weg::vAbfertigung()
{
	//Abfertigung aller Listenelemente nacheinander
	LazyListe<Fahrzeug*>::iterator  it;
	for (it = p_pFahrzeuge.begin();it != p_pFahrzeuge.end(); it++)
    {
		//Fangen der Exceptions
        try
        {
            (*it)->vAbfertigung();
            cout << **it << endl;
        }
        catch(FahrAusnahme* pFahrAusname)
        {
            pFahrAusname->vBearbeiten();
        }
    }
	p_pFahrzeuge.vAktualisieren();
}

ostream& Weg::ostreamAusgabe(ostream& Stream)
{
    LazyListe<Fahrzeug*>::iterator  it;
    
    AktivesVO::ostreamAusgabe(Stream);
	Stream << setw(6) << setiosflags(ios::left) << p_dLaenge << "( ";
    
	//Ausgabe der Fahrzeuge auf dem Weg
    for (it = p_pFahrzeuge.begin();it != p_pFahrzeuge.end(); it++)
	{
		Stream << setw(9) << setiosflags(ios::left) << (*it)->sGetName();
	}      
	
    Stream << " )" << endl;
    return Stream;
}

double Weg::dGetLaenge()
{
    return p_dLaenge;
}

Begrenzung Weg::eGetLimit()
{
    return p_eLimit;
}

//Überladene Annahme, setzt fahrende/parkende Fahrzeuge auf den Weg, weist Fahrzeug ein "Verhaltensobjekt" zu

void Weg::vAnnahme(Fahrzeug *pFahrzeug)
{
    pFahrzeug->vNeueStrecke(this, new FzgFahren(this));
	p_pFahrzeuge.push_back(pFahrzeug);
}

void Weg::vAnnahme(Fahrzeug *pFahrzeug, double dStartzeit)
{
    pFahrzeug->vNeueStrecke(this, new FzgParken(this, dStartzeit));
	p_pFahrzeuge.push_front(pFahrzeug);
}

//löscht Fahrzeug aus der Liste des Weges

void Weg::vAbgabe(Fahrzeug* pFahrzeug)
{
	for (list<Fahrzeug*>::iterator  it = p_pFahrzeuge.begin(); it != p_pFahrzeuge.end(); it++)
	{
		if(*it == pFahrzeug)
		{
			p_pFahrzeuge.erase(it);
		}
	}
}