//----- Aufgabenblock_1 -----//
#include "Fahrrad.h"

Fahrrad::Fahrrad(string sName, 
				 double dMaxGeschwindigkeit)
	   : Fahrzeug(sName, dMaxGeschwindigkeit) {
}
double Fahrrad::dGeschwindigkeit() const {
	//Berechnung umstaendlich, aendern
	int iStreckenEinheiten = (int)p_dGesamtStrecke;
	iStreckenEinheiten = iStreckenEinheiten / 20;
	double dGeschw = p_dMaxGeschwindigkeit;
	for(int l = 0; l < iStreckenEinheiten; l++) {
		dGeschw = dGeschw - dGeschw/10;
	}
	if(dGeschw < 12.0)
		dGeschw = 12.0;
	return dGeschw;
}
