//
//  FzgFahren.h
//  Strassenverkehr
//
//  Created by Till Rachow on 06.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef Strassenverkehr_FzgFahren_h
#define Strassenverkehr_FzgFahren_h
#include "FzgVerhalten.h"

class FzgFahren:
    public FzgVerhalten
{
public:
    FzgFahren(Weg* pWeg);
    ~FzgFahren();
    
    virtual double dStrecke(Fahrzeug* pFahrzeug, double dZeit);
};


#endif
