#pragma once

#include <string> 
#include <map>

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

	//Überladen des Ausgabe-Operators
	virtual ostream& ostreamAusgabe(ostream& output);  //Referenz-Rückgabe 

	//Überladen des Eingabe-Operators
	virtual istream& istreamEingabe(istream& input);  //Referenz-Rückgabe 


	//Funktion zum finden eines Zeigers in der Map
	static AktivesVO* ptObjekt(string);
   
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
	//höchzählende  Klassenvariable -> ID 
	static int p_iMaxID;
};

ostream& operator <<(ostream& output , AktivesVO& Object); //Operanden kein Element der Klasse deshalb außerhalb
istream& operator >>(istream& input , AktivesVO& Object);  //Operanden kein Element der Klasse deshalb außerhalb

//Map zum Speichern der VO's : Schlüssel -> Name(string) , Wert -> Zeiger auf VO
//statisch damit Member existiert ohne Klasse
static map<string,AktivesVO*> mapVO;

