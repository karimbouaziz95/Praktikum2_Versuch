//
//  FzgParken.h
//  Strassenverkehr
//
//  Created by Till Rachow on 06.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef Strassenverkehr_FzgParken_h
#define Strassenverkehr_FzgParken_h
#include "FzgVerhalten.h"

class Weg;
class Fahrzeug;

class FzgParken :
    public FzgVerhalten
{
public:
    FzgParken(Weg* pWeg, double dStartzeit);
    ~FzgParken();
    
    virtual double dStrecke(Fahrzeug* pFahrzeug, double dZeit);
protected:
    double p_dStartzeit;
};


#endif
