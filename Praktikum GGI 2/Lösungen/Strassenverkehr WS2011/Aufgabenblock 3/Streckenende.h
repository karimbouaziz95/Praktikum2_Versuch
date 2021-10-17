//
//  Streckenende.h
//  Strassenverkehr
//
//  Created by Till Rachow on 06.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef Strassenverkehr_Streckenende_h
#define Strassenverkehr_Streckenende_h

#include "FahrAusnahme.h"

class Weg;
class Fahrzeug;

class Streckenende:
    public FahrAusnahme
{
public:
    Streckenende(Weg* pWeg, Fahrzeug* pFahrzeug);
    ~Streckenende();
    
    virtual void vBearbeiten();
};

#endif
