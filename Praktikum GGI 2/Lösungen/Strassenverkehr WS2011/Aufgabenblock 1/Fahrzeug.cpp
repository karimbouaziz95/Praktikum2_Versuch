#include "Fahrzeug.h"

int Fahrzeug::p_iMaxID = 0;

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
	++p_iMaxID;
	p_iID = p_iMaxID;
	p_sName = "";
	p_dMaxGeschwindigkeit = 0;
	p_dGesamtStrecke = 0;
	p_dGesamtzeit = 0;
	p_dZeit = 0;
}

void Fahrzeug::vAusgabe(void)
{
	cout << setw(4) << setiosflags(ios::left) << p_iID 
		 << setw(12) << setiosflags(ios::left) << p_sName 
		 << setw(3) << setiosflags(ios::left) << ":" 
		 << setw(17) << setiosflags(ios::left) << setiosflags(ios::fixed) << setprecision(2) << dGeschwindigkeit()  
		 << setw(16) << setiosflags(ios::left) << setiosflags(ios::fixed) << setprecision(2) << p_dGesamtStrecke ;
}

void Fahrzeug::vAbfertigung(void)
{
	extern double dGlobaleZeit;
	extern double dZeitschritt;

	//Abfertigung nur wenn verstrichene Zeit seit letzter Abfertigung mindestens einen Zeitschritt groß ist.

	if((dGlobaleZeit-p_dZeit)>=dZeitschritt)
	{
		p_dGesamtStrecke += dGeschwindigkeit()*(dGlobaleZeit-p_dZeit);  //Gesamtstrecke += verstrichene Zeit*Geschwindigkeit
		p_dGesamtzeit += (dGlobaleZeit-p_dZeit);						//Gesamtzeit += verstrichene Zeit
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

ostream& operator<<(ostream& Stream, Fahrzeug& Fahrzeug_o)
{
	Fahrzeug_o.ostreamAusgabe(Stream);
	return Stream;
}

ostream& Fahrzeug::ostreamAusgabe(ostream& Stream)
{
	Stream << setw(4) << setiosflags(ios::left) << p_iID 
		   << setw(12) << setiosflags(ios::left) << p_sName 
		   << setw(3) << setiosflags(ios::left) << ":" 
		   << setw(17) << setiosflags(ios::left) << setiosflags(ios::fixed) << setprecision(2) << dGeschwindigkeit()  
		   << setw(16) << setiosflags(ios::left) << setiosflags(ios::fixed) << setprecision(2) << p_dGesamtStrecke ;
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
	this->p_dGesamtzeit = fVergleichsFahrzeug.p_dGesamtzeit;
	this->p_dZeit = fVergleichsFahrzeug.p_dZeit;
	this->p_sName = "n" + fVergleichsFahrzeug.p_sName;
}