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
	cout << p_pDriveThing->getsName() << *p_pWay << "Ausnahme:Streckenende" << endl;
	p_pWay->vAbgabe(p_pDriveThing);

}
//</Allgemeine_Funktionen>