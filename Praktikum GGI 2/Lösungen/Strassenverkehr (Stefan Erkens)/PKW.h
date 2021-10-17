#pragma once

#include "Fahrzeug.h"

class PKW : public Fahrzeug
{
	public:
		//Konstruktoren
		PKW();
		PKW(string sName, double dMaxSpeed);
		PKW(string name, double speed, double consumption, double volume);
		~PKW(){};
		double dVerbrauch(); //Gibt den Verbauch zurück
		virtual double dTanken(double dMenge = 0.0); //Tankt das Fahrzeug und gibt die Tatsächliche Menge zurück
		virtual void vAbfertigung(); //Fertigt den PKW ab
		virtual double dGeschwindigkeit(); //Errechnet die aktuelle Geschwindigkeit
		virtual ostream& ostreamAusgabe(ostream& data); //Ostream mit allen PKW-Daten
		virtual void vDraw(Weg* TrackPtr); //Funktion zum zeichnen von PKWs
	private:
		double p_dVerbrauch;
		double p_dTankinhalt;
		double p_dTankvolumen;
};