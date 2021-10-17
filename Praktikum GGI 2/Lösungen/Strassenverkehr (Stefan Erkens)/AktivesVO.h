#pragma once

#include <iostream>
#include <iomanip>
#include "AktivesVO.h"
#include <string>
using namespace std;

class AktivesVO
{

	public:
		AktivesVO();
		AktivesVO(string name);
		~AktivesVO(){};
		virtual void vAusgabe(); //Name und ID ausgeben
		virtual void vAbfertigung() = 0; //Abfertigung 
		virtual ostream& ostreamAusgabe(ostream& data); //Name und ID als Ostream zur�ckgeben
		virtual string GetName() {return p_sName;}; //Name zur�ckgeben
	protected:	
		double p_dZeit; //Zeitpunkt der letzten Abfertigung
		string p_sName; //Name
		int p_iID; //ID-Nummer des Fahrzeugs
		static int p_iMaxID; //H�chste vergebene ID

};

ostream& operator<<(ostream& Stream, AktivesVO& name); //Ausgabeoperator