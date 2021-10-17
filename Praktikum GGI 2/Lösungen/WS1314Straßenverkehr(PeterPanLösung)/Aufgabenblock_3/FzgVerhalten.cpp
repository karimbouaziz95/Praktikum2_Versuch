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
    if(   (p_wAktWeg->GetSchranke() - Fzg->GetAbschnittStrecke()) > 0)
		    {
			    if( ( zeitraum * Fzg->dGeschwindigkeit() )<=( p_wAktWeg->GetSchranke() - Fzg->GetAbschnittStrecke() ) )
			    {
                    double neueSchranke = ( Fzg->GetAbschnittStrecke() + zeitraum * Fzg->dGeschwindigkeit() );
                    p_wAktWeg->SetSchranke(neueSchranke);
				    return (zeitraum * Fzg->dGeschwindigkeit());                   // return Zu fahrenden Weg
			    }

			    return ( p_wAktWeg->GetSchranke() - Fzg->GetAbschnittStrecke() );  // return Reststrecke
		    }
	
		    throw new Streckenende(Fzg, p_wAktWeg);
		    //return 0;
   
       
}

double FzgVerhalten::GetLimit()
{
    return p_wAktWeg->GetLimit();
}