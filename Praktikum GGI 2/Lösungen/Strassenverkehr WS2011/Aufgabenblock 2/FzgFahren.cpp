//
//  FzgFahren.cpp
//  Strassenverkehr
//
//  Created by Till Rachow on 06.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "FzgFahren.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Streckenende.h"
#include "math.h"

FzgFahren::FzgFahren(Weg* pWeg) : FzgVerhalten(pWeg)
{
}

FzgFahren::~FzgFahren()
{

}

double FzgFahren::dStrecke(Fahrzeug *pFahrzeug, double dZeit)
{
	if((wGetWeg()->dGetLaenge() - pFahrzeug->dGetAbschnittStrecke()) <= 0)
    {
		//Exception wird geworfen, wenn Fahrzeug am Wegende angekommen ist.
        throw new Streckenende(wGetWeg(), pFahrzeug);
    }
    
	//ansonsten Berechnung der gefahrenen Strecke im Zeitraum dZeit
	double dStrecke;
    dStrecke=pFahrzeug->dGeschwindigkeit()*dZeit;
    
    if ((wGetWeg()->dGetLaenge() - pFahrzeug->dGetAbschnittStrecke() - dStrecke) >= 0.01) //Wenn dStrecke komplett fahrbar ist,
    {
        return dStrecke;																  //wird dStrecke zurückgegeben
    } 
    else																				  //sonst
    {
        return (wGetWeg()->dGetLaenge() - pFahrzeug->dGetAbschnittStrecke());			  //wird noch zu fahrende Strecke bis Wegende zurückgegeben. 
    }
}
