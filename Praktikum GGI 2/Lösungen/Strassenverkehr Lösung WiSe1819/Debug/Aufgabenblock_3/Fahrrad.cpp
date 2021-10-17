#include "Fahrrad.h"
#include <iostream>
#include <string>

#include <iomanip>
#include <math.h>

#include "Weg.h"


//Konstruktor mit aufruf von Fahrzeug f�r Initialisierung und ID vergabe
Fahrrad::Fahrrad() : Fahrzeug()
{

}

//Konstruktor mit aufruf von Fahrzeug f�r Initialisierung und ID vergabe
Fahrrad::Fahrrad(string sName, double MaxSpeed) : Fahrzeug(sName)
{
	p_dMaxGeschwindigkeit = MaxSpeed;
}


Fahrrad::~Fahrrad()
{
}


double Fahrrad::dGeschwindigkeit() {
	
	double dGeschwindigkeit = p_dMaxGeschwindigkeit;
	int n = ((int)p_dGesamtStrecke / 20);
	for (int i = 0; i < n; i++) {
		
		dGeschwindigkeit *= 0.9;
	}

	if (dGeschwindigkeit < 12)
		dGeschwindigkeit = 12;

	return dGeschwindigkeit;

}



void Fahrrad::vZeichnen(Weg* pWeg)
{
	double dRelPos = p_dAbschnittStrecke / pWeg->GetLaenge();
	dRelPos = dRelPos > 1 ? 1 : dRelPos;
	dRelPos = dRelPos < 0 ? 0 : dRelPos;
	bZeichneFahrrad(sGetName().c_str(), pWeg->sGetName().c_str(), dRelPos, dGeschwindigkeit());

}


ostream& Fahrrad::ostreamAusgabe(ostream& Stream)
{
	Fahrzeug::ostreamAusgabe(Stream);
	Stream << resetiosflags(ios::right) << setiosflags(ios::left) //vorher rechts jetzt wieder linksb�ndig (1.5)
		<< setw(12) << " "
		<< setw(12) << " "
		<< setw(12) << dGeschwindigkeit() << endl;
	return Stream;
}

istream& Fahrrad::istreamEingabe(istream& Stream)
{
	Fahrzeug::istreamEingabe(Stream);
	return Stream;
}
