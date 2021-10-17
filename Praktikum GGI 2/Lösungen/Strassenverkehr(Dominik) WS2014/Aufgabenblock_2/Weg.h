#pragma once
#include "AktivesVO.h"
#include "Fahrzeug.h"
#include "LazyListe.h"
#include <list>
class Fahrzeug;
enum Begrenzung { Innerorts = 50, Landstraﬂe = 100, Autobahn = 0 }; //in km/h  0= Unbegrenzt

class Weg :
	public AktivesVO
{
public:
	Weg();
	Weg(string,double,Begrenzung=Autobahn);
	virtual ~Weg();


	void vAbfertigung();
	void vAnnahme(Fahrzeug*);
	void vAnnahme(Fahrzeug*,double);
	void vAbgabe(Fahrzeug*);
	double getp_dLaenge();
	void push_vorne(Fahrzeug*);
	void push_hinten(Fahrzeug*);
	
	ostream& ostreamAusgabe(ostream&);
	
	Begrenzung getp_eLimit();
	
	
protected	:
	double p_dLaenge;
	Begrenzung p_eLimit;
	//Fahrzeug* p_pFahrzeuge;

	void   vInitialisierung();

	LazyListe <Fahrzeug*> p_pFahrzeuge;
	
};


