#include "FzgFahren.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include "Streckenende.h"
#include <math.h>

FzgFahren::FzgFahren(Weg * ptWay):FzgVerhalten(ptWay)
{
}

//Gibt fahrbare Strecke zurück, solange nicht Ende des Wegs erreicht wurde
double FzgFahren::dStrecke(Fahrzeug * ptCar, double dZeit)
{
	double dFahrbareStrecke;
	double dGefahreneStrecke;
	double dWegLaenge;
	double dSchranke;

	//Strecke, die das Fahrzeug in der Zeit fahren koennte
	dFahrbareStrecke = ptCar->dGeschwindigkeit()*dZeit;

	//Von Fahrzeug gefahrene Teilstrecke
	dGefahreneStrecke = ptCar->GetAbschnittStrecke();

	//Laenge des Wegs, auf dem Fahrzeug unterwegs ist
	dWegLaenge = p_ptWeg->GetLaenge();

	//Schranke fuer Ueberholverbot
	dSchranke = p_ptWeg->GetSchranke();

	if((dGefahreneStrecke+dFahrbareStrecke > dWegLaenge) && (dGefahreneStrecke >= (dWegLaenge-0.001)))
	{
		//Beende, da Wegende
		throw new Streckenende(ptCar,p_ptWeg);
	}
	else if((dGefahreneStrecke+dFahrbareStrecke > dWegLaenge) && (dGefahreneStrecke < (dWegLaenge-0.001)))
	{
		//Gib Reststrecke zurueck, da keine ganze Strecke mehr fahrbar
		return (dWegLaenge-dGefahreneStrecke);
	}
	else
	{
		if((dGefahreneStrecke+dFahrbareStrecke) > dSchranke)
		{
			return fabs(dGefahreneStrecke-dSchranke);
		}
		else
		{
			p_ptWeg->SetSchranke(dGefahreneStrecke+dFahrbareStrecke);
			return dFahrbareStrecke;
		}

	}
}