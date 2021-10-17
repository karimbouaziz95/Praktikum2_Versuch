#include "AktivesVO.h"
#include "FzgVerhalten.h"
#include "Weg.h"

extern double dGlobabeZeit;

//Konstruktoren
FzgVerhalten::FzgVerhalten(void)
{
}

FzgVerhalten::FzgVerhalten(Weg* pWeg)
{
    p_pWeg = pWeg;
}

//Destruktor
FzgVerhalten::~FzgVerhalten(void)
{
}

//Zeiger übergeben
Weg* FzgVerhalten::getWayPointer()
{
	return p_pWeg;
}