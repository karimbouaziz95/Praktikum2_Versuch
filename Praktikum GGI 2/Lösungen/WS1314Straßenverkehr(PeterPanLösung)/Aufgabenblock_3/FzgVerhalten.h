#pragma once
#include "Fahrzeug.h"
#include "AktivesVO.h"

#include "Weg.h"

class FzgVerhalten
{
public:

    FzgVerhalten(void);
    FzgVerhalten(Weg *way);

    virtual ~FzgVerhalten(void);
    virtual double dStrecke(Fahrzeug* Fzg,double zeitraum);
    double GetLimit();

protected:
    Weg* p_wAktWeg;
};

