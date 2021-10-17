//
//  Losfahren.cpp
//  Strassenverkehr
//
//  Created by Till Rachow on 06.11.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Losfahren.h"
#include "Weg.h"
#include "Fahrzeug.h"
#include "FzgFahren.h"

Losfahren::Losfahren(Weg* pWeg, Fahrzeug* pFahrzeug) : FahrAusnahme(pWeg, pFahrzeug)
{
    cout <<"Losfahren" << endl;
}

Losfahren::~Losfahren()
{
    
}

void Losfahren::vBearbeiten()
{
	p_PointWeg->vAbgabe(p_PointFahrzeug);
	p_PointWeg->vAnnahme(p_PointFahrzeug);
    cout << *p_PointWeg << *p_PointFahrzeug << "Losfahren" << endl;
}