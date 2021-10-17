#include "FahrAusnahme.h"

//<Konstruktoren_Destruktoren>
FahrAusnahme::FahrAusnahme()
{


}
FahrAusnahme::FahrAusnahme(Fahrzeug* drivething,Weg* Way)
{
	p_pDriveThing = drivething;
	p_pWay = Way;


}
FahrAusnahme::~FahrAusnahme()
{
}
//</Konstruktoren_Destruktoren>