//
//  FzgVerhalten.cpp
//  Strassenverkehr
//
//  Created by Till Rachow on 05.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "FzgVerhalten.h"
#include "Weg.h"
#include "Fahrzeug.h"

FzgVerhalten::FzgVerhalten(Weg* pWeg)
{
    p_pWeg = pWeg;
} 

FzgVerhalten::~FzgVerhalten()
{

}

Weg* FzgVerhalten::wGetWeg()
{
    return p_pWeg;
}