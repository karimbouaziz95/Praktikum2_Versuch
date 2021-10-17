//----- Aufgabenblock_1 -----//
#include "PKW.h"

PKW::PKW(string sName,
	     double dMaxGeschwindigkeit) 
	: Fahrzeug(sName, dMaxGeschwindigkeit),
	  p_dVerbrauch(0.0),
	  p_dTankVolumen(PKW_STD_TANK_VOLUMEN),
	  p_dTankInhalt(PKW_STD_TANK_VOLUMEN/2) {
}
PKW::PKW(string sName, 
		 double dMaxGeschwindigkeit,
		 double dVerbrauch,
		 double dTankVolumen) 
	: Fahrzeug(sName, dMaxGeschwindigkeit),
	  p_dVerbrauch(dVerbrauch),
	  p_dTankVolumen(dTankVolumen),
	  p_dTankInhalt(dTankVolumen/2) {

		  //vAusgabe();
		  //cout << endl;

}
extern double g_dGlobaleZeit;
void PKW::vAbfertigung() {
	if(p_dTankInhalt <= 0.0)
		return;
	p_dTankInhalt -= p_dVerbrauch / 100 * (g_dGlobaleZeit-p_dZeit) * p_dMaxGeschwindigkeit;
	if(p_dTankInhalt <= 0.0)
		p_dTankInhalt = 0.0;
	//call parent
	Fahrzeug::vAbfertigung();
}
double PKW::dTanken(double dMenge) {
	if(dMenge == PKW_VOLL_TANKEN) {
		double dGetankt = (p_dTankVolumen - p_dTankInhalt);
		p_dTankInhalt = p_dTankVolumen;
		return dGetankt;
	}
	if(dMenge > (p_dTankVolumen-p_dTankInhalt))
		dMenge = (p_dTankVolumen-p_dTankInhalt);
	p_dTankInhalt += dMenge;
	return dMenge;
}
void PKW::vAusgabe(ostream& out) const {
	Fahrzeug::vAusgabe();
	out << setw(12) << p_dTankInhalt
		 << (p_dTankVolumen-p_dTankInhalt);
}