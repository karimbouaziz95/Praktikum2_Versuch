#ifndef FAHRRAD_H
#define FAHRRAD_H
#pragma once
#include "Fahrzeug.h"
#include "SimuClient.h"
extern double dGlobaleZeit;

class Fahrrad :
	public Fahrzeug
{
public:
	Fahrrad(string,double);
	virtual ~Fahrrad();

	double dGeschwindigkeit();
	virtual void vZeichnen(Weg*);
	

};

#endif