#include "AktivesVO.h"

int AktivesVO::p_iMaxID=1;
map<string, AktivesVO*> AktivesVO::mapVO;

AktivesVO::AktivesVO(void)
{
}

AktivesVO::AktivesVO(string sName) 
{
	if(mapVO.count(sName))
	{
		throw string("Error: Objekt mit diesem Namen existiert bereits: " + sName + "\n");
	}
	p_sName = sName;
	p_iID = p_iMaxID;
	p_iMaxID++;
	p_dZeit = 0;

	if(sName != "")
	{
		mapVO[sName] = this;
	}
}

AktivesVO::~AktivesVO(void)
{
}

void AktivesVO::vInitialisierung()
{
	p_iID = p_iMaxID++;
	p_sName = "";
    p_dGesamtZeit = 0;
	p_dZeit = 0;
}

ostream& AktivesVO::ostreamAusgabe(ostream& Stream)
{
	Stream << setw(4) << setiosflags(ios::left) << p_iID 
		   << setw(12) << setiosflags(ios::left) << p_sName ;
	return Stream;
}

ostream& operator<<(ostream& Stream, AktivesVO& AktivesVO_o)
{
	AktivesVO_o.ostreamAusgabe(Stream);
	return Stream;
}

string AktivesVO::sGetName()
{
    return p_sName;
}

istream& AktivesVO::istreamEingabe(istream& Stream)
{
	if(!p_sName.empty())
	{
		throw string("Error: sName ist nicht leer!\n");
	}
	string sName;
	Stream >> sName;

	if(mapVO.count(sName))
	{
		throw string("Error: Objekt mit diesem Namen existiert bereits\n");
	}

	p_sName = sName;
	mapVO[sName] = this;

	return Stream;
}

istream& operator>>(istream& Stream, AktivesVO& AktivesVO_o)
{
	return AktivesVO_o.istreamEingabe(Stream);
}

AktivesVO* AktivesVO::ptObjekt(string sName)
{
	if(!mapVO.count(sName))
	{
		throw string("Error: Objekt nicht gefunden: " + sName + "\n");
	}
	return mapVO.find(sName)->second;
}