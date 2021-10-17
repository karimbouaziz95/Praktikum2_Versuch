#include "Fahrrad.h"
#include <math.h>

//<Konstruktoren_Destruktoren>
Fahrrad::Fahrrad(string sName,double dSpeed)
{
	p_sName = sName;
	p_dMaxGeschwindigkeit = dSpeed;


}
Fahrrad::~Fahrrad()
{
}
//</Konstruktoren_Destruktoren>



//<Allgemeine_Funktionen>
double Fahrrad::dGeschwindigkeit()
{

	double speed =p_dMaxGeschwindigkeit* pow(0.9, (double)((int)p_dGesamtStrecke / 20));
	if (speed < 12.0)
	{
		speed = 12.0;
	}
	return speed;
}
void Fahrrad::vZeichnen(Weg* pWay)
{

	double dRelPosition = fabs(p_dAbschnittStrecke / pWay->getp_dLaenge());

	bZeichneFahrrad(GetName().c_str(), pWay->getsName().c_str(), dRelPosition, dGeschwindigkeit());

}
//</Allgemeine_Funktionen>
