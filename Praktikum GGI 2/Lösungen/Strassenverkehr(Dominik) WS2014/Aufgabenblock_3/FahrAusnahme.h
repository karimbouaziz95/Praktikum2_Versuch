#ifndef FAHRAUSNAHME_H
#define FAHRAUSNAHME_H
#pragma once

#include "Fahrzeug.h"
#include "Weg.h"


class FahrAusnahme
{
public:
	FahrAusnahme();
	FahrAusnahme(Fahrzeug* drivething, Weg* Way);
	virtual ~FahrAusnahme();


	virtual void vBearbeiten() = 0;

protected:

	Fahrzeug* p_pDriveThing;
	Weg * p_pWay;


};

#endif
