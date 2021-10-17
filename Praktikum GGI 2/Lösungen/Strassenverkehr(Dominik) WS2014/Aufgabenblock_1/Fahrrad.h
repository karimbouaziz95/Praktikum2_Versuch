
#ifndef FAHRRAD_H
#define FAHRRAD_H
#pragma once
#include "Fahrzeug.h"

/*	  Klasse: Fahhrad
  Oberklasse: Fahrzeug
  Enthält das Fahrzeug Fahrrad und die Geschwindigkeit dessen
  */
extern double dGlobaleZeit;

class Fahrrad :
	public Fahrzeug
{
public:
	Fahrrad(string,double);
	virtual ~Fahrrad();
	double dGeschwindigkeit();
	//ostream& ostreamAusgabe(ostream&);
	

};

#endif