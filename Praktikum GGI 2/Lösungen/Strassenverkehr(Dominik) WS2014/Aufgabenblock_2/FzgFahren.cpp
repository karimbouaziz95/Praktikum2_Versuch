#include "FzgFahren.h"
#include "Streckenende.h"

//<Konstruktoren_Destruktoren>
FzgFahren::FzgFahren()
{
}
FzgFahren::FzgFahren(Weg* pWay)
{
	p_pSaveWeg = pWay;
}
FzgFahren::~FzgFahren()
{
}
//</Konstruktoren_Destruktoren>



//<Allgemeine_Funktionen>
double FzgFahren::dStrecke(Fahrzeug* pFahrzeug, double dZeit)
{

	double p_dGefahreneStrecke = ((pFahrzeug->dGeschwindigkeit())*dZeit)/10.0;

	if (fabs(p_pSaveWeg->getp_dLaenge()) - (pFahrzeug->getp_dAbschnittStrecke()) <0.1){

		throw Streckenende(pFahrzeug,p_pSaveWeg);
	}


	if ((p_pSaveWeg->getp_dLaenge()) < (pFahrzeug->getp_dAbschnittStrecke() + p_dGefahreneStrecke))
	{

		return (p_pSaveWeg->getp_dLaenge()) - (pFahrzeug->getp_dAbschnittStrecke());

	}

	return p_dGefahreneStrecke;
}
//</Allgemeine_Funktionen>