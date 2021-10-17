#include "Kreuzung.h"
#include "Weg.h"
#include <stddef.h>


extern double dGlobaleZeit;


//Konstruktor
Kreuzung::Kreuzung(void) : AktivesVO()
{
	p_dTankstelle = 0.0;
}


Kreuzung::Kreuzung(string sName) : AktivesVO(sName) {};


Kreuzung::Kreuzung(string sName, double dTankstelle) : AktivesVO(sName)
{
	p_dTankstelle = dTankstelle;
}


//Destruktor
Kreuzung::~Kreuzung(void)
{
}


//Funktion zum Verbinden der Kreuzung
void Kreuzung::vVerbinde(string sHinweg, string sRueckweg, double dLaenge, Kreuzung* Krz, int Speedlimit, bool bUeberholv)
{
	//erzeugen der neuen Hin- und Rueckwege
	Weg* Hinweg = new Weg(sHinweg, dLaenge, Speedlimit, Krz, bUeberholv);
	Weg* Rueckweg = new Weg(sRueckweg, dLaenge, Speedlimit, this, bUeberholv);

	//bekannt machen der Rückwege und der Kreuzungen
	Hinweg->vsetPtrRueckWeg(Rueckweg);
	Rueckweg->vsetPtrRueckWeg(Hinweg);

	//fuellen der Liste mit abfuehrenden Wegen
	this->vfillList(Hinweg);
	Krz->vfillList(Rueckweg);
}


//Tankfuntkion
void Kreuzung::vTanken(Fahrzeug* Fzg)
{
	if(p_dTankstelle > 0)
	{
		cout << "__________FAHRZEUG WIRD BETANKT__________"   << endl << endl;    
		double dMenge = Fzg->dTanken();    //Betanken des Fahrzeugs
		if(dMenge == 0){cout << "Fahrzeug musste nicht betankt werden !" << endl;};		   //Falls Fahrrad Betankt wird, oder der Tank vom Fahrzeug voll ist
		p_dTankstelle -= dMenge;           //Aktualisierung des Volumens
		cout << "Restvolumen der Tankstelle " << p_sName   << " :   " << p_dTankstelle << endl
		     << "__________________________________________"   << endl  << endl;
		p_dTankstelle -= dMenge;           //Aktualisierung des Volumens
	}
	else if(p_dTankstelle <= 0)
	{
		p_dTankstelle = 0;
	}
	else 
	{ return;}

}


//wegfuehrenden Weg auf Liste schreiben
void Kreuzung::vfillList(Weg* Weg)
{
	p_awaylist.push_back(Weg);
}


//Annehmen eines Fahrzeugs
void Kreuzung::vAnnahme(Fahrzeug* Fzg, double Start)
{
	vTanken(Fzg);
	list<Weg*>::iterator firstWay = p_awaylist.begin();
	(*firstWay)->vAnnahme(Fzg, Start);
}


//Abfertigung
void Kreuzung::vAbfertigung()
{
	list<Weg*>::iterator itlistWeg;
	for(itlistWeg = p_awaylist.begin(); itlistWeg != p_awaylist.end(); itlistWeg++)
	{
		(*itlistWeg)->vAbfertigung();
	}
}


//Ausgabe
ostream& Kreuzung::ostreamAusgabe(ostream& output)
{
	list<Weg*>::iterator itListWeg;
	AktivesVO::ostreamAusgabe(output);
	cout << "( ";
	for (itListWeg = p_awaylist.begin(); itListWeg != p_awaylist.end(); itListWeg++)
	{
		cout << (*itListWeg)->sgetName() << " ";
	}	
	cout << ")   |   Tankstelleninhalt : " << p_dTankstelle << " l" << endl;
	return output;
}


//spezifische Eingaben
istream& Kreuzung::istreamEingabe(istream& input)
{
	AktivesVO::istreamEingabe(input)
	>> p_dTankstelle;
	return input;
}


//Zufaelliges Umsetzen
Weg* Kreuzung::ptZuefaelligerWeg(Weg* ankommWeg)
{
	list<Weg*>::iterator itListWeg = p_awaylist.begin();
	int Size = p_awaylist.size();
	int Wdh = rand()%Size;

	//Falls die Groesse 1 ist, ist es eine Sackgasse
	if(Size == 1)
	{
		return (ankommWeg->getRueckWeg());  //Also muss man auf Rueckweg zurueck
	}
	else
	{
		for(int counter = 0; counter < Wdh; counter++)
		{
			itListWeg++;		
		}

		if((*itListWeg) == ankommWeg->getRueckWeg())
		{
			return ptZuefaelligerWeg(ankommWeg); //Falls gleicher Weg rekursives Aufrufen
		}
		else
		{
			return (*itListWeg);
		}
	}
	
}


//Getter Name
string Kreuzung::sgetName()
{
	return p_sName;
}


//Umsetzen
void Kreuzung::vUmsetzen(Fahrzeug* Fzg, Weg* way)
{
	vTanken(Fzg);
	Weg* randomway = this->ptZuefaelligerWeg(way);
	randomway->vAnnahme(Fzg);
	//Ausgabe
	cout   << resetiosflags(ios::right) << setiosflags(ios::left)
		   << setiosflags(ios::fixed)   << setprecision(2)
		   << "___________________________________________________________STRASSE GEWECHSELT__________________________________________________________" << endl << endl
		   << setw(15)  << "ZEIT"       << ": "       << dGlobaleZeit                                        << endl
		   << setw(15)  << "KREUZUNG"   << ": "       << this->sgetName() << " "    << p_dTankstelle         << endl
		   << setw(15)  << "WECHSEL"    << ": "       << way->sgetName()  << " -> " << randomway->sgetName() << endl
	       << setw(15)  << "FAHRZEUG"   << ": "       << *Fzg                                                << endl 
		   << "_______________________________________________________________________________________________________________________________________" << endl << endl << endl;
}