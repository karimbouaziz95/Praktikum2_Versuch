#pragma once
#include "AktivesVO.h"
#include <list>
#include "Fahrzeug.h"
#include "LazyListe.h"

class Fahrzeug;

enum Begrenzung{Innerorts = 50, Außerorts = 100, Autobahn = 0};

class Weg : public AktivesVO
{
	public:
		Weg();
		Weg(string name, double length, double limit = 0.0);
		~Weg(){};
		virtual void vAbfertigung(); //Alle Fahrzeuge auf dem Weg abfertigen und anschließend grafisch ausgeben lassen
		virtual ostream& Weg::ostreamAusgabe(ostream& data); //Weglänge und alle Fahrzeuge darauf ausgeben
		virtual double GetLaenge() {return p_dLaenge;}; //Länge zurückgeben
		void vAnnahme(Fahrzeug* vhc); //fahrendes Fahrzeug annehmen
		void vAnnahme(Fahrzeug* vhc, double dStartzeit); //parkendes Fahrzeug annehmen
		void vAbgabe(Fahrzeug* vhc); //Fahrzeug abgeben
		double getLimit() {return p_eLimit;}; //Geschwindigkeitslimit zurücckkgeben
		string getName() {return p_sName;}; //Name zurückgeben
		double getLaenge() {return p_dLaenge;}; //Länge zurückgeben
	private:
		double p_dLaenge; //Länge des Weges
		double p_eLimit; //Geschwindigkeitslimit
		
		LazyListe<Fahrzeug*> p_pFahrzeuge; //LazyListe für die Fahrzeuge auf dem Weg


};
