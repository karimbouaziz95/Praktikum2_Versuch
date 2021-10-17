#include "Streckenende.h"
#include "FahrAusnahme.h"
#include "Fahrzeug.h"
#include "Weg.h"




Streckenende::Streckenende(Weg* weg, Fahrzeug* fzg) : FahrAusnahme(weg,fzg)
{
}

Streckenende::~Streckenende()
{
}

void Streckenende::vBearbeiten()
{
	cout << endl << "STRECKENENDE: " << pFahrzeug->sGetName() << " erreicht Ende von " << pWeg->sGetName() << endl;
	pWeg->vAbgabe(pFahrzeug);
	//Weiterfahren
	Kreuzung* kreuzung = pWeg->GetKreuzung();
	Weg* neuerWeg;
	if (kreuzung != NULL) 
	{
		kreuzung->vTanken(pFahrzeug);
		neuerWeg = kreuzung->ptZufaelligerWeg(pWeg);
	}
	else 
	{
		neuerWeg = pWeg->GetRueckWeg();
	}

	//Ausgabe
	cout << setfill(' '); // Reset Fill
	cout << setfill(' ');
	//Zeit
	cout << left << setw(8) << setfill(' ') << "ZEIT";
	cout << left << setw(3) << setfill(' ') << ":";
	cout << left << setw(8) << setfill(' ') << dGlobaleZeit << endl;
	//Kreuzung
	if(kreuzung != NULL)
	{
		cout << left << setw(8) << setfill(' ') << "KREUZUNG";
		cout << left << setw(3) << setfill(' ') << ":";
		cout << left << setw(8) << setfill(' ') << kreuzung->sGetName();
		cout << left << setw(8) << setfill(' ') << kreuzung->dGetTankstelle() << endl;
	}
	//Wechsel
	cout << left << setw(8) << setfill(' ') << "WECHSEL";
	cout << left << setw(3) << setfill(' ') << ":";
	cout << left << setw(8) << setfill(' ') << pWeg->sGetName() << " -> ";
	cout << left << setw(8) << setfill(' ') << neuerWeg->sGetName() << endl;
	//Fahrzeug
	cout << left << setw(8) << setfill(' ') << "Fahrzeug";
	cout << left << setw(3) << setfill(' ') << ":";
	cout << left << setw(8) << setfill(' ') << pFahrzeug->sGetName() << endl;
	

	neuerWeg->vAnnahme(pFahrzeug);
}
