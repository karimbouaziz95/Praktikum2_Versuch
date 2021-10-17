#include "FzgFahren.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Streckenende.h"

extern double dGlobaleZeit;

//Konstruktor mit aufruf von FzgVerhalten, pWeg wird gesetzt
FzgFahren::FzgFahren(Weg * pWeg) : FzgVerhalten(pWeg)
{
	
}

FzgFahren::~FzgFahren()
{

}


	double FzgFahren::dStrecke(Fahrzeug * fahrzeug, double dZeitraum)
	{
		if (fahrzeug->dGetZeit() == dGlobaleZeit) //Mehrmalige verwendung des Autos in einer Zeiteinheit ausgeschließen
			return 0.0;

		double tolerance = 0.0002;
		double restlicheStrecke = p_pWeg->GetLaenge() - fahrzeug->dGetAbschnittStrecke();
		double gefahreneStrecke = fabs(fahrzeug->dGeschwindigkeit() * dZeitraum);
		//3. Fuer ueberholverbot
		double maxDeltaStrecke = fabs(p_pWeg->dGetSchranke() - fahrzeug->dGetAbschnittStrecke());
		gefahreneStrecke = gefahreneStrecke < maxDeltaStrecke ? gefahreneStrecke : maxDeltaStrecke;
		gefahreneStrecke = fabs(gefahreneStrecke);
		// Noch auf Weg 
		/*
		if (restlicheStrecke - gefahreneStrecke > 0) {
			return gefahreneStrecke;
		}*/
		// Ende erreicht
		if (restlicheStrecke - gefahreneStrecke<= 0) {
			throw Streckenende(p_pWeg, fahrzeug); //exit(1)
		}
	
		return gefahreneStrecke;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*/Bei Zeittakt 0.25 ausreichend
	if (dStreckeAbschnitt < dStreckeGeschwindigkeit)
	{
		throw Streckenende(p_pWeg, fahrzeug); //exit(1); Ende des Weges
	}

	return dStrecke;*/





