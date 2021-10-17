#include "Streckenende.h"


//<Konstruktoren_Destruktoren>
Streckenende::Streckenende()
{
}
Streckenende::Streckenende(Fahrzeug* drivething, Weg* Way)
{
	p_pDriveThing = drivething;
	p_pWay = Way;
}
Streckenende::~Streckenende()
{
}
//</Konstruktoren_Destruktoren>


//<Allgemeine_Funktionen>
void Streckenende::vBearbeiten()
{
	Weg* NeuerWeg;
	cout << p_pDriveThing->getsName() << *p_pWay << "Ausnahme:Streckenende" << endl;
	p_pWay->vAbgabe(p_pDriveThing);
	p_pWay->GetKreuzung()->vTanken(p_pDriveThing);

	NeuerWeg = p_pWay->GetKreuzung()->ptZufaelligerWeg(p_pWay);
	p_pWay = NeuerWeg;
	NeuerWeg->vAnnahme(p_pDriveThing);
	

}
//</Allgemeine_Funktionen>