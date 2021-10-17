#pragma warning(disable:4786)
#include "Weg.h"
#include "FahrAusnahme.h"


//<Konstruktoren_Destruktoren>
Weg::Weg()
{
}

Weg::Weg(string sName, double dLaenge, Kreuzung* pt_Inter,Begrenzung eSpeed, bool bLimit)
{
	vInitialisierung();
	p_sName = sName;
	p_dLaenge = dLaenge;
	p_eLimit = eSpeed;
	p_bUeberholverbot=bLimit;
	p_ptKreuzung = pt_Inter;
	//p_dSchranke = dLaenge;
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
	
	p_pFahrzeuge.vAktualisieren();
	//Schranke zuruecksetzen
	p_dSchranke = p_dLaenge;

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
istream& Weg::istreamEingabe(istream& Stream)
{
	AktivesVO::istreamEingabe(Stream);

	return Stream;
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
bool Weg::getp_bUeberholverbot() 
{
	return p_bUeberholverbot;
}
double Weg::getp_dSchranke()
{
	if (p_bUeberholverbot==true)
	{
		return p_dSchranke;
	}
	else
	{
		return p_dLaenge;
	}
}
void Weg::setp_dSchranke(double dStrecke)
{

	p_dSchranke = dStrecke;

}
Kreuzung* Weg::GetKreuzung() const
{
	return p_ptKreuzung;
}
Weg* Weg::GetRueckweg() const
{
	return p_ptRueckweg;
}
void Weg::SetRueckweg(Weg* ptWay)
{
	p_ptRueckweg = ptWay;
}


//</Setter_Getter_Funktionen>