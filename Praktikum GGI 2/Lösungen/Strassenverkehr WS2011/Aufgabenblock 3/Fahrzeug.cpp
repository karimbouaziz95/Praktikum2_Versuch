#include "Fahrzeug.h"
#include "AktivesVO.h"
#include "FzgVerhalten.h"
#include "Weg.h"
#include "FzgParken.h"
#include "FzgFahren.h"
#include "math.h"

Fahrzeug::Fahrzeug(void)
{
	vInitialisierung();
	p_sName = "";
	//cout << "Standardkonstruktor" << endl;
}

Fahrzeug::Fahrzeug(string sName)
{
	vInitialisierung();
	p_sName = sName;
	//cout << "Konstruktor:" << p_sName << endl;
}

Fahrzeug::Fahrzeug(string sName, double dMaxGeschwindigkeit)
{
	vInitialisierung();
	p_sName = sName;
	p_dMaxGeschwindigkeit = dMaxGeschwindigkeit;
	//cout << "Konstruktor:" << p_sName << endl;
}

Fahrzeug::~Fahrzeug(void)
{
	//cout << "Destruktor:" << p_sName << endl;
	p_iID = 0 ;
	p_sName = "";
}

void Fahrzeug::vInitialisierung(void)
{
    AktivesVO::vInitialisierung();
	p_dMaxGeschwindigkeit = 0;
	p_dGesamtStrecke = 0;
	p_dAbschnittStrecke = 0;
    p_pVerhalten = NULL;
}

void Fahrzeug::vAusgabe(void)
{
	cout << setw(4) << setiosflags(ios::left) << p_iID 
		 << setw(12) << setiosflags(ios::left) << p_sName 
		 << setw(3) << setiosflags(ios::left) << ":" 
		 << setw(17) << setiosflags(ios::left) << setiosflags(ios::fixed) << setprecision(2) << dGeschwindigkeit()  
		 << setw(16) << setiosflags(ios::left) << setiosflags(ios::fixed) << setprecision(2) << p_dGesamtStrecke;
}

void Fahrzeug::vAbfertigung(void)
{
	extern double dGlobaleZeit;
	extern double dZeitschritt;
	//Abfertigung nur wenn verstrichene Zeit seit letzter Abfertigung mindestens einen Zeitschritt groß ist.

    
	if(fabs(dGlobaleZeit-p_dZeit-dZeitschritt)>=0)
	{
        double dStrecke;
        double dZeitIntervall;
        
        dZeitIntervall = dGlobaleZeit-p_dZeit;
		dStrecke = p_pVerhalten->dStrecke(this, dZeitIntervall);
        
        p_dAbschnittStrecke += dStrecke;
		p_dGesamtStrecke += dStrecke;  
		p_dGesamtZeit += (dGlobaleZeit-p_dZeit);						//Gesamtzeit += verstrichene Zeit
		p_dZeit = dGlobaleZeit;											//Zeitpunkt des letzten Abfertigen
	}
}

double Fahrzeug::dGeschwindigkeit()
{
	return p_dMaxGeschwindigkeit;
}

double Fahrzeug::dTanken(double dMenge)
{
	return 0.0;
}

ostream& Fahrzeug::ostreamAusgabe(ostream& Stream)
{
	AktivesVO::ostreamAusgabe(Stream) 
									<< setw(3) << setiosflags(ios::left) << ":"
									<< setw(17) << setiosflags(ios::left) << setiosflags(ios::fixed) << setprecision(2) << dGeschwindigkeit()  
									<< setw(16) << setiosflags(ios::left) << setiosflags(ios::fixed) << setprecision(2) << p_dGesamtStrecke 
									<< setw(16) << setiosflags(ios::left) << setiosflags(ios::fixed) << setprecision(2) << p_dAbschnittStrecke;
	return Stream;
}

bool Fahrzeug::operator<(const Fahrzeug& fVergleichsFahrzeug)
{
	if (this->p_dGesamtStrecke < fVergleichsFahrzeug.p_dGesamtStrecke)
		return true;
	else
		return false;
}

void Fahrzeug::operator=(const Fahrzeug& fVergleichsFahrzeug)
{
	this->p_dGesamtStrecke = fVergleichsFahrzeug.p_dGesamtStrecke;
	this->p_dMaxGeschwindigkeit = fVergleichsFahrzeug.p_dMaxGeschwindigkeit;
	this->p_dGesamtZeit = fVergleichsFahrzeug.p_dGesamtZeit;
	this->p_dZeit = fVergleichsFahrzeug.p_dZeit;
	this->p_sName = "n" + fVergleichsFahrzeug.p_sName;
	this->p_dAbschnittStrecke = fVergleichsFahrzeug.p_dAbschnittStrecke;
}

void Fahrzeug::vNeueStrecke(Weg* pWeg, FzgVerhalten* pFzgVerhalten)
{
    delete p_pVerhalten;
    p_pVerhalten = pFzgVerhalten;
	p_dAbschnittStrecke=0;
}   

double Fahrzeug::dGetAbschnittStrecke()
{
    return p_dAbschnittStrecke;
}

void Fahrzeug::vZeichnen(Weg* pWeg) //Leer, dient nur als Oberfunktion für PKW und Fahrrad zeichnen
{

}

istream& Fahrzeug::istreamEingabe(istream& stream) 
{
	AktivesVO::istreamEingabe(stream) >> p_dMaxGeschwindigkeit;
	return stream;
}