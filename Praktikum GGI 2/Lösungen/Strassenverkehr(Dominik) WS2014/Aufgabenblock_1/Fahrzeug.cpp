#include "Fahrzeug.h"

int Fahrzeug::p_iMaxID = 0;


Fahrzeug::Fahrzeug()
{
	p_vInitialisierung();
	p_iID = p_iMaxID;
	//cout <<"Fahrzeug erstellt: "<<endl<< "Name: " << p_sName << endl << "ID:" << p_iID<<endl<<endl;
}


Fahrzeug::Fahrzeug(string sName)
{
	p_vInitialisierung();
	p_sName = sName;
	p_iID = p_iMaxID;
	//cout << "Fahrzeug erstellt: " << endl << "Name: " << p_sName << endl << "ID:" << p_iID << endl << endl;
}

Fahrzeug::Fahrzeug(string sName,double dSpeed)
{
	p_vInitialisierung();
	p_dMaxGeschwindigkeit = dSpeed;
	p_sName = sName;
	p_iID = p_iMaxID;
	//cout << "Fahrzeug erstellt: " << endl << "Name: " << p_sName << endl << "ID:" << p_iID << endl << endl;
}


Fahrzeug::~Fahrzeug()
{
	
	//cout <<"Fahrzeug zerstoert: "<<endl<< "Name: "<< p_sName << endl << "ID:" << p_iID<<endl<<endl;
}

void Fahrzeug::vAusgabe()
{
	
	cout << setiosflags(ios::fixed) << setiosflags(ios::right) << setprecision(2) << setw(5) << p_iID << setw(10) << p_sName << setw(5) << ":" << setw(9) << dGeschwindigkeit() << setw(20) << p_dGesamtStrecke << setw(10) << endl;

	


}
double Fahrzeug::dGeschwindigkeit()
{
	return p_dMaxGeschwindigkeit;
}

double Fahrzeug::dTanken(double dMenge)
{

	return 0.0;


}
void Fahrzeug::vAbfertigung()
{
	//ändern
	if (p_dLetzeAbfertigung < dGlobaleZeit)
	{
		p_dGesamtZeit += (dGlobaleZeit - p_dLetzeAbfertigung);
		p_dGesamtStrecke += (dGlobaleZeit - p_dLetzeAbfertigung)*dGeschwindigkeit();
		p_dLetzeAbfertigung = dGlobaleZeit;
	}
}

void Fahrzeug::p_vInitialisierung()
{

	p_dMaxGeschwindigkeit = 0.0;
	p_dGesamtStrecke = 0.0;
	p_sName = "";
	p_iID = 0;
	p_iMaxID++;
	p_dLetzeAbfertigung = dGlobaleZeit;

}

/*
Ueberladung des << Operators
*/
ostream& operator << (ostream& out, Fahrzeug& x)
{
	return x.ostreamAusgabe(out);
}
ostream& Fahrzeug::ostreamAusgabe(ostream& out)
{
	out << setiosflags(ios::left) <<
		setw(5) << p_iID << setw(10) 
		<< p_sName << setw(5) << ":" <<
		setw(9) << dGeschwindigkeit() << 
		setw(20) << p_dGesamtStrecke << 
		setw(10) << endl;
	return out;
}

/*
Aufgabe3.2 
Ueberladung des Vergleichsoperators
*/
bool Fahrzeug:: operator < (const Fahrzeug& Vgl)
{
	return p_dGesamtStrecke < Vgl.p_dGesamtStrecke;
}

void Fahrzeug:: operator =(Fahrzeug& Zuw){

	p_sName = Zuw.p_sName;
	p_dMaxGeschwindigkeit = Zuw.p_dMaxGeschwindigkeit;
	//cout << "lame standard kopyfunktinbenutzt" << endl;

}
