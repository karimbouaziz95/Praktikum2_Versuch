//
//  FahrAusnahme.cpp
//  Strassenverkehr
//
//  Created by Till Rachow on 06.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "FahrAusnahme.h"
#include "Weg.h"
#include "Fahrzeug.h"

FahrAusnahme::FahrAusnahme(Weg* pWeg, Fahrzeug* pFahrzeug)
{
    p_PointWeg = pWeg;
    p_PointFahrzeug = pFahrzeug;
}

FahrAusnahme::~FahrAusnahme()
{

}