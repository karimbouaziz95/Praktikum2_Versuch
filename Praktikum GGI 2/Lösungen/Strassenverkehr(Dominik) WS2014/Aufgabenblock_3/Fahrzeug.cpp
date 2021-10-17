#include "Fahrzeug.h"
#include "FzgVerhalten.h"
#include "FzgFahren.h"
#include "FzgParken.h"
#include "FahrAusnahme.h"



//<Konstruktoren_Destruktoren>
Fahrzeug::Fahrzeug()
{
	vInitialisierung();
	
}
Fahrzeug::Fahrzeug(string sName)
{
	vInitialisierung();
	p_sName = sName;
	
}
Fahrzeug::Fahrzeug(string sName, double dSpeed)
{
	vInitialisierung();
	p_dMaxGeschwindigkeit = dSpeed;
	p_sName = sName;
}
Fahrzeug::~Fahrzeug()
{

}
//</Konstruktoren_Destruktoren>



//<Allgemeine_Funktionen>
void Fahrzeug::vInitialisierung()
{
	AktivesVO::vInitialisierung();
	p_dMaxGeschwindigkeit = 0.0;
	p_dGesamtStrecke = 0.0;
	p_dGefahreneStrecke = 0.0;
	p_dLetzeAbfertigung = dGlobaleZeit;
	p_dAbschnittStrecke = 0.0;
	p_pVerhalten = NULL;
	p_dZeit = dGlobaleZeit;
}
void Fahrzeug::vAusgabe()
{
	cout << setiosflags(ios::left) << 
	setw(5) <<p_iID << setw(10) <<p_sName <<
	setw(5) << ":" <<setw(9)<<dGeschwindigkeit()<<
	setw(20) <<p_dGesamtStrecke<<setw(10)<<  endl;
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
	p_dGefahreneStrecke = 0;
	if (p_dLetzeAbfertigung < dGlobaleZeit)
	{
		try{
			p_dGefahreneStrecke = p_pVerhalten->dStrecke(this, dGlobaleZeit-p_dZeit);
		}
		catch (FahrAusnahme& DriveException)
		{
				DriveException.vBearbeiten();
					
		}
		
		p_dGesamtStrecke += p_dGefahreneStrecke;
		
		p_dAbschnittStrecke += p_dGefahreneStrecke;

		p_dLetzeAbfertigung = dGlobaleZeit;

		p_dZeit = p_dLetzeAbfertigung;
		
		

		cout <<*this << endl;
	}
}
void Fahrzeug::vNeueStrecke(Weg* pWay)
{
	p_pVerhalten = new FzgFahren(pWay);
	//pWay->push_hinten(this);
	p_dAbschnittStrecke = 0.0;
}
void Fahrzeug::vNeueStrecke(Weg* pWay,double dStartzeit)
{
	p_pVerhalten = new FzgParken(pWay,dStartzeit);
	//pWay->push_hinten(this);
	p_dAbschnittStrecke = 0.0;
}
//</Allgemeine_Funktionen>



//<Ueberladungen>
ostream& operator << (ostream& out, Fahrzeug& x)
{
	return x.ostreamAusgabe(out);
}
ostream& Fahrzeug::ostreamAusgabe(ostream& out)
{
	AktivesVO::ostreamAusgabe(out);
	out <<setw(9) << dGeschwindigkeit() << " " << setw(10)<<p_dGesamtStrecke;
	return out;
}
istream& Fahrzeug::istreamEingabe(istream& Stream)
{
	AktivesVO::istreamEingabe(Stream);
	Stream >> p_dMaxGeschwindigkeit;
	return Stream;
}
bool Fahrzeug:: operator < (const Fahrzeug& Vgl)
{
	return p_dGesamtStrecke < Vgl.p_dGesamtStrecke;
}
void Fahrzeug:: operator =(Fahrzeug& Zuw){
	p_sName = Zuw.p_sName;
	p_dMaxGeschwindigkeit = Zuw.p_dMaxGeschwindigkeit;
}
//</Ueberladungen>



//<Setter_Getter_Funktionen>
string Fahrzeug::GetName() const
{
	return p_sName;
}
double Fahrzeug::getp_dAbschnittStrecke()const
{
	return p_dAbschnittStrecke;
}
FzgVerhalten* Fahrzeug::getp_pVerhalten()
{
	return p_pVerhalten;
}
void Fahrzeug::setp_pVerhalten(FzgVerhalten* pNeuesVerhalten)
{
	p_pVerhalten = pNeuesVerhalten;

}

//</Setter_Getter_Funktionen>