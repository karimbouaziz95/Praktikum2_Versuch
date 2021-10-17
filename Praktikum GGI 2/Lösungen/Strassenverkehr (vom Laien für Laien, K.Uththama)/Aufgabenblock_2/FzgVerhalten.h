#pragma once
#include "Fahrzeug.h"
#include "AktivesVO.h"
 
#include "Weg.h"

using namespace std;

class FzgVerhalten
{
public:
	//Konstruktoren
	FzgVerhalten(void);
	FzgVerhalten(Weg* Weg);
	
	//Destrukor
	virtual ~FzgVerhalten(void);

	//m�gliche fahrbare Strecke
	virtual	double dStrecke(Fahrzeug* Fzg, double Zeitraum) = 0;

	//Zeiger �bergeben
	Weg* getWayPointer();

	//rein virtuelle Methode
	virtual double dgetstartTime() = 0;

protected:
	//Zeiger auf aktuellen weg
	Weg* p_pWeg;
};

