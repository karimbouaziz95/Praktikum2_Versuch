#include <string>
#include <list>
#include <iostream>
#include <iomanip>

using namespace std;

#include "Kreuzung.h"
#include "Fahrzeug.h"
#include "Weg.h"

extern double dGlobaleZeit;

Kreuzung::Kreuzung(void) 
{
	p_dTankstelle = 0.0;
}

Kreuzung::Kreuzung(string sName) 
{
	p_dTankstelle = 0.0;
}
Kreuzung::Kreuzung(string sName, double dTankstelle)
{
	p_dTankstelle = dTankstelle;
}

// Verbindet Hin- und Rückweg mit Kreuzung pt_Inter
void Kreuzung::vVerbinde(string sHin, string sZurueck, double dLaenge, Kreuzung* pt_Inter)
{
	Weg* pt_WayH;
	Weg* pt_WayZ;

	//Neue Wege erstellen mit den verbindenen Kreuzungen
	pt_WayH = new Weg(sHin, dLaenge, pt_Inter);
	pt_WayZ = new Weg(sZurueck, dLaenge, this);

	//Rueckwege setzen
	pt_WayH->SetRueckweg(pt_WayZ);
	pt_WayZ->SetRueckweg(pt_WayH);

	//Zu Kreuzungslisten hinzufügen
	pt_Inter->pt_Wegfuehrend.push_back(pt_WayZ);
	pt_Wegfuehrend.push_back(pt_WayH);
}

void Kreuzung::vWegeAusgabe()
{
	list<Weg*>::iterator Lpointer;
	for (Lpointer = pt_Wegfuehrend.begin(); Lpointer != pt_Wegfuehrend.end(); ++Lpointer)
	{
		cout<<(*Lpointer)<<endl;

	}
	cout << endl;
}
ostream& Kreuzung::ostreamAusgabe(ostream& Stream)
{
	list<Weg*>::iterator Lpointer;

	AktivesVO::ostreamAusgabe(Stream)
		<< setprecision(0)
		<< "  " << setw(10)
		<< resetiosflags(ios::left)
		<< setiosflags(ios::right) << "Tankstelle:"
		<< p_dTankstelle
		<< resetiosflags(ios::right)
		<< setiosflags(ios::left)
		<< "    [ ";

	for (Lpointer = pt_Wegfuehrend.begin(); Lpointer != pt_Wegfuehrend.end(); ++Lpointer)
	{
		Stream << (*Lpointer)->getsName() << ", ";
	}

	Stream << " ]" << endl;
	Stream << resetiosflags(ios::left);
	return Stream;
}

istream& Kreuzung::istreamEingabe(istream& Stream)
{
	AktivesVO::istreamEingabe(Stream);
	Stream >> p_dTankstelle;
	return Stream;
}

void Kreuzung::vTanken(Fahrzeug *ptCar)
{
	if (p_dTankstelle > 0)
	{
		double getankt = ptCar->dTanken();
		p_dTankstelle -= getankt;
		if (getankt > 0)
		{
			cout << endl
				<< "************ Tanken *************" << endl
				<< setw(10) << "Fahrzeug: " << ptCar->GetName() << endl
				<< setw(10) << "Zeit: " << dGlobaleZeit << endl
				<< setw(10) << "Kreuzung: " << this->getsName() << " (" << this->p_dTankstelle << "L) " << endl
				<< "*********************************" << endl;
		}
	}
	else
	{
		p_dTankstelle = 0;
	}
}

void Kreuzung::vAbfertigung()
{
	list<Weg*>::iterator Lpointer;
	for (Lpointer = pt_Wegfuehrend.begin(); Lpointer != pt_Wegfuehrend.end(); ++Lpointer)
	{
		(*Lpointer)->vAbfertigung();
	}
}

void Kreuzung::vAnnahme(Fahrzeug *ptCar, double dStartzeit)
{
	vTanken(ptCar);
	(*pt_Wegfuehrend.begin())->vAnnahme(ptCar, dStartzeit);
	cout << endl
		<< "***** Fahrzeug angenommen *******" << endl
		<< setw(10) << "Kreuzung: " << this->getsName() << endl
		<< setw(10) << "Fahrzeug: " << ptCar->GetName() << endl
		<< setw(10) << "Weg: " << (*pt_Wegfuehrend.begin())->getsName() << endl
		<< "*********************************" << endl << endl;
}

void Kreuzung::vAnnahme(Fahrzeug *ptCar, double dStartzeit, Weg *ptWeg)
{
	vTanken(ptCar);
	Weg * zufallsWeg;
	zufallsWeg = ptZufaelligerWeg(ptWeg);
	zufallsWeg->vAnnahme(ptCar, dStartzeit);
	cout << endl
		<< "****** Strasse gewechselt *******" << endl
		<< setw(10) << "Zeit: " << dGlobaleZeit << endl
		<< setw(10) << "Kreuzung: " << this->getsName() << endl
		<< setw(10) << "Weg: " << ptWeg->getsName() << " -> " << zufallsWeg->getsName() << endl
		<< setw(10) << "Fahrzeug: " << ptCar->GetName() << endl
		<< "*********************************" << endl << endl;
}


Weg* Kreuzung::ptZufaelligerWeg(Weg *ptWeg)
{
	int iZufallsZahl = (rand() % (int)pt_Wegfuehrend.size());

	
	if (pt_Wegfuehrend.empty() == true)
	{
		return 0;
	}
	else if (pt_Wegfuehrend.size() == 1)
	{
		return (*pt_Wegfuehrend.begin());
	}
	else
	{
		list<Weg*>::iterator Lpointer;
		Lpointer = pt_Wegfuehrend.begin();
		for (int i = 0; i<iZufallsZahl; ++i)
		{
			++Lpointer;
		}

		if ((*Lpointer) == ptWeg->GetRueckweg())
		{
			return ptZufaelligerWeg(ptWeg);
		}
		else
		{
			return (*Lpointer);
		}
	}

}