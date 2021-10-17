//
//  FahrAusnahme.h
//  Strassenverkehr
//
//  Created by Till Rachow on 06.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef Strassenverkehr_FahrAusnahme_h
#define Strassenverkehr_FahrAusnahme_h

class Weg;
class Fahrzeug;

class FahrAusnahme
{
public:
    FahrAusnahme(Weg* pWeg, Fahrzeug* pFahrzeug);
    ~FahrAusnahme();
    
    virtual void vBearbeiten()=0;
    
protected:
    Weg* p_PointWeg;
    Fahrzeug* p_PointFahrzeug;
    
};

#endif
