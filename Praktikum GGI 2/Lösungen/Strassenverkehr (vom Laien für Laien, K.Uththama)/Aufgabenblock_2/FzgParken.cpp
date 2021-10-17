#include "FzgParken.h"
#include "FzgFahren.h"
#include "Losfahren.h"

extern double dGlobaleZeit;

//Konstruktoren
FzgParken::FzgParken(void)
{
}

FzgParken::FzgParken(Weg* Weg, double Startzeitpunkt) : FzgVerhalten(Weg)
{
	p_dStartzeitpunkt = Startzeitpunkt;
}

//Dekstruktor
FzgParken::~FzgParken(void)
{
}

//mögliche Strecke
double FzgParken::dStrecke(Fahrzeug* Fzg, double Zeitraum)
{
	if(dGlobaleZeit < p_dStartzeitpunkt)
	{
		return 0.0;
	}
	else 
	{
		Fzg->vsetactTime(dGlobaleZeit);
		throw new Losfahren(p_pWeg, Fzg);
		//cout << "Startzeitpunkt erreicht !" << endl;
		//exit(2)
	}
}


double FzgParken::dgetstartTime()
{
	return p_dStartzeitpunkt;
}