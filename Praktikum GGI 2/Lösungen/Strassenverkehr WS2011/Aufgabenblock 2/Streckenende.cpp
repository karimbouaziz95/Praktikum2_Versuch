//
//  Streckenende.cpp
//  Strassenverkehr
//
//  Created by Till Rachow on 06.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Streckenende.h"
#include "AktivesVO.h"
#include "Weg.h"
#include "Fahrzeug.h"

Streckenende::Streckenende(Weg* pWeg, Fahrzeug* pFahrzeug) : FahrAusnahme(pWeg, pFahrzeug)
{

}

Streckenende::~Streckenende()
{

}

void Streckenende::vBearbeiten()
{
	p_PointWeg->vAbgabe(p_PointFahrzeug);
    cout << *p_PointWeg << *p_PointFahrzeug << "Streckenende" << endl;
}