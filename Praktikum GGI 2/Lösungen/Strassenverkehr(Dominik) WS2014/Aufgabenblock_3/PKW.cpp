#include "PKW.h"
#include <sstream>

//<Konstruktoren_Destruktoren>
PKW::PKW(string sName)
{
	p_dTankvolumen = 55.0;
	p_dTankinhalt = p_dTankvolumen / 2.0;
	dRelativePosition = 0.0;
	p_sName = sName;



}
PKW::PKW(string sName, double dSpeed, double dUsage)
{
	p_dTankvolumen = 55.0;
	p_dTankinhalt = p_dTankvolumen / 2.0;
	p_sName = sName;
	p_dMaxGeschwindigkeit = dSpeed;
	p_dVerbrauch = dUsage;
	dRelativePosition = 0.0;


}
PKW::PKW(string sName, double dSpeed, double dUsage, double dTankVol)
{
	p_dTankvolumen = dTankVol;
	p_dTankinhalt = p_dTankvolumen / 2.0;
	p_sName = sName;
	p_dMaxGeschwindigkeit = dSpeed;
	p_dVerbrauch = dUsage;
	dRelativePosition = 0.0;

}
PKW::~PKW()
{
}
//</Konstruktoren_Destruktoren>



//<Allgemeine_Funktionen>
void PKW::vZeichnen(Weg* pWay)
{

	dRelativePosition = (p_dAbschnittStrecke / pWay->getp_dLaenge());
	//cout << dRelativePosition<< endl;
	if (dRelativePosition >= 1)dRelativePosition = 1;
	bZeichnePKW(GetName(),pWay->getsName(),dRelativePosition, dGeschwindigkeit(), p_dTankinhalt);
	
}
void PKW::vAbfertigung()
{
Fahrzeug::vAbfertigung();

p_dTankinhalt -= dVerbrauch(p_dGefahreneStrecke);
if (p_dTankinhalt <= 0.0){ dTanken(); cout <<p_sName << " vollgetankt!" << endl; }

}
double PKW::dVerbrauch(double strecke)
{
	return (p_dVerbrauch / 100.0)*strecke;
}
double PKW::dTanken(double dMenge)
{
	
	if (dMenge == -1.0)
	{
		dMenge = p_dTankvolumen - p_dTankinhalt;
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
double PKW::dGeschwindigkeit()
{
	if (p_dTankinhalt > 0)
	{
		if (p_dMaxGeschwindigkeit< (this->p_pVerhalten->getp_pSaveWeg()->getp_eLimit()) || (this->p_pVerhalten->getp_pSaveWeg()->getp_eLimit())==0){
			return p_dMaxGeschwindigkeit;

		}
		else
		{
			return (this->p_pVerhalten->getp_pSaveWeg()->getp_eLimit());
		}
		
	}
	else
	{
		return 0.0;
	}
	
}

//</Allgemeine_Funktionen>



//<Ueberladungen>
istream& PKW::istreamEingabe(istream& Stream)
{
	Fahrzeug::istreamEingabe(Stream);
	Stream >> p_dVerbrauch;
	Stream >> p_dTankvolumen;
	p_dTankinhalt = p_dTankvolumen / 2;
	return Stream;
}
istream& operator>>(istream& Stream, PKW& car)
{
	return car.istreamEingabe(Stream);
}
ostream& PKW::ostreamAusgabe(ostream& out)
{ 
	Fahrzeug::ostreamAusgabe(out);
	out  << setw(10) << p_dTankinhalt << endl;
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
//</Ueberladungen>

//<Get_Set-Funktionen>
double PKW::getp_dTankinhalt(){

	return p_dTankinhalt;
}

//</Get_Set-Funktion>
