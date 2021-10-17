#include "AktivesVO.h"
#include "FzgVerhalten.h"
#include "Weg.h"
#include "Streckenende.h"

FzgVerhalten::FzgVerhalten(void)
{
}

FzgVerhalten::FzgVerhalten(Weg *way)
{
    p_wAktWeg = way;
}


FzgVerhalten::~FzgVerhalten(void)
{
}


double FzgVerhalten::dStrecke(Fahrzeug* Fzg,double zeitraum)
{
		if(p_wAktWeg->GetLaenge() - Fzg->GetAbschnittStrecke() > 0)
		{
			if((zeitraum * Fzg->dGeschwindigkeit())<=(p_wAktWeg->GetLaenge()-Fzg->GetAbschnittStrecke()))
			{
				return (zeitraum * Fzg->dGeschwindigkeit());
			}
			return (p_wAktWeg->GetLaenge()-Fzg->GetAbschnittStrecke());
		}
	
		throw new Streckenende(Fzg, p_wAktWeg);                           // werfen von streckenende
		//return 0;
	
	
}

double FzgVerhalten::GetLimit()
{
    return p_wAktWeg->GetLimit();
}