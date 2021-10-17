#pragma once
#include "Weg.h"
#include "Fahrzeug.h"

class Weg;
class Fahrzeug;
class FzgVerhalten
{
public:
	FzgVerhalten();	
	FzgVerhalten(Weg*);
	virtual ~FzgVerhalten();

			
	virtual double dStrecke(Fahrzeug*, double)=0;//abstrakte Oberklasse
	Weg* getp_pSaveWeg();
	
protected:
	Weg *p_pWeg;
	Weg *p_pSaveWeg;
	
	
	
};

