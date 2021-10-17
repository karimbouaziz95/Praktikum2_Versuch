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
	
	
	double dSchranke = p_pSaveWeg->getp_dSchranke();

	double dGefahreneStrecke = ((pFahrzeug->dGeschwindigkeit())*dZeit) ;
	

	//if-Wegende erreicht
	if (p_pSaveWeg->getp_dLaenge() == pFahrzeug->getp_dAbschnittStrecke()){

		throw Streckenende(pFahrzeug,p_pSaveWeg);
	}

	if (p_pSaveWeg->getp_dLaenge() < pFahrzeug->getp_dAbschnittStrecke()){
		dGefahreneStrecke = (p_pSaveWeg->getp_dLaenge() - pFahrzeug->getp_dAbschnittStrecke());
	}



	if (pFahrzeug->getp_dAbschnittStrecke() + dGefahreneStrecke > p_pSaveWeg->getp_dSchranke() && p_pSaveWeg->getp_bUeberholverbot())
	{
		
			dGefahreneStrecke = p_pSaveWeg->getp_dSchranke() - pFahrzeug->getp_dAbschnittStrecke();
		
	}

	
	getp_pSaveWeg()->setp_dSchranke(dGefahreneStrecke + pFahrzeug->getp_dAbschnittStrecke());

	return dGefahreneStrecke;

	
	
}
//</Allgemeine_Funktionen>