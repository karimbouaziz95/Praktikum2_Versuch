//
//  FzgParken.cpp
//  Strassenverkehr
//
//  Created by Till Rachow on 06.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "FzgParken.h"
#include "Losfahren.h"

using namespace std;
extern double dGlobaleZeit;

FzgParken::FzgParken(Weg* pWeg, double dStartzeit) : FzgVerhalten(pWeg)
{
    p_dStartzeit = dStartzeit;
}

double FzgParken::dStrecke(Fahrzeug *pFahrzeug, double dZeit)
{
    if (dGlobaleZeit < p_dStartzeit)
        return 0.0;
    throw new Losfahren(wGetWeg(), pFahrzeug); //Wenn Startzeit erreicht, Exception werfen um Fahrzeug zu starten
}