#pragma once 

class Weg;
class Fahrzeug;

class FzgVerhalten
{
	public:
		FzgVerhalten(Weg* WegPtr);
		~FzgVerhalten(void){};
		virtual double dStrecke(Fahrzeug* FzgPtr, double zeit) {return 0;}; //Trivialer Funktionsrumpf f�r die Streckenberechnung
		Weg *p_pWeg;
};


