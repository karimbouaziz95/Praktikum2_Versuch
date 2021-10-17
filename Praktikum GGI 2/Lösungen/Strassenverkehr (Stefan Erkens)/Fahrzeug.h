#pragma once
#include <iostream>
#include <iomanip>
#include "AktivesVO.h"
#include "Weg.h"

#include "FzgVerhalten.h"
#include "FzgFahren.h"
#include "FzgParken.h"
#include "SimuClient.h"
#include <string>
using namespace std;

//Verarbeitung der globalen Uhr
extern double dGlobaleZeit;

class Fahrzeug : public AktivesVO
{
	public:
		//Konstruktoren
		Fahrzeug();
		Fahrzeug(string name);
		Fahrzeug(string name, double speed);
		~Fahrzeug(){}; //Destruktor
		virtual void vAbfertigung(); //Abfertigung 
		virtual double dTanken(double dMenge = 0.0){return 0;}; //Triviale Tankfunktion
		virtual double dGeschwindigkeit(){return p_dMaxGeschwindigkeit;}; //Triviale Geschwindigkeitsfunktion
		virtual ostream& ostreamAusgabe(ostream& data); //Fahrzeug als Ostream ausgeben
		virtual bool operator < (const Fahrzeug& compare); //Operator vergleicht gesamt gefahrene Strecke
		virtual void operator = (const Fahrzeug& origin); //Copy-Operator
		virtual double GetMaxSpeed() {return p_dMaxGeschwindigkeit;}; //Maximalgeschwindigkeit zurückgeben
		virtual double GetAbschnittStrecke() {return p_dAbschnittStrecke;}; //Strecke auf dem aktuellen Weg
		virtual void vNeueStrecke(Weg* track); //Strecke, auf das das Fahrzeug fährt
		virtual void vNeueStrecke(Weg* track, double dStartzeitpunkt); //Strecke, auf der das Fahrzeug parkt
		virtual void vDraw(Weg* TrackPtr) {}; //Funktionsstumpf für das Zeichnen eines Fahrzeugs
		virtual void ClearBehaviour() {delete p_pVerhalten; p_pVerhalten = NULL;}; //Verhalten löschen
	private:
		void vInitialisierung(); //Initialisierungs
	protected:	
		double p_dMaxGeschwindigkeit; //Höchstgeschwindigkeit
		double p_dGesamtStrecke; //Gesamt zurückgelegte Strecke
		double p_dAbschnittStrecke; //Strecke auf dem aktuellen Weg
		double p_dGesamtZeit; //Zeit, in der das Fahrzeugt existiert hat
		FzgVerhalten *p_pVerhalten; //Pointer auf das zugehörige Verhalten
		
};







