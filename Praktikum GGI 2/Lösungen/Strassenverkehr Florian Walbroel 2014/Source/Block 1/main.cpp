//----- Aufgabenblock_1 -----//
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
using namespace std;

#include "Fahrrad.h"
#include "PKW.h"

double g_dGlobaleZeit;

#define D_SECOND		0.0002777

//#define TEST_DEBUG_MODE


void vPrintHeader() {
	cout << resetiosflags(ios::right)
		 << setiosflags(ios::left);
	cout << setw(4) << "ID"
		 << setw(7) << "Name"
		 << setw(3) << ":"
		 << setw(9) << "km / h"
		 << "GesamtStrecke" << endl;
	cout << setfill('+') << setw(42)  << "+" 
		 << endl << setfill(' ');
}
void vPrintAdvHeader() {
	cout << resetiosflags(ios::right)
		 << setiosflags(ios::left);
	cout << setw(4)  << "ID"
		 << setw(7)  << "Name"
		 << setw(3)  << ":"
		 << setw(9)  << "km / h"
		 << setw(16) << "GesamtStrecke"
		 << setw(12)  << "TankInhalt"
		 << "GesamtVerbrauch" << endl;
	cout << setfill('+') << setw(60)  << "+" 
		 << endl << setfill(' ');
}
void vAufgabe_1_deb() {
	cout << "\n\tAufgabe - 1 Debug\n" << endl;
	Fahrzeug * f_feld[4];
	f_feld[0] = new Fahrzeug("f_1", 47.0);
	f_feld[1] = new Fahrzeug("f_2", 56.0);
	f_feld[2] = new Fahrzeug("f_3", 48.0);
	f_feld[3] = new Fahrzeug("f_4", 53.0);

	vPrintHeader();
	for(unsigned int l = 0; l < 4; l++) {
		cout << *f_feld[l] << endl;
	}

	f_feld[2] = 0; //verursacht laufzeit fehler

	vPrintHeader();
	for(unsigned int l = 0; l < 4; l++) {
		cout << *f_feld[l] << endl;
	}
	cout << "\n\tEnde von Aufgabe - 1 Debug\n" << endl;
}
void vAufgabe_1() {
	cout << "\n\tAufgabe - 1\n" << endl;
	Fahrzeug   f_1;
	Fahrzeug   f_2("f_2");
	Fahrzeug * f_3 = new Fahrzeug;
	Fahrzeug * f_4 = new Fahrzeug("f_4");
	Fahrzeug * f_5;

	string sName = "";
	cout << "Geben sie einen Namen ein: ";
	cin >> sName;
	f_5 = new Fahrzeug(sName);
	
	vPrintHeader();
	cout <<  f_1 << endl
		 <<  f_2 << endl
		 << *f_3 << endl
		 << *f_4 << endl 
		 << *f_5 << endl;

	
	Fahrzeug* f_6 = new Fahrzeug("f_5", 52.0); //km/h
	Fahrzeug* f_7 = new Fahrzeug("f_4", 53.0); //km/h
	Fahrzeug* f_8 = new Fahrzeug("f_3", 47.0); //km/h
	

	//globale zeit zurücksetzen
	g_dGlobaleZeit = 0.0;
	for(unsigned int l = 0; l < 120*4; l++) { //== 120 s
		f_6->vAbfertigung();
		f_7->vAbfertigung();
		f_8->vAbfertigung();
		g_dGlobaleZeit += D_SECOND / 4; //== 0.25 s == 1/7200 h
		cout << "Zeit:" << setw(11) << g_dGlobaleZeit << "h\r";
	}
	cout << endl;
	vPrintHeader();
	cout << *f_6 << endl
		 << *f_7 << endl
		 << *f_8 << endl;
	
	delete f_8;
	delete f_7;
	delete f_6;
	delete f_5;	
	delete f_4;
	delete f_3;
	cout << "\n\tEnde von Aufgabe - 1\n" << endl;
}
string NumberToString(double d) {
	stringstream ss;
	ss << d;
	return ss.str();
}
void vAufgabe_2() {
	cout << "\n\tAufgabe - 2\n" << endl;
	unsigned int iFCount = 0;
	int iIdent = 0;
	int iPkw = 0, iFahrr = 0;
	srand((unsigned) time(NULL));
	cout << "Anzahl zu erzeugender Fahrzeuge: ";
	cin >> iFCount;
	vector<Fahrzeug*> f_vec;
	Fahrzeug * f;
	for(unsigned int l = 0; l < iFCount; l++) {
		iIdent = rand() % 2;
		if(iIdent) {
			iPkw++;
			f = new PKW("PKW_"+NumberToString(iPkw), (rand() % 75)+ 25, 7, (rand() % 55) + 25);
		}
		else {
			iFahrr++;
			f = new Fahrrad("FR_"+NumberToString(iFahrr), rand() % 25 + 12);
		}
		f_vec.push_back(f);
	}
	g_dGlobaleZeit = 0.0;
	for(unsigned int m = 0; m < 6; m++) {
		g_dGlobaleZeit += 0.5; //1800 s
		cout << endl << "Zeitpunkt: " << g_dGlobaleZeit << "h" << endl;
		vPrintAdvHeader();
		for(unsigned int l = 0; l < f_vec.size(); l++) {
			f_vec.at(l)->vAbfertigung();
			cout << *f_vec.at(l) << endl;
		}
		cout << endl;
	}
	cout << "Tanken" << endl;
	for(unsigned int l = 0; l < f_vec.size(); l++) {
		f_vec.at(l)->dTanken();
	}
	cout << endl;
	for(unsigned int m = 0; m < 6; m++) {
		g_dGlobaleZeit += 0.5; //1800 s
		vPrintAdvHeader();
		for(unsigned int l = 0; l < f_vec.size(); l++) {
			f_vec.at(l)->vAbfertigung();
			cout << *f_vec.at(l) << endl;
		}
		cout << endl;
	}
	cout << "\n\tEnde von Aufgabe - 2\n" << endl; 
}
void vAufgabe3() {
	cout << "\n\tAufgabe - 3\n" << endl;
	cout << "\n\tVergleichs Operator Test:\n" << endl;
	PKW pkw1("PKW1", 56, 4, 40);
	cout << pkw1 << endl;
	g_dGlobaleZeit = 0.0;
	for(unsigned int l = 0; l < 120*4; l++) { //== 120 s
		pkw1.vAbfertigung();
		g_dGlobaleZeit += D_SECOND / 4; //== 0.25 s == 1/7200 h
	}
	cout << pkw1 << endl;

	PKW pkw2("PKW2", 56, 5, 60);
	cout << pkw2 << endl;
	if(pkw2 < pkw1) {
		cout << pkw1.sName() << " ist Weiter gefahren" << endl;
	}
	else
		cout << pkw2.sName() << " ist weiter gefahren" << endl;

	Fahrzeug f1("f1", 999);
	Fahrzeug f2 = f1;
	cout << "\n\tCopy Konstruktor Test:\n" << endl;
	cout << setw(10) << "Original:" << f1 << endl;
	cout << setw(10) << "Copy:" << f2 << endl;
	f2.vNeuerName("f2");
	cout << setw(10) << "N. Name:" << f2 << endl;
	
	Fahrzeug f3("f3", 888);
	cout << "\n\tAssignment Operator Test:\n" << endl;
	cout << setw(10) << "Start:" << f3 << endl;
	f3 = f2;
	cout << setw(10) << "End:" << f3 << endl;
	cout << "\n\tEnde von Aufgabe - 3\n" << endl; 
}
int main() {
	cout << "Aufgabenblock_1(1,2,3)\n" << endl;
	g_dGlobaleZeit = 0.0;
	//vAufgabe_1();
#ifdef TEST_DEBUG_MODE
	vAufgabe_1_deb();
#endif
	vAufgabe_2();
	vAufgabe3();
	cin.ignore(256, '\n');
	cin.get();
	return 0;
}