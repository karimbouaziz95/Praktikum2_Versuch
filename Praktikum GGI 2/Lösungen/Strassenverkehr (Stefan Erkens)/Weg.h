#pragma once
#include "AktivesVO.h"
#include <list>
#include "Fahrzeug.h"
#include "LazyListe.h"

class Fahrzeug;

enum Begrenzung{Innerorts = 50, Au�erorts = 100, Autobahn = 0};

class Weg : public AktivesVO
{
	public:
		Weg();
		Weg(string name, double length, double limit = 0.0);
		~Weg(){};
		virtual void vAbfertigung(); //Alle Fahrzeuge auf dem Weg abfertigen und anschlie�end grafisch ausgeben lassen
		virtual ostream& Weg::ostreamAusgabe(ostream& data); //Wegl�nge und alle Fahrzeuge darauf ausgeben
		virtual double GetLaenge() {return p_dLaenge;}; //L�nge zur�ckgeben
		void vAnnahme(Fahrzeug* vhc); //fahrendes Fahrzeug annehmen
		void vAnnahme(Fahrzeug* vhc, double dStartzeit); //parkendes Fahrzeug annehmen
		void vAbgabe(Fahrzeug* vhc); //Fahrzeug abgeben
		double getLimit() {return p_eLimit;}; //Geschwindigkeitslimit zur�cckkgeben
		string getName() {return p_sName;}; //Name zur�ckgeben
		double getLaenge() {return p_dLaenge;}; //L�nge zur�ckgeben
	private:
		double p_dLaenge; //L�nge des Weges
		double p_eLimit; //Geschwindigkeitslimit
		
		LazyListe<Fahrzeug*> p_pFahrzeuge; //LazyListe f�r die Fahrzeuge auf dem Weg


};
