#include "PKW.h"
#include "FzgVerhalten.h"
#include "Weg.h"
#include "SimuClient.h"


PKW::PKW(double dVerbrauch, string sName, double dMaxGeschwindigkeit, double dTankvolumen) : Fahrzeug(sName, dMaxGeschwindigkeit)
{
	p_dVerbrauch = dVerbrauch;
	p_dTankvolumen = dTankvolumen;
	p_dTankinhalt = dTankvolumen;
}

PKW::~PKW(void)
{
	
}

double PKW::dVerbrauch()
{
	return (p_dVerbrauch*p_dGesamtStrecke/100);
}

double PKW::dTanken(double dMenge)
{
	double dTankMenge;
	if (dMenge == 0.0)  //Wenn kein Parameter übergeben wird, soll 
	{
		dTankMenge = p_dTankvolumen-p_dTankinhalt;		// zu tankende Menge berechnet werden
		p_dTankinhalt = p_dTankvolumen;					// Tankinhalt auf Tankvolumen gesetzt werden (volltanken)
		return dTankMenge;
	}
	else				//Wenn Parameter übergeben wird
	{
		if (dMenge >= (p_dTankvolumen-p_dTankinhalt))		//und zu tankende Menge größer oder gleich dem Platz im Tank ist, soll
		{
			dTankMenge = p_dTankvolumen-p_dTankinhalt;			// zu tankende Menge berechnet werden
			p_dTankinhalt = p_dTankvolumen;						// Tankinhalt auf Tankvolumen gesetzt werden (volltanken)
			return dTankMenge;
		}
		else												//und zu tankende Menge kleiner als der Platz im Tank ist, soll
		{
			p_dTankinhalt += dMenge;							//übergebene Menge getankt werden
			return dMenge;
		}
	}
}

void PKW::vAbfertigung()
{
	extern double dGlobaleZeit;
	extern double dZeitschritt;

	if(p_dTankinhalt != 0.0)	//wenn PKW bei Aufruf der Funktion noch fährt (da Treibstoff im Tank), soll
	{
		double dTankinhaltcheck;
		dTankinhaltcheck = p_dTankinhalt- p_pVerhalten->dStrecke(this,(dGlobaleZeit-p_dZeit))*p_dVerbrauch/100;
		if(dTankinhaltcheck > 0)				//geprüft werden ob Spritmenge gereicht hat, um letzten Abschnitt zu fahren. Wenn ja, soll
		{
			p_dTankinhalt=dTankinhaltcheck;			//Tankinhalt aktualisiert werden
			Fahrzeug::vAbfertigung();				//Fahrzeug abgefertigt werden
		}
		else									//Wenn nicht, soll
		{
            Fahrzeug::vAbfertigung();				//letzte Abfertigung durchgeführt werden
			p_dTankinhalt = 0.0;					//Tankinhalt geleert werden
		}
	}
	else						//wenn PKW bei Aufruf der Funktion bereits steht:		
	{
	if((dGlobaleZeit-p_dZeit)>=dZeitschritt)			//Zeitliche Abfertigung für evtl. Berechnung nach erneutem Tanken 
		{
			p_dZeit = dGlobaleZeit;
		}
	}
}

void PKW::vAusgabe()
{
	Fahrzeug::vAusgabe();
	cout << setw(15) << setiosflags(ios::left) << setiosflags(ios::fixed) << setprecision(2) << dVerbrauch() 
		 << setw(20) << setiosflags(ios::left) << setiosflags(ios::fixed) << setprecision(2) << p_dTankinhalt << endl;
}

double PKW::dGeschwindigkeit(void)
{
    if (p_pVerhalten == NULL) 
    {
        return p_dMaxGeschwindigkeit;
    } 
    
    double dGeschwindigkeitB;
    
    if(p_pVerhalten->wGetWeg()->eGetLimit() == Autobahn)
    {
        dGeschwindigkeitB = 1000000000;					//"unbegrenzte" Geschwindigkeit bei Limit Autobahn
    }
    if(p_pVerhalten->wGetWeg()->eGetLimit() == Landstrasse)
    {
        dGeschwindigkeitB = 100;						// Geschwindigkeitsbegrenzung 100km/h bei Limit Landstrasse
    }
    if(p_pVerhalten->wGetWeg()->eGetLimit() == Innerorts)
    {
        dGeschwindigkeitB = 50;							// Geschwindigkeitsbegrenzung 50km/h bei Limit Landstrasse
    }
    if(dGeschwindigkeitB < p_dMaxGeschwindigkeit)
    {
        return dGeschwindigkeitB;						//Geschwindigkeitsbegrenzung als Höchstgeschwindigkeit zurückgeben
    }
    return p_dMaxGeschwindigkeit;						//Maximalgeschwindigkeit des PKW zurückgeben, wenn Geschwindigkeitsbegrenzung nicht erreicht wird
}

ostream& PKW::ostreamAusgabe(ostream& Stream)
{
	Fahrzeug::ostreamAusgabe(Stream) << setw(15) << setiosflags(ios::left) << setiosflags(ios::fixed) << setprecision(2) << dVerbrauch() 
									 << setw(20) << setiosflags(ios::left) << setiosflags(ios::fixed) << setprecision(2) << p_dTankinhalt 
									 << endl;
	return Stream;
}

void PKW::vZeichnen(Weg* pWeg)
{
	bZeichnePKW(p_sName, pWeg->sGetName(), p_dAbschnittStrecke/pWeg->dGetLaenge(), dGeschwindigkeit(), p_dTankinhalt);
}