#include "Fahrrad.h"
#include <math.h>


Fahrrad::Fahrrad(string sName,double dSpeed)
{
	p_sName = sName;
	p_dMaxGeschwindigkeit = dSpeed;


}


Fahrrad::~Fahrrad()
{
}


double Fahrrad::dGeschwindigkeit()
{

	double speed =p_dMaxGeschwindigkeit* pow(0.9, (double)((int)p_dGesamtStrecke / 20)); //Fahrradfahrer verringern Geschwindigkeit um 10% je 20km
	if (speed < 12.0)
	{
		speed = 12.0;
	}
	return speed;
}