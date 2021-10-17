#include "FzgParken.h"
#include "FzgFahren.h"
#include "Losfahren.h"

extern double dGlobaleZeit;

FzgParken::FzgParken(void)
{

}

FzgParken::FzgParken(Weg *way, double dStart) : FzgVerhalten(way)
{
	p_dStartzeitpunkt = dStart;
}


FzgParken::~FzgParken(void)
{
}


double FzgParken::dStrecke(Fahrzeug* Fzg,double zeitraum)
{
	if(p_dStartzeitpunkt >= dGlobaleZeit)
	{
		return 0;
	}
	else throw new Losfahren(Fzg, p_wAktWeg);   //exit(2);
}

