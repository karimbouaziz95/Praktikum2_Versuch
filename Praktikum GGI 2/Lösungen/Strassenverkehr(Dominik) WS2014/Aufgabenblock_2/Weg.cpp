#pragma warning(disable:4786)
#include "Weg.h"
#include "FahrAusnahme.h"


//<Konstruktoren_Destruktoren>
Weg::Weg()
{
}
Weg::Weg(string sName,double dLaenge,Begrenzung eSpeed)
{
	vInitialisierung();
	p_sName = sName;
	p_dLaenge = dLaenge;
	p_eLimit = eSpeed;
}
Weg::~Weg()
{
}
//</Konstruktoren_Destruktoren>



//<Allgemeine Funktionen>
void   Weg::vInitialisierung()
{
	AktivesVO::vInitialisierung();
	p_dLaenge = 0.0;
}
void Weg::vAbfertigung()
{

	list <Fahrzeug*>::iterator itL;


	for (itL = p_pFahrzeuge.begin(); itL != p_pFahrzeuge.end();itL++)
	{
		if (p_pFahrzeuge.empty()){ cout << "Keine Fahrzeuge!" << endl; }
		else
		{
			cout << *this << endl;
			(*itL)->vAbfertigung();
			(*itL)->vZeichnen(this);
		}
	}


	p_pFahrzeuge.vAktualisieren();
}
//</Allgemeine Funktionen>



//<Ueberladungen>
ostream& Weg::ostreamAusgabe(ostream& out)
{
	list <Fahrzeug*>::iterator itL;

	AktivesVO::ostreamAusgabe(out);
		out<<setw(9) << p_dLaenge << setw(2)<<"(";
	for (itL = p_pFahrzeuge.begin(); itL != p_pFahrzeuge.end(); itL++)
	{
		out<< (*itL)->getsName()<<" ";
	}
	out << ")" << endl<<endl;
	return out;
}
//</Ueberladungen>


//<Annahme und Abgabe von p_pFahrzeugen>
void Weg::vAnnahme(Fahrzeug* pDriveThing)
{
	p_pFahrzeuge.push_back(pDriveThing);
	pDriveThing->vNeueStrecke(this);
}
void Weg::vAnnahme(Fahrzeug* pDriveThing,double dStartzeit)
{
	p_pFahrzeuge.push_front(pDriveThing);
	pDriveThing->vNeueStrecke(this,dStartzeit+0.2);
}
void Weg::vAbgabe(Fahrzeug* pDriveThing)
{	
	list<Fahrzeug*>::iterator iter;
	for (iter = p_pFahrzeuge.begin(); iter != p_pFahrzeuge.end(); iter++)
	{
		if (*iter == pDriveThing)
		{
			cout << "Fahrzeug geloescht" << endl;
			p_pFahrzeuge.erase(iter);
		}
	}
}
//</Annahme und Abgabe von Fahrzeugen>



//<Push-Funktionen für die Liste>
void Weg::push_vorne(Fahrzeug* pFahrzeug)
{

	p_pFahrzeuge.push_front(pFahrzeug);

}
void Weg::push_hinten(Fahrzeug* pFahrzeug)
{
	p_pFahrzeuge.push_back(pFahrzeug);


}
//</Push-Funktionen für die Liste>



//<Setter_Getter_Funktionen>
double Weg::getp_dLaenge()
{
	return p_dLaenge;
}
Begrenzung  Weg::getp_eLimit()
{

	return p_eLimit;


}
//</Setter_Getter_Funktionen>