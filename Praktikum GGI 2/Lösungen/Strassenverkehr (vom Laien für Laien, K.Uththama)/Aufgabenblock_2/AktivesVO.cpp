#include "AktivesVO.h"
#include <string>
#include <iomanip>

int AktivesVO::p_iMaxID = 0;

//Konstruktoren
AktivesVO::AktivesVO(void)
{
	vInitialisierung();
}

AktivesVO::AktivesVO(string sName)
{
	vInitialisierung();
	p_sName = sName;
}

//Destruktor
AktivesVO::~AktivesVO(void)
{
}

//Initialisierungsfunktion
void AktivesVO::vInitialisierung(void)
{
	p_iMaxID++;
    p_sName = "";
    p_iID = p_iMaxID;
    p_dZeit = 0;
}

//spezifische Ausgaben
ostream& AktivesVO::ostreamAusgabe(ostream& output)
{
	output << resetiosflags(ios::right) << setiosflags(ios::left) //jetzt rechtsbündig -> aus Aufgabe 1.5
		   << setiosflags(ios::fixed) << setprecision(2)
		   << setw(5)  << p_iID 
	       << setw(14) << p_sName;
	return output;
}

//Überladen des Ausgabe-Operators "<<"
ostream& operator <<(ostream& output , AktivesVO& Object)
{
	Object.ostreamAusgabe(output);
	return output;
}