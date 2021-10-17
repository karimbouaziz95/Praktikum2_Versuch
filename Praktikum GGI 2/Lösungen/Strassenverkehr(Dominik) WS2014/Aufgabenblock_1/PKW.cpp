#include "PKW.h"
#include <sstream>


PKW::PKW(string sName, double dSpeed, double dUsage)
{
	p_dTankvolumen = 55.0;
	p_dTankinhalt = p_dTankvolumen / 2.0; //Standardmaessig auf Haelfte des Tankes gestellt
	p_sName = sName;
	p_dMaxGeschwindigkeit = dSpeed;
	p_dVerbrauch = dUsage;


}

void PKW::vAbfertigung()
{


	if (p_dLetzeAbfertigung < dGlobaleZeit)
	{

		p_dGesamtZeit += (dGlobaleZeit - p_dLetzeAbfertigung);
		p_dGesamtStrecke += (dGlobaleZeit - p_dLetzeAbfertigung)*dGeschwindigkeit();
		p_dTankinhalt -= dVerbrauch((dGlobaleZeit - p_dLetzeAbfertigung)*dGeschwindigkeit());
		p_dLetzeAbfertigung = dGlobaleZeit;



	}


}
double PKW::dVerbrauch(double strecke)
{
	return (p_dVerbrauch / 100.0)*strecke;
}
double PKW::dTanken(double dMenge)
{
	
	if (dMenge == -1.0) //leer
	{
		dMenge = p_dTankvolumen - p_dTankinhalt; //Voltanken
		p_dTankinhalt = p_dTankvolumen;

	}
	else
	{
		p_dTankinhalt += dMenge;
		if (p_dTankinhalt > p_dTankvolumen)
		{
			dMenge = p_dTankvolumen - p_dTankinhalt;
			p_dTankinhalt = p_dTankvolumen;
		}
	}
	return dMenge;
}
PKW::PKW(string sName, double dSpeed, double dUsage, double dTankVol)
{
	p_dTankvolumen = dTankVol;
	p_dTankinhalt = p_dTankvolumen / 2.0;
	p_sName = sName;
	p_dMaxGeschwindigkeit = dSpeed;
	p_dVerbrauch = dUsage;

}


PKW::~PKW()
{
}
double PKW::dGeschwindigkeit()
{
	if (p_dTankinhalt > 0)
	{
		return p_dMaxGeschwindigkeit;
	}
	else
	{
		return 0.0;
	}
	
}
ostream& PKW::ostreamAusgabe(ostream& out)
{
out << setiosflags(ios::left) << setw(5) << p_iID << 
setw(10) << p_sName << setw(5) << ":" << setw(9) <<
dGeschwindigkeit() << setw(20) << p_dGesamtStrecke << setw(10) <<  p_dTankinhalt << endl;
return out;
}

void PKW:: operator =(PKW& Zuw)
{
	p_sName = Zuw.p_sName;
	p_dMaxGeschwindigkeit = Zuw.p_dMaxGeschwindigkeit;
	p_dTankvolumen = Zuw.p_dTankvolumen;
	p_dVerbrauch = Zuw.p_dVerbrauch;
	//cout << "tolle kopyfuntion benutzt";
}


