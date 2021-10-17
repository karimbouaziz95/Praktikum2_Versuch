#pragma once
#include "AktivesVO.h"
#include "Fahrzeug.h"
#include "LazyListe.h"
#include <list>
#include "Kreuzung.h"

class Fahrzeug;
enum Begrenzung { Innerorts = 50, Landstraﬂe = 100, Autobahn = 0 }; //in km/h  0= Unbegrenzt

class Weg :
	public AktivesVO
{
public:
	Weg();
	Weg(string,double,Kreuzung*,Begrenzung=Autobahn,bool=true);
	virtual ~Weg();


	void vAbfertigung();
	void vAnnahme(Fahrzeug*);
	void vAnnahme(Fahrzeug*,double);
	void vAbgabe(Fahrzeug*);
	double getp_dLaenge();
	void push_vorne(Fahrzeug*);
	void push_hinten(Fahrzeug*);
	
	ostream& ostreamAusgabe(ostream&);
	virtual istream& istreamEingabe(istream& Stream);
	bool getp_bUeberholverbot();
	Begrenzung getp_eLimit();
	double getp_dSchranke();

	Kreuzung* GetKreuzung() const;
	Weg* GetRueckweg() const;

	void setp_dSchranke(double);
	void SetRueckweg(Weg* pt_Way);

protected	:
	double p_dLaenge;
	double p_dSchranke;
	Begrenzung p_eLimit;
	bool p_bUeberholverbot;
	
	Kreuzung* p_ptKreuzung;
	Weg* p_ptRueckweg;

	void   vInitialisierung();

	LazyListe <Fahrzeug*> p_pFahrzeuge;
	
};


