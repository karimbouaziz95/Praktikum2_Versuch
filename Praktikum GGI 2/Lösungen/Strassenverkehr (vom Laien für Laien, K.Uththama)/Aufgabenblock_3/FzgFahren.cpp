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
	double Schranke = p_pWeg->dgetSchranke();
	double fahrbar = Fzg->dGeschwindigkeit() * Zeitraum;
	double Abschnittsstr = Fzg->dgetactLength();
	double rueckgabe;
	if (p_pWeg->dgetlength() == Abschnittsstr)
	{
		Fzg->vsetactTime(dGlobaleZeit);      //weil code nach throw nicht fortgeführt wird.
		throw new Streckenende(p_pWeg, Fzg); //exit(1)
	}
	else if ((fahrbar + Abschnittsstr) <= Schranke)
	{
		rueckgabe = fahrbar;
	}
	else if ((fahrbar + Abschnittsstr)> Schranke)
	{
		rueckgabe = Schranke - Abschnittsstr;
	}
	p_pWeg->vsetSchranke(Abschnittsstr + rueckgabe);
	return rueckgabe;
}

double FzgFahren::dgetstartTime()
{
	return 0;
}
