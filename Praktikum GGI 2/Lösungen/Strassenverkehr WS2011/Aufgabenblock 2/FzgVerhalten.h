//
//  FzgVerhalten.h
//  Strassenverkehr
//
//  Created by Till Rachow on 05.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef Strassenverkehr_FzgVerhalten_h
#define Strassenverkehr_FzgVerhalten_h

class Fahrzeug;
class Weg;

class FzgVerhalten
{
public:
    FzgVerhalten(Weg* pWeg);
    ~FzgVerhalten();
    
    virtual double dStrecke(Fahrzeug* pFahrzeug,double dZeit) =0;
    Weg* wGetWeg();
    
private:
    Weg* p_pWeg;
};


#endif
