#include "AktivesVO.h"
#include <iomanip>
#include <iostream> 


AktivesVO::AktivesVO(void)
{
	p_sName="";
	p_iID=0;
	p_dZeit=0;
}


AktivesVO::~AktivesVO(void)
{
}


ostream& AktivesVO::ostreamAusgabe(ostream& Stream)
{
	Stream << resetiosflags(ios::right) << setiosflags(ios::left) //vorher rechts jetzt wieder linksbündig (1.5)
		   << setw(4)  << p_iID
		   << setw(7) << p_sName  
		   << setw(3) << ":";
	return Stream;
}


ostream& operator<<(ostream& Stream, AktivesVO& car)
{
	car.ostreamAusgabe(Stream);
	return Stream;
}