#include "Weg.h"
#include "Fahrzeug.h"
#include "FzgVerhalten.h"
#include "FahrAusnahme.h"
#include <iomanip>

//Kontruktoren
Weg::Weg(void) : AktivesVO()
{
}

Weg::Weg(string sName , double dLaenge , int iSpeedLimit) : AktivesVO(sName)
{
	p_dLaenge = dLaenge;
	p_eLimit = iSpeedLimit;
}

//Destruktor
Weg::~Weg(void)
{
}

//Abfertigung
void Weg::vAbfertigung()
{
	list<Fahrzeug*>::iterator itlistFzg;
	p_pFahrzeuge.vAktualisieren();
	for (itlistFzg = p_pFahrzeuge.begin() ; itlistFzg != p_pFahrzeuge.end() ; itlistFzg++)
	{
		try 
		{
			(*itlistFzg)->vAbfertigung();  //Überwachen 
		}
		catch (FahrAusnahme* aktAusnahme)
		{
			aktAusnahme->vBearbeiten();
		}	
	}
	p_pFahrzeuge.vAktualisieren();
}

//Ausgabe
ostream& Weg::ostreamAusgabe(ostream& output)
{
	list<Fahrzeug*>::iterator itListFzg;
	AktivesVO::ostreamAusgabe(output);
	cout << "Laenge : " << setw(10)<< p_dLaenge << "( ";
	for (itListFzg = p_pFahrzeuge.begin(); itListFzg != p_pFahrzeuge.end(); itListFzg++)
	{
		cout << (*itListFzg)->sgetName() << " ";
	}	
	cout << ")" << endl;
	return output;
}

//Funktion zum Übergeben der Länge
double Weg::dgetlength()
{
	return p_dLaenge;
}

//Annahme eines fahrenden Fahrzeugs auf den Weg
void Weg::vAnnahme(Fahrzeug* Fzg)
{
	Fzg->vNeueStrecke(this);
	p_pFahrzeuge.push_back(Fzg);
}

//Annahme eines parkenden Fahrzeugs auf den Weg
void Weg::vAnnahme(Fahrzeug* Fzg, double dStart)
{
	Fzg->vNeueStrecke(this, dStart);
	p_pFahrzeuge.push_front(Fzg);
}

//Übergabe der Geschwindigkeitsbegrenzung 
int Weg::igetSpeedLimit()
{
	return p_eLimit;
}


//Übergabe des Namens
string Weg::sgetName()
{
	return p_sName;
}


//Abgabe des Fahrzeugs
void Weg::vAbgabe(Fahrzeug* Fzg)
{
	list<Fahrzeug*>::iterator itlistFzg;
	for(itlistFzg = p_pFahrzeuge.begin(); itlistFzg != p_pFahrzeuge.end(); itlistFzg++)
	{
		if(*itlistFzg == Fzg)
		{
			p_pFahrzeuge.erase(itlistFzg);
		}
	}
}