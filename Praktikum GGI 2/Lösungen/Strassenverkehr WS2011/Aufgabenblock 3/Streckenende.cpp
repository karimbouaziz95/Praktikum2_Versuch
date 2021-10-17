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
#include "Kreuzung.h"

Streckenende::Streckenende(Weg* pWeg, Fahrzeug* pFahrzeug) : FahrAusnahme(pWeg, pFahrzeug)
{

}

Streckenende::~Streckenende()
{

}

void Streckenende::vBearbeiten()
{
	cout << endl << "Exception: " << p_PointFahrzeug->sGetName() 
		 << " " << p_PointWeg->sGetName() << " Streckenende" << endl;
	p_PointWeg->vAbgabe(p_PointFahrzeug);
	p_PointWeg->kGetKreuzung()->vAnnahme(p_PointFahrzeug, 0, p_PointWeg);
}