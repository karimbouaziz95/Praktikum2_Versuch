#include "AktivesVO.h"
#include <iomanip>
#include <iostream> 
#include <map>

map<string, AktivesVO*> AktivesVO::VOmap;


AktivesVO::AktivesVO(void)
{
	p_sName="";
	p_iID=0;
	p_dZeit=0;
}

AktivesVO::AktivesVO(string sName)
{
	p_sName = sName;

	if(VOmap.find(p_sName) == VOmap.end())
	{
		VOmap[p_sName] = this;
	}
	else 
	{
		if(p_sName != "")
		{
				throw new string ("Objekt mit " + p_sName + " existiert bereits.");
		}
	}
}


AktivesVO::~AktivesVO(void)
{
}


ostream& AktivesVO::ostreamAusgabe(ostream& Stream)
{
	Stream << resetiosflags(ios::right) << setiosflags(ios::left) //vorher rechts jetzt wieder linksb¸ndig (1.5)
		   << setw(4)  << p_iID
		   << setw(7) << p_sName  
		   << setw(3) << ":";
	return Stream;
}

istream& AktivesVO::istreamEingabe(istream& Stream)
{
	if(p_sName=="")
	{
		Stream >> p_sName;

		if(VOmap.find(p_sName)==VOmap.end())
		{
			VOmap[p_sName] = this;
		}
		else
		{
			throw new string("Objekt " + p_sName + " existiert schon"); 
		}
	}
	else throw new string ("Das Objekt heiﬂt bereits: " + p_sName);
	return Stream;
}


ostream& operator<<(ostream& Stream, AktivesVO& car)
{
	car.ostreamAusgabe(Stream);
	return Stream;
}

istream& operator>>(istream& Stream, AktivesVO& car)
{
	car.istreamEingabe(Stream);
	return Stream;
}




AktivesVO* AktivesVO::ptObjekt(string sName)
{
	if(VOmap.find(sName) == VOmap.end())
	{
		throw new string("Objekt mit " + sName + " existiert nicht!");
	}
	else
	{
		//cout << "Objekt Gefunden!";
		return VOmap.find(sName)->second;
	}
}