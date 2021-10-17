#include "Losfahren.h"

//<Konstruktoren_Destruktoren>
Losfahren::Losfahren()
{
}
Losfahren::Losfahren(Fahrzeug* drivething, Weg* Way)
{
	p_pDriveThing = drivething;
	p_pWay = Way;


}
Losfahren::~Losfahren()
{
}
//</Konstruktoren_Destruktoren>



//<Allgemeine_Funktionen>
void Losfahren::vBearbeiten()
{
	cout << p_pDriveThing->getsName() << *p_pWay << "Ausnahme:Losfahren"<<endl;
	p_pWay->vAbgabe(p_pDriveThing);
	p_pWay->vAnnahme(p_pDriveThing);
}
//</Allgemeine_Funktionen>