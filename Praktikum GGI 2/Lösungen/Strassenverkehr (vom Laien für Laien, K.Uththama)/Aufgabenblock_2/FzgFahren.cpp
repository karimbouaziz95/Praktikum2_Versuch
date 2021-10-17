#include "FzgFahren.h"
#include "FzgParken.h"
#include "Streckenende.h"
#include "Fahrzeug.h"

extern double dGlobaleZeit;

FzgFahren::FzgFahren(void)
{
}


FzgFahren::FzgFahren(Weg* Weg) : FzgVerhalten(Weg) {};


FzgFahren::~FzgFahren(void)
{
}


//mögliche Strecke
double FzgFahren::dStrecke(Fahrzeug* Fzg, double Zeitraum)
{
	double diff = p_pWeg->dgetlength() - Fzg->dgetactLength();
	double abschnitt = Fzg->dGeschwindigkeit() * Zeitraum;
	if (diff == 0)
	{
		Fzg->vsetactTime(dGlobaleZeit);    //weil code nach catch-Block nicht fortgeführt wird.
		throw new Streckenende(p_pWeg, Fzg); //exit(1)
	}
	else if ( diff <= abschnitt)
	{
		return diff;
	}
	else if ( diff > abschnitt)
	{
		return abschnitt;
	}
}

double FzgFahren::dgetstartTime()
{
	return 0;
}
