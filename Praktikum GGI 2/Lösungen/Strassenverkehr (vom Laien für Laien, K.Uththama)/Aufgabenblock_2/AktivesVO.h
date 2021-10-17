#pragma once

#include <string> 

using namespace std ;

//Abstrakte Oberklasse
class AktivesVO
{
public:
	//Standardkonstruktor
	AktivesVO(void);
	AktivesVO(string sName);

	//Destruktor
	~AktivesVO(void);

	//Abfertigung rein virtuell
	virtual void vAbfertigung() = 0; //abtrakte Klasse

	//�berladen des Operators
	virtual ostream& ostreamAusgabe(ostream& output);  //Referenz-R�ckgabe 
   
protected :
	//Initialisierungsfunktion
	void vInitialisierung();
	
	//zuletzt abgefertigte Zeit
	double p_dZeit;
   
	//Name des jeweiligen Fahrzeugs
	string p_sName;
	
	//ID des jeweiligen Fahrzeugs
	int p_iID;

private:
	//h�chz�hlende  Klassenvariable -> ID 
	static int p_iMaxID;
};

ostream& operator <<(ostream& output , AktivesVO& Object); //Operand kein Element der Klasse deshalb au�erhalb


