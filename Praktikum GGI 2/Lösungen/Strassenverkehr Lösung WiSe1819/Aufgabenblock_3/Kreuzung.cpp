#include "Kreuzung.h"

#include "Weg.h"
#include "SimuClient.h"


Kreuzung::Kreuzung() : AktivesVO()
{
}

Kreuzung::Kreuzung(string sName, double tankstelle) : AktivesVO(sName) //Konstruktor von AktivesVO wird mit aufgerufen für Initialisierung und ID vergabe
{
	p_dTankstelle = tankstelle;
}


Kreuzung::~Kreuzung()
{
}

void Kreuzung::vVerbinde(string sRueckweg, string  sHinweg, double laenge, Kreuzung * kreuzung, double speedLimit, bool ueberholverbot)
{
	//Wege erzeugen
	Weg* hinweg = new Weg(sHinweg, laenge, speedLimit, ueberholverbot,kreuzung);
	Weg* rueckweg = new Weg(sRueckweg, laenge, speedLimit, ueberholverbot, this);
	//Wege untereinander verknuepfen
	hinweg->SetRueckweg(rueckweg);
	rueckweg->SetRueckweg(hinweg);
	//Wege mit Kreuzungen verknuepfen
	this->wegHinzufuegen(hinweg);
	kreuzung->wegHinzufuegen(rueckweg);	
}

void Kreuzung::vTanken(Fahrzeug * fzg)
{
	if (p_dTankstelle <= 0)
		return; //Tankstelle leer

	//Fzg komplett auftanken
	p_dTankstelle -= fzg->dTanken();

	if (p_dTankstelle < 0)
		p_dTankstelle = 0;
}

void Kreuzung::wegHinzufuegen(Weg * weg)
{
	p_abgehendeWege.push_front(weg);
}

void Kreuzung::vAnnahme(Fahrzeug * fzg, double zeit)
{
	vTanken(fzg);
	(*p_abgehendeWege.begin())->vAnnahme(fzg, zeit);
}

void Kreuzung::vAbfertigung()
{
	list<Weg*>::iterator iterator;
	for (iterator = p_abgehendeWege.begin(); iterator != p_abgehendeWege.end(); iterator++) {
		(*iterator)->vAbfertigung();
	}
}

ostream & Kreuzung::ostreamAusgabe(ostream & output)
{
	cout << setfill(' '); // Reset Fill
	output << setfill(' ');
	output << left << setw(8) << setfill(' ') << p_iID;
	output << left << setw(8) << setfill(' ') << p_sName;
	output << left << setw(3) << setfill(' ') << ":";
	output << fixed;

	//Ausgabe der Fahrzeuge auf dem Weg : ( Audi Ford )
	
	list<Weg*>::iterator iterator;
	for (iterator = p_abgehendeWege.begin(); iterator != p_abgehendeWege.end(); iterator++) {
		output << endl << " ";
		output << *(*iterator);
	}
	return output;
}

istream& Kreuzung::istreamEingabe(istream& input)
{
	AktivesVO::istreamEingabe(input);
	double tank;
	input >> tank;
	if ((double)tank == tank)
	{
		p_dTankstelle = tank;
	}
	else throw new string("Fehler bei Tankstelle!");
	return input;
}

Weg* Kreuzung::ptZufaelligerWeg(Weg * weg)
{
	//Sackgasse
	if (p_abgehendeWege.size() == 0)
		return weg->GetRueckWeg();
	if (p_abgehendeWege.size() == 1)
		return *p_abgehendeWege.begin();
	//Weg von Liste entfernen
	list<Weg*> wegeOhne(p_abgehendeWege);
	list<Weg*>::iterator iterator;
	for (iterator = wegeOhne.begin(); iterator != wegeOhne.end(); iterator++)
	{
		if (*iterator == weg->GetRueckWeg())
		{
			wegeOhne.remove(*iterator);
			break;
		}	
	}
	//Liste um rand durchgehen
	iterator = wegeOhne.begin();
	advance(iterator, rand() % (wegeOhne.size()));
	//Rand element zurueck geben
	return *iterator;
}

double Kreuzung::dGetTankstelle()
{
	return p_dTankstelle;
}
