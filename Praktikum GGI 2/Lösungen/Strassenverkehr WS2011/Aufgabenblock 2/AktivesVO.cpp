#include "AktivesVO.h"

int AktivesVO::p_iMaxID=1;

AktivesVO::AktivesVO(void)
{
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