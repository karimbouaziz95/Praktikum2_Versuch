#pragma once
#include "Fahrzeug.h"

class Fahrrad : public Fahrzeug
{
	public:
		Fahrrad(){};
		Fahrrad(string sName, double dMaxSpeed):Fahrzeug(sName, dMaxSpeed){};
		virtual double dTanken(double dMenge = 0.0) {return 0;}; //Tanken nicht möglich -> es wird immer 0 returnt
		virtual void vAbfertigung(); //Abfertigung
		virtual double dGeschwindigkeit(); //Geschwindigkeit ausrechnen und zurückgeben
		virtual ostream& ostreamAusgabe(ostream& data); //Ostream mit spezifischen Daten zurückgeben
		virtual void vDraw(Weg* TrackPtr); //Fahrzeug in der grafikschen Oberfläche zeichnen
		
};