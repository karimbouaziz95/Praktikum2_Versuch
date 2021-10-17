//----- Aufgabenblock_1 -----//
#include "Fahrzeug.h"

int Fahrzeug::p_iMaxID = 0;

Fahrzeug::Fahrzeug() {
	p_vInitialisierung();
	#ifdef DEBUG
		cout << "Created new Object: [" << p_iID << "] - '" 
			 << p_sName << "'" << endl;
	#endif
}
Fahrzeug::Fahrzeug(string sName) {
	p_vInitialisierung();
	p_sName = sName;
	#ifdef DEBUG
		cout << "Created new Object: [" << p_iID << "] - '" 
			 << p_sName << "'" << endl;
	#endif
}
Fahrzeug::Fahrzeug(string sName, double dMaxGeschwindigkeit) {
	p_vInitialisierung();
	p_sName = sName;
	p_dMaxGeschwindigkeit = dMaxGeschwindigkeit;
	#ifdef DEBUG
		cout << "Created new Object: [" << p_iID << "] - '" 
			 << p_sName << "'" << endl;
	#endif
}
#ifndef DISABLE_COPY
//es ist unsinnig hier p_vInitialisierung aufzurufen
Fahrzeug::Fahrzeug(const Fahrzeug& f)
	: p_dMaxGeschwindigkeit(f.p_dMaxGeschwindigkeit),
	  p_dGesamtStrecke(f.p_dGesamtStrecke),
	  p_dGesamtZeit(f.p_dGesamtZeit),
	  p_dZeit(f.p_dZeit),
	  p_sName(f.p_sName + "_copy"),
	  p_iID(++p_iMaxID) { }
Fahrzeug& Fahrzeug::operator=(const Fahrzeug& f) {
	p_dMaxGeschwindigkeit = f.p_dMaxGeschwindigkeit;
	p_dGesamtStrecke = f.p_dGesamtStrecke;
	p_dGesamtZeit = f.p_dGesamtZeit;
	p_dZeit = f.p_dZeit;
	return *this;
}
#endif

Fahrzeug::~Fahrzeug() {
	#ifdef DEBUG
		cout << "Destroyed Object: [" << p_iID << "] - '" 
			 << p_sName << "'" << endl;
	#endif
}
bool Fahrzeug::operator< (const Fahrzeug& f) {
	if(p_dGesamtStrecke < f.p_dGesamtStrecke)
		return true;
	return false;
}
extern double g_dGlobaleZeit;
void Fahrzeug::vAbfertigung() {
	if(p_dZeit >= g_dGlobaleZeit)
		return;	
	p_dGesamtStrecke += (g_dGlobaleZeit-p_dZeit) * dGeschwindigkeit();
	p_dGesamtZeit += (g_dGlobaleZeit-p_dZeit);
	p_dZeit = g_dGlobaleZeit;
}
string Fahrzeug::sName() {
	return p_sName;
}
void Fahrzeug::vNeuerName(string sName) {
	p_sName = sName;
}
void Fahrzeug::vAusgabe(ostream& out) const {
	out  << resetiosflags(ios::right)
		 << setiosflags(ios::left);
	out  << setw(4)  << p_iID
		 << setw(7)  << p_sName
		 << setw(3)  << ":"
		 << setw(9)  << dGeschwindigkeit()
		 << setw(19) << p_dGesamtStrecke;
}

void Fahrzeug::p_vInitialisierung() {
	p_dMaxGeschwindigkeit = 0.0;
	p_dGesamtStrecke = 0.0;
	p_dGesamtZeit = 0.0;
	p_dZeit = 0.0;
	p_sName = "";
	p_iMaxID++;
	p_iID = p_iMaxID;
}

ostream& operator << (ostream& out, const Fahrzeug& f) {
	f.vAusgabe(out);
	return out;
}