//
//  Losfahren.h
//  Strassenverkehr
//
//  Created by Till Rachow on 06.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef Strassenverkehr_Losfahren_h
#define Strassenverkehr_Losfahren_h

#include "FahrAusnahme.h"

class Weg;
class Fahrzeug;

class Losfahren :
    public FahrAusnahme
{
public:
    Losfahren(Weg* pWeg, Fahrzeug* pFahrzeug);
    ~Losfahren();
    
    virtual void vBearbeiten();
};


#endif
